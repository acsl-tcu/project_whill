function result = idleMotionForDoorSensor(params)
    % idleMotionForDoorSensor - Generate small forward/backward motion to trigger door sensors
    %
    % This function alternates between forward and backward movement each time it's called
    % to help trigger automatic door sensors while waiting for a door to open.
    %
    % Inputs:
    %   params - (Optional) Struct with motion parameters:
    %       .IDLE_SPEED - Linear velocity during motion (default: 0.05 m/s)
    %
    % Outputs:
    %   result - Struct with:
    %       .V - [linear_vel; angular_vel] control command
    %       .status - String description of current motion state
    %       .direction - String: 'forward' or 'backward'
    %
    % Example:
    %   result = idleMotionForDoorSensor();
    %   % Call 1: Returns V = [0.05; 0] (forward)
    %   % Call 2: Returns V = [-0.05; 0] (backward)
    %   % Call 3: Returns V = [0.05; 0] (forward)
    %   % ...alternates each call
    %
    % Motion Pattern:
    %   Each control loop alternates: forward → backward → forward → backward...

    persistent motion_direction;  % Track current direction: 1 = forward, -1 = backward

    % Initialize persistent variable
    if isempty(motion_direction)
        motion_direction = 1;  % Start with forward motion
    end

    % Initialize result structure
    result = struct();

    % Set default parameters if not provided
    if nargin < 1 || isempty(params)
        params = struct();
    end

    if ~isfield(params, 'IDLE_SPEED')
        params.IDLE_SPEED = 0.05;  % 5 cm/s - gentle motion
    end

    % Generate motion command based on current direction
    result.V = [motion_direction * params.IDLE_SPEED; 0];
    pause(1)
    % Set status message
    if motion_direction == 1
        result.status = 'Moving forward to trigger door sensor';
        result.direction = 'forward';
    else
        result.status = 'Moving backward to trigger door sensor';
        result.direction = 'backward';
    end

    % Alternate direction for next call
    motion_direction = -motion_direction;
end
