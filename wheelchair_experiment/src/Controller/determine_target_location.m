function tgt_n = determine_target_location(obj,px)
% waypointの更新
% Extract scalar index (target_n is often [1,1] array, we need just first element)
target_idx = obj.target_n(1,1);

% Handle edge case when target_n is 1 (can't access index 0)
prev_idx = max(1, target_idx-1);

% Get waypoints (handle both CPU and GPU arrays)
% Extract x,y coordinates separately to avoid reshape issues with GPU arrays
w0_x = obj.waypoint(prev_idx, 1);  % Scalar x
w0_y = obj.waypoint(prev_idx, 2);  % Scalar y
w1_x = obj.waypoint(target_idx, 1); % Scalar x
w1_y = obj.waypoint(target_idx, 2); % Scalar y

% Create [1, 2, K, NP] arrays by replicating scalars
w0 = zeros(1, 2, obj.K, obj.NP, 'like', px);  % Match data type of px
w0(1, 1, :, :) = w0_x;
w0(1, 2, :, :) = w0_y;

w1 = zeros(1, 2, obj.K, obj.NP, 'like', px);
w1(1, 1, :, :) = w1_x;
w1(1, 2, :, :) = w1_y;

robot = reshape(px(1:2,:,:), [1, 2, obj.K, obj.NP]);
flag_next = squeeze(dot(w1-w0,robot-w1,2)>=0) & target_idx~=size(obj.waypoint,1);
tgt_n = target_idx + flag_next;