function find_path(start_room, goal_room)
%% Simple Path Finder - Shows only the result
% Usage: find_path('A', 'D')
%
% Network Structure:
%     A ↔ B ↔ C
%         ↓
%         D
% (B is the central hub connected to A, C, and D)

%% Build 4-room network with connected boundaries
% Position rooms so they touch at doors (no gaps)

roomA = RoomNode('A', [4, 6], [0, 8; 4, 8]);       % Left:    X:[0-8],   Y:[4-8]
roomB = RoomNode('B', [15, 6], [8, 22; 4, 8]);     % Center:  X:[8-22],  Y:[4-8]
roomC = RoomNode('C', [26, 6], [22, 30; 4, 8]);    % Right:   X:[22-30], Y:[4-8]
roomD = RoomNode('D', [19, -1], [8, 30; -5, 4]);   % Bottom:  X:[8-30],  Y:[-5-4] (extended to reach C)

% Connections (doors are at boundaries where rooms meet):
% A ↔ B (door at X=8, the shared boundary)
roomA.addConnection(DoorConnection('B', [8, 6], 1.5, 1.0));
roomB.addConnection(DoorConnection('A', [8, 6], 1.5, 1.0));

% B ↔ C (door at X=22, the shared boundary)
roomB.addConnection(DoorConnection('C', [22, 6], 1.5, 1.0));
roomC.addConnection(DoorConnection('B', [22, 6], 1.5, 1.0));

% B ↔ D (door at Y=4, the shared boundary, left side)
roomB.addConnection(DoorConnection('D', [15, 4], 1.5, 1.0));
roomD.addConnection(DoorConnection('B', [15, 4], 1.5, 1.0));

% C ↔ D (door at Y=4, the shared boundary, right side)
roomC.addConnection(DoorConnection('D', [26, 4], 1.5, 1.0));
roomD.addConnection(DoorConnection('C', [26, 4], 1.5, 1.0));

graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);
graph.addRoom(roomC);
graph.addRoom(roomD);

%% Visualize the network
figure('Name', sprintf('Room Network: %s to %s', start_room, goal_room), ...
    'Position', [100, 100, 900, 700]);
graph.visualize();
title(sprintf('Room Network (B is central hub)\nFinding path: %s → %s', start_room, goal_room), ...
    'FontSize', 14, 'FontWeight', 'bold');

%% Find path (silent)
[room_sequence, ~] = graph.findRoomPath(start_room, goal_room);

%% Display result - ONLY THE PATH
fprintf('\n');
if isempty(room_sequence)
    fprintf('No path found from %s to %s\n', start_room, goal_room);
    return;
end

% Build path string
path_str = room_sequence{1};
for i = 2:length(room_sequence)
    path_str = [path_str, ' → ', room_sequence{i}];
end

% Output
fprintf('Path: %s\n', path_str);

end
