function [target,wall] = Discrimination(obj,px,i,j)

    if px(2,i+1,j) > 1 || px(1,i+1,j) <-6
        target = [obj.waypoint(1,1) obj.waypoint(1,2)];
        wall = [-11 -6 ;-inf inf];
    else%if px(2,i+1,j) > 0.5 || px(2,i+1,j) < 1 || px(1,i+1,j) <-7
        target = [obj.waypoint(2,1) obj.waypoint(2,2)];
        wall = [-inf inf ;-1 1];
%      else
%          target = [obj.waypoint(3,1) obj.waypoint(3,2)];
%          wall = [-inf inf ;-0.95 0.95];
    end
end