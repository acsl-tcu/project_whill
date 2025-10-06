%% Improved Room Painting Test - Better Parameters for Full Room Coverage
% This version uses optimized parameters to paint entire rooms

clear; close all; clc;

fprintf('=== Improved Room Painting Test ===\n\n');

%% Initialize with better default parameters
painter = FloodFillROI('../map2.mat');

if isempty(painter.getOccupancyMap())
    error('Failed to load map2.mat');
end

% Get map info for parameter optimization
resolution = painter.getGridResolution();
fprintf('Map resolution: %.4f m/cell\n', resolution);
fprintf('Optimizing parameters for better room coverage...\n\n');

% Improved parameters based on typical room sizes
max_distance = 200;      % Increased from 100 - allows ~8-40m radius depending on resolution
wall_threshold = 0.4;    % Lowered from 0.5 - less aggressive wall detection

fprintf('Using improved parameters:\n');
fprintf('  Max distance: %d grid cells (~%.1f m radius)\n', max_distance, max_distance * resolution);
fprintf('  Wall threshold: %.1f (lower = more area painted)\n\n', wall_threshold);

%% Interactive painting with better parameters
fig = figure('Name', 'Improved Room Painting - Full Coverage', 'Position', [100, 100, 1200, 900]);

show(painter.getOccupancyMap());
hold on;

title('Improved Room Painting - Click anywhere for full room coverage', 'FontSize', 16, 'FontWeight', 'bold');
xlabel('X (m)'); ylabel('Y (m)');
grid on; axis equal;

% Instructions
instruction_text = text(0.02, 0.98, ...
    {'IMPROVED ROOM PAINTING', '', ...
     sprintf('Max distance: %d cells', max_distance), ...
     sprintf('Wall threshold: %.1f', wall_threshold), ...
     '• Click anywhere to paint full room', ...
     '• Should now cover entire connected areas', ...
     '', 'Close figure to exit'}, ...
    'Units', 'normalized', 'VerticalAlignment', 'top', ...
    'BackgroundColor', 'yellow', 'EdgeColor', 'black', 'FontSize', 11, ...
    'FontWeight', 'bold');

% Enhanced color palette
colors = {'cyan', 'magenta', [0 0.8 0], 'red', 'blue', [1 0.5 0], [1 0.7 0.8], [0.5 0 0.5]};
color_index = 1;

painted_areas = [];
total_painted_cells = 0;

%% Improved painting loop
try
    while ishandle(fig)
        [x_click, y_click] = ginput(1);
        
        if isempty(x_click)
            break;
        end
        
        fprintf('🎨 Painting room at [%.2f, %.2f] with improved parameters...\n', x_click, y_click);
        
        current_color = colors{color_index};
        
        % Use improved parameters
        tic;
        [~, room_cells] = painter.getFloodFillROI([x_click, y_click], max_distance, wall_threshold);
        paint_time = toc;
        
        if isempty(room_cells)
            fprintf('❌ No room found! Try adjusting parameters.\n');
            
            % Try even more aggressive parameters
            fprintf('   Trying more aggressive parameters...\n');
            [~, room_cells] = painter.getFloodFillROI([x_click, y_click], 300, 0.3);
            
            if isempty(room_cells)
                fprintf('   Still no room found - may be in occupied area\n');
                continue;
            else
                fprintf('   Success with aggressive parameters!\n');
            end
        end
        
        % Convert to world coordinates and paint
        world_coords = grid2world(painter.getOccupancyMap(), room_cells);
        
        % Paint with larger dots for better visibility
        scatter(world_coords(:,1), world_coords(:,2), 25, current_color, 'filled', ...
            'MarkerFaceAlpha', 0.8, ...
            'DisplayName', sprintf('Room %d (%d cells)', color_index, size(room_cells, 1)));
        
        % Mark click position
        plot(x_click, y_click, 'ko', 'MarkerSize', 12, 'LineWidth', 3, ...
            'MarkerFaceColor', 'white');
        
        % Calculate statistics
        room_area = size(room_cells, 1) * (resolution^2);
        total_painted_cells = total_painted_cells + size(room_cells, 1);
        
        % Estimate room dimensions
        world_x = world_coords(:,1);
        world_y = world_coords(:,2);
        room_width = max(world_x) - min(world_x);
        room_height = max(world_y) - min(world_y);
        
        fprintf('✅ Painted %d cells (%.1f m²) in %.3f sec\n', ...
            size(room_cells, 1), room_area, paint_time);
        fprintf('   Room dimensions: %.1f x %.1f m\n', room_width, room_height);
        
        % Store results
        painted_areas(end+1) = struct('position', [x_click, y_click], ...
                                     'cells', size(room_cells, 1), ...
                                     'area_m2', room_area, ...
                                     'dimensions', [room_width, room_height], ...
                                     'color', current_color, ...
                                     'time', paint_time);
        
        % Update title with progress
        title(sprintf('Improved Room Painting - %d rooms, %d cells (%.1f m²)', ...
            length(painted_areas), total_painted_cells, ...
            total_painted_cells * (resolution^2)), ...
            'FontSize', 14, 'FontWeight', 'bold');
        
        % Update instructions
        delete(instruction_text);
        color_name = current_color;
        if isnumeric(current_color)
            color_name = sprintf('[%.1f %.1f %.1f]', current_color(1), current_color(2), current_color(3));
        end
        
        instruction_text = text(0.02, 0.98, ...
            {'IMPROVED ROOM PAINTING', '', ...
             sprintf('Rooms painted: %d', length(painted_areas)), ...
             sprintf('Total area: %.1f m²', total_painted_cells * (resolution^2)), ...
             sprintf('Avg room size: %.1f m²', (total_painted_cells * (resolution^2)) / length(painted_areas)), ...
             sprintf('Last room: %.1f x %.1f m', room_width, room_height), ...
             '', '• Click for more rooms', '• Close to finish'}, ...
            'Units', 'normalized', 'VerticalAlignment', 'top', ...
            'BackgroundColor', 'yellow', 'EdgeColor', 'black', 'FontSize', 10, ...
            'FontWeight', 'bold');
        
        % Next color
        color_index = mod(color_index, length(colors)) + 1;
        
        drawnow;
        fprintf('\n');
    end
    
catch ME
    if ~strcmp(ME.identifier, 'MATLAB:ginput:Interrupted')
        fprintf('Painting ended: %s\n', ME.message);
    end
end

%% Final summary
if ~isempty(painted_areas)
    fprintf('=== Final Results ===\n');
    fprintf('Rooms painted: %d\n', length(painted_areas));
    fprintf('Total area: %.1f m²\n', total_painted_cells * (resolution^2));
    fprintf('Average room size: %.1f m²\n', mean([painted_areas.area_m2]));
    fprintf('Largest room: %.1f m²\n', max([painted_areas.area_m2]));
    fprintf('Average painting time: %.3f sec\n', mean([painted_areas.time]));
    
    fprintf('\nRoom details:\n');
    for i = 1:length(painted_areas)
        fprintf('  Room %d: %.1f m² (%.1f x %.1f m) at [%.1f, %.1f]\n', ...
            i, painted_areas(i).area_m2, painted_areas(i).dimensions(1), painted_areas(i).dimensions(2), ...
            painted_areas(i).position(1), painted_areas(i).position(2));
    end
    
    if mean([painted_areas.area_m2]) > 50
        fprintf('\n✅ Room painting improved! Larger areas detected.\n');
    else
        fprintf('\n⚠️  Still small areas. Try debug script to analyze further.\n');
    end
else
    fprintf('\nNo rooms painted. Run debugFloodFill.m to analyze the issue.\n');
end

fprintf('\nTip: Run debugFloodFill.m to analyze why some rooms arent fully painted.\n');