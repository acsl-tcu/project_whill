# Dijkstra Algorithm Walkthrough: Room A → Room D

## Problem Setup

**Room Network:**
```
    A ↔ B ↔ C
        ↓   ↓
        D ←─┘
```

**Room Positions (centers):**
- Room A: [4, 6]
- Room B: [15, 6]
- Room C: [26, 6]
- Room D: [19, -1]

**Edge Costs (using current uniform cost = 1.0):**
- A ↔ B: cost = 1.0
- B ↔ C: cost = 1.0
- B ↔ D: cost = 1.0
- C ↔ D: cost = 1.0

**Task:** Find shortest path from Room A to Room D

---

## Dijkstra Algorithm Step-by-Step

### Initialization

```
distances = {
    'A': 0,       ← Start room (distance from A to A = 0)
    'B': ∞,
    'C': ∞,
    'D': ∞
}

parents = {
    (empty - no parents yet)
}

visited = {
    'A': false,
    'B': false,
    'C': false,
    'D': false
}

unvisited = ['A', 'B', 'C', 'D']
```

---

### Iteration 1: Process Room A

**1. Select room with minimum distance from unvisited:**
```
Unvisited distances:
  A: 0    ← minimum!
  B: ∞
  C: ∞
  D: ∞

Current room: A
```

**2. Mark A as visited:**
```
visited['A'] = true
unvisited = ['B', 'C', 'D']
```

**3. Check if goal reached:**
```
Current: A
Goal: D
A ≠ D → Continue
```

**4. Update neighbors of A:**

Room A has 1 connection: **A → B**

```
Neighbor: B
Edge cost (A→B): 1.0
Tentative distance = distances['A'] + edge_cost
                   = 0 + 1.0
                   = 1.0

Current distances['B'] = ∞
Tentative (1.0) < Current (∞) ? YES!

Update:
  distances['B'] = 1.0
  parents['B'] = 'A'
```

**State after Iteration 1:**
```
distances = {'A': 0, 'B': 1.0, 'C': ∞, 'D': ∞}
parents = {'B': 'A'}
visited = {'A': true, 'B': false, 'C': false, 'D': false}
unvisited = ['B', 'C', 'D']
```

---

### Iteration 2: Process Room B

**1. Select room with minimum distance from unvisited:**
```
Unvisited distances:
  B: 1.0  ← minimum!
  C: ∞
  D: ∞

Current room: B
```

**2. Mark B as visited:**
```
visited['B'] = true
unvisited = ['C', 'D']
```

**3. Check if goal reached:**
```
Current: B
Goal: D
B ≠ D → Continue
```

**4. Update neighbors of B:**

Room B has 3 connections: **B → A**, **B → C**, **B → D**

**Connection 1: B → A**
```
Neighbor: A
visited['A'] = true → Skip (already visited)
```

**Connection 2: B → C**
```
Neighbor: C
Edge cost (B→C): 1.0
Tentative distance = distances['B'] + edge_cost
                   = 1.0 + 1.0
                   = 2.0

Current distances['C'] = ∞
Tentative (2.0) < Current (∞) ? YES!

Update:
  distances['C'] = 2.0
  parents['C'] = 'B'
```

**Connection 3: B → D**
```
Neighbor: D
Edge cost (B→D): 1.0
Tentative distance = distances['B'] + edge_cost
                   = 1.0 + 1.0
                   = 2.0

Current distances['D'] = ∞
Tentative (2.0) < Current (∞) ? YES!

Update:
  distances['D'] = 2.0
  parents['D'] = 'B'
```

**State after Iteration 2:**
```
distances = {'A': 0, 'B': 1.0, 'C': 2.0, 'D': 2.0}
parents = {'B': 'A', 'C': 'B', 'D': 'B'}
visited = {'A': true, 'B': true, 'C': false, 'D': false}
unvisited = ['C', 'D']
```

---

### Iteration 3: Process Room D (or C - both have distance 2.0)

**1. Select room with minimum distance from unvisited:**
```
Unvisited distances:
  C: 2.0  ← tie with D
  D: 2.0  ← algorithm picks first one (D)

Current room: D
```

**2. Mark D as visited:**
```
visited['D'] = true
unvisited = ['C']
```

**3. Check if goal reached:**
```
Current: D
Goal: D
D = D → GOAL REACHED! ✓
```

**Final distances:**
```
distances = {'A': 0, 'B': 1.0, 'C': 2.0, 'D': 2.0}
parents = {'B': 'A', 'C': 'B', 'D': 'B'}
```

---

## Path Reconstruction

**Goal:** D
**Start:** A

**Backtrack using parents map:**

```
Step 1: current = 'D'
        parent['D'] = 'B'
        path = ['D']

Step 2: current = 'B'
        parent['B'] = 'A'
        path = ['B', 'D']

Step 3: current = 'A'
        A is the start → Stop
        path = ['A', 'B', 'D']
```

**Final Result:**
```
Room sequence: A → B → D
Total cost: 2.0
```

---

## Alternative Path (Not Chosen)

**Path A → B → C → D:**
```
Distance = distances['A→B'] + distances['B→C'] + distances['C→D']
         = 1.0 + 1.0 + 1.0
         = 3.0
```

**Why Dijkstra didn't choose this path:**
- A → B → D has cost **2.0** ✓ (shorter)
- A → B → C → D has cost **3.0** (longer)

**Dijkstra always finds the shortest path!**

---

## With Distance-Based Costs (What You Suggested)

**Recalculated Edge Costs:**
```
A ↔ B: norm([15,6] - [4,6]) = 11.0 m
B ↔ C: norm([26,6] - [15,6]) = 11.0 m
B ↔ D: norm([19,-1] - [15,6]) = 8.1 m
C ↔ D: norm([19,-1] - [26,6]) = 9.9 m
```

**Running Dijkstra with distance costs:**

**After processing A:**
```
distances = {'A': 0, 'B': 11.0, 'C': ∞, 'D': ∞}
```

**After processing B:**
```
distances = {'A': 0, 'B': 11.0, 'C': 22.0, 'D': 19.1}
                                        ^^^      ^^^
                               B→C=11.0      B→D=8.1
```

**Result:**
```
Path: A → B → D
Total cost: 19.1 m (actual distance!)
```

**Alternative path A → B → C → D:**
```
Cost = 11.0 + 11.0 + 9.9 = 31.9 m (longer, not chosen)
```

**Same path chosen, but now with meaningful costs!**

---

## Code Implementation

**In RoomGraph.m (lines 65-184):**

```matlab
function [room_sequence, total_cost] = findRoomPath(obj, start_room_id, goal_room_id)
    % Initialize
    distances = containers.Map();
    parents = containers.Map();

    for room in all_rooms
        distances(room) = inf;
    end
    distances(start_room_id) = 0;

    % Main loop
    while unvisited not empty
        current = room with min distance

        if current == goal
            return reconstructPath(parents, start, goal)
        end

        for each neighbor of current
            edge_cost = door.cost  ← Currently 1.0
            tentative = distances(current) + edge_cost

            if tentative < distances(neighbor)
                distances(neighbor) = tentative
                parents(neighbor) = current
            end
        end
    end
end
```

---

## Summary

| Step | Current Room | Distances | Action |
|------|--------------|-----------|--------|
| Init | - | A:0, B:∞, C:∞, D:∞ | Start |
| 1 | A | A:0, B:1.0, C:∞, D:∞ | Update B via A |
| 2 | B | A:0, B:1.0, C:2.0, D:2.0 | Update C,D via B |
| 3 | D | (same) | Goal reached! |

**Path found:** A → B → D (cost: 2.0)

**Key insight:** Dijkstra explores rooms in order of increasing distance from start, guaranteeing the shortest path is found first!
