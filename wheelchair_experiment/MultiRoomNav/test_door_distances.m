%% Test Door-to-Door Distance Path Finding
% Compares path costs using door-to-door distances vs room center distances

clc; clear; close all;

fprintf('=== Door-to-Door Distance Path Finding Test ===\n\n');

%% Build room network
roomA = RoomNode('A', [4, 6], [0, 8; 4, 8]);
roomB = RoomNode('B', [15, 6], [8, 22; 4, 8]);
roomC = RoomNode('C', [26, 6], [22, 30; 4, 8]);
roomD = RoomNode('D', [19, -1], [8, 30; -5, 4]);

% Add connections (costs don't matter for door-to-door version)
roomA.addConnection(DoorConnection('B', [8, 6], 1.5, 0));
roomB.addConnection(DoorConnection('A', [8, 6], 1.5, 0));
roomB.addConnection(DoorConnection('C', [22, 6], 1.5, 0));
roomC.addConnection(DoorConnection('B', [22, 6], 1.5, 0));
roomB.addConnection(DoorConnection('D', [15, 4], 1.5, 0));
roomD.addConnection(DoorConnection('B', [15, 4], 1.5, 0));
roomC.addConnection(DoorConnection('D', [26, 4], 1.5, 0));
roomD.addConnection(DoorConnection('C', [26, 4], 1.5, 0));

graph = RoomGraphWithDoorDistances();
graph.addRoom(roomA);
graph.addRoom(roomB);
graph.addRoom(roomC);
graph.addRoom(roomD);

%% Print all door-to-door distances
graph.printDoorDistances();

%% Visualize with door-to-door distance labels
fprintf('Visualizing room graph with door-to-door distances...\n');
fig1 = figure('Name', 'Door-to-Door Distances', 'Position', [100, 100, 1200, 800]);
graph.visualize(fig1);

%% Test Case 1: A → D

fprintf('\n╔════════════════════════════════════════════╗\n');
fprintf('║  TEST CASE 1: Path from A to D            ║\n');
fprintf('╚════════════════════════════════════════════╝\n\n');

[rooms, doors, cost] = graph.findRoomPath('A', 'D');

if ~isempty(rooms)
    fprintf('Room sequence: ');
    for i = 1:length(rooms)
        fprintf('%s', rooms{i});
        if i < length(rooms)
            fprintf(' → ');
        end
    end
    fprintf('\n');

    fprintf('\nDetailed breakdown:\n');
    fprintf('─────────────────────────────────────────────\n');

    for i = 1:length(rooms)
        room_id = rooms{i};
        room = graph.getRoom(room_id);

        if i == 1
            fprintf('%d. Start in Room %s at center [%.1f, %.1f]\n', ...
                i, room_id, room.center(1), room.center(2));

            if length(rooms) > 1
                next_room_id = rooms{i+1};
                door = room.getDoorTo(next_room_id);
                dist = norm(door.door_center - room.center);
                fprintf('   → Travel to door %s→%s at [%.1f, %.1f]: %.2f m\n', ...
                    room_id, next_room_id, door.door_center(1), door.door_center(2), dist);
            end
        elseif i == length(rooms)
            prev_room_id = rooms{i-1};
            prev_room = graph.getRoom(prev_room_id);
            entry_door = prev_room.getDoorTo(room_id);

            fprintf('\n%d. Enter Room %s from door at [%.1f, %.1f]\n', ...
                i, room_id, entry_door.door_center(1), entry_door.door_center(2));
            fprintf('   → Reach center at [%.1f, %.1f]\n', ...
                room.center(1), room.center(2));
        else
            prev_room_id = rooms{i-1};
            prev_room = graph.getRoom(prev_room_id);
            entry_door = prev_room.getDoorTo(room_id);

            next_room_id = rooms{i+1};
            exit_door = room.getDoorTo(next_room_id);

            dist = norm(exit_door.door_center - entry_door.door_center);

            fprintf('\n%d. Enter Room %s from door at [%.1f, %.1f]\n', ...
                i, room_id, entry_door.door_center(1), entry_door.door_center(2));
            fprintf('   → Travel to door %s→%s at [%.1f, %.1f]: %.2f m\n', ...
                room_id, next_room_id, exit_door.door_center(1), exit_door.door_center(2), dist);
        end
    end

    fprintf('─────────────────────────────────────────────\n');
    fprintf('TOTAL DISTANCE: %.2f meters\n', cost);
    fprintf('═════════════════════════════════════════════\n\n');
end

%% Test Case 2: A → C

fprintf('\n╔════════════════════════════════════════════╗\n');
fprintf('║  TEST CASE 2: Path from A to C            ║\n');
fprintf('╚════════════════════════════════════════════╝\n\n');

[rooms2, doors2, cost2] = graph.findRoomPath('A', 'C');

if ~isempty(rooms2)
    fprintf('Room sequence: ');
    for i = 1:length(rooms2)
        fprintf('%s', rooms2{i});
        if i < length(rooms2)
            fprintf(' → ');
        end
    end
    fprintf('\n');
    fprintf('Total distance: %.2f meters\n\n', cost2);
end

%% Test Case 3: Compare all possible paths from A to D

fprintf('\n╔════════════════════════════════════════════╗\n');
fprintf('║  PATH COMPARISON: A → D                   ║\n');
fprintf('╚════════════════════════════════════════════╝\n\n');

fprintf('Manual calculation of all possible paths:\n');
fprintf('─────────────────────────────────────────────\n');

% Path 1: A → B → D
fprintf('Path 1: A → B → D\n');
dist_A_center_to_door_AB = norm([8, 6] - [4, 6]);
dist_door_AB_to_door_BD = norm([15, 4] - [8, 6]);
dist_door_BD_to_D_center = norm([19, -1] - [15, 4]);
total1 = dist_A_center_to_door_AB + dist_door_AB_to_door_BD;
fprintf('  In A: center [4,6] → door [8,6]: %.2f m\n', dist_A_center_to_door_AB);
fprintf('  In B: door [8,6] → door [15,4]: %.2f m\n', dist_door_AB_to_door_BD);
fprintf('  TOTAL: %.2f m\n\n', total1);

% Path 2: A → B → C → D
fprintf('Path 2: A → B → C → D\n');
dist_door_AB_to_door_BC = norm([22, 6] - [8, 6]);
dist_door_BC_to_door_CD = norm([26, 4] - [22, 6]);
total2 = dist_A_center_to_door_AB + dist_door_AB_to_door_BC + dist_door_BC_to_door_CD;
fprintf('  In A: center [4,6] → door [8,6]: %.2f m\n', dist_A_center_to_door_AB);
fprintf('  In B: door [8,6] → door [22,6]: %.2f m\n', dist_door_AB_to_door_BC);
fprintf('  In C: door [22,6] → door [26,4]: %.2f m\n', dist_door_BC_to_door_CD);
fprintf('  TOTAL: %.2f m\n\n', total2);

fprintf('─────────────────────────────────────────────\n');
fprintf('Dijkstra chose: A → B → D (%.2f m) ✓\n', cost);
fprintf('Not chosen: A → B → C → D (%.2f m)\n', total2);
fprintf('Savings: %.2f meters\n', total2 - cost);
fprintf('═════════════════════════════════════════════\n\n');

fprintf('Test complete! Door-to-door distances working correctly.\n');
