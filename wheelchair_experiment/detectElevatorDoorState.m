function door_state = detectElevatorDoorState(pointCloud, wheelchair_pose, elevator_center, odometry_mode, door_params)
    % Detect elevator door state using angular approach
    % Method: Check if points within ±30° towards elevator extend beyond elevator center distance
    % 
    % Inputs:
    %   pointCloud - 3D point cloud data (Nx3 matrix: [x, y, z]) 
    %                In GLOBAL coordinates (default) or LOCAL coordinates (odometry_mode)
    %   wheelchair_pose - current wheelchair position and orientation [x, y, yaw]
    %   elevator_center - elevator center position [x, y] (default: [27, 12]) - ignored in odometry_mode
    %   odometry_mode - boolean, if true uses wheelchair heading direction instead of elevator_center
    %   door_params - struct with detection parameters (optional)
    %
    % Output:
    %   door_state - 'open', 'closed', or 'unknown'
    
    if nargin < 3
        elevator_center = [27, 12]; % Default elevator center
    end
    
    if nargin < 4
        odometry_mode = false; % Default to map-based mode
    end
    
    if nargin < 5 || isempty(door_params)
        % Default parameters for angular door detection
        door_params = struct();
        door_params.ANGLE_TOLERANCE = 30;       % ±30 degrees cone towards elevator (initial filtering)
        door_params.NARROW_ROI_ANGLE = 12;      % ±12 degrees for wheelchair safe passage (1.3m at 3m distance)
        door_params.DOOR_HEIGHT_MIN = 0.3;      % Minimum height (avoid floor)
        door_params.DOOR_HEIGHT_MAX = 2.2;      % Maximum door height  
        door_params.MIN_POINTS_THRESHOLD = 5;   % Minimum points needed for analysis
        door_params.DEPTH_THRESHOLD = 0.3;      % Points must be this much deeper than elevator center
        door_params.FIXED_ELEVATOR_DISTANCE = 2.5; % Fixed elevator center distance in odometry mode (meters)
    end
    
    % Extract parameters from struct
    ANGLE_TOLERANCE = door_params.ANGLE_TOLERANCE;
    NARROW_ROI_ANGLE = door_params.NARROW_ROI_ANGLE;
    DOOR_HEIGHT_MIN = door_params.DOOR_HEIGHT_MIN;
    DOOR_HEIGHT_MAX = door_params.DOOR_HEIGHT_MAX;
    MIN_POINTS_THRESHOLD = door_params.MIN_POINTS_THRESHOLD;
    DEPTH_THRESHOLD = door_params.DEPTH_THRESHOLD;
    FIXED_ELEVATOR_DISTANCE = door_params.FIXED_ELEVATOR_DISTANCE;
    
    try
        % Validate inputs
        if isempty(pointCloud) || size(pointCloud, 2) < 3
            door_state = 'unknown';
            fprintf('Door Detection: Invalid point cloud data\n');
            return;
        end
        
        % Convert wheelchair pose
        wheelchair_pos = wheelchair_pose(1:2);
        wheelchair_yaw = wheelchair_pose(3);
        
        if odometry_mode
            % Odometry mode: use LiDAR forward direction (angle 0) and fixed distance
            target_angle = 0; % LiDAR angle 0 = forward direction of wheelchair
            distance_to_elevator = FIXED_ELEVATOR_DISTANCE; % Fixed arbitrary distance
            % Calculate elevator center from wheelchair origin
            elevator_center_calc = [0, 0] + distance_to_elevator * [cos(target_angle), sin(target_angle)];
            
            fprintf('Door Detection (Odometry Mode): Wheelchair at origin [0, 0]\n');
            fprintf('LiDAR forward direction (0°), Expected elevator center: [%.2f, %.2f]\n', ...
                    elevator_center_calc(1), elevator_center_calc(2));
            fprintf('Fixed distance: %.2fm (Point cloud in LOCAL coordinates)\n', distance_to_elevator);
        else
            % Map mode: calculate direction vector from wheelchair to elevator center
            direction_to_elevator = elevator_center - wheelchair_pos;
            distance_to_elevator = norm(direction_to_elevator);
            direction_unit = direction_to_elevator / distance_to_elevator;
            
            % Calculate target angle towards elevator center
            target_angle = atan2(direction_to_elevator(2), direction_to_elevator(1));
            
            fprintf('Door Detection (Map Mode): Wheelchair at [%.2f, %.2f] -> Elevator [%.2f, %.2f]\n', ...
                    wheelchair_pos(1), wheelchair_pos(2), elevator_center(1), elevator_center(2));
            fprintf('Direction: %.1f°, Distance: %.2fm\n', rad2deg(target_angle), distance_to_elevator);
        end
        
        % Step 1: Filter points by height (door height range)
        height_filter = pointCloud(:,3) >= DOOR_HEIGHT_MIN & pointCloud(:,3) <= DOOR_HEIGHT_MAX;
        height_filtered_points = pointCloud(height_filter, :);
        
        if size(height_filtered_points, 1) < MIN_POINTS_THRESHOLD
            door_state = 'unknown';
            fprintf('Door Detection: Insufficient points (%d) at door height\n', size(height_filtered_points, 1));
            return;
        end
        
        % Step 2: Filter points within ±30° cone towards elevator
        if odometry_mode
            % In odometry mode, point cloud is already in LiDAR coordinates (relative to wheelchair)
            % LiDAR angle 0 = forward direction of wheelchair
            point_angles = atan2(height_filtered_points(:,2), height_filtered_points(:,1));
            points_relative = height_filtered_points(:,1:2); % Already relative to LiDAR/wheelchair
        else
            % In map mode, convert points to wheelchair-relative coordinates
            points_relative = height_filtered_points(:,1:2) - wheelchair_pos; % Relative to wheelchair
            point_angles = atan2(points_relative(:,2), points_relative(:,1));
        end
        
        % Calculate angular difference from target direction
        angle_diff = angdiff(point_angles, target_angle);
        angle_tolerance_rad = deg2rad(ANGLE_TOLERANCE);
        within_cone = abs(angle_diff) <= angle_tolerance_rad;
        
        cone_points = height_filtered_points(within_cone, :);
        
        fprintf('Door Detection: %d points at door height, %d within ±%d° cone\n', ...
                size(height_filtered_points, 1), size(cone_points, 1), ANGLE_TOLERANCE);
        
        if size(cone_points, 1) < MIN_POINTS_THRESHOLD
            door_state = 'unknown';
            fprintf('Door Detection: Insufficient points (%d) within angular cone\n', size(cone_points, 1));
            return;
        end
        
        % Step 3: Calculate distances from wheelchair to each cone point
        if odometry_mode
            % In odometry mode, points are already relative to LiDAR/wheelchair
            cone_distances = sqrt(sum(cone_points(:,1:2).^2, 2));
        else
            % In map mode, calculate distance from wheelchair position
            cone_distances = sqrt(sum((cone_points(:,1:2) - wheelchair_pos).^2, 2));
        end
        
        % Step 4: Find points that extend beyond elevator center distance + threshold
        % These points indicate we're seeing deeper into the elevator (door is open)
        expected_door_distance = distance_to_elevator;
        deep_threshold = expected_door_distance + DEPTH_THRESHOLD;
        deep_points_mask = cone_distances > deep_threshold;
        deep_points = cone_points(deep_points_mask, :);
        deep_distances = cone_distances(deep_points_mask);
        
        num_deep_points = size(deep_points, 1);
        
        fprintf('Door Detection Analysis:\n');
        fprintf('  - Expected door surface distance: %.2fm\n', expected_door_distance);
        fprintf('  - Looking for points beyond: %.2fm\n', deep_threshold);
        fprintf('  - Found %d points extending deeper\n', num_deep_points);
        
        if num_deep_points > 0
            fprintf('  - Deep point distances: [%.2f', deep_distances(1));
            for i = 2:min(5, length(deep_distances))
                fprintf(', %.2f', deep_distances(i));
            end
            if length(deep_distances) > 5
                fprintf(', ... (%d more)', length(deep_distances) - 5);
            end
            fprintf('] meters\n');
        end
        
        % Step 5: Center-point based complete coverage detection
        % Find center point among ALL cone points (nearest to target direction)
        if odometry_mode
            % In odometry mode, points are already relative to LiDAR/wheelchair
            cone_angles = atan2(cone_points(:,2), cone_points(:,1));
        else
            % In map mode, calculate angles relative to wheelchair position
            cone_angles = atan2(cone_points(:,2) - wheelchair_pos(2), cone_points(:,1) - wheelchair_pos(1));
        end
        
        angle_diffs = abs(angdiff(cone_angles, target_angle));
        [~, center_idx] = min(angle_diffs);
        center_point = cone_points(center_idx, :);
        center_angle = cone_angles(center_idx);
        
        fprintf('  - Center point: [%.2f, %.2f] at angle %.1f°\n', ...
                center_point(1), center_point(2), rad2deg(center_angle));
        
        % Define narrow ROI: points within ±NARROW_ROI_ANGLE of center point
        narrow_roi_tolerance = deg2rad(NARROW_ROI_ANGLE);
        narrow_roi_mask = abs(angdiff(cone_angles, center_angle)) <= narrow_roi_tolerance;
        narrow_roi_points = cone_points(narrow_roi_mask, :);
        num_narrow_roi = size(narrow_roi_points, 1);
        
        fprintf('  - Narrow ROI (±%d°): %d points\n', NARROW_ROI_ANGLE, num_narrow_roi);
        
        if num_narrow_roi < MIN_POINTS_THRESHOLD
            door_state = 'unknown';
            fprintf('Door Detection Result: UNKNOWN (insufficient points in narrow ROI)\n');
        else
            % Check if ALL narrow ROI points are deep points (complete coverage)
            if odometry_mode
                % In odometry mode, points are already relative to LiDAR/wheelchair
                narrow_roi_distances = sqrt(sum(narrow_roi_points(:,1:2).^2, 2));
            else
                % In map mode, calculate distance from wheelchair position
                narrow_roi_distances = sqrt(sum((narrow_roi_points(:,1:2) - wheelchair_pos).^2, 2));
            end
            
            narrow_roi_deep_mask = narrow_roi_distances > deep_threshold;
            num_deep_in_roi = sum(narrow_roi_deep_mask);
            coverage_percentage = (num_deep_in_roi / num_narrow_roi) * 100;
            
            fprintf('  - Deep points in ROI: %d/%d (%.1f%% coverage)\n', ...
                    num_deep_in_roi, num_narrow_roi, coverage_percentage);
            
            if num_deep_in_roi == num_narrow_roi
                door_state = 'open';
                fprintf('Door Detection Result: OPEN (100%% coverage in wheelchair path)\n');
            else
                door_state = 'closed';
                fprintf('Door Detection Result: CLOSED (incomplete coverage - obstacle in path)\n');
            end
        end
        
    catch ME
        door_state = 'unknown';
        fprintf('Door Detection Error: %s\n', ME.message);
    end
end


function angle_diff = angdiff(angle1, angle2)
    % Calculate the shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end