function door_state = debugElevatorDoorDetection(pointCloud, wheelchair_pose, elevator_center, enable_debug, odometry_mode, door_params)
    % Debug version using angular approach - simple visualization
    % 
    % Inputs:
    %   pointCloud - 3D point cloud data (Nx3 matrix: [x, y, z]) 
    %                In GLOBAL coordinates (map mode) or LOCAL coordinates (odometry mode)
    %   wheelchair_pose - current wheelchair position and orientation [x, y, yaw]
    %   elevator_center - elevator center position [x, y] (default: [27, 12]) - ignored in odometry mode
    %   enable_debug - boolean flag for debug output
    %   odometry_mode - boolean, if true uses wheelchair-relative coordinates
    %   door_params - struct with detection parameters (optional)
    %
    % Output:
    %   door_state - 'open', 'closed', or 'unknown'
    
    % Get parameters from door_params struct or use defaults
    if nargin < 6 || isempty(door_params)
        % Default parameters matching main detection function
        door_params = struct();
        door_params.ANGLE_TOLERANCE = 30;       % ±30 degrees cone towards elevator (initial filtering)
        door_params.NARROW_ROI_ANGLE = 12;      % ±12 degrees for wheelchair safe passage
        door_params.DOOR_HEIGHT_MIN = 0.3;      % Minimum height (avoid floor)
        door_params.DOOR_HEIGHT_MAX = 2.2;      % Maximum door height
    end
    
    % Extract parameters from struct
    ANGLE_TOLERANCE = door_params.ANGLE_TOLERANCE;
    NARROW_ROI_ANGLE = door_params.NARROW_ROI_ANGLE;
    DOOR_HEIGHT_MIN = door_params.DOOR_HEIGHT_MIN;
    DOOR_HEIGHT_MAX = door_params.DOOR_HEIGHT_MAX;
    
    if nargin < 3
        elevator_center = [27, 12]; % Default elevator center
    end
    if nargin < 4
        enable_debug = true;
    end
    if nargin < 5
        odometry_mode = false; % Default to map mode
    end
    
    % Use the main detection function with door_params
    door_state = detectElevatorDoorState(pointCloud, wheelchair_pose, elevator_center, odometry_mode, door_params);
    
    % Simple visualization
    if enable_debug
        % Set coordinates based on mode
        if odometry_mode
            wheelchair_pos = [0, 0]; % Wheelchair is at origin in odometry mode
            target_angle = 0; % Forward direction (angle 0) in LiDAR coordinates
            distance_to_elevator = 2.5; % Fixed distance in odometry mode
            % Calculate elevator center position from wheelchair forward direction
            elevator_center_viz = wheelchair_pos + distance_to_elevator * [cos(target_angle), sin(target_angle)];
        else
            wheelchair_pos = wheelchair_pose(1:2);
            direction_to_elevator = elevator_center - wheelchair_pos;
            distance_to_elevator = norm(direction_to_elevator);
            target_angle = atan2(direction_to_elevator(2), direction_to_elevator(1));
            elevator_center_viz = elevator_center;
        end
        
        % Calculate visualization data using same logic as detection
        cone_points = [];
        narrow_roi_points = [];
        deep_points = [];
        center_point = [];
        
        if ~isempty(pointCloud) && size(pointCloud, 2) >= 3
            
            % Filter height first using dynamic parameters
            height_filter = pointCloud(:,3) >= DOOR_HEIGHT_MIN & pointCloud(:,3) <= DOOR_HEIGHT_MAX;
            height_filtered_points = pointCloud(height_filter, :);
            
            if size(height_filtered_points, 1) > 0
                % Filter by angle (±30° cone) - coordinate system dependent
                if odometry_mode
                    % In odometry mode, points are already relative to wheelchair
                    point_angles = atan2(height_filtered_points(:,2), height_filtered_points(:,1));
                    points_relative = height_filtered_points(:,1:2);
                else
                    % In map mode, convert points to wheelchair-relative coordinates
                    points_relative = height_filtered_points(:,1:2) - wheelchair_pos;
                    point_angles = atan2(points_relative(:,2), points_relative(:,1));
                end
                
                angle_diff = angdiff(point_angles, target_angle);
                within_cone = abs(angle_diff) <= deg2rad(ANGLE_TOLERANCE);
                cone_points = height_filtered_points(within_cone, :);
                
                if size(cone_points, 1) > 0
                    % Find center point - coordinate system dependent
                    if odometry_mode
                        cone_angles = atan2(cone_points(:,2), cone_points(:,1));
                    else
                        cone_angles = atan2(cone_points(:,2) - wheelchair_pos(2), cone_points(:,1) - wheelchair_pos(1));
                    end
                    
                    angle_diffs = abs(angdiff(cone_angles, target_angle));
                    [~, center_idx] = min(angle_diffs);
                    center_point = cone_points(center_idx, :);
                    center_angle = cone_angles(center_idx);
                    
                    % Find narrow ROI points using dynamic parameter
                    narrow_roi_mask = abs(angdiff(cone_angles, center_angle)) <= deg2rad(NARROW_ROI_ANGLE);
                    narrow_roi_points = cone_points(narrow_roi_mask, :);
                    
                    % Find deep points - coordinate system dependent
                    if odometry_mode
                        cone_distances = sqrt(sum(cone_points(:,1:2).^2, 2));
                    else
                        cone_distances = sqrt(sum((cone_points(:,1:2) - wheelchair_pos).^2, 2));
                    end
                    
                    deep_threshold = distance_to_elevator + 0.3;
                    deep_mask = cone_distances > deep_threshold;
                    deep_points = cone_points(deep_mask, :);
                end
            end
        end
        pause(1)
        plotSimpleDebug(pointCloud, cone_points, narrow_roi_points, deep_points, center_point, wheelchair_pos, elevator_center_viz, door_state, odometry_mode, ANGLE_TOLERANCE, NARROW_ROI_ANGLE);
    end
end

function plotSimpleDebug(pointCloud, cone_points, narrow_roi_points, deep_points, center_point, wheelchair_pos, elevator_center, door_state, odometry_mode, angle_tolerance, narrow_roi_angle)
    % Simple debug plot with narrow ROI visualization
    persistent fig_handle;
    
    if isempty(fig_handle) || ~ishandle(fig_handle)
        mode_str = 'Map Mode';
        if nargin >= 9 && odometry_mode
            mode_str = 'Odometry Mode';
        end
        fig_handle = figure('Name', sprintf('Door Detection Debug - %s', mode_str), 'Position', [100, 100, 900, 700]);
    else
        figure(fig_handle);
        clf;
    end
    
    hold on;
    
    % 1. All point cloud in light blue
    if ~isempty(pointCloud) && size(pointCloud, 1) > 0
        scatter(pointCloud(:,1), pointCloud(:,2), 3, [0.7 0.7 1], 'filled', 'MarkerFaceAlpha', 0.3);
    end
    
    % 2. Cone points (angle ROI) in light red
    if ~isempty(cone_points) && size(cone_points, 1) > 0
        scatter(cone_points(:,1), cone_points(:,2), 15, [1 0.5 0.5], 'filled', 'MarkerFaceAlpha', 0.6);
    end
    
    % 3. Narrow ROI points (wheelchair path) in ORANGE
    if ~isempty(narrow_roi_points) && size(narrow_roi_points, 1) > 0
        scatter(narrow_roi_points(:,1), narrow_roi_points(:,2), 25, [1 0.6 0], 'filled', 'MarkerEdgeColor', 'black', 'LineWidth', 1);
    end
    
    % 4. Deep points (distance passing) in GREEN
    if ~isempty(deep_points) && size(deep_points, 1) > 0
        scatter(deep_points(:,1), deep_points(:,2), 20, 'green', 'filled', 'MarkerEdgeColor', 'green');
    end
    
    % 5. Center point (most aligned with elevator direction) in MAGENTA
    if ~isempty(center_point) && size(center_point, 1) > 0
        scatter(center_point(1), center_point(2), 100, 'magenta', 'filled', 'p', 'MarkerEdgeColor', 'black', 'LineWidth', 2);
    end
    
    % 6. Wheelchair position
    scatter(wheelchair_pos(1), wheelchair_pos(2), 200, 'blue', 'filled', '^', 'MarkerEdgeColor', 'black', 'LineWidth', 2);
    
    % 7. Elevator center
    scatter(elevator_center(1), elevator_center(2), 200, [0.8 0.4 0], 'filled', 's', 'MarkerEdgeColor', 'black', 'LineWidth', 2);
    
    % Add direction arrow from wheelchair to elevator
    arrow_length = 1.5;
    direction_vec = (elevator_center - wheelchair_pos) / norm(elevator_center - wheelchair_pos);
    arrow_end = wheelchair_pos + arrow_length * direction_vec;
    plot([wheelchair_pos(1), arrow_end(1)], [wheelchair_pos(2), arrow_end(2)], ...
         'Color', 'blue', 'LineWidth', 3, 'Marker', '>', 'MarkerSize', 8);
    
    xlabel('X (m)'); ylabel('Y (m)');
    mode_str = 'Map Mode';
    if nargin >= 9 && odometry_mode
        mode_str = 'Odometry Mode (Wheelchair @ Origin)';
    end
    title(sprintf('Door Detection: %s | %s | Narrow ROI (±%d°) Coverage Check', upper(door_state), mode_str, narrow_roi_angle));
    axis equal; grid on;
    
    % Create comprehensive legend
    legend_entries = {};
    if ~isempty(pointCloud), legend_entries{end+1} = 'All Points'; end
    if ~isempty(cone_points), legend_entries{end+1} = sprintf('±%d° Cone', angle_tolerance); end
    if ~isempty(narrow_roi_points), legend_entries{end+1} = sprintf('±%d° ROI (Critical)', narrow_roi_angle); end
    if ~isempty(deep_points), legend_entries{end+1} = 'Deep Points'; end
    if ~isempty(center_point), legend_entries{end+1} = 'Center Point'; end
    legend_entries = [legend_entries, {'Wheelchair', 'Elevator', 'Direction'}];
    
    legend(legend_entries, 'Location', 'best', 'FontSize', 10);
    
    drawnow;
end

function angle_diff = angdiff(angle1, angle2)
    % Calculate the shortest angular difference between two angles
    angle_diff = angle1 - angle2;
    angle_diff = atan2(sin(angle_diff), cos(angle_diff));
end