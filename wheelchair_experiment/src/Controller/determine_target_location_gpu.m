function tgt_n = determine_target_location_gpu(obj,px) %#codegen
% waypointの更新
w0 = reshape(obj.waypoint(obj.target_n-1,:)',1,2,obj.K,obj.NP);
w1 = reshape(obj.waypoint(obj.target_n  ,:)',1,2,obj.K,obj.NP);
robot = reshape(px(1:2,:,:), [1, 2, obj.K, obj.NP]);
flag_next = squeeze(dot(w1-w0,robot-w1,2)>=0) & obj.target_n~=size(obj.waypoint,1);
tgt_n = obj.target_n + flag_next;