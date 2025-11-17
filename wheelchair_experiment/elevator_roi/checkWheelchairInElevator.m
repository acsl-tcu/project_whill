function is_inside = checkWheelchairInElevator(wheelchair_pos, elevator_pose, W, L)
% CHECKWHEELCHAIRINELEVATOR - Check if wheelchair position is inside elevator
%
% Inputs:
%   wheelchair_pos  - [x, y] position of wheelchair (meters)
%   elevator_pose   - Structure with .x, .y, .theta (from fitElevatorSimplified)
%   W               - Elevator width (meters)
%   L               - Elevator length/depth (meters)
%
% Output:
%   is_inside - Boolean, true if wheelchair is inside elevator rectangle
%
% Algorithm:
%   1. Transform wheelchair position to elevator-aligned frame
%   2. Check if position is within rectangle bounds [±L/2, ±W/2]
%
% Example:
%   elevator_pose = fitElevatorSimplified(lidar_points, wheelchair.heading, 1.5, 2.0);
%   is_inside = checkWheelchairInElevator([5.2, 3.1], elevator_pose, 1.5, 2.0);
%   if is_inside
%       fprintf('Wheelchair has entered elevator!\n');
%   end

% Transform wheelchair position relative to elevator center
dx = wheelchair_pos(1) - elevator_pose.x;
dy = wheelchair_pos(2) - elevator_pose.y;

% Rotate to elevator-aligned frame
x_aligned = dx * cos(-elevator_pose.theta) - dy * sin(-elevator_pose.theta);
y_aligned = dx * sin(-elevator_pose.theta) + dy * cos(-elevator_pose.theta);

% Simple rectangle boundary check
is_inside = (abs(x_aligned) < L/2) && (abs(y_aligned) < W/2);

end
