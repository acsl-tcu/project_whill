%% Visualize Flood Fill Steps - See How Paint Spreads
% This shows the flood fill algorithm step by step to debug spreading issues

clear; close all; clc;

fprintf('=== Flood Fill Step-by-Step Visualization ===\n\n');

%% Initialize
painter = FloodFillROI('../map2.mat');

if isempty(painter.getOccupancyMap())
    error('Failed to load map2.mat');
end

fprintf('Click on a position to see step-by-step flood fill animation\n\n');

%% Interactive step visualization
fig = figure('Name', 'Flood Fill Animation - Click to See Steps', 'Position', [50, 50, 1400, 900]);

show(painter.getOccupancyMap());
hold on;
title('Click anywhere to see flood fill animation', 'FontSize', 16, 'FontWeight', 'bold');
xlabel('X (m)'); ylabel('Y (m)');
grid on; axis equal;

try
    while ishandle(fig)
        % Wait for click
        [x_click, y_click] = ginput(1);
        
        if isempty(x_click)
            break;
        end
        
        fprintf('🎬 Starting flood fill animation at [%.2f, %.2f]\n', x_click, y_click);
        
        % Clear previous results
        cla;
        show(painter.getOccupancyMap());
        hold on;
        
        % Animate the flood fill process
        animateFloodFill(painter, [x_click, y_click]);
        
        fprintf('Animation complete! Click elsewhere for another animation.\n\n');
    end
    
catch ME
    if ~strcmp(ME.identifier, 'MATLAB:ginput:Interrupted')
        fprintf('Animation ended: %s\n', ME.message);
    end
end

function animateFloodFill(painter, robot_pos)
    % Animate flood fill step by step
    
    max_distance = 100;
    wall_threshold = 0.5;
    
    % Get map properties
    map = painter.getOccupancyMap();
    occupancyMatrix = painter.getOccupancyMatrix();
    [rows, cols] = size(occupancyMatrix);
    
    % Convert to grid coordinates
    robot_grid = world2grid(map, robot_pos);
    start_row = round(robot_grid(1));
    start_col = round(robot_grid(2));
    
    % Validate starting position
    if start_row < 1 || start_row > rows || start_col < 1 || start_col > cols
        fprintf('Position outside map bounds!\n');
        return;
    end
    
    if occupancyMatrix(start_row, start_col) >= wall_threshold
        fprintf('Starting position is occupied (%.3f >= %.3f)\n', ...
            occupancyMatrix(start_row, start_col), wall_threshold);
        return;
    end
    
    fprintf('Starting animation from grid [%d, %d]\n', start_row, start_col);
    
    % Initialize flood fill
    visited = false(rows, cols);
    room_cells = [start_row, start_col];
    visited(start_row, start_col) = true;
    
    % Use queue for breadth-first search (shows spreading pattern better)
    queue = [start_row, start_col, 0]; % [row, col, distance]
    
    step = 0;
    colors = lines(10); % Different colors for different distances
    
    % Plot starting point
    start_world = grid2world(map, [start_row, start_col]);
    plot(robot_pos(1), robot_pos(2), 'ro', 'MarkerSize', 15, 'LineWidth', 3);
    scatter(start_world(1), start_world(2), 100, 'red', 'filled', 'MarkerEdgeColor', 'black');
    
    title(sprintf('Step %d: Starting point at [%d, %d]', step, start_row, start_col));
    drawnow;
    pause(1);
    
    % Animation loop
    while ~isempty(queue) && step < 50 % Limit steps for visualization
        step = step + 1;
        
        % Process one level of the queue (all cells at same distance)
        current_distance = queue(1, 3);
        cells_at_this_distance = [];
        
        % Get all cells at current distance
        while ~isempty(queue) && queue(1, 3) == current_distance
            current = queue(1, :);
            queue(1, :) = [];
            
            curr_row = current(1);
            curr_col = current(2);
            curr_dist = current(3);
            
            % Check 4-connected neighbors
            neighbors = [
                curr_row-1, curr_col;  % Up
                curr_row+1, curr_col;  % Down  
                curr_row, curr_col-1;  % Left
                curr_row, curr_col+1   % Right
            ];
            
            for i = 1:size(neighbors, 1)
                nr = neighbors(i, 1);
                nc = neighbors(i, 2);
                new_dist = curr_dist + 1;
                
                % Check if we can spread to this cell
                if nr >= 1 && nr <= rows && nc >= 1 && nc <= cols && ...
                   ~visited(nr, nc) && ...
                   occupancyMatrix(nr, nc) < wall_threshold && ...
                   new_dist <= max_distance
                    
                    visited(nr, nc) = true;
                    room_cells = [room_cells; nr, nc];
                    queue = [queue; nr, nc, new_dist];
                    cells_at_this_distance = [cells_at_this_distance; nr, nc];
                end
            end
        end
        
        % Visualize cells added in this step
        if ~isempty(cells_at_this_distance)
            world_coords = grid2world(map, cells_at_this_distance);
            color_idx = mod(current_distance, size(colors, 1)) + 1;
            
            scatter(world_coords(:,1), world_coords(:,2), 30, colors(color_idx, :), 'filled', ...
                'MarkerFaceAlpha', 0.8, 'MarkerEdgeColor', 'black', 'LineWidth', 0.5);
            
            title(sprintf('Step %d: Distance %d - Added %d cells (Total: %d)', ...
                step, current_distance, size(cells_at_this_distance, 1), size(room_cells, 1)));
            
            fprintf('  Step %d: Distance %d, added %d cells\n', step, current_distance, size(cells_at_this_distance, 1));
            
            drawnow;
            pause(0.5); % Slower animation to see spreading
        end
        
        % Stop if no more expansion
        if isempty(queue)
            break;
        end
    end
    
    % Final result
    title(sprintf('Final Result: %d cells painted, max distance %d reached', ...
        size(room_cells, 1), max([0; room_cells(:,1) - start_row; room_cells(:,2) - start_col])));
    
    % Add legend
    legend_entries = arrayfun(@(d) sprintf('Distance %d', d), 0:min(step-1, 9), 'UniformOutput', false);
    legend(['Start Point', legend_entries], 'Location', 'best', 'FontSize', 8);
    
    fprintf('Final result: %d cells painted\n', size(room_cells, 1));
    
    % Analyze spreading pattern
    distances_x = abs(room_cells(:, 2) - start_col);
    distances_y = abs(room_cells(:, 1) - start_row);
    max_spread_x = max(distances_x);
    max_spread_y = max(distances_y);
    
    fprintf('Spreading analysis:\n');
    fprintf('  Max spread X-direction: %d cells\n', max_spread_x);
    fprintf('  Max spread Y-direction: %d cells\n', max_spread_y);
    
    if max_spread_x < 5 && max_spread_y < 5
        fprintf('  ⚠️  Very limited spreading - check wall_threshold or map quality\n');
    elseif abs(max_spread_x - max_spread_y) > 10
        fprintf('  ⚠️  Uneven spreading - may indicate walls or obstacles\n');
    else
        fprintf('  ✅  Good radial spreading pattern\n');
    end
end