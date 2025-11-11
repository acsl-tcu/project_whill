function [waypoint_segments, room_sequence, total_distance] = HybridPathPlanner(start_position, goal_position, roomGraph, robot_width, robot_length, safety_margin, occupancyMap)
    % HybridPathPlanner - Combines Dijkstra (room-level) with A* (geometric)
    %
    % This function performs two-level path planning:
    %   1. Use Dijkstra to find shortest room sequence through doors
    %   2. Use A* within each room to plan collision-free geometric paths
    %
    % Inputs:
    %   start_position - [x, y] starting position in world coordinates
    %   goal_position - [x, y] goal position in world coordinates
    %   roomGraph - RoomGraphWithDoorDistances object (passed from PhaseManager)
    %   robot_width - wheelchair width in meters
    %   robot_length - wheelchair length in meters
    %   safety_margin - safety clearance in meters
    %   occupancyMap - Occupancy map object (passed from PhaseManager)
    %
    % Outputs:
    %   waypoint_segments - cell array of waypoint matrices, one per room
    %                      Each segment is Nx2 matrix of [x, y] waypoints
    %   room_sequence - cell array of room IDs in the path
    %   total_distance - total path distance in meters
    %
    % Example:
    %   [segments, rooms, dist] = HybridPathPlanner([10, 5], [35, 10], ...
    %       roomGraph, 0.6, 1.0, 0.1, occupancyMap);
    %
    % Returns:
    %   segments{1} = waypoints from start to first door (in room 1)
    %   segments{2} = waypoints from first door to second door (in room 2)
    %   segments{3} = waypoints from last door to goal (in final room)

    fprintf('\n╔══════════════════════════════════════════════════╗\n');
    fprintf('║   HYBRID PATH PLANNER (Dijkstra + A*)           ║\n');
    fprintf('╚══════════════════════════════════════════════════╝\n\n');

    % Print map and robot info once (instead of per segment)
    fprintf('Map: %dx%d cells (%.1f cells/m) | Robot: %.2fm x %.2fm\n', ...
            size(getOccupancy(occupancyMap), 1), size(getOccupancy(occupancyMap), 2), ...
            occupancyMap.Resolution, robot_width, robot_length);
    fprintf('Planning: [%.2f, %.2f] → [%.2f, %.2f]\n\n', ...
            start_position(1), start_position(2), goal_position(1), goal_position(2));

    %% Step 1: Use provided room graph
    fprintf('STEP 1: Using room graph...\n');

    if isempty(roomGraph)
        error('Room graph not provided! Must be passed from PhaseManager.');
    end

    graph = roomGraph;

    %% Step 2: Find which rooms contain start and goal
    fprintf('STEP 2: Start [%.2f, %.2f] → Room %s | Goal [%.2f, %.2f] → Room %s\n', ...
            start_position(1), start_position(2), graph.findRoomContaining(start_position), ...
            goal_position(1), goal_position(2), graph.findRoomContaining(goal_position));

    start_room_id = graph.findRoomContaining(start_position);
    goal_room_id = graph.findRoomContaining(goal_position);

    if isempty(start_room_id)
        error('Start position [%.2f, %.2f] is not in any room!', start_position(1), start_position(2));
    end
    if isempty(goal_room_id)
        error('Goal position [%.2f, %.2f] is not in any room!', goal_position(1), goal_position(2));
    end

    %% Step 3: Use Dijkstra to find shortest room sequence
    fprintf('STEP 3: Planning room sequence using Dijkstra...\n');

    [room_sequence, door_sequence, dijkstra_cost] = graph.findRoomPath(start_room_id, goal_room_id, start_position, goal_position);

    if isempty(room_sequence)
        error('No path found between Room %s and Room %s', start_room_id, goal_room_id);
    end

    % Build path string
    path_str = room_sequence{1};
    for i = 2:length(room_sequence)
        path_str = [path_str, ' → ', room_sequence{i}];
    end

    fprintf('  Path: %s (cost: %.2fm)\n', path_str, dijkstra_cost);

    %% Step 4: Build subgoals for each room segment
    fprintf('STEP 4: Building %d subgoals\n', 2 + 2*(length(room_sequence)-1));

    % Create list of subgoals (start, astar_goal positions, goal)
    subgoals = [start_position];  % Start with starting position

    % Add BOTH astar_goal positions for each door (exit + entry)
    for i = 1:length(room_sequence)-1
        current_room_id = room_sequence{i};
        next_room_id = room_sequence{i+1};

        % Get door from current room's perspective (for exit position)
        current_room = graph.rooms(current_room_id);
        door_from_current = current_room.getDoorTo(next_room_id);

        % Get door from next room's perspective (for entry position)
        next_room = graph.rooms(next_room_id);
        door_from_next = next_room.getDoorTo(current_room_id);

        if ~isempty(door_from_current) && ~isempty(door_from_next)
            % Add exit position (stop before door in current room)
            subgoals = [subgoals; door_from_current.astar_goal];

            % Add entry position (start after door in next room)
            subgoals = [subgoals; door_from_next.astar_goal];

            fprintf('  Room %s → %s:\n', current_room_id, next_room_id);
            fprintf('    Exit at [%.2f, %.2f] (door at [%.2f, %.2f])\n', ...
                door_from_current.astar_goal(1), door_from_current.astar_goal(2), ...
                door_from_current.door_center(1), door_from_current.door_center(2));
            fprintf('    Entry at [%.2f, %.2f]\n', ...
                door_from_next.astar_goal(1), door_from_next.astar_goal(2));
        end
    end

    % Add goal position
    subgoals = [subgoals; goal_position];

    fprintf('  Total subgoals: %d (start + %d door pairs + goal)\n\n', ...
        size(subgoals, 1), (length(room_sequence) - 1) * 2);

    %% Step 5: Use A* to plan geometric path in each room segment
    fprintf('STEP 5: Planning A* segments...\n');

    waypoint_segments = {};
    total_distance = 0;
    segment_count = 0;

    % Plan path for each segment (skip door crossings - use different algorithm)
        for i = 1:length(subgoals)-1
            segment_start = subgoals(i, :);
            segment_goal = subgoals(i+1, :);

            % Determine if this is a door crossing segment (even index, except last)
            is_door_crossing = (mod(i, 2) == 0) && (i < length(subgoals)-1);

            if is_door_crossing
                continue;  % Skip A* planning for door crossings
            end

            segment_count = segment_count + 1;

            % Determine which room and segment type
            if i == 1
                segment_type = sprintf('Start → Exit door (Room %s)', room_sequence{1});
            elseif i == length(subgoals)-1
                room_idx = length(room_sequence);
                segment_type = sprintf('Entry door → Goal (Room %s)', room_sequence{room_idx});
            else
                room_idx = (i + 1) / 2 + 1;
                if room_idx <= length(room_sequence)
                    segment_type = sprintf('Entry → Exit (Room %s)', room_sequence{room_idx});
                else
                    segment_type = 'Unknown';
                end
            end

            fprintf('  Segment %d: %s\n', segment_count, segment_type);

            % Call PathSetting_AStar for this segment (pass map to avoid reloading)
            [waypoints, ~, ~, ~, ~] = PathSetting_AStar(segment_start, segment_goal, ...
                robot_width, robot_length, safety_margin, occupancyMap);

            if isempty(waypoints)
                error('A* failed for segment %d', segment_count);
            end

            % Calculate segment distance
            segment_dist = 0;
            for j = 1:size(waypoints, 1)-1
                segment_dist = segment_dist + norm(waypoints(j+1, :) - waypoints(j, :));
            end

            fprintf('    A* found %d waypoints, distance: %.2f m\n', ...
                size(waypoints, 1), segment_dist);

            % Store segment
            waypoint_segments{segment_count} = waypoints;
            total_distance = total_distance + segment_dist;
        end

    %% Summary
    fprintf('\n✓ Path complete: %d waypoints, %.2fm total\n', ...
            sum(cellfun(@(x) size(x,1), waypoint_segments)), total_distance);
    fprintf('  %d segments across rooms: %s\n\n', length(waypoint_segments), path_str);
end
