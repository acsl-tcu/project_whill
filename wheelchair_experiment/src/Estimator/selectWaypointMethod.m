function waypoint = selectWaypointMethod(initial_position, goal_position, robot_width, robot_length, safety_margin)
    % Select waypoint generation method - interactive or automatic A*
    %
    % Inputs:
    %   initial_position - [x, y] starting position
    %   goal_position - [x, y] goal position
    %   robot_width - Width of robot in meters
    %   robot_length - Length of robot in meters
    %   safety_margin - Safety margin for obstacle clearance
    %
    % Output:
    %   waypoint - Nx2 array of [x, y] waypoints

    fprintf('\n=== WAYPOINT SELECTION ===\n');
    fprintf('Do you want to manually select waypoints on the map?\n');
    fprintf('  y - Open interactive map to click waypoints\n');
    fprintf('  n - Use automatic A* pathfinding (default)\n');

    user_choice = input('Enter choice (y/n) [default: n]: ', 's');

    if strcmpi(user_choice, 'y')
        % User wants to manually select waypoints
        fprintf('Opening interactive waypoint selection...\n');
        waypoint = interactiveWaypointSelection();

        if isempty(waypoint)
            fprintf('No waypoints selected. Falling back to A* pathfinding...\n');
            waypoint = generateAStarPath(initial_position, goal_position, robot_width, robot_length, safety_margin);
        else
            fprintf('Estimate: Using custom waypoints (%d points)\n', size(waypoint, 1));
        end
    else
        % Default: Use A* pathfinding
        fprintf('Using automatic A* pathfinding...\n');
        waypoint = generateAStarPath(initial_position, goal_position, robot_width, robot_length, safety_margin);
    end

    fprintf('==========================\n\n');
end

function waypoint = generateAStarPath(initial_position, goal_position, robot_width, robot_length, safety_margin)
    % Generate path using A* algorithm with fallback to original method

    try
        [waypoint, ~, ~, ~, ~] = PathSetting_AStar(initial_position, goal_position, robot_width, robot_length, safety_margin);
        fprintf('Estimate: Using A* generated waypoints (%d points) with vehicle size %.2fx%.2fm, safety margin %.2fm\n', ...
            size(waypoint, 1), robot_width, robot_length, safety_margin);
    catch ME
        fprintf('Estimate: A* pathfinding failed (%s), using original waypoints\n', ME.message);
        [waypoint, ~, ~, ~, ~] = PathSetting_original;
    end
end
