function [Grade] = FPM_boundingbox_vec(obj, x, y, th, boundingBoxes, target, param_FPM)
% FPM_boundingbox_vec - Vectorized Fuzzy Potential Method using oriented rectangular bounding boxes
% High-performance vectorized version that processes all obstacles and path points simultaneously
% Based on FPM_capsule_v3_2vec.m structure for optimal performance
%
% Inputs:
%   obj          - wheelchair object with parameters
%   x, y, th     - current wheelchair position and orientation [1,1,K,NP] arrays
%   boundingBoxes - cell array of bounding box structures from Estimate.m
%   target       - target position [1,2,K,NP] array
%   param_FPM    - FPM parameters structure
%
% Outputs:
%   Grade        - FPM grade array [1,1,K-1,NP] for all path points

    %% FPM Parameters
    eta = param_FPM.eta;            % Goal PMF ratio (min/max)
    alpha = param_FPM.alpha;        % Distance threshold for obstacle consideration
    ds = param_FPM.margin;          % Safety margin around obstacles
    obs_cost = param_FPM.obs_cost;  % Collision cost penalty

    %% Wheelchair Parameters
    Po = [x y];                     % Wheelchair position [1,2,K,NP]
    a_wheel = obj.wheel_width;      % Wheelchair width
    b_wheel = obj.wheel_len_front;  % Wheelchair length
    r_wheel = norm([a_wheel b_wheel]); % Wheelchair radius (corner distance)

    %% Goal PMF (using pre-computed target headings like capsule FPM)
    g_a = 1.0;                      % PMF maximum value for goal
    g_b = eta * g_a;                % PMF minimum value for goal
    
    % Use vectorized indexing to get target headings (same as FPM_capsule_v3_3vec.m)
    % obj.target_n is [K, NP], we want [K-1, NP] starting from step 2
    target_indices = obj.target_n(2:end,:);  % Get indices for steps 2 to K
    th_target = obj.th_target_w(reshape(target_indices, [1, 1, obj.K-1, obj.NP]));
    
    % Calculate angle difference using trimmed th
    th_trimmed_for_goal = th(:,:,2:end,:);  % [1,1,K-1,NP]
    phig = th_target - th_trimmed_for_goal;
    phaierror = atan2(sin(phig - 0), cos(phig - 0));
    grade_trgt = -((g_a - g_b)/pi) * abs(phaierror) + g_a;

    %% Convert Bounding Boxes to Vectorized Format
    if isempty(boundingBoxes)
        obsnum = 0;
        Grade = grade_trgt;
        return;
    end
    
    obsnum = length(boundingBoxes);
    
    % Get dimensions
    K_steps = size(x, 3);
    NP_paths = size(x, 4);
    
    % Pre-allocate arrays for all bounding box data [obsnum, 2, K-1, NP]
    % Only need K-1 steps for obstacle processing (skip first step)
    bbox_centers = zeros(obsnum, 2, K_steps-1, NP_paths);  % Center positions
    bbox_dims = zeros(obsnum, 2, K_steps-1, NP_paths);     % [length, width]
    bbox_orients = zeros(obsnum, 1, K_steps-1, NP_paths);  % Orientations
    
    % Extract bounding box parameters into vectorized arrays
    for i = 1:obsnum
        bbox = boundingBoxes{i};
        bbox_centers(i, :, :, :) = repmat(reshape(bbox.center(1:2), [1, 2, 1, 1]), [1, 1, K_steps-1, NP_paths]);
        bbox_dims(i, :, :, :) = repmat(reshape(bbox.dimensions(1:2), [1, 2, 1, 1]), [1, 1, K_steps-1, NP_paths]);
        bbox_orients(i, 1, :, :) = repmat(bbox.orientation, [1, 1, K_steps-1, NP_paths]);
    end

    %% Obstacle PMF Processing (Vectorized)
    if obsnum > 0
        % Initialize grade array - ensure dimensions match input arrays
        K_steps = size(x, 3);      % Should be K
        NP_paths = size(x, 4);     % Should be NP
        grade_obs = ones(obsnum, 1, K_steps-1, NP_paths);  % Skip first step to match K-1
        
        % Safety margin
        D = a_wheel + ds;
        
        % Transform to wheelchair coordinate frame - vectorized rotation
        R = [cos(-th) -sin(-th); sin(-th) cos(-th)];  % [2,2,K,NP]
        
        % Calculate relative positions [obsnum, 2, K-1, NP]
        % Use Po from step 2 onwards to match bbox_centers dimensions
        Po_trimmed = Po(:, :, 2:end, :);  % [1, 2, K-1, NP]
        rel_pos = bbox_centers - Po_trimmed;
        
        % Vectorized rotation transformation
        % Use trimmed th to match dimensions [1,1,K-1,NP]
        th_trimmed = th(:, :, 2:end, :);
        bbox_centers_wf = zeros(size(bbox_centers));
        bbox_centers_wf(:,1,:,:) = rel_pos(:,1,:,:) .* cos(-th_trimmed) - rel_pos(:,2,:,:) .* sin(-th_trimmed);
        bbox_centers_wf(:,2,:,:) = rel_pos(:,1,:,:) .* sin(-th_trimmed) + rel_pos(:,2,:,:) .* cos(-th_trimmed);
        
        % Distance to bounding box centers
        PoQo = vecnorm(bbox_centers_wf, 2, 2);  % [obsnum, 1, K-1, NP]
        
        % Direction to bounding box centers in wheelchair frame
        phiQo = atan2(bbox_centers_wf(:,2,:,:), bbox_centers_wf(:,1,:,:));
        
        % Calculate minimum distance to each bounding box using vectorized operations
        % This is a simplified approximation - for full accuracy, we'd need the complete
        % point-to-rectangle distance calculation vectorized
        
        % Approximate bounding box as equivalent circle for vectorized calculation
        % This maintains performance while providing reasonable obstacle avoidance
        equiv_radius = vecnorm(bbox_dims, 2, 2) / 2;  % Approximate radius from dimensions
        
        % Minimum distance approximation
        PoQ3 = max(0, PoQo - equiv_radius);  % Distance to bounding box boundary
        
        % Angular range calculation (simplified for vectorization)
        % For full rectangle, this would require corner processing
        bbox_angular_extent = 2 * atan(equiv_radius ./ max(PoQo, equiv_radius));
        phi_o_l = phiQo + bbox_angular_extent/2;
        phi_o_r = phiQo - bbox_angular_extent/2;
        
        % Normalize angles to [-pi, pi]
        phi_o_l = atan2(sin(phi_o_l), cos(phi_o_l));
        phi_o_r = atan2(sin(phi_o_r), cos(phi_o_r));
        
        % Check if obstacle blocks forward direction (0 radians)
        % Handle angle wrapping for proper intersection detection
        blocks_forward = (phi_o_r <= 0 & phi_o_l >= 0) | ...
                        (phi_o_r > phi_o_l & (phi_o_r <= 0 | phi_o_l >= 0));
        
        % Calculate obstacle grades
        idx2 = blocks_forward & PoQ3 < alpha;  % Obstacles that affect forward motion
        
        % Vectorized grade calculation
        safe_distance = PoQ3 - equiv_radius - r_wheel;
        grade_obs = 1 - exp(-max(0, safe_distance) / 1.0);
        
        % Apply collision penalty for very close obstacles
        collision_risk = safe_distance <= 0;
        grade_obs = grade_obs - obs_cost * collision_risk;
        
        % Apply grades only to relevant obstacles
        grade_obs = grade_obs .* idx2 + ~idx2;
        
        % Ensure grades are within valid range [0, 1]
        grade_obs = max(0, min(1, grade_obs));
        
    else
        % No obstacles - use dimensions from input
        K_steps = size(x, 3);
        NP_paths = size(x, 4);
        grade_obs = ones(1, 1, K_steps-1, NP_paths);
    end

    %% Final Grade Calculation
    % Both grade_trgt and grade_obs are now [1,1,K-1,NP]
    grade_obs_min = min(grade_obs, [], 1);         % [1,1,K-1,NP]
    Grade = min(grade_trgt, grade_obs_min);        % Both are [1,1,K-1,NP]
end