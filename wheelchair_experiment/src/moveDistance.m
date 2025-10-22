function result = moveDistance(target_distance, move_speed, direction, distance_traveled, last_update_time)
    % moveDistance - Move wheelchair forward or backward using odometry-based tracking
    %
    % This function tracks distance traveled using velocity × time integration
    % and generates velocity commands until the target distance is reached.
    %
    % Inputs:
    %   target_distance - total distance to travel (meters)
    %   move_speed - linear velocity magnitude (m/s, positive value)
    %   direction - 'forward' or 'reverse'
    %   distance_traveled - accumulated distance so far (persistent between calls)
    %   last_update_time - tic() timestamp from previous iteration (for dt calculation)
    %
    % Outputs:
    %   result - struct with:
    %       .completed - boolean, true when target distance reached
    %       .V - [linear_velocity; 0] control commands
    %       .distance_traveled - updated accumulated distance
    %       .remaining_distance - distance left to travel
    %       .last_update_time - updated timestamp for next iteration
    %       .dt - time elapsed since last update (seconds)
    %
    % Example:
    %   % First call (initialize)
    %   result = moveDistance(2.5, 0.2, 'forward', 0, []);
    %   % Subsequent calls
    %   result = moveDistance(2.5, 0.2, 'forward', result.distance_traveled, result.last_update_time);

    % Validate direction
    if ~strcmp(direction, 'forward') && ~strcmp(direction, 'reverse')
        error('Direction must be ''forward'' or ''reverse''');
    end

    % Calculate time elapsed since last update
    if isempty(last_update_time)
        dt = 0; % First iteration, no time elapsed yet
        current_time = tic; % Initialize timer
    else
        dt = toc(last_update_time);
        current_time = tic; % Reset for next iteration
    end

    % Failsafe: Reject large dt values (prevent distance corruption)
    if dt > 0.5
        fprintf('  WARNING: Large dt detected (%.2fs) - setting to 0 to prevent distance corruption\n', dt);
        dt = 0;
    end

    % Update distance traveled based on commanded velocity
    % IMPORTANT: Always accumulate POSITIVE distance regardless of direction
    % The direction only affects the velocity command sign (forward/reverse),
    % but distance_traveled should always represent absolute distance moved
    distance_traveled = distance_traveled + (move_speed * dt);

    % Calculate remaining distance
    remaining_distance = target_distance - distance_traveled;

    % Initialize result structure
    result = struct();
    result.distance_traveled = distance_traveled;
    result.remaining_distance = remaining_distance;
    result.last_update_time = current_time;
    result.dt = dt;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]

    % Distance tolerance (10cm)
    DISTANCE_TOLERANCE = 0.1;

    fprintf('  Move: Distance traveled: %.2f m, Remaining: %.2f m (dt=%.3fs, direction=%s)\n', ...
            distance_traveled, remaining_distance, dt, direction);

    % Check if target reached
    if remaining_distance > DISTANCE_TOLERANCE
        % Still need to move
        result.completed = false;

        if strcmp(direction, 'forward')
            result.V(1) = move_speed;  % Forward movement
            fprintf('  Move: Moving FORWARD (%.1f m/s)\n', move_speed);
        else % reverse
            result.V(1) = -move_speed; % Reverse movement
            fprintf('  Move: Moving REVERSE (%.1f m/s)\n', -move_speed);
        end
    else
        % Target distance reached
        result.completed = true;
        result.V = [0; 0]; % Stop
        fprintf('  Move: COMPLETED! Total distance: %.2f m\n', distance_traveled);
    end
end
