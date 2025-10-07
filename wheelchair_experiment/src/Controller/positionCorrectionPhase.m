function result = positionCorrectionPhase(current_position, current_yaw, target_position, door_center, door_params)
    % Position Correction Phase (Phase 1) - Reusable function for door entry positioning
    %
    % Ensures wheelchair is at the specified target position and correct orientation
    % before attempting door entry. This corrects positioning errors accumulated
    % during path following.
    %
    % Inputs:
    %   current_position - [x, y] wheelchair position (meters, global coordinates)
    %   current_yaw - heading angle (radians)
    %   target_position - [x, y] desired target position (meters, from metadata)
    %   door_center - [x, y] door center position (meters, for heading calculation)
    %   door_params - struct with Phase 1 parameters:
    %       .POSITION_TOLERANCE - acceptable distance error (default: 0.15m)
    %       .POSITION_ANGLE_TOLERANCE - acceptable heading error (default: 0.087 rad / 5°)
    %       .CORRECTION_TURN_SPEED - angular velocity for corrections (default: 0.1 rad/s)
    %       .CORRECTION_MOVE_SPEED - linear velocity for corrections (default: 0.15 m/s)
    %
    % Outputs:
    %   result - struct with:
    %       .phase - always 1 (position correction)
    %       .status - 'Correcting position' or 'Position verified'
    %       .V - [linear_vel; angular_vel] control commands
    %       .position_error - distance error in meters
    %       .angle_error - heading error in radians
    %       .target_position - calculated target position [x, y]
    %       .completed - true when Phase 1 done

    % Default parameters if not provided
    if nargin < 4 || isempty(door_params)
        door_params = struct();
    end

    POSITION_TOLERANCE = getParam(door_params, 'POSITION_TOLERANCE', 0.15);
    POSITION_ANGLE_TOLERANCE = getParam(door_params, 'POSITION_ANGLE_TOLERANCE', 0.087);
    CORRECTION_TURN_SPEED = getParam(door_params, 'CORRECTION_TURN_SPEED', 0.1);
    CORRECTION_MOVE_SPEED = getParam(door_params, 'CORRECTION_MOVE_SPEED', 0.15);

    % Initialize result structure
    result = struct();
    result.phase = 1; % Phase 1: Position Correction
    result.completed = false;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]

    % Use provided target position (from metadata)
    % Calculate direction to door for heading calculation
    direction_to_door = door_center - current_position;
    distance_to_door = norm(direction_to_door);

    % Measure position error
    position_error_vector = target_position - current_position;
    position_error_distance = norm(position_error_vector);

    % Calculate required heading (towards door center, not target position)
    required_heading = atan2(direction_to_door(2), direction_to_door(1));
    heading_error = angdiff(required_heading, current_yaw);

    % Store for debugging and output
    result.position_error = position_error_distance;
    result.angle_error = heading_error;
    result.target_position = target_position;

    fprintf('Phase 1: Position Correction\n');
    fprintf('  Current pos: [%.2f, %.2f], Target pos: [%.2f, %.2f]\n', ...
            current_position(1), current_position(2), target_position(1), target_position(2));
    fprintf('  Position error: %.2fm, Heading error: %.2f° (%.3f rad)\n', ...
            position_error_distance, rad2deg(heading_error), heading_error);

    % Decision tree: Check position tolerance first
    if position_error_distance > POSITION_TOLERANCE
        result.status = 'Correcting position';

        % Calculate heading towards target position (not door center)
        target_direction = target_position - current_position;
        required_heading_to_target = atan2(target_direction(2), target_direction(1));
        heading_error_to_target = angdiff(required_heading_to_target, current_yaw);

        if abs(heading_error_to_target) > POSITION_ANGLE_TOLERANCE
            % Step 1: Turn to face target position
            result.V(2) = sign(heading_error_to_target) * CORRECTION_TURN_SPEED;
            result.V(1) = 0; % No forward movement while turning
            fprintf('  Action: Turning towards target position (%.1f deg remaining)\n', ...
                    rad2deg(abs(heading_error_to_target)));
        else
            % Step 2: Move straight forward to target position
            result.V(1) = CORRECTION_MOVE_SPEED;  % Always move forward
            result.V(2) = 0; % No turning while moving
            fprintf('  Action: Moving FORWARD to target (%.2fm to go)\n', position_error_distance);
        end

        result.completed = false;

    else
        % Position verified - proceed to Phase 2
        result.status = 'Position verified';
        result.V = [0; 0]; % Stop
        result.completed = true;

        fprintf('Phase 1: COMPLETED - Position verified!\n');
        fprintf('  Final position error: %.3fm, Heading error: %.2f°\n', ...
                position_error_distance, rad2deg(heading_error));
    end
end

function value = getParam(params, field, default_value)
    % Helper function to get parameter with default fallback
    if isfield(params, field)
        value = params.(field);
    else
        value = default_value;
    end
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate the shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end
