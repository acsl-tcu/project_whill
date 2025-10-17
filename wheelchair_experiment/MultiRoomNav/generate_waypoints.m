function waypoint_segments = generate_waypoints(start_room, goal_room, start_pos, goal_pos)
%% Generate Waypoint Segments for Multi-Room Navigation
% Creates waypoint segments where robot stops 0.5m before each door
%
% Inputs:
%   start_room - Starting room ID (e.g., 'A')
%   goal_room  - Goal room ID (e.g., 'C')
%   start_pos  - [x, y] starting position in start_room
%   goal_pos   - [x, y] final goal position in goal_room
%
% Output:
%   waypoint_segments - Cell array of [start, end] position pairs
%
% Example output for path A→B→C:
%   Segment 1: start_pos → door_AB_approach (0.5m before door A→B)
%   Segment 2: door_AB_exit → door_BC_approach (0.5m before door B→C)
%   Segment 3: door_BC_exit → goal_pos

DOOR_OFFSET = 0.5; % meters before/after door

fprintf('=== Waypoint Segment Generator ===\n\n');

%% Build room network (same as find_path)
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

%% Find room sequence
fprintf('Finding room path from %s to %s...\n', start_room, goal_room);
[room_sequence, ~] = graph.findRoomPath(start_room, goal_room);

if isempty(room_sequence)
    fprintf('ERROR: No path found!\n');
    waypoint_segments = {};
    return;
end

% Display path
path_str = room_sequence{1};
for i = 2:length(room_sequence)
    path_str = [path_str, ' → ', room_sequence{i}];
end
fprintf('Room sequence: %s\n\n', path_str);

%% Generate waypoint segments
waypoint_segments = {};
num_segments = length(room_sequence); % Number of path segments

fprintf('Generating waypoint segments:\n');
fprintf('─────────────────────────────────────────────────\n');

for i = 1:num_segments
    current_room_id = room_sequence{i};
    current_room = graph.getRoom(current_room_id);

    % Determine segment start position
    if i == 1
        % First segment: start from given start position
        segment_start = start_pos;
        start_label = sprintf('Start position [%.1f, %.1f]', segment_start(1), segment_start(2));
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
        % Last segment: end at goal position
        segment_end = goal_pos;
        end_label = sprintf('Goal position [%.1f, %.1f]', segment_end(1), segment_end(2));
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

%% Visualize waypoints on room graph
visualize_waypoint_segments(graph, waypoint_segments, start_room, goal_room);

end

%% Helper Functions

function approach_pos = calculate_door_approach(door_pos, room_center, offset)
    % Calculate position 0.5m before door (approaching from room center)
    % Direction: from room center toward door
    direction = door_pos - room_center;
    direction = direction / norm(direction); % Normalize

    % Position is offset meters before the door
    approach_pos = door_pos - direction * offset;
end

function exit_pos = calculate_door_exit(door_pos, prev_room_center, next_room_center, offset)
    % Calculate position 0.5m after door (exiting into next room)
    % Direction: from previous room center through door toward next room center
    direction = next_room_center - prev_room_center;
    direction = direction / norm(direction); % Normalize

    % Position is offset meters past the door
    exit_pos = door_pos + direction * offset;
end

function visualize_waypoint_segments(graph, segments, start_room, goal_room)
    % Visualize the waypoint segments on the room graph

    figure('Name', sprintf('Waypoint Segments: %s to %s', start_room, goal_room), ...
        'Position', [100, 100, 1200, 800]);

    % Plot room graph
    graph.visualize();
    hold on;

    % Plot segments with different colors
    colors = {'red', 'green', 'blue', [1 0.5 0], [1 0 1], [0 1 1]};

    for i = 1:length(segments)
        seg = segments{i};
        color_idx = mod(i-1, length(colors)) + 1;
        color = colors{color_idx};

        % Plot segment line
        plot([seg.start(1), seg.end(1)], [seg.start(2), seg.end(2)], ...
            '-', 'Color', color, 'LineWidth', 4);

        % Plot start point
        plot(seg.start(1), seg.start(2), 'o', 'Color', color, ...
            'MarkerSize', 10, 'MarkerFaceColor', color, 'MarkerEdgeColor', 'black', 'LineWidth', 2);

        % Plot end point
        plot(seg.end(1), seg.end(2), 's', 'Color', color, ...
            'MarkerSize', 10, 'MarkerFaceColor', color, 'MarkerEdgeColor', 'black', 'LineWidth', 2);

        % Label segment
        mid_point = (seg.start + seg.end) / 2;
        text(mid_point(1), mid_point(2) + 0.5, sprintf('Seg %d', i), ...
            'HorizontalAlignment', 'center', 'FontSize', 12, 'FontWeight', 'bold', ...
            'BackgroundColor', 'white', 'EdgeColor', 'black');
    end

    title(sprintf('Waypoint Segments (%d segments)\nRobot stops 0.5m before each door', length(segments)), ...
        'FontSize', 14, 'FontWeight', 'bold');

    hold off;
end
