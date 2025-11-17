function point_cloud = generatePartialElevatorPointCloud(elevator_pose, elevator_dims, params)
% GENERATEPARTIALELEVATORPOINTCLOUD Generate simulated partial elevator point cloud
%
% Simulates LiDAR scan of elevator with only corner regions visible
% (middle sections of walls are missing, as if there are openings/doors)
%
% Inputs:
%   elevator_pose - [x, y, theta] pose of elevator center in world frame
%   elevator_dims - struct with fields:
%                   .width  - elevator width (m)
%                   .length - elevator length (m)
%   params - struct with fields:
%            .corner_coverage - fraction of each wall visible at corners (e.g., 0.3 = 30%)
%            .point_density   - points per meter along walls (default: 20)
%            .noise_std       - Gaussian noise std dev in meters (default: 0.01)
%
% Output:
%   point_cloud - Nx2 matrix of [x, y] points in world frame

    % Default parameters
    if nargin < 3
        params = struct();
    end
    if ~isfield(params, 'corner_coverage')
        params.corner_coverage = 0.3;  % 30% of each wall at corners
    end
    if ~isfield(params, 'point_density')
        params.point_density = 20;  % points per meter
    end
    if ~isfield(params, 'noise_std')
        params.noise_std = 0.01;  % 1 cm noise
    end

    % Extract elevator pose
    x_c = elevator_pose(1);
    y_c = elevator_pose(2);
    theta = elevator_pose(3);  % orientation in radians

    % Extract dimensions
    W = elevator_dims.width;   % width
    L = elevator_dims.length;  % length

    % Calculate corner coverage length
    corner_len = params.corner_coverage;

    % Generate points in elevator local frame (centered at origin)
    % Local frame: x-axis along length, y-axis along width

    % Half dimensions
    half_L = L / 2;
    half_W = W / 2;

    % Calculate number of points per corner section
    n_points_L = round(corner_len * L * params.point_density);
    n_points_W = round(corner_len * W * params.point_density);

    points_local = [];

    % Wall 1: Top (y = +half_W)
    % Left corner section
    x1_left = linspace(-half_L, -half_L + corner_len * L, n_points_L)';
    y1_left = half_W * ones(n_points_L, 1);
    % Right corner section
    x1_right = linspace(half_L - corner_len * L, half_L, n_points_L)';
    y1_right = half_W * ones(n_points_L, 1);
    points_local = [points_local; x1_left, y1_left; x1_right, y1_right];

    % Wall 2: Right (x = +half_L)
    % Top corner section
    y2_top = linspace(half_W - corner_len * W, half_W, n_points_W)';
    x2_top = half_L * ones(n_points_W, 1);
    % Bottom corner section
    y2_bottom = linspace(-half_W, -half_W + corner_len * W, n_points_W)';
    x2_bottom = half_L * ones(n_points_W, 1);
    points_local = [points_local; x2_top, y2_top; x2_bottom, y2_bottom];

    % Wall 3: Bottom (y = -half_W)
    % Right corner section
    x3_right = linspace(half_L - corner_len * L, half_L, n_points_L)';
    y3_right = -half_W * ones(n_points_L, 1);
    % Left corner section
    x3_left = linspace(-half_L, -half_L + corner_len * L, n_points_L)';
    y3_left = -half_W * ones(n_points_L, 1);
    points_local = [points_local; x3_right, y3_right; x3_left, y3_left];

    % Wall 4: Left (x = -half_L)
    % Bottom corner section
    y4_bottom = linspace(-half_W, -half_W + corner_len * W, n_points_W)';
    x4_bottom = -half_L * ones(n_points_W, 1);
    % Top corner section
    y4_top = linspace(half_W - corner_len * W, half_W, n_points_W)';
    x4_top = -half_L * ones(n_points_W, 1);
    points_local = [points_local; x4_bottom, y4_bottom; x4_top, y4_top];

    % Add Gaussian noise
    if params.noise_std > 0
        noise = params.noise_std * randn(size(points_local));
        points_local = points_local + noise;
    end

    % Transform points to world frame
    % Rotation matrix
    R = [cos(theta), -sin(theta);
         sin(theta),  cos(theta)];

    % Transform: rotate then translate
    point_cloud = (R * points_local')' + [x_c, y_c];

end
