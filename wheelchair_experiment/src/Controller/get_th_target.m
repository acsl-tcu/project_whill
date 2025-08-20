function th_target = get_th_target(waypoints)
th_target = NaN(size(waypoints,1),1);
for i =2:size(waypoints,1)
    th_target(i,1) = atan2(waypoints(i,2)-waypoints(i-1,2),waypoints(i,1)-waypoints(i-1,1));
end