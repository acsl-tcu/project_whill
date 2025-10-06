%% Simple Room Painting Test - Paint Bucket Effect Demo
% This script demonstrates the flood fill "paint bucket" effect
% Click anywhere on the map to paint the room at that location

clear; close all; clc;

fprintf('=== Room Painting Test - Paint Bucket Effect ===\n\n');

%% Initialize
fprintf('Loading map and initializing flood fill...\n');

painter = FloodFillROI('../map2.mat');

if isempty(painter.getOccupancyMap())
    error('Failed to load map2.mat. Make sure it exists in the parent directory.');
end

fprintf('✓ Map loaded successfully!\n\n');

%% Interactive painting mode
fprintf('=== Interactive Room Painting ===\n');
fprintf('Click anywhere on the map to paint that room!\n');
fprintf('Each click will paint the connected room area.\n');
fprintf('Close the figure to exit.\n\n');

% Display base map
fig = figure('Name', 'Interactive Room Painting - Click to Paint!', ...
    'Position', [100, 100, 1200, 900]);

show(painter.getOccupancyMap());
hold on;

title('Click anywhere to paint the room at that location', 'FontSize', 16, 'FontWeight', 'bold');
xlabel('X (m)'); ylabel('Y (m)');
grid on; axis equal;

% Add instructions
instruction_text = text(0.02, 0.98, ...
    {'ROOM PAINTING MODE', '', ...
     '• Click anywhere to paint the room', ...
     '• Cyan dots = painted room area', ...
     '• Red circle = click position', ...
     '• Different rooms will be painted separately', ...
     '', 'Close figure to exit'}, ...
    'Units', 'normalized', 'VerticalAlignment', 'top', ...
    'BackgroundColor', 'yellow', 'EdgeColor', 'black', 'FontSize', 11, ...
    'FontWeight', 'bold');

% Color options for different rooms
colors = {'cyan', 'magenta', 'yellow', 'green', 'red', 'blue', [1 0.5 0], [1 0.7 0.8]}; % orange, pink as RGB
color_index = 1;

painted_areas = []; % Store painted room info
total_painted_cells = 0;

%% Interactive painting loop
try
    while ishandle(fig)
        % Wait for user click
        [x_click, y_click] = ginput(1);
        
        if isempty(x_click) % User closed figure or pressed Enter
            break;
        end
        
        fprintf('\n🎨 Painting room at [%.2f, %.2f]...\n', x_click, y_click);
        
        % Get current color
        current_color = colors{color_index};
        
        % Get flood filled cells for this position
        [~, room_cells] = painter.getFloodFillROI([x_click, y_click], 100, 0.5);
        
        if isempty(room_cells)
            fprintf('❌ No room found at clicked position!\n');
            continue;
        end
        
        % Convert to world coordinates
        world_coords = grid2world(painter.getOccupancyMap(), room_cells);
        
        % Paint the room cells
        scatter(world_coords(:,1), world_coords(:,2), 15, current_color, 'filled', ...
            'MarkerFaceAlpha', 0.8, ...
            'DisplayName', sprintf('Room %d (%d cells)', color_index, size(room_cells, 1)));
        
        % Show click position
        plot(x_click, y_click, 'ro', 'MarkerSize', 12, 'LineWidth', 3);
        
        % Calculate area
        room_area = size(room_cells, 1) * (painter.getGridResolution()^2);
        total_painted_cells = total_painted_cells + size(room_cells, 1);
        
        % Store painted area info
        painted_areas(end+1) = struct('position', [x_click, y_click], ...
                                     'cells', size(room_cells, 1), ...
                                     'area_m2', room_area, ...
                                     'color', current_color);
        
        fprintf('✅ Painted %d cells (%.1f m²) with %s color\n', ...
            size(room_cells, 1), room_area, current_color);
        
        % Update title with statistics
        title(sprintf('Room Painting - %d rooms painted, %d total cells (%.1f m²)', ...
            length(painted_areas), total_painted_cells, ...
            total_painted_cells * (painter.getGridResolution()^2)), ...
            'FontSize', 14, 'FontWeight', 'bold');
        
        % Update instructions with current stats
        delete(instruction_text);
        color_name = current_color;
        if isnumeric(current_color)
            color_name = sprintf('[%.1f %.1f %.1f]', current_color(1), current_color(2), current_color(3));
        end
        instruction_text = text(0.02, 0.98, ...
            {'ROOM PAINTING MODE', '', ...
             sprintf('• Rooms painted: %d', length(painted_areas)), ...
             sprintf('• Total area: %.1f m²', total_painted_cells * (painter.getGridResolution()^2)), ...
             sprintf('• Current color: %s', color_name), ...
             '', '• Click anywhere to paint more rooms', ...
             '• Close figure to exit'}, ...
            'Units', 'normalized', 'VerticalAlignment', 'top', ...
            'BackgroundColor', 'yellow', 'EdgeColor', 'black', 'FontSize', 11, ...
            'FontWeight', 'bold');
        
        % Move to next color
        color_index = mod(color_index, length(colors)) + 1;
        
        drawnow;
    end
catch ME
    if ~strcmp(ME.identifier, 'MATLAB:ginput:Interrupted')
        fprintf('Painting mode ended: %s\n', ME.message);
    end
end

%% Summary
if ~isempty(painted_areas)
    fprintf('\n=== Painting Summary ===\n');
    fprintf('Total rooms painted: %d\n', length(painted_areas));
    fprintf('Total cells painted: %d\n', total_painted_cells);
    fprintf('Total area painted: %.1f m²\n', total_painted_cells * (painter.getGridResolution()^2));
    fprintf('\nRoom details:\n');
    
    for i = 1:length(painted_areas)
        fprintf('  Room %d at [%.1f, %.1f]: %d cells, %.1f m², %s color\n', ...
            i, painted_areas(i).position(1), painted_areas(i).position(2), ...
            painted_areas(i).cells, painted_areas(i).area_m2, painted_areas(i).color);
    end
else
    fprintf('\nNo rooms were painted.\n');
end

fprintf('\n🎨 Room painting demonstration complete!\n');
fprintf('The flood fill algorithm successfully painted connected room areas.\n');