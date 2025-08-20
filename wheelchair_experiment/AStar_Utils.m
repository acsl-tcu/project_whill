function path = pathPlanningOccupancyGrid(start, goal, occ_matrix, resolution, map_origin, robot_width, robot_height)
    % A* path planning using occupancy grid
    % Inputs:
    %   start - [x, y] start position in world coordinates
    %   goal - [x, y] goal position in world coordinates  
    %   occ_matrix - occupancy grid matrix (0=free, 1=occupied)
    %   resolution - cells per meter
    %   map_origin - [x, y] world coordinate of grid origin
    %   robot_width - robot width in meters
    %   robot_height - robot height in meters
    % Output:
    %   path - [x1,y1; x2,y2; ...] waypoints in world coordinates
    
    [rows, cols] = size(occ_matrix);
    
    % Convert world coordinates to grid coordinates
    start_c = round((start(1) - map_origin(1)) * resolution) + 1;
    start_r = rows - round((start(2) - map_origin(2)) * resolution);
    goal_c = round((goal(1) - map_origin(1)) * resolution) + 1;
    goal_r = rows - round((goal(2) - map_origin(2)) * resolution);
    
    % Bounds checking
    start_r = max(1, min(rows, start_r));
    start_c = max(1, min(cols, start_c));
    goal_r = max(1, min(rows, goal_r));
    goal_c = max(1, min(cols, goal_c));
    
    % Inflate obstacles for robot size
    clearance_cells = ceil(max(robot_width, robot_height) * resolution / 2) + 1;
    inflated_map = inflateMap(occ_matrix, clearance_cells);
    
    % A* pathfinding
    path_indices = astar([start_r, start_c], [goal_r, goal_c], inflated_map);
    
    if isempty(path_indices)
        path = [];
        return;
    end
    
    % Convert back to world coordinates
    path = [];
    for i = 1:size(path_indices, 1)
        r = path_indices(i, 1);
        c = path_indices(i, 2);
        world_x = map_origin(1) + (c - 1) / resolution;
        world_y = map_origin(2) + (rows - r) / resolution;
        path = [path; world_x, world_y];
    end
end

function inflated_map = inflateMap(occ_matrix, clearance)
    % Inflate obstacles by clearance distance
    [rows, cols] = size(occ_matrix);
    inflated_map = occ_matrix;
    
    for r = 1:rows
        for c = 1:cols
            if occ_matrix(r, c) >= 0.5
                % This cell is occupied, inflate around it
                r_min = max(1, r - clearance);
                r_max = min(rows, r + clearance);
                c_min = max(1, c - clearance);
                c_max = min(cols, c + clearance);
                
                inflated_map(r_min:r_max, c_min:c_max) = 1;
            end
        end
    end
end

function path = astar(start, goal, obstacle_map)
    % Simple A* implementation
    % Inputs: start, goal as [row, col], obstacle_map as 2D matrix
    % Output: path as [r1,c1; r2,c2; ...] in grid coordinates
    
    [rows, cols] = size(obstacle_map);
    
    % Initialize
    open_set = [start, 0, heuristic(start, goal)]; % [r, c, g_score, f_score]
    closed_set = false(rows, cols);
    came_from = zeros(rows, cols, 2);
    g_score = inf(rows, cols);
    g_score(start(1), start(2)) = 0;
    
    directions = [-1,0; 1,0; 0,-1; 0,1; -1,-1; -1,1; 1,-1; 1,1];
    costs = [1, 1, 1, 1, sqrt(2), sqrt(2), sqrt(2), sqrt(2)];
    
    while size(open_set, 1) > 0
        % Find node with lowest f_score
        [~, idx] = min(open_set(:, 4));
        current = open_set(idx, 1:2);
        open_set(idx, :) = [];
        
        if current(1) == goal(1) && current(2) == goal(2)
            % Reconstruct path
            path = [];
            while ~(current(1) == start(1) && current(2) == start(2))
                path = [current; path];
                parent = squeeze(came_from(current(1), current(2), :))';
                current = parent;
            end
            path = [start; path];
            return;
        end
        
        closed_set(current(1), current(2)) = true;
        
        % Explore neighbors
        for d = 1:size(directions, 1)
            neighbor = current + directions(d, :);
            
            if neighbor(1) < 1 || neighbor(1) > rows || neighbor(2) < 1 || neighbor(2) > cols
                continue;
            end
            
            if closed_set(neighbor(1), neighbor(2)) || obstacle_map(neighbor(1), neighbor(2)) >= 0.5
                continue;
            end
            
            tentative_g = g_score(current(1), current(2)) + costs(d);
            
            if tentative_g < g_score(neighbor(1), neighbor(2))
                came_from(neighbor(1), neighbor(2), :) = current;
                g_score(neighbor(1), neighbor(2)) = tentative_g;
                f_score = tentative_g + heuristic(neighbor, goal);
                
                % Add to open set if not already there
                in_open = false;
                for j = 1:size(open_set, 1)
                    if open_set(j, 1) == neighbor(1) && open_set(j, 2) == neighbor(2)
                        open_set(j, :) = [neighbor, tentative_g, f_score];
                        in_open = true;
                        break;
                    end
                end
                
                if ~in_open
                    open_set = [open_set; neighbor, tentative_g, f_score];
                end
            end
        end
    end
    
    path = []; % No path found
end

function h = heuristic(a, b)
    % Euclidean distance heuristic
    h = sqrt((a(1) - b(1))^2 + (a(2) - b(2))^2);
end