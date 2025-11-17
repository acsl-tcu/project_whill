function [fitted_pose, corner_points, fit_quality] = fitRectangleToPartialCorners(point_cloud, elevator_dims, params)
% FITRECTANGLETOPARTIALCORNERS Fit fixed-size rectangle to partial corner point cloud
%
% Fits a rectangle of known dimensions to point cloud data where only
% corner regions are visible (middle sections of walls are missing).
%
% Algorithm:
%   1. Estimate orientation using PCA on all points
%   2. Project points to principal axes to find corner clusters
%   3. Detect 4 corner positions from clusters
%   4. Compute rectangle center and orientation from corners
%   5. Refine orientation using RANSAC line fitting on edge points
%
% Inputs:
%   point_cloud    - Nx2 matrix of [x, y] points
%   elevator_dims  - struct with fields:
%                    .width  - known elevator width (m)
%                    .length - known elevator length (m)
%   params         - (optional) struct with fields:
%                    .cluster_tolerance - distance for corner clustering (default: 0.2 m)
%                    .ransac_iterations - RANSAC iterations for line fitting (default: 100)
%                    .ransac_threshold  - inlier threshold for RANSAC (default: 0.05 m)
%
% Outputs:
%   fitted_pose   - [x, y, theta] fitted rectangle pose
%   corner_points - 4x2 matrix of corner positions [x, y]
%   fit_quality   - struct with quality metrics:
%                   .mean_error    - mean distance from points to fitted edges (m)
%                   .num_inliers   - number of inlier points
%                   .orientation_confidence - orientation estimate confidence (0-1)

    % Default parameters
    if nargin < 3
        params = struct();
    end
    if ~isfield(params, 'cluster_tolerance')
        params.cluster_tolerance = 0.2;  % 20 cm
    end
    if ~isfield(params, 'ransac_iterations')
        params.ransac_iterations = 100;
    end
    if ~isfield(params, 'ransac_threshold')
        params.ransac_threshold = 0.05;  % 5 cm
    end

    % Extract dimensions
    W = elevator_dims.width;
    L = elevator_dims.length;

    %% Step 1: Initial orientation estimate using PCA
    points_centered = point_cloud - mean(point_cloud, 1);
    [coeff, ~, latent] = pca(points_centered);

    % Principal direction (major axis)
    theta_pca = atan2(coeff(2, 1), coeff(1, 1));

    % Orientation confidence based on eigenvalue ratio
    orientation_confidence = (latent(1) - latent(2)) / latent(1);

    %% Step 2: Refine orientation using RANSAC on edge points
    theta_refined = refineOrientationRANSAC(point_cloud, theta_pca, params);

    %% Step 3: Detect corner clusters
    % Transform points to rectangle-aligned frame
    R = [cos(theta_refined), sin(theta_refined);
        -sin(theta_refined), cos(theta_refined)];
    points_aligned = (R * point_cloud')';

    % Find center estimate from aligned points
    center_aligned = mean(points_aligned, 1);

    % Classify points into 4 corner regions based on quadrants
    points_rel = points_aligned - center_aligned;

    % Quadrant assignment
    quadrant_1 = points_rel(:, 1) > 0 & points_rel(:, 2) > 0;  % +x, +y (top-right)
    quadrant_2 = points_rel(:, 1) < 0 & points_rel(:, 2) > 0;  % -x, +y (top-left)
    quadrant_3 = points_rel(:, 1) < 0 & points_rel(:, 2) < 0;  % -x, -y (bottom-left)
    quadrant_4 = points_rel(:, 1) > 0 & points_rel(:, 2) < 0;  % +x, -y (bottom-right)

    % Extract corner points for each quadrant (use extreme points)
    corners_aligned = zeros(4, 2);

    if any(quadrant_1)
        pts = points_aligned(quadrant_1, :);
        corners_aligned(1, :) = mean(pts, 1);  % Average corner cluster
    end
    if any(quadrant_2)
        pts = points_aligned(quadrant_2, :);
        corners_aligned(2, :) = mean(pts, 1);
    end
    if any(quadrant_3)
        pts = points_aligned(quadrant_3, :);
        corners_aligned(3, :) = mean(pts, 1);
    end
    if any(quadrant_4)
        pts = points_aligned(quadrant_4, :);
        corners_aligned(4, :) = mean(pts, 1);
    end

    %% Step 4: Compute rectangle center from corners
    % The corners should form a rectangle with known dimensions
    % Use median of corners as center
    center_aligned_refined = median(corners_aligned, 1);

    %% Step 5: Adjust corners to match exact dimensions
    % Expected corner positions in aligned frame (centered at origin)
    half_L = L / 2;
    half_W = W / 2;

    expected_corners_local = [
         half_L,  half_W;   % corner 1 (top-right)
        -half_L,  half_W;   % corner 2 (top-left)
        -half_L, -half_W;   % corner 3 (bottom-left)
         half_L, -half_W    % corner 4 (bottom-right)
    ];

    % Fitted corners in aligned frame
    fitted_corners_aligned = expected_corners_local + center_aligned_refined;

    % Transform back to world frame
    R_inv = [cos(theta_refined), -sin(theta_refined);
             sin(theta_refined),  cos(theta_refined)];
    corner_points = (R_inv * fitted_corners_aligned')';

    % Compute final center in world frame
    center_world = mean(corner_points, 1);

    %% Step 6: Compute fit quality metrics
    % Calculate distance from each point to nearest edge
    edges = [
        corner_points([1 2], :);  % top edge
        corner_points([2 3], :);  % left edge
        corner_points([3 4], :);  % bottom edge
        corner_points([4 1], :)   % right edge
    ];

    distances = zeros(size(point_cloud, 1), 1);
    for i = 1:size(point_cloud, 1)
        pt = point_cloud(i, :);
        min_dist = inf;

        % Check distance to each edge
        for e = 1:4
            idx1 = e;
            idx2 = mod(e, 4) + 1;
            edge_start = corner_points(idx1, :);
            edge_end = corner_points(idx2, :);

            dist = pointToLineSegmentDistance(pt, edge_start, edge_end);
            min_dist = min(min_dist, dist);
        end

        distances(i) = min_dist;
    end

    mean_error = mean(distances);
    num_inliers = sum(distances < params.ransac_threshold * 2);

    %% Output
    fitted_pose = [center_world, theta_refined];

    fit_quality = struct();
    fit_quality.mean_error = mean_error;
    fit_quality.num_inliers = num_inliers;
    fit_quality.orientation_confidence = orientation_confidence;
    fit_quality.inlier_ratio = num_inliers / size(point_cloud, 1);

end


%% Helper Functions

function theta_refined = refineOrientationRANSAC(points, theta_init, params)
    % Refine orientation estimate using RANSAC line fitting

    best_theta = theta_init;
    best_inliers = 0;

    % Try orientations around initial estimate
    theta_range = linspace(theta_init - 0.2, theta_init + 0.2, params.ransac_iterations);

    for i = 1:params.ransac_iterations
        theta = theta_range(i);

        % Transform points to this orientation
        R = [cos(theta), sin(theta);
            -sin(theta), cos(theta)];
        points_aligned = (R * points')';

        % Count inliers: points close to horizontal or vertical lines
        x_coords = points_aligned(:, 1);
        y_coords = points_aligned(:, 2);

        % Find horizontal and vertical line candidates
        y_bins = linspace(min(y_coords), max(y_coords), 10);
        x_bins = linspace(min(x_coords), max(x_coords), 10);

        inliers = 0;

        % Check horizontal alignment
        for j = 1:length(y_bins)
            dist_to_line = abs(y_coords - y_bins(j));
            inliers = inliers + sum(dist_to_line < params.ransac_threshold);
        end

        % Check vertical alignment
        for j = 1:length(x_bins)
            dist_to_line = abs(x_coords - x_bins(j));
            inliers = inliers + sum(dist_to_line < params.ransac_threshold);
        end

        if inliers > best_inliers
            best_inliers = inliers;
            best_theta = theta;
        end
    end

    theta_refined = best_theta;
end


function dist = pointToLineSegmentDistance(pt, line_start, line_end)
    % Calculate distance from point to line segment

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
