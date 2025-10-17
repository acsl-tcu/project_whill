function [navigation_state, control_cmd] = executeMultiRoomNavigation(current_position, current_yaw, lidar_scan_data, door_params)
    % executeMultiRoomNavigation - Execute multi-room navigation with door crossings
    %
    % This function manages the complete multi-room navigation sequence:
    %   1. Follows A* waypoints within each room
    %   2. At door crossings, switches to enterDoor algorithm
    %   3. Resumes A* waypoints after door crossing
    %   4. Repeats until goal reached
    %
    % Usage in Control.m:
    %   First call: Initialize with HybridPathPlanner
    %   Subsequent calls: Execute current segment/door crossing
    %
    % Inputs:
    %   current_position - [x, y] current wheelchair position
    %   current_yaw - current heading angle in radians
    %   lidar_scan_data - struct with point cloud data for door detection
    %   door_params - struct with door entry parameters
    %
    % Outputs:
    %   navigation_state - struct with:
    %       .initialized - boolean, true if path planning done
    %       .completed - boolean, true when goal reached
    %       .current_segment - which room segment (1, 2, ...)
    %       .current_door - which door crossing (0 = none, 1, 2, ...)
    %       .mode - 'planning', 'following', 'door_crossing', 'completed'
    %       .status - string description of current state
    %       .waypoint_segments - cell array of waypoint paths
    %       .room_sequence - cell array of room IDs
    %       .door_centers - array of door center positions
    %       .door_exit_positions - array of exit positions after doors
    %   control_cmd - struct with:
    %       .V - [linear_vel; angular_vel] control commands
    %       .target_waypoint - current target waypoint [x, y]

    persistent state; % Navigation state (persists across calls)

    % Initialize on first call or after reset
    if isempty(state) || ~isfield(state, 'initialized') || ~state.initialized
        fprintf('\n╔══════════════════════════════════════════════════╗\n');
        fprintf('║  MULTI-ROOM NAVIGATION - INITIALIZATION          ║\n');
        fprintf('╚══════════════════════════════════════════════════╝\n\n');

        state = struct();
        state.initialized = false;
        state.completed = false;
        state.current_segment = 0;
        state.current_door = 0;
        state.mode = 'planning';
        state.status = 'Not initialized - call planMultiRoomPath first';
        state.waypoint_segments = {};
        state.room_sequence = {};
        state.door_centers = [];
        state.door_exit_positions = [];
        state.current_waypoint_index = 1;
    end

    % Initialize control command
    control_cmd = struct();
    control_cmd.V = [0; 0];
    control_cmd.target_waypoint = [];

    % Return current state
    navigation_state = state;

    fprintf('\n=== MULTI-ROOM NAVIGATION ===\n');
    fprintf('Mode: %s\n', state.mode);
    fprintf('Status: %s\n', state.status);

    % State machine
    switch state.mode
        case 'planning'
            fprintf('ERROR: Path not planned yet. Call planMultiRoomPath first.\n');
            control_cmd.V = [0; 0];

        case 'following'
            % Following A* waypoints within current room segment
            if state.current_segment > length(state.waypoint_segments)
                % All segments completed
                state.mode = 'completed';
                state.completed = true;
                state.status = 'Goal reached!';
                control_cmd.V = [0; 0];
                fprintf('GOAL REACHED! Navigation completed.\n');
                return;
            end

            % Get current segment waypoints
            waypoints = state.waypoint_segments{state.current_segment};
            room_id = state.room_sequence{state.current_segment};

            fprintf('Segment %d/%d (Room %s): Following waypoint %d/%d\n', ...
                    state.current_segment, length(state.waypoint_segments), ...
                    room_id, state.current_waypoint_index, size(waypoints, 1));

            % Check if reached current waypoint
            target_waypoint = waypoints(state.current_waypoint_index, :);
            distance_to_waypoint = norm(target_waypoint - current_position);

            fprintf('Distance to waypoint [%.2f, %.2f]: %.2f m\n', ...
                    target_waypoint(1), target_waypoint(2), distance_to_waypoint);

            if distance_to_waypoint < 0.3 % Waypoint reached (30cm tolerance)
                state.current_waypoint_index = state.current_waypoint_index + 1;

                if state.current_waypoint_index > size(waypoints, 1)
                    % Segment completed - check if door crossing needed
                    fprintf('Segment %d completed!\n', state.current_segment);

                    if state.current_segment < length(state.waypoint_segments)
                        % More segments ahead - switch to door crossing mode
                        state.current_door = state.current_segment; % Door index
                        state.mode = 'door_crossing';
                        state.status = sprintf('Entering door %d', state.current_door);
                        fprintf('Switching to DOOR CROSSING mode (door %d)\n', state.current_door);
                    else
                        % Final segment completed
                        state.mode = 'completed';
                        state.completed = true;
                        state.status = 'Goal reached!';
                    end

                    control_cmd.V = [0; 0]; % Stop before door
                    return;
                end

                target_waypoint = waypoints(state.current_waypoint_index, :);
                distance_to_waypoint = norm(target_waypoint - current_position);
            end

            % Pure pursuit or simple controller to follow waypoint
            control_cmd = computeWaypointFollowingControl(current_position, current_yaw, ...
                                                          target_waypoint, door_params);
            control_cmd.target_waypoint = target_waypoint;

        case 'door_crossing'
            % Crossing door between segments
            fprintf('Door crossing %d: Entering door...\n', state.current_door);

            % Get door info
            door_center = state.door_centers(state.current_door, :);
            exit_position = state.door_exit_positions(state.current_door, :);

            % Call enterDoor function
            door_result = enterDoor(current_position, current_yaw, door_center, ...
                                    exit_position, lidar_scan_data, door_params, 'regular');

            % Pass through control commands
            control_cmd.V = door_result.V;
            state.status = door_result.status;

            if door_result.completed
                % Door crossing completed - move to next segment
                fprintf('Door crossing %d completed!\n', state.current_door);
                state.current_segment = state.current_segment + 1;
                state.current_waypoint_index = 1; % Reset for next segment
                state.mode = 'following';
                state.status = sprintf('Following segment %d', state.current_segment);
            end

        case 'completed'
            fprintf('Navigation completed! All segments done.\n');
            control_cmd.V = [0; 0];
            state.status = 'Completed';

        otherwise
            fprintf('ERROR: Unknown navigation mode: %s\n', state.mode);
            control_cmd.V = [0; 0];
    end

    % Update navigation state output
    navigation_state = state;

    fprintf('Control: V=[%.2f, %.2f]\n', control_cmd.V(1), control_cmd.V(2));
    fprintf('=============================\n');
end

function control_cmd = computeWaypointFollowingControl(current_position, current_yaw, target_waypoint, door_params)
    % Simple proportional controller for waypoint following
    %
    % Returns control commands to move towards target waypoint

    control_cmd = struct();

    % Calculate direction to target
    direction = target_waypoint - current_position;
    distance = norm(direction);
    target_angle = atan2(direction(2), direction(1));

    % Calculate heading error
    heading_error = angdiff(target_angle, current_yaw);

    % Control parameters
    K_linear = 0.3;  % Linear velocity gain
    K_angular = 1.0; % Angular velocity gain
    max_linear_vel = door_params.MOVE_SPEED;
    max_angular_vel = door_params.TURN_SPEED * 2; % Allow faster turning during following

    % Compute velocities
    % If heading error is large, prioritize turning
    if abs(heading_error) > 0.3 % ~17 degrees
        linear_vel = 0.1 * max_linear_vel; % Slow down during turn
    else
        linear_vel = min(K_linear * distance, max_linear_vel);
    end

    angular_vel = K_angular * heading_error;
    angular_vel = max(-max_angular_vel, min(max_angular_vel, angular_vel));

    control_cmd.V = [linear_vel; angular_vel];
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate shortest angular difference between two angles
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end

function planMultiRoomPath(start_position, goal_position, room_database_path, robot_width, robot_length, safety_margin, door_params)
    % planMultiRoomPath - Initialize navigation by planning complete path
    %
    % This function should be called ONCE before starting navigation to:
    %   1. Run HybridPathPlanner to get waypoint segments and room sequence
    %   2. Extract door positions from room database
    %   3. Initialize navigation state
    %
    % Call this function separately before entering the navigation loop

    global NAV_STATE; % Use global to pass state to executeMultiRoomNavigation

    fprintf('\n╔══════════════════════════════════════════════════╗\n');
    fprintf('║  PLANNING MULTI-ROOM PATH                        ║\n');
    fprintf('╚══════════════════════════════════════════════════╝\n\n');

    % Call HybridPathPlanner
    [waypoint_segments, room_sequence, total_distance] = HybridPathPlanner(...
        start_position, goal_position, room_database_path, ...
        robot_width, robot_length, safety_margin);

    % Load room database to extract door information
    db = RoomDatabase(room_database_path);
    graph = db.buildGraph();

    % Extract door centers and exit positions
    num_doors = length(room_sequence) - 1;
    door_centers = zeros(num_doors, 2);
    door_exit_positions = zeros(num_doors, 2);

    for i = 1:num_doors
        current_room_id = room_sequence{i};
        next_room_id = room_sequence{i+1};

        % Get door from current room
        current_room = graph.rooms(current_room_id);
        door_obj = current_room.getDoorTo(next_room_id);

        % Get door from next room (for exit position)
        next_room = graph.rooms(next_room_id);
        door_obj_next = next_room.getDoorTo(current_room_id);

        if ~isempty(door_obj) && ~isempty(door_obj_next)
            door_centers(i, :) = door_obj.door_center;
            door_exit_positions(i, :) = door_obj_next.astar_goal; % Exit = entry of next room
        end
    end

    % Initialize global navigation state
    NAV_STATE = struct();
    NAV_STATE.initialized = true;
    NAV_STATE.completed = false;
    NAV_STATE.current_segment = 1; % Start with first segment
    NAV_STATE.current_door = 0;
    NAV_STATE.mode = 'following';
    NAV_STATE.status = 'Following segment 1';
    NAV_STATE.waypoint_segments = waypoint_segments;
    NAV_STATE.room_sequence = room_sequence;
    NAV_STATE.door_centers = door_centers;
    NAV_STATE.door_exit_positions = door_exit_positions;
    NAV_STATE.current_waypoint_index = 1;
    NAV_STATE.total_distance = total_distance;

    fprintf('\n╔══════════════════════════════════════════════════╗\n');
    fprintf('║  PATH PLANNING COMPLETE                          ║\n');
    fprintf('╚══════════════════════════════════════════════════╝\n\n');
    fprintf('Room sequence: %s\n', strjoin(room_sequence, ' → '));
    fprintf('Number of segments: %d\n', length(waypoint_segments));
    fprintf('Number of doors: %d\n', num_doors);
    fprintf('Total distance: %.2f m\n', total_distance);
    fprintf('\nReady to start navigation!\n\n');
end
