function result = turnTowardsTarget(current_yaw, target_position, current_position, turn_speed, turn_tolerance)
    % turnTowardsTarget - Turn the wheelchair towards a target position
    %
    % This function calculates the required heading to face a target and
    % generates angular velocity commands to achieve that heading.
    %
    % Inputs:
    %   current_yaw - current heading angle in radians
    %   target_position - [x, y] target position to face towards
    %   current_position - [x, y] current wheelchair position
    %   turn_speed - angular velocity for turning (rad/s)
    %   turn_tolerance - acceptable heading error (radians)
    %
    % Outputs:
    %   result - struct with:
    %       .completed - boolean, true when heading error within tolerance
    %       .V - [0; angular_velocity] control commands
    %       .heading_error - current heading error in radians
    %       .required_heading - target heading in radians
    %       .turn_direction - 'left', 'right', or 'aligned'
    %
    % Example:
    %   result = turnTowardsTarget(pi/4, [27, 12], [25, 10], 0.1, 0.1);

    % Calculate required heading to face target
    direction_vector = target_position - current_position;
    required_heading = atan2(direction_vector(2), direction_vector(1));

    % Calculate heading error (shortest angular path)
    heading_error = angdiff(required_heading, current_yaw);

    % Initialize result structure
    result = struct();
    result.required_heading = required_heading;
    result.heading_error = heading_error;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]

    % Check if already aligned
    if abs(heading_error) <= turn_tolerance
        result.completed = true;
        result.turn_direction = 'aligned';
        fprintf('  Turn: ALIGNED (error: %.1f deg)\n', rad2deg(abs(heading_error)));
    else
        result.completed = false;

        % Determine turn direction and command
        if heading_error > 0
            result.V(2) = turn_speed;  % Turn left (counterclockwise)
            result.turn_direction = 'left';
            fprintf('  Turn: LEFT (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        else
            result.V(2) = -turn_speed; % Turn right (clockwise)
            result.turn_direction = 'right';
            fprintf('  Turn: RIGHT (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        end
    end
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end
