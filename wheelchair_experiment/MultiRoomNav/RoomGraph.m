classdef RoomGraph < handle
    % RoomGraph - Graph structure for topological navigation
    %
    % Stores rooms as nodes and implements Dijkstra's algorithm
    % to find shortest room sequence between start and goal.
    %
    % Properties:
    %   rooms - Map (dictionary) of room_id -> RoomNode

    properties
        rooms  % containers.Map: room_id -> RoomNode object
    end

    methods
        function obj = RoomGraph()
            % Constructor - initialize empty room map
            obj.rooms = containers.Map();
        end

        function addRoom(obj, room_node)
            % Add a room to the graph
            % Input: room_node - RoomNode object

            if ~isa(room_node, 'RoomNode')
                error('Input must be a RoomNode object');
            end

            obj.rooms(room_node.id) = room_node;
            fprintf('[RoomGraph] Added room %s (center: [%.2f, %.2f])\n', ...
                room_node.id, room_node.center(1), room_node.center(2));
        end

        function room = getRoom(obj, room_id)
            % Get a room by ID
            % Input: room_id - room identifier
            % Output: RoomNode object or error if not found

            if ~obj.rooms.isKey(room_id)
                error('Room %s not found in graph', room_id);
            end

            room = obj.rooms(room_id);
        end

        function room_id = findRoomContaining(obj, position)
            % Find which room contains a given position
            % Input: position - [x, y] coordinates
            % Output: room_id or [] if position not in any room

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

        function [room_sequence, total_cost] = findRoomPath(obj, start_room_id, goal_room_id)
            % Find shortest path between two rooms using Dijkstra's algorithm
            % Inputs:
            %   start_room_id - ID of starting room
            %   goal_room_id  - ID of goal room
            % Outputs:
            %   room_sequence - Cell array of room IDs in order
            %   total_cost    - Total cost of the path

            fprintf('[RoomGraph] Planning path from room %s to room %s...\n', ...
                start_room_id, goal_room_id);

            % Validate inputs
            if ~obj.rooms.isKey(start_room_id)
                error('Start room %s not found in graph', start_room_id);
            end
            if ~obj.rooms.isKey(goal_room_id)
                error('Goal room %s not found in graph', goal_room_id);
            end

            % Same room - trivial path
            if strcmp(start_room_id, goal_room_id)
                room_sequence = {start_room_id};
                total_cost = 0;
                fprintf('[RoomGraph] Start and goal are the same room\n');
                return;
            end

            % Initialize Dijkstra's algorithm
            room_keys = keys(obj.rooms);
            num_rooms = length(room_keys);

            % Distance map: room_id -> distance from start
            distances = containers.Map();
            % Parent map: room_id -> previous room in shortest path
            parents = containers.Map();
            % Visited set
            visited = containers.Map();

            % Initialize all distances to infinity
            for i = 1:num_rooms
                distances(room_keys{i}) = inf;
                visited(room_keys{i}) = false;
            end
            distances(start_room_id) = 0;

            % Priority queue (simple array implementation)
            % Each element: [room_id, distance]
            unvisited = cell(num_rooms, 1);
            for i = 1:num_rooms
                unvisited{i} = room_keys{i};
            end

            % Main Dijkstra loop
            while ~isempty(unvisited)
                % Find unvisited room with minimum distance
                min_dist = inf;
                min_idx = -1;
                current_room_id = [];

                for i = 1:length(unvisited)
                    rid = unvisited{i};
                    if distances(rid) < min_dist
                        min_dist = distances(rid);
                        min_idx = i;
                        current_room_id = rid;
                    end
                end

                % No more reachable rooms
                if isinf(min_dist)
                    fprintf('[RoomGraph] ERROR: No path exists from %s to %s\n', ...
                        start_room_id, goal_room_id);
                    room_sequence = {};
                    total_cost = inf;
                    return;
                end

                % Remove from unvisited
                unvisited(min_idx) = [];
                visited(current_room_id) = true;

                % Goal reached - reconstruct path
                if strcmp(current_room_id, goal_room_id)
                    room_sequence = obj.reconstructPath(parents, start_room_id, goal_room_id);
                    total_cost = distances(goal_room_id);

                    % Convert to cell array of strings for strjoin
                    path_str = room_sequence{1};
                    for k = 2:length(room_sequence)
                        path_str = [path_str, ' → ', room_sequence{k}];
                    end
                    fprintf('[RoomGraph] Path found: %s (cost: %.2f)\n', path_str, total_cost);
                    return;
                end

                % Update neighbors
                current_room = obj.rooms(current_room_id);
                for i = 1:length(current_room.connections)
                    door = current_room.connections(i);
                    neighbor_id = door.target_room_id;

                    % Skip if already visited
                    if visited(neighbor_id)
                        continue;
                    end

                    % Calculate tentative distance
                    edge_cost = door.cost;
                    tentative_dist = distances(current_room_id) + edge_cost;

                    % Update if shorter path found
                    if tentative_dist < distances(neighbor_id)
                        distances(neighbor_id) = tentative_dist;
                        parents(neighbor_id) = current_room_id;
                    end
                end
            end

            % If we get here, no path was found
            fprintf('[RoomGraph] ERROR: No path found from %s to %s\n', ...
                start_room_id, goal_room_id);
            room_sequence = {};
            total_cost = inf;
        end

        function path = reconstructPath(obj, parents, start_id, goal_id)
            % Reconstruct path from parent pointers
            % Input: parents - Map of room_id -> parent_room_id
            %        start_id, goal_id - start and goal room IDs
            % Output: Cell array of room IDs in order from start to goal

            path = {goal_id};
            current = goal_id;

            while ~strcmp(current, start_id)
                if ~parents.isKey(current)
                    error('Path reconstruction failed: no parent for room %s', current);
                end
                current = parents(current);
                path = [{current}, path];
            end
        end

        function visualize(obj, fig_handle)
            % Visualize the room graph
            % Input: fig_handle - figure handle (optional)

            if nargin < 2 || isempty(fig_handle)
                fig_handle = figure('Name', 'Room Graph Visualization', ...
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

            % Plot connections between rooms
            for i = 1:length(room_keys)
                room = obj.rooms(room_keys{i});
                for j = 1:length(room.connections)
                    door = room.connections(j);
                    target_room = obj.rooms(door.target_room_id);

                    % Draw line from room center to door to target center
                    plot([room.center(1), door.door_center(1)], ...
                         [room.center(2), door.door_center(2)], ...
                         '--', 'Color', [0.5 0.5 0.5], 'LineWidth', 1.5);
                end
            end

            title('Room Graph - Topological Map', 'FontSize', 14, 'FontWeight', 'bold');
            xlabel('X (meters)');
            ylabel('Y (meters)');
            grid on;
            axis equal;

            % Auto-zoom to fit all rooms with margin
            if ~isempty(room_keys)
                all_x = [];
                all_y = [];
                for i = 1:length(room_keys)
                    room = obj.rooms(room_keys{i});
                    all_x = [all_x, room.boundaries(1,1), room.boundaries(1,2)];
                    all_y = [all_y, room.boundaries(2,1), room.boundaries(2,2)];
                end
                margin = 2; % 2 meter margin
                xlim([min(all_x)-margin, max(all_x)+margin]);
                ylim([min(all_y)-margin, max(all_y)+margin]);
            end

            hold off;
        end

        function printGraphInfo(obj)
            % Display graph information in console
            fprintf('\n=== Room Graph Summary ===\n');
            fprintf('Total rooms: %d\n\n', obj.rooms.Count);

            room_keys = keys(obj.rooms);
            for i = 1:length(room_keys)
                room = obj.rooms(room_keys{i});
                room.displayInfo();
                fprintf('\n');
            end
        end
    end
end
