function result = enterElevator(current_position, current_yaw, elevator_center, start_position)
    % Enter elevator function with two phases:
    % Phase 1: Turn towards elevator center
    % Phase 2: Move into elevator using odometry only until target distance reached
    %
    % Inputs:
    %   current_position - [x, y] current wheelchair position
    %   current_yaw - current heading angle in radians
    %   elevator_center - [x, y] position of elevator center (default: [27, 12])
    %   start_position - [x, y] position where Phase 2 started (for distance tracking)
    %
    % Outputs:
    %   result - struct with control commands and status
    
    persistent phase2_start_pos; % Remember where Phase 2 started
    
    if nargin < 3
        elevator_center = [27, 12.2]; % Default elevator center position
    end
    
    if nargin >= 4 && ~isempty(start_position)
        phase2_start_pos = start_position; % Initialize Phase 2 start position
    end
    
    % Parameters
    TURN_TOLERANCE = 0.1; % radians (~6 degrees)
    MOVE_DISTANCE = 2.0;  % meters to move into elevator
    TURN_SPEED = 0.3;     % rad/s for turning
    MOVE_SPEED = 0.2;     % m/s for forward movement
    
    fprintf('=== ENTERING ELEVATOR SEQUENCE ===\n');
    fprintf('Current position: [%.2f, %.2f], Yaw: %.2f rad\n', ...
            current_position(1), current_position(2), current_yaw);
    fprintf('Elevator center: [%.2f, %.2f]\n', elevator_center(1), elevator_center(2));
    
    % Calculate required heading to face elevator center
    direction_vector = elevator_center - current_position;
    required_heading = atan2(direction_vector(2), direction_vector(1));
    
    % Calculate heading error
    heading_error = angdiff(required_heading, current_yaw);
    
    fprintf('Required heading: %.2f rad (%.1f deg)\n', required_heading, rad2deg(required_heading));
    fprintf('Current heading: %.2f rad (%.1f deg)\n', current_yaw, rad2deg(current_yaw));
    fprintf('Heading error: %.2f rad (%.1f deg)\n', heading_error, rad2deg(heading_error));
    
    % Initialize result structure
    result = struct();
    result.phase = 1; % Start with Phase 1 (turning)
    result.completed = false;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]
    
    % Phase 1: Turn towards elevator
    if abs(heading_error) > TURN_TOLERANCE
        result.phase = 1;
        result.status = 'Turning towards elevator';
        
        % Determine turn direction (positive = counterclockwise, negative = clockwise)
        if heading_error > 0
            result.V(2) = TURN_SPEED;  % Turn left (counterclockwise)
            fprintf('Phase 1: Turning LEFT (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        else
            result.V(2) = -TURN_SPEED; % Turn right (clockwise)
            fprintf('Phase 1: Turning RIGHT (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        end
        
        result.V(1) = 0; % No forward movement during turning
        
    else
        % Phase 2: Move forward into elevator with distance tracking
        result.phase = 2;
        
        % Initialize Phase 2 start position if not set
        if isempty(phase2_start_pos)
            phase2_start_pos = current_position;
            fprintf('Phase 2: Starting forward movement from [%.2f, %.2f]\n', ...
                    phase2_start_pos(1), phase2_start_pos(2));
        end
        
        % Calculate distance moved since Phase 2 started
        distance_moved = norm(current_position - phase2_start_pos);
        remaining_distance = MOVE_DISTANCE - distance_moved;
        
        fprintf('Phase 2: Distance moved: %.2f m, Remaining: %.2f m\n', ...
                distance_moved, remaining_distance);
        
        if remaining_distance > 0.1 % Still need to move (with 10cm tolerance)
            result.status = 'Moving into elevator';
            result.V(1) = MOVE_SPEED;  % Forward movement
            result.V(2) = 0;           % No turning
            
            fprintf('Phase 2: Moving FORWARD into elevator (%.1f m/s)\n', MOVE_SPEED);
        else
            % Phase 2 completed - wheelchair is inside elevator
            result.status = 'Inside elevator - STOPPED';
            result.V(1) = 0;  % Stop moving
            result.V(2) = 0;  % No turning
            result.completed = true;
            
            fprintf('Phase 2: COMPLETED! Wheelchair is inside elevator.\n');
            fprintf('Total distance moved: %.2f m\n', distance_moved);
            
            % Reset persistent variable for next use
            phase2_start_pos = [];
        end
    end
    
    fprintf('Command: V=[%.2f, %.2f] (linear, angular)\n', result.V(1), result.V(2));
    fprintf('=====================================\n');
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate the shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end