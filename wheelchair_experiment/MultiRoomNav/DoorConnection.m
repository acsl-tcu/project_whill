classdef DoorConnection < handle
    % DoorConnection - Represents a connection (door/passage) between two rooms
    %
    % Properties:
    %   target_room_id - ID of the room this door connects to
    %   door_center    - [x, y] position of door center in world coordinates
    %   door_width     - Width of the passage in meters
    %   cost           - Traversal cost (default: distance-based)
    %   astar_goal     - [x, y] position where A* should stop (1m before door)

    properties
        target_room_id  % String or numeric ID of connected room
        door_center     % [x, y] world coordinates
        door_width      % Width in meters
        cost            % Traversal cost
        astar_goal      % [x, y] A* goal position (stop before door)
    end

    methods
        function obj = DoorConnection(target_id, door_pos, width, cost, astar_goal_pos)
            % Constructor
            % Inputs:
            %   target_id - ID of room this door connects to
            %   door_pos  - [x, y] position of door center
            %   width     - Door/passage width in meters (default: 1.0)
            %   cost      - Traversal cost (default: 1.0)
            %   astar_goal_pos - [x, y] A* goal position (default: door_pos)

            if nargin < 5
                astar_goal_pos = door_pos;  % Default to door position
            end
            if nargin < 4
                cost = 1.0;  % Default cost
            end
            if nargin < 3
                width = 1.0;  % Default 1 meter wide door
            end

            obj.target_room_id = target_id;
            obj.door_center = door_pos;
            obj.door_width = width;
            obj.cost = cost;
            obj.astar_goal = astar_goal_pos;
        end

        function displayInfo(obj)
            % Display door connection information
            fprintf('  Door to Room %s at [%.2f, %.2f] (width: %.2fm, cost: %.2f)\n', ...
                obj.target_room_id, obj.door_center(1), obj.door_center(2), ...
                obj.door_width, obj.cost);
        end
    end
end
