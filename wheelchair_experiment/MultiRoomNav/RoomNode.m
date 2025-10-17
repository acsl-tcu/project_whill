classdef RoomNode < handle
    % RoomNode - Represents a room in the topological navigation graph
    %
    % Properties:
    %   id          - Unique identifier (string or number)
    %   center      - [x, y] center position in world coordinates
    %   boundaries  - [x_min, x_max; y_min, y_max] bounding box
    %   area        - Room area in square meters
    %   connections - Array of DoorConnection objects
    %   metadata    - Optional struct for additional info (room type, etc.)

    properties
        id              % Unique room identifier
        center          % [x, y] room center
        boundaries      % [x_min, x_max; y_min, y_max]
        area            % Room area (m^2)
        connections     % Array of DoorConnection objects
        metadata        % Optional metadata struct
    end

    methods
        function obj = RoomNode(room_id, center_pos, bounds, metadata)
            % Constructor
            % Inputs:
            %   room_id    - Unique identifier (string or number)
            %   center_pos - [x, y] center position
            %   bounds     - [x_min, x_max; y_min, y_max] boundaries
            %   metadata   - Optional struct with extra info

            obj.id = room_id;
            obj.center = center_pos;
            obj.boundaries = bounds;

            % Calculate area
            obj.area = (bounds(1,2) - bounds(1,1)) * (bounds(2,2) - bounds(2,1));

            % Initialize empty connections array
            obj.connections = DoorConnection.empty(0);

            % Store metadata if provided
            if nargin >= 4
                obj.metadata = metadata;
            else
                obj.metadata = struct();
            end
        end

        function addConnection(obj, door_connection)
            % Add a door connection to another room
            % Input: door_connection - DoorConnection object

            if ~isa(door_connection, 'DoorConnection')
                error('Input must be a DoorConnection object');
            end

            % Add to connections array
            obj.connections(end+1) = door_connection;
        end

        function connected_rooms = getConnectedRooms(obj)
            % Get list of all connected room IDs
            % Output: cell array of room IDs

            connected_rooms = cell(1, length(obj.connections));
            for i = 1:length(obj.connections)
                connected_rooms{i} = obj.connections(i).target_room_id;
            end
        end

        function door = getDoorTo(obj, target_room_id)
            % Get door connection to a specific room
            % Input: target_room_id - ID of target room
            % Output: DoorConnection object, or [] if not found

            door = [];
            for i = 1:length(obj.connections)
                if strcmp(obj.connections(i).target_room_id, target_room_id)
                    door = obj.connections(i);
                    return;
                end
            end
        end

        function tf = isInside(obj, position)
            % Check if a position is inside this room
            % Input: position - [x, y] coordinates
            % Output: true if inside, false otherwise

            x = position(1);
            y = position(2);

            tf = (x >= obj.boundaries(1,1)) && (x <= obj.boundaries(1,2)) && ...
                 (y >= obj.boundaries(2,1)) && (y <= obj.boundaries(2,2));
        end

        function dist = distanceToCenter(obj, position)
            % Calculate Euclidean distance from position to room center
            % Input: position - [x, y] coordinates
            % Output: distance in meters

            dist = norm(position - obj.center);
        end

        function displayInfo(obj)
            % Display room information
            fprintf('Room %s:\n', obj.id);
            fprintf('  Center: [%.2f, %.2f]\n', obj.center(1), obj.center(2));
            fprintf('  Bounds: X[%.2f, %.2f], Y[%.2f, %.2f]\n', ...
                obj.boundaries(1,1), obj.boundaries(1,2), ...
                obj.boundaries(2,1), obj.boundaries(2,2));
            fprintf('  Area: %.2f m^2\n', obj.area);
            fprintf('  Connections: %d\n', length(obj.connections));

            for i = 1:length(obj.connections)
                obj.connections(i).displayInfo();
            end
        end

        function plotRoom(obj, fig_handle, color)
            % Plot room boundaries and center on given figure
            % Inputs:
            %   fig_handle - figure handle (optional)
            %   color - color for plotting (default: 'blue')

            if nargin < 3
                color = [0 0 1];  % Blue
            end
            % Don't switch figures - just plot on current axes
            % The caller (visualize) handles figure creation

            % Plot room boundary
            x_bounds = [obj.boundaries(1,1), obj.boundaries(1,2), ...
                        obj.boundaries(1,2), obj.boundaries(1,1), obj.boundaries(1,1)];
            y_bounds = [obj.boundaries(2,1), obj.boundaries(2,1), ...
                        obj.boundaries(2,2), obj.boundaries(2,2), obj.boundaries(2,1)];
            plot(x_bounds, y_bounds, '-', 'Color', color, 'LineWidth', 3);

            % Plot room center
            plot(obj.center(1), obj.center(2), 'o', 'Color', color, ...
                'MarkerSize', 12, 'MarkerFaceColor', color, 'LineWidth', 2);

            % Label room
            text(obj.center(1), obj.center(2) + 1, sprintf('Room %s', obj.id), ...
                'HorizontalAlignment', 'center', 'FontSize', 14, 'FontWeight', 'bold', ...
                'Color', color);

            % Plot doors
            for i = 1:length(obj.connections)
                door = obj.connections(i);
                plot(door.door_center(1), door.door_center(2), 's', ...
                    'Color', [1 0.5 0], 'MarkerSize', 12, 'MarkerFaceColor', [1 0.5 0], ...
                    'LineWidth', 2);
                text(door.door_center(1) + 0.5, door.door_center(2), ...
                    sprintf('→%s', door.target_room_id), 'FontSize', 11, 'FontWeight', 'bold');
            end
        end
    end
end
