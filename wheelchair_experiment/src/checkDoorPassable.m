function result = checkDoorPassable(lidar_scan_data, wheelchair_pose, door_center, odometry_mode, door_params, odometry_target_angle)
    % checkDoorPassable - Check if a door is passable using LiDAR data
    %
    % Unified door detection algorithm for both regular doors and elevators.
    % Uses coverage-based depth analysis: checks if all points in the wheelchair's
    % path extend beyond the expected door surface (indicating door is open).
    %
    % Inputs:
    %   lidar_scan_data - struct with xyz_global and xyz_local point cloud data
    %                     OR direct point cloud array (Nx3) for legacy compatibility
    %   wheelchair_pose - [x, y, yaw] current wheelchair pose
    %   door_center - [x, y] position of door/elevator center
    %   odometry_mode - boolean: true = use local coordinates, false = use global
    %   door_params - struct with door detection parameters
    %   odometry_target_angle - (optional) target angle in odometry mode (default: 0 = forward)
    %                           Use pi (180°) for reverse direction
    %
    % Outputs:
    %   result - struct with:
    %       .door_state - 'open', 'closed', or 'unknown'
    %       .verified - boolean, true if door is confirmed passable
    %       .point_count - number of points analyzed in door ROI
    %       .coordinate_mode - 'global' or 'local' (which coordinates were used)
    %       .coverage_percentage - percentage of ROI points that are "deep"
    %
    % Examples:
    %   % Forward detection (default)
    %   result = checkDoorPassable(lidar_data, [27, 12, pi/2], [27, 12.2], false, door_params);
    %
    %   % Reverse detection (looking backward)
    %   result = checkDoorPassable(lidar_data, pose, door_center, true, door_params, pi);

    % Handle optional odometry_target_angle parameter
    if nargin < 6 || isempty(odometry_target_angle)
        odometry_target_angle = 0; % Default: forward direction (0°)
    end

    % Initialize result structure
    result = struct();
    result.door_state = 'unknown';
    result.verified = false;
    result.point_count = 0;
    result.coordinate_mode = 'none';
    result.coverage_percentage = 0;

    % Determine direction string for logging
    if odometry_mode
        if abs(odometry_target_angle) < 0.1
            direction_str = 'forward';
        elseif abs(odometry_target_angle - pi) < 0.1
            direction_str = 'reverse';
        else
            direction_str = sprintf('%.0f°', rad2deg(odometry_target_angle));
        end
        fprintf('  Checking door passability (Mode: odometry %s)...\n', direction_str);
    else
        fprintf('  Checking door passability (Mode: map)...\n');
    end

    % Extract point cloud data based on coordinate mode
    if isempty(lidar_scan_data)
        fprintf('  Warning: No LiDAR data available\n');
        result.door_state = 'unknown';
        return;
    end

    % Handle structured data (preferred format)
    if isstruct(lidar_scan_data) && isfield(lidar_scan_data, 'xyz_global') && isfield(lidar_scan_data, 'xyz_local')
        pointCloud_global = lidar_scan_data.xyz_global;
        pointCloud_local = lidar_scan_data.xyz_local;

        if odometry_mode
            % Use local coordinates (odometry mode)
            if ~isempty(pointCloud_local)
                pointCloud = pointCloud_local;
                result.coordinate_mode = 'local';
                fprintf('  Using LOCAL coordinates (odometry mode)\n');
            else
                fprintf('  Warning: Odometry mode requested but no local data available\n');
                result.door_state = 'unknown';
                return;
            end
        else
            % Use global coordinates (map mode)
            if ~isempty(pointCloud_global)
                pointCloud = pointCloud_global;
                result.coordinate_mode = 'global';
                fprintf('  Using GLOBAL coordinates (map mode)\n');
            else
                fprintf('  Warning: Map mode requested but no global data available\n');
                result.door_state = 'unknown';
                return;
            end
        end
    else
        % Legacy format: assume it's direct point cloud data
        if odometry_mode
            fprintf('  Warning: Odometry mode with legacy data format\n');
            result.door_state = 'unknown';
            return;
        end
        pointCloud = lidar_scan_data;
        result.coordinate_mode = 'global';
        fprintf('  Using legacy point cloud format (global)\n');
    end

    % Handle cell array wrapper (from Estimate.m)
    if iscell(pointCloud)
        pointCloud = pointCloud{1};
    end

    % Check if point cloud is valid
    if isempty(pointCloud) || size(pointCloud, 1) == 0
        fprintf('  Warning: Empty point cloud after extraction\n');
        result.door_state = 'unknown';
        return;
    end

    fprintf('  Point cloud: %d points\n', size(pointCloud, 1));

    % ========== UNIFIED DOOR DETECTION ALGORITHM ==========
    % Based on coverage-based depth analysis (from detectDoorState)

    % Visualization control - plot every N iterations when door is closed
    persistent vis_counter;
    if isempty(vis_counter)
        vis_counter = 0;
    end
    vis_counter = vis_counter + 1;

    % Extract default parameters if not provided
    if nargin < 5 || isempty(door_params)
        door_params = struct();
        door_params.ANGLE_TOLERANCE = 30;       % ±30 degrees cone towards door
        door_params.NARROW_ROI_ANGLE = 12;      % ±12 degrees for wheelchair safe passage
        door_params.DOOR_HEIGHT_MIN = 0.3;      % Minimum height (avoid floor)
        door_params.DOOR_HEIGHT_MAX = 2.2;      % Maximum door height
        door_params.MIN_POINTS_THRESHOLD = 5;   % Minimum points needed
        door_params.DEPTH_THRESHOLD = 0.3;      % Points must be this much deeper
        door_params.FIXED_ELEVATOR_DISTANCE = 2.5; % Fixed distance in odometry mode
    end

    % Extract parameters
    ANGLE_TOLERANCE = door_params.ANGLE_TOLERANCE;
    NARROW_ROI_ANGLE = door_params.NARROW_ROI_ANGLE;
    DOOR_HEIGHT_MIN = door_params.DOOR_HEIGHT_MIN;
    DOOR_HEIGHT_MAX = door_params.DOOR_HEIGHT_MAX;
    MIN_POINTS = door_params.MIN_POINTS_THRESHOLD;
    DEPTH_THRESHOLD = door_params.DEPTH_THRESHOLD;

    % FIXED_ELEVATOR_DISTANCE was removed - use MOVE_DISTANCE or default 2.5m
    if isfield(door_params, 'MOVE_DISTANCE')
        FIXED_DOOR_DISTANCE = door_params.MOVE_DISTANCE;
    elseif isfield(door_params, 'FIXED_ELEVATOR_DISTANCE')
        FIXED_DOOR_DISTANCE = door_params.FIXED_ELEVATOR_DISTANCE;
    else
        FIXED_DOOR_DISTANCE = 2.5; % Default: 2.5m fixed distance in odometry mode
    end

    % Calculate target direction and distance to door
    wheelchair_pos = wheelchair_pose(1:2);

    if odometry_mode
        % Odometry mode: use specified target angle (0° = forward, pi = reverse)
        target_angle = odometry_target_angle;
        distance_to_door = FIXED_DOOR_DISTANCE;
        fprintf('  Odometry Mode: target angle %.1f° (%.2fm fixed distance)\n', ...
                rad2deg(target_angle), distance_to_door);
    else
        % Map mode: calculate direction to door center
        direction_to_door = door_center - wheelchair_pos;
        distance_to_door = norm(direction_to_door);
        target_angle = atan2(direction_to_door(2), direction_to_door(1));
        fprintf('  Map Mode: wheelchair [%.2f, %.2f] -> door [%.2f, %.2f]\n', ...
                wheelchair_pos(1), wheelchair_pos(2), door_center(1), door_center(2));
        fprintf('  Direction: %.1f°, Distance: %.2fm\n', rad2deg(target_angle), distance_to_door);
    end

    % Step 1: Filter by height (door height range)
    height_filter = pointCloud(:,3) >= DOOR_HEIGHT_MIN & pointCloud(:,3) <= DOOR_HEIGHT_MAX;
    height_filtered_points = pointCloud(height_filter, :);

    if size(height_filtered_points, 1) < MIN_POINTS
        result.door_state = 'unknown';
        result.point_count = size(pointCloud, 1);
        fprintf('  Insufficient points (%d) at door height\n', size(height_filtered_points, 1));
        fprintf('  Result: Door state UNKNOWN\n');
        return;
    end

    % Step 2: Filter points within angular cone towards door
    if odometry_mode
        % Points already in LiDAR coordinates (relative to wheelchair)
        point_angles = atan2(height_filtered_points(:,2), height_filtered_points(:,1));
        points_relative = height_filtered_points(:,1:2);
    else
        % Convert to wheelchair-relative coordinates
        points_relative = height_filtered_points(:,1:2) - wheelchair_pos;
        point_angles = atan2(points_relative(:,2), points_relative(:,1));
    end

    % Filter by angle
    angle_diff = angdiff(point_angles, target_angle);
    angle_tolerance_rad = deg2rad(ANGLE_TOLERANCE);
    within_cone = abs(angle_diff) <= angle_tolerance_rad;

    cone_points = height_filtered_points(within_cone, :);

    fprintf('  %d points at door height, %d within ±%d° cone\n', ...
            size(height_filtered_points, 1), size(cone_points, 1), ANGLE_TOLERANCE);

    if size(cone_points, 1) < MIN_POINTS
        result.door_state = 'unknown';
        result.point_count = size(pointCloud, 1);
        fprintf('  Insufficient points (%d) within angular cone\n', size(cone_points, 1));
        fprintf('  Result: Door state UNKNOWN\n');
        return;
    end

    % Step 3: Calculate distances from wheelchair to each cone point
    if odometry_mode
        cone_distances = sqrt(sum(cone_points(:,1:2).^2, 2));
    else
        cone_distances = sqrt(sum((cone_points(:,1:2) - wheelchair_pos).^2, 2));
    end

    % Step 4: Find "deep" points (beyond door surface - seeing into the room)
    expected_door_distance = distance_to_door;
    deep_threshold = expected_door_distance + DEPTH_THRESHOLD;
    deep_points_mask = cone_distances > deep_threshold;
    deep_points = cone_points(deep_points_mask, :);

    num_deep_points = size(deep_points, 1);

    fprintf('  Expected door surface: %.2fm, Deep threshold: %.2fm\n', ...
            expected_door_distance, deep_threshold);
    fprintf('  Found %d points extending deeper\n', num_deep_points);

    % Step 5: Center-point based complete coverage detection
    % Find center point (most aligned with target direction)
    if odometry_mode
        cone_angles = atan2(cone_points(:,2), cone_points(:,1));
    else
        cone_angles = atan2(cone_points(:,2) - wheelchair_pos(2), ...
                           cone_points(:,1) - wheelchair_pos(1));
    end

    angle_diffs = abs(angdiff(cone_angles, target_angle));
    [~, center_idx] = min(angle_diffs);
    center_point = cone_points(center_idx, :);
    center_angle = cone_angles(center_idx);

    fprintf('  Center point: [%.2f, %.2f] at angle %.1f°\n', ...
            center_point(1), center_point(2), rad2deg(center_angle));

    % Step 6: Define narrow ROI (wheelchair safe passage zone)
    narrow_roi_tolerance = deg2rad(NARROW_ROI_ANGLE);
    narrow_roi_mask = abs(angdiff(cone_angles, center_angle)) <= narrow_roi_tolerance;
    narrow_roi_points = cone_points(narrow_roi_mask, :);
    num_narrow_roi = size(narrow_roi_points, 1);

    fprintf('  Narrow ROI (±%d°): %d points\n', NARROW_ROI_ANGLE, num_narrow_roi);

    if num_narrow_roi < MIN_POINTS
        result.door_state = 'unknown';
        result.point_count = size(pointCloud, 1);
        fprintf('  Decision: UNKNOWN (insufficient points in narrow ROI)\n');
        return;
    end

    % Step 7: Check coverage - are ALL narrow ROI points deep? (100% = open)
    if odometry_mode
        narrow_roi_distances = sqrt(sum(narrow_roi_points(:,1:2).^2, 2));
    else
        narrow_roi_distances = sqrt(sum((narrow_roi_points(:,1:2) - wheelchair_pos).^2, 2));
    end

    narrow_roi_deep_mask = narrow_roi_distances > deep_threshold;
    num_deep_in_roi = sum(narrow_roi_deep_mask);
    coverage_percentage = (num_deep_in_roi / num_narrow_roi) * 100;

    fprintf('  Deep points in ROI: %d/%d (%.1f%% coverage)\n', ...
            num_deep_in_roi, num_narrow_roi, coverage_percentage);

    % Decision based on complete coverage
    if num_deep_in_roi == num_narrow_roi
        door_state = 'open';
        fprintf('  Decision: OPEN (100%% coverage - no obstacles in path)\n');
    else
        door_state = 'closed';
        fprintf('  Decision: CLOSED (%.1f%% coverage - obstacle blocking path)\n', coverage_percentage);
    end

    % Update result structure
    result.door_state = door_state;
    result.point_count = size(pointCloud, 1);
    result.coverage_percentage = coverage_percentage;

    % Determine if door is verified as passable
    if strcmp(door_state, 'open')
        result.verified = true;
        fprintf('  Result: Door OPEN/PASSABLE - verified\n');
    elseif strcmp(door_state, 'closed')
        result.verified = false;
        fprintf('  Result: Door CLOSED/BLOCKED - not passable\n');

        % Visualize every 5 iterations when door is closed (to reduce computational load)
        if mod(vis_counter, 5) == 0
            fprintf('  [VIS] Plotting door detection - DOOR CLOSED (iteration %d)\n', vis_counter);
            detection_data = struct();
            detection_data.cone_points = cone_points;
            detection_data.narrow_points = narrow_roi_points;
            detection_data.deep_points = deep_points;
            detection_data.center_point = center_point;
            detection_data.wheelchair_pos = wheelchair_pos;
            detection_data.target_angle = target_angle;

            plotDoorDetectionDebug(pointCloud, detection_data, wheelchair_pose, ...
                                   door_center, door_state, odometry_mode, door_params, ...
                                   coverage_percentage);
        end
    else
        result.verified = false;
        fprintf('  Result: Door state UNKNOWN - not verified\n');
    end
end

function str = ternary(condition, true_val, false_val)
    % Simple ternary operator helper
    if condition
        str = true_val;
    else
        str = false_val;
    end
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate shortest angular difference between two angles
    % Result is in range [-pi, pi]
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end

function plotDoorDetectionDebug(pointCloud, detection_data, wheelchair_pose, door_center, door_state, odometry_mode, door_params, coverage_percentage)
    % Plot door detection debug visualization when door is closed
    % Shows point cloud analysis with color-coded regions

    persistent fig_handle;

    % Create or reuse figure
    if isempty(fig_handle) || ~ishandle(fig_handle)
        mode_str = 'Map Mode';
        if odometry_mode
            mode_str = 'Odometry Mode';
        end
        fig_handle = figure('Name', sprintf('Door Detection Debug - %s', mode_str), ...
                           'Position', [100, 100, 900, 700]);
    else
        figure(fig_handle);
        clf;
    end

    hold on;

    % Extract visualization data
    cone_points = detection_data.cone_points;
    narrow_points = detection_data.narrow_points;
    deep_points = detection_data.deep_points;
    center_point = detection_data.center_point;
    wheelchair_pos = detection_data.wheelchair_pos;
    target_angle = detection_data.target_angle;

    % Set wheelchair position based on mode
    if odometry_mode
        wheelchair_pos = [0, 0];  % Origin in odometry mode
        door_center_viz = wheelchair_pos + 2.5 * [cos(target_angle), sin(target_angle)];
    else
        wheelchair_pos = wheelchair_pose(1:2);
        door_center_viz = door_center;
    end

    % 1. Plot all point cloud in light blue
    if ~isempty(pointCloud) && size(pointCloud, 1) > 0
        scatter(pointCloud(:,1), pointCloud(:,2), 3, [0.7 0.9 1], 'filled', ...
               'MarkerFaceAlpha', 0.3);
    end

    % 2. Plot cone points (wider angle tolerance) in light red
    if ~isempty(cone_points) && size(cone_points, 1) > 0
        scatter(cone_points(:,1), cone_points(:,2), 15, [1 0.5 0.5], 'filled', ...
               'MarkerFaceAlpha', 0.6);
    end

    % 3. Plot narrow ROI points (critical passage zone) in ORANGE
    if ~isempty(narrow_points) && size(narrow_points, 1) > 0
        scatter(narrow_points(:,1), narrow_points(:,2), 25, [1 0.6 0], 'filled', ...
               'MarkerEdgeColor', 'black', 'LineWidth', 1);
    end

    % 4. Plot deep points (seeing past door - indicates door is open) in GREEN
    if ~isempty(deep_points) && size(deep_points, 1) > 0
        scatter(deep_points(:,1), deep_points(:,2), 30, 'green', 'filled', ...
               'MarkerEdgeColor', 'black', 'LineWidth', 1.5);
    end

    % 5. Plot center point (most aligned with door direction) in MAGENTA
    if ~isempty(center_point) && size(center_point, 1) > 0
        scatter(center_point(1), center_point(2), 100, 'magenta', 'filled', 'p', ...
               'MarkerEdgeColor', 'black', 'LineWidth', 2);
    end

    % 6. Plot wheelchair position (blue triangle)
    scatter(wheelchair_pos(1), wheelchair_pos(2), 200, 'blue', 'filled', '^', ...
           'MarkerEdgeColor', 'black', 'LineWidth', 2);

    % 7. Plot door center (orange square)
    scatter(door_center_viz(1), door_center_viz(2), 200, [0.8 0.4 0], 'filled', 's', ...
           'MarkerEdgeColor', 'black', 'LineWidth', 2);

    % 8. Plot direction arrow from wheelchair towards door
    arrow_length = 1.5;
    direction_vec = [cos(target_angle), sin(target_angle)];
    arrow_end = wheelchair_pos + arrow_length * direction_vec;
    plot([wheelchair_pos(1), arrow_end(1)], [wheelchair_pos(2), arrow_end(2)], ...
         'Color', 'blue', 'LineWidth', 3, 'Marker', '>', 'MarkerSize', 8);

    % 9. Plot angular cone boundaries
    if ~odometry_mode
        distance = norm(door_center_viz - wheelchair_pos);
    else
        distance = 2.5;
    end

    ANGLE_TOLERANCE = door_params.ANGLE_TOLERANCE;
    NARROW_ROI_ANGLE = door_params.NARROW_ROI_ANGLE;

    % Wide cone boundary (±ANGLE_TOLERANCE)
    cone_left = target_angle + deg2rad(ANGLE_TOLERANCE);
    cone_right = target_angle - deg2rad(ANGLE_TOLERANCE);
    cone_radius = distance + 1.0;

    plot([wheelchair_pos(1), wheelchair_pos(1) + cone_radius*cos(cone_left)], ...
         [wheelchair_pos(2), wheelchair_pos(2) + cone_radius*sin(cone_left)], ...
         '--', 'Color', [1 0.5 0.5], 'LineWidth', 1.5);
    plot([wheelchair_pos(1), wheelchair_pos(1) + cone_radius*cos(cone_right)], ...
         [wheelchair_pos(2), wheelchair_pos(2) + cone_radius*sin(cone_right)], ...
         '--', 'Color', [1 0.5 0.5], 'LineWidth', 1.5);

    % Narrow ROI boundary (±NARROW_ROI_ANGLE)
    narrow_left = target_angle + deg2rad(NARROW_ROI_ANGLE);
    narrow_right = target_angle - deg2rad(NARROW_ROI_ANGLE);

    plot([wheelchair_pos(1), wheelchair_pos(1) + cone_radius*cos(narrow_left)], ...
         [wheelchair_pos(2), wheelchair_pos(2) + cone_radius*sin(narrow_left)], ...
         '-', 'Color', [1 0.6 0], 'LineWidth', 2);
    plot([wheelchair_pos(1), wheelchair_pos(1) + cone_radius*cos(narrow_right)], ...
         [wheelchair_pos(2), wheelchair_pos(2) + cone_radius*sin(narrow_right)], ...
         '-', 'Color', [1 0.6 0], 'LineWidth', 2);

    % Labels and formatting
    xlabel('X (m)');
    ylabel('Y (m)');

    mode_str = 'Map Mode';
    if odometry_mode
        mode_str = 'Odometry Mode (Wheelchair @ Origin)';
    end

    % Title with coverage information
    if ~isempty(narrow_points) && size(narrow_points, 1) > 0
        num_narrow = size(narrow_points, 1);
        num_deep = size(deep_points, 1);
        title(sprintf('Door Detection: %s | %s | ROI ±%d° | Coverage: %d/%d (%.0f%%)', ...
                      upper(door_state), mode_str, NARROW_ROI_ANGLE, num_deep, num_narrow, coverage_percentage));
    else
        title(sprintf('Door Detection: %s | %s | ROI ±%d°', ...
                      upper(door_state), mode_str, NARROW_ROI_ANGLE));
    end

    axis equal;
    grid on;

    % Set axis limits to show area around wheelchair
    xlim([wheelchair_pos(1) - 3, wheelchair_pos(1) + 3]);
    ylim([wheelchair_pos(2) - 3, wheelchair_pos(2) + 3]);

    % Create legend
    legend_entries = {};
    if ~isempty(pointCloud), legend_entries{end+1} = 'All Points'; end
    if ~isempty(cone_points), legend_entries{end+1} = sprintf('±%d° Cone', ANGLE_TOLERANCE); end
    if ~isempty(narrow_points), legend_entries{end+1} = sprintf('±%d° ROI (Critical)', NARROW_ROI_ANGLE); end
    if ~isempty(deep_points), legend_entries{end+1} = 'Deep Points (Past Door)'; end
    if ~isempty(center_point), legend_entries{end+1} = 'Center Point'; end
    legend_entries = [legend_entries, {'Wheelchair', 'Door Center', 'Direction'}];

    if ~isempty(cone_points)
        legend_entries = [legend_entries, {'Wide Cone Boundary', 'Narrow ROI Boundary'}];
    end

    legend(legend_entries, 'Location', 'best', 'FontSize', 9);

    drawnow;
end
