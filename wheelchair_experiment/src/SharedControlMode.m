classdef SharedControlMode < handle
    % SharedControlMode - Handle class for sharing control_mode between Control and Estimate
    % This allows both modules to access the same control_mode value
    % Control can update it, Estimate can read it
    
    properties
        control_mode    % Current control mode (e.g., 'path_following', 'elevator_entry', etc.)
        waypoint        % Shared waypoints between Estimate and Control
        is_first_use    % Track if this is the very first time any mode is selected
        waypoint_updated % Flag to indicate waypoints have been updated
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
    end
end