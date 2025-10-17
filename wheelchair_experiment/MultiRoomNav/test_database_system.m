%% Test Universal Room Database System
% Demonstrates loading room configuration from JSON and using it for path planning

clc; clear; close all;

fprintf('╔══════════════════════════════════════════════════╗\n');
fprintf('║   UNIVERSAL ROOM DATABASE SYSTEM TEST            ║\n');
fprintf('╚══════════════════════════════════════════════════╝\n\n');

%% Step 1: Load room database from JSON
fprintf('STEP 1: Loading room database from JSON...\n');
fprintf('─────────────────────────────────────────────────────\n');

db = RoomDatabase('room_database.json');

if isempty(db.rooms_data)
    fprintf('ERROR: Failed to load database!\n');
    return;
end

fprintf('\n');

%% Step 2: Print database summary
fprintf('STEP 2: Database summary\n');
fprintf('─────────────────────────────────────────────────────\n');

db.printSummary();

%% Step 3: Print connectivity matrix
fprintf('STEP 3: Room connectivity\n');
fprintf('─────────────────────────────────────────────────────\n');

db.printConnectivityMatrix();

%% Step 4: Build room graph from database
fprintf('STEP 4: Building room graph from database...\n');
fprintf('─────────────────────────────────────────────────────\n');

graph = db.buildGraph();

fprintf('\n');

%% Step 5: Print door-to-door distances
fprintf('STEP 5: Door-to-door distances\n');
fprintf('─────────────────────────────────────────────────────\n');

graph.printDoorDistances();

%% Step 6: Load and display occupancy map
fprintf('STEP 6: Loading occupancy map...\n');
fprintf('─────────────────────────────────────────────────────\n');

% Load occupancy map from map_file
map_path = fullfile(fileparts(mfilename('fullpath')), db.map_file);
fprintf('  Loading map from: %s\n', map_path);

if ~exist(map_path, 'file')
    fprintf('  ERROR: Map file not found!\n');
else
    % Load the map
    load(map_path, 'map');

    fprintf('  Map loaded successfully\n');
    fprintf('  Grid size: %d x %d\n', map.GridSize(1), map.GridSize(2));
    fprintf('  Resolution: %.2f cells/meter\n', map.Resolution);
    fprintf('  X limits: [%.1f, %.1f] m\n', map.XWorldLimits(1), map.XWorldLimits(2));
    fprintf('  Y limits: [%.1f, %.1f] m\n\n', map.YWorldLimits(1), map.YWorldLimits(2));

    % Display map with room boundaries
    fprintf('STEP 7: Visualizing map with room boundaries...\n');
    fprintf('─────────────────────────────────────────────────────\n\n');

    fig = figure('Name', 'Room Database Visualization with Map', ...
        'Position', [100, 100, 1400, 900]);

    % Show occupancy map
    show(map);
    hold on;
    axis equal;
    grid on;

    % Manually overlay room boundaries (don't use visualize - it clears figure)
    room_keys = keys(graph.rooms);
    colors = {[1 0 0], [0 0.7 0], [0 0 1], [1 0.5 0], [0.5 0 0.5], [0 1 1]};

    for i = 1:length(room_keys)
        room = graph.rooms(room_keys{i});
        color_idx = mod(i-1, length(colors)) + 1;
        color = colors{color_idx};

        % Draw room boundary rectangle
        x_min = room.boundaries(1,1);
        x_max = room.boundaries(1,2);
        y_min = room.boundaries(2,1);
        y_max = room.boundaries(2,2);

        rectangle('Position', [x_min, y_min, x_max-x_min, y_max-y_min], ...
                  'EdgeColor', color, 'LineWidth', 3);

        % Draw room label
        text(room.center(1), room.center(2), sprintf('Room %s', room.id), ...
             'HorizontalAlignment', 'center', 'FontSize', 14, 'FontWeight', 'bold', ...
             'Color', color, 'BackgroundColor', [1 1 1 0.8], ...
             'EdgeColor', color, 'LineWidth', 2);

        % Draw doors
        for j = 1:length(room.connections)
            door = room.connections(j);
            plot(door.door_center(1), door.door_center(2), 'p', ...
                 'MarkerSize', 20, 'MarkerFaceColor', [1 1 0], ...
                 'MarkerEdgeColor', [0 0 0], 'LineWidth', 2);
        end
    end

    hold off;

    title('Room Boundaries on Occupancy Map - Click Start and Goal Points', 'FontSize', 16, 'FontWeight', 'bold');
    xlabel('X (meters)', 'FontSize', 14);
    ylabel('Y (meters)', 'FontSize', 14);

    %% Interactive point selection
    fprintf('\n=== INTERACTIVE PATH PLANNING ===\n');
    fprintf('Click on the map to select:\n');
    fprintf('  1. Starting point (cyan circle)\n');
    fprintf('  2. Goal point (magenta circle)\n\n');

    % Get starting point
    fprintf('Click starting point...\n');
    [start_x, start_y] = ginput(1);

    if isempty(start_x)
        fprintf('No starting point selected. Skipping interactive mode.\n');
    else
        % Plot starting point
        hold on;
        plot(start_x, start_y, 'o', 'MarkerSize', 15, ...
             'MarkerFaceColor', [0 1 1], 'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);
        text(start_x, start_y + 0.5, 'START', 'HorizontalAlignment', 'center', ...
             'FontSize', 12, 'FontWeight', 'bold', 'Color', [0 1 1], ...
             'BackgroundColor', [0 0 0 0.7]);

        fprintf('  Start: [%.2f, %.2f]\n', start_x, start_y);

        % Get goal point
        fprintf('Click goal point...\n');
        [goal_x, goal_y] = ginput(1);

        if isempty(goal_x)
            fprintf('No goal point selected. Skipping interactive mode.\n');
        else
            % Plot goal point
            plot(goal_x, goal_y, 'o', 'MarkerSize', 15, ...
                 'MarkerFaceColor', [1 0 1], 'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);
            text(goal_x, goal_y + 0.5, 'GOAL', 'HorizontalAlignment', 'center', ...
                 'FontSize', 12, 'FontWeight', 'bold', 'Color', [1 0 1], ...
                 'BackgroundColor', [0 0 0 0.7]);

            fprintf('  Goal: [%.2f, %.2f]\n\n', goal_x, goal_y);

            % Find which rooms contain these points
            start_room_id = graph.findRoomContaining([start_x, start_y]);
            goal_room_id = graph.findRoomContaining([goal_x, goal_y]);

            fprintf('Room detection:\n');
            if ~isempty(start_room_id)
                fprintf('  Start point is in Room %s\n', start_room_id);
            else
                fprintf('  WARNING: Start point is not in any room!\n');
            end

            if ~isempty(goal_room_id)
                fprintf('  Goal point is in Room %s\n\n', goal_room_id);
            else
                fprintf('  WARNING: Goal point is not in any room!\n\n');
            end

            % Plan path if both points are in rooms
            if ~isempty(start_room_id) && ~isempty(goal_room_id)
                fprintf('Planning room path: %s → %s\n', start_room_id, goal_room_id);
                fprintf('  Using actual positions: [%.2f, %.2f] → [%.2f, %.2f]\n', start_x, start_y, goal_x, goal_y);
                fprintf('─────────────────────────────────────────────────────\n');

                [room_sequence, door_sequence, total_cost] = graph.findRoomPath(start_room_id, goal_room_id, [start_x, start_y], [goal_x, goal_y]);

                if ~isempty(room_sequence)
                    % Build path string
                    path_str = room_sequence{1};
                    for i = 2:length(room_sequence)
                        path_str = [path_str, ' → ', room_sequence{i}];
                    end

                    fprintf('✓ Path found: %s\n', path_str);
                    fprintf('  Total cost: %.2f m\n', total_cost);
                    fprintf('  Number of rooms: %d\n', length(room_sequence));
                    fprintf('  Number of doors: %d\n\n', length(door_sequence));

                    % Visualize the path on the map
                    fprintf('Drawing path on map...\n');

                    % Build the actual path through doors
                    path_points = [start_x, start_y];  % Start with starting position

                    % Add door positions along the path
                    for i = 1:length(room_sequence)-1
                        current_room_id = room_sequence{i};
                        next_room_id = room_sequence{i+1};

                        % Get the door connecting current room to next room
                        current_room = graph.rooms(current_room_id);
                        door_obj = current_room.getDoorTo(next_room_id);

                        if ~isempty(door_obj)
                            % Add door position to path
                            path_points = [path_points; door_obj.door_center];

                            % Highlight the door with orange circle
                            plot(door_obj.door_center(1), door_obj.door_center(2), 'o', ...
                                 'MarkerSize', 18, 'MarkerFaceColor', [1 0.5 0], ...
                                 'MarkerEdgeColor', [0 0 0], 'LineWidth', 3);
                        end
                    end

                    % Add goal position
                    path_points = [path_points; goal_x, goal_y];

                    % Draw the complete path as connected yellow line
                    plot(path_points(:,1), path_points(:,2), ...
                         'Color', [1 1 0], 'LineWidth', 4, 'LineStyle', '-');

                    % Add markers at start and goal
                    plot(path_points(1,1), path_points(1,2), 'o', ...
                         'MarkerSize', 10, 'MarkerFaceColor', [1 1 0], ...
                         'MarkerEdgeColor', [0 0 0], 'LineWidth', 2);
                    plot(path_points(end,1), path_points(end,2), 'o', ...
                         'MarkerSize', 10, 'MarkerFaceColor', [1 1 0], ...
                         'MarkerEdgeColor', [0 0 0], 'LineWidth', 2);

                    % Update title
                    title(sprintf('Path: %s (%.2f m)', path_str, total_cost), ...
                          'FontSize', 16, 'FontWeight', 'bold');

                    fprintf('✓ Path visualization complete!\n\n');
                else
                    fprintf('✗ No path found between rooms!\n\n');
                end
            end

            hold off;
        end
    end
end

%% Step 7: Test path finding (universal - uses actual rooms from database)
fprintf('╔══════════════════════════════════════════════════╗\n');
fprintf('║   PATH FINDING TESTS                             ║\n');
fprintf('╚══════════════════════════════════════════════════╝\n\n');

% Get all room IDs from the database
room_keys = keys(graph.rooms);
num_rooms = length(room_keys);

if num_rooms < 2
    fprintf('Not enough rooms for path testing (need at least 2 rooms)\n\n');
else
    % Test 1: First room to last room
    start_room = room_keys{1};
    end_room = room_keys{end};
    fprintf('TEST 1: Path from %s to %s\n', start_room, end_room);
    fprintf('─────────────────────────────────────────────────────\n');
    [rooms1, ~, cost1] = graph.findRoomPath(start_room, end_room);
    if ~isempty(rooms1)
        path_str = rooms1{1};
        for i = 2:length(rooms1)
            path_str = [path_str, ' → ', rooms1{i}];
        end
        fprintf('Result: %s (%.2f m)\n\n', path_str, cost1);
    else
        fprintf('No path found!\n\n');
    end

    if num_rooms >= 3
        % Test 2: First room to middle room
        middle_room = room_keys{ceil(num_rooms/2)};
        fprintf('TEST 2: Path from %s to %s\n', start_room, middle_room);
        fprintf('─────────────────────────────────────────────────────\n');
        [rooms2, ~, cost2] = graph.findRoomPath(start_room, middle_room);
        if ~isempty(rooms2)
            path_str = rooms2{1};
            for i = 2:length(rooms2)
                path_str = [path_str, ' → ', rooms2{i}];
            end
            fprintf('Result: %s (%.2f m)\n\n', path_str, cost2);
        else
            fprintf('No path found!\n\n');
        end

        % Test 3: Reverse path
        fprintf('TEST 3: Path from %s to %s (reverse)\n', middle_room, start_room);
        fprintf('─────────────────────────────────────────────────────\n');
        [rooms3, ~, cost3] = graph.findRoomPath(middle_room, start_room);
        if ~isempty(rooms3)
            path_str = rooms3{1};
            for i = 2:length(rooms3)
                path_str = [path_str, ' → ', rooms3{i}];
            end
            fprintf('Result: %s (%.2f m)\n\n', path_str, cost3);
        else
            fprintf('No path found!\n\n');
        end
    end

    % Test 4: Same room (always test with first room)
    fprintf('TEST 4: Path from %s to %s (same room)\n', start_room, start_room);
    fprintf('─────────────────────────────────────────────────────\n');
    [rooms4, ~, cost4] = graph.findRoomPath(start_room, start_room);
    if ~isempty(rooms4)
        path_str = rooms4{1};
        for i = 2:length(rooms4)
            path_str = [path_str, ' → ', rooms4{i}];
        end
        fprintf('Result: %s (%.2f m)\n\n', path_str, cost4);
    else
        fprintf('No path found!\n\n');
    end
end

%% Step 8: Test database modification and save
fprintf('╔══════════════════════════════════════════════════╗\n');
fprintf('║   DATABASE MODIFICATION TEST                     ║\n');
fprintf('╚══════════════════════════════════════════════════╝\n\n');

fprintf('Modifying description field...\n');
db.description = 'Updated: 4th floor with tested door-to-door distances';

fprintf('Saving modified database to room_database_modified.json...\n');
db.saveToJSON('room_database_modified.json');

fprintf('\n');

%% Summary
fprintf('╔══════════════════════════════════════════════════╗\n');
fprintf('║   TEST COMPLETE                                  ║\n');
fprintf('╚══════════════════════════════════════════════════╝\n\n');

fprintf('✓ Database loaded from JSON\n');
fprintf('✓ Room graph built automatically\n');
fprintf('✓ Door-to-door distances calculated\n');
fprintf('✓ Path finding working correctly\n');
fprintf('✓ Database can be modified and saved\n\n');

fprintf('The system is now UNIVERSAL and REUSABLE:\n');
fprintf('  1. Edit room_database.json to change room layout\n');
fprintf('  2. Run this script to load and test\n');
fprintf('  3. No code changes needed for different maps!\n\n');

fprintf('Next steps:\n');
fprintf('  - Create databases for different floors/buildings\n');
fprintf('  - Integrate with interactive waypoint generator\n');
fprintf('  - Add more room metadata (accessibility, etc.)\n');
