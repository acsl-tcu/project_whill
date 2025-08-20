function [waypoints, selectZone, NoEntryZone, ZoneNum, V_ref] = PathSetting_AStar(start_position,goal_position,robot_width,robot_length)
    % A*-based path setting using map2.mat occupancy grid
    % This version automatically generates waypoints using A* pathfinding
    % instead of manual waypoint definition
    
    fprintf('Loading occupancy map for A* pathfinding...\n');
    debug_on=false;
    try
        % Load the occupancy map
        map_data = load('map2.mat');
        map_obj = map_data.map;
        
        % Extract occupancy matrix and parameters
        occ_matrix = getOccupancy(map_obj);  % This method works with this MATLAB version
        resolution = map_obj.Resolution;  % cells per meter
        map_origin = map_obj.GridOriginInLocal;  % [x, y] origin
        
        fprintf('Map loaded - Size: %dx%d, Resolution: %.1f cells/m\n', ...
                size(occ_matrix, 1), size(occ_matrix, 2), resolution);
        fprintf('World limits - X: [%.1f, %.1f], Y: [%.1f, %.1f]\n', ...
                map_obj.XWorldLimits(1), map_obj.XWorldLimits(2), ...
                map_obj.YWorldLimits(1), map_obj.YWorldLimits(2));
        
    catch ME
        fprintf('Error loading map2.mat: %s\n', ME.message);
        fprintf(['Falling back to original manual waypo' ...
            'ints...\n']);
        [waypoints, selectZone, NoEntryZone, ZoneNum, V_ref] = PathSetting_original();
        return;
    end
    
    % Robot parameters (wheelchair dimensions) - passed as function arguments
    if nargin >= 4 && ~isempty(robot_width) && ~isempty(robot_length)
        % Use provided vehicle dimensions
        safety_margin = 0.15;  % Additional safety clearance
        fprintf('Using provided vehicle dimensions:\n');
        fprintf('  Width: %.2fm, Length: %.2fm, Safety margin: %.2fm\n', ...
                robot_width, robot_length, safety_margin);
    else
        % Fallback to default values
        robot_width = 0.6;     % meters (fallback)
        robot_length = 1.0;    % meters (fallback)
        safety_margin = 0.1;   % meters (fallback)
        fprintf('WARNING: Vehicle dimensions not provided, using defaults\n');
        fprintf('  Width: %.2fm, Length: %.2fm, Safety margin: %.2fm\n', ...
                robot_width, robot_length, safety_margin);
    end
    
    % Define start and goal positions
    % Use provided start position or fallback to original if not provided
    if nargin < 1 || isempty(start_position)
        start_pos = [4, -0.2];     % Original first waypoint as fallback
    else
        start_pos = [start_position(1), start_position(2)];  % Use current wheelchair position
    end
    
    if nargin < 2 || isempty(goal_position)
        goal_pos = [30.0, 12.5];     % Original last waypoint as fallback
    else
        goal_pos = [goal_position(1), goal_position(2)];   % Use provided goal position
    end
    
    fprintf('Planning path from [%.1f, %.1f] to [%.1f, %.1f]...\n', ...
            start_pos(1), start_pos(2), goal_pos(1), goal_pos(2));
    
    % Debug: Check start and goal positions in occupancy grid
    fprintf('\n=== A* DEBUGGING ===\n');
    [rows, cols] = size(occ_matrix);
    
    % Convert world coordinates to grid coordinates for debugging
    % Use the same conversion as the occupancyMap's internal coordinate system
    start_grid = world2grid(map_obj, [start_pos(1), start_pos(2)]);
    start_r = start_grid(1);
    start_c = start_grid(2);
    goal_grid = world2grid(map_obj, [goal_pos(1), goal_pos(2)]);
    goal_r = goal_grid(1);
    goal_c = goal_grid(2);
    fprintf('Grid size: %dx%d cells\n', rows, cols);
    fprintf('Start world: [%.2f, %.2f] -> grid: [%d, %d]\n', start_pos(1), start_pos(2), start_r, start_c);
    fprintf('Goal world:  [%.2f, %.2f] -> grid: [%d, %d]\n', goal_pos(1), goal_pos(2), goal_r, goal_c);
    
    % Check if start/goal are within bounds
    fprintf('Valid grid bounds: rows [1-%d], cols [1-%d]\n', rows, cols);
    
    if start_r < 1 || start_r > rows || start_c < 1 || start_c > cols
        fprintf('ERROR: Start position [%d, %d] is OUTSIDE grid bounds!\n', start_r, start_c);
        fprintf('  Calculated start_r=%d (valid: 1-%d), start_c=%d (valid: 1-%d)\n', start_r, rows, start_c, cols);
        fprintf('  World pos [%.2f, %.2f] -> Grid pos [%d, %d]\n', start_pos(1), start_pos(2), start_r, start_c);
    else
        fprintf('Start position [%d, %d] is WITHIN bounds - OK\n', start_r, start_c);
        fprintf('Start occupancy value: %.3f\n', occ_matrix(start_r, start_c));
    end
    
    if goal_r < 1 || goal_r > rows || goal_c < 1 || goal_c > cols
        fprintf('ERROR: Goal position [%d, %d] is OUTSIDE grid bounds!\n', goal_r, goal_c);
        fprintf('  Calculated goal_r=%d (valid: 1-%d), goal_c=%d (valid: 1-%d)\n', goal_r, rows, goal_c, cols);
        fprintf('  World pos [%.2f, %.2f] -> Grid pos [%d, %d]\n', goal_pos(1), goal_pos(2), goal_r, goal_c);
    else
        fprintf('Goal position [%d, %d] is WITHIN bounds - OK\n', goal_r, goal_c);
        fprintf('Goal occupancy value: %.3f\n', occ_matrix(goal_r, goal_c));
    end
    
    % Check occupancy thresholds
    fprintf('Map occupancy range: %.3f to %.3f\n', min(occ_matrix(:)), max(occ_matrix(:)));
    fprintf('Free space threshold: < 0.5, Occupied: >= 0.5\n');
    
    % Check robot clearance - use larger dimension plus safety margin
    robot_clearance = max(robot_width, robot_length) + safety_margin;
    clearance_cells = ceil(robot_clearance * resolution / 2) + 1;
    fprintf('Robot clearance: %.1f cells (%.2fm total clearance)\n', clearance_cells, robot_clearance);
    
    % PLOT: Create two debug plots to show both coordinate systems
    fprintf('\nCreating debug plots...\n');
    
    %% ===== FIGURE 1: WORLD COORDINATES =====
   if debug_on
    figure('Name', 'A* Debug: World Coordinates', 'Position', [50, 100, 900, 600]);
    
    % Display occupancy map in world coordinates using MATLAB's show() function
    show(map_obj);
    hold on;
    
    % Plot start position (blue circle)
    plot(start_pos(1), start_pos(2), 'bo', 'MarkerSize', 15, 'LineWidth', 4, 'MarkerFaceColor', 'blue');
    text(start_pos(1) + 2, start_pos(2) + 1, 'START', 'Color', 'blue', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Plot goal position (red square)  
    plot(goal_pos(1), goal_pos(2), 'rs', 'MarkerSize', 15, 'LineWidth', 4, 'MarkerFaceColor', 'red');
    text(goal_pos(1) + 2, goal_pos(2) + 1, 'GOAL', 'Color', 'red', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Plot original manual waypoints for reference (green line)
    waypoints_orig_plot = [4.0000   -0.2000; 1.9100   -0.2000; -0.1800   -0.2000; -0.6800    0.3000; -0.6800    2.1000; -0.6800    3.9000; -0.6800    5.7000; -0.1800    6.2000; 1.8787    6.2000; 3.9373    6.2000; 5.9960    6.2000; 8.0547    6.2000; 10.1133    6.2000; 12.1720    6.2000; 14.2307    6.2000; 16.2893    6.2000; 18.3480    6.2000; 20.4067    6.2000; 22.4653    6.2000; 24.5240    6.2000; 26.5827    6.2000; 28.6413    6.2000; 30.7000    6.2000; 31.2000    6.7000; 31.2000    7.8500; 31.2000    9.0000; 31.7000    9.5000; 33.0000    9.5000; 34.0000    9.5000; 34.2000    9.5000; 38.0000    9.5000];
    plot(waypoints_orig_plot(:,1), waypoints_orig_plot(:,2), 'g--', 'LineWidth', 3);
    plot(waypoints_orig_plot(:,1), waypoints_orig_plot(:,2), 'go', 'MarkerSize', 6);
    
    title(sprintf('WORLD COORDINATES (meters)\nStart: [%.1f, %.1f]m, Goal: [%.1f, %.1f]m', start_pos(1), start_pos(2), goal_pos(1), goal_pos(2)));
    xlabel('X Position (meters)');
    ylabel('Y Position (meters)');
    legend('Start (A*)', 'Goal (A*)', 'Original Path', 'Original Waypoints', 'Location', 'best');
    grid on;
    axis equal;
    hold off;
    
    %% ===== FIGURE 2: GRID COORDINATES =====
    figure('Name', 'A* Debug: Grid Coordinates', 'Position', [1000, 100, 900, 600]);
    
    % Display occupancy grid in grid coordinates (array indices)
    imagesc(occ_matrix);
    colormap(gray);
    colorbar;
    hold on;
    
    % Convert start/goal to bounded grid coordinates for plotting
    start_r_plot = max(1, min(rows, start_r));
    start_c_plot = max(1, min(cols, start_c));
    goal_r_plot = max(1, min(rows, goal_r));
    goal_c_plot = max(1, min(cols, goal_c));
    
    % Plot start position in grid coordinates (blue circle)
    plot(start_c_plot, start_r_plot, 'bo', 'MarkerSize', 15, 'LineWidth', 4, 'MarkerFaceColor', 'blue');
    text(start_c_plot + 50, start_r_plot + 20, 'START', 'Color', 'blue', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Plot goal position in grid coordinates (red square)
    plot(goal_c_plot, goal_r_plot, 'rs', 'MarkerSize', 15, 'LineWidth', 4, 'MarkerFaceColor', 'red');
    text(goal_c_plot + 50, goal_r_plot + 20, 'GOAL', 'Color', 'red', 'FontSize', 14, 'FontWeight', 'bold');
    
    % Convert and plot original waypoints in grid coordinates for reference
    waypoints_grid = zeros(size(waypoints_orig_plot));
    for i = 1:size(waypoints_orig_plot, 1)
        wp_grid = world2grid(map_obj, [waypoints_orig_plot(i,1), waypoints_orig_plot(i,2)]);
        wp_r = wp_grid(1);
        wp_c = wp_grid(2);
        waypoints_grid(i,:) = [max(1, min(cols, wp_c)), max(1, min(rows, wp_r))];
    end
    plot(waypoints_grid(:,1), waypoints_grid(:,2), 'g--', 'LineWidth', 3);
    plot(waypoints_grid(:,1), waypoints_grid(:,2), 'go', 'MarkerSize', 6);
    
    title(sprintf('GRID COORDINATES (array indices)\nStart: [%d, %d], Goal: [%d, %d]\nGrid Size: %dx%d cells', start_r, start_c, goal_r, goal_c, rows, cols));
    xlabel('Column Index (1 to 4000)');
    ylabel('Row Index (1 to 800)');
    legend('Start (A*)', 'Goal (A*)', 'Original Path', 'Original Waypoints', 'Location', 'best');
    grid on;
    axis equal;
    
    % Add coordinate conversion info
    text(0.02, 0.98, sprintf('Resolution: %.0f cells/meter', resolution), ...
         'Units', 'normalized', 'BackgroundColor', 'white', 'FontSize', 12, 'FontWeight', 'bold');
    text(0.02, 0.92, sprintf('1 meter = %.0f cells', resolution), ...
         'Units', 'normalized','BackgroundColor', 'white', 'FontSize', 10);
    text(0.02, 0.86, sprintf('1 cell = %.1f cm', 100/resolution), ...
         'Units', 'normalized', 'BackgroundColor', 'white', 'FontSize', 10);
    
    hold off;
    fprintf('Two debug plots created - check both figure windows\n');
   end
    %% Use A* pathfinding
    astar_path = pathPlanningOccupancyGrid(start_pos, goal_pos, occ_matrix, ...
                                          resolution, map_origin, robot_width, robot_length, map_obj, debug_on);
    
    if isempty(astar_path)
        fprintf('\nA* PATHFINDING FAILED!\n');
        fprintf('Possible reasons:\n');
        fprintf('1. Start or goal in occupied space\n');
        fprintf('2. No path exists due to obstacles\n');
        fprintf('3. Robot clearance too large for narrow passages\n');
        fprintf('4. Coordinate conversion errors\n');
        fprintf('Falling back to original waypoints...\n');
        fprintf('==================\n');
        [waypoints, selectZone, NoEntryZone, ZoneNum, V_ref] = PathSetting_original();
        return;
    end
    
    fprintf('A* SUCCESS: Found path with %d points\n', size(astar_path, 1));
    fprintf('==================\n');
    
    fprintf('A* found path with %d waypoints\n', size(astar_path, 1));
    
    % The A* path might have too many points, so subsample for smoother control
    % Keep every Nth point, but always keep start and end
    subsample_factor = max(1, floor(size(astar_path, 1) / 30)); % Target ~30 waypoints
    indices = 1:subsample_factor:size(astar_path, 1);
    if indices(end) ~= size(astar_path, 1)
        indices = [indices, size(astar_path, 1)]; % Ensure goal is included
    end
    
    waypoints = [astar_path(indices(1:end-1), :);goal_pos];
    fprintf('Subsampled to %d waypoints for control\n', size(waypoints, 1));
    
    % Set up zones (simplified - use original zones as reference)
    % For now, create a simple single zone covering the corridor areas
    NoEntryZone = inf(3,4,10).*[1 -1 1 -1];
    
    % Define corridor boundaries based on map limits
    % These are approximate boundaries for Building 10, 4th floor corridor
    NoEntryZone(1:3,:,1) = [-0.05, 38.00,  0.60,  5.40;   % Main corridor walls
                           -5.00, -1.40, -6.00, 12.00;    % Left side boundary  
                           -1.40, 38.00, -6.00, -1.00];   % Bottom boundary
    
    % Create zone selection (all waypoints use zone 1 for now)
    selectZone = ones(size(waypoints,1), 1);
    
    % Set reference velocities
    V_ref = zeros(size(waypoints,1), 1) + 0.5;  % 0.5 m/s default
    V_ref(end-1) = 0.2;  % Slow down before goal
    V_ref(end) = 0;      % Stop at goal
    
    % Calculate zone numbers
    ZoneNum = zeros(size(NoEntryZone, 3), 1);
    for i = 1:size(NoEntryZone, 3)
        for k = 1:size(NoEntryZone, 1)
            if NoEntryZone(k,:,i) == [inf -inf inf -inf]
                break
            else
                ZoneNum(i) = k;
            end
        end
    end
    
    % Validation
    for i = 1:size(NoEntryZone, 3)
        if NoEntryZone(1,:,i) == [inf -inf inf -inf] 
            GrupuNum = i - 1;
            break
        elseif i == size(NoEntryZone, 3)
            GrupuNum = i - 1;
            break
        end
    end
    
    % Check for errors
    flag = 0;
    for i = 1:size(NoEntryZone, 3)
        for j = 1:ZoneNum(i)
            if NoEntryZone(j,1,i) > NoEntryZone(j,2,i) || NoEntryZone(j,3,i) > NoEntryZone(j,4,i)
                fprintf('NoEntryZone(%d,:%d) is incorrect!\n', j, i);
                flag = 1;
            end
        end
    end
    
    if max(selectZone) > GrupuNum
        fprintf('selectZone value exceeds NoEntryZone group count!\n');
        flag = 1;
    end
    
    if flag == 1
        fprintf('Validation failed! Using original waypoints...\n');
        [waypoints, selectZone, NoEntryZone, ZoneNum, V_ref] = PathSetting_original();
        return;
    end
    
    % Optional: Plot the generated path for visualization
    if false  % Set to true to enable plotting
        figure;
        hold on;
        
        % Show occupancy grid
        x_world = linspace(map_obj.XWorldLimits(1), map_obj.XWorldLimits(2), size(occ_matrix, 2));
        y_world = linspace(map_obj.YWorldLimits(1), map_obj.YWorldLimits(2), size(occ_matrix, 1));
        imagesc(x_world, y_world, flipud(occ_matrix'));
        colormap(gray);
        
        % Plot A* waypoints
        plot(waypoints(:,1), waypoints(:,2), 'ro-', 'LineWidth', 2, 'MarkerSize', 8);
        plot(start_pos(1), start_pos(2), 'gs', 'MarkerSize', 12, 'LineWidth', 3);
        plot(goal_pos(1), goal_pos(2), 'rs', 'MarkerSize', 12, 'LineWidth', 3);
        
        xlabel('X (m)');
        ylabel('Y (m)');
        title('A* Generated Waypoints');
        legend('Occupancy Grid', 'A* Waypoints', 'Start', 'Goal');
        grid on;
        axis equal;
    end
    
    fprintf('A* pathfinding completed successfully!\n');
    
    % Print comparison between original and A* waypoints
    fprintf('\n========================================\n');
    fprintf('WAYPOINT COMPARISON\n');
    fprintf('========================================\n');
    
    % Hardcoded original manual waypoints from PathSetting_original.m
    waypoints_orig = [4.0000   -0.2000
                      1.9100   -0.2000
                     -0.1800   -0.2000
                     -0.6800    0.3000
                     -0.6800    2.1000
                     -0.6800    3.9000
                     -0.6800    5.7000
                     -0.1800    6.2000
                      1.8787    6.2000
                      3.9373    6.2000
                      5.9960    6.2000
                      8.0547    6.2000
                     10.1133    6.2000
                     12.1720    6.2000
                     14.2307    6.2000
                     16.2893    6.2000
                     18.3480    6.2000
                     20.4067    6.2000
                     22.4653    6.2000
                     24.5240    6.2000
                     26.5827    6.2000
                     28.6413    6.2000
                     30.7000    6.2000
                     31.2000    6.7000
                     31.2000    7.8500
                     31.2000    9.0000
                     31.7000    9.5000
                     33.0000    9.5000
                     34.0000    9.5000
                     34.2000    9.5000
                     38.0000    9.5000];
    
    fprintf('ORIGINAL MANUAL WAYPOINTS (%d points):\n', size(waypoints_orig, 1));
    for i = 1:size(waypoints_orig, 1)
        fprintf('%2d: [%7.2f, %7.2f]\n', i, waypoints_orig(i, 1), waypoints_orig(i, 2));
    end
    
    fprintf('\nA* GENERATED WAYPOINTS (%d points):\n', size(waypoints, 1));
    for i = 1:size(waypoints, 1)
        fprintf('%2d: [%7.2f, %7.2f]\n', i, waypoints(i, 1), waypoints(i, 2));
    end
    fprintf('========================================\n');
  
end
% ===== A* UTILITY FUNCTIONS =====

function path = pathPlanningOccupancyGrid(start, goal, occ_matrix, resolution, map_origin, robot_width, robot_length, map_obj, debug_on)
    % A* path planning using occupancy grid
    [rows, cols] = size(occ_matrix);
    
    % Convert world coordinates to grid coordinates using the original map object
    start_grid = world2grid(map_obj, [start(1), start(2)]);
    start_r = start_grid(1);
    start_c = start_grid(2);
    goal_grid = world2grid(map_obj, [goal(1), goal(2)]);
    goal_r = goal_grid(1);
    goal_c = goal_grid(2);
    
    % Bounds checking
    start_r = max(1, min(rows, start_r));
    start_c = max(1, min(cols, start_c));
    goal_r = max(1, min(rows, goal_r));
    goal_c = max(1, min(cols, goal_c));
    
    % Inflate obstacles for robot size
    clearance_cells = ceil(max(robot_width, robot_length) * resolution / 2) + 1;
    inflated_map = inflateMap(occ_matrix, clearance_cells);
    
    % A* pathfinding
    path_indices = astar([start_r, start_c], [goal_r, goal_c], inflated_map,debug_on);
    
    if isempty(path_indices)
        path = [];
        return;
    end
    
    % Convert back to world coordinates using the original map object
    path = [];
    for i = 1:size(path_indices, 1)
        r = path_indices(i, 1);
        c = path_indices(i, 2);
        [world_pos] = grid2world(map_obj, [r,c]);
        path = [path; world_pos(1), world_pos(2)];
    end
end

function inflated_map = inflateMap(occ_matrix, clearance)
    % Inflate obstacles by clearance distance
    [rows, cols] = size(occ_matrix);
    inflated_map = occ_matrix;
    
    for r = 1:rows
        for c = 1:cols
            if occ_matrix(r, c) >= 0.5
                % This cell is occupied, inflate around it
                r_min = max(1, r - clearance);
                r_max = min(rows, r + clearance);
                c_min = max(1, c - clearance);
                c_max = min(cols, c + clearance);
                
                inflated_map(r_min:r_max, c_min:c_max) = 1;
            end
        end
    end
end

function path = astar(start, goal, obstacle_map,debug_on)
    % Simple A* implementation with detailed debugging and optional visualization
    [rows, cols] = size(obstacle_map);
    
    % Enable/disable visualization and recording
    ENABLE_VISUALIZATION = debug_on;   % Set to false to disable
    RECORD_VIDEO = true && ENABLE_VISUALIZATION;           % Set to false to disable video recording
    close all
    % Video recording settings
    VIDEO_FRAME_RATE = 10;        % Frames per second in output video
    VIDEO_QUALITY = 90;           % Video quality (0-100)
    EARLY_RECORD_ITERATIONS = 10; % Record every iteration for first N iterations
    MAIN_RECORD_INTERVAL = 10000;   % Record every N iterations during main search
    FINAL_RECORD_DURATION = 3;    % Seconds to record final result
    
    % Setup video recording
    if ENABLE_VISUALIZATION && RECORD_VIDEO
        video_filename = sprintf('astar_visualization_%s.avi', datestr(now, 'yyyymmdd_HHMMSS'));
        try
            % Try Motion JPEG AVI first (most compatible)
            video_writer = VideoWriter(video_filename, 'Motion JPEG AVI');
            video_writer.FrameRate = VIDEO_FRAME_RATE;
            video_writer.Quality = VIDEO_QUALITY;
            open(video_writer);
            fprintf('Recording A* visualization to: %s\n', video_filename);
            fprintf('  Frame rate: %d fps, Quality: %d%%, Early: %d iters, Interval: %d\n', ...
                    VIDEO_FRAME_RATE, VIDEO_QUALITY, EARLY_RECORD_ITERATIONS, MAIN_RECORD_INTERVAL);
        catch
            try
                % Fallback to uncompressed AVI
                video_writer = VideoWriter(video_filename, 'Uncompressed AVI');
                video_writer.FrameRate = VIDEO_FRAME_RATE;
                open(video_writer);
                fprintf('Recording A* visualization to: %s (uncompressed)\n', video_filename);
                fprintf('  Frame rate: %d fps, Early: %d iters, Interval: %d\n', ...
                        VIDEO_FRAME_RATE, EARLY_RECORD_ITERATIONS, MAIN_RECORD_INTERVAL);
            catch
                fprintf('Warning: Could not set up video recording. Continuing without recording.\n');
                video_writer = [];
            end
        end
    else
        video_writer = [];
    end
    
    % Setup visualization if enabled
    if ENABLE_VISUALIZATION
        % Get all monitor positions
        monitor_positions = get(0, 'MonitorPositions');

            fig_x = monitor_positions(3)-1300;
            fig_y = monitor_positions(4)-10;
    
        
        % Create figure with proper size specification on main monitor
        fig = figure('Name', 'A* Algorithm Visualization', ...
                    'Position', [fig_x, fig_y, 1200, 600], ...
                    'Units', 'pixels');
        
        % Subsample for visualization (every 5th cell for performance)
        vis_subsample = 5;
        if rows > 200 || cols > 200
            occ_vis = obstacle_map(1:vis_subsample:end, 1:vis_subsample:end);
            vis_scale = vis_subsample;
        else
            occ_vis = obstacle_map;
            vis_scale = 1;
        end
        [rows_vis, cols_vis] = size(occ_vis);
        
        % Create visualization matrices
        closed_viz = zeros(rows_vis, cols_vis);
        
        % Setup subplot
        subplot(1,2,1);
        imagesc(occ_vis);
        colormap(gray);
        hold on;
        
        % Plot start and goal on visualization
        start_vis = round(start / vis_scale);
        goal_vis = round(goal / vis_scale);
        plot(start_vis(2), start_vis(1), 'gs', 'MarkerSize', 12, 'LineWidth', 3, 'MarkerFaceColor', 'green');
        plot(goal_vis(2), goal_vis(1), 'rs', 'MarkerSize', 12, 'LineWidth', 3, 'MarkerFaceColor', 'red');
        
        title('A* Algorithm Progress');
        xlabel('Column (X)');
        ylabel('Row (Y)');
    end
    
    fprintf('\n=== A* ALGORITHM DEBUG ===\n');
    fprintf('Grid size: %dx%d\n', rows, cols);
    fprintf('Start: [%d, %d], Goal: [%d, %d]\n', start(1), start(2), goal(1), goal(2));
    
    % Check start and goal positions
    if obstacle_map(start(1), start(2)) >= 0.5
        fprintf('ERROR: Start position [%d,%d] is OCCUPIED (value: %.3f)\n', start(1), start(2), obstacle_map(start(1), start(2)));
        path = [];
        return;
    else
        fprintf('Start position [%d,%d] is FREE (value: %.3f)\n', start(1), start(2), obstacle_map(start(1), start(2)));
    end
    
    if obstacle_map(goal(1), goal(2)) >= 0.5
        fprintf('ERROR: Goal position [%d,%d] is OCCUPIED (value: %.3f)\n', goal(1), goal(2), obstacle_map(goal(1), goal(2)));
        path = [];
        return;
    else
        fprintf('Goal position [%d,%d] is FREE (value: %.3f)\n', goal(1), goal(2), obstacle_map(goal(1), goal(2)));
    end
    
    % Count free vs occupied cells
    free_cells = sum(obstacle_map(:) < 0.5);
    occupied_cells = sum(obstacle_map(:) >= 0.5);
    total_cells = rows * cols;
    fprintf('Map statistics: %d free, %d occupied, %d total (%.1f%% free)\n', ...
            free_cells, occupied_cells, total_cells, 100*free_cells/total_cells);
    
    % Initialize
    open_set = [start, 0, heuristic(start, goal)]; % [r, c, g_score, f_score]
    closed_set = false(rows, cols);
    came_from = zeros(rows, cols, 2);
    g_score = inf(rows, cols);
    g_score(start(1), start(2)) = 0;
    
    fprintf('A* initialization complete, starting search...\n');
    
    directions = [-1,0; 1,0; 0,-1; 0,1; -1,-1; -1,1; 1,-1; 1,1];
    costs = [1, 1, 1, 1, sqrt(2), sqrt(2), sqrt(2), sqrt(2)];
    
    iterations = 0;
    pause(0.05)
    while size(open_set, 1) > 0
        iterations = iterations + 1;
        
        % Find node with lowest f_score
        [~, idx] = min(open_set(:, 4));
        current = open_set(idx, 1:2);
        current_f = open_set(idx, 4);
        open_set(idx, :) = [];
        
        % Update visualization based on adjustable intervals
        should_record = false;
        if iterations <= EARLY_RECORD_ITERATIONS
            should_record = true;  % Record every iteration early on
        elseif mod(iterations, MAIN_RECORD_INTERVAL) == 0
            should_record = true;  % Record every N iterations during main search
        end
        
        if ENABLE_VISUALIZATION && should_record
            % Mark current cell as explored
            current_vis = round(current / vis_scale);
            if current_vis(1) >= 1 && current_vis(1) <= rows_vis && current_vis(2) >= 1 && current_vis(2) <= cols_vis
                closed_viz(current_vis(1), current_vis(2)) = 1;
            end
            
            % Update main plot
            subplot(1,2,1);
            cla;
            imagesc(occ_vis);
            colormap(gray);
            hold on;
            
            % Show explored areas (cyan overlay)
            explored_overlay = closed_viz;
            explored_overlay(explored_overlay == 0) = NaN;
            h_explored = imagesc(explored_overlay, 'AlphaData', 0.4);
            colormap([gray(256); [0, 0.8, 0.8]]); % Cyan for explored
            
            % Show some open set cells (yellow dots) - collect handles
            h_open = [];
            for i = 1:min(50, size(open_set, 1))  % Show max 50 for performance
                open_vis = round(open_set(i, 1:2) / vis_scale);
                if open_vis(1) >= 1 && open_vis(1) <= rows_vis && open_vis(2) >= 1 && open_vis(2) <= cols_vis
                    h_temp = plot(open_vis(2), open_vis(1), 'yo', 'MarkerSize', 2);
                    if isempty(h_open)
                        h_open = h_temp; % Keep only first handle for legend
                    end
                end
            end
            
            % Show current position (magenta)
            h_current = plot(current_vis(2), current_vis(1), 'mo', 'MarkerSize', 8, 'LineWidth', 2);
            
            % Plot start and goal
            h_start = plot(start_vis(2), start_vis(1), 'gs', 'MarkerSize', 12, 'LineWidth', 3, 'MarkerFaceColor', 'green');
            h_goal = plot(goal_vis(2), goal_vis(1), 'rs', 'MarkerSize', 12, 'LineWidth', 3, 'MarkerFaceColor', 'red');
            
            % Create legend with proper handles
            legend_handles = [h_start, h_goal, h_current];
            legend_labels = {'Start', 'Goal', 'Current'};
            
            if ~isempty(h_open)
                legend_handles = [legend_handles, h_open];
                legend_labels = [legend_labels, {'Open Set'}];
            end
            
            legend(legend_handles, legend_labels, 'Location', 'best');
            
            % Update statistics subplot
            subplot(1,2,2);
            cla;
            stats_text = {
                sprintf('Iteration: %d', iterations);
                sprintf('Current: [%d, %d]', current(1), current(2));
                sprintf('f-score: %.2f', current_f);
                sprintf('Open set: %d cells', size(open_set, 1));
                sprintf('Explored: %d cells', sum(closed_viz(:)));
                sprintf('Dist to goal: %.1f', heuristic(current, goal));
                '';
                'How A* works:';
                '• Explores most promising';
                '  cells first (lowest f-score)';
                '• f = g + h where:';
                '  - g = distance from start';
                '  - h = estimate to goal';
            };
            
            text(0.05, 0.95, stats_text, 'Units', 'normalized', 'VerticalAlignment', 'top', ...
                 'FontSize', 10, 'FontName', 'FixedWidth');
            set(gca, 'XTick', [], 'YTick', []);
            title('A* Algorithm Stats');
            
            drawnow;
            
            % Capture video frame
            if ~isempty(video_writer)
                frame = getframe(gcf);
                writeVideo(video_writer, frame);
            end
            
            pause(0.05);  % Small pause for smooth animation
        end
        
        if current(1) == goal(1) && current(2) == goal(2)
            % Reconstruct path
            fprintf('A* SUCCESS: Goal reached after %d iterations!\n', iterations);
            path = [];
            while ~(current(1) == start(1) && current(2) == start(2))
                path = [current; path];
                parent = squeeze(came_from(current(1), current(2), :))';
                current = parent;
            end
            path = [start; path];
            fprintf('Path found with %d waypoints\n', size(path, 1));
            
            % Plot final waypoints on the visualization figure if enabled
            if ENABLE_VISUALIZATION
                fprintf('Plotting final path with %d points...\n', size(path, 1));
                
                % Scale path coordinates to match the compressed visualization grid
                scaled_path = round(path / vis_scale);
                
                % Plot on the compressed grid subplot
                subplot(1,2,1);
                hold on;
                plot(scaled_path(:,2), scaled_path(:,1), 'r-', 'LineWidth', 6);
                plot(scaled_path(:,2), scaled_path(:,1), 'ro', 'MarkerSize', 8, 'MarkerFaceColor', 'red', 'MarkerEdgeColor', 'white', 'LineWidth', 2);
                title('Grid View - PATH FOUND!', 'Color', 'green', 'FontWeight', 'bold');
                
                % Force display update
                drawnow;
                pause(1); % Pause so you can see it before video recording starts
                
                fprintf('Final path plotted on compressed grid (scale factor: %d)\n', vis_scale);
            end
            
            
            % Record final frames showing the complete path
            if ~isempty(video_writer)
                final_frames = VIDEO_FRAME_RATE * FINAL_RECORD_DURATION;
                for i = 1:final_frames
                    frame = getframe(gcf);
                    writeVideo(video_writer, frame);
                end
                close(video_writer);
                fprintf('Video saved: %s\n', video_filename);
            end
            
            return;
        end
        
        closed_set(current(1), current(2)) = true;
        
        % Explore neighbors
        for d = 1:size(directions, 1)
            neighbor = current + directions(d, :);
            
            if neighbor(1) < 1 || neighbor(1) > rows || neighbor(2) < 1 || neighbor(2) > cols
                continue;
            end
            
            if closed_set(neighbor(1), neighbor(2)) || obstacle_map(neighbor(1), neighbor(2)) >= 0.5
                continue;
            end
            
            tentative_g = g_score(current(1), current(2)) + costs(d);
            
            if tentative_g < g_score(neighbor(1), neighbor(2))
                came_from(neighbor(1), neighbor(2), :) = current;
                g_score(neighbor(1), neighbor(2)) = tentative_g;
                f_score = tentative_g + heuristic(neighbor, goal);
                
                % Add to open set if not already there
                in_open = false;
                for j = 1:size(open_set, 1)
                    if open_set(j, 1) == neighbor(1) && open_set(j, 2) == neighbor(2)
                        open_set(j, :) = [neighbor, tentative_g, f_score];
                        in_open = true;
                        break;
                    end
                end
                
                if ~in_open
                    open_set = [open_set; neighbor, tentative_g, f_score];
                end
            end
        end
    end
    
    % A* failed - determine why
    fprintf('\nA* FAILED after %d iterations!\n', iterations);
    
    if size(open_set, 1) == 0
        fprintf('REASON: Open set is empty - no more nodes to explore\n');
        fprintf('This means:\n');
        fprintf('  - Goal is unreachable from start\n');
        fprintf('  - All paths are blocked by obstacles\n');
        fprintf('  - Start and goal are in separate disconnected regions\n');
    end
    
    fprintf('Final search statistics:\n');
    fprintf('  - Iterations: %d\n', iterations);
    fprintf('  - Nodes explored: %d\n', sum(closed_set(:)));
    fprintf('  - Open set size: %d\n', size(open_set, 1));
    fprintf('  - Distance to goal: %.2f units\n', heuristic(current, goal));
    
    % Close video if recording
    if ~isempty(video_writer)
        close(video_writer);
        fprintf('Video saved (incomplete): %s\n', video_filename);
    end
    
    path = []; % No path found
end

function h = heuristic(a, b)
    % Euclidean distance heuristic
    h = sqrt((a(1) - b(1))^2 + (a(2) - b(2))^2);
end