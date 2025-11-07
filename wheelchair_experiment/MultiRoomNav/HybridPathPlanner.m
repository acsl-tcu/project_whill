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

    %% Step 1: Use provided room graph
    fprintf('STEP 1: Using room graph from PhaseManager...\n');
    fprintf('─────────────────────────────────────────────────────\n');

    if isempty(roomGraph)
        error('Room graph not provided! Must be passed from PhaseManager.');
    end

    graph = roomGraph;
    fprintf('  Room graph loaded: %d rooms\n\n', graph.rooms.Count);

    %% Step 2: Find which rooms contain start and goal
    fprintf('STEP 2: Detecting rooms for start and goal positions...\n');
    fprintf('─────────────────────────────────────────────────────\n');

    start_room_id = graph.findRoomContaining(start_position);
    goal_room_id = graph.findRoomContaining(goal_position);

    if isempty(start_room_id)
        error('Start position [%.2f, %.2f] is not in any room!', start_position(1), start_position(2));
    end
    if isempty(goal_room_id)
        error('Goal position [%.2f, %.2f] is not in any room!', goal_position(1), goal_position(2));
    end

    fprintf('  Start [%.2f, %.2f] is in Room %s\n', start_position(1), start_position(2), start_room_id);
    fprintf('  Goal [%.2f, %.2f] is in Room %s\n\n', goal_position(1), goal_position(2), goal_room_id);

    %% Step 3: Use Dijkstra to find shortest room sequence
    fprintf('STEP 3: Planning room sequence using Dijkstra...\n');
    fprintf('─────────────────────────────────────────────────────\n');

    [room_sequence, door_sequence, dijkstra_cost] = graph.findRoomPath(start_room_id, goal_room_id, start_position, goal_position);

    if isempty(room_sequence)
        error('No path found between Room %s and Room %s', start_room_id, goal_room_id);
    end

    % Build path string
    path_str = room_sequence{1};
    for i = 2:length(room_sequence)
        path_str = [path_str, ' → ', room_sequence{i}];
    end

    fprintf('  Path found: %s\n', path_str);
    fprintf('  Number of rooms: %d\n', length(room_sequence));
    fprintf('  Number of doors: %d\n', length(room_sequence) - 1);
    fprintf('  Dijkstra cost: %.2f m\n\n', dijkstra_cost);

    %% Step 4: Build subgoals for each room segment
    fprintf('STEP 4: Building subgoals for A* planning...\n');
    fprintf('─────────────────────────────────────────────────────\n');

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
    fprintf('STEP 5: Planning geometric paths using A* for each segment...\n');
    fprintf('─────────────────────────────────────────────────────\n');

    waypoint_segments = {};
    total_distance = 0;
    segment_count = 0;

    % Plan path for each segment (skip door crossings - use different algorithm)
        for i = 1:length(subgoals)-1
            segment_start = subgoals(i, :);
            segment_goal = subgoals(i+1, :);

            % Determine if this is a door crossing segment (even index, except last)
            % Pattern: start, exit1, entry1, exit2, entry2, ..., goal
            % Odd segments (1,3,5,...): Use A* within rooms
            % Even segments (2,4,6,...): Door crossings (skip A*, use separate algorithm)
            is_door_crossing = (mod(i, 2) == 0) && (i < length(subgoals)-1);

            if is_door_crossing
                fprintf('\n  Skipping segment %d/%d: [%.2f, %.2f] → [%.2f, %.2f]\n', ...
                    i, length(subgoals)-1, ...
                    segment_start(1), segment_start(2), ...
                    segment_goal(1), segment_goal(2));
                fprintf('    Type: DOOR CROSSING (use separate algorithm, not A*)\n');
                continue;  % Skip A* planning for door crossings
            end

            segment_count = segment_count + 1;
            fprintf('\n  Planning segment %d: [%.2f, %.2f] → [%.2f, %.2f]\n', ...
                segment_count, ...
                segment_start(1), segment_start(2), ...
                segment_goal(1), segment_goal(2));

            % Determine which room this segment belongs to
            if i == 1
                fprintf('    Type: Start → Exit door (Room %s)\n', room_sequence{1});
            elseif i == length(subgoals)-1
                % Last segment: from last entry to goal
                room_idx = length(room_sequence);
                fprintf('    Type: Entry door → Goal (Room %s)\n', room_sequence{room_idx});
            else
                % Other odd segments: entry → exit
                room_idx = (i + 1) / 2 + 1;
                if room_idx <= length(room_sequence)
                    fprintf('    Type: Entry door → Exit door (Room %s)\n', room_sequence{room_idx});
                end
            end

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
    fprintf('\n╔══════════════════════════════════════════════════╗\n');
    fprintf('║   HYBRID PATH PLANNING COMPLETE                  ║\n');
    fprintf('╚══════════════════════════════════════════════════╝\n\n');

    fprintf('Room sequence: %s\n', path_str);
    fprintf('Number of segments: %d\n', length(waypoint_segments));
    fprintf('Total waypoints: %d\n', sum(cellfun(@(x) size(x,1), waypoint_segments)));
    fprintf('Dijkstra cost: %.2f m\n', dijkstra_cost);
    fprintf('A* total distance: %.2f m\n', total_distance);
    fprintf('Difference: %.2f m (%.1f%%)\n\n', ...
        total_distance - dijkstra_cost, ...
        100 * (total_distance - dijkstra_cost) / dijkstra_cost);

    fprintf('Waypoint segments breakdown:\n');
    for i = 1:length(waypoint_segments)
        % Determine which room this segment belongs to
        % Pattern: start, exit1, entry1, exit2, entry2, ..., goal
        % Segment 1: start → exit1 (room 1)
        % Segment 2: entry1 → exit2 or goal (room 2)
        % Segment 3: entry2 → exit3 or goal (room 3)
        if i == 1
            room_idx = 1;
        elseif mod(i, 2) == 0
            % Even segments: entry → exit (in next room)
            room_idx = i/2 + 1;
        else
            % Odd segments after first: shouldn't happen with proper door pairs
            room_idx = ceil(i/2);
        end

        if room_idx <= length(room_sequence)
            fprintf('  Segment %d (Room %s): %d waypoints\n', ...
                i, room_sequence{room_idx}, size(waypoint_segments{i}, 1));
        else
            fprintf('  Segment %d: %d waypoints\n', ...
                i, size(waypoint_segments{i}, 1));
        end
    end
    fprintf('\n');
end
