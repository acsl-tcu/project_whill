classdef RoomGraphWithDoorDistances < handle
    % RoomGraphWithDoorDistances - Graph with door-to-door distance costs
    %
    % Uses actual door-to-door distances for path cost calculation
    % State: (current_room, entry_door) to track which door we entered from

    properties
        rooms  % containers.Map: room_id -> RoomNode object
    end

    methods
        function obj = RoomGraphWithDoorDistances()
            % Constructor - initialize empty room map
            obj.rooms = containers.Map();
        end

        function addRoom(obj, room_node)
            % Add a room to the graph
            if ~isa(room_node, 'RoomNode')
                error('Input must be a RoomNode object');
            end
            obj.rooms(room_node.id) = room_node;
            fprintf('[RoomGraph] Added room %s (center: [%.2f, %.2f])\n', ...
                room_node.id, room_node.center(1), room_node.center(2));
        end

        function room = getRoom(obj, room_id)
            % Get a room by ID
            if ~obj.rooms.isKey(room_id)
                error('Room %s not found in graph', room_id);
            end
            room = obj.rooms(room_id);
        end

        function room_id = findRoomContaining(obj, position)
            % Find which room contains a given position
            room_id = [];
            room_keys = keys(obj.rooms);

            for i = 1:length(room_keys)
                room = obj.rooms(room_keys{i});
                if room.isInside(position)
                    room_id = room.id;
                    return;
                end
            end

            fprintf('[RoomGraph] Warning: Position [%.2f, %.2f] not found in any room\n', ...
                position(1), position(2));
        end

        function [room_sequence, door_sequence, total_cost] = findRoomPath(obj, start_room_id, goal_room_id, start_pos, goal_pos)
            % Find shortest path using door-to-door distances
            % Inputs:
            %   start_room_id - ID of starting room
            %   goal_room_id - ID of goal room
            %   start_pos (optional) - [x, y] starting position (default: room center)
            %   goal_pos (optional) - [x, y] goal position (default: room center)
            % Returns: room_sequence, door_sequence (doors used), total_cost

            % Handle optional position arguments
            if nargin < 4 || isempty(start_pos)
                start_room = obj.rooms(start_room_id);
                start_pos = start_room.center;
            end
            if nargin < 5 || isempty(goal_pos)
                goal_room = obj.rooms(goal_room_id);
                goal_pos = goal_room.center;
            end

            fprintf('[RoomGraph] Planning path from room %s to room %s...\n', ...
                start_room_id, goal_room_id);

            % Validate inputs
            if ~obj.rooms.isKey(start_room_id)
                error('Start room %s not found in graph', start_room_id);
            end
            if ~obj.rooms.isKey(goal_room_id)
                error('Goal room %s not found in graph', goal_room_id);
            end

            % Same room - trivial path (direct line)
            if strcmp(start_room_id, goal_room_id)
                room_sequence = {start_room_id};
                door_sequence = {};
                total_cost = norm(goal_pos - start_pos);
                fprintf('[RoomGraph] Start and goal are the same room (cost: %.2f m)\n', total_cost);
                return;
            end

            % State: (room_id, entry_door_target) where entry_door_target is the room we came from
            % For start room, entry_door_target = 'START'

            % distances: Map of 'room_id|entry_from' -> distance
            distances = containers.Map();
            % parents: Map of 'room_id|entry_from' -> parent state
            parents = containers.Map();
            % visited
            visited = containers.Map();

            % Initialize start state
            start_state = [start_room_id, '|START'];
            distances(start_state) = 0;
            visited(start_state) = false;

            % Priority queue (simple array)
            unvisited = {start_state};

            % Main Dijkstra loop
            while ~isempty(unvisited)
                % Find state with minimum distance
                min_dist = inf;
                min_idx = -1;
                current_state = [];

                for i = 1:length(unvisited)
                    state = unvisited{i};
                    if distances(state) < min_dist
                        min_dist = distances(state);
                        min_idx = i;
                        current_state = state;
                    end
                end

                % No more reachable states
                if isinf(min_dist)
                    fprintf('[RoomGraph] ERROR: No path exists from %s to %s\n', ...
                        start_room_id, goal_room_id);
                    room_sequence = {};
                    door_sequence = {};
                    total_cost = inf;
                    return;
                end

                % Remove from unvisited
                unvisited(min_idx) = [];
                visited(current_state) = true;

                % Parse current state
                parts = strsplit(current_state, '|');
                current_room_id = parts{1};
                entry_from = parts{2};

                % Check if goal reached
                if strcmp(current_room_id, goal_room_id)
                    [room_sequence, door_sequence] = obj.reconstructPath(parents, start_state, current_state);

                    % Add distance from entry door to goal position in final room
                    if strcmp(entry_from, 'START')
                        % Only one room, shouldn't reach here (handled above)
                        final_dist = norm(goal_pos - start_pos);
                    else
                        % Get entry door to goal room
                        goal_room = obj.rooms(goal_room_id);
                        entry_door = goal_room.getDoorTo(entry_from);
                        final_dist = norm(goal_pos - entry_door.door_center);
                    end

                    total_cost = distances(current_state) + final_dist;

                    % Build path string
                    path_str = room_sequence{1};
                    for k = 2:length(room_sequence)
                        path_str = [path_str, ' → ', room_sequence{k}];
                    end
                    fprintf('[RoomGraph] Path found: %s (cost: %.2f m)\n', path_str, total_cost);
                    return;
                end

                % Explore neighbors
                current_room = obj.rooms(current_room_id);

                for i = 1:length(current_room.connections)
                    door = current_room.connections(i);
                    neighbor_id = door.target_room_id;

                    % Calculate door-to-door distance in current room
                    if strcmp(entry_from, 'START')
                        % First room - use distance from start position to exit door
                        door_to_door_dist = norm(door.door_center - start_pos);
                    else
                        % Not first room - door to door distance
                        entry_door = current_room.getDoorTo(entry_from);
                        door_to_door_dist = norm(door.door_center - entry_door.door_center);
                    end

                    % Create neighbor state
                    neighbor_state = [neighbor_id, '|', current_room_id];

                    % Initialize if first time seeing this state
                    if ~distances.isKey(neighbor_state)
                        distances(neighbor_state) = inf;
                        visited(neighbor_state) = false;
                    end

                    % Skip if already visited
                    if visited(neighbor_state)
                        continue;
                    end

                    % Calculate tentative distance
                    tentative_dist = distances(current_state) + door_to_door_dist;

                    % Update if shorter path found
                    if tentative_dist < distances(neighbor_state)
                        distances(neighbor_state) = tentative_dist;
                        parents(neighbor_state) = current_state;

                        % Add to unvisited if not already there
                        if ~any(strcmp(unvisited, neighbor_state))
                            unvisited{end+1} = neighbor_state;
                        end
                    end
                end
            end

            % If we get here, no path was found
            fprintf('[RoomGraph] ERROR: No path found from %s to %s\n', ...
                start_room_id, goal_room_id);
            room_sequence = {};
            door_sequence = {};
            total_cost = inf;
        end

        function [room_seq, door_seq] = reconstructPath(obj, parents, start_state, goal_state)
            % Reconstruct path from parent pointers
            room_seq = {};
            door_seq = {};
            current = goal_state;

            while ~strcmp(current, start_state)
                if ~parents.isKey(current)
                    error('Path reconstruction failed: no parent for state %s', current);
                end

                % Parse current state
                parts = strsplit(current, '|');
                room_id = parts{1};
                entry_from = parts{2};

                room_seq = [{room_id}, room_seq];
                if ~strcmp(entry_from, 'START')
                    door_seq = [{entry_from}, door_seq];
                end

                current = parents(current);
            end

            % Add start room
            parts = strsplit(start_state, '|');
            room_seq = [{parts{1}}, room_seq];
        end

        function visualize(obj, fig_handle)
            % Visualize the room graph (same as original)
            if nargin < 2 || isempty(fig_handle)
                fig_handle = figure('Name', 'Room Graph with Door Distances', ...
                    'Position', [100, 100, 1000, 800]);
            else
                figure(fig_handle);
            end

            clf;
            hold on;

            % Plot each room
            room_keys = keys(obj.rooms);
            colors = {[0 0 1], [1 0 0], [0 1 0], [1 0.5 0], [0.5 0 0.5], [0 0.5 0.5]};

            for i = 1:length(room_keys)
                room = obj.rooms(room_keys{i});
                color_idx = mod(i-1, length(colors)) + 1;
                room.plotRoom(fig_handle, colors{color_idx});
            end

            % Plot door-to-door connections
            for i = 1:length(room_keys)
                room = obj.rooms(room_keys{i});

                % Plot lines between all door pairs in this room
                if length(room.connections) > 1
                    for j = 1:length(room.connections)
                        for k = (j+1):length(room.connections)
                            door1 = room.connections(j);
                            door2 = room.connections(k);

                            % Draw door-to-door line
                            plot([door1.door_center(1), door2.door_center(1)], ...
                                 [door1.door_center(2), door2.door_center(2)], ...
                                 ':', 'Color', [0.7 0.7 0.7], 'LineWidth', 1);

                            % Label with distance
                            mid = (door1.door_center + door2.door_center) / 2;
                            dist = norm(door2.door_center - door1.door_center);
                            text(mid(1), mid(2), sprintf('%.1fm', dist), ...
                                'FontSize', 8, 'Color', [0.5 0.5 0.5], ...
                                'BackgroundColor', 'white');
                        end
                    end
                end
            end

            title('Room Graph - Door-to-Door Distances', 'FontSize', 14, 'FontWeight', 'bold');
            xlabel('X (meters)');
            ylabel('Y (meters)');
            grid on;
            axis equal;

            % Auto-zoom
            if ~isempty(room_keys)
                all_x = [];
                all_y = [];
                for i = 1:length(room_keys)
                    room = obj.rooms(room_keys{i});
                    all_x = [all_x, room.boundaries(1,1), room.boundaries(1,2)];
                    all_y = [all_y, room.boundaries(2,1), room.boundaries(2,2)];
                end
                margin = 2;
                xlim([min(all_x)-margin, max(all_x)+margin]);
                ylim([min(all_y)-margin, max(all_y)+margin]);
            end

            hold off;
        end

        function printDoorDistances(obj)
            % Print all door-to-door distances for debugging
            fprintf('\n=== Door-to-Door Distances ===\n');
            room_keys = keys(obj.rooms);

            for i = 1:length(room_keys)
                room = obj.rooms(room_keys{i});
                fprintf('\nRoom %s:\n', room.id);

                if length(room.connections) < 2
                    fprintf('  (Only 1 door - no internal distances)\n');
                    continue;
                end

                for j = 1:length(room.connections)
                    for k = (j+1):length(room.connections)
                        door1 = room.connections(j);
                        door2 = room.connections(k);
                        dist = norm(door2.door_center - door1.door_center);

                        fprintf('  Door to %s [%.1f,%.1f] → Door to %s [%.1f,%.1f]: %.2f m\n', ...
                            door1.target_room_id, door1.door_center(1), door1.door_center(2), ...
                            door2.target_room_id, door2.door_center(1), door2.door_center(2), ...
                            dist);
                    end
                end
            end
            fprintf('================================\n\n');
        end
    end
end
