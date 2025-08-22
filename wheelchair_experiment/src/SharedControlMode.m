classdef SharedControlMode < handle
    % SharedControlMode - Handle class for sharing control_mode between Control and Estimate
    % This allows both modules to access the same control_mode value
    % Control can update it, Estimate can read it
    
    properties
        control_mode    % Current control mode (e.g., 'path_following', 'elevator_entry', etc.)
    end
    
    methods
        function obj = SharedControlMode(initial_mode)
            % Constructor - initialize with default or provided mode
            if nargin < 1
                obj.control_mode = 'path_following'; % Default mode
            else
                obj.control_mode = initial_mode;
            end
        end
        
        function setMode(obj, new_mode)
            % Update the control mode
            obj.control_mode = new_mode;
        end
        
        function mode = getMode(obj)
            % Get the current control mode
            mode = obj.control_mode;
        end
    end
end