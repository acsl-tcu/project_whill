function result = enterDoor(current_position, current_yaw, door_center, exit_position, lidar_scan_data, door_params, door_type)
    % enterDoor - General door entry function for both regular doors and elevators
    %
    % This function handles the complete door entry sequence:
    %   Phase 1: Position correction (reach target distance/orientation before door)
    %   Phase 2: Turn towards door center
    %   Phase 2.5: Verify door is passable using LiDAR
    %   Phase 3: Move through door to exit position
    %   Phase 4: Completed
    %
    % Inputs:
    %   current_position - [x, y] current wheelchair position
    %   current_yaw - current heading angle in radians
    %   door_center - [x, y] position of door center
    %   exit_position - [x, y] target position after passing through door
    %   lidar_scan_data - struct with xyz_global and xyz_local point cloud data
    %   door_params - struct with door detection/control parameters
    %   door_type - string: 'regular' or 'elevator' (determines behavior)
    %
    % Outputs:
    %   result - struct with control commands and status:
    %       .phase - current phase number (1-4)
    %       .status - string description of current state
    %       .V - [linear_vel; angular_vel] control commands
    %       .completed - boolean, true when door entry is complete
    %       .door_state - 'open', 'closed', or 'unknown' (Phase 2.5)
    %
    % Example:
    %   result = enterDoor([31.1, 5.9], pi/2, [31.1, 6.9], [31.1, 7.9], ...
    %                      lidar_data, door_params, 'regular');

    persistent phase1_completed;  % Track if position correction is done
    persistent door_verified;     % Track if door has been verified open
    persistent distance_traveled; % Track odometry-based distance in Phase 3
    persistent last_update_time;  % For delta time calculation
    persistent idle_phase_active; % Track if idle phase (2.5) is active (controls Phase 2 reentry + pause)

    % Initialize persistent variables
    if isempty(phase1_completed)
        phase1_completed = false;
    end
    if isempty(door_verified)
        door_verified = false;
    end
    if isempty(distance_traveled)
        distance_traveled = 0;
    end
    if isempty(idle_phase_active)
        idle_phase_active = false;  % Not in idle phase initially
    end

    % Set default door_type
    if nargin < 7 || isempty(door_type)
        door_type = 'regular';
    end

    % Validate door_params (use defaults if not provided)
    if nargin < 6 || isempty(door_params)
        door_params = getDefaultDoorParams();
    end

    % Extract parameters
    TURN_TOLERANCE = door_params.TURN_TOLERANCE;
    TURN_SPEED = door_params.TURN_SPEED;
    MOVE_SPEED = door_params.MOVE_SPEED;

    % Calculate required heading to face exit position (target in next room)
    % This ensures wheelchair is aligned towards where it needs to go, not just the door
    direction_vector = exit_position - current_position;
    required_heading = atan2(direction_vector(2), direction_vector(1));
    heading_error = angdiff(required_heading, current_yaw);

    % Initialize result structure
    result = struct();
    result.phase = 1;
    result.completed = false;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]
    result.door_type = door_type;

    % Phase 1: Position Correction
    if ~phase1_completed
        % Calculate target position (should be ~1m before door)
        % This is passed from HybridPathPlanner as the astar_goal
        target_position = current_position; % Already at astar_goal from A* planning

        phase1_result = positionCorrectionPhase(current_position, current_yaw, ...
                                                target_position, door_center, door_params);

        result.phase = phase1_result.phase;
        result.status = phase1_result.status;
        result.V = phase1_result.V;
        result.position_error = phase1_result.position_error;
        result.angle_error = phase1_result.angle_error;

        if phase1_result.completed
            phase1_completed = true;
        end

    % Phase 2: Turn towards exit position (with hysteresis when idle phase active)
    elseif (~idle_phase_active && abs(heading_error) > TURN_TOLERANCE) || ...
           (idle_phase_active && abs(heading_error) > TURN_TOLERANCE + 0.25)
        % Enter Phase 2 if:
        % - Idle phase NOT active AND error > tight tolerance (initial entry)
        % - Idle phase active AND error > wider tolerance (prevent re-entry oscillation during idle motion)

        result.phase = 2;
        result.status = 'Turning towards exit position';

        % Deactivate idle phase when re-entering Phase 2 (allows exit with tight tolerance again)
        if idle_phase_active
            fprintf('  Phase 2: Re-entering (error %.1f° > %.1f° reentry threshold)\n', ...
                rad2deg(abs(heading_error)), rad2deg(TURN_TOLERANCE + 0.25));
            idle_phase_active = false;
        end

        turn_result = turnTowardsTarget(current_yaw, exit_position, current_position, TURN_SPEED, TURN_TOLERANCE);
        result.V = turn_result.V;

    % Phase 2.5: Check door state
    elseif ~door_verified
        result.phase = 2.5;
        result.status = 'Verifying door is passable';

        % Use unified door checking function
        wheelchair_pose = [current_position, current_yaw];
        odometry_mode = false; % Use global coordinates for enterDoor

        door_check = checkDoorPassable(lidar_scan_data, wheelchair_pose, door_center, odometry_mode, door_params);
        result.door_state = door_check.door_state;

        if door_check.verified
            fprintf('Door detected as OPEN - waiting 2 seconds before moving forward...\n');
            pause(2); % Wait 2 seconds after detecting door is open
            door_verified = true;
            result.V = [0; 0]; % Stop after detection
        elseif strcmp(door_check.door_state, 'closed')
            % Door closed - use idle motion to trigger door sensor
            fprintf('Door CLOSED - performing idle motion to trigger sensor...\n');

            % Generate idle motion commands (alternates forward/backward each call)
            idle_params = struct();
            idle_params.IDLE_SPEED = 0.05;  % 5 cm/s
            idle_params.should_pause = idle_phase_active;  % Only pause if idle phase already active

            idle_result = idleMotionForDoorSensor(idle_params);
            result.V = idle_result.V;
            result.status = sprintf('Phase 2.5: %s', idle_result.status);

            % Activate idle phase AFTER idle motion command (prevents oscillation, but allows first turn to complete)
            if ~idle_phase_active
                idle_phase_active = true;
                fprintf('  Phase 2.5: ACTIVATED idle phase (Phase 2 reentry requires %.1f° error, pause enabled)\n', ...
                    rad2deg(TURN_TOLERANCE + 0.25));
            end
        else
            door_verified = true; % Proceed anyway if unknown
            result.V = [0; 0];
        end

    % Phase 3: Move through door to exit position
    else
        result.phase = 3;
        result.status = 'Moving through door';

        % Calculate target distance based on exit position
        distance_to_exit = norm(exit_position - current_position);

        % Use moveDistance for odometry tracking
        % Target distance is a reasonable fixed value (e.g., 2.0m for typical door passage)
        TARGET_DOOR_DISTANCE = 2.0; % meters
        move_result = moveDistance(TARGET_DOOR_DISTANCE, MOVE_SPEED, 'forward', distance_traveled, last_update_time);

        result.V = move_result.V;
        distance_traveled = move_result.distance_traveled;
        last_update_time = move_result.last_update_time;

        % Check if we've reached the exit position (primary check)
        if distance_to_exit <= 0.15 || move_result.completed
            % Phase 4: Completed
            result.phase = 4;
            result.status = 'Door entry completed';
            result.V = [0; 0];
            result.completed = true;

            % Reset persistent variables for next door
            phase1_completed = [];
            door_verified = [];
            distance_traveled = [];
            last_update_time = [];
            idle_phase_active = [];  % Reset idle phase flag for next door
        end
    end
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end

function params = getDefaultDoorParams()
    % Default door parameters
    params = struct();

    % Phase 1: Position Correction
    params.POSITION_TOLERANCE = 0.15;          % ±15cm acceptable distance error
    params.POSITION_ANGLE_TOLERANCE = 0.087;   % ±5 degrees acceptable heading error
    params.CORRECTION_TURN_SPEED = 0.3;        % rad/s for correction turns
    params.CORRECTION_MOVE_SPEED = 0.15;       % m/s for correction movement

    % Phase 2: Turning towards door
    params.TURN_TOLERANCE = 0.1;               % radians (~6 degrees)
    params.TURN_SPEED = 0.1;                   % rad/s for turning

    % Phase 2.5: Door Detection
    params.ANGLE_TOLERANCE = 30;               % ±30 degrees cone towards door
    params.NARROW_ROI_ANGLE = 12;              % ±12 degrees for safe passage
    params.DOOR_HEIGHT_MIN = 0.5;              % Minimum height (avoid floor)
    params.DOOR_HEIGHT_MAX = 1.7;              % Maximum door height
    params.MIN_POINTS_THRESHOLD = 5;           % Minimum points for analysis
    params.DEPTH_THRESHOLD = 0.3;              % Depth difference threshold

    % Phase 3: Movement through door
    params.MOVE_SPEED = 0.2;                   % m/s for forward movement
end
