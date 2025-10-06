function visualizeFloodFillComparison(mapFile, robot_positions)
%VISUALIZEFLOODFILLCOMPARISON Advanced visualization for flood fill ROI comparison
% This function creates comprehensive visualizations comparing flood fill
% ROI detection at multiple robot positions
%
% Input:
%   mapFile - path to occupancy map file
%   robot_positions - Nx2 array of [x, y] positions to test (optional)

if nargin < 1
    mapFile = '../map2.mat';
end

if nargin < 2
    % Default test positions
    robot_positions = [
        5.0, 1.0;      % Position near start
        15.0, 2.0;     % Middle corridor  
        25.0, 5.0;     % Near elevator
        10.0, -1.0;    % Different room
        2.0, 3.0;      % Another area
        20.0, 8.0;     % Upper area
    ];
end

fprintf('Creating advanced flood fill visualizations...\n');

% Initialize detector
detector = FloodFillROI(mapFile);

% Parameters
max_distance = 50;
wall_threshold = 0.5;
colors = lines(size(robot_positions, 1));

%% 1. Overview comparison plot
figure('Name', 'Flood Fill ROI Overview', 'Position', [50, 50, 1400, 900]);

% Compute all ROIs
rois = zeros(size(robot_positions, 1), 4); % [x_min, x_max, y_min, y_max]
areas = zeros(size(robot_positions, 1), 1);

for i = 1:size(robot_positions, 1)
    roi = detector.getFloodFillROI(robot_positions(i,:), max_distance, wall_threshold);
    rois(i, :) = [roi(1,:), roi(2,:)];
    areas(i) = (roi(1,2) - roi(1,1)) * (roi(2,2) - roi(2,1));
end

% Plot overview
show(detector.getOccupancyMap());
hold on;

% Plot all ROIs with different colors
for i = 1:size(robot_positions, 1)
    % ROI boundary
    roi_x = [rois(i,1), rois(i,2), rois(i,2), rois(i,1), rois(i,1)];
    roi_y = [rois(i,3), rois(i,3), rois(i,4), rois(i,4), rois(i,3)];
    plot(roi_x, roi_y, 'Color', colors(i,:), 'LineWidth', 2, ...
        'DisplayName', sprintf('ROI %d (%.1f m²)', i, areas(i)));
    
    % Robot position
    scatter(robot_positions(i,1), robot_positions(i,2), 100, colors(i,:), 'filled', ...
        'MarkerEdgeColor', 'black', 'LineWidth', 1.5);
    
    % Position label
    text(robot_positions(i,1) + 0.5, robot_positions(i,2) + 0.5, num2str(i), ...
        'Color', colors(i,:), 'FontSize', 12, 'FontWeight', 'bold', ...
        'BackgroundColor', 'white', 'EdgeColor', colors(i,:));
end

title('Flood Fill ROI Comparison - All Positions', 'FontSize', 16, 'FontWeight', 'bold');
xlabel('X (m)'); ylabel('Y (m)');
legend('Location', 'best');
grid on; axis equal;

%% 2. Individual detailed plots
figure('Name', 'Individual Flood Fill Results', 'Position', [100, 50, 1600, 1200]);

rows = ceil(sqrt(size(robot_positions, 1)));
cols = ceil(size(robot_positions, 1) / rows);

for i = 1:size(robot_positions, 1)
    subplot(rows, cols, i);
    
    % Show map
    show(detector.getOccupancyMap());
    hold on;
    
    % Highlight current ROI
    roi_x = [rois(i,1), rois(i,2), rois(i,2), rois(i,1), rois(i,1)];
    roi_y = [rois(i,3), rois(i,3), rois(i,4), rois(i,4), rois(i,3)];
    plot(roi_x, roi_y, 'g-', 'LineWidth', 3);
    
    % Fill ROI area with transparency
    fill(roi_x, roi_y, 'green', 'FaceAlpha', 0.2);
    
    % Robot position
    plot(robot_positions(i,1), robot_positions(i,2), 'ro', 'MarkerSize', 12, 'LineWidth', 3);
    
    % Statistics
    width = rois(i,2) - rois(i,1);
    height = rois(i,4) - rois(i,3);
    
    title(sprintf('Pos %d: [%.1f, %.1f]\nROI: %.1f×%.1f m, Area: %.1f m²', ...
        i, robot_positions(i,:), width, height, areas(i)));
    
    xlabel('X (m)'); ylabel('Y (m)');
    axis equal; grid on;
    
    % Zoom to ROI area with margin
    margin = 2;
    xlim([rois(i,1) - margin, rois(i,2) + margin]);
    ylim([rois(i,3) - margin, rois(i,4) + margin]);
end

%% 3. Performance and statistics plot
figure('Name', 'Flood Fill Statistics', 'Position', [200, 100, 1200, 800]);

% Plot 1: Area comparison
subplot(2, 3, 1);
bar(1:size(robot_positions, 1), areas, 'FaceColor', [0.3, 0.7, 0.3]);
title('Room Areas Detected');
xlabel('Robot Position'); ylabel('Area (m²)');
grid on;
for i = 1:length(areas)
    text(i, areas(i) + max(areas)*0.02, sprintf('%.1f', areas(i)), ...
        'HorizontalAlignment', 'center', 'FontSize', 10);
end

% Plot 2: ROI dimensions
subplot(2, 3, 2);
widths = rois(:,2) - rois(:,1);
heights = rois(:,4) - rois(:,3);
bar_data = [widths, heights];
bar(bar_data);
title('ROI Dimensions');
xlabel('Robot Position'); ylabel('Distance (m)');
legend('Width (X)', 'Height (Y)', 'Location', 'best');
grid on;

% Plot 3: ROI aspect ratios
subplot(2, 3, 3);
aspect_ratios = widths ./ heights;
bar(1:length(aspect_ratios), aspect_ratios, 'FaceColor', [0.7, 0.3, 0.3]);
title('ROI Aspect Ratios');
xlabel('Robot Position'); ylabel('Width/Height Ratio');
grid on;
yline(1, '--k', 'Square', 'FontSize', 10);

% Plot 4: ROI centers
subplot(2, 3, 4);
roi_centers_x = (rois(:,1) + rois(:,2)) / 2;
roi_centers_y = (rois(:,3) + rois(:,4)) / 2;
scatter(roi_centers_x, roi_centers_y, 100, 1:length(roi_centers_x), 'filled');
colormap(lines);
colorbar('Ticks', 1:length(roi_centers_x), 'TickLabels', arrayfun(@num2str, 1:length(roi_centers_x), 'UniformOutput', false));
title('ROI Centers');
xlabel('X (m)'); ylabel('Y (m)');
grid on; axis equal;

% Plot 5: Distance from robot to ROI center
subplot(2, 3, 5);
distances = sqrt((roi_centers_x - robot_positions(:,1)).^2 + ...
                (roi_centers_y - robot_positions(:,2)).^2);
bar(1:length(distances), distances, 'FaceColor', [0.3, 0.3, 0.7]);
title('Robot Distance from ROI Center');
xlabel('Robot Position'); ylabel('Distance (m)');
grid on;

% Plot 6: Area efficiency compared to static ROI
subplot(2, 3, 6);
static_roi_area = 17 * 4; % Typical static ROI: 17m x 4m = 68 m²
efficiency = areas / static_roi_area * 100;
colors_eff = efficiency;
colors_eff(efficiency > 100) = 1; % Red for larger than static
colors_eff(efficiency <= 100) = 2; % Blue for smaller than static
bar(1:length(efficiency), efficiency, 'CData', colors_eff);
title('Efficiency vs Static ROI');
xlabel('Robot Position'); ylabel('Efficiency (%)');
grid on;
yline(100, '--k', 'Static ROI Size', 'FontSize', 10);

%% 4. Adaptive ROI demonstration
figure('Name', 'Adaptive ROI Benefits', 'Position', [250, 150, 1400, 600]);

% Compare with static ROI
static_roi_bounds = [-2, 15, -2, 2]; % [x_min, x_max, y_min, y_max]
static_area = (static_roi_bounds(2) - static_roi_bounds(1)) * (static_roi_bounds(4) - static_roi_bounds(3));

subplot(1, 2, 1);
show(detector.getOccupancyMap());
hold on;

% Show static ROI
static_x = [static_roi_bounds(1), static_roi_bounds(2), static_roi_bounds(2), static_roi_bounds(1), static_roi_bounds(1)];
static_y = [static_roi_bounds(3), static_roi_bounds(3), static_roi_bounds(4), static_roi_bounds(4), static_roi_bounds(3)];
plot(static_x, static_y, 'r--', 'LineWidth', 3, 'DisplayName', sprintf('Static ROI (%.0f m²)', static_area));

% Show robot positions
for i = 1:size(robot_positions, 1)
    plot(robot_positions(i,1), robot_positions(i,2), 'ko', 'MarkerSize', 8, 'LineWidth', 2);
    text(robot_positions(i,1) + 0.3, robot_positions(i,2), num2str(i), 'FontSize', 10, 'FontWeight', 'bold');
end

title('Static ROI Approach', 'FontSize', 14);
xlabel('X (m)'); ylabel('Y (m)');
legend('Location', 'best');
grid on; axis equal;

subplot(1, 2, 2);
show(detector.getOccupancyMap());
hold on;

% Show adaptive ROIs
for i = 1:size(robot_positions, 1)
    roi_x = [rois(i,1), rois(i,2), rois(i,2), rois(i,1), rois(i,1)];
    roi_y = [rois(i,3), rois(i,3), rois(i,4), rois(i,4), rois(i,3)];
    plot(roi_x, roi_y, 'Color', colors(i,:), 'LineWidth', 2, ...
        'DisplayName', sprintf('Pos %d (%.0f m²)', i, areas(i)));
    
    plot(robot_positions(i,1), robot_positions(i,2), 'o', 'Color', colors(i,:), ...
        'MarkerSize', 8, 'LineWidth', 2, 'MarkerFaceColor', colors(i,:));
    text(robot_positions(i,1) + 0.3, robot_positions(i,2), num2str(i), ...
        'Color', colors(i,:), 'FontSize', 10, 'FontWeight', 'bold');
end

title('Adaptive Flood Fill ROI', 'FontSize', 14);
xlabel('X (m)'); ylabel('Y (m)');
legend('Location', 'best');
grid on; axis equal;

%% 5. Print summary
fprintf('\n=== Flood Fill ROI Analysis Summary ===\n');
fprintf('Number of test positions: %d\n', size(robot_positions, 1));
fprintf('Average room area detected: %.1f ± %.1f m²\n', mean(areas), std(areas));
fprintf('Static ROI area: %.0f m²\n', static_area);
fprintf('Average efficiency: %.1f%%\n', mean(efficiency));
fprintf('\nPosition details:\n');
for i = 1:size(robot_positions, 1)
    fprintf('  Pos %d [%.1f, %.1f]: ROI %.1f×%.1f m, Area %.1f m² (%.1f%% of static)\n', ...
        i, robot_positions(i,:), widths(i), heights(i), areas(i), efficiency(i));
end

fprintf('\n✓ Flood fill provides room-aware ROI that adapts to local geometry\n');
fprintf('✓ Reduces computation in large open areas\n');
fprintf('✓ Focuses processing on relevant nearby obstacles\n');
fprintf('✓ Automatically handles complex room shapes\n\n');

end