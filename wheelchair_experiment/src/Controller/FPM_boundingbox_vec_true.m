function [Grade] = FPM_boundingbox_vec_true(obj, x, y, th, boundingBoxes, target, param_FPM)
% FPM_boundingbox_vec_true - TRUE Vectorized Fuzzy Potential Method using oriented rectangular bounding boxes
% High-performance vectorized version with EXACT rectangular collision detection (no circle approximation)
% Processes all obstacles and path points simultaneously while maintaining rectangular accuracy
%
% Inputs:
%   obj          - wheelchair object with parameters
%   x, y, th     - current wheelchair position and orientation [1,1,K,NP] arrays
%   boundingBoxes - cell array of bounding box structures from Estimate.m
%   target       - target position [1,2,K,NP] array (unused - uses obj.th_target_w)
%   param_FPM    - FPM parameters structure
%
% Outputs:
%   Grade        - FMP grade array [1,1,K-1,NP] for all path points

    %% FPM Parameters
    eta = param_FPM.eta;            % Goal PMF ratio (min/max)
    alpha = param_FPM.alpha;        % Distance threshold for obstacle consideration
    ds = param_FPM.margin;          % Safety margin around obstacles
    obs_cost = param_FPM.obs_cost;  % Collision cost penalty

    %% Wheelchair Parameters
    Po = [x y];                     % Wheelchair position [1,2,K,NP]
    a_wheel = obj.wheel_width;      % Wheelchair width
    b_wheel = obj.wheel_len_front;  % Wheelchair length
    r_wheel = norm([a_wheel b_wheel]); % Wheelchair radius (corner distance)

    %% Goal PMF (using pre-computed target headings like capsule FPM)
    g_a = 1.0;                      % PMF maximum value for goal
    g_b = eta * g_a;                % PMF minimum value for goal
    
    % Use vectorized indexing to get target headings (same as FPM_capsule_v3_3vec.m)
    target_indices = obj.target_n(2:end,:);  % Get indices for steps 2 to K
    th_target = obj.th_target_w(reshape(target_indices, [1, 1, obj.K-1, obj.NP]));
    
    % Calculate angle difference using trimmed th
    th_trimmed_for_goal = th(:,:,2:end,:);  % [1,1,K-1,NP]
    phig = th_target - th_trimmed_for_goal;
    phaierror = atan2(sin(phig - 0), cos(phig - 0));
    grade_trgt = -((g_a - g_b)/pi) * abs(phaierror) + g_a;

    %% Convert Bounding Boxes to Vectorized Format
    if isempty(boundingBoxes)
        obsnum = 0;
        Grade = grade_trgt;
        return;
    end
    
    obsnum = length(boundingBoxes);
    
    % Get dimensions
    K_steps = size(x, 3);
    NP_paths = size(x, 4);
    
    % Pre-allocate arrays for all bounding box data [obsnum, 2, K-1, NP]
    % Only need K-1 steps for obstacle processing (skip first step)
    bbox_centers = zeros(obsnum, 2, K_steps-1, NP_paths);  % Center positions
    bbox_dims = zeros(obsnum, 2, K_steps-1, NP_paths);     % [length, width]
    bbox_orients = zeros(obsnum, 1, K_steps-1, NP_paths);  % Orientations
    
    % Extract bounding box parameters into vectorized arrays
    for i = 1:obsnum
        bbox = boundingBoxes{i};
        bbox_centers(i, :, :, :) = repmat(reshape(bbox.center(1:2), [1, 2, 1, 1]), [1, 1, K_steps-1, NP_paths]);
        bbox_dims(i, :, :, :) = repmat(reshape(bbox.dimensions(1:2), [1, 2, 1, 1]), [1, 1, K_steps-1, NP_paths]);
        bbox_orients(i, 1, :, :) = repmat(bbox.orientation, [1, 1, K_steps-1, NP_paths]);
    end

    %% TRUE Vectorized Rectangular Obstacle PMF Processing 
    if obsnum > 0
        % Initialize grade array - ensure dimensions match input arrays
        grade_obs = ones(obsnum, 1, K_steps-1, NP_paths);  % Skip first step to match K-1
        
        % Safety margin
        effective_margin = ds + r_wheel;
        
        % Use Po from step 2 onwards to match bbox_centers dimensions
        Po_trimmed = Po(:, :, 2:end, :);  % [1, 2, K-1, NP]
        
        % Use trimmed th to match dimensions [1,1,K-1,NP]
        th_trimmed = th(:, :, 2:end, :);
        
        % Calculate TRUE vectorized distance to rectangles (NO circle approximation)
        [min_dist_to_rects, rect_corners_wf] = vectorizedRectangleDistance(...
            bbox_centers, bbox_dims, bbox_orients, Po_trimmed, th_trimmed);
        
        % Calculate TRUE vectorized angular range from actual rectangle corners
        [phi_min, phi_max] = vectorizedAngularRangeFromCorners(rect_corners_wf);
        
        % Check if obstacle blocks forward direction (0 radians)
        % Handle angle wrapping for proper intersection detection
        blocks_forward = (phi_min <= 0 & phi_max >= 0) | ...
                        (phi_min > phi_max & (phi_min <= 0 | phi_max >= 0));
        
        % Distance to bounding box centers (for alpha threshold check)
        center_distances = vecnorm(bbox_centers - Po_trimmed, 2, 2);  % [obsnum, 1, K-1, NP]
        
        % Ensure dimensions match for logical operations
        % blocks_forward is [obsnum, 1, K-1, NP], center_distances is [obsnum, 1, K-1, NP]
        center_check = center_distances < alpha;  % [obsnum, 1, K-1, NP]
        
        % Calculate obstacle grades using TRUE rectangular distances
        idx_relevant = blocks_forward & center_check;  % Obstacles affecting forward motion
        
        % Vectorized grade calculation using exact rectangular distances
        safe_distance = min_dist_to_rects - effective_margin;
        
        % Exponential decay for safe distances
        grade_safe = 1 - exp(-max(0, safe_distance) / 1.0);
        
        % Collision penalty for unsafe distances
        grade_collision = exp(min(0, safe_distance) / 1.0) - obs_cost;
        
        % Combine safe and collision grades
        grade_combined = grade_safe .* (safe_distance >= 0) + grade_collision .* (safe_distance < 0);
        
        % Apply grades only to relevant obstacles
        grade_obs = grade_combined .* idx_relevant + ~idx_relevant;
        
        % Ensure grades are within valid range [0, 1]
        grade_obs = max(0, min(1, grade_obs));
        
    else
        % No obstacles - use dimensions from input
        grade_obs = ones(1, 1, K_steps-1, NP_paths);
    end

    %% Final Grade Calculation
    % Both grade_trgt and grade_obs are now [1,1,K-1,NP]
    grade_obs_min = min(grade_obs, [], 1);         % [1,1,K-1,NP]
    Grade = min(grade_trgt, grade_obs_min);        % Both are [1,1,K-1,NP]
    
    %% Debug Visualization
    persistent debug_enabled debug_counter;
    if isempty(debug_enabled)
        debug_enabled = false;  % Set to true to enable debug visualization
        debug_counter = 0;
    end
    
    if debug_enabled
        debug_counter = debug_counter + 1;
        if mod(debug_counter, 10) == 1  % Plot every 10th call to avoid too many plots
            visualizeFPMDebug(obj, Po, th, boundingBoxes, Grade, min_dist_to_rects, ...
                             bbox_centers, bbox_dims, bbox_orients, Po_trimmed, th_trimmed);
        end
    end
end

%% TRUE Vectorized Rectangle Distance Function
function [min_dist_vec, rect_corners_wf] = vectorizedRectangleDistance(bbox_centers, bbox_dims, bbox_orients, wheelchair_pos, wheelchair_th)
    % Calculate TRUE minimum distance from wheelchair to ALL rectangles simultaneously
    % NO circle approximation - uses exact point-to-rectangle geometry
    %
    % Inputs:
    %   bbox_centers - [obsnum, 2, K-1, NP] rectangle centers
    %   bbox_dims    - [obsnum, 2, K-1, NP] rectangle [length, width]
    %   bbox_orients - [obsnum, 1, K-1, NP] rectangle orientations
    %   wheelchair_pos - [1, 2, K-1, NP] wheelchair positions
    %   wheelchair_th  - [1, 1, K-1, NP] wheelchair headings
    %
    % Outputs:
    %   min_dist_vec    - [obsnum, 1, K-1, NP] minimum distances to rectangles
    %   rect_corners_wf - [obsnum, 4, 2, K-1, NP] rectangle corners in wheelchair frame
    
    % Get array dimensions
    [obsnum, ~, K_minus_1, NP] = size(bbox_centers);
    
    % Transform wheelchair position relative to each rectangle center
    % wheelchair_pos is [1, 2, K-1, NP], bbox_centers is [obsnum, 2, K-1, NP]
    rel_pos = wheelchair_pos - bbox_centers;  % [obsnum, 2, K-1, NP]
    
    % Vectorized rotation transformation to rectangle local frames
    % Each rectangle has its own orientation
    cos_theta = cos(-bbox_orients);  % [obsnum, 1, K-1, NP] 
    sin_theta = sin(-bbox_orients);  % [obsnum, 1, K-1, NP]
    
    % Transform wheelchair position to each rectangle's local coordinate system
    local_x = rel_pos(:,1,:,:) .* cos_theta - rel_pos(:,2,:,:) .* sin_theta; % [obsnum, 1, K-1, NP]
    local_y = rel_pos(:,1,:,:) .* sin_theta + rel_pos(:,2,:,:) .* cos_theta; % [obsnum, 1, K-1, NP]
    
    % Vectorized clamping to rectangle bounds
    half_length = bbox_dims(:,1,:,:) / 2;  % [obsnum, 1, K-1, NP]
    half_width = bbox_dims(:,2,:,:) / 2;   % [obsnum, 1, K-1, NP]
    
    % Clamp wheelchair position to rectangle boundaries
    clamped_x = max(-half_length, min(half_length, local_x));  % [obsnum, 1, K-1, NP]
    clamped_y = max(-half_width, min(half_width, local_y));    % [obsnum, 1, K-1, NP]
    
    % Calculate minimum distance (Euclidean distance from wheelchair to clamped point)
    dist_x = local_x - clamped_x;  % [obsnum, 1, K-1, NP]
    dist_y = local_y - clamped_y;  % [obsnum, 1, K-1, NP]
    min_dist_vec = sqrt(dist_x.^2 + dist_y.^2);  % [obsnum, 1, K-1, NP]
    
    % Handle inside-rectangle case (distance = 0 when wheelchair is inside rectangle)
    inside_rect = (abs(local_x) <= half_length) & (abs(local_y) <= half_width);
    min_dist_vec = min_dist_vec .* ~inside_rect;  % Set distance to 0 if inside
    
    % Calculate rectangle corners in wheelchair frame for angular range calculation
    % Rectangle corners in local frame: [±half_length, ±half_width]
    corners_local = zeros(4, 2);
    corners_local(1, :) = [-1, -1];  % Bottom-left
    corners_local(2, :) = [ 1, -1];  % Bottom-right  
    corners_local(3, :) = [ 1,  1];  % Top-right
    corners_local(4, :) = [-1,  1];  % Top-left
    
    % Initialize corner array: [obsnum, 4, 2, K-1, NP]
    rect_corners_wf = zeros(obsnum, 4, 2, K_minus_1, NP);
    
    % Transform each corner to wheelchair frame
    for corner_idx = 1:4
        % Scale by rectangle dimensions
        corner_x_local = corners_local(corner_idx, 1) .* half_length;  % [obsnum, 1, K-1, NP]
        corner_y_local = corners_local(corner_idx, 2) .* half_width;   % [obsnum, 1, K-1, NP]
        
        % Transform from rectangle local frame back to wheelchair frame
        % First: rotate back to world frame
        corner_x_world = corner_x_local .* cos(-bbox_orients) + corner_y_local .* sin(-bbox_orients);
        corner_y_world = -corner_x_local .* sin(-bbox_orients) + corner_y_local .* cos(-bbox_orients);
        
        % Then: translate by rectangle center and subtract wheelchair position
        corner_x_global = corner_x_world + bbox_centers(:,1,:,:) - wheelchair_pos(:,1,:,:);
        corner_y_global = corner_y_world + bbox_centers(:,2,:,:) - wheelchair_pos(:,2,:,:);
        
        % Finally: rotate to wheelchair frame
        cos_wh = cos(-wheelchair_th);  % [1, 1, K-1, NP]
        sin_wh = sin(-wheelchair_th);  % [1, 1, K-1, NP]
        
        corner_x_wf = corner_x_global .* cos_wh - corner_y_global .* sin_wh;
        corner_y_wf = corner_x_global .* sin_wh + corner_y_global .* cos_wh;
        
        % Store in corners array
        rect_corners_wf(:, corner_idx, 1, :, :) = corner_x_wf;  % X coordinates
        rect_corners_wf(:, corner_idx, 2, :, :) = corner_y_wf;  % Y coordinates
    end
end

%% TRUE Vectorized Angular Range from Rectangle Corners
function [phi_min, phi_max] = vectorizedAngularRangeFromCorners(rect_corners_wf)
    % Calculate angular range occupied by rectangles using ACTUAL corner points
    % NO circular approximation - uses exact rectangular geometry
    %
    % Input:
    %   rect_corners_wf - [obsnum, 4, 2, K-1, NP] rectangle corners in wheelchair frame
    %
    % Outputs:
    %   phi_min, phi_max - [obsnum, 1, K-1, NP] angular ranges for each rectangle
    
    % Get array dimensions
    [obsnum, num_corners, coord_dims, K_minus_1, NP] = size(rect_corners_wf);
    
    % Calculate angles to all 4 corners for each rectangle
    corner_x = rect_corners_wf(:, :, 1, :, :);  % X coordinates of all corners
    corner_y = rect_corners_wf(:, :, 2, :, :);  % Y coordinates of all corners
    
    % Handle squeezed dimensions
    corner_x = reshape(corner_x, obsnum, num_corners, K_minus_1, NP);
    corner_y = reshape(corner_y, obsnum, num_corners, K_minus_1, NP);
    
    % Vectorized atan2 for all corners simultaneously
    corner_angles = atan2(corner_y, corner_x);  % [obsnum, 4, K-1, NP]
    
    % Find angular span for each rectangle
    phi_min = zeros(obsnum, 1, K_minus_1, NP);
    phi_max = zeros(obsnum, 1, K_minus_1, NP);
    
    for obs_idx = 1:obsnum
        for k_idx = 1:K_minus_1
            for np_idx = 1:NP
                % Extract 4 corner angles for this obstacle/timestep/path
                if K_minus_1 == 1 && NP == 1
                    angles = squeeze(corner_angles(obs_idx, :));  % [4]
                elseif NP == 1
                    angles = squeeze(corner_angles(obs_idx, :, k_idx));  % [4]
                elseif K_minus_1 == 1
                    angles = squeeze(corner_angles(obs_idx, :, np_idx));  % [4]
                else
                    angles = squeeze(corner_angles(obs_idx, :, k_idx, np_idx));  % [4]
                end
                
                angles = angles(:);  % Ensure column vector [4,1]
                
                % Sort angles to find angular span
                angles_sorted = sort(angles);
                
                % Find the largest gap between consecutive angles
                gaps = diff([angles_sorted(:); angles_sorted(1) + 2*pi]);
                [max_gap, max_gap_idx] = max(gaps);
                
                if max_gap > pi
                    % Large gap exists - span everything except the gap
                    after_gap_idx = mod(max_gap_idx, 4) + 1;
                    if after_gap_idx > 4, after_gap_idx = 1; end
                    
                    phi_min(obs_idx, 1, k_idx, np_idx) = angles_sorted(after_gap_idx);
                    phi_max(obs_idx, 1, k_idx, np_idx) = angles_sorted(max_gap_idx);
                else
                    % No large gap - direct span from min to max
                    phi_min(obs_idx, 1, k_idx, np_idx) = angles_sorted(1);
                    phi_max(obs_idx, 1, k_idx, np_idx) = angles_sorted(end);
                end
                
                % Normalize to [-pi, pi] range
                phi_min(obs_idx, 1, k_idx, np_idx) = atan2(sin(phi_min(obs_idx, 1, k_idx, np_idx)), cos(phi_min(obs_idx, 1, k_idx, np_idx)));
                phi_max(obs_idx, 1, k_idx, np_idx) = atan2(sin(phi_max(obs_idx, 1, k_idx, np_idx)), cos(phi_max(obs_idx, 1, k_idx, np_idx)));
                
                % Handle wraparound case
                if phi_min(obs_idx, 1, k_idx, np_idx) > phi_max(obs_idx, 1, k_idx, np_idx)
                    phi_max(obs_idx, 1, k_idx, np_idx) = phi_max(obs_idx, 1, k_idx, np_idx) + 2*pi;
                end
            end
        end
    end
end

%% FMP Debug Visualization Function
function visualizeFPMDebug(obj, Po, th, boundingBoxes, Grade, min_dist_to_rects, ...
                          bbox_centers, bbox_dims, bbox_orients, Po_trimmed, th_trimmed)
    % Comprehensive FPM debug visualization
    try
        % Gather data from GPU if needed
        Po_cpu = gather(Po);
        th_cpu = gather(th);
        Grade_cpu = gather(Grade);
        
        % Calculate path costs (lower grade = higher cost)
        path_costs = squeeze(sum(1 - Grade_cpu, 3));  % Sum cost over time steps [1, NP]
        
        % Find best path (lowest cost)
        [~, best_path_idx] = min(path_costs);
        
        % Create figure
        figure(888);
        clf;
        hold on;
        axis equal;
        grid on;
        
        %% 1. Plot All Rectangle Obstacles (Background)
        fprintf('Plotting %d obstacles...\n', length(boundingBoxes));
        
        for i = 1:length(boundingBoxes)
            bbox = boundingBoxes{i};
            center = bbox.center(1:2);
            dims = bbox.dimensions(1:2);
            orient = bbox.orientation;
            
            % Plot rectangle obstacle
            rect_corners = getRectangleCorners(center, dims, orient);
            plot([rect_corners(:,1); rect_corners(1,1)], [rect_corners(:,2); rect_corners(1,2)], ...
                 'r-', 'LineWidth', 2, 'HandleVisibility', 'off');
            fill(rect_corners(:,1), rect_corners(:,2), [1, 0.8, 0.8], 'FaceAlpha', 0.3, ...
                 'EdgeColor', 'r', 'LineWidth', 2, 'HandleVisibility', 'off');
            
            % Label obstacle
            text(center(1), center(2), sprintf('Obs%d', i), 'HorizontalAlignment', 'center', ...
                 'FontSize', 10, 'FontWeight', 'bold', 'Color', [0.8, 0, 0]);
        end
        
        %% 2. Plot Waypoints (Background)
        try
            if isfield(obj, 'waypoint') && ~isempty(obj.waypoint)
                waypoints_cpu = gather(obj.waypoint);
                plot(waypoints_cpu(:,1), waypoints_cpu(:,2), 'b*-', 'MarkerSize', 10, ...
                     'LineWidth', 2, 'DisplayName', 'Waypoints');
                
                % Label waypoints
                for wp_idx = 1:min(10, size(waypoints_cpu, 1))  % Show first 10 waypoint labels
                    text(waypoints_cpu(wp_idx,1), waypoints_cpu(wp_idx,2), sprintf('W%d', wp_idx), ...
                         'VerticalAlignment', 'bottom', 'FontSize', 8, 'Color', 'b', 'FontWeight', 'bold');
                end
            end
        catch
            % Waypoint plotting failed - continue without waypoints
        end
        
        %% 3. Plot All Paths with Color Gradient (Mid-layer)
        fprintf('Plotting %d paths...\n', size(Po_cpu, 4));
        
        % Normalize costs for color mapping
        min_cost = min(path_costs);
        max_cost = max(path_costs);
        cost_range = max_cost - min_cost;
        
        if cost_range > 0
            normalized_costs = (path_costs - min_cost) / cost_range;  % [0, 1]
        else
            normalized_costs = zeros(size(path_costs));  % All costs are equal
        end
        
        % Plot candidate paths first (other paths - background)
        for path_idx = 1:size(Po_cpu, 4)
            if mod(path_idx, 50) == 1 && path_idx ~= best_path_idx  % Show every 50th path except best
                path_x = squeeze(Po_cpu(1, 1, :, path_idx));
                path_y = squeeze(Po_cpu(1, 2, :, path_idx));
                
                % Color: Red (1,0,0) = worst, Blue (0,0,1) = best
                cost_norm = normalized_costs(path_idx);
                color = [cost_norm, 0, 1-cost_norm];  % Red to Blue gradient
                
                % Other paths - thin colored lines (no legend)
                plot(path_x, path_y, 'Color', [color, 0.6], 'LineWidth', 1, 'HandleVisibility', 'off');
            end
        end
        
        %% 4. Plot Best Path (2nd Front - Above other paths)
        % Plot best path - thick green line on top of other paths
        if ~isempty(best_path_idx)
            path_x = squeeze(Po_cpu(1, 1, :, best_path_idx));
            path_y = squeeze(Po_cpu(1, 2, :, best_path_idx));
            plot(path_x, path_y, 'g-', 'LineWidth', 4, 'DisplayName', 'Best Path');
        end
        
        %% 5. Plot Clamped Points for Best Path
        if exist('min_dist_to_rects', 'var') && ~isempty(min_dist_to_rects)
            min_dist_cpu = gather(min_dist_to_rects);
            bbox_centers_cpu = gather(bbox_centers);
            bbox_dims_cpu = gather(bbox_dims);
            bbox_orients_cpu = gather(bbox_orients);
            Po_trimmed_cpu = gather(Po_trimmed);
            
            % Calculate clamped points for best path and each obstacle
            for obs_idx = 1:length(boundingBoxes)
                for k_idx = 1:min(5, size(Po_trimmed_cpu, 3))  % Show first 5 time steps
                    % Get wheelchair position for this timestep
                    wh_pos = squeeze(Po_trimmed_cpu(1, :, k_idx, best_path_idx));  % [2,1]
                    
                    % Get obstacle parameters
                    obs_center = squeeze(bbox_centers_cpu(obs_idx, :, k_idx, best_path_idx));
                    obs_dims = squeeze(bbox_dims_cpu(obs_idx, :, k_idx, best_path_idx));
                    obs_orient = bbox_orients_cpu(obs_idx, 1, k_idx, best_path_idx);
                    
                    % Calculate clamped point
                    clamped_point = calculateClampedPoint(wh_pos, obs_center, obs_dims, obs_orient);
                    
                    % Plot clamped point
                    if obs_idx == 1 && k_idx == 1  % Only show legend for first point
                        plot(clamped_point(1), clamped_point(2), 'mo', 'MarkerSize', 8, ...
                             'MarkerFaceColor', 'm', 'DisplayName', 'Clamped Points');
                    else
                        plot(clamped_point(1), clamped_point(2), 'mo', 'MarkerSize', 8, ...
                             'MarkerFaceColor', 'm', 'HandleVisibility', 'off');
                    end
                    
                    % Draw line from wheelchair to clamped point
                    plot([wh_pos(1), clamped_point(1)], [wh_pos(2), clamped_point(2)], ...
                         'm--', 'LineWidth', 1.5, 'HandleVisibility', 'off');
                    
                    % Display distance
                    dist_val = min_dist_cpu(obs_idx, 1, k_idx, best_path_idx);
                    mid_x = (wh_pos(1) + clamped_point(1)) / 2;
                    mid_y = (wh_pos(2) + clamped_point(2)) / 2;
                    text(mid_x, mid_y, sprintf('%.2fm', dist_val), 'FontSize', 8, ...
                         'Color', 'm', 'FontWeight', 'bold');
                end
            end
        end
        
        %% 6. Plot Current Wheelchair Position and Orientation (MOST FRONT - Top layer)
        current_x = Po_cpu(1, 1, 1, 1);
        current_y = Po_cpu(1, 2, 1, 1);
        current_yaw = th_cpu(1, 1, 1, 1);
        
        % Wheelchair position - plot on top of everything
        plot(current_x, current_y, 'ko', 'MarkerSize', 14, 'MarkerFaceColor', 'y', ...
             'DisplayName', 'Wheelchair');
        
        % Wheelchair orientation arrow - thick and visible
        arrow_len = 0.8;
        quiver(current_x, current_y, arrow_len*cos(current_yaw), arrow_len*sin(current_yaw), ...
               'k', 'LineWidth', 4, 'MaxHeadSize', 0.5, 'HandleVisibility', 'off');
        
        % Wheelchair dimensions visualization - thick outline
        wheel_corners = getWheelchairCorners(current_x, current_y, current_yaw, obj);
        plot([wheel_corners(:,1); wheel_corners(1,1)], [wheel_corners(:,2); wheel_corners(1,2)], ...
             'k-', 'LineWidth', 3, 'HandleVisibility', 'off');
        
        %% 7. Formatting and Labels
        xlabel('X (m)');
        ylabel('Y (m)');
        title(sprintf('FPM Debug: Best Path Cost=%.2f, Total Paths=%d, Obstacles=%d', ...
              min(path_costs), length(path_costs), length(boundingBoxes)));
        
        % Legend
        legend('Location', 'best');
        
        % Set axis limits around action
        all_x = Po_cpu(1, 1, :, :);
        all_y = Po_cpu(1, 2, :, :);
        
        % Add bounding box centers to axis calculation
        for i = 1:length(boundingBoxes)
            bbox = boundingBoxes{i};
            all_x = [all_x(:); bbox.center(1)];
            all_y = [all_y(:); bbox.center(2)];
        end
        margin = 3;
        xlim([min(all_x(:)) - margin, max(all_x(:)) + margin]);
        ylim([min(all_y(:)) - margin, max(all_y(:)) + margin]);
        
        % Status text
        status_str = sprintf(['FPM Status:\nPaths: %d\nObstacles: %d\nBest Cost: %.3f\n' ...
                             'Worst Cost: %.3f\nCost Range: %.3f'], ...
                            length(path_costs), length(boundingBoxes), min_cost, max_cost, cost_range);
        text(0.02, 0.98, status_str, 'Units', 'normalized', 'VerticalAlignment', 'top', ...
             'FontSize', 9, 'BackgroundColor', [1 1 1 0.8], 'EdgeColor', 'k');
        
        drawnow;
        fprintf('FPM Debug plot updated (Best path: %d, Cost: %.3f)\n', best_path_idx, min_cost);
        
    catch ME
        fprintf('FPM Debug visualization failed: %s\n', ME.message);
    end
end

%% Helper Functions
function corners = getRectangleCorners(center, dimensions, orientation)
    % Calculate corners of oriented rectangle
    half_len = dimensions(1) / 2;
    half_wid = dimensions(2) / 2;
    
    % Local corners
    local = [-half_len, -half_wid; half_len, -half_wid; half_len, half_wid; -half_len, half_wid];
    
    % Rotation matrix
    R = [cos(orientation) -sin(orientation); sin(orientation) cos(orientation)];
    
    % Transform to global
    corners = (R * local')' + center;
end

function corners = getWheelchairCorners(x, y, yaw, obj)
    % Calculate wheelchair corner positions
    half_width = obj.wheel_width / 2;
    half_front = obj.wheel_len_front / 2;
    half_rear = half_front;  % Assume symmetric for visualization
    
    % Local corners (front-right, front-left, rear-left, rear-right)
    local = [half_front, half_width; half_front, -half_width; -half_rear, -half_width; -half_rear, half_width];
    
    % Rotation matrix
    R = [cos(yaw) -sin(yaw); sin(yaw) cos(yaw)];
    
    % Transform to global
    corners = (R * local')' + [x, y];
end

function clamped_point = calculateClampedPoint(wheelchair_pos, obstacle_center, obstacle_dims, obstacle_orient)
    % Calculate the clamped point (closest point on rectangle to wheelchair)
    
    % Transform wheelchair to obstacle local frame
    rel_pos = wheelchair_pos - obstacle_center;
    cos_theta = cos(-obstacle_orient);
    sin_theta = sin(-obstacle_orient);
    
    local_x = rel_pos(1) * cos_theta - rel_pos(2) * sin_theta;
    local_y = rel_pos(1) * sin_theta + rel_pos(2) * cos_theta;
    
    % Clamp to rectangle bounds
    half_length = obstacle_dims(1) / 2;
    half_width = obstacle_dims(2) / 2;
    
    clamped_x = max(-half_length, min(half_length, local_x));
    clamped_y = max(-half_width, min(half_width, local_y));
    
    % Transform back to global frame
    global_x = clamped_x * cos(-obstacle_orient) - clamped_y * sin(-obstacle_orient);
    global_y = clamped_x * sin(-obstacle_orient) + clamped_y * cos(-obstacle_orient);
    
    clamped_point = [global_x, global_y] + obstacle_center;
end