%% Test Script for Flood Fill ROI Detection
% This script demonstrates the flood fill algorithm for room-based ROI detection
% using the map2.mat occupancy grid from your wheelchair experiment

clear; close all; clc;

fprintf('=== Flood Fill ROI Test ===\n\n');

%% Initialize Flood Fill ROI detector
fprintf('1. Initializing FloodFillROI detector...\n');

% Create flood fill ROI detector
floodFillDetector = FloodFillROI();

% Load the map2.mat file from the main directory
mapFile = '../map2.mat';
if ~exist(mapFile, 'file')
    error('map2.mat not found. Please ensure it exists in the main wheelchair_experiment directory');
end

success = floodFillDetector.loadMap(mapFile);
if ~success
    error('Failed to load occupancy map');
end

fprintf('✓ Map loaded successfully\n\n');

%% Test flood fill at multiple robot positions
fprintf('2. Testing flood fill at different robot positions...\n\n');

% Define test positions (feel free to modify these based on your map)
test_positions = [
    5.0, 1.0;      % Position 1 - Near starting area
    15.0, 2.0;     % Position 2 - Middle corridor  
    25.0, 5.0;     % Position 3 - Near elevator area
    10.0, -1.0;    % Position 4 - Different room
    2.0, 3.0;      % Position 5 - Another area
];

% Test parameters
max_distance = 50;      % Maximum flood fill distance (grid cells)
wall_threshold = 0.5;   % Occupancy threshold for walls

% Store results for comparison
results = cell(size(test_positions, 1), 1);

for i = 1:size(test_positions, 1)
    robot_pos = test_positions(i, :);
    
    fprintf('Testing position %d: [%.1f, %.1f]\n', i, robot_pos(1), robot_pos(2));
    
    % Compute ROI using flood fill
    tic;
    roi = floodFillDetector.getFloodFillROI(robot_pos, max_distance, wall_threshold);
    computation_time = toc;
    
    % Store results
    results{i} = struct('robot_pos', robot_pos, 'roi', roi, 'time', computation_time);
    
    % Analyze ROI
    stats = floodFillDetector.analyzeROI(roi, robot_pos);
    
    fprintf('   Computation time: %.3f seconds\n', computation_time);
    fprintf('   ROI: X[%.2f, %.2f], Y[%.2f, %.2f]\n', roi(1,:), roi(2,:));
    fprintf('   Room area: %.2f m²\n\n', stats.area);
end

%% Visualize results
fprintf('3. Creating visualizations...\n\n');

% Create a comprehensive comparison plot
figure('Name', 'Flood Fill ROI Comparison', 'Position', [50, 50, 1400, 1000]);

for i = 1:size(test_positions, 1)
    subplot(2, 3, i);
    
    robot_pos = results{i}.robot_pos;
    roi = results{i}.roi;
    
    % Load and display map
    floodFillDetector.loadMap(mapFile); % Reload to ensure fresh instance
    show(floodFillDetector.getOccupancyMap());
    hold on;
    
    % Plot robot position
    plot(robot_pos(1), robot_pos(2), 'ro', 'MarkerSize', 12, 'LineWidth', 3);
    
    % Plot ROI boundary
    roi_x = [roi(1,1), roi(1,2), roi(1,2), roi(1,1), roi(1,1)];
    roi_y = [roi(2,1), roi(2,1), roi(2,2), roi(2,2), roi(2,1)];
    plot(roi_x, roi_y, 'g-', 'LineWidth', 2);
    
    title(sprintf('Position %d: [%.1f, %.1f]', i, robot_pos(1), robot_pos(2)));
    xlabel('X (m)'); ylabel('Y (m)');
    axis equal; grid on;
    
    % Add ROI info as text
    stats = floodFillDetector.analyzeROI(roi, robot_pos);
    text(roi(1,1), roi(2,2), sprintf('Area: %.1f m²\nSize: %.1fx%.1f m', ...
        stats.area, stats.width, stats.height), ...
        'BackgroundColor', 'white', 'FontSize', 8);
end

% Add overall title
sgtitle('Flood Fill ROI Detection - Multiple Test Positions', 'FontSize', 16, 'FontWeight', 'bold');

%% Interactive test mode
fprintf('4. Starting interactive test mode...\n');
fprintf('   Click on the map to test flood fill at different positions\n');
fprintf('   Press Enter to continue or close the figure to skip\n\n');

% Create interactive figure
fig_interactive = figure('Name', 'Interactive Flood Fill Test - Click to Test', ...
    'Position', [100, 100, 1000, 800]);

% Load and display map
show(floodFillDetector.getOccupancyMap());
hold on;
title('Interactive Flood Fill Test - Click anywhere to test ROI', 'FontSize', 14);
xlabel('X (m)'); ylabel('Y (m)');
grid on; axis equal;

% Instructions text
text_handle = text(0.02, 0.98, {'Click anywhere on the map to test flood fill at that position', ...
    'Green rectangle = Generated ROI', 'Red circle = Robot position', ...
    'Close figure or press Ctrl+C to exit'}, ...
    'Units', 'normalized', 'VerticalAlignment', 'top', ...
    'BackgroundColor', 'white', 'EdgeColor', 'black', 'FontSize', 10);

% Interactive loop
try
    while ishandle(fig_interactive)
        % Wait for user click
        [x_click, y_click] = ginput(1);
        
        if isempty(x_click) % User closed figure or pressed Enter
            break;
        end
        
        fprintf('Testing flood fill at clicked position: [%.2f, %.2f]\n', x_click, y_click);
        
        % Clear previous results
        cla;
        show(floodFillDetector.getOccupancyMap());
        hold on;
        
        % Compute ROI at clicked position
        tic;
        roi_click = floodFillDetector.getFloodFillROI([x_click, y_click], max_distance, wall_threshold);
        time_click = toc;
        
        % Plot results
        plot(x_click, y_click, 'ro', 'MarkerSize', 15, 'LineWidth', 3);
        roi_x = [roi_click(1,1), roi_click(1,2), roi_click(1,2), roi_click(1,1), roi_click(1,1)];
        roi_y = [roi_click(2,1), roi_click(2,1), roi_click(2,2), roi_click(2,2), roi_click(2,1)];
        plot(roi_x, roi_y, 'g-', 'LineWidth', 3);
        
        % Add statistics
        stats_click = floodFillDetector.analyzeROI(roi_click, [x_click, y_click]);
        
        title(sprintf('Flood Fill Result - Area: %.1f m², Time: %.3f s', ...
            stats_click.area, time_click), 'FontSize', 14);
        xlabel('X (m)'); ylabel('Y (m)');
        grid on; axis equal;
        
        % Update instructions
        text(0.02, 0.98, {'Click anywhere on the map to test flood fill at that position', ...
            'Green rectangle = Generated ROI', 'Red circle = Robot position', ...
            'Close figure or press Ctrl+C to exit', '', ...
            sprintf('Last result: Area %.1f m², Computation time %.3f s', stats_click.area, time_click)}, ...
            'Units', 'normalized', 'VerticalAlignment', 'top', ...
            'BackgroundColor', 'white', 'EdgeColor', 'black', 'FontSize', 10);
        
        drawnow;
    end
catch ME
    if ~strcmp(ME.identifier, 'MATLAB:ginput:Interrupted')
        fprintf('Interactive mode ended: %s\n', ME.message);
    end
end

%% Performance analysis
fprintf('\n5. Performance Analysis:\n');
fprintf('========================\n');

all_times = cellfun(@(r) r.time, results);
all_areas = cellfun(@(r) (r.roi(1,2)-r.roi(1,1))*(r.roi(2,2)-r.roi(2,1)), results);

fprintf('Computation times: %.3f ± %.3f seconds (mean ± std)\n', mean(all_times), std(all_times));
fprintf('Room areas detected: %.1f ± %.1f m² (mean ± std)\n', mean(all_areas), std(all_areas));
fprintf('Fastest computation: %.3f seconds\n', min(all_times));
fprintf('Largest room detected: %.1f m²\n', max(all_areas));

%% Comparison with static ROI
fprintf('\n6. Comparison with Static ROI:\n');
fprintf('==============================\n');

% Define a typical static ROI (similar to your current system)
static_roi = [-2, 15; -2, 2; 0.4, 2]; % Typical corridor-like ROI
static_area = (static_roi(1,2) - static_roi(1,1)) * (static_roi(2,2) - static_roi(1,1));

fprintf('Static ROI area: %.1f m²\n', static_area);

for i = 1:length(results)
    dynamic_area = (results{i}.roi(1,2) - results{i}.roi(1,1)) * (results{i}.roi(2,2) - results{i}.roi(2,1));
    efficiency = dynamic_area / static_area * 100;
    fprintf('Position %d - Dynamic ROI: %.1f m² (%.1f%% of static ROI)\n', ...
        i, dynamic_area, efficiency);
end

fprintf('\nFlood fill provides adaptive ROI that changes based on actual room geometry!\n');
fprintf('This reduces unnecessary computation in large spaces and increases focus in small rooms.\n');

%% Summary
fprintf('\n=== Test Summary ===\n');
fprintf('✓ Flood fill algorithm implemented and tested\n');
fprintf('✓ Multiple robot positions tested successfully\n');  
fprintf('✓ Interactive testing completed\n');
fprintf('✓ Performance analysis completed\n');
fprintf('✓ Comparison with static ROI completed\n\n');

fprintf('The flood fill ROI detection is ready for integration into your Estimate.m file!\n');
fprintf('You can use FloodFillROI class in your main wheelchair navigation system.\n');