function [Grade, Grade_old] = FPM_boundingbox(obj, x, y, th, boundingBoxes, target, param_FPM)
% FPM_boundingbox - Fuzzy Potential Method using oriented rectangular bounding boxes
% Replaces capsule-based obstacle representation with rectangular bounding boxes
% for better fit to rectangular obstacles (furniture, doors, walls)
%
% Inputs:
%   obj          - wheelchair object with parameters
%   x, y, th     - current wheelchair position and orientation
%   boundingBoxes - cell array of bounding box structures from Estimate.m
%   target       - target position [x, y]
%   param_FPM    - FPM parameters structure
%
% Outputs:
%   Grade        - FPM grade for current direction (0 = collision, 1 = free)
%   Grade_old    - Combined grade considering all obstacles

    %% FPM Parameters
    eta = param_FPM.eta;            % Goal PMF ratio (min/max)
    alpha = param_FPM.alpha;        % Distance threshold for obstacle consideration
    margin = param_FPM.margin;      % Safety margin around obstacles
    obs_cost = param_FPM.obs_cost;  % Collision cost penalty
    
    %% Wheelchair Parameters
    state = [x y];                          % Wheelchair position
    a_wheel = obj.wheel_width;              % Wheelchair width
    b_wheel = obj.wheel_len_front;          % Wheelchair length
    r_wheel = norm([a_wheel b_wheel]);      % Wheelchair radius (corner distance)
    
    %% Goal Parameters  
    goal = target;                          % Target position
    
    %% Process Bounding Boxes
    if isempty(boundingBoxes)
        obsnum = 0;
        bbox_distances = [];
        phio_max = [];
        phio_min = [];
        grade_obs = [];
    else
        obsnum = length(boundingBoxes);
        bbox_distances = zeros(obsnum, 1);
        phio_max = zeros(obsnum, 1);
        phio_min = zeros(obsnum, 1);
        grade_obs = ones(obsnum, 1);
    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% PMF of Goal (begin)
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    g_a = 1.0;                              % PMF maximum value for goal
    g_b = eta * g_a;                        % PMF minimum value for goal
    
    phig = atan2((goal(1,2) - y), (goal(1,1) - x)) - th;     % Direction to goal
    phaierror = atan2(sin(phig - 0), cos(phig - 0));
    grade_trgt = -((g_a - g_b)/pi) * abs(phaierror) + g_a;    % PMF of Goal
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% PMF of Obstacles (begin) - Bounding Box Processing
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    if obsnum > 0
        % Transform to wheelchair coordinate frame
        R = [cos(-th), -sin(-th); sin(-th), cos(-th)];
        
        for i = 1:obsnum
            bbox = boundingBoxes{i};
            
            % Get bounding box parameters
            bbox_center = bbox.center(1:2);        % [x, y] center (ignore z)
            bbox_dims = bbox.dimensions(1:2);       % [length, width] (ignore height)
            bbox_orient = bbox.orientation;         % Rotation angle
            
            % Transform bbox center to wheelchair frame
            bbox_center_wf = (R * (bbox_center - state)')';
            
            % Calculate distance and angle to bbox center
            d_center = norm(bbox_center_wf);
            phio_center = atan2(bbox_center_wf(2), bbox_center_wf(1));
            
            % Get bounding box corners in world frame
            corners_world = bbox.corners;  % 4x2 matrix of corner points
            
            % Transform corners to wheelchair frame
            corners_wf = zeros(4, 2);
            for j = 1:4
                corners_wf(j, :) = (R * (corners_world(j, :) - state)')';
            end
            
            % Calculate minimum distance from wheelchair to bounding box
            [min_dist, closest_point] = distanceToRectangle(bbox_center_wf, ...
                bbox_dims(1), bbox_dims(2), bbox_orient - th, [0, 0]);
            
            bbox_distances(i) = min_dist;
            
            % Calculate angular range occupied by bounding box
            [phi_min, phi_max] = calculateAngularRange(corners_wf, [0, 0]);
            
            phio_min(i) = phi_min;
            phio_max(i) = phi_max;
            
            % Calculate obstacle grade based on distance and angular overlap
            if (phio_min(i) <= 0) && (0 <= phio_max(i))  % Obstacle blocks forward direction
                if d_center < alpha  % Within consideration distance
                    % Calculate grade based on minimum distance to rectangle
                    effective_margin = margin + r_wheel;
                    safe_distance = min_dist - effective_margin;
                    
                    if safe_distance > 0
                        % Safe - exponential decay from safe distance
                        grade_obs(i) = 1 - exp(-safe_distance / 1.0);
                    else
                        % Collision risk - apply penalty
                        grade_obs(i) = exp(safe_distance / 1.0) - obs_cost;
                    end
                    
                    % Ensure minimum grade is not negative
                    if grade_obs(i) < 0
                        grade_obs(i) = 0;
                    end
                else
                    % Too far to consider
                    grade_obs(i) = 1.0;
                end
            else
                % Obstacle doesn't block forward direction
                grade_obs(i) = 1.0;
            end
        end
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% PMF of Obstacles (end)
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    %% Final PMF Calculation
    if isempty(grade_obs)
        Grade_old = grade_trgt;
    else
        Grade_old = min(grade_trgt, min(grade_obs));
    end
    
    Grade = -10;  % Placeholder (matches original FPM_capsule structure)
end

%% Helper Functions

function [min_dist, closest_point] = distanceToRectangle(rect_center, length, width, orientation, point)
    % Calculate minimum distance from a point to an oriented rectangle
    % 
    % Inputs:
    %   rect_center - [x, y] center of rectangle
    %   length, width - rectangle dimensions
    %   orientation - rotation angle of rectangle (radians)
    %   point - [x, y] point to measure distance from
    %
    % Outputs:
    %   min_dist - minimum distance from point to rectangle
    %   closest_point - closest point on rectangle to the input point
    
    % Translate point to rectangle's local coordinate system
    relative_point = point - rect_center;
    
    % Rotate to align with rectangle axes
    cos_theta = cos(-orientation);
    sin_theta = sin(-orientation);
    
    local_point = [cos_theta * relative_point(1) - sin_theta * relative_point(2), ...
                   sin_theta * relative_point(1) + cos_theta * relative_point(2)];
    
    % Half dimensions
    half_length = length / 2;
    half_width = width / 2;
    
    % Clamp to rectangle bounds in local coordinates
    clamped_x = max(-half_length, min(half_length, local_point(1)));
    clamped_y = max(-half_width, min(half_width, local_point(2)));
    
    closest_local = [clamped_x, clamped_y];
    
    % Transform back to world coordinates
    closest_world = [cos_theta * closest_local(1) + sin_theta * closest_local(2), ...
                    -sin_theta * closest_local(1) + cos_theta * closest_local(2)];
    closest_point = closest_world + rect_center;
    
    % Calculate distance
    min_dist = norm(local_point - closest_local);
    
    % If point is inside rectangle, distance is 0
    if abs(local_point(1)) <= half_length && abs(local_point(2)) <= half_width
        min_dist = 0;
        closest_point = point;  % Point is inside, so closest point is the point itself
    end
end

function [phi_min, phi_max] = calculateAngularRange(corners, center_point)
    % Calculate angular range occupied by a polygon (bounding box)
    % from a given center point
    %
    % Inputs:
    %   corners - Nx2 matrix of corner points
    %   center_point - [x, y] reference point
    %
    % Outputs:
    %   phi_min, phi_max - angular range in radians
    
    if size(corners, 1) < 3
        phi_min = 0;
        phi_max = 0;
        return;
    end
    
    % Calculate angles to all corners
    angles = zeros(size(corners, 1), 1);
    for i = 1:size(corners, 1)
        relative_pos = corners(i, :) - center_point;
        angles(i) = atan2(relative_pos(2), relative_pos(1));
    end
    
    % Handle angle wrapping to find the correct angular span
    angles = sort(angles);
    
    % Find the largest gap between consecutive angles
    gaps = diff([angles; angles(1) + 2*pi]);
    [max_gap, max_gap_idx] = max(gaps);
    
    if max_gap > pi
        % Large gap exists, span is everything except the gap
        phi_min = angles(mod(max_gap_idx, length(angles)) + 1);
        phi_max = angles(max_gap_idx);
    else
        % No large gap, span from min to max
        phi_min = angles(1);
        phi_max = angles(end);
    end
    
    % Normalize to [-pi, pi]
    phi_min = atan2(sin(phi_min), cos(phi_min));
    phi_max = atan2(sin(phi_max), cos(phi_max));
    
    % Ensure proper ordering
    if phi_min > phi_max
        phi_max = phi_max + 2*pi;
    end
end