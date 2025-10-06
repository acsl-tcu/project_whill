function visualize_inflation(robot_width, robot_length, safety_margin)
% VISUALIZE_INFLATION - Visualization of current obstacle inflation method
% 
% Usage:
%   visualize_inflation()                    % Use default wheelchair size
%   visualize_inflation(0.6, 1.0, 0.8)     % Custom dimensions
%
% This function loads the map and shows the current inflation method used
% in PathSetting_AStar.m with detailed analysis

    if nargin < 3
        % Default wheelchair dimensions
        robot_width = 0.6;     % meters
        robot_length = 1.0;    % meters  
        safety_margin = 0.8;   % meters
    end
    
    fprintf('=== OBSTACLE INFLATION VISUALIZATION ===\n');
    fprintf('Robot dimensions: %.2fm × %.2fm\n', robot_width, robot_length);
    fprintf('Safety margin: %.2fm\n', safety_margin);
    fprintf('Loading map...\n');
    
    % Load the occupancy map
    try
        map_data = load('map2.mat');
        map_obj = map_data.map;
        occ_matrix = getOccupancy(map_obj);
        resolution = map_obj.Resolution;
        
        fprintf('Map loaded successfully:\n');
        fprintf('  Size: %dx%d cells\n', size(occ_matrix,1), size(occ_matrix,2));
        fprintf('  Resolution: %.0f cells/meter\n', resolution);
        fprintf('  World limits: X[%.1f,%.1f], Y[%.1f,%.1f]\n', ...
                map_obj.XWorldLimits, map_obj.YWorldLimits);
    catch ME
        fprintf('Error loading map2.mat: %s\n', ME.message);
        return;
    end
    
    % Calculate clearance using current method from PathSetting_AStar.m
    fprintf('\n=== CLEARANCE CALCULATION ===\n');
    
    robot_clearance = max(robot_width, robot_length) + safety_margin;
    clearance_cells = ceil(robot_clearance * resolution / 2) + 1;
    
    fprintf('Current inflation method:\n');
    fprintf('  robot_clearance = max(%.2f, %.2f) + %.2f = %.2fm\n', ...
            robot_width, robot_length, safety_margin, robot_clearance);
    fprintf('  clearance_cells = ceil(%.2f * %.0f / 2) + 1 = %d cells\n', ...
            robot_clearance, resolution, clearance_cells);
    fprintf('  Actual clearance distance = %d / %.0f = %.2fm\n', ...
            clearance_cells, resolution, clearance_cells/resolution);
    
    % Perform inflation
    fprintf('\n=== PERFORMING INFLATION ===\n');
    fprintf('Inflating obstacles with %d cells clearance...\n', clearance_cells);
    tic;
    inflated_map = inflateMapSquare(occ_matrix, clearance_cells);
    inflation_time = toc;
    fprintf('Inflation completed in %.3f seconds\n', inflation_time);
    
    % Calculate statistics
    original_occupied = sum(occ_matrix(:) >= 0.5);
    inflated_occupied = sum(inflated_map(:) >= 0.5);
    total_cells = numel(occ_matrix);
    
    fprintf('\n=== INFLATION STATISTICS ===\n');
    fprintf('Original occupied cells: %d (%.2f%%)\n', ...
            original_occupied, 100*original_occupied/total_cells);
    fprintf('Inflated occupied cells: %d (%.2f%%)\n', ...
            inflated_occupied, 100*inflated_occupied/total_cells);
    fprintf('Inflation growth factor: %.2fx\n', inflated_occupied/original_occupied);
    fprintf('Added occupied cells: %d\n', inflated_occupied - original_occupied);
    
    % Create visualization
    fprintf('\n=== CREATING VISUALIZATION ===\n');
    
    % Focus on an interesting corridor region 
    row_range = 300:500;  
    col_range = 1000:1400; 
    
    % Extract regions for display
    occ_region = occ_matrix(row_range, col_range);
    inflated_region = inflated_map(row_range, col_range);
    
    % Create main figure
    fig = figure('Name', 'Current Obstacle Inflation Method', ...
                 'Position', [100, 100, 1400, 800]);
    
    % Subplot 1: Original map
    subplot(2,3,1);
    imagesc(occ_region);
    colormap(gray);
    title('Original Occupancy Grid');
    xlabel('Columns');
    ylabel('Rows');
    colorbar;
    axis equal tight;
    
    % Subplot 2: Inflated map
    subplot(2,3,2);
    imagesc(inflated_region);
    colormap(gray);
    title(sprintf('After Inflation (%d cells)', clearance_cells));
    xlabel('Columns');
    ylabel('Rows');
    colorbar;
    axis equal tight;
    
    % Subplot 3: Difference (what was added)
    subplot(2,3,3);
    diff_region = inflated_region - occ_region;
    imagesc(diff_region);
    colormap(gray);
    title('Added by Inflation');
    xlabel('Columns');
    ylabel('Rows');
    colorbar;
    axis equal tight;
    
    % Subplot 4: Side-by-side comparison
    subplot(2,3,4);
    comparison = zeros(size(occ_region,1), size(occ_region,2), 3);
    comparison(:,:,1) = occ_region;      % Original in red
    comparison(:,:,2) = inflated_region; % Inflated in green
    comparison(:,:,3) = occ_region;      % Original in blue
    
    imshow(comparison);
    title('Overlay: Green=Inflated, Red/Blue=Original');
    
    % Subplot 5: Full map overview
    subplot(2,3,5);
    % Subsample for overview
    step = 10;
    overview_orig = occ_matrix(1:step:end, 1:step:end);
    overview_inflated = inflated_map(1:step:end, 1:step:end);
    
    imagesc(overview_inflated - overview_orig);
    colormap(gray);
    title('Full Map: Inflation Effect');
    xlabel('Columns (subsampled)');
    ylabel('Rows (subsampled)');
    colorbar;
    
    % Draw rectangle showing zoomed region
    hold on;
    zoom_rect = [col_range(1)/step, row_range(1)/step, ...
                 (col_range(end)-col_range(1))/step, (row_range(end)-row_range(1))/step];
    rectangle('Position', zoom_rect, 'EdgeColor', 'red', 'LineWidth', 2);
    text(zoom_rect(1), zoom_rect(2)-10, 'Zoomed Area', 'Color', 'red', 'FontWeight', 'bold');
    
    % Subplot 6: Information panel
    subplot(2,3,6);
    axis off;
    
    info_text = {
        '=== WHEELCHAIR DIMENSIONS ===';
        sprintf('Width: %.2fm', robot_width);
        sprintf('Length: %.2fm', robot_length);
        sprintf('Safety margin: %.2fm', safety_margin);
        '';
        '=== INFLATION CALCULATION ===';
        sprintf('Robot clearance: %.2fm', robot_clearance);
        sprintf('Grid resolution: %.0f cells/m', resolution);
        sprintf('Clearance cells: %d', clearance_cells);
        sprintf('Actual clearance: %.2fm', clearance_cells/resolution);
        '';
        '=== MAP STATISTICS ===';
        sprintf('Map size: %dx%d cells', size(occ_matrix,1), size(occ_matrix,2));
        sprintf('Original occupied: %d cells', original_occupied);
        sprintf('After inflation: %d cells', inflated_occupied);
        sprintf('Growth factor: %.2fx', inflated_occupied/original_occupied);
        sprintf('Processing time: %.3fs', inflation_time);
        '';
        '=== INFLATION METHOD ===';
        'Square inflation algorithm:';
        '• For each occupied cell';
        '• Mark square region around it';
        '• Size = clearance_cells × clearance_cells';
        '';
        '=== COLOR LEGEND ===';
        'Black = Free space (value < 0.5)';
        'White = Occupied (value ≥ 0.5)';
        'Green overlay = Inflated areas';
    };
    
    text(0.05, 0.95, info_text, 'Units', 'normalized', 'VerticalAlignment', 'top', ...
         'FontSize', 9, 'FontName', 'FixedWidth');
    
    % Add main title
    sgtitle(sprintf('Obstacle Inflation Analysis - Current Method\nRobot: %.1fm×%.1fm + %.1fm safety → %d cells clearance', ...
                   robot_width, robot_length, safety_margin, clearance_cells), ...
                   'FontSize', 14, 'FontWeight', 'bold');
    
    fprintf('Visualization complete!\n');
    fprintf('\nKEY INSIGHTS:\n');
    fprintf('• Each obstacle grows by %d cells in all directions\n', clearance_cells);
    fprintf('• This creates %.2fm clearance around obstacles\n', clearance_cells/resolution);
    fprintf('• Square inflation method creates blocky expansion\n');
    fprintf('• Green areas show where wheelchair cannot travel\n');
    
    % Save the visualization
    timestamp = datestr(now, 'yyyymmdd_HHMMSS');
    filename = sprintf('inflation_analysis_%s.png', timestamp);
    
    try
        saveas(fig, filename);
        fprintf('\nVisualization saved as: %s\n', filename);
    catch
        fprintf('Could not save figure automatically.\n');
    end
    
    % Create a detailed zoom view
    create_zoom_view(occ_region, inflated_region, clearance_cells, resolution);
    
end

function inflated_map = inflateMapSquare(occ_matrix, clearance)
    % Current square inflation implementation from PathSetting_AStar.m
    [rows, cols] = size(occ_matrix);
    inflated_map = occ_matrix;
    
    for r = 1:rows
        for c = 1:cols
            if occ_matrix(r, c) >= 0.5
                r_min = max(1, r - clearance);
                r_max = min(rows, r + clearance);
                c_min = max(1, c - clearance);
                c_max = min(cols, c + clearance);
                
                inflated_map(r_min:r_max, c_min:c_max) = 1;
            end
        end
    end
end

function create_zoom_view(occ_region, inflated_region, clearance_cells, resolution)
    % Create a detailed cell-level view
    
    % Find center of region
    [rows, cols] = size(occ_region);
    center_r = round(rows/2);
    center_c = round(cols/2);
    
    % Extract small area for detailed view
    detail_size = 25;
    r_range = max(1, center_r-detail_size):min(rows, center_r+detail_size);
    c_range = max(1, center_c-detail_size):min(cols, center_c+detail_size);
    
    detail_orig = occ_region(r_range, c_range);
    detail_inflated = inflated_region(r_range, c_range);
    
    % Create detailed figure
    figure('Name', 'Cell-Level Detail View', 'Position', [300, 300, 1000, 400]);
    
    subplot(1,2,1);
    imagesc(detail_orig);
    colormap(gray);
    title('Original (Cell Level)');
    hold on;
    % Draw grid lines to show individual cells
    [X, Y] = meshgrid(0.5:size(detail_orig,2)+0.5, 0.5:size(detail_orig,1)+0.5);
    plot(X, Y, 'b-', 'LineWidth', 0.5, 'Color', [0.3 0.3 1]);
    plot(X', Y', 'b-', 'LineWidth', 0.5, 'Color', [0.3 0.3 1]);
    axis equal tight;
    xlabel('Cell columns');
    ylabel('Cell rows');
    
    subplot(1,2,2);
    imagesc(detail_inflated);
    colormap(gray);
    title(sprintf('After %d-cell Square Inflation', clearance_cells));
    hold on;
    plot(X, Y, 'r-', 'LineWidth', 0.5, 'Color', [1 0.3 0.3]);
    plot(X', Y', 'r-', 'LineWidth', 0.5, 'Color', [1 0.3 0.3]);
    axis equal tight;
    xlabel('Cell columns');
    ylabel('Cell rows');
    
    sgtitle(sprintf('Individual Cell View (1 cell = %.1fcm)', 100/resolution), 'FontSize', 12);
    
    fprintf('Detailed cell-level view created\n');
    fprintf('Grid lines show individual cells for precise analysis\n');
end