function result = enterElevatorNew(current_position, current_yaw, elevator_center, ~, lidar_scan_data, is_gazebo, odometry_mode, door_detection_mode, door_params, target_position)
    % enterElevatorNew - Elevator entry function using general enterDoor for Phases 1-3
    %
    % This is a refactored version that:
    % - Uses enterDoor.m for Phases 1-3 (position, turning, door check, entry)
    % - Adds elevator-specific Phases 4-5 (inside waiting, floor change, exit)
    %
    % Phases:
    %   Phases 1-3: Door entry (delegated to enterDoor.m)
    %   Phase 4: Inside elevator waiting (door close, floor change, reopen)
    %   Phase 5: Reverse out of elevator
    %   Phase 6: Completed
    %
    % Inputs:
    %   current_position - [x, y] current wheelchair position
    %   current_yaw - current heading angle in radians
    %   elevator_center - [x, y] position of elevator center
    %   (4th parameter unused - backward compatibility)
    %   lidar_scan_data - struct with xyz_global and xyz_local point cloud
    %   is_gazebo - boolean flag for Gazebo simulation
    %   odometry_mode - boolean: true = local coords, false = global coords
    %   door_detection_mode - boolean: true = debug mode (bypass Phase 1)
    %   door_params - struct with door detection parameters
    %   target_position - [x, y] Phase 1 target position (from metadata)
    %
    % Outputs:
    %   result - struct with control commands and status

    persistent entry_completed; % Track if door entry (Phases 1-3) is done
    persistent elevator_sequence_state; % 'entering', 'door_closed', 'inside_waiting', 'reversing'
    persistent sequence_timer;
    persistent current_floor;
    persistent target_floor;
    persistent floor_input_requested;
    persistent phase5_distance_to_reverse; % Distance to reverse in Phase 5
    persistent last_update_time_reverse;

    % Initialize persistent variables
    if isempty(entry_completed)
        entry_completed = false;
    end
    if isempty(elevator_sequence_state)
        elevator_sequence_state = 'entering';
    end
    if isempty(sequence_timer)
        sequence_timer = 0;
    end
    if isempty(current_floor)
        current_floor = 4;
    end
    if isempty(target_floor)
        target_floor = 1;
    end
    if isempty(floor_input_requested)
        floor_input_requested = false;
    end
    if isempty(phase5_distance_to_reverse)
        phase5_distance_to_reverse = 0;
    end

    % Default parameters
    if nargin < 3
        elevator_center = [27, 12.2];
    end
    if nargin < 6
        is_gazebo = false;
    end
    if nargin < 7 || isempty(odometry_mode)
        odometry_mode = false;
    end
    if nargin < 8 || isempty(door_detection_mode)
        door_detection_mode = false;
    end
    if nargin < 9 || isempty(door_params)
        door_params = getDefaultElevatorParams();
    end

    % Calculate exit position (inside elevator = elevator_center + offset forward)
    direction_to_elevator = elevator_center - current_position;
    direction_angle = atan2(direction_to_elevator(2), direction_to_elevator(1));
    entry_distance = door_params.MOVE_DISTANCE; % How far into elevator to move
    exit_position = elevator_center + entry_distance * [cos(direction_angle), sin(direction_angle)];

    % Initialize result
    result = struct();
    result.completed = false;
    result.V = [0; 0];

    fprintf('\n=== ENTERING ELEVATOR (Refactored) ===\n');
    fprintf('State: %s\n', elevator_sequence_state);

    % State machine
    switch elevator_sequence_state
        case 'entering'
            % Phases 1-3: Use general enterDoor function
            if door_detection_mode
                fprintf('*** DOOR DETECTION MODE ACTIVE ***\n');
            end

            % Call general enterDoor for door entry sequence
            door_result = enterDoor(current_position, current_yaw, elevator_center, ...
                                    exit_position, lidar_scan_data, door_params, 'elevator');

            % Pass through all door entry result fields
            result.phase = door_result.phase;
            result.status = door_result.status;
            result.V = door_result.V;
            if isfield(door_result, 'door_state')
                result.door_state = door_result.door_state;
            end

            % Check if door entry completed
            if door_result.completed
                entry_completed = true;
                elevator_sequence_state = 'door_closed';
                sequence_timer = tic;

                % Store distance traveled for Phase 5 reversal
                phase5_distance_to_reverse = entry_distance;

                fprintf('Door entry COMPLETED - entering Phase 4 (inside elevator)\n');

                % Trigger door close
                if is_gazebo
                    controlElevatorDoor('close');
                    fprintf('Simulation: Door closing (Gazebo)\n');
                end

                result.phase = 4;
                result.status = 'Inside elevator - Door closing';
                result.V = [0; 0];
            end

        case 'door_closed'
            % Phase 4: Door closed, waiting inside elevator
            result.phase = 4;
            result.status = 'Inside elevator - Door closed, waiting';
            result.V = [0; 0];

            fprintf('Phase 4: Door closed, current_floor = %d, target_floor = %d\n', ...
                    current_floor, target_floor);

            % Manual floor input (only once)
            if is_gazebo && ~floor_input_requested
                fprintf('\n========================================\n');
                fprintf('MANUAL FLOOR INPUT REQUIRED\n');
                fprintf('========================================\n');
                fprintf('Current floor: %d\n', current_floor);
                fprintf('Please enter the floor number:\n');
                user_floor = input('Floor number: ');

                if ~isempty(user_floor) && isnumeric(user_floor) && user_floor > 0
                    current_floor = user_floor;
                    floor_input_requested = true;
                    fprintf('Floor set to: %d\n', current_floor);
                end
                fprintf('========================================\n\n');
            end

            % Proceed to door opening
            if current_floor == target_floor
                fprintf('Phase 4: Reached target floor - opening door\n');

                if is_gazebo
                    controlElevatorDoor('open');
                    fprintf('Simulation: Door opening (Gazebo)\n');
                end

                elevator_sequence_state = 'inside_waiting';
            end

        case 'inside_waiting'
            % Phase 4: Waiting for door to open (LiDAR detection)
            result.phase = 4;
            result.status = 'Inside elevator - Detecting door opening';
            result.V = [0; 0];

            % Detect door opening using LiDAR
            if ~isempty(lidar_scan_data)
                wheelchair_pose = [current_position, current_yaw];

                % Extract point cloud
                if isstruct(lidar_scan_data) && isfield(lidar_scan_data, 'xyz_global')
                    pointCloud = lidar_scan_data.xyz_global;
                else
                    pointCloud = lidar_scan_data;
                end

                % Detect door state (looking toward hallway/target_position)
                door_state = detectElevatorDoorState(pointCloud{1}, wheelchair_pose, ...
                                                      target_position, false, door_params);

                if strcmp(door_state, 'open')
                    fprintf('Phase 4: Door confirmed OPEN - ready to reverse\n');
                    elevator_sequence_state = 'reversing';
                    sequence_timer = tic;
                else
                    fprintf('Phase 4: Door state: %s - waiting...\n', door_state);
                end
            else
                % Fallback: proceed after 2 seconds
                if toc(sequence_timer) > 2.0
                    elevator_sequence_state = 'reversing';
                    sequence_timer = tic;
                end
            end

        case 'reversing'
            % Phase 5: Reverse out of elevator
            result.phase = 5;
            result.status = 'Reversing out of elevator';

            % Calculate time elapsed
            if isempty(last_update_time_reverse)
                dt = 0;
                last_update_time_reverse = tic;
            else
                dt = toc(last_update_time_reverse);
                last_update_time_reverse = tic;
            end

            % Failsafe
            if dt > 0.5
                dt = 0;
            end

            % Reduce distance counter
            MOVE_SPEED = door_params.MOVE_SPEED;
            phase5_distance_to_reverse = phase5_distance_to_reverse - (MOVE_SPEED * dt);

            fprintf('Phase 5: Distance remaining: %.2f m\n', phase5_distance_to_reverse);

            if phase5_distance_to_reverse > 0.1
                result.V(1) = -MOVE_SPEED; % Reverse
                result.V(2) = 0;
            else
                % Phase 6: Completed
                result.phase = 6;
                result.status = 'Elevator sequence completed';
                result.V = [0; 0];
                result.completed = true;

                fprintf('Elevator sequence COMPLETED!\n');

                % Reset persistent variables
                entry_completed = [];
                elevator_sequence_state = 'entering';
                sequence_timer = [];
                current_floor = 4;
                target_floor = 1;
                floor_input_requested = [];
                phase5_distance_to_reverse = [];
                last_update_time_reverse = [];
            end
    end

    fprintf('Command: V=[%.2f, %.2f]\n', result.V(1), result.V(2));
    fprintf('====================================\n');
end

function params = getDefaultElevatorParams()
    % Default elevator parameters
    params = struct();
    params.POSITION_TOLERANCE = 0.15;
    params.POSITION_ANGLE_TOLERANCE = 0.087;
    params.CORRECTION_TURN_SPEED = 0.3;
    params.CORRECTION_MOVE_SPEED = 0.15;
    params.TURN_TOLERANCE = 0.1;
    params.TURN_SPEED = 0.1;
    params.ANGLE_TOLERANCE = 30;
    params.NARROW_ROI_ANGLE = 12;
    params.DOOR_HEIGHT_MIN = 0.5;
    params.DOOR_HEIGHT_MAX = 1.7;
    params.MIN_POINTS_THRESHOLD = 5;
    params.DEPTH_THRESHOLD = 0.3;
    params.MOVE_DISTANCE = 2.60;  % Increased by 10cm total for deeper elevator entry
    params.MOVE_SPEED = 0.2;
end
