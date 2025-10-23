function result = idleMotionForDoorSensor(elapsed_time, params)
    % idleMotionForDoorSensor - Generate small forward/backward motion to trigger door sensors
    %
    % This function creates a small oscillating motion pattern that helps trigger
    % automatic door sensors while waiting for a door to open. The motion alternates
    % between forward and backward movement with short pauses.
    %
    % Inputs:
    %   elapsed_time - Time elapsed since starting to wait at the door (seconds)
    %   params - (Optional) Struct with motion parameters:
    %       .IDLE_SPEED - Linear velocity during motion (default: 0.05 m/s)
    %       .MOTION_DURATION - Duration of each forward/backward motion (default: 1.0 s)
    %       .PAUSE_DURATION - Duration to pause between motions (default: 0.5 s)
    %
    % Outputs:
    %   result - Struct with:
    %       .V - [linear_vel; angular_vel] control command
    %       .status - String description of current motion state
    %       .phase - String: 'forward', 'backward', or 'pause'
    %
    % Example:
    %   result = idleMotionForDoorSensor(3.5);  % After waiting 3.5 seconds
    %   % Returns V = [0.05; 0] with status 'Moving forward to trigger sensor'
    %
    % Motion Pattern:
    %   0.0s - 1.0s:  Move forward  (0.05 m = 5cm)
    %   1.0s - 1.5s:  Pause
    %   1.5s - 2.5s:  Move backward (0.05 m = 5cm)
    %   2.5s - 3.0s:  Pause
    %   [Repeat cycle: total 3.0s period]

    % Initialize result structure
    result = struct();
    result.V = [0; 0];
    result.status = 'Idle motion - waiting';
    result.phase = 'pause';

    % Set default parameters if not provided
    if nargin < 2 || isempty(params)
        params = struct();
    end

    if ~isfield(params, 'IDLE_SPEED')
        params.IDLE_SPEED = 0.05;  % 5 cm/s - gentle motion
    end

    if ~isfield(params, 'MOTION_DURATION')
        params.MOTION_DURATION = 1.0;  % 1 second of motion
    end

    if ~isfield(params, 'PAUSE_DURATION')
        params.PAUSE_DURATION = 0.5;  % 0.5 second pause
    end

    % Calculate cycle timing
    CYCLE_PERIOD = 2 * params.MOTION_DURATION + 2 * params.PAUSE_DURATION;  % Total cycle time

    % Find position within current cycle
    cycle_time = mod(elapsed_time, CYCLE_PERIOD);

    % Determine motion phase based on cycle time
    % Phase 1: Forward motion
    if cycle_time < params.MOTION_DURATION
        result.V = [params.IDLE_SPEED; 0];
        result.status = 'Moving forward to trigger door sensor';
        result.phase = 'forward';

    % Phase 2: Pause after forward
    elseif cycle_time < params.MOTION_DURATION + params.PAUSE_DURATION
        result.V = [0; 0];
        result.status = 'Pausing (forward complete)';
        result.phase = 'pause';

    % Phase 3: Backward motion
    elseif cycle_time < 2*params.MOTION_DURATION + params.PAUSE_DURATION
        result.V = [-params.IDLE_SPEED; 0];
        result.status = 'Moving backward to trigger door sensor';
        result.phase = 'backward';

    % Phase 4: Pause after backward
    else
        result.V = [0; 0];
        result.status = 'Pausing (backward complete)';
        result.phase = 'pause';
    end
end
