function [waypoint, room_sequence, door_info] = selectWaypointMethod(initial_position, goal_position, robot_width, robot_length, safety_margin)
    % Select waypoint generation method - interactive, A*, or multi-room navigation
    %
    % Inputs:
    %   initial_position - [x, y] starting position
    %   goal_position - [x, y] goal position
    %   robot_width - Width of robot in meters
    %   robot_length - Length of robot in meters
    %   safety_margin - Safety margin for obstacle clearance
    %
    % Outputs:
    %   waypoint - Cell array of waypoint segments {segment1, segment2, ...}
    %              Single-room: {Nx2}, Multi-room: {M1x2, M2x2, ...}
    %              Multi-room mode is auto-detected by length(waypoint) > 1
    %   room_sequence - Cell array of room IDs (empty if single-room)
    %   door_info - Struct with door_centers, door_exit_positions (empty if single-room)

    fprintf('\n=== WAYPOINT SELECTION ===\n');
    fprintf('Select waypoint generation method:\n');
    fprintf('  1 - Interactive manual waypoint selection\n');
    fprintf('  2 - Automatic A* pathfinding (single room) [default]\n');
    fprintf('  3 - Multi-room navigation with door crossing\n');

    user_choice = input('Enter choice (1/2/3) [default: 2]: ', 's');

    % Initialize outputs
    room_sequence = {};
    door_info = struct();

    switch user_choice
        case '1'
            % Interactive manual selection
            fprintf('Opening interactive waypoint selection...\n');
            waypoint_matrix = interactiveWaypointSelection();

            if isempty(waypoint_matrix)
                fprintf('No waypoints selected. Falling back to A* pathfinding...\n');
                waypoint_matrix = generateAStarPath(initial_position, goal_position, robot_width, robot_length, safety_margin);
            else
                fprintf('Estimate: Using custom waypoints (%d points)\n', size(waypoint_matrix, 1));
            end

            % Wrap in cell array for unified structure
            waypoint = {waypoint_matrix};
            fprintf('Single-room mode: 1 segment with %d waypoints\n', size(waypoint_matrix, 1));

        case '3'
            % Multi-room navigation
            fprintf('\n=== MULTI-ROOM NAVIGATION MODE ===\n');
            [waypoint_first, waypoint_segments, room_sequence, door_info] = generateMultiRoomPath(...
                initial_position, goal_position, robot_width, robot_length, safety_margin);

            % Use the cell array directly (generateMultiRoomPath will be updated to return cell + door_info)
            waypoint = waypoint_segments;
            fprintf('Multi-room path generated:\n');
            fprintf('  Room sequence: %s\n', strjoin(room_sequence, ' → '));
            fprintf('  Number of segments: %d\n', length(waypoint));
            fprintf('  Segment 1: %d waypoints\n', size(waypoint{1}, 1));

        otherwise % '2' or empty (default)
            % Automatic A* pathfinding (single room)
            fprintf('Using automatic A* pathfinding (single room)...\n');
            waypoint_matrix = generateAStarPath(initial_position, goal_position, robot_width, robot_length, safety_margin);

            % Wrap in cell array for unified structure
            waypoint = {waypoint_matrix};
            fprintf('Single-room mode: 1 segment with %d waypoints\n', size(waypoint_matrix, 1));
    end

    fprintf('==========================\n\n');
end

function waypoint = generateAStarPath(initial_position, goal_position, robot_width, robot_length, safety_margin)
    % Generate path using A* algorithm with fallback to original method

    try
        [waypoint, ~, ~, ~, ~] = PathSetting_AStar(initial_position, goal_position, robot_width, robot_length, safety_margin);
        fprintf('Estimate: Using A* generated waypoints (%d points) with vehicle size %.2fx%.2fm, safety margin %.2fm\n', ...
            size(waypoint, 1), robot_width, robot_length, safety_margin);
    catch ME
        fprintf('Estimate: A* pathfinding failed (%s), using original waypoints\n', ME.message);
        [waypoint, ~, ~, ~, ~] = PathSetting_original;
    end
end
