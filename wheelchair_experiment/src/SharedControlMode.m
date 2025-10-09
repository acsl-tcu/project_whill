classdef SharedControlMode < handle
    % SharedControlMode - Handle class for sharing control_mode between Control and Estimate
    % This allows both modules to access the same control_mode value
    % Control can update it, Estimate can read it
    
    properties
        control_mode    % Current control mode (e.g., 'path_following', 'elevator_entry', etc.)
        waypoint        % Shared waypoints between Estimate and Control
        is_first_use    % Track if this is the very first time any mode is selected
        waypoint_updated % Flag to indicate waypoints have been updated
        current_target_n % Current target waypoint number (from Control.m obj.target_n)
        total_waypoints  % Total number of waypoints
    end
    
    methods
        function obj = SharedControlMode(initial_mode)
            % Constructor - initialize with default or provided mode
            if nargin < 1
                obj.control_mode = 'path_following'; % Default mode
            else
                obj.control_mode = initial_mode;
            end
            obj.waypoint = []; % Initialize empty waypoints
            obj.is_first_use = true; % This is the first time using the system
            obj.waypoint_updated = false; % No updates initially
            obj.current_target_n = 1; % Start at first waypoint
            obj.total_waypoints = 0; % No waypoints initially
        end
        
        function setMode(obj, new_mode)
            % Update the control mode
            obj.control_mode = new_mode;
            
            % Mark that the system has been used (no longer first time)
            obj.is_first_use = false;
        end
        
        function mode = getMode(obj)
            % Get the current control mode
            mode = obj.control_mode;
        end
        
        function setWaypoints(obj, waypoint)
            % Update the shared waypoints and mark as updated
            obj.waypoint = waypoint;
            obj.total_waypoints = size(waypoint, 1); % Update total count when waypoints change
            obj.waypoint_updated = true; % Flag that waypoints have been updated
        end
        
        function waypoint = getWaypoints(obj)
            % Get the current waypoints
            waypoint = obj.waypoint;
        end
        
        function has_waypoints = hasWaypoints(obj)
            % Check if waypoints are available
            has_waypoints = ~isempty(obj.waypoint);
        end
        
        function is_first = isFirstTimeUse(obj)
            % Check if this is the very first time using the system
            is_first = obj.is_first_use;
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