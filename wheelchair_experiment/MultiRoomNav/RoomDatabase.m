classdef RoomDatabase < handle
    % RoomDatabase - Universal room database loader and manager
    %
    % Loads room configurations from JSON file and builds room graph
    % Provides methods to query, update, and save room data

    properties
        building         % Building name
        floor            % Floor number
        map_file         % Path to occupancy map
        description      % Description of the layout
        last_updated     % Last update date
        rooms_data       % Cell array of room structs
        graph            % RoomGraphWithDoorDistances object
    end

    methods (Static)
        function val = getVal(field)
            % Helper to extract value from cell or direct value
            if iscell(field)
                val = field{1};
            else
                val = field;
            end
        end
    end

    methods
        function obj = RoomDatabase(json_file)
            % Constructor - Load database from JSON file
            % Input: json_file - path to JSON database file

            if nargin > 0 && ~isempty(json_file)
                obj.loadFromJSON(json_file);
            end
        end

        function buildConnectionsFromDoors(obj, doors_data)
            % Build bidirectional connections from centralized door database
            % Input: doors_data - array of door structs from JSON

            fprintf('[RoomDatabase] Building connections from %d doors...\n', length(doors_data));

            for i = 1:length(doors_data)
                % Handle cell array from JSON
                if iscell(doors_data)
                    door = doors_data{i};
                else
                    door = doors_data(i);
                end

                % Get the two rooms this door connects
                % door.connects is an array like ["A", "B"] which becomes cell array {'A', 'B'}
                if iscell(door.connects)
                    room1_id = door.connects{1};
                    room2_id = door.connects{2};
                else
                    room1_id = door.connects(1);
                    room2_id = door.connects(2);
                end

                % Find room 1
                room1_idx = -1;
                for j = 1:length(obj.rooms_data)
                    if strcmp(obj.rooms_data(j).id, room1_id)
                        room1_idx = j;
                        break;
                    end
                end

                % Find room 2
                room2_idx = -1;
                for j = 1:length(obj.rooms_data)
                    if strcmp(obj.rooms_data(j).id, room2_id)
                        room2_idx = j;
                        break;
                    end
                end

                if room1_idx == -1 || room2_idx == -1
                    door_id_str = RoomDatabase.getVal(door.id);
                    fprintf('  Warning: Door %s references non-existent room\n', door_id_str);
                    continue;
                end

                % Extract door values (handle cell arrays)
                door_pos_val = RoomDatabase.getVal(door.position);
                door_width_val = RoomDatabase.getVal(door.width);
                door_type_val = RoomDatabase.getVal(door.door_type);
                door_bidirectional_val = RoomDatabase.getVal(door.bidirectional);

                % Extract astar_goal positions (field names use room IDs)
                % For room1 -> room2, use astar_goal_from_<room1_id>
                astar_field_name_room1 = sprintf('astar_goal_from_%s', room1_id);
                astar_field_name_room2 = sprintf('astar_goal_from_%s', room2_id);

                if isfield(door, astar_field_name_room1)
                    astar_goal_room1 = RoomDatabase.getVal(door.(astar_field_name_room1));
                else
                    astar_goal_room1 = door_pos_val;  % Fallback to door position
                end

                if isfield(door, astar_field_name_room2)
                    astar_goal_room2 = RoomDatabase.getVal(door.(astar_field_name_room2));
                else
                    astar_goal_room2 = door_pos_val;  % Fallback to door position
                end

                % Create connection struct for room1 -> room2
                conn1 = struct();
                conn1.target_room = room2_id;
                conn1.door_position = door_pos_val;
                conn1.astar_goal = astar_goal_room1;  % Stop position from room1 side
                conn1.door_width = door_width_val;
                conn1.door_type = door_type_val;
                conn1.bidirectional = door_bidirectional_val;

                % Initialize connections array if it doesn't exist
                if ~isfield(obj.rooms_data(room1_idx), 'connections')
                    obj.rooms_data(room1_idx).connections = {};
                end

                % Add connection
                obj.rooms_data(room1_idx).connections{end+1} = conn1;

                % If bidirectional, create reverse connection
                if door_bidirectional_val
                    conn2 = struct();
                    conn2.target_room = room1_id;
                    conn2.door_position = door_pos_val;  % SAME position!
                    conn2.astar_goal = astar_goal_room2;  % Stop position from room2 side
                    conn2.door_width = door_width_val;
                    conn2.door_type = door_type_val;
                    conn2.bidirectional = true;

                    if ~isfield(obj.rooms_data(room2_idx), 'connections')
                        obj.rooms_data(room2_idx).connections = {};
                    end

                    obj.rooms_data(room2_idx).connections{end+1} = conn2;
                end

                door_id_str = RoomDatabase.getVal(door.id);
                fprintf('  Added door %s: %s ↔ %s at [%.1f, %.1f]\n', ...
                    door_id_str, room1_id, room2_id, door_pos_val(1), door_pos_val(2));
            end

            fprintf('[RoomDatabase] Connections built successfully\n');
        end

        function success = loadFromJSON(obj, json_file)
            % Load room database from JSON file

            fprintf('[RoomDatabase] Loading from: %s\n', json_file);

            try
                % Read JSON file
                fid = fopen(json_file, 'r');
                if fid == -1
                    error('Cannot open file: %s', json_file);
                end
                raw_json = fread(fid, inf, 'char=>char')';
                fclose(fid);

                % Parse JSON
                data = jsondecode(raw_json);

                % Load metadata
                obj.building = data.building;
                obj.floor = data.floor;
                obj.map_file = data.map_file;
                obj.description = data.description;
                obj.last_updated = data.last_updated;

                % Load rooms and doors
                obj.rooms_data = data.rooms;

                % Build connections from centralized door database
                if isfield(data, 'doors')
                    obj.buildConnectionsFromDoors(data.doors);
                end

                fprintf('[RoomDatabase] Loaded successfully:\n');
                fprintf('  Building: %s, Floor: %d\n', obj.building, obj.floor);
                fprintf('  Map file: %s\n', obj.map_file);
                fprintf('  Rooms: %d\n', length(obj.rooms_data));
                if isfield(data, 'doors')
                    fprintf('  Doors: %d\n', length(data.doors));
                end
                fprintf('  Description: %s\n', obj.description);

                success = true;

            catch ME
                fprintf('[RoomDatabase] ERROR loading JSON: %s\n', ME.message);
                success = false;
            end
        end

        function graph = buildGraph(obj)
            % Build RoomGraphWithDoorDistances from database
            % Returns: RoomGraphWithDoorDistances object

            fprintf('\n[RoomDatabase] Building room graph...\n');

            graph = RoomGraphWithDoorDistances();

            % First pass: Create all room nodes
            for i = 1:length(obj.rooms_data)
                room_data = obj.rooms_data(i);

                % Extract boundaries
                bounds = [room_data.boundaries.x_min, room_data.boundaries.x_max; ...
                          room_data.boundaries.y_min, room_data.boundaries.y_max];

                % Calculate center
                center_x = (room_data.boundaries.x_min + room_data.boundaries.x_max) / 2;
                center_y = (room_data.boundaries.y_min + room_data.boundaries.y_max) / 2;
                center = [center_x, center_y];

                % Create room node
                room_node = RoomNode(room_data.id, center, bounds);

                % Add connections
                for j = 1:length(room_data.connections)
                    % Handle both cell array and struct array
                    if iscell(room_data.connections)
                        conn = room_data.connections{j};
                    else
                        conn = room_data.connections(j);
                    end

                    % Extract connection values (handle cell arrays)
                    door_pos_val = RoomDatabase.getVal(conn.door_position);
                    target_room_val = RoomDatabase.getVal(conn.target_room);
                    door_width_val = RoomDatabase.getVal(conn.door_width);

                    % Extract astar_goal if it exists
                    if isfield(conn, 'astar_goal')
                        astar_goal_val = RoomDatabase.getVal(conn.astar_goal);
                        astar_goal_pos = [astar_goal_val(1), astar_goal_val(2)];
                    else
                        astar_goal_pos = [door_pos_val(1), door_pos_val(2)];  % Fallback
                    end

                    % Convert door position to array
                    door_pos = [door_pos_val(1), door_pos_val(2)];

                    % Create door connection (cost = 0, calculated by graph)
                    door = DoorConnection(target_room_val, door_pos, door_width_val, 0, astar_goal_pos);
                    room_node.addConnection(door);
                end

                % Add to graph
                graph.addRoom(room_node);
            end

            fprintf('[RoomDatabase] Graph built with %d rooms\n', length(obj.rooms_data));

            obj.graph = graph;
        end

        function room_data = getRoomData(obj, room_id)
            % Get room data by ID
            room_data = [];

            for i = 1:length(obj.rooms_data)
                if strcmp(obj.rooms_data(i).id, room_id)
                    room_data = obj.rooms_data(i);
                    return;
                end
            end

            fprintf('[RoomDatabase] Warning: Room %s not found\n', room_id);
        end

        function printSummary(obj)
            % Print database summary

            fprintf('\n╔════════════════════════════════════════════════╗\n');
            fprintf('║       ROOM DATABASE SUMMARY                    ║\n');
            fprintf('╚════════════════════════════════════════════════╝\n\n');

            fprintf('Building:     %s\n', obj.building);
            fprintf('Floor:        %d\n', obj.floor);
            fprintf('Map file:     %s\n', obj.map_file);
            fprintf('Description:  %s\n', obj.description);
            fprintf('Last updated: %s\n', obj.last_updated);
            fprintf('Total rooms:  %d\n\n', length(obj.rooms_data));

            fprintf('─────────────────────────────────────────────────\n');
            fprintf('ROOM DETAILS:\n');
            fprintf('─────────────────────────────────────────────────\n\n');

            for i = 1:length(obj.rooms_data)
                room = obj.rooms_data(i);

                fprintf('Room %s: %s (%s)\n', room.id, room.name, room.type);
                fprintf('  Boundaries: X[%.1f-%.1f], Y[%.1f-%.1f]\n', ...
                    room.boundaries.x_min, room.boundaries.x_max, ...
                    room.boundaries.y_min, room.boundaries.y_max);

                % Check if connections field exists first
                if ~isfield(room, 'connections') || isempty(room.connections)
                    fprintf('  Connections: 0\n\n');
                    continue;
                end

                fprintf('  Connections: %d\n', length(room.connections));

                for j = 1:length(room.connections)
                    % Handle both cell array and struct array
                    if iscell(room.connections)
                        conn = room.connections{j};
                    else
                        conn = room.connections(j);
                    end

                    % Extract values using helper
                    door_pos = RoomDatabase.getVal(conn.door_position);
                    target_room_str = RoomDatabase.getVal(conn.target_room);
                    door_type_str = RoomDatabase.getVal(conn.door_type);
                    door_width_val = RoomDatabase.getVal(conn.door_width);

                    fprintf('    → %s: door at [%.1f, %.1f], width %.1fm (%s)\n', ...
                        target_room_str, door_pos(1), door_pos(2), door_width_val, door_type_str);
                end
                fprintf('\n');
            end

            fprintf('═════════════════════════════════════════════════\n\n');
        end

        function printConnectivityMatrix(obj)
            % Print connectivity matrix showing which rooms connect

            fprintf('\n╔════════════════════════════════════════════════╗\n');
            fprintf('║       ROOM CONNECTIVITY MATRIX                 ║\n');
            fprintf('╚════════════════════════════════════════════════╝\n\n');

            room_ids = {};
            for i = 1:length(obj.rooms_data)
                room_ids{i} = obj.rooms_data(i).id;
            end

            % Print header
            fprintf('     ');
            for i = 1:length(room_ids)
                fprintf('  %s ', room_ids{i});
            end
            fprintf('\n');

            fprintf('    ');
            for i = 1:length(room_ids)
                fprintf('────');
            end
            fprintf('\n');

            % Print matrix
            for i = 1:length(room_ids)
                fprintf(' %s │', room_ids{i});

                for j = 1:length(room_ids)
                    % Check if i connects to j
                    room = obj.rooms_data(i);
                    connected = false;

                    % Check if room has connections
                    if ~isfield(room, 'connections') || isempty(room.connections)
                        % No connections, skip to display
                    else
                        for k = 1:length(room.connections)
                            % Handle both cell array and struct array
                            if iscell(room.connections)
                                conn_k = room.connections{k};
                            else
                                conn_k = room.connections(k);
                            end
                            % Extract target room (handle cell array)
                            target_room_val = RoomDatabase.getVal(conn_k.target_room);
                            if strcmp(target_room_val, room_ids{j})
                                connected = true;
                                break;
                            end
                        end
                    end

                    if i == j
                        fprintf('  - ');
                    elseif connected
                        fprintf('  ✓ ');
                    else
                        fprintf('    ');
                    end
                end
                fprintf('\n');
            end

            fprintf('\n');
        end

        function success = saveToJSON(obj, json_file)
            % Save current database to JSON file

            fprintf('[RoomDatabase] Saving to: %s\n', json_file);

            try
                % Build data structure
                data = struct();
                data.building = obj.building;
                data.floor = obj.floor;
                data.map_file = obj.map_file;
                data.description = obj.description;
                data.last_updated = datestr(now, 'yyyy-mm-dd');
                data.rooms = obj.rooms_data;

                % Convert to JSON
                json_str = jsonencode(data, 'PrettyPrint', true);

                % Write to file
                fid = fopen(json_file, 'w');
                if fid == -1
                    error('Cannot write to file: %s', json_file);
                end
                fprintf(fid, '%s', json_str);
                fclose(fid);

                fprintf('[RoomDatabase] Saved successfully\n');
                success = true;

            catch ME
                fprintf('[RoomDatabase] ERROR saving JSON: %s\n', ME.message);
                success = false;
            end
        end
    end
end
