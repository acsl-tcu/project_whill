function [pw,remove_sample] = EvaluationPath_vec_gpu(obj,px,pu,preobs,param_FPM,Grid_Matrix,boundingBoxes,varargin)
%�@EVALUATIONPATH ���̊֐��̊T�v�������ɋL�q
    
    % Parse optional map object for world coordinate visualization
    mapObject = [];
    if nargin > 7 && ~isempty(varargin{1})
        mapObject = varargin{1};
    end
    
    obj.K= gpuArray(obj.K);
    obj.NP= gpuArray(obj.NP);
    obj.target_n= gpuArray(obj.target_n);
    obj.ltheta= gpuArray(obj.ltheta);
    obj.wall_penalty1= gpuArray(obj.wall_penalty1);
    px= gpuArray(px);
    pu= gpuArray(pu);
    preobs= gpuArray(preobs);

    %% �ڐG����̂��߂̓d���Ԉ֎q�̃|�C���g���v�Z
    % points = [ -obj.wheel_len_rear  obj.wheel_width
    %            obj.wheel_len_front  obj.wheel_width
    %            -obj.wheel_len_rear -obj.wheel_width
    %            obj.wheel_len_front -obj.wheel_width];
    % px(���)��3*1*(�z���C�]����)*(�T���v����)�ɕϊ�
    px2 =reshape(px,3,1,obj.K,obj.NP);
    % ��]�s��
    roll =[cos(px2(3,:,:,:)) -sin(px2(3,:,:,:));sin(px2(3,:,:,:)) cos(px2(3,:,:,:))];
    % �ԗ��̊e�_�̍��W���v�Z
    vehicle_Points = pagetranspose(pagemtimes(roll,obj.points')+px2(1:2,:,:,:));
    %% �ǖʐ���y�ѕǖʃR�X�g�̌v�Z
    % xy���W�n����O���b�h���W�n�֕ϊ�
    state = vehicle_Points-[obj.Grid_Xlim(1),obj.Grid_Ylim(1)];
    Grid_Idx = [obj.Grid_Size(1) 0]+[-1 1].*floor(state(:,[2,1],:,:)./obj.Cell_Size)+[0 1];
    % �͈͊O�̏���(�ύX�K�{�F�O���b�h�͈͊O�ł���ꍇ,1�ԉE���̃C���f�b�N�X�ƂȂ�)
    flag_out = any(Grid_Idx<[0 0] | Grid_Idx>[obj.Grid_Size(1) obj.Grid_Size(2)],2);
    Grid_Idx = ~flag_out.*Grid_Idx + flag_out.*obj.Grid_Size;
    % sub2ind�Ő��`�C���f�b�N�X�ɕϊ�
    Grid_Idx_linear = sub2ind(obj.Grid_Size, (Grid_Idx(:, 1,:,:)), Grid_Idx(:, 2,:,:));
    % �e�_�ł̃O���b�h�}�b�v�̒l���擾���ő�l���Ƃ�
    Grid_values = max(Grid_Matrix(Grid_Idx_linear));
    %% �ǖʐ���
    remove_sample = squeeze(max(Grid_values,[],3)>=0.98);
    %% �ǖʃR�X�g
    WALLcost = pagetranspose(squeeze(sum(Grid_values,3))*obj.wall_penalty1);
    %% FPM cost - Now using Bounding Box FPM instead of Capsule FPM
    if nargin > 6 && ~isempty(boundingBoxes)&& false
        % Use bounding box FPM for better rectangular obstacle representation
        FPMcost = calculateBoundingBoxFPMCost(obj, px2, boundingBoxes, param_FPM);
    else
        % Fallback to capsule FPM for backward compatibility
        preobs2=pagetranspose(preobs);
        [grade] = FPM_capsule_v3_3vec(obj,px2(1,:,2:obj.K,:),px2(2,:,2:obj.K,:),px2(3,:,2:obj.K,:),preobs2(:,:,1:obj.K-1),param_FPM);
        FPMcost = reshape((obj.K-1) - sum(grade,3) , 1 , []);
    end
    
    %% Legacy Bounding Box Cost (now integrated into FPM above)
    % BBcost = zeros(1, obj.NP, 'gpuArray');  % Removed - cost integrated into FPMcost

    %% Velocity cost
    v_max= 0.55;
    v_min=-0.25;
    v_cost=5000;
    Vcost = reshape(((pu(1,1,:)-v_max)*v_cost).*(pu(1,1,:) > v_max)+((pu(1,1,:)-v_min)*-v_cost).*(pu(1,1,:) < v_min),1,[]);
	
    %% Input cost
    % Vref = reshape(obj.V_ref(obj.target_n(1:obj.K-1,:)), 1, obj.K-1, obj.NP);       % ���ꂼ��̃|�C���g���ƂɖڕW���x������
    Vref =obj.V_ref(obj.target_n(1,1));     % ���ׂē����ڕW���x
    Inputcost = reshape(sum(pu(2,1:end-1,:).^2)*obj.R(2) +  sum((pu(1,1:end-1,:) - Vref).^2)*obj.R(1),[1,obj.NP]);
	
    %% Distance cost
    Q = 0.15;
    w0 = gpuArray(reshape(obj.waypoint(obj.target_n-1,:)',1,2,obj.K,obj.NP));
    w1 = gpuArray(reshape(obj.waypoint(obj.target_n  ,:)',1,2,obj.K,obj.NP));
    state = gpuArray(pagetranspose(px2(1:2,:,:,:)));
    d_target = get_distance(w0,w1,state);
    Dcost = reshape(sum(d_target,3)*Q,1,[]);
    %% Cost SUM
    pw = FPMcost + Inputcost + Vcost + WALLcost + Dcost;  % BBcost removed - now integrated into FPMcost
    % pw = FPMcost + Inputcost + Vcost + Dcost;
    % pw = FPMcost + Inputcost + Vcost + WALLcost;

    %% Debug visualization (enabled by persistent flag)
    persistent debug_plot_enabled plot_counter;
    if isempty(debug_plot_enabled)
        debug_plot_enabled = false; % Set to true to enable plotting
        plot_counter = 0;
    end
    
    if debug_plot_enabled
        plot_counter = plot_counter + 1;
        if mod(plot_counter, 5) == 1 % Plot every 5th call to avoid too many plots
            plotMPCDebug(obj, px2, pw, boundingBoxes, remove_sample, Grid_Matrix, mapObject);
        end
    end

    %%
    pw=gather(pw);
    remove_sample=gather(remove_sample);

end

function BBcost = calculateBoundingBoxCost(obj, px2, boundingBoxes, mapObject)
    % Calculate avoidance cost for bounding boxes
    % px2: robot trajectory positions [3, 1, K, NP] 
    % boundingBoxes: cell array of detected objects
    % mapObject: map object for visualization (optional)
    
    if isempty(boundingBoxes)
        BBcost = zeros(1, obj.NP, 'gpuArray');
        return;
    end
    
    % Extract robot positions (x, y) for all time steps and samples
    robot_x = squeeze(px2(1, 1, :, :)); % [K, NP]
    robot_y = squeeze(px2(2, 1, :, :)); % [K, NP]
    
    % Convert to GPU arrays
    robot_x = gpuArray(robot_x);
    robot_y = gpuArray(robot_y);
    
    % Initialize total cost
    total_cost = zeros(size(robot_x), 'gpuArray');
    
    % Safety margin around bounding boxes
    safety_margin = 0.2; % meters
    collision_penalty = 5000; % high penalty for collision
    proximity_penalty = 0.4; % lower penalty for being near
    
    % Debug visualization flag
    persistent bb_debug_enabled bb_plot_counter;
    if isempty(bb_debug_enabled)
        bb_debug_enabled = false; % Set to true to enable BB cost visualization
        bb_plot_counter = 0;
    end
    
    % Process each bounding box
    for i = 1:length(boundingBoxes)
        bbox = boundingBoxes{i};
        center = bbox.center; % [x, y, z]
        dimensions = bbox.dimensions; % [length, width, height]
        orientation = bbox.orientation; % rotation around z-axis
        
        % Convert to GPU arrays
        center_x = gpuArray(center(1));
        center_y = gpuArray(center(2));
        half_length = gpuArray(dimensions(1)/2 + safety_margin);
        half_width = gpuArray(dimensions(2)/2 + safety_margin);
        cos_theta = gpuArray(cos(orientation));
        sin_theta = gpuArray(sin(orientation));
        
        % Transform robot positions to bounding box local coordinates
        % Translate to box center
        rel_x = robot_x - center_x;
        rel_y = robot_y - center_y;
        
        % Rotate to box frame
        local_x = rel_x * cos_theta + rel_y * sin_theta;
        local_y = -rel_x * sin_theta + rel_y * cos_theta;
        
        % Check if robot is inside expanded bounding box
        inside_x = abs(local_x) <= half_length;
        inside_y = abs(local_y) <= half_width;
        inside_box = inside_x & inside_y;
        
        % Calculate distance-based cost
        dist_x = max(0, abs(local_x) - half_length);
        dist_y = max(0, abs(local_y) - half_width);
        bbox_distance = sqrt(dist_x.^2 + dist_y.^2);
        
        % Apply costs
        collision_cost = 0* inside_box * collision_penalty;
        proximity_cost =  proximity_penalty .* exp(-bbox_distance);
        
        total_cost = total_cost + collision_cost + proximity_cost;
        
        % Visualization for the first bounding box
        if bb_debug_enabled && i == 1
            bb_plot_counter = bb_plot_counter + 1;
            if mod(bb_plot_counter, 3) == 1 % Plot every 3rd call
                if nargin > 3 && exist('mapObject', 'var') && ~isempty(mapObject)
                    visualizeBoundingBoxCost(obj, bbox, robot_x, robot_y, inside_box, bbox_distance, ...
                                           collision_cost, proximity_cost, safety_margin, mapObject);
                else
                    visualizeBoundingBoxCost(obj, bbox, robot_x, robot_y, inside_box, bbox_distance, ...
                                           collision_cost, proximity_cost, safety_margin);
                end
            end
        end
    end
    
    % Sum over prediction horizon and reshape for output
    BBcost = reshape(sum(total_cost, 1), 1, []);
end

function plotMPCDebug(obj, px2, pw, boundingBoxes, remove_sample, Grid_Matrix, mapObject)
    % Debug visualization for MPC path planning
    % Shows: full world map, robot paths colored by cost, bounding boxes, best path
    
    try
        % Gather data from GPU
        px_cpu = gather(px2);
        pw_cpu = gather(pw);
        remove_sample_cpu = gather(remove_sample);
        
        % Create figure
        figure(999);
        clf;
        hold on;
        
        % Plot full world map if available, otherwise use grid map
        if nargin > 6 && ~isempty(mapObject)
            plotFullWorldMap(mapObject);
        else
            plotOccupancyMap(obj, Grid_Matrix);
        end
        
        % Color map for path costs (similar to myplotResult.m)
        Color_map = (169/255)*ones(30000,3);
        Color_map(1:10,:) = jet(10);
        
        % Find best path (lowest cost) first
        [~, best_idx] = min(pw_cpu);
        
        % Plot all predicted paths colored by cost
        for j = 1:size(px_cpu, 4)
            if ~remove_sample_cpu(j) % Only plot non-removed samples
                path_x = squeeze(px_cpu(1, 1, :, j));
                path_y = squeeze(px_cpu(2, 1, :, j));
                
                % Color based on cost (similar to myplotResult.m line 399)
                cost_index = min(ceil(pw_cpu(j)), size(Color_map, 1));
                if cost_index < 1, cost_index = 1; end
                
                plot(path_x, -path_y, 'Color', [Color_map(cost_index, :), 0.4], 'LineWidth', 1);
            end
        end
        
        % Show how MPC transforms coordinates for the best path
        if size(px_cpu, 4) > 0 && ~remove_sample_cpu(best_idx)
            showMPCCoordinateTransform(obj, px_cpu, Grid_Matrix, best_idx);
        end
        
        % Plot bounding boxes using grid coordinates
        if ~isempty(boundingBoxes)
            for i = 1:length(boundingBoxes)
                bbox = boundingBoxes{i};
                plotBoundingBoxGrid(obj, bbox, [1, 0, 0], 0.4); % Red with transparency
            end
        end
        
        % Plot best path (lowest cost)
        if ~remove_sample_cpu(best_idx)
            best_path_x = squeeze(px_cpu(1, 1, :, best_idx));
            best_path_y = squeeze(px_cpu(2, 1, :, best_idx));
            plot(best_path_x, best_path_y, 'g-', 'LineWidth', 3, 'DisplayName', 'Best Path');
        end
        
        % Plot current robot position
        current_x = px_cpu(1, 1, 1, 1);
        current_y = px_cpu(2, 1, 1, 1);
        current_yaw = px_cpu(3, 1, 1, 1);
        
        % Robot position and orientation
        plot(current_x, current_y, 'bo', 'MarkerSize', 10, 'MarkerFaceColor', 'b', 'DisplayName', 'Robot');
        quiver(current_x, current_y, 0.7*cos(current_yaw), 0.7*sin(current_yaw), ...
               'b', 'LineWidth', 2, 'MaxHeadSize', 2);
        
        % Plot waypoints if available
        if isfield(obj, 'waypoint')
            waypoint_cpu = gather(obj.waypoint);
            plot(waypoint_cpu(:,1), waypoint_cpu(:,2), 'k--o', 'LineWidth', 1, 'DisplayName', 'Waypoints');
        end
        
        % Formatting
        axis equal;
        grid on;
        xlabel('X (m)');
        ylabel('Y (m)');
        title(sprintf('MPC Debug: %d paths, Best cost: %.2f', size(px_cpu, 4), min(pw_cpu)));
        legend('Location', 'best');
        
        % Set axis limits around robot
        margin = 8;
        xlim([current_x - margin, current_x + margin]);
        ylim([current_y - margin, current_y + margin]);
        
        drawnow;
        
    catch ME
        fprintf('Debug plot failed: %s\n', ME.message);
    end
end

function plotOccupancyMap(obj, Grid_Matrix)
    % Plot occupancy grid map using the EXACT same coordinate system as the MPC
    try
        % Gather data from GPU
        map_cpu = gather(Grid_Matrix);
        xlim_cpu = gather(obj.Grid_Xlim);
        ylim_cpu = gather(obj.Grid_Ylim);
        cell_size_cpu = gather(obj.Cell_Size);
        grid_size_cpu = gather(obj.Grid_Size);
        
        fprintf('Grid Debug Info:\n');
        fprintf('  Grid_Matrix size: [%d, %d] (rows=Y, cols=X)\n', grid_size_cpu(1), grid_size_cpu(2));
        fprintf('  X world limits: [%.2f, %.2f]\n', xlim_cpu(1), xlim_cpu(2));
        fprintf('  Y world limits: [%.2f, %.2f]\n', ylim_cpu(1), ylim_cpu(2));
        fprintf('  Cell size: %.3f m\n', cell_size_cpu);
        fprintf('  MPC uses coordinate swap: [X,Y] -> [Y,X] for grid indexing\n');
        
        % CRITICAL: Grid_Matrix is stored as Grid_Matrix(row, col) = Grid_Matrix(Y_index, X_index)
        % Line 26 uses: state(:,[2,1],:,:) which swaps [X,Y] -> [Y,X]
        
        % Create coordinate vectors that match MPC's grid indexing
        % For display purposes, we need to understand how the grid is oriented
        x_world = linspace(xlim_cpu(1), xlim_cpu(2), grid_size_cpu(2)); % columns = X
        y_world = linspace(ylim_cpu(1), ylim_cpu(2), grid_size_cpu(1)); % rows = Y
        
        % Display the grid exactly as the MPC sees it
        imagesc(x_world, y_world, map_cpu);
        colormap(gray);
        caxis([0 1]);
        alpha(0.7);
        
        % Set axis direction to match MPC coordinate system
        set(gca, 'YDir', 'normal');
        
        % Add sparse grid lines for reference
        if grid_size_cpu(1) < 50 && grid_size_cpu(2) < 50
            x_step = max(1, round(length(x_world)/10));
            y_step = max(1, round(length(y_world)/10));
            for i = 1:x_step:length(x_world)
                line([x_world(i) x_world(i)], [y_world(1) y_world(end)], 'Color', [0.7 0.7 0.7], 'LineStyle', ':', 'LineWidth', 0.3);
            end
            for j = 1:y_step:length(y_world)
                line([x_world(1) x_world(end)], [y_world(j) y_world(j)], 'Color', [0.7 0.7 0.7], 'LineStyle', ':', 'LineWidth', 0.3);
            end
        end
        
    catch ME
        fprintf('Occupancy map plot failed: %s\n', ME.message);
    end
end

function plotBoundingBoxGrid(obj, bbox, color, alpha)
    % Plot bounding box by converting to grid coordinates and drawing on grid
    try
        center = bbox.center;
        dimensions = bbox.dimensions;
        orientation = bbox.orientation;
        
        % Get grid parameters
        xlim_cpu = gather(obj.Grid_Xlim);
        ylim_cpu = gather(obj.Grid_Ylim);
        cell_size_cpu = gather(obj.Cell_Size);
        grid_size_cpu = gather(obj.Grid_Size);
        
        % Calculate corners in local frame
        half_dims = dimensions / 2;
        corners_local = [
            -half_dims(1), -half_dims(2);
             half_dims(1), -half_dims(2);
             half_dims(1),  half_dims(2);
            -half_dims(1),  half_dims(2)
        ];
        
        % Rotation matrix around Z-axis
        R = [cos(orientation) -sin(orientation);
             sin(orientation)  cos(orientation)];
        
        % Transform to global frame
        corners_global = (R * corners_local')' + center(1:2);
        corners_global = [corners_global; corners_global(1, :)]; % Close the shape
        
        % Plot the bounding box in world coordinates
        plot(corners_global(:,1), corners_global(:,2), 'Color', color, 'LineWidth', 3);
        fill(corners_global(1:4,1), corners_global(1:4,2), color, 'FaceAlpha', alpha, 'EdgeColor', color);
        
        % Also mark the grid cells that would be affected
        markBoundingBoxOnGrid(obj, bbox, color);
        
    catch ME
        fprintf('Bounding box grid plot failed: %s\n', ME.message);
    end
end

function markBoundingBoxOnGrid(obj, bbox, color)
    % Mark grid cells using EXACT same coordinate transformation as MPC line 26
    try
        center = bbox.center;
        dimensions = bbox.dimensions;
        orientation = bbox.orientation;
        
        % Get grid parameters
        xlim_cpu = gather(obj.Grid_Xlim);
        ylim_cpu = gather(obj.Grid_Ylim);
        cell_size_cpu = gather(obj.Cell_Size);
        grid_size_cpu = gather(obj.Grid_Size);
        
        fprintf('  Bounding box center: [%.3f, %.3f]\n', center(1), center(2));
        fprintf('  Bounding box dims: [%.3f, %.3f] orient: %.3f°\n', dimensions(1), dimensions(2), rad2deg(orientation));
        
        % Create a dense sampling of points within the bounding box
        half_dims = dimensions / 2;
        
        % Sample points within the box (local coordinates)
        sample_res = 0.15; % 15cm resolution for clearer visualization
        x_samples = -half_dims(1):sample_res:half_dims(1);
        y_samples = -half_dims(2):sample_res:half_dims(2);
        [X_local, Y_local] = meshgrid(x_samples, y_samples);
        points_local = [X_local(:), Y_local(:)];
        
        % Rotation matrix around Z-axis
        R = [cos(orientation) -sin(orientation);
             sin(orientation)  cos(orientation)];
        
        % Transform to global frame
        points_global = (R * points_local')' + center(1:2);
        
        % EXACT same coordinate transformation as MPC line 25-26:
        % 1. Convert to grid-relative coordinates
        state = points_global - [xlim_cpu(1), ylim_cpu(1)];
        
        % 2. Apply coordinate swap [X,Y] -> [Y,X] and grid transformation
        % Grid_Idx = [obj.Grid_Size(1) 0]+[-1 1].*floor(state(:,[2,1],:,:)./obj.Cell_Size)+[0 1];
        state_swapped = state(:,[2,1]); % Critical [X,Y] -> [Y,X] swap!
        grid_indices_raw = floor(state_swapped / cell_size_cpu);
        grid_indices = [grid_size_cpu(1), 0] + [-1, 1] .* grid_indices_raw + [0, 1];
        
        % Filter valid grid indices (same bounds check as MPC line 28)
        valid_mask = grid_indices(:,1) >= 1 & grid_indices(:,1) <= grid_size_cpu(1) & ...
                     grid_indices(:,2) >= 1 & grid_indices(:,2) <= grid_size_cpu(2);
        valid_indices = grid_indices(valid_mask, :);
        
        % Plot grid cell markers using ORIGINAL world coordinates (before swap)
        if ~isempty(valid_indices)
            valid_world_points = points_global(valid_mask, :);
            scatter(valid_world_points(:,1), valid_world_points(:,2), 15, color, 'filled', 'MarkerFaceAlpha', 0.7);
            
            fprintf('  Marked %d grid cells for bounding box\n', size(valid_indices, 1));
        end
        
    catch ME
        fprintf('Grid marking failed: %s\n', ME.message);
    end
end

function showMPCCoordinateTransform(obj, px_cpu, Grid_Matrix, sample_idx)
    % Show exactly how the MPC transforms coordinates and checks collisions
    try
        if nargin < 4, sample_idx = 1; end
        
        % Get grid parameters (same as MPC)
        xlim_cpu = gather(obj.Grid_Xlim);
        ylim_cpu = gather(obj.Grid_Ylim);
        cell_size_cpu = gather(obj.Cell_Size);
        grid_size_cpu = gather(obj.Grid_Size);
        points_cpu = gather(obj.points);
        
        % Take first few timesteps of the selected sample
        num_steps = min(5, size(px_cpu, 3));
        
        fprintf('\n=== MPC Coordinate Transform Debug ===\n');
        fprintf('Sample %d, first %d timesteps:\n', sample_idx, num_steps);
        
        for k = 1:num_steps
            robot_x = px_cpu(1, 1, k, sample_idx);
            robot_y = px_cpu(2, 1, k, sample_idx);
            robot_yaw = px_cpu(3, 1, k, sample_idx);
            
            fprintf('\nTimestep %d:\n', k);
            fprintf('  Robot pose: [%.3f, %.3f, %.3f°]\n', robot_x, robot_y, rad2deg(robot_yaw));
            
            % Calculate vehicle corner points (same as MPC lines 20-22)
            cos_yaw = cos(robot_yaw);
            sin_yaw = sin(robot_yaw);
            R = [cos_yaw -sin_yaw; sin_yaw cos_yaw];
            
            % Transform corner points to world coordinates
            corners_world = (R * points_cpu')' + [robot_x, robot_y];
            
            fprintf('  Vehicle corners (world):\n');
            for i = 1:size(corners_world, 1)
                fprintf('    Corner %d: [%.3f, %.3f]\n', i, corners_world(i,1), corners_world(i,2));
            end
            
            % Convert to grid coordinates using EXACT same transformation as MPC line 25-26
            state = corners_world - [xlim_cpu(1), ylim_cpu(1)];
            
            % EXACT replication of MPC line 26 coordinate transformation:
            % Grid_Idx = [obj.Grid_Size(1) 0]+[-1 1].*floor(state(:,[2,1],:,:)./obj.Cell_Size)+[0 1];
            % Key: state(:,[2,1]) swaps [X,Y] -> [Y,X] for grid indexing
            state_swapped = state(:,[2,1]); % [X,Y] -> [Y,X] coordinate swap!
            grid_indices_raw = floor(state_swapped / cell_size_cpu);
            grid_indices = [grid_size_cpu(1), 0] + [-1, 1] .* grid_indices_raw + [0, 1];
            
            fprintf('  Grid indices [Y_idx, X_idx]:\n');
            max_occupancy = 0;
            for i = 1:size(grid_indices, 1)
                y_idx = grid_indices(i, 1);
                x_idx = grid_indices(i, 2);
                
                % Check bounds
                if y_idx >= 1 && y_idx <= grid_size_cpu(1) && x_idx >= 1 && x_idx <= grid_size_cpu(2)
                    occupancy = Grid_Matrix(y_idx, x_idx);
                    max_occupancy = max(max_occupancy, occupancy);
                    fprintf('    Corner %d: [%d, %d] -> occupancy = %.3f\n', i, y_idx, x_idx, occupancy);
                    
                    % Plot this grid cell
                    cell_x = (x_idx - 1) * cell_size_cpu + xlim_cpu(1);
                    cell_y = (y_idx - 1) * cell_size_cpu + ylim_cpu(1);
                    rectangle('Position', [cell_x, cell_y, cell_size_cpu, cell_size_cpu], ...
                             'FaceColor', [1, 1, 0, 0.5], 'EdgeColor', 'y', 'LineWidth', 2);
                else
                    fprintf('    Corner %d: [%d, %d] -> OUT OF BOUNDS\n', i, y_idx, x_idx);
                end
            end
            
            % Show robot corners
            plot(corners_world(:,1), corners_world(:,2), 'mo', 'MarkerSize', 8, 'MarkerFaceColor', 'm');
            
            fprintf('  Max occupancy: %.3f (remove if >= 0.98)\n', max_occupancy);
            
            if k <= 3 % Only show first few to avoid clutter
                % Draw robot rectangle at this timestep
                robot_corners = [corners_world; corners_world(1, :)];
                plot(robot_corners(:,1), robot_corners(:,2), 'm-', 'LineWidth', 2);
                text(robot_x, robot_y, sprintf('t%d', k), 'Color', 'm', 'FontSize', 12, 'FontWeight', 'bold');
            end
        end
        
    catch ME
        fprintf('Coordinate transform debug failed: %s\n', ME.message);
    end
end

function visualizeBoundingBoxCost(obj, bbox, robot_x, robot_y, inside_box, bbox_distance, collision_cost, proximity_cost, safety_margin, varargin)
    % Detailed visualization of bounding box cost calculation with optional map background
    try
        % Gather data from GPU
        robot_x_cpu = gather(robot_x);
        robot_y_cpu = gather(robot_y);
        inside_box_cpu = gather(inside_box);
        bbox_distance_cpu = gather(bbox_distance);
        collision_cost_cpu = gather(collision_cost);
        proximity_cost_cpu = gather(proximity_cost);
        
        % Create separate figure for bounding box analysis
        figure(998);
        clf;
        hold on;
        
        % Plot map background if available
        if nargin > 9 && ~isempty(varargin{1})
            mapObject = varargin{1};
            fprintf('Plotting map background for bounding box analysis...\n');
            plotFullWorldMap(mapObject);
        end
        
        % Extract bounding box parameters
        center = bbox.center;
        dimensions = bbox.dimensions;
        orientation = bbox.orientation;
        
        fprintf('\n=== Bounding Box Cost Analysis ===\n');
        fprintf('Object center: [%.2f, %.2f]\n', center(1), center(2));
        fprintf('Dimensions: [%.2f × %.2f] m\n', dimensions(1), dimensions(2));
        fprintf('Orientation: %.1f degrees\n', rad2deg(orientation));
        fprintf('Safety margin: %.2f m\n', safety_margin);
        
        % 1. Plot original bounding box (object boundary)
        plotRotatedRectangle(center(1:2), dimensions(1:2), orientation, [1 0 0], 2, 0.1, 'Object');
        
        % 2. Plot expanded bounding box (with safety margin)
        expanded_dims = dimensions(1:2) + 2*safety_margin;
        plotRotatedRectangle(center(1:2), expanded_dims, orientation, [1 0.5 0], 2, 0.2, 'Safety Zone');
        
        % 3. Show cost field visualization around the object
        visualizeCostField(center(1:2), expanded_dims, orientation, safety_margin);
        
        % 4. Plot robot trajectories with cost-based coloring
        num_samples = min(50, size(robot_x_cpu, 2)); % Show subset for clarity
        sample_indices = round(linspace(1, size(robot_x_cpu, 2), num_samples));
        
        for i = 1:length(sample_indices)
            idx = sample_indices(i);
            
            % Extract trajectory
            traj_x = robot_x_cpu(:, idx);
            traj_y = robot_y_cpu(:, idx);
            
            % Calculate total cost for this trajectory
            total_traj_cost = sum(collision_cost_cpu(:, idx) + proximity_cost_cpu(:, idx));
            
            % Color based on cost level using green-to-red gradient
            max_cost = 5000; % Define maximum cost for color scaling
            normalized_cost = min(total_traj_cost / max_cost, 1); % Normalize cost to [0,1]
            
            % Green to red gradient: Green (0,1,0) -> Yellow (1,1,0) -> Red (1,0,0)
            if normalized_cost <= 0.5
                % Green to yellow transition
                green_component = 1;
                red_component = 2 * normalized_cost;
                blue_component = 0;
            else
                % Yellow to red transition
                green_component = 2 * (1 - normalized_cost);
                red_component = 1;
                blue_component = 0;
            end
            
            color = [red_component, green_component, blue_component];
            
            % Line width based on cost
            if total_traj_cost > 4000
                width = 2;
            elseif total_traj_cost > 100
                width = 1.5;
            else
                width = 1;
            end
            
            plot(traj_x, traj_y, 'Color', [color, 0.6], 'LineWidth', width);
            
            % Mark collision points
            collision_points = inside_box_cpu(:, idx);
            if any(collision_points)
                collision_x = traj_x(collision_points);
                collision_y = traj_y(collision_points);
                scatter(collision_x, collision_y, 80, [1 0 0], 'filled', 'MarkerEdgeColor', [0 0 0]);
            end
        end
        
        % 5. Show statistics
        total_collisions = sum(inside_box_cpu(:));
        avg_distance = mean(bbox_distance_cpu(bbox_distance_cpu > 0));
        max_cost = max(collision_cost_cpu(:) + proximity_cost_cpu(:));
        
        fprintf('Total collision points: %d\n', total_collisions);
        fprintf('Average distance (non-collision): %.3f m\n', avg_distance);
        fprintf('Maximum single-point cost: %.1f\n', max_cost);
        
        % 6. Plot object center and orientation
        plot(center(1), center(2), 'o', 'Color', [0 0 0], 'MarkerSize', 10, 'MarkerFaceColor', [0 0 0]);
        
        % Show orientation arrow
        arrow_length = max(dimensions(1:2)) / 2;
        arrow_x = center(1) + arrow_length * cos(orientation);
        arrow_y = center(2) + arrow_length * sin(orientation);
        quiver(center(1), center(2), arrow_x - center(1), arrow_y - center(2), ...
               'Color', [0 0 0], 'LineWidth', 3, 'MaxHeadSize', 2);
        
        % Formatting
        axis equal;
        grid on;
        xlabel('X (m)');
        ylabel('Y (m)');
        title(sprintf('Bounding Box Cost Analysis: %.0f collisions, max cost: %.1f', total_collisions, max_cost));
        
        % Set axis limits around the bounding box
        margin = 2;
        x_range = [center(1) - expanded_dims(1)/2 - margin, center(1) + expanded_dims(1)/2 + margin];
        y_range = [center(2) - expanded_dims(2)/2 - margin, center(2) + expanded_dims(2)/2 + margin];
        xlim(x_range);
        ylim(y_range);
        
        % Add legend
        legend({'Object Boundary', 'Safety Zone', 'Robot Trajectories', 'Collision Points', 'Object Center'}, ...
               'Location', 'best');
        
        drawnow;
        
    catch ME
        fprintf('Bounding box visualization failed: %s\n', ME.message);
    end
end

function plotRotatedRectangle(center, dimensions, orientation, color, linewidth, alpha, label)
    % Plot a rotated rectangle
    % Calculate corners in local frame
    half_dims = dimensions / 2;
    corners_local = [
        -half_dims(1), -half_dims(2);
         half_dims(1), -half_dims(2);
         half_dims(1),  half_dims(2);
        -half_dims(1),  half_dims(2)
    ];
    
    % Rotation matrix
    R = [cos(orientation) -sin(orientation);
         sin(orientation)  cos(orientation)];
    
    % Transform to global frame
    corners_global = (R * corners_local')' + center;
    corners_global = [corners_global; corners_global(1, :)]; % Close the shape
    
    % Plot rectangle
    if alpha > 0
        fill(corners_global(:,1), corners_global(:,2), color, 'FaceAlpha', alpha, ...
             'EdgeColor', color, 'LineWidth', linewidth, 'DisplayName', label);
    else
        plot(corners_global(:,1), corners_global(:,2), 'Color', color, ...
             'LineWidth', linewidth, 'DisplayName', label);
    end
end

function visualizeCostField(center, expanded_dims, orientation, safety_margin)
    % Create a cost field visualization around the bounding box
    
    % Create grid around the object
    margin = 1.5;
    x_range = center(1) + (-expanded_dims(1)/2 - margin : 0.1 : expanded_dims(1)/2 + margin);
    y_range = center(2) + (-expanded_dims(2)/2 - margin : 0.1 : expanded_dims(2)/2 + margin);
    [X, Y] = meshgrid(x_range, y_range);
    
    % Calculate cost for each point
    cost_field = zeros(size(X));
    
    % Transform to object local coordinates
    rel_x = X - center(1);
    rel_y = Y - center(2);
    
    local_x = rel_x * cos(orientation) + rel_y * sin(orientation);
    local_y = -rel_x * sin(orientation) + rel_y * cos(orientation);
    
    % Calculate distances and costs (same logic as main algorithm)
    half_length = expanded_dims(1)/2;
    half_width = expanded_dims(2)/2;
    
    inside_x = abs(local_x) <= half_length;
    inside_y = abs(local_y) <= half_width;
    inside_box = inside_x & inside_y;
    
    dist_x = max(0, abs(local_x) - half_length);
    dist_y = max(0, abs(local_y) - half_width);
    field_distance = sqrt(dist_x.^2 + dist_y.^2);
    
    collision_cost = inside_box * 5000;
    proximity_cost = (~inside_box) .* 1000 .* exp(-field_distance);
    
    cost_field = collision_cost + proximity_cost;
    
    % Plot cost field as contours
    contour_levels = [10, 50, 100, 200, 500, 1000, 2000, 5000];
    contour(X, Y, cost_field, contour_levels, 'LineWidth', 1);
    
    % Add colorbar for cost reference
    colorbar;
    colormap(hot);
end

function plotFullWorldMap(mapObject)
    % Plot the complete world map in world coordinates using show() method
    try
        fprintf('=== Full World Map Visualization ===\n');
        fprintf('Map world X limits: [%.2f, %.2f] m\n', mapObject.XWorldLimits(1), mapObject.XWorldLimits(2));
        fprintf('Map world Y limits: [%.2f, %.2f] m\n', mapObject.YWorldLimits(1), mapObject.YWorldLimits(2));
        fprintf('Map resolution: %.3f cells/m\n', mapObject.Resolution);
        fprintf('Map size: [%d, %d] cells\n', size(mapObject.occupancyMatrix, 1), size(mapObject.occupancyMatrix, 2));
        
        % Use the built-in show method to ensure correct coordinate system
        show(mapObject);
        hold on;  % Allow overlaying additional elements
        
        % Add grid lines for reference at 5-meter intervals
        x_grid_lines = floor(mapObject.XWorldLimits(1)/5)*5:5:ceil(mapObject.XWorldLimits(2)/5)*5;
        y_grid_lines = floor(mapObject.YWorldLimits(1)/5)*5:5:ceil(mapObject.YWorldLimits(2)/5)*5;
        
        for x = x_grid_lines
            if x >= mapObject.XWorldLimits(1) && x <= mapObject.XWorldLimits(2)
                line([x x], mapObject.YWorldLimits, 'Color', [0.6 0.6 0.9], 'LineStyle', ':', 'LineWidth', 0.5);
            end
        end
        
        for y = y_grid_lines
            if y >= mapObject.YWorldLimits(1) && y <= mapObject.YWorldLimits(2)
                line(mapObject.XWorldLimits, [y y], 'Color', [0.6 0.6 0.9], 'LineStyle', ':', 'LineWidth', 0.5);
            end
        end
        
        % Add coordinate labels
        xlabel('X (m) - World Coordinates');
        ylabel('Y (m) - World Coordinates');
        title('Complete World Map (Occupancy Grid)');
        
        % Add a text box with map information
        info_str = sprintf('World Map: %.0fm × %.0fm\nResolution: %.1f cells/m\nTotal area: %.1f m²', ...
                          diff(mapObject.XWorldLimits), diff(mapObject.YWorldLimits), ...
                          mapObject.Resolution, diff(mapObject.XWorldLimits)*diff(mapObject.YWorldLimits));
        text(mapObject.XWorldLimits(1) + 0.02*diff(mapObject.XWorldLimits), ...
             mapObject.YWorldLimits(2) - 0.02*diff(mapObject.YWorldLimits), ...
             info_str, 'FontSize', 10, 'BackgroundColor', 'w', 'EdgeColor', 'k', ...
             'VerticalAlignment', 'top');
        
        fprintf('Successfully plotted complete world map using show() method\n');
        
    catch ME
        fprintf('Full world map visualization failed: %s\n', ME.message);
        % Fallback to error message
        text(0, 0, sprintf('Map visualization failed: %s', ME.message), ...
             'HorizontalAlignment', 'center', 'Color', 'r', 'FontSize', 12);
    end
end