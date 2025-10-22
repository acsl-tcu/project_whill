# Multi-Room Navigation System Design

## Overview
Hierarchical path planning system that enables navigation between rooms in a building by connecting multiple A* paths through room transitions (doors/doorways).

## Problem Statement
**Current limitation:** A* pathfinding only works within a single connected space (one room or continuous corridor). It cannot plan paths that require traversing multiple discrete rooms.

**Example scenario:**
- Robot in Room A needs to reach Room D
- Room connectivity: A ↔ B ↔ C ↔ D (rooms only connected through doorways)
- Current system: Cannot find path (A* fails because rooms are disconnected in occupancy grid)
- Required system: High-level planner finds sequence (A → B → D), then stitches A* paths

## System Architecture

### Two-Level Hierarchy

```
┌─────────────────────────────────────────────────┐
│  LEVEL 1: Topological Planner (Room Graph)     │
│  Input:  Start room, Goal room                  │
│  Output: Room sequence [A, B, D]                │
│  Algorithm: Dijkstra/BFS on room graph          │
└─────────────────────────────────────────────────┘
                        ↓
┌─────────────────────────────────────────────────┐
│  LEVEL 2: Geometric Planner (A* per segment)    │
│  Input:  Room transitions [(A→B), (B→D)]        │
│  Output: Waypoint sequences per segment         │
│  Algorithm: A* on occupancy grid                │
└─────────────────────────────────────────────────┘
```

## Data Structures

### 1. Room Graph

```matlab
classdef RoomGraph < handle
    properties
        rooms           % Map of room_id → RoomNode
        connections     % Adjacency list of room connections
        occupancyMap    % Reference to global occupancy map
    end
end
```

### 2. Room Node

```matlab
classdef RoomNode < handle
    properties
        id              % Unique identifier (string or int)
        center          % [x, y] room center in world coordinates
        boundaries      % [x_min, x_max; y_min, y_max] bounding box
        area            % Room area in m²
        neighbors       % Array of DoorConnection objects
        flood_cells     % Nx2 grid cells from flood fill (optional)
    end
end
```

### 3. Door Connection

```matlab
classdef DoorConnection < handle
    properties
        target_room_id  % ID of connected room
        door_center     % [x, y] door/passage center
        door_width      % Width of passage (meters)
        traversal_cost  % Cost to traverse (default: Euclidean distance)
    end
end
```

## Implementation Plan

### Phase 1: Room Detection & Graph Building

**Goal:** Automatically build room graph from occupancy map

**Method:**
1. Use flood fill to segment map into rooms
2. Detect doorways (gaps in walls between flooded regions)
3. Build graph with rooms as nodes, doors as edges

**Files to create:**
- `src/Navigation/RoomGraph.m` - Main graph class
- `src/Navigation/RoomNode.m` - Room node class
- `src/Navigation/DoorConnection.m` - Door connection class
- `src/Navigation/RoomGraphBuilder.m` - Automatic graph construction

**Algorithm: Automatic Room Detection**
```
1. Perform multiple flood fills from seed points across map
2. Each flood fill = one room region
3. For each room pair (A, B):
   - Find boundary cells of A adjacent to B
   - Detect continuous free-space gaps (= doors)
   - Create DoorConnection between A and B
4. Store graph structure
```

### Phase 2: High-Level Path Planning

**Goal:** Find optimal room sequence from start to goal

**Files to create:**
- `src/Navigation/TopologicalPlanner.m` - High-level room-to-room planning

**Algorithm: Dijkstra on Room Graph**
```matlab
function room_sequence = planRoomPath(start_room_id, goal_room_id, room_graph)
    % Use Dijkstra's algorithm to find shortest room sequence
    % Returns: ['A', 'B', 'D'] or room ID array

    % Standard Dijkstra implementation:
    % 1. Initialize distances (start=0, others=inf)
    % 2. Priority queue of (room, distance)
    % 3. For each room, explore neighbors
    % 4. Backtrack to reconstruct path
end
```

### Phase 3: Path Stitching

**Goal:** Generate continuous A* path through room sequence

**Files to modify:**
- `PathSetting_AStar.m` - Add multi-room support

**Algorithm: Multi-Room A* Stitching**
```matlab
function waypoints = planMultiRoomPath(room_sequence, room_graph, occ_map)
    % Input: ['A', 'B', 'D']
    % Output: Combined waypoint array

    all_waypoints = [];

    for i = 1:(length(room_sequence) - 1)
        room_current = room_sequence{i};
        room_next = room_sequence{i+1};

        % Get door position between rooms
        door_pos = room_graph.getDoorPosition(room_current, room_next);

        % Plan A* path from current position to door
        if i == 1
            start_pos = robot_current_position;
        else
            start_pos = all_waypoints(end, :);  % Last waypoint
        end

        segment_waypoints = PathSetting_AStar(start_pos, door_pos, ...);
        all_waypoints = [all_waypoints; segment_waypoints];
    end

    % Final segment: last door to goal
    final_door = all_waypoints(end, :);
    goal_room = room_sequence{end};
    goal_pos = goal_position;  % User-specified goal

    final_waypoints = PathSetting_AStar(final_door, goal_pos, ...);
    all_waypoints = [all_waypoints; final_waypoints];

    return all_waypoints;
end
```

### Phase 4: Integration with Existing System

**Files to modify:**
- `src/Estimator/Estimate.m` - Add room graph initialization
- `src/Controller/@Control/Control.m` - Use multi-room planner
- `main_astar.m` - Load room graph on startup

**Integration points:**
1. **Startup (main_astar.m:117-118):**
   ```matlab
   % Load room graph
   room_graph = RoomGraphBuilder.buildFromMap('map2.mat');
   obj.EstimatorObj = Estimate(dt, mode, Datadir, sharedControlMode, room_graph);
   ```

2. **Path planning (Estimate.m):**
   ```matlab
   % Detect which room robot is in
   current_room = room_graph.findRoomContaining(robot_position);
   goal_room = room_graph.findRoomContaining(goal_position);

   if current_room == goal_room
       % Same room: use single A* path
       waypoints = PathSetting_AStar(robot_position, goal_position, ...);
   else
       % Different rooms: use multi-room planner
       room_sequence = TopologicalPlanner.planRoomPath(current_room, goal_room);
       waypoints = planMultiRoomPath(room_sequence, room_graph, map);
   end
   ```

## Advantages of This Approach

1. **Automatic:** Room graph built automatically from occupancy map
2. **Scalable:** Works with any number of rooms
3. **Optimal:** Dijkstra finds shortest room sequence
4. **Reusable:** Room graph computed once, reused for all queries
5. **Robust:** Falls back to single A* if rooms are connected

## Example Use Case

**Building:** 10F Building, 4th floor
**Start:** Room A (coordinates [4, -0.2])
**Goal:** Elevator (Room D at [30, 12])

**Room graph:**
```
A (office) ↔ B (corridor) ↔ C (hallway) ↔ D (elevator area)
```

**Execution:**
1. High-level planner: A → B → D (skip C, direct connection exists)
2. A* segment 1: [4, -0.2] → door(A→B) at [5, 2]
3. A* segment 2: door(A→B) → door(B→D) at [28, 6]
4. A* segment 3: door(B→D) → [30, 12] (elevator)
5. **Result:** Continuous waypoint array combining all segments

## Manual vs Automatic Graph Building

### Option A: Automatic Detection (Recommended)
- Use flood fill + door detection
- No manual configuration needed
- Works for any map

### Option B: Manual Specification (Fallback)
- Define rooms and doors in config file
- Useful for complex buildings
- Example:
  ```matlab
  % ManualRoomGraphConfig.m
  rooms = {
      struct('id', 'A', 'center', [4, 0], 'bounds', [0, 8; -2, 2]),
      struct('id', 'B', 'center', [15, 6], 'bounds', [8, 22; 4, 8])
  };
  doors = {
      struct('from', 'A', 'to', 'B', 'position', [8, 2], 'width', 1.5)
  };
  ```

## Testing Strategy

### Test 1: Simple 2-Room Navigation
- Start: Room A [4, -0.2]
- Goal: Room B [15, 6]
- Expected: Path through door at ~[8, 2]

### Test 2: Complex 4-Room Navigation
- Start: Room A [4, -0.2]
- Goal: Room D (elevator) [30, 12]
- Expected: Optimal room sequence with stitched A* paths

### Test 3: Same-Room Navigation (Regression)
- Start: [4, -0.2]
- Goal: [6, 0]
- Expected: Single A* path (existing behavior preserved)

## Performance Considerations

**Graph building:** O(N) where N = number of map cells (one-time cost)
**Dijkstra planning:** O(R² log R) where R = number of rooms (~10-20 typically)
**A* per segment:** O(M log M) where M = cells per room
**Total:** Dominated by A*, similar to current system

## Future Enhancements

1. **Dynamic re-planning:** Update room graph if doors open/close
2. **Multi-floor navigation:** Extend graph to 3D with elevator nodes
3. **Semantic labels:** Add room types (office, corridor, elevator, stairs)
4. **Traffic-aware costs:** Prefer wider corridors, avoid congested areas
5. **Time-dependent costs:** Model door schedules (locked at night, etc.)

---

**Created:** 2025-10-10
**Status:** Design phase - ready for implementation
**Priority:** High - enables multi-room autonomous navigation
