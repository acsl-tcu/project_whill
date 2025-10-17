function result = enterDoor(current_position, current_yaw, door_center, exit_position, lidar_scan_data, door_params, door_type)
    % enterDoor - General door entry function for both regular doors and elevators
    %
    % This function handles the complete door entry sequence:
    %   Phase 1: Position correction (reach target distance/orientation before door)
    %   Phase 2: Turn towards door center
    %   Phase 2.5: Verify door is passable using LiDAR
    %   Phase 3: Move through door to exit position
    %   Phase 4: Completed
    %
    % Inputs:
    %   current_position - [x, y] current wheelchair position
    %   current_yaw - current heading angle in radians
    %   door_center - [x, y] position of door center
    %   exit_position - [x, y] target position after passing through door
    %   lidar_scan_data - struct with xyz_global and xyz_local point cloud data
    %   door_params - struct with door detection/control parameters
    %   door_type - string: 'regular' or 'elevator' (determines behavior)
    %
    % Outputs:
    %   result - struct with control commands and status:
    %       .phase - current phase number (1-4)
    %       .status - string description of current state
    %       .V - [linear_vel; angular_vel] control commands
    %       .completed - boolean, true when door entry is complete
    %       .door_state - 'open', 'closed', or 'unknown' (Phase 2.5)
    %
    % Example:
    %   result = enterDoor([31.1, 5.9], pi/2, [31.1, 6.9], [31.1, 7.9], ...
    %                      lidar_data, door_params, 'regular');

    persistent phase1_completed;  % Track if position correction is done
    persistent door_verified;     % Track if door has been verified open
    persistent distance_traveled; % Track odometry-based distance in Phase 3
    persistent last_update_time;  % For delta time calculation

    % Initialize persistent variables
    if isempty(phase1_completed)
        phase1_completed = false;
    end
    if isempty(door_verified)
        door_verified = false;
    end
    if isempty(distance_traveled)
        distance_traveled = 0;
    end

    % Set default door_type
    if nargin < 7 || isempty(door_type)
        door_type = 'regular';
    end

    % Validate door_params (use defaults if not provided)
    if nargin < 6 || isempty(door_params)
        door_params = getDefaultDoorParams();
    end

    % Extract parameters
    TURN_TOLERANCE = door_params.TURN_TOLERANCE;
    TURN_SPEED = door_params.TURN_SPEED;
    MOVE_SPEED = door_params.MOVE_SPEED;

    fprintf('\n=== ENTERING DOOR SEQUENCE (Type: %s) ===\n', door_type);
    fprintf('Current position: [%.2f, %.2f], Yaw: %.2f rad\n', ...
            current_position(1), current_position(2), current_yaw);
    fprintf('Door center: [%.2f, %.2f]\n', door_center(1), door_center(2));
    fprintf('Exit position: [%.2f, %.2f]\n', exit_position(1), exit_position(2));

    % Calculate required heading to face door center
    direction_vector = door_center - current_position;
    required_heading = atan2(direction_vector(2), direction_vector(1));
    heading_error = angdiff(required_heading, current_yaw);

    fprintf('Required heading: %.2f rad (%.1f deg)\n', required_heading, rad2deg(required_heading));
    fprintf('Heading error: %.2f rad (%.1f deg)\n', heading_error, rad2deg(heading_error));

    % Initialize result structure
    result = struct();
    result.phase = 1;
    result.completed = false;
    result.V = [0; 0]; % [linear_velocity; angular_velocity]
    result.door_type = door_type;

    % Phase 1: Position Correction
    if ~phase1_completed
        fprintf('Phase 1: Position correction\n');

        % Calculate target position (should be ~1m before door)
        % This is passed from HybridPathPlanner as the astar_goal
        target_position = current_position; % Already at astar_goal from A* planning

        phase1_result = positionCorrectionPhase(current_position, current_yaw, ...
                                                target_position, door_center, door_params);

        result.phase = phase1_result.phase;
        result.status = phase1_result.status;
        result.V = phase1_result.V;
        result.position_error = phase1_result.position_error;
        result.angle_error = phase1_result.angle_error;

        if phase1_result.completed
            phase1_completed = true;
            fprintf('Phase 1 completed - proceeding to Phase 2 (turning)\n');
        end

    % Phase 2: Turn towards door
    elseif abs(heading_error) > TURN_TOLERANCE
        result.phase = 2;
        result.status = 'Turning towards door';

        if heading_error > 0
            result.V(2) = TURN_SPEED;  % Turn left (counterclockwise)
            fprintf('Phase 2: Turning LEFT (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        else
            result.V(2) = -TURN_SPEED; % Turn right (clockwise)
            fprintf('Phase 2: Turning RIGHT (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        end
        result.V(1) = 0; % No forward movement

    % Phase 2.5: Check door state
    elseif ~door_verified
        result.phase = 2.5;
        result.status = 'Verifying door is passable';
        result.V = [0; 0]; % Stop while checking

        fprintf('Phase 2.5: Checking door state using LiDAR...\n');

        % Extract point cloud data
        if ~isempty(lidar_scan_data)
            if isstruct(lidar_scan_data) && isfield(lidar_scan_data, 'xyz_global')
                pointCloud = lidar_scan_data.xyz_global;
            else
                pointCloud = lidar_scan_data;
            end

            % Check door state
            wheelchair_pose = [current_position, current_yaw];
            odometry_mode = false; % Use global coordinates

            if strcmp(door_type, 'elevator')
                % Use elevator-specific door detection
                door_state = detectElevatorDoorState(pointCloud{1}, wheelchair_pose, ...
                                                      door_center, odometry_mode, door_params);
            else
                % Use general door detection (regular doors)
                door_state = detectDoorState(pointCloud{1}, wheelchair_pose, ...
                                             door_center, odometry_mode, door_params);
            end

            result.door_state = door_state;

            if strcmp(door_state, 'open')
                fprintf('Phase 2.5: Door verified as OPEN/PASSABLE - proceeding to Phase 3\n');
                door_verified = true;
            elseif strcmp(door_state, 'closed')
                fprintf('Phase 2.5: Door is CLOSED - waiting...\n');
                % Stay in Phase 2.5
            else
                fprintf('Phase 2.5: Door state UNKNOWN - proceeding with caution\n');
                door_verified = true; % Proceed anyway
            end
        else
            fprintf('Warning: No LiDAR data - assuming door is passable\n');
            door_verified = true;
            result.door_state = 'unknown';
        end

    % Phase 3: Move through door to exit position
    else
        result.phase = 3;

        % Calculate distance to exit position
        distance_to_exit = norm(exit_position - current_position);

        % Calculate time elapsed since last update (for odometry)
        if isempty(last_update_time)
            dt = 0;
            last_update_time = tic;
        else
            dt = toc(last_update_time);
            last_update_time = tic;
        end

        % Failsafe: reject large dt values
        if dt > 0.5
            fprintf('WARNING: Large dt detected (%.2fs) - setting to 0\n', dt);
            dt = 0;
        end

        % Accumulate distance traveled
        distance_traveled = distance_traveled + (MOVE_SPEED * dt);

        fprintf('Phase 3: Distance to exit: %.2f m, Traveled: %.2f m\n', ...
                distance_to_exit, distance_traveled);

        if distance_to_exit > 0.15 % 15cm tolerance
            result.status = 'Moving through door';
            result.V(1) = MOVE_SPEED;  % Forward movement
            result.V(2) = 0;           % No turning

            fprintf('Phase 3: Moving FORWARD through door (%.1f m/s)\n', MOVE_SPEED);
        else
            % Phase 4: Completed
            result.phase = 4;
            result.status = 'Door entry completed';
            result.V = [0; 0];
            result.completed = true;

            fprintf('Phase 4: COMPLETED! Passed through door.\n');
            fprintf('Total distance traveled: %.2f m\n', distance_traveled);

            % Reset persistent variables for next door
            phase1_completed = [];
            door_verified = [];
            distance_traveled = [];
            last_update_time = [];
        end
    end

    fprintf('Command: V=[%.2f, %.2f] (linear, angular)\n', result.V(1), result.V(2));
    fprintf('=====================================\n');
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end

function params = getDefaultDoorParams()
    % Default door parameters
    params = struct();

    % Phase 1: Position Correction
    params.POSITION_TOLERANCE = 0.15;          % ±15cm acceptable distance error
    params.POSITION_ANGLE_TOLERANCE = 0.087;   % ±5 degrees acceptable heading error
    params.CORRECTION_TURN_SPEED = 0.3;        % rad/s for correction turns
    params.CORRECTION_MOVE_SPEED = 0.15;       % m/s for correction movement

    % Phase 2: Turning towards door
    params.TURN_TOLERANCE = 0.1;               % radians (~6 degrees)
    params.TURN_SPEED = 0.1;                   % rad/s for turning

    % Phase 2.5: Door Detection
    params.ANGLE_TOLERANCE = 30;               % ±30 degrees cone towards door
    params.NARROW_ROI_ANGLE = 12;              % ±12 degrees for safe passage
    params.DOOR_HEIGHT_MIN = 0.5;              % Minimum height (avoid floor)
    params.DOOR_HEIGHT_MAX = 1.7;              % Maximum door height
    params.MIN_POINTS_THRESHOLD = 5;           % Minimum points for analysis
    params.DEPTH_THRESHOLD = 0.3;              % Depth difference threshold

    % Phase 3: Movement through door
    params.MOVE_SPEED = 0.2;                   % m/s for forward movement
end

function door_state = detectDoorState(pointCloud, wheelchair_pose, door_center, odometry_mode, door_params)
    % General door state detection for regular doors
    % For now, this is a placeholder that checks if there are obstacles in the path
    %
    % This function should be implemented similar to detectElevatorDoorState
    % but adapted for regular doors (different geometry, no elevator-specific logic)

    fprintf('  Detecting door state (regular door)...\n');

    if isempty(pointCloud) || size(pointCloud, 1) == 0
        fprintf('  Warning: Empty point cloud - assuming door is passable\n');
        door_state = 'unknown';
        return;
    end

    % Extract parameters
    ANGLE_TOLERANCE = door_params.ANGLE_TOLERANCE;
    NARROW_ROI_ANGLE = door_params.NARROW_ROI_ANGLE;
    DOOR_HEIGHT_MIN = door_params.DOOR_HEIGHT_MIN;
    DOOR_HEIGHT_MAX = door_params.DOOR_HEIGHT_MAX;
    MIN_POINTS = door_params.MIN_POINTS_THRESHOLD;

    % Filter points within angular cone towards door
    wheelchair_pos = wheelchair_pose(1:2);
    wheelchair_yaw = wheelchair_pose(3);

    % Calculate angles to each point
    dx = pointCloud(:,1) - wheelchair_pos(1);
    dy = pointCloud(:,2) - wheelchair_pos(2);
    angles = atan2(dy, dx);
    angle_diff = angdiff(angles, wheelchair_yaw);

    % Filter by angle (narrow ROI for safe passage)
    narrow_mask = abs(rad2deg(angle_diff)) <= NARROW_ROI_ANGLE;
    narrow_points = pointCloud(narrow_mask, :);

    % Filter by height (door height range)
    if ~isempty(narrow_points)
        height_mask = (narrow_points(:,3) >= DOOR_HEIGHT_MIN) & ...
                      (narrow_points(:,3) <= DOOR_HEIGHT_MAX);
        door_roi_points = narrow_points(height_mask, :);
    else
        door_roi_points = [];
    end

    fprintf('  Points in narrow ROI (±%d deg, height %.1f-%.1f m): %d\n', ...
            NARROW_ROI_ANGLE, DOOR_HEIGHT_MIN, DOOR_HEIGHT_MAX, size(door_roi_points, 1));

    % Decision logic
    if size(door_roi_points, 1) < MIN_POINTS
        % Very few or no obstacles detected in path
        door_state = 'open';
        fprintf('  Decision: OPEN/PASSABLE (< %d obstacle points)\n', MIN_POINTS);
    else
        % Significant obstacles detected
        door_state = 'closed';
        fprintf('  Decision: CLOSED/BLOCKED (%d obstacle points)\n', size(door_roi_points, 1));
    end
end
