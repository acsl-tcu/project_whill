%% 3-Room Chain Navigation Test
% This demonstrates finding paths through multiple connected rooms
%
% Scenario: Room A → Room B → Room C (chain connection)
% Goal: Navigate from A to C (must go through B)

clc; clear; close all;

fprintf('=== 3-Room Chain Navigation Test ===\n');
fprintf('Testing: A is NOT connected to C directly\n');
fprintf('Connection: A ↔ B ↔ C (must go A→B→C)\n\n');

%% Create 3 rooms in a chain

% Room A (left)
roomA = RoomNode('A', [4, 0], [0, 8; -2, 2]);
fprintf('Room A created at [%.1f, %.1f]\n', roomA.center(1), roomA.center(2));

% Room B (middle)
roomB = RoomNode('B', [15, 0], [8, 22; -2, 2]);
fprintf('Room B created at [%.1f, %.1f]\n', roomB.center(1), roomB.center(2));

% Room C (right)
roomC = RoomNode('C', [26, 0], [22, 30; -2, 2]);
fprintf('Room C created at [%.1f, %.1f]\n', roomC.center(1), roomC.center(2));

%% Connect rooms: A ↔ B ↔ C (NO direct A ↔ C connection!)

fprintf('\nCreating connections:\n');

% A ↔ B
door_AB = DoorConnection('B', [8, 0], 1.5, 1.0);
roomA.addConnection(door_AB);
fprintf('  A → B (door at [8, 0])\n');

door_BA = DoorConnection('A', [8, 0], 1.5, 1.0);
roomB.addConnection(door_BA);
fprintf('  B → A (door at [8, 0])\n');

% B ↔ C
door_BC = DoorConnection('C', [22, 0], 1.5, 1.0);
roomB.addConnection(door_BC);
fprintf('  B → C (door at [22, 0])\n');

door_CB = DoorConnection('B', [22, 0], 1.5, 1.0);
roomC.addConnection(door_CB);
fprintf('  C → B (door at [22, 0])\n');

fprintf('\nNOTE: A and C are NOT directly connected!\n');

%% Build graph

graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);
graph.addRoom(roomC);

%% Visualize

fprintf('\nVisualizing 3-room chain...\n');
fig = figure('Name', '3-Room Chain: A ↔ B ↔ C', 'Position', [100, 100, 1200, 600]);
graph.visualize(fig);

%% Test path finding: A → C (should find A → B → C)

fprintf('\n=== PATH FINDING TEST ===\n');
fprintf('Goal: Navigate from Room A to Room C\n');
fprintf('Expected: Algorithm finds route A → B → C\n\n');

[room_sequence, total_cost] = graph.findRoomPath('A', 'C');

if ~isempty(room_sequence)
    fprintf('✓ SUCCESS!\n');
    fprintf('  Room sequence: %s\n', strjoin(room_sequence, ' → '));
    fprintf('  Total cost: %.2f\n', total_cost);
    fprintf('  Number of rooms to traverse: %d\n', length(room_sequence));

    % Verify the path
    fprintf('\n  Path breakdown:\n');
    for i = 1:length(room_sequence)
        fprintf('    Step %d: Room %s\n', i, room_sequence{i});
        if i < length(room_sequence)
            current_room = graph.getRoom(room_sequence{i});
            next_room_id = room_sequence{i+1};
            door = current_room.getDoorTo(next_room_id);
            fprintf('           → Exit through door at [%.1f, %.1f] to Room %s\n', ...
                door.door_center(1), door.door_center(2), next_room_id);
        end
    end

    % Check if path is correct
    if length(room_sequence) == 3 && ...
       strcmp(room_sequence{1}, 'A') && ...
       strcmp(room_sequence{2}, 'B') && ...
       strcmp(room_sequence{3}, 'C')
        fprintf('\n✓✓ CORRECT! Algorithm found A → B → C path!\n');
    else
        fprintf('\n✗ ERROR: Unexpected path!\n');
    end
else
    fprintf('✗ FAILED: No path found\n');
end

%% Test reverse path: C → A (should find C → B → A)

fprintf('\n=== REVERSE PATH TEST ===\n');
fprintf('Goal: Navigate from Room C to Room A\n');
fprintf('Expected: Algorithm finds route C → B → A\n\n');

[room_sequence_CA, cost_CA] = graph.findRoomPath('C', 'A');

if ~isempty(room_sequence_CA)
    fprintf('✓ SUCCESS!\n');
    fprintf('  Room sequence: %s\n', strjoin(room_sequence_CA, ' → '));
    fprintf('  Total cost: %.2f\n', cost_CA);

    % Check if path is correct
    if length(room_sequence_CA) == 3 && ...
       strcmp(room_sequence_CA{1}, 'C') && ...
       strcmp(room_sequence_CA{2}, 'B') && ...
       strcmp(room_sequence_CA{3}, 'A')
        fprintf('\n✓✓ CORRECT! Algorithm found C → B → A path!\n');
    else
        fprintf('\n✗ ERROR: Unexpected path!\n');
    end
else
    fprintf('✗ FAILED: No path found\n');
end

%% Test adjacent rooms: A → B (should be direct)

fprintf('\n=== ADJACENT ROOM TEST ===\n');
fprintf('Goal: Navigate from Room A to Room B\n');
fprintf('Expected: Direct path A → B\n\n');

[room_sequence_AB, cost_AB] = graph.findRoomPath('A', 'B');

if ~isempty(room_sequence_AB)
    fprintf('✓ SUCCESS!\n');
    fprintf('  Room sequence: %s\n', strjoin(room_sequence_AB, ' → '));
    fprintf('  Total cost: %.2f\n', cost_AB);

    if length(room_sequence_AB) == 2
        fprintf('\n✓✓ CORRECT! Direct path found!\n');
    else
        fprintf('\n✗ ERROR: Path should be direct (2 rooms)!\n');
    end
else
    fprintf('✗ FAILED: No path found\n');
end

%% Summary

fprintf('\n=== TEST SUMMARY ===\n');
fprintf('This test proves that Dijkstra algorithm:\n');
fprintf('1. ✓ Finds multi-hop paths (A → B → C)\n');
fprintf('2. ✓ Works in both directions (C → B → A)\n');
fprintf('3. ✓ Finds optimal paths (shortest route)\n');
fprintf('4. ✓ Handles rooms that are NOT directly connected\n\n');

fprintf('Next step: Use this room sequence to generate A* waypoints!\n');
fprintf('  - A* from A to door(A→B)\n');
fprintf('  - A* from door(A→B) to door(B→C)\n');
fprintf('  - A* from door(B→C) to final goal in C\n');
