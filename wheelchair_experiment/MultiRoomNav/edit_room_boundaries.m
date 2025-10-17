%% Interactive Room Boundary Editor
% Load occupancy map and room database, visualize together for editing
%
% Instructions:
%   1. Script loads occupancy map and room database
%   2. Displays map with current room boundaries overlaid
%   3. You can see which boundaries need adjustment
%   4. Edit room_database.json manually based on the visualization
%   5. Re-run script to verify changes

clc; clear; close all;

fprintf('╔══════════════════════════════════════════════════╗\n');
fprintf('║   ROOM BOUNDARY EDITOR                           ║\n');
fprintf('╚══════════════════════════════════════════════════╝\n\n');

%% Step 1: Load room database
fprintf('STEP 1: Loading room database...\n');
fprintf('─────────────────────────────────────────────────────\n');

db = RoomDatabase('room_database.json');

if isempty(db.rooms_data)
    fprintf('ERROR: Failed to load database!\n');
    return;
end

fprintf('  Loaded %d rooms\n', length(db.rooms_data));
fprintf('  Map file: %s\n\n', db.map_file);

%% Step 2: Load occupancy map
fprintf('STEP 2: Loading occupancy map...\n');
fprintf('─────────────────────────────────────────────────────\n');

% Construct full path (relative to this script's location)
map_path = fullfile(fileparts(mfilename('fullpath')), db.map_file);

if ~exist(map_path, 'file')
    fprintf('ERROR: Map file not found: %s\n', map_path);
    return;
end

% Load map
load(map_path, 'occupancyMap');

fprintf('  Map loaded successfully\n');
fprintf('  Resolution: %.2f cells/meter\n', occupancyMap.Resolution);
fprintf('  Grid size: %d x %d cells\n', occupancyMap.GridSize(1), occupancyMap.GridSize(2));

% Get map limits
[x_min, x_max] = occupancyMap.XWorldLimits;
[y_min, y_max] = occupancyMap.YWorldLimits;
fprintf('  X range: [%.1f, %.1f] m\n', x_min, x_max);
fprintf('  Y range: [%.1f, %.1f] m\n\n', y_min, y_max);

%% Step 3: Visualize map with room boundaries
fprintf('STEP 3: Visualizing map with room boundaries...\n');
fprintf('─────────────────────────────────────────────────────\n');

fig = figure('Name', 'Room Boundary Editor', ...
    'Position', [50, 50, 1600, 1000]);

% Show occupancy map
show(occupancyMap);
hold on;
axis equal;
grid on;

% Define colors for different rooms
room_colors = {
    [1 0 0],      % Red
    [0 0.7 0],    % Green
    [0 0 1],      % Blue
    [1 0.5 0],    % Orange
    [1 0 1],      % Magenta
    [0 1 1]       % Cyan
};

%% Step 4: Overlay room boundaries
fprintf('Overlaying room boundaries:\n\n');

for i = 1:length(db.rooms_data)
    room = db.rooms_data(i);

    % Get boundaries
    x_min_room = room.boundaries.x_min;
    x_max_room = room.boundaries.x_max;
    y_min_room = room.boundaries.y_min;
    y_max_room = room.boundaries.y_max;

    % Select color
    color_idx = mod(i-1, length(room_colors)) + 1;
    color = room_colors{color_idx};

    % Draw rectangle for room boundaries
    rectangle('Position', [x_min_room, y_min_room, ...
                          x_max_room - x_min_room, ...
                          y_max_room - y_min_room], ...
             'EdgeColor', color, 'LineWidth', 3, 'LineStyle', '-');

    % Calculate center
    center_x = (x_min_room + x_max_room) / 2;
    center_y = (y_min_room + y_max_room) / 2;

    % Add room label at center
    text(center_x, center_y, sprintf('Room %s\n%s', room.id, room.name), ...
        'HorizontalAlignment', 'center', ...
        'FontSize', 14, 'FontWeight', 'bold', ...
        'Color', color, ...
        'BackgroundColor', [1 1 1 0.8], ...
        'EdgeColor', color, 'LineWidth', 2);

    % Add corner labels for precise coordinates
    % Bottom-left corner
    text(x_min_room, y_min_room, sprintf('[%.1f, %.1f]', x_min_room, y_min_room), ...
        'FontSize', 10, 'Color', color, 'FontWeight', 'bold', ...
        'BackgroundColor', [1 1 1 0.9], 'VerticalAlignment', 'top');

    % Top-right corner
    text(x_max_room, y_max_room, sprintf('[%.1f, %.1f]', x_max_room, y_max_room), ...
        'FontSize', 10, 'Color', color, 'FontWeight', 'bold', ...
        'BackgroundColor', [1 1 1 0.9], 'VerticalAlignment', 'bottom');

    fprintf('  Room %s (%s):\n', room.id, room.name);
    fprintf('    X: [%.1f, %.1f]  Y: [%.1f, %.1f]\n', ...
        x_min_room, x_max_room, y_min_room, y_max_room);
    fprintf('    Center: [%.1f, %.1f]\n', center_x, center_y);
    fprintf('    Size: %.1f × %.1f m\n\n', ...
        x_max_room - x_min_room, y_max_room - y_min_room);
end

%% Step 5: Overlay door positions
fprintf('Overlaying door positions:\n\n');

% Read doors from JSON
fid = fopen('room_database.json', 'r');
raw_json = fread(fid, inf, 'char=>char')';
fclose(fid);
data = jsondecode(raw_json);

if isfield(data, 'doors')
    for i = 1:length(data.doors)
        if iscell(data.doors)
            door = data.doors{i};
        else
            door = data.doors(i);
        end

        % Extract door position
        if iscell(door.position)
            door_pos = door.position{1};
        else
            door_pos = door.position;
        end

        % Extract door ID
        if iscell(door.id)
            door_id = door.id{1};
        else
            door_id = door.id;
        end

        % Plot door as large marker
        plot(door_pos(1), door_pos(2), 'p', ...
            'MarkerSize', 25, 'MarkerFaceColor', [1 1 0], ...
            'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);

        % Label door
        text(door_pos(1), door_pos(2) + 0.8, door_id, ...
            'HorizontalAlignment', 'center', ...
            'FontSize', 11, 'FontWeight', 'bold', ...
            'Color', [0 0 0], ...
            'BackgroundColor', [1 1 0 0.8], ...
            'EdgeColor', [0 0 0], 'LineWidth', 2);

        fprintf('  Door %s: [%.1f, %.1f]\n', door_id, door_pos(1), door_pos(2));
    end
end

hold off;

% Set title
title('Room Boundaries on Occupancy Map - Edit room\_database.json to adjust', ...
    'FontSize', 16, 'FontWeight', 'bold', 'Interpreter', 'none');

xlabel('X (meters)', 'FontSize', 14);
ylabel('Y (meters)', 'FontSize', 14);

%% Instructions
fprintf('\n╔══════════════════════════════════════════════════╗\n');
fprintf('║   EDITING INSTRUCTIONS                           ║\n');
fprintf('╚══════════════════════════════════════════════════╝\n\n');

fprintf('To edit room boundaries:\n');
fprintf('  1. Look at the visualization above\n');
fprintf('  2. Identify which boundaries need adjustment\n');
fprintf('  3. Edit room_database.json manually:\n');
fprintf('     - Update x_min, x_max, y_min, y_max values\n');
fprintf('  4. Re-run this script to verify changes\n\n');

fprintf('Room boundary format in JSON:\n');
fprintf('  "boundaries": {\n');
fprintf('    "x_min": 0,\n');
fprintf('    "x_max": 8,\n');
fprintf('    "y_min": 4,\n');
fprintf('    "y_max": 8\n');
fprintf('  }\n\n');

fprintf('═════════════════════════════════════════════════\n');
fprintf('Visualization complete! Adjust boundaries as needed.\n');
fprintf('═════════════════════════════════════════════════\n\n');
