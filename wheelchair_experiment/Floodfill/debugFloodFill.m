%% Debug Flood Fill - Analyze Why Room Isn't Fully Painted
% This script helps debug flood fill issues by showing detailed information

clear; close all; clc;

fprintf('=== Flood Fill Debug Analysis ===\n\n');

%% Initialize
painter = FloodFillROI('../map2.mat');

if isempty(painter.getOccupancyMap())
    error('Failed to load map2.mat');
end

% Get map properties
map = painter.getOccupancyMap();
matrix = painter.getOccupancyMatrix();
resolution = painter.getGridResolution();
limits = painter.getMapLimits();

fprintf('Map Properties:\n');
fprintf('  Size: %d x %d cells\n', size(matrix));
fprintf('  Resolution: %.4f m/cell\n', resolution);
fprintf('  World limits: X[%.1f, %.1f], Y[%.1f, %.1f]\n', limits);
fprintf('  Occupancy range: %.3f to %.3f\n', min(matrix(:)), max(matrix(:)));

%% Interactive debug mode
fprintf('\n=== Interactive Debug Mode ===\n');
fprintf('Click on a position to debug flood fill at that location\n\n');

fig = figure('Name', 'Flood Fill Debug - Click to Analyze', 'Position', [50, 50, 1400, 1000]);

% Create subplot layout
subplot(2, 2, 1);
show(map);
title('Original Map - Click Here to Debug');
xlabel('X (m)'); ylabel('Y (m)');
grid on; axis equal;

try
    while ishandle(fig)
        % Wait for click
        subplot(2, 2, 1);
        [x_click, y_click] = ginput(1);
        
        if isempty(x_click)
            break;
        end
        
        fprintf('🔍 Debugging flood fill at [%.2f, %.2f]\n', x_click, y_click);
        
        %% Test different parameters
        test_params = [

            20000000000, 0.5;   % Very large distance
        ];
        
        % Convert click to grid coordinates for analysis
        robot_grid = world2grid(map, [x_click, y_click]);
        start_row = round(robot_grid(1));
        start_col = round(robot_grid(2));
        
        fprintf('  Grid position: [%d, %d]\n', start_row, start_col);
        fprintf('  Occupancy at click: %.3f\n', matrix(start_row, start_col));
        
        % Analyze local area around click
        local_radius = 5;
        r_min = max(1, start_row - local_radius);
        r_max = min(size(matrix, 1), start_row + local_radius);
        c_min = max(1, start_col - local_radius);
        c_max = min(size(matrix, 2), start_col + local_radius);
        
        local_area = matrix(r_min:r_max, c_min:c_max);
        fprintf('  Local area occupancy: min=%.3f, max=%.3f, mean=%.3f\n', ...
            min(local_area(:)), max(local_area(:)), mean(local_area(:)));
        
        %% Test different flood fill parameters
        subplot(2, 2, 2); cla;
        show(map); hold on;
        plot(x_click, y_click, 'ro', 'MarkerSize', 15, 'LineWidth', 3);
        title(sprintf('Flood Fill Results at [%.1f, %.1f]', x_click, y_click));
        
        colors_debug = {'red', 'blue', 'green', 'cyan', 'magenta', 'yellow'};
        
        for i = 1:size(test_params, 1)
            max_dist = test_params(i, 1);
            wall_thresh = test_params(i, 2);
            
            [~, room_cells] = painter.getFloodFillROI([x_click, y_click], max_dist, wall_thresh);
            
            if ~isempty(room_cells)
                world_coords = grid2world(map, room_cells);
                scatter(world_coords(:,1), world_coords(:,2), 10, colors_debug{i}, 'filled', ...
                    'MarkerFaceAlpha', 0.6);
                
                fprintf('  Params [dist=%d, thresh=%.1f]: %d cells (%.1f m²)\n', ...
                    max_dist, wall_thresh, size(room_cells, 1), ...
                    size(room_cells, 1) * resolution^2);
            else
                fprintf('  Params [dist=%d, thresh=%.1f]: No cells found!\n', max_dist, wall_thresh);
            end
        end
        
        legend_entries = arrayfun(@(i) sprintf('D=%d,T=%.1f', test_params(i,1), test_params(i,2)), ...
            1:size(test_params,1), 'UniformOutput', false);
        legend(['Click Point', legend_entries], 'Location', 'best', 'FontSize', 8);
        axis equal; grid on;
        
        %% Show occupancy analysis
        subplot(2, 2, 3); cla;
        
        % Use best parameters (largest result)
        [~, room_cells] = painter.getFloodFillROI([x_click, y_click], 200, 0.5);
        
        if ~isempty(room_cells)
            % Show occupancy histogram of flooded area
            flooded_occupancy = [];
            for j = 1:size(room_cells, 1)
                flooded_occupancy(j) = matrix(room_cells(j, 1), room_cells(j, 2));
            end
            
            histogram(flooded_occupancy, 20);
            title('Occupancy Values in Flooded Area');
            xlabel('Occupancy Value'); ylabel('Number of Cells');
            grid on;
            
            % Add threshold line
            hold on;
            xline(0.5, 'r--', 'LineWidth', 2, 'DisplayName', 'Default Threshold (0.5)');
            legend();
        end
        
        %% Show distance analysis
        subplot(2, 2, 4); cla;
        
        if ~isempty(room_cells)
            % Calculate distance of each flooded cell from start
            distances = sqrt((room_cells(:, 1) - start_row).^2 + (room_cells(:, 2) - start_col).^2);
            
            scatter(distances, flooded_occupancy, 20, 'blue', 'filled', 'MarkerFaceAlpha', 0.6);
            title('Distance vs Occupancy');
            xlabel('Distance from Start (grid cells)'); ylabel('Occupancy Value');
            grid on;
            
            % Add threshold and distance limits
            hold on;
            yline(0.5, 'r--', 'LineWidth', 2, 'DisplayName', 'Wall Threshold');
            xline(50, 'g--', 'LineWidth', 2, 'DisplayName', 'Default Max Distance');
            xline(100, 'b--', 'LineWidth', 2, 'DisplayName', 'Extended Distance');
            legend('Location', 'best');
            
            fprintf('  Distance analysis:\n');
            fprintf('    Max distance reached: %.1f cells (%.2f m)\n', max(distances), max(distances)*resolution);
            fprintf('    Cells beyond 50: %d (%.1f%%)\n', sum(distances > 50), 100*sum(distances > 50)/length(distances));
            fprintf('    Cells beyond 100: %d (%.1f%%)\n', sum(distances > 100), 100*sum(distances > 100)/length(distances));
        end
        
        drawnow;
        fprintf('\n');
    end
    
catch ME
    if ~strcmp(ME.identifier, 'MATLAB:ginput:Interrupted')
        fprintf('Debug ended: %s\n', ME.message);
    end
end

fprintf('Debug analysis complete!\n');
fprintf('\nRecommendations:\n');
fprintf('• If few cells painted: Increase max_distance parameter\n');
fprintf('• If stopping at gray areas: Lower wall_threshold\n');
fprintf('• If too much painted: Raise wall_threshold\n');
fprintf('• Check occupancy histogram to find optimal threshold\n');