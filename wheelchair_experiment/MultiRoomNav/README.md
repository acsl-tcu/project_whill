# Multi-Room Navigation Prototype

## Overview
This folder contains a simple prototype for multi-room navigation using manual room graph configuration.

## Why Manual Configuration?
The automatic flood fill room detection in `Floodfill/` is currently not working, so this prototype uses manual room and door definitions.

## Components

### Core Classes
- `RoomNode.m` - Represents a single room with boundaries and connections
- `DoorConnection.m` - Represents a door/passage between two rooms
- `RoomGraph.m` - Graph structure holding all rooms and implementing Dijkstra search
- `TopologicalPlanner.m` - High-level planner that finds room sequences

### Configuration
- `ManualRoomConfig.m` - Manual definition of rooms and doors for testing

### Test Scripts
- `test_simple_2room.m` - Test 2-room navigation (A → B)
- `test_complex_4room.m` - Test 4-room navigation (A → B → D)
- `visualize_room_graph.m` - Visualize room graph and paths

## Simple Example

```matlab
% Define two rooms manually
roomA = RoomNode('A', [4, 0], [0, 8; -2, 2]);
roomB = RoomNode('B', [15, 6], [8, 22; 4, 8]);

% Define door between them
door = DoorConnection('B', [8, 2], 1.5);
roomA.addConnection(door);

% Create graph and plan path
graph = RoomGraph();
graph.addRoom(roomA);
graph.addRoom(roomB);

% Find room sequence: A → B
sequence = graph.findRoomPath('A', 'B');
% Result: {'A', 'B'}
```

## Integration with Existing A* System

The prototype will:
1. Use `PathSetting_AStar.m` for each path segment
2. Stitch segments together at door positions
3. Return complete waypoint array to `Control.m`

## Testing Strategy

1. **Phase 1:** Test with 2 simple rooms (corridor segments)
2. **Phase 2:** Test with 4 rooms including elevator area
3. **Phase 3:** Integrate with main navigation system

---
Created: 2025-10-10
Status: Prototyping with manual room configuration
