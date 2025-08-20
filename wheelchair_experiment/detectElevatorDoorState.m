function door_state = detectElevatorDoorState(pointCloud, wheelchair_pose, elevator_center)
    % Detect elevator door state using 3D point cloud data
    % 
    % Inputs:
    %   pointCloud - 3D point cloud data (Nx3 matrix: [x, y, z])
    %   wheelchair_pose - current wheelchair position and orientation [x, y, yaw]
    %   elevator_center - elevator center position [x, y] (default: [27, 12])
    %
    % Output:
    %   door_state - 'open', 'closed', or 'unknown'
    
    if nargin < 3
        elevator_center = [27, 12]; % Default elevator center
    end
    
    % Parameters for door detection
    DOOR_WIDTH = 1.2;           % Expected door width (meters)
    DOOR_HEIGHT = 2.0;          % Expected door height (meters)
    DOOR_THICKNESS = 0.1;       % Door thickness tolerance
    DETECTION_RANGE = 3.0;      % Maximum detection range (meters)
    MIN_POINTS_THRESHOLD = 10;  % Minimum points to detect door
    OPENING_THRESHOLD = 0.8;    % Threshold to consider door "open" (80% of width)
    
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
        
        % Calculate door position relative to elevator center
        % Assume door is on the front face of elevator (facing wheelchair)
        door_direction = wheelchair_pos - elevator_center;
        door_direction = door_direction / norm(door_direction);
        door_center = elevator_center + door_direction * 0.5; % Door is 0.5m from center
        
        fprintf('Door Detection: Wheelchair at [%.2f, %.2f], Door center at [%.2f, %.2f]\n', ...
                wheelchair_pos(1), wheelchair_pos(2), door_center(1), door_center(2));
        
        % Filter points within detection range and expected door area
        distance_to_door = sqrt(sum((pointCloud(:,1:2) - door_center).^2, 2));
        in_range = distance_to_door <= DETECTION_RANGE;
        
        % Filter points by height (door height range)
        height_filter = pointCloud(:,3) >= 0.1 & pointCloud(:,3) <= DOOR_HEIGHT;
        
        % Combine filters
        door_region_points = pointCloud(in_range & height_filter, :);
        
        if size(door_region_points, 1) < MIN_POINTS_THRESHOLD
            door_state = 'unknown';
            fprintf('Door Detection: Insufficient points (%d) in door region\n', size(door_region_points, 1));
            return;
        end
        
        fprintf('Door Detection: Found %d points in door region\n', size(door_region_points, 1));
        
        % Create door frame reference
        % Rotate coordinate system to align with door orientation
        rotation_angle = atan2(door_direction(2), door_direction(1));
        cos_theta = cos(rotation_angle);
        sin_theta = sin(rotation_angle);
        rotation_matrix = [cos_theta, -sin_theta; sin_theta, cos_theta];
        
        % Transform points to door-centered coordinate system
        centered_points = door_region_points(:,1:2) - door_center;
        rotated_points = centered_points * rotation_matrix';
        
        % Define door frame boundaries in rotated coordinate system
        % X-axis: perpendicular to door (depth)
        % Y-axis: along door width
        door_depth_range = [-DOOR_THICKNESS, DOOR_THICKNESS];
        door_width_range = [-DOOR_WIDTH/2, DOOR_WIDTH/2];
        
        % Filter points that are within door frame
        depth_filter = rotated_points(:,1) >= door_depth_range(1) & rotated_points(:,1) <= door_depth_range(2);
        width_filter = rotated_points(:,2) >= door_width_range(1) & rotated_points(:,2) <= door_width_range(2);
        door_frame_points = rotated_points(depth_filter & width_filter, :);
        
        if size(door_frame_points, 1) < MIN_POINTS_THRESHOLD/2
            door_state = 'open';
            fprintf('Door Detection: Very few points in door frame - likely OPEN\n');
            return;
        end
        
        % Analyze distribution of points across door width
        % Divide door width into segments and count points
        num_segments = 10;
        segment_width = DOOR_WIDTH / num_segments;
        segment_counts = zeros(num_segments, 1);
        
        for i = 1:num_segments
            segment_start = door_width_range(1) + (i-1) * segment_width;
            segment_end = segment_start + segment_width;
            segment_points = door_frame_points(:,2) >= segment_start & door_frame_points(:,2) < segment_end;
            segment_counts(i) = sum(segment_points);
        end
        
        % Calculate metrics for door state detection
        total_points_in_frame = sum(segment_counts);
        occupied_segments = sum(segment_counts > 1); % Segments with significant points
        occupancy_ratio = occupied_segments / num_segments;
        
        % Detect large gaps (indicating open door)
        max_consecutive_empty = 0;
        current_empty_streak = 0;
        for i = 1:num_segments
            if segment_counts(i) <= 1 % Consider <= 1 as empty
                current_empty_streak = current_empty_streak + 1;
                max_consecutive_empty = max(max_consecutive_empty, current_empty_streak);
            else
                current_empty_streak = 0;
            end
        end
        
        gap_ratio = max_consecutive_empty / num_segments;
        
        fprintf('Door Detection Analysis:\n');
        fprintf('  - Total points in door frame: %d\n', total_points_in_frame);
        fprintf('  - Occupied segments: %d/%d (%.1f%%)\n', occupied_segments, num_segments, occupancy_ratio*100);
        fprintf('  - Largest gap: %d segments (%.1f%% of width)\n', max_consecutive_empty, gap_ratio*100);
        
        % Decision logic
        if gap_ratio >= OPENING_THRESHOLD
            door_state = 'open';
            fprintf('Door Detection Result: OPEN (large gap detected)\n');
        elseif occupancy_ratio >= 0.7
            door_state = 'closed';
            fprintf('Door Detection Result: CLOSED (high occupancy)\n');
        elseif occupancy_ratio <= 0.3
            door_state = 'open';
            fprintf('Door Detection Result: OPEN (low occupancy)\n');
        else
            door_state = 'unknown';
            fprintf('Door Detection Result: UNKNOWN (ambiguous data)\n');
        end
        
    catch ME
        door_state = 'unknown';
        fprintf('Door Detection Error: %s\n', ME.message);
    end
end