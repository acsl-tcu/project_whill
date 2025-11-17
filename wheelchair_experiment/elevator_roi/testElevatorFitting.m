%% Test Script: Elevator Rectangle Fitting with Partial Corner Data
% This script demonstrates the elevator fitting algorithm:
% 1. Generate simulated partial point cloud (corners only)
% 2. Define elevator dimensions
% 3. Fit rectangle to partial data
% 4. Visualize results

clear; close all; clc;

%% 1. Define Ground Truth Elevator
% True elevator pose and dimensions
true_pose = [5.0, 3.0, deg2rad(25)];  % [x, y, theta] in world frame

elevator_dims = struct();
elevator_dims.width = 1.5;   % 1.5 m width
elevator_dims.length = 2.0;  % 2.0 m length (depth)

fprintf('=== Ground Truth Elevator ===\n');
fprintf('Position: [%.2f, %.2f] m\n', true_pose(1), true_pose(2));
fprintf('Orientation: %.2f deg\n', rad2deg(true_pose(3)));
fprintf('Dimensions: %.2f m (W) x %.2f m (L)\n\n', elevator_dims.width, elevator_dims.length);

%% 2. Generate Simulated Partial Point Cloud
% Parameters for point cloud generation
gen_params = struct();
gen_params.corner_coverage = 0.35;  % 35% of each wall visible at corners
gen_params.point_density = 25;      % 25 points per meter
gen_params.noise_std = 0.015;       % 1.5 cm noise

fprintf('=== Generating Point Cloud ===\n');
fprintf('Corner coverage: %.0f%%\n', gen_params.corner_coverage * 100);
fprintf('Point density: %d pts/m\n', gen_params.point_density);
fprintf('Noise level: %.1f cm\n', gen_params.noise_std * 100);

point_cloud = generatePartialElevatorPointCloud(true_pose, elevator_dims, gen_params);

fprintf('Generated %d points\n\n', size(point_cloud, 1));

%% 3. Fit Rectangle to Point Cloud
% Parameters for fitting algorithm
fit_params = struct();
fit_params.cluster_tolerance = 0.2;   % 20 cm clustering
fit_params.ransac_iterations = 100;   % RANSAC iterations
fit_params.ransac_threshold = 0.05;   % 5 cm inlier threshold

fprintf('=== Fitting Rectangle ===\n');
tic;
[fitted_pose, corner_points, fit_quality] = fitRectangleToPartialCorners(point_cloud, elevator_dims, fit_params);
fit_time = toc;

fprintf('Fitting completed in %.3f seconds\n\n', fit_time);

%% 4. Display Results
fprintf('=== Fitted Results ===\n');
fprintf('Position: [%.2f, %.2f] m\n', fitted_pose(1), fitted_pose(2));
fprintf('Orientation: %.2f deg\n', rad2deg(fitted_pose(3)));

% Compute errors
pos_error = norm(fitted_pose(1:2) - true_pose(1:2));
angle_error = rad2deg(angdiff(fitted_pose(3), true_pose(3)));

fprintf('\n=== Error Analysis ===\n');
fprintf('Position error: %.3f m\n', pos_error);
fprintf('Orientation error: %.2f deg\n', abs(angle_error));

fprintf('\n=== Fit Quality Metrics ===\n');
fprintf('Mean point-to-edge error: %.3f m (%.1f cm)\n', fit_quality.mean_error, fit_quality.mean_error * 100);
fprintf('Number of inliers: %d / %d (%.1f%%)\n', fit_quality.num_inliers, size(point_cloud, 1), fit_quality.inlier_ratio * 100);
fprintf('Orientation confidence: %.3f\n', fit_quality.orientation_confidence);

%% 5. Visualization
figure('Position', [100, 100, 1200, 800]);

%% Subplot 1: Point Cloud and Fitted Rectangle
subplot(2, 2, 1);
hold on; grid on; axis equal;

% Plot point cloud
scatter(point_cloud(:, 1), point_cloud(:, 2), 30, [0.2 0.8 0.3], 'filled', 'DisplayName', 'Point Cloud');

% Plot fitted rectangle
plot([corner_points(:, 1); corner_points(1, 1)], ...
     [corner_points(:, 2); corner_points(1, 2)], ...
     'b-', 'LineWidth', 2.5, 'DisplayName', 'Fitted Rectangle');

% Plot fitted center and orientation
arrow_len = 0.5;
quiver(fitted_pose(1), fitted_pose(2), ...
       arrow_len * cos(fitted_pose(3)), arrow_len * sin(fitted_pose(3)), ...
       'b', 'LineWidth', 2, 'MaxHeadSize', 0.5, 'DisplayName', 'Fitted Orientation');

% Plot corner points
scatter(corner_points(:, 1), corner_points(:, 2), 100, 'blue', 'x', 'LineWidth', 2, 'DisplayName', 'Fitted Corners');

xlabel('X (m)');
ylabel('Y (m)');
title('Fitted Rectangle Result');
legend('Location', 'best');

%% Subplot 2: Ground Truth Comparison
subplot(2, 2, 2);
hold on; grid on; axis equal;

% Plot point cloud
scatter(point_cloud(:, 1), point_cloud(:, 2), 30, [0.2 0.8 0.3], 'filled', 'DisplayName', 'Point Cloud');

% Compute true corner points
half_L = elevator_dims.length / 2;
half_W = elevator_dims.width / 2;
true_corners_local = [
     half_L,  half_W;
    -half_L,  half_W;
    -half_L, -half_W;
     half_L, -half_W
];
R_true = [cos(true_pose(3)), -sin(true_pose(3));
          sin(true_pose(3)),  cos(true_pose(3))];
true_corners = (R_true * true_corners_local')' + true_pose(1:2);

% Plot ground truth rectangle
plot([true_corners(:, 1); true_corners(1, 1)], ...
     [true_corners(:, 2); true_corners(1, 2)], ...
     'r--', 'LineWidth', 2.5, 'DisplayName', 'Ground Truth');

% Plot fitted rectangle
plot([corner_points(:, 1); corner_points(1, 1)], ...
     [corner_points(:, 2); corner_points(1, 2)], ...
     'b-', 'LineWidth', 2, 'DisplayName', 'Fitted Rectangle');

% Plot centers
scatter(true_pose(1), true_pose(2), 150, 'red', 'x', 'LineWidth', 3, 'DisplayName', 'True Center');
scatter(fitted_pose(1), fitted_pose(2), 150, 'blue', '+', 'LineWidth', 3, 'DisplayName', 'Fitted Center');

xlabel('X (m)');
ylabel('Y (m)');
title('Ground Truth vs Fitted');
legend('Location', 'best');

%% Subplot 3: Point-to-Edge Distance Distribution
subplot(2, 2, 3);

% Calculate distances from points to fitted edges
distances = zeros(size(point_cloud, 1), 1);
for i = 1:size(point_cloud, 1)
    pt = point_cloud(i, :);
    min_dist = inf;

    for e = 1:4
        idx1 = e;
        idx2 = mod(e, 4) + 1;
        dist = pointToLineSegmentDistance(pt, corner_points(idx1, :), corner_points(idx2, :));
        min_dist = min(min_dist, dist);
    end

    distances(i) = min_dist;
end

histogram(distances * 100, 20, 'FaceColor', [0.3 0.6 0.8]);
xlabel('Distance to Nearest Edge (cm)');
ylabel('Count');
title(sprintf('Residual Distribution (Mean: %.1f cm)', mean(distances) * 100));
grid on;

%% Subplot 4: Summary Text
subplot(2, 2, 4);
axis off;

summary_text = sprintf(['\\fontsize{11}\\bf Test Summary\\rm\n\n', ...
    '\\bf Ground Truth:\\rm\n', ...
    '  Position: [%.2f, %.2f] m\n', ...
    '  Orientation: %.1f°\n', ...
    '  Dimensions: %.2f × %.2f m\n\n', ...
    '\\bf Fitted Result:\\rm\n', ...
    '  Position: [%.2f, %.2f] m\n', ...
    '  Orientation: %.1f°\n\n', ...
    '\\bf Errors:\\rm\n', ...
    '  Position error: \\color{red}%.1f cm\\color{black}\n', ...
    '  Angle error: \\color{red}%.2f°\\color{black}\n\n', ...
    '\\bf Quality Metrics:\\rm\n', ...
    '  Mean residual: %.1f cm\n', ...
    '  Inlier ratio: %.1f%%\n', ...
    '  Confidence: %.2f\n\n', ...
    '\\bf Performance:\\rm\n', ...
    '  Computation time: %.1f ms\n', ...
    '  Points processed: %d'], ...
    true_pose(1), true_pose(2), rad2deg(true_pose(3)), ...
    elevator_dims.width, elevator_dims.length, ...
    fitted_pose(1), fitted_pose(2), rad2deg(fitted_pose(3)), ...
    pos_error * 100, abs(angle_error), ...
    fit_quality.mean_error * 100, fit_quality.inlier_ratio * 100, ...
    fit_quality.orientation_confidence, ...
    fit_time * 1000, size(point_cloud, 1));

text(0.1, 0.95, summary_text, 'VerticalAlignment', 'top', 'FontName', 'FixedWidth');

sgtitle('Elevator Rectangle Fitting - Partial Corner Data', 'FontSize', 14, 'FontWeight', 'bold');

%% Helper Function
function dist = pointToLineSegmentDistance(pt, line_start, line_end)
    v = line_end - line_start;
    w = pt - line_start;

    c1 = dot(w, v);
    if c1 <= 0
        dist = norm(pt - line_start);
        return;
    end

    c2 = dot(v, v);
    if c1 >= c2
        dist = norm(pt - line_end);
        return;
    end

    b = c1 / c2;
    pb = line_start + b * v;
    dist = norm(pt - pb);
end
