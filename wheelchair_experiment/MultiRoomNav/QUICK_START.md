# Multi-Room Navigation - Quick Start Guide

## 🚀 Try It Now!

### Option 1: Run the test script
```matlab
cd MultiRoomNav
test_simple_2room
```

This will:
- Create 2 rooms (A and B)
- Connect them with a door
- Find path A → B using Dijkstra
- Show visualization

### Option 2: Interactive MATLAB session

```matlab
% Load classes (make sure you're in the project root or MultiRoomNav/ is in path)
addpath('MultiRoomNav')

% Create rooms
roomA = RoomNode('A', [4, 0], [0, 8; -2, 2]);
roomB = RoomNode('B', [15, 6], [8, 22; 4, 8]);

% Connect with doors (bidirectional)
roomA.addConnection(DoorConnection('B', [8, 2], 1.5));
roomB.addConnection(DoorConnection('A', [8, 2], 1.5));

% Build graph
graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);

% Find path
[sequence, cost] = graph.findRoomPath('A', 'B')
% Output: sequence = {'A', 'B'}, cost = 1.0

% Visualize
graph.visualize()
```

## 📂 File Structure

```
MultiRoomNav/
├── README.md                    # Overview
├── IMPLEMENTATION_SUMMARY.md    # Detailed documentation
├── QUICK_START.md              # This file
│
├── DoorConnection.m            # Door/passage class
├── RoomNode.m                  # Room representation
├── RoomGraph.m                 # Graph + Dijkstra algorithm
│
└── test_simple_2room.m         # Working demo
```

## 🎯 What This Solves

**Problem:** Robot in Room A needs to reach Room D, but rooms are disconnected.

**Old system:** A* fails (no path exists in occupancy grid)

**New system:**
1. Dijkstra finds room sequence: A → B → D
2. A* creates paths between rooms through doors
3. Paths stitched together → continuous waypoints

## ⚡ Quick API Reference

### Create a room
```matlab
room = RoomNode(id, center, boundaries)
% Example:
room = RoomNode('A', [4, 0], [0, 8; -2, 2])
```

### Add door connection
```matlab
door = DoorConnection(target_room_id, position, width)
room.addConnection(door)
% Example:
door = DoorConnection('B', [8, 2], 1.5)
roomA.addConnection(door)
```

### Build graph
```matlab
graph = RoomGraph()
graph.addRoom(roomA)
graph.addRoom(roomB)
```

### Find path
```matlab
[sequence, cost] = graph.findRoomPath(start_id, goal_id)
% Example:
[seq, cost] = graph.findRoomPath('A', 'B')
```

### Which room am I in?
```matlab
room_id = graph.findRoomContaining([x, y])
% Example:
room_id = graph.findRoomContaining([4, 0])  % Returns 'A'
```

## 🔧 Next Implementation Steps

1. **Create path stitching function** - Combine A* paths through doors
2. **Test with map2.mat** - Use real occupancy map for A* segments
3. **Define real building layout** - Map 10F 4th floor to rooms
4. **Integrate with Control.m** - Use in main navigation loop

## 💡 Tips

- **Always create bidirectional doors** unless you want one-way passages
- **Door positions** should be at room boundaries in free space
- **Room boundaries** should match occupancy map structure
- **Test incrementally** - 2 rooms first, then add more

## 🐛 Troubleshooting

**"Room X not found in graph"**
- Check room ID spelling (case-sensitive)
- Make sure you called `graph.addRoom()`

**"No path exists"**
- Check door connections are bidirectional
- Verify room IDs in door definitions match added rooms

**Position not in any room**
- Check boundaries format: [x_min, x_max; y_min, y_max]
- Verify position is within at least one room's boundaries

## 📞 Support

See full documentation:
- `IMPLEMENTATION_SUMMARY.md` - Complete API and architecture
- `../Reference/Multi_Room_Navigation_Design.md` - Original design doc
- `../CLAUDE.md` - Project notes (updated with multi-room info)

---
**Ready to test?** Run `test_simple_2room` now!
