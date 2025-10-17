%% Test Hybrid Path Planner (Dijkstra + A*)
% This script demonstrates the two-level path planning:
%   1. Dijkstra: Find optimal room sequence
%   2. A*: Plan geometric paths within each room

clc; clear; close all;

fprintf('═════════════════════════════════════════════════════\n');
fprintf('   TEST: HYBRID PATH PLANNER (Dijkstra + A*)        \n');
fprintf('═════════════════════════════════════════════════════\n\n');

%% Define test parameters
start_position = [0, 0];    % Start in Room A
goal_position = [30, 10];      % Goal in Room B
robot_width = 0.6;             % meters
robot_length = 1.0;            % meters
safety_margin = 0.1;           % meters

fprintf('Test Configuration:\n');
fprintf('  Start position: [%.1f, %.1f] m\n', start_position(1), start_position(2));
fprintf('  Goal position: [%.1f, %.1f] m\n', goal_position(1), goal_position(2));
fprintf('  Robot: %.1fm × %.1fm + %.1fm safety\n\n', robot_width, robot_length, safety_margin);

%% Run hybrid planner
[waypoint_segments, room_sequence, total_distance] = HybridPathPlanner(...
    start_position, goal_position, 'room_database.json', ...
    robot_width, robot_length, safety_margin);

%% Visualize results
fprintf('═════════════════════════════════════════════════════\n');
fprintf('   VISUALIZATION                                     \n');
fprintf('═════════════════════════════════════════════════════\n\n');

% Load map for visualization
db = RoomDatabase('room_database.json');
map_path = fullfile(fileparts(mfilename('fullpath')), db.map_file);
load(map_path, 'map');

% Create figure
fig = figure('Name', 'Hybrid Path Planner Results', ...
    'Position', [100, 100, 1400, 900]);

% Show map
show(map);
hold on;
axis equal;
grid on;

% Define colors for different segments
segment_colors = {
    [1 0 0],      % Red
    [0 0.7 0],    % Green
    [0 0 1],      % Blue
    [1 0.5 0],    % Orange
    [0.5 0 0.5],  % Purple
    [0 1 1]       % Cyan
};

% Plot each segment with different color
for i = 1:length(waypoint_segments)
    waypoints = waypoint_segments{i};
    color_idx = mod(i-1, length(segment_colors)) + 1;
    color = segment_colors{color_idx};

    % Plot waypoints as line
    plot(waypoints(:,1), waypoints(:,2), '-', ...
         'Color', color, 'LineWidth', 4);

    % Plot waypoints as circles
    plot(waypoints(:,1), waypoints(:,2), 'o', ...
         'MarkerSize', 6, 'MarkerFaceColor', color, ...
         'MarkerEdgeColor', [0 0 0], 'LineWidth', 1);

    % Label segment
    mid_idx = ceil(size(waypoints, 1) / 2);
    text(waypoints(mid_idx, 1), waypoints(mid_idx, 2), ...
         sprintf('Seg %d\n(Room %s)', i, room_sequence{i}), ...
         'HorizontalAlignment', 'center', ...
         'FontSize', 10, 'FontWeight', 'bold', ...
         'Color', color, ...
         'BackgroundColor', [1 1 1 0.8], ...
         'EdgeColor', color, 'LineWidth', 2);
end

% Plot start and goal
plot(start_position(1), start_position(2), 'o', ...
     'MarkerSize', 20, 'MarkerFaceColor', [0 1 1], ...
     'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);
text(start_position(1), start_position(2) + 0.8, 'START', ...
     'HorizontalAlignment', 'center', 'FontSize', 12, 'FontWeight', 'bold', ...
     'Color', [0 1 1], 'BackgroundColor', [0 0 0 0.7]);

plot(goal_position(1), goal_position(2), 'o', ...
     'MarkerSize', 20, 'MarkerFaceColor', [1 0 1], ...
     'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);
text(goal_position(1), goal_position(2) + 0.8, 'GOAL', ...
     'HorizontalAlignment', 'center', 'FontSize', 12, 'FontWeight', 'bold', ...
     'Color', [1 0 1], 'BackgroundColor', [0 0 0 0.7]);

% Plot doors
for i = 1:length(room_sequence)-1
    current_room_id = room_sequence{i};
    next_room_id = room_sequence{i+1};

    graph = db.buildGraph();
    current_room = graph.rooms(current_room_id);
    door_obj = current_room.getDoorTo(next_room_id);

    if ~isempty(door_obj)
        plot(door_obj.door_center(1), door_obj.door_center(2), 'p', ...
             'MarkerSize', 25, 'MarkerFaceColor', [1 1 0], ...
             'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);
    end
end

hold off;

% Build path string
path_str = room_sequence{1};
for i = 2:length(room_sequence)
    path_str = [path_str, ' → ', room_sequence{i}];
end

title(sprintf('Hybrid Path: %s (%.2f m)', path_str, total_distance), ...
      'FontSize', 16, 'FontWeight', 'bold');
xlabel('X (meters)', 'FontSize', 14);
ylabel('Y (meters)', 'FontSize', 14);

fprintf('Visualization complete!\n\n');

%% Print detailed segment information
fprintf('═════════════════════════════════════════════════════\n');
fprintf('   DETAILED SEGMENT BREAKDOWN                       \n');
fprintf('═════════════════════════════════════════════════════\n\n');

for i = 1:length(waypoint_segments)
    waypoints = waypoint_segments{i};

    fprintf('Segment %d (Room %s):\n', i, room_sequence{i});
    fprintf('  Number of waypoints: %d\n', size(waypoints, 1));
    fprintf('  Start: [%.2f, %.2f]\n', waypoints(1,1), waypoints(1,2));
    fprintf('  End: [%.2f, %.2f]\n', waypoints(end,1), waypoints(end,2));

    % Calculate segment distance
    segment_dist = 0;
    for j = 1:size(waypoints, 1)-1
        segment_dist = segment_dist + norm(waypoints(j+1, :) - waypoints(j, :));
    end
    fprintf('  Distance: %.2f m\n', segment_dist);

    fprintf('  Waypoints:\n');
    for j = 1:size(waypoints, 1)
        fprintf('    %2d: [%7.2f, %7.2f]\n', j, waypoints(j,1), waypoints(j,2));
    end
    fprintf('\n');
end

fprintf('═════════════════════════════════════════════════════\n');
fprintf('TEST COMPLETE!\n');
fprintf('═════════════════════════════════════════════════════\n');
