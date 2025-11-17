function result = idleMotionForDoorSensor(params)
    % idleMotionForDoorSensor - Generate small forward/backward motion to trigger door sensors
    %
    % This function generates a forward-forward-backward-backward pattern to create
    % longer motion cycles to help trigger automatic door sensors while waiting for a door to open.
    %
    % Inputs:
    %   params - (Optional) Struct with motion parameters:
    %       .IDLE_SPEED - Linear velocity during motion (default: 0.05 m/s)
    %       .should_pause - Boolean: true = pause 1 sec, false = no pause (default: true)
    %
    % Outputs:
    %   result - Struct with:
    %       .V - [linear_vel; angular_vel] control command
    %       .status - String description of current motion state
    %       .direction - String: 'forward' or 'backward'
    %
    % Example:
    %   result = idleMotionForDoorSensor();
    %   % Call 1-5: Returns V = [0.05; 0] (forward)
    %   % Call 6-10: Returns V = [-0.05; 0] (backward)
    %   % ...repeats pattern
    %
    % Motion Pattern:
    %   Each cycle: forward (x5) → backward (x5) → (repeat)
    %   This creates 25cm motion in each direction (5 steps × 5cm/step)

    persistent motion_step;  % Track step in cycle: 1-5=forward, 6-10=backward

    % Initialize persistent variable
    if isempty(motion_step)
        motion_step = 1;  % Start at step 1 (forward)
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

    if ~isfield(params, 'should_pause')
        params.should_pause = true;  % Default: pause enabled
    end

    % Determine direction based on current step in 10-step cycle
    % Steps 1-5: forward, Steps 6-10: backward
    if motion_step <= 5
        motion_direction = 1;   % Forward
        result.status = sprintf('Moving forward to trigger door sensor (step %d/5)', motion_step);
        result.direction = 'forward';
    else
        motion_direction = -1;  % Backward
        result.status = sprintf('Moving backward to trigger door sensor (step %d/5)', motion_step - 5);
        result.direction = 'backward';
    end

    % Generate motion command
    result.V = [motion_direction * params.IDLE_SPEED; 0];

    % Only pause if should_pause is true (skip on first entry to Phase 2.5)
    if params.should_pause
        pause(1)
    end

    % Advance to next step in cycle (1 → 2 → ... → 10 → 1 → ...)
    motion_step = motion_step + 1;
    if motion_step > 10
        motion_step = 1;  % Reset cycle
    end
end
