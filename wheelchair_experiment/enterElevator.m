function result = enterElevator(current_position, current_yaw, elevator_center, ~, lidar_scan_data, is_gazebo, odometry_mode, door_detection_mode, door_params, target_position)
    % Enter elevator function with six phases:
    % Phase 1: Position correction (reach target distance and orientation)
    % Phase 2: Turn towards elevator center
    % Phase 2.5: Verify elevator door is open using LiDAR (done once)
    % Phase 3: Move into elevator using odometry (velocity × time) until target distance reached
    % Phase 4: Inside elevator waiting (door close, reopen, detect)
    % Phase 5: Reverse out of elevator (odometry-based)
    % Phase 6: Completed
    %
    % Inputs:
    %   current_position - [x, y] current wheelchair position (used only for Phase 1 & 2)
    %   current_yaw - current heading angle in radians
    %   elevator_center - [x, y] position of elevator center (default: [27, 12])
    %   (4th parameter unused - kept for backward compatibility)
    %   lidar_scan_data - struct with xyz_global and xyz_local point cloud data from Estimate.m
    %   is_gazebo - boolean flag indicating if running in Gazebo simulation
    %   odometry_mode - boolean or empty: true = use local coordinates, false/[] = use global coordinates
    %   door_detection_mode - boolean: true = bypass Phase 1, go directly to Phase 2.5 debug
    %   door_params - struct with door detection parameters
    %   target_position - [x, y] Phase 1 target position (from metadata, passed by Control.m)
    %
    % Outputs:
    %   result - struct with control commands and status
    %
    % Note: Phase 3 & 5 use odometry-based distance tracking (velocity × time integration)
    %       independent of global position to work in map-free environments
    
    persistent phase1_completed; % Track if Phase 1 position correction is done
    persistent phase3_distance_traveled; % Track accumulated distance in Phase 3 (odometry-based)
    persistent phase5_distance_traveled; % Track accumulated distance in Phase 5 reverse (separate from Phase 3)
    persistent door_verified; % Track if door has been verified (check only once)
    persistent elevator_sequence_state; % Track elevator simulation state
    persistent sequence_timer; % Timer for elevator sequence
    persistent current_floor; % Track current floor
    persistent target_floor; % Track target floor
    persistent floor_input_requested; % Track if floor input was already requested
    persistent last_update_time; % For delta time calculation (Phase 3 forward)
    persistent last_update_time_reverse; % For delta time calculation (Phase 5 reverse)

    if nargin < 3
        elevator_center = [27, 12.2]; % Default elevator center position
    end
    
    if nargin < 6
        is_gazebo = false; % Default to real system if not specified
    end
    
    if nargin < 7 || isempty(odometry_mode)
        odometry_mode = false; % Default to map mode (global coordinates) if not specified
    end
    
    if nargin < 8 || isempty(door_detection_mode)
        door_detection_mode = false; % Default to normal elevator entry
    end
    
    if nargin < 9 || isempty(door_params)
        % Default door detection parameters if not provided (should match Control.m)
        door_params = struct();
        % Phase 1: Position Correction
        door_params.POSITION_TOLERANCE = 0.15;          % ±15cm acceptable distance error
        door_params.POSITION_ANGLE_TOLERANCE = 0.087;   % ±5 degrees acceptable heading error (radians)
        door_params.CORRECTION_TURN_SPEED = 0.3;        % rad/s for correction turns
        door_params.CORRECTION_MOVE_SPEED = 0.15;       % m/s for correction movement (slower than entry)
        % Phase 2: Turning towards elevator
        door_params.TURN_TOLERANCE = 0.1;               % radians (~6 degrees) - when to stop turning
        door_params.TURN_SPEED = 0.1;                   % rad/s for Phase 2 turning
        % Phase 2.5: Door Detection
        door_params.ANGLE_TOLERANCE = 30;       % ±30 degrees cone towards elevator (initial filtering)
        door_params.NARROW_ROI_ANGLE = 3.5;       % ±7 degrees for wheelchair safe passage (critical ROI)
        door_params.DOOR_HEIGHT_MIN = 0.5;      % Minimum height (avoid floor)
        door_params.DOOR_HEIGHT_MAX = 1.7;      % Maximum door height
        door_params.MIN_POINTS_THRESHOLD = 5;   % Minimum points needed for analysis
        door_params.DEPTH_THRESHOLD = 0.3;     % Points must be this much deeper than elevator center
        % Phase 3 & 5: Movement into/out of elevator
        door_params.MOVE_DISTANCE = 2.3;                % meters to move into elevator
        door_params.MOVE_SPEED = 0.2;                   % m/s for forward/reverse movement
    end
    
    % Initialize persistent variables on first call
    if isempty(phase1_completed)
        phase1_completed = false;
    end

    if isempty(door_verified)
        door_verified = false;
    end
    
    if isempty(elevator_sequence_state)
        elevator_sequence_state = 'normal'; % 'normal', 'inside_waiting', 'door_closed', 'reversing'
    end
    
    if isempty(sequence_timer)
        sequence_timer = 0;
    end
    
    if isempty(current_floor)
        current_floor = 4; % Start at floor 1
    end
    
    if isempty(target_floor)
        target_floor = 1; % Will be set when entering elevator
    end

    if isempty(floor_input_requested)
        floor_input_requested = false; % Initialize flag
    end

    if isempty(phase3_distance_traveled)
        phase3_distance_traveled = 0; % Initialize distance counter for Phase 3 forward movement
    end

    if isempty(phase5_distance_traveled)
        phase5_distance_traveled = 0; % Initialize distance counter for Phase 5 reverse movement
    end


    % Extract parameters from door_params (all parameters now centralized in Control.m)
    TURN_TOLERANCE = door_params.TURN_TOLERANCE;  % radians (~6 degrees)
    MOVE_DISTANCE = door_params.MOVE_DISTANCE;    % meters to move into elevator
    TURN_SPEED = door_params.TURN_SPEED;          % rad/s for turning
    MOVE_SPEED = door_params.MOVE_SPEED;          % m/s for forward movement
    
    % DEBUG MODE - Set to true to enable continuous door checking
    DEBUG_MODE = false;
    % Override DEBUG_MODE if door detection mode is requested
    if nargin >= 8 && door_detection_mode
        DEBUG_MODE = true;
        fprintf('*** DOOR DETECTION MODE: Setting DEBUG_MODE = true ***\n');
    end
    
    fprintf('=== ENTERING ELEVATOR SEQUENCE ===\n');
    fprintf('Current position: [%.2f, %.2f], Yaw: %.2f rad\n', ...
            current_position(1), current_position(2), current_yaw);
    fprintf('Elevator center: [%.2f, %.2f]\n', elevator_center(1), elevator_center(2));
    
    % Calculate required heading to face elevator center
    direction_vector = elevator_center - current_position;
    required_heading = atan2(direction_vector(2), direction_vector(1));
    
    % Calculate heading error
    heading_error = angdiff(required_heading, current_yaw);
    
    fprintf('Required heading: %.2f rad (%.1f deg)\n', required_heading, rad2deg(required_heading));
    fprintf('Current heading: %.2f rad (%.1f deg)\n', current_yaw, rad2deg(current_yaw));
    fprintf('Heading error: %.2f rad (%.1f deg)\n', heading_error, rad2deg(heading_error));
    
    % Initialize result structure
    result = struct();
    result.phase = 1; % Start with Phase 1 (position correction)
    result.completed = false;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]
    
    % Main control flow based on elevator_sequence_state
    switch elevator_sequence_state
        case 'normal'
            % Normal elevator entry phases (1, 2, 2.5, 3)
            if door_detection_mode
                % Door Detection Mode: Skip Phases 1 and 2, go directly to Phase 2.5
                fprintf('*** DOOR DETECTION MODE: Bypassing Phase 1 (position) and Phase 2 (turning) ***\n');
                phase1_completed = true; % Mark Phase 1 as completed
                door_verified = false; % Force Phase 2.5 to run
            end

            if ~phase1_completed
                % Phase 1: Position Correction - ensure wheelchair is at correct distance/orientation
                % target_position is passed as parameter from Control.m
                phase1_result = positionCorrectionPhase(current_position, current_yaw, target_position, elevator_center, door_params);

                result.phase = phase1_result.phase;
                result.status = phase1_result.status;
                result.V = phase1_result.V;
                result.position_error = phase1_result.position_error;
                result.angle_error = phase1_result.angle_error;
                result.target_position = phase1_result.target_position;

                if phase1_result.completed
                    phase1_completed = true;
                    fprintf('Phase 1 completed - proceeding to Phase 2 (turning)\n');
                end

            elseif ~door_detection_mode && abs(heading_error) > TURN_TOLERANCE
                % Phase 2: Turn towards elevator (only if not in door detection mode)
                result.phase = 2;
                result.status = 'Turning towards elevator';

                fprintf('Phase 2: Turning towards elevator\n');
                turn_result = turnTowardsTarget(current_yaw, elevator_center, current_position, TURN_SPEED, TURN_TOLERANCE);
                result.V = turn_result.V;
                
            elseif ~door_verified || DEBUG_MODE
                % Phase 2.5: Check door state using LiDAR
                result.phase = 2.5;

                if DEBUG_MODE
                    if door_detection_mode
                        result.status = 'DOOR DETECTION MODE: Bypassed to Phase 2.5';
                        fprintf('\n============= DOOR DETECTION MODE ACTIVE ==============\n');
                        fprintf('=== Phases 1 & 2 Bypassed - Direct Door Detection Debug ===\n');
                    else
                        result.status = 'DEBUG MODE: Continuous door checking';
                        fprintf('\n================== DEBUG MODE ACTIVE ==================\n');
                        fprintf('=== Continuous Door Detection Analysis ===\n');
                    end
                else
                    result.status = 'Verifying elevator door is open';
                    fprintf('Phase 2.5: Checking elevator door state using LiDAR...\n');
                end

                result.V = [0; 0]; % Stop while checking door

                % Use unified door checking function
                wheelchair_pose = [current_position, current_yaw];

                if DEBUG_MODE
                    % In debug mode, call the original debug function directly
                    if nargin >= 5 && ~isempty(lidar_scan_data)
                        if isstruct(lidar_scan_data) && isfield(lidar_scan_data, 'xyz_local')
                            pointCloud = lidar_scan_data.xyz_local;
                        else
                            pointCloud = lidar_scan_data;
                        end
                        if iscell(pointCloud)
                            pointCloud = pointCloud{1};
                        end
                        door_state = debugElevatorDoorDetection(pointCloud, wheelchair_pose, elevator_center, DEBUG_MODE, odometry_mode, door_params);
                    else
                        door_state = 'unknown';
                    end
                    result.door_state = door_state;
                    door_verified = false; % Keep checking in debug mode
                else
                    % Normal mode: use unified door checking function
                    door_check = checkDoorPassable(lidar_scan_data, wheelchair_pose, elevator_center, odometry_mode, door_params);
                    result.door_state = door_check.door_state;

                    if door_check.verified
                        fprintf('Phase 2.5: Door verified as OPEN - proceeding to Phase 3\n');
                        door_verified = true;
                    elseif strcmp(door_check.door_state, 'closed')
                        fprintf('Phase 2.5: Door is CLOSED - waiting...\n');
                    else
                        fprintf('Phase 2.5: Door state UNKNOWN - proceeding with caution\n');
                        door_verified = true; % Proceed even if unknown
                    end
                end
                
            else
                % Phase 3: Move forward into elevator (odometry-based distance tracking)
                result.phase = 3;
                result.status = 'Moving into elevator (odometry)';

                % Initialize Phase 3 distance if not set
                if isempty(phase3_distance_traveled)
                    phase3_distance_traveled = 0;
                    fprintf('Phase 3: Starting forward movement (odometry mode)\n');
                    fprintf('         Target distance: %.2f m\n', MOVE_DISTANCE);
                end

                fprintf('Phase 3: Moving into elevator\n');
                move_result = moveDistance(MOVE_DISTANCE, MOVE_SPEED, 'forward', phase3_distance_traveled, last_update_time);

                result.V = move_result.V;
                phase3_distance_traveled = move_result.distance_traveled;
                last_update_time = move_result.last_update_time;

                if move_result.completed
                    % Phase 3 completed - transition to elevator simulation
                    elevator_sequence_state = 'door_closed';
                    sequence_timer = tic;
                    fprintf('Phase 3: COMPLETED! Wheelchair inside elevator.\n');
                    fprintf('Total distance traveled (odometry): %.2f m\n', phase3_distance_traveled);
                    fprintf('Setting current_floor = target_floor = %d\n', target_floor);

                    % Trigger door close
                    if is_gazebo
                        controlElevatorDoor('close');
                        fprintf('Simulation: Door closing (Gazebo)\n');
                    else
                        fprintf('Simulation: Door closing (real system)\n');
                    end

                    % Set up for Phase 4
                    result.phase = 4;
                    result.status = 'Inside elevator - Door closing';
                    result.V = [0; 0]; % Stay still
                end
            end
            
        case 'door_closed'
            % Phase 4: Door closed, waiting inside elevator
            result.phase = 4;
            result.status = 'Inside elevator - Door closed, waiting';
            result.V = [0; 0]; % Stay still

            fprintf('Phase 4: Door closed, current_floor = %d, target_floor = %d\n', current_floor, target_floor);

            % Manual floor input for real experiment (only ask once)
            if ~floor_input_requested 
                fprintf('\n========================================\n');
                fprintf('MANUAL FLOOR INPUT REQUIRED\n');
                fprintf('========================================\n');
                fprintf('The robot is now inside the elevator.\n');
                fprintf('Current floor: %d\n', current_floor);
                fprintf('Please enter the floor number you have arrived at:\n');
                fprintf('(Press Enter after typing the floor number)\n');
                fprintf('========================================\n');

                % Get floor input from user
                user_floor = input('Floor number: ');

                % Validate input
                if ~isempty(user_floor) && isnumeric(user_floor) && user_floor > 0 && mod(user_floor, 1) == 0
                    current_floor = user_floor;
                    floor_input_requested = true; % Mark as requested, won't ask again
                    fprintf('Floor set to: %d\n', current_floor);
                else
                    fprintf('Invalid input! Keeping current floor = %d\n', current_floor);
                end
                fprintf('========================================\n\n');
            end

            % Since current_floor == target_floor, immediately proceed to door opening
            if current_floor == target_floor
                fprintf('Phase 4: Reached target floor - opening door\n');

                if is_gazebo
                    controlElevatorDoor('open');
                    fprintf('Simulation: Door opening (Gazebo)\n');
                else
                    fprintf('Simulation: Door opening (real system)\n');
                end

                elevator_sequence_state = 'inside_waiting';
            end
            
        case 'inside_waiting'
            % Phase 4: Door is opening, wait for LiDAR detection of open door
            result.phase = 4;
            result.status = 'Inside elevator - Detecting door opening';
            result.V = [0; 0]; % Stay still

            % Use LiDAR to detect door opening (looking outward from inside elevator)
            if nargin >= 5 && ~isempty(lidar_scan_data)
                wheelchair_pose = [current_position, current_yaw];
                % Use floor/hallway center as reference (outside the elevator)
                % floor_center passed as function parameter from Control.m

                % Use unified door checking function for Phase 4
                % Looking outward from inside elevator toward floor/hallway (REVERSE direction)
                phase4_odometry_mode = true; % Use odometry-based detection
                phase4_target_angle = pi;    % 180° = reverse/backward direction (robot will exit backward)

                % Check if door is passable looking backward (robot exits in reverse)
                door_check = checkDoorPassable(lidar_scan_data, wheelchair_pose, target_position, ...
                                               phase4_odometry_mode, door_params, phase4_target_angle);

                if door_check.verified && strcmp(door_check.door_state, 'open')
                    fprintf('Phase 4: LiDAR confirmed door is OPEN - ready to reverse\n');
                    % Transition to reversing state
                    elevator_sequence_state = 'reversing';
                    phase5_distance_traveled = 0; % Reset distance for Phase 5 reverse movement
                    last_update_time_reverse = []; % Reset timer for Phase 5
                    sequence_timer = tic;
                else
                    fprintf('Phase 4: LiDAR detects door state: %s - waiting for open...\n', door_check.door_state);
                end
            else
                fprintf('Phase 4: No LiDAR data - assuming door open after delay\n');
                % Fallback: proceed after 2 seconds
                elapsed_time = toc(sequence_timer);
                if elapsed_time > 2.0
                    elevator_sequence_state = 'reversing';
                    phase5_distance_traveled = 0; % Reset distance for Phase 5 reverse movement
                    last_update_time_reverse = []; % Reset timer for Phase 5
                    sequence_timer = tic;
                end
            end
            
        case 'reversing'
            % Phase 5: Reverse out of elevator (odometry-based)
            result.phase = 5;
            result.status = 'Reversing out of elevator (odometry)';

            fprintf('Phase 5: Reversing out of elevator\n');
            % Use moveDistance with 'reverse' direction
            % Target: reverse the same distance we moved forward in Phase 3
            % Start from 0 and accumulate to phase3_distance_traveled
            move_result = moveDistance(phase3_distance_traveled, MOVE_SPEED, 'reverse', phase5_distance_traveled, last_update_time_reverse);

            result.V = move_result.V;
            phase5_distance_traveled = move_result.distance_traveled;
            last_update_time_reverse = move_result.last_update_time;

            if move_result.completed
                % Phase 6: Simulation completed
                result.phase = 6;
                result.status = 'Elevator simulation completed';
                result.V = [0; 0]; % Stop
                result.completed = true;

                fprintf('Simulation COMPLETED! Wheelchair exited elevator.\n');

                % Reset all persistent variables for next use
                phase1_completed = [];
                phase3_distance_traveled = [];
                phase5_distance_traveled = [];
                elevator_sequence_state = 'normal';
                sequence_timer = 0;
                door_verified = false;
                current_floor = 1;
                target_floor = 1;
                floor_input_requested = false;
                last_update_time = [];
                last_update_time_reverse = [];
            end
    end
    
    fprintf('Command: V=[%.2f, %.2f] (linear, angular)\n', result.V(1), result.V(2));
    fprintf('=====================================\n');
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate the shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end