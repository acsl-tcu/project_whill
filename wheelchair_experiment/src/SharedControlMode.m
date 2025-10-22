classdef SharedControlMode < handle
    % SharedControlMode - Handle class for sharing waypoint data between Control and Estimate
    % This class is a DATA CONTAINER ONLY - it does NOT track phase/mode state
    % Phase/mode state is managed by PhaseManager (single source of truth)

    properties
        waypoint        % Shared waypoints: cell array {segment1, segment2, ...}
        waypoint_updated % Flag to indicate waypoints have been updated
        current_target_n % Current target waypoint number (from Control.m obj.target_n)
        total_waypoints  % Total number of waypoints in current segment
        current_segment  % Current segment index (for multi-room navigation)
        total_segments   % Total number of segments
    end
    
    methods
        function obj = SharedControlMode(~)
            % Constructor - initialize waypoint data
            % NOTE: This class no longer tracks phase/mode - use PhaseManager instead
            obj.waypoint = {}; % Initialize empty cell array
            obj.waypoint_updated = false; % No updates initially
            obj.current_target_n = 1; % Start at first waypoint
            obj.total_waypoints = 0; % No waypoints initially
            obj.current_segment = 1; % Start at first segment
            obj.total_segments = 0; % No segments initially
        end
        
        function setWaypoints(obj, waypoint_cell_array)
            % Update the shared waypoints (cell array) and mark as updated
            % Input: waypoint_cell_array - {segment1, segment2, ...}

            % DEBUG: Check what's being stored
            fprintf('\n[SHARED DEBUG] setWaypoints() called:\n');
            fprintf('  Input type: %s\n', class(waypoint_cell_array));
            fprintf('  Is cell: %d\n', iscell(waypoint_cell_array));
            fprintf('  Length: %d\n', length(waypoint_cell_array));
            if iscell(waypoint_cell_array) && ~isempty(waypoint_cell_array)
                for i = 1:length(waypoint_cell_array)
                    fprintf('  Segment %d size: %dx%d\n', i, size(waypoint_cell_array{i}, 1), size(waypoint_cell_array{i}, 2));
                end
            end

            obj.waypoint = waypoint_cell_array;

            % DEBUG: Verify what was stored
            fprintf('  Stored obj.waypoint type: %s\n', class(obj.waypoint));
            fprintf('  Stored obj.waypoint length: %d\n', length(obj.waypoint));
            if iscell(obj.waypoint) && ~isempty(obj.waypoint)
                fprintf('  Stored segment 1 size: %dx%d\n', size(obj.waypoint{1}, 1), size(obj.waypoint{1}, 2));
            end
            fprintf('\n');

            obj.total_segments = length(waypoint_cell_array);
            obj.current_segment = 1; % Reset to first segment

            % Update total waypoints for first segment
            if ~isempty(waypoint_cell_array) && ~isempty(waypoint_cell_array{1})
                obj.total_waypoints = size(waypoint_cell_array{1}, 1);
            else
                obj.total_waypoints = 0;
            end

            obj.waypoint_updated = true; % Flag that waypoints have been updated
        end

        function waypoint = getWaypoints(obj)
            % Get the full waypoint cell array

            % DEBUG: Check what's being retrieved
            fprintf('\n[SHARED DEBUG] getWaypoints() called:\n');
            fprintf('  obj.waypoint type: %s\n', class(obj.waypoint));
            fprintf('  obj.waypoint length: %d\n', length(obj.waypoint));
            if iscell(obj.waypoint) && ~isempty(obj.waypoint)
                fprintf('  obj.waypoint{1} size: %dx%d\n', size(obj.waypoint{1}, 1), size(obj.waypoint{1}, 2));
            end

            waypoint = obj.waypoint;

            % DEBUG: Check what's being returned
            fprintf('  Returning type: %s\n', class(waypoint));
            fprintf('  Returning length: %d\n', length(waypoint));
            if iscell(waypoint) && ~isempty(waypoint)
                fprintf('  Returning segment 1 size: %dx%d\n', size(waypoint{1}, 1), size(waypoint{1}, 2));
            end
            fprintf('\n');
        end

        function segment = getCurrentSegmentWaypoints(obj)
            % Get waypoints for current segment
            if obj.current_segment > 0 && obj.current_segment <= length(obj.waypoint)
                segment = obj.waypoint{obj.current_segment};
            else
                segment = [];
            end
        end

        function has_waypoints = hasWaypoints(obj)
            % Check if waypoints are available
            has_waypoints = ~isempty(obj.waypoint) && length(obj.waypoint) > 0;
        end

        function is_multi = isMultiRoom(obj)
            % Check if multi-room navigation (more than 1 segment)
            is_multi = length(obj.waypoint) > 1;
        end

        function is_updated = areWaypointsUpdated(obj)
            % Check if waypoints have been updated since last check
            is_updated = obj.waypoint_updated;
        end
        
        function clearWaypointUpdateFlag(obj)
            % Clear the waypoint update flag (called after Control.m processes the update)
            obj.waypoint_updated = false;
        end

        function setCurrentTargetWaypoint(obj, target_n)
            % Update the current target waypoint number (called by Control.m)
            % Input: target_n - current target waypoint index from obj.target_n(1,1)
            obj.current_target_n = target_n;
        end

        function target_n = getCurrentTargetWaypoint(obj)
            % Get the current target waypoint number
            target_n = obj.current_target_n;
        end

        function is_final = isAtFinalWaypoint(obj)
            % Check if currently at the final waypoint
            % Returns true if current_target_n equals total number of waypoints
            % NOTE: This relies on Control.m updating current_target_n via setCurrentTargetWaypoint()
            %       Control.m is the single source of truth for target_n
            if obj.total_waypoints == 0
                is_final = false;
            else
                is_final = (obj.current_target_n >= obj.total_waypoints);
            end
        end
    end
end