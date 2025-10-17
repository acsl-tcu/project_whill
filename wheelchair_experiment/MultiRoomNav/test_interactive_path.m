function test_interactive_path(start_room, goal_room)
%% Interactive Room Path Finder
% Usage: test_interactive_path('A', 'C')
%        test_interactive_path('C', 'A')
%        test_interactive_path('B', 'D')
%
% Tests pathfinding between any two rooms in a 4-room network

clc;

fprintf('=== Interactive Room Path Finder ===\n\n');

%% Build 4-room network: A ↔ B ↔ C ↔ D

fprintf('Building room network...\n');

% Create 4 rooms
roomA = RoomNode('A', [4, 0], [0, 8; -2, 2]);
roomB = RoomNode('B', [15, 0], [8, 22; -2, 2]);
roomC = RoomNode('C', [26, 0], [22, 30; -2, 2]);
roomD = RoomNode('D', [37, 0], [30, 44; -2, 2]);

fprintf('  Room A: [0-8, -2 to 2]\n');
fprintf('  Room B: [8-22, -2 to 2]\n');
fprintf('  Room C: [22-30, -2 to 2]\n');
fprintf('  Room D: [30-44, -2 to 2]\n');

% Connect rooms in a chain: A ↔ B ↔ C ↔ D
fprintf('\nConnections:\n');

% A ↔ B
roomA.addConnection(DoorConnection('B', [8, 0], 1.5, 1.0));
roomB.addConnection(DoorConnection('A', [8, 0], 1.5, 1.0));
fprintf('  A ↔ B (door at [8, 0])\n');

% B ↔ C
roomB.addConnection(DoorConnection('C', [22, 0], 1.5, 1.0));
roomC.addConnection(DoorConnection('B', [22, 0], 1.5, 1.0));
fprintf('  B ↔ C (door at [22, 0])\n');

% C ↔ D
roomC.addConnection(DoorConnection('D', [30, 0], 1.5, 1.0));
roomD.addConnection(DoorConnection('C', [30, 0], 1.5, 1.0));
fprintf('  C ↔ D (door at [30, 0])\n');

fprintf('\nNetwork structure: A ↔ B ↔ C ↔ D\n');

% Build graph
graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);
graph.addRoom(roomC);
graph.addRoom(roomD);

%% Visualize network

fprintf('\nVisualizing room network...\n');
fig = figure('Name', sprintf('Path from %s to %s', start_room, goal_room), ...
    'Position', [100, 100, 1400, 600]);
graph.visualize(fig);

%% Find path

fprintf('\n========================================\n');
fprintf('PATHFINDING REQUEST\n');
fprintf('========================================\n');
fprintf('Start room: %s\n', start_room);
fprintf('Goal room:  %s\n', goal_room);
fprintf('----------------------------------------\n\n');

% Run Dijkstra
[room_sequence, total_cost] = graph.findRoomPath(start_room, goal_room);

%% Display result

if isempty(room_sequence)
    fprintf('❌ FAILED: No path found!\n');
    fprintf('Possible reasons:\n');
    fprintf('  - Room %s or %s does not exist\n', start_room, goal_room);
    fprintf('  - Rooms are not connected\n\n');
    fprintf('Available rooms: A, B, C, D\n');
    return;
end

fprintf('✅ SUCCESS! Path found:\n\n');
fprintf('========================================\n');
fprintf('RESULT\n');
fprintf('========================================\n');

% Build path string manually
path_str = room_sequence{1};
for k = 2:length(room_sequence)
    path_str = [path_str, ' → ', room_sequence{k}];
end

fprintf('Room sequence: %s\n', path_str);
fprintf('Number of hops: %d\n', length(room_sequence) - 1);
fprintf('Total cost: %.2f\n', total_cost);
fprintf('========================================\n\n');

%% Display detailed path

fprintf('Detailed path breakdown:\n');
fprintf('----------------------------------------\n');

for i = 1:length(room_sequence)
    room_id = room_sequence{i};
    room = graph.getRoom(room_id);

    fprintf('%d. Room %s (center: [%.1f, %.1f])\n', ...
        i, room_id, room.center(1), room.center(2));

    if i < length(room_sequence)
        % Show door to next room
        next_room_id = room_sequence{i+1};
        door = room.getDoorTo(next_room_id);

        fprintf('   ├─ Exit through door at [%.1f, %.1f]\n', ...
            door.door_center(1), door.door_center(2));
        fprintf('   └─ Enter Room %s\n\n', next_room_id);
    else
        fprintf('   └─ DESTINATION REACHED!\n');
    end
end

fprintf('========================================\n\n');

%% Verify expected path

fprintf('Path verification:\n');
fprintf('----------------------------------------\n');

% Calculate expected number of hops
rooms_order = {'A', 'B', 'C', 'D'};
start_idx = find(strcmp(rooms_order, start_room));
goal_idx = find(strcmp(rooms_order, goal_room));

if ~isempty(start_idx) && ~isempty(goal_idx)
    expected_hops = abs(goal_idx - start_idx);
    actual_hops = length(room_sequence) - 1;

    fprintf('Expected hops: %d\n', expected_hops);
    fprintf('Actual hops:   %d\n', actual_hops);

    if expected_hops == actual_hops
        fprintf('✓ Path is OPTIMAL (shortest possible)\n');
    else
        fprintf('⚠ Path may not be optimal\n');
    end
else
    fprintf('Cannot verify (unknown room)\n');
end

fprintf('----------------------------------------\n\n');

%% Example usage

fprintf('========================================\n');
fprintf('TRY THESE EXAMPLES:\n');
fprintf('========================================\n');
fprintf('test_interactive_path(''A'', ''D'')  → A → B → C → D (3 hops)\n');
fprintf('test_interactive_path(''D'', ''A'')  → D → C → B → A (3 hops)\n');
fprintf('test_interactive_path(''A'', ''C'')  → A → B → C (2 hops)\n');
fprintf('test_interactive_path(''B'', ''D'')  → B → C → D (2 hops)\n');
fprintf('test_interactive_path(''A'', ''B'')  → A → B (1 hop)\n');
fprintf('test_interactive_path(''A'', ''A'')  → A (0 hops, same room)\n');
fprintf('========================================\n');

end
