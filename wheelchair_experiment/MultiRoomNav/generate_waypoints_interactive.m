function waypoint_segments = generate_waypoints_interactive()
%% Interactive Waypoint Segment Generator
% Click on the map to select start and goal positions
% Automatically detects which rooms contain the positions
% Generates waypoint segments with 0.5m stops before doors
%
% Usage:
%   segments = generate_waypoints_interactive()
%
% Instructions:
%   1. Click on the map for START position (green circle will appear)
%   2. Click on the map for GOAL position (red circle will appear)
%   3. Waypoint segments will be generated automatically

DOOR_OFFSET = 0.5; % meters before/after door

%% Build room network
fprintf('=== Interactive Waypoint Generator ===\n\n');
fprintf('Building room network...\n');

roomA = RoomNode('A', [4, 6], [0, 8; 4, 8]);
roomB = RoomNode('B', [15, 6], [8, 22; 4, 8]);
roomC = RoomNode('C', [26, 6], [22, 30; 4, 8]);
roomD = RoomNode('D', [19, -1], [8, 30; -5, 4]);

% Connections
roomA.addConnection(DoorConnection('B', [8, 6], 1.5, 1.0));
roomB.addConnection(DoorConnection('A', [8, 6], 1.5, 1.0));
roomB.addConnection(DoorConnection('C', [22, 6], 1.5, 1.0));
roomC.addConnection(DoorConnection('B', [22, 6], 1.5, 1.0));
roomB.addConnection(DoorConnection('D', [15, 4], 1.5, 1.0));
roomD.addConnection(DoorConnection('B', [15, 4], 1.5, 1.0));
roomC.addConnection(DoorConnection('D', [26, 4], 1.5, 1.0));
roomD.addConnection(DoorConnection('C', [26, 4], 1.5, 1.0));

graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);
graph.addRoom(roomC);
graph.addRoom(roomD);

%% Display room map
fprintf('Displaying room map...\n');
fig = figure('Name', 'Interactive Waypoint Generator - Click Start and Goal', ...
    'Position', [100, 100, 1200, 800]);
graph.visualize();
hold on;

title('Click on map: (1) START position, (2) GOAL position', ...
    'FontSize', 16, 'FontWeight', 'bold', 'Color', [0 0 1]);

%% Get START position by clicking
fprintf('\n>>> Click on the map to select START position...\n');
[start_x, start_y] = ginput(1);
start_pos = [start_x, start_y];

% Plot start position
plot(start_pos(1), start_pos(2), 'o', 'Color', [0 0.8 0], ...
    'MarkerSize', 20, 'MarkerFaceColor', [0 0.8 0], 'LineWidth', 3);
text(start_pos(1), start_pos(2) + 1, 'START', ...
    'HorizontalAlignment', 'center', 'FontSize', 14, 'FontWeight', 'bold', ...
    'Color', [0 0.8 0], 'BackgroundColor', 'white', 'EdgeColor', 'black');

fprintf('  Start position: [%.2f, %.2f]\n', start_pos(1), start_pos(2));

% Detect start room
start_room_id = graph.findRoomContaining(start_pos);
if isempty(start_room_id)
    fprintf('  ERROR: Start position is not inside any room!\n');
    fprintf('  Please click inside a room boundary.\n');
    waypoint_segments = {};
    return;
end
fprintf('  Detected in Room: %s\n', start_room_id);

%% Get GOAL position by clicking
fprintf('\n>>> Click on the map to select GOAL position...\n');
[goal_x, goal_y] = ginput(1);
goal_pos = [goal_x, goal_y];

% Plot goal position
plot(goal_pos(1), goal_pos(2), 's', 'Color', [1 0 0], ...
    'MarkerSize', 20, 'MarkerFaceColor', [1 0 0], 'LineWidth', 3);
text(goal_pos(1), goal_pos(2) + 1, 'GOAL', ...
    'HorizontalAlignment', 'center', 'FontSize', 14, 'FontWeight', 'bold', ...
    'Color', [1 0 0], 'BackgroundColor', 'white', 'EdgeColor', 'black');

fprintf('  Goal position: [%.2f, %.2f]\n', goal_pos(1), goal_pos(2));

% Detect goal room
goal_room_id = graph.findRoomContaining(goal_pos);
if isempty(goal_room_id)
    fprintf('  ERROR: Goal position is not inside any room!\n');
    fprintf('  Please click inside a room boundary.\n');
    waypoint_segments = {};
    return;
end
fprintf('  Detected in Room: %s\n', goal_room_id);

%% Find room sequence
fprintf('\n─────────────────────────────────────────────────\n');
fprintf('Finding path from Room %s to Room %s...\n', start_room_id, goal_room_id);

[room_sequence, ~] = graph.findRoomPath(start_room_id, goal_room_id);

if isempty(room_sequence)
    fprintf('ERROR: No path found between rooms!\n');
    waypoint_segments = {};
    return;
end

% Display path
path_str = room_sequence{1};
for i = 2:length(room_sequence)
    path_str = [path_str, ' → ', room_sequence{i}];
end
fprintf('Room sequence: %s\n', path_str);
fprintf('─────────────────────────────────────────────────\n\n');

%% Generate waypoint segments
waypoint_segments = {};
num_segments = length(room_sequence);

fprintf('Generating waypoint segments:\n');
fprintf('─────────────────────────────────────────────────\n');

for i = 1:num_segments
    current_room_id = room_sequence{i};
    current_room = graph.getRoom(current_room_id);

    % Determine segment start position
    if i == 1
        % First segment: start from clicked position
        segment_start = start_pos;
        start_label = sprintf('Start [%.1f, %.1f]', segment_start(1), segment_start(2));
    else
        % Later segments: start from exit of previous door
        prev_room_id = room_sequence{i-1};
        prev_room = graph.getRoom(prev_room_id);
        door_prev = prev_room.getDoorTo(current_room_id);

        % Calculate position 0.5m after door (entry into current room)
        segment_start = calculate_door_exit(door_prev.door_center, prev_room.center, current_room.center, DOOR_OFFSET);
        start_label = sprintf('Exit door %s→%s [%.1f, %.1f]', prev_room_id, current_room_id, segment_start(1), segment_start(2));
    end

    % Determine segment end position
    if i == num_segments
        % Last segment: end at clicked goal position
        segment_end = goal_pos;
        end_label = sprintf('Goal [%.1f, %.1f]', segment_end(1), segment_end(2));
    else
        % Intermediate segments: end 0.5m before next door
        next_room_id = room_sequence{i+1};
        door_next = current_room.getDoorTo(next_room_id);

        % Calculate position 0.5m before door (approach to door)
        segment_end = calculate_door_approach(door_next.door_center, current_room.center, DOOR_OFFSET);
        end_label = sprintf('Approach door %s→%s [%.1f, %.1f]', current_room_id, next_room_id, segment_end(1), segment_end(2));
    end

    % Store segment
    waypoint_segments{i} = struct('start', segment_start, 'end', segment_end, ...
                                  'room', current_room_id, ...
                                  'start_label', start_label, ...
                                  'end_label', end_label);

    % Display segment info
    fprintf('Segment %d (Room %s):\n', i, current_room_id);
    fprintf('  Start: %s\n', start_label);
    fprintf('  End:   %s\n', end_label);
    fprintf('  Distance: %.2f m\n', norm(segment_end - segment_start));
    fprintf('\n');
end

fprintf('─────────────────────────────────────────────────\n');
fprintf('Total segments: %d\n', num_segments);
fprintf('=================================================\n\n');

%% Visualize waypoints on the map
visualize_segments_on_map(waypoint_segments);

hold off;

end

%% Helper Functions

function approach_pos = calculate_door_approach(door_pos, room_center, offset)
    % Calculate position 0.5m before door (approaching from room center)
    direction = door_pos - room_center;
    direction = direction / norm(direction); % Normalize
    approach_pos = door_pos - direction * offset;
end

function exit_pos = calculate_door_exit(door_pos, prev_room_center, next_room_center, offset)
    % Calculate position 0.5m after door (exiting into next room)
    direction = next_room_center - prev_room_center;
    direction = direction / norm(direction); % Normalize
    exit_pos = door_pos + direction * offset;
end

function visualize_segments_on_map(segments)
    % Visualize the waypoint segments on the current figure

    % Plot segments with different colors
    colors = {[1 0 0], [0 0.7 0], [0 0 1], [1 0.5 0], [1 0 1], [0 1 1]};

    for i = 1:length(segments)
        seg = segments{i};
        color_idx = mod(i-1, length(colors)) + 1;
        color = colors{color_idx};

        % Plot segment line (thick)
        plot([seg.start(1), seg.end(1)], [seg.start(2), seg.end(2)], ...
            '-', 'Color', color, 'LineWidth', 5);

        % Plot start point
        plot(seg.start(1), seg.start(2), 'o', 'Color', color, ...
            'MarkerSize', 12, 'MarkerFaceColor', color, 'MarkerEdgeColor', 'black', 'LineWidth', 2);

        % Plot end point
        plot(seg.end(1), seg.end(2), 's', 'Color', color, ...
            'MarkerSize', 12, 'MarkerFaceColor', color, 'MarkerEdgeColor', 'black', 'LineWidth', 2);

        % Label segment
        mid_point = (seg.start + seg.end) / 2;
        text(mid_point(1), mid_point(2) + 0.8, sprintf('Seg %d', i), ...
            'HorizontalAlignment', 'center', 'FontSize', 13, 'FontWeight', 'bold', ...
            'BackgroundColor', 'white', 'EdgeColor', color, 'LineWidth', 2);
    end

    title(sprintf('Waypoint Segments (%d segments) - Robot stops 0.5m before each door', length(segments)), ...
        'FontSize', 14, 'FontWeight', 'bold');
end
