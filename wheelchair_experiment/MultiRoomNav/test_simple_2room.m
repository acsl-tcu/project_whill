%% Simple 2-Room Navigation Test
% This script demonstrates manual room graph configuration
% and topological path planning between two rooms.
%
% Scenario: Navigate from Room A (office) to Room B (corridor)
% Connection: Single door at [8, 2]

clc; clear; close all;

fprintf('=== Simple 2-Room Navigation Test ===\n\n');

%% Step 1: Define Room A (Office area)
fprintf('Step 1: Creating Room A (office)...\n');
roomA_id = 'A';
roomA_center = [4, 0];           % Center at [4, 0]
roomA_bounds = [0, 8; -2, 2];    % X: [0, 8], Y: [-2, 2]

roomA = RoomNode(roomA_id, roomA_center, roomA_bounds);
fprintf('  Room A created: center [%.1f, %.1f], area %.1f m²\n', ...
    roomA.center(1), roomA.center(2), roomA.area);

%% Step 2: Define Room B (Corridor)
fprintf('\nStep 2: Creating Room B (corridor)...\n');
roomB_id = 'B';
roomB_center = [15, 6];          % Center at [15, 6]
roomB_bounds = [8, 22; 4, 8];    % X: [8, 22], Y: [4, 8]

roomB = RoomNode(roomB_id, roomB_center, roomB_bounds);
fprintf('  Room B created: center [%.1f, %.1f], area %.1f m²\n', ...
    roomB.center(1), roomB.center(2), roomB.area);

%% Step 3: Define door connection A → B
fprintf('\nStep 3: Creating door connection A → B...\n');
door_AB_position = [8, 2];       % Door at boundary between rooms
door_AB_width = 1.5;             % 1.5 meter wide door
door_AB = DoorConnection(roomB_id, door_AB_position, door_AB_width, 1.0);

roomA.addConnection(door_AB);
fprintf('  Door added: Room A → Room B at [%.1f, %.1f] (width %.1fm)\n', ...
    door_AB.door_center(1), door_AB.door_center(2), door_AB.door_width);

%% Step 4: Define door connection B → A (bidirectional)
fprintf('\nStep 4: Creating door connection B → A...\n');
door_BA = DoorConnection(roomA_id, door_AB_position, door_AB_width, 1.0);
roomB.addConnection(door_BA);
fprintf('  Door added: Room B → Room A at [%.1f, %.1f] (width %.1fm)\n', ...
    door_BA.door_center(1), door_BA.door_center(2), door_BA.door_width);

%% Step 5: Build room graph
fprintf('\nStep 5: Building room graph...\n');
graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);

%% Step 6: Visualize room graph
fprintf('\nStep 6: Visualizing room graph...\n');
fig1 = figure('Name', '2-Room Graph Visualization', 'Position', [100, 100, 900, 700]);
graph.visualize(fig1);

%% Step 7: Test room finding
fprintf('\nStep 7: Testing room detection...\n');
test_positions = [
    4, 0;    % Inside Room A (center)
    15, 6;   % Inside Room B (center)
    2, -1;   % Inside Room A (edge)
    10, 5;   % Inside Room B (edge)
];

for i = 1:size(test_positions, 1)
    pos = test_positions(i, :);
    room_id = graph.findRoomContaining(pos);
    if ~isempty(room_id)
        fprintf('  Position [%.1f, %.1f] is in Room %s\n', pos(1), pos(2), room_id);
    else
        fprintf('  Position [%.1f, %.1f] is NOT in any room\n', pos(1), pos(2));
    end
end

%% Step 8: Plan path from A to B
fprintf('\nStep 8: Planning path from Room A to Room B...\n');
[room_sequence, cost] = graph.findRoomPath('A', 'B');

if ~isempty(room_sequence)
    fprintf('  SUCCESS! Room sequence: %s\n', strjoin(room_sequence, ' → '));
    fprintf('  Total cost: %.2f\n', cost);

    % Display path details
    fprintf('\n  Path breakdown:\n');
    for i = 1:length(room_sequence)
        room = graph.getRoom(room_sequence{i});
        fprintf('    %d. Room %s (center: [%.1f, %.1f])\n', ...
            i, room.id, room.center(1), room.center(2));

        if i < length(room_sequence)
            % Show door to next room
            next_room_id = room_sequence{i+1};
            door = room.getDoorTo(next_room_id);
            fprintf('       └─ Door to Room %s at [%.1f, %.1f]\n', ...
                next_room_id, door.door_center(1), door.door_center(2));
        end
    end
else
    fprintf('  FAILED: No path found!\n');
end

%% Step 9: Test reverse path (B to A)
fprintf('\nStep 9: Planning reverse path from Room B to Room A...\n');
[room_sequence_BA, cost_BA] = graph.findRoomPath('B', 'A');

if ~isempty(room_sequence_BA)
    fprintf('  SUCCESS! Room sequence: %s\n', strjoin(room_sequence_BA, ' → '));
    fprintf('  Total cost: %.2f\n', cost_BA);
else
    fprintf('  FAILED: No path found!\n');
end

%% Step 10: Display full graph information
fprintf('\n');
graph.printGraphInfo();

fprintf('\n=== Test Complete ===\n');
fprintf('Next steps:\n');
fprintf('1. Integrate with PathSetting_AStar.m for geometric paths\n');
fprintf('2. Implement path stitching through doors\n');
fprintf('3. Test with actual occupancy map (map2.mat)\n');
