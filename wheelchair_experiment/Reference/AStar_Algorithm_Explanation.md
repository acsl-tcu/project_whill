# A* Path Planning Algorithm - Wheelchair Navigation System

## Overview

The A* (A-star) algorithm is a graph traversal and path searching algorithm used in this wheelchair navigation system to find the optimal path from a start position to a goal position while avoiding obstacles.

**Simple Analogy:** Think of A* like exploring a maze where you're trying to find the shortest path to the exit. Instead of blindly trying every path, A* intelligently explores promising paths first by estimating which direction gets you closer to the goal.

## How A* Works - The Big Picture

### 1. Basic Concept

A* is a **best-first search algorithm** that finds the least-cost path from a given initial node to a goal node. It uses a heuristic function to guide its search.

**Real-world analogy:** Imagine you're navigating a wheelchair through a building to reach a destination:
- You know where you are now (start position)
- You know where you want to go (goal position)
- You can see obstacles around you (walls, furniture)
- At each moment, you choose to move in the direction that seems most promising

A* does exactly this, but systematically explores all possibilities to guarantee finding the best path.

### 2. Core Formula - Understanding the Costs

A* evaluates each grid cell (position) using this function:

```
f(n) = g(n) + h(n)
```

Let's break down what each term means:

#### **g(n) - "How far have I traveled?"**
- The **actual cost** from the start position to the current cell `n`
- Measured in grid steps (orthogonal = 1, diagonal = √2)
- Think of it as your "odometer reading" - the total distance you've covered
- **Example:** If you moved 10 steps from start, then g(n) = 10

#### **h(n) - "How far do I still need to go?"**
- The **estimated cost** from current cell `n` to the goal
- Calculated as straight-line (Euclidean) distance
- This is the "heuristic" - an educated guess about remaining distance
- Think of it as "as the crow flies" distance to your destination
- **Example:** If goal is 50 grid cells away in straight line, h(n) = 50

#### **f(n) - "What's my total estimated trip cost?"**
- The **total estimated cost** of the complete path through cell `n`
- f(n) = distance traveled so far + estimated distance remaining
- A* always explores the cell with the **lowest f(n)** value first
- This makes A* efficient - it focuses on promising paths
- **Example:** f(n) = 10 + 50 = 60

**Why this works:** By always choosing the cell with lowest f(n), A* balances between:
1. Exploring nearby areas (low g(n))
2. Moving toward the goal (low h(n))

### 3. Key Data Structures - The Algorithm's Memory

#### **Open Set - "Places I might explore next"**
- A list of grid cells that are **candidates for exploration**
- Think of it as your "to-do list" of locations to check
- Each entry contains: [row, col, g_score, f_score]
- A* always picks the cell with **lowest f(n)** from this list
- When a cell is explored, it's removed from the open set

**Example:**
```
Open Set = [
  [245, 1023, g=0, f=50],      ← Start position
  [246, 1023, g=1, f=50.5],    ← One step down
  [245, 1024, g=1, f=50.3]     ← One step right
]
A* will explore [245, 1023] first because it has lowest f
```

#### **Closed Set - "Places I've already explored"**
- A grid-sized boolean array marking cells that have been **fully explored**
- Think of it as "marking your footprints" so you don't waste time revisiting
- Once a cell is in closed set, A* won't explore it again
- Prevents infinite loops and redundant work

**Example:**
```
Closed Set (visualized):
. . . . .     Legend:
. X X . .     . = not explored yet
. X X . .     X = already explored (in closed set)
. . . . .
```

#### **came_from - "How did I get here?"**
- A grid-sized array storing the **parent cell** for each explored cell
- Think of it as "breadcrumbs" showing the path you took
- Used at the end to reconstruct the optimal path by backtracking
- For each cell, stores [parent_row, parent_col]

**Example:**
```
If came_from[10,20] = [9,20]
This means: "I reached cell (10,20) by coming from cell (9,20)"

At the end, backtrack from goal to start:
Goal (100,200) ← came from (99,200) ← came from (98,201) ← ... ← Start
```

#### **g_score - "Distance tracker"**
- A grid-sized array storing the **shortest distance found so far** to each cell
- Initially all infinity, except start = 0
- Gets updated when a shorter path to a cell is discovered
- Think of it as a "scoreboard" showing best distances

**Example:**
```
g_score at start:
[inf  inf  inf  inf]
[inf   0   inf  inf]  ← Start at (1,1) has g=0
[inf  inf  inf  inf]

After exploring neighbors:
[inf   1   inf  inf]
[ 1    0    1   inf]  ← Neighbors now have g=1
[inf   1   inf  inf]
```

### 4. Algorithm Steps - The Search Process

Here's what A* does step-by-step, explained with reasoning:

#### **Step 1: Initialize**
```matlab
open_set = [start_position]  % Only start in to-do list
closed_set = all false        % Nothing explored yet
g_score[start] = 0           % Zero distance to start
g_score[all_others] = inf    % Unknown distance to others
```

**Reasoning:** We begin at the start with zero cost, and we don't know distances to anywhere else yet.

#### **Step 2: Main Loop**
```
while open_set is not empty:
```

**Reasoning:** As long as we have unexplored candidates, keep searching. If open_set becomes empty, no path exists.

#### **Step 3: Pick most promising cell**
```matlab
current = cell with lowest f(n) in open_set
remove current from open_set
```

**Reasoning:** We explore the most promising path first (lowest total estimated cost). This makes A* efficient.

#### **Step 4: Check if we reached the goal**
```matlab
if current == goal:
    reconstruct_path()
    return SUCCESS
```

**Reasoning:** If we've reached the goal, we're done! Backtrack to build the path.

#### **Step 5: Mark as explored**
```matlab
add current to closed_set
```

**Reasoning:** We've fully processed this cell, so mark it "done" to avoid revisiting.

#### **Step 6: Check all 8 neighbors**
```matlab
for each neighbor of current:
```

**Reasoning:** A wheelchair can move in 8 directions (up, down, left, right, and 4 diagonals).

#### **Step 7: Skip invalid neighbors**
```matlab
if neighbor is obstacle OR neighbor in closed_set:
    skip this neighbor
```

**Reasoning:**
- Can't move through walls/obstacles
- No point revisiting already-explored cells

#### **Step 8: Calculate tentative cost**
```matlab
tentative_g = g_score[current] + movement_cost
movement_cost = 1 (orthogonal) or √2 (diagonal)
```

**Reasoning:** Calculate what the distance would be if we reached this neighbor via the current cell.

#### **Step 9: Check if this path is better**
```matlab
if tentative_g < g_score[neighbor]:
```

**Reasoning:** Only update if we found a shorter path to this neighbor than we knew before.

#### **Step 10: Update neighbor information**
```matlab
came_from[neighbor] = current
g_score[neighbor] = tentative_g
f_score = tentative_g + heuristic(neighbor, goal)
add/update neighbor in open_set with new f_score
```

**Reasoning:**
- Record that best path to neighbor comes through current
- Update the distance to neighbor
- Calculate total estimated cost (f = g + h)
- Add to to-do list if not already there

### 5. Path Reconstruction - Building the Final Path

Once the goal is reached:

```matlab
path = []
current = goal
while current != start:
    path.insert_at_beginning(current)
    current = came_from[current]
path.insert_at_beginning(start)
```

**Reasoning:** Follow the breadcrumbs backward from goal to start using the `came_from` array. This gives us the optimal path.

**Example:**
```
came_from trail:
Goal(100,200) → (99,200) → (98,201) → (97,201) → ... → Start(1,1)

Final path (reversed):
Start(1,1) → ... → (97,201) → (98,201) → (99,200) → Goal(100,200)
```

## Implementation in PathSetting_AStar.m

### Coordinate Systems

The implementation uses **two coordinate systems**:

#### World Coordinates (Real-world)
- **Units**: Meters
- **Origin**: Real-world reference point
- **Example**: Start `[4.0, -0.2]` meters
- **Used for**: Input/output, visualization

#### Grid Coordinates (Array indices)
- **Units**: Grid cells (array indices)
- **Origin**: Array index `[1,1]` (MATLAB convention)
- **Example**: Start `[245, 1023]` grid cells
- **Used for**: A* computation

### Conversion Process

```matlab
% World → Grid
start_grid = world2grid(map_obj, [start_x, start_y]);
start_r = start_grid(1);  % Row index
start_c = start_grid(2);  % Column index

% Grid → World  
world_pos = grid2world(map_obj, [row, col]);
```

### Map Resolution
- **Resolution**: 20 cells/meter (typically)
- **1 meter** = 20 grid cells
- **1 grid cell** = 5 cm in real world

## Obstacle Handling

### 1. Occupancy Grid
```matlab
% Load map
map_data = load('map2.mat');
map_obj = map_data.map;
occ_matrix = getOccupancy(map_obj);
```

- **Free space**: `occ_matrix < 0.5`
- **Occupied space**: `occ_matrix >= 0.5`
- **Grid size**: Typically 800×4000 cells

### 2. Obstacle Inflation

**Purpose**: Account for wheelchair dimensions by "growing" obstacles

```matlab
% Calculate clearance needed
robot_clearance = robot_width + safety_margin;
clearance_cells = ceil(robot_clearance * resolution / 2) + 1;

% Inflate obstacles
inflated_map = inflateMap(occ_matrix, clearance_cells);
```

**Inflation Process**:
- For each occupied cell, mark surrounding cells as occupied
- Creates "safety buffer" around obstacles
- Wheelchair treated as point robot on inflated map

#### **Understanding the Clearance Calculation - The Math Explained**

The clearance calculation determines how many grid cells to inflate around each obstacle. Let's break down the formula step by step:

```matlab
clearance_cells = ceil(robot_clearance * resolution / 2) + 1
```

**Step-by-Step Breakdown:**

**Step 1: Calculate total clearance needed (in meters)**
```matlab
robot_clearance = robot_width + safety_margin
```

- **robot_width**: Physical width of wheelchair (e.g., 0.6m)
- **safety_margin**: Extra buffer for safety (e.g., 0.2m)
- **robot_clearance**: Total clearance needed (e.g., 0.6 + 0.2 = 0.8m)

**WHY**: We want the wheelchair to stay at least `robot_clearance` distance away from walls.

---

**Step 2: Convert meters to grid cells**
```matlab
robot_clearance * resolution
```

- **resolution**: Grid density (e.g., 20 cells/meter)
- **Result**: Number of cells equivalent to the clearance distance

**EXAMPLE**:
- `0.8m × 20 cells/m = 16 cells`

**WHY**: The grid is discrete (made of cells), so we need to convert real-world meters to grid cell count.

---

**Step 3: Divide by 2 (radius vs diameter)**
```matlab
(robot_clearance * resolution) / 2
```

- **Result**: Half the clearance in cells

**EXAMPLE**:
- `16 cells / 2 = 8 cells`

**WHY THIS DIVISION?**

The inflation algorithm grows obstacles in **all directions** from each occupied cell:
- It expands **left AND right** (both directions)
- It expands **up AND down** (both directions)

```
Original obstacle: █
After inflation (8 cells radius):

        ← 8 cells → | ← 8 cells →
    ████████████████████████████
    ████████████ █ ████████████    ← Total width = 8 + 1 + 8 = 17 cells
    ████████████████████████████
                  ↑
            Original cell
```

**KEY INSIGHT**:
- The formula calculates the **radius** (distance from center)
- Inflation happens in **both directions**, creating the full diameter
- Total clearance = radius × 2 = full robot_clearance

**Without the `/2`:**
- Would inflate by the full clearance distance in each direction
- Total clearance would be **double** what we want
- Wheelchair would be too conservative

**Mathematical relationship:**
```
Total inflation diameter = 2 × clearance_cells
Total real-world clearance = diameter / resolution
                           = (2 × clearance_cells) / resolution
                           = 2 × (robot_clearance × resolution / 2) / resolution
                           = robot_clearance ✓ (correct!)
```

---

**Step 4: Round up with ceil()**
```matlab
ceil((robot_clearance * resolution) / 2)
```

- **ceil()**: Round up to nearest integer

**EXAMPLE**:
- If result is 8.3 cells → round up to 9 cells

**WHY**:
- Grid cells are discrete (no fractional cells)
- **Always round UP** for safety (better too much clearance than too little)
- Ensures we never under-inflate

---

**Step 5: Add 1 extra cell**
```matlab
ceil(robot_clearance * resolution / 2) + 1
```

**EXAMPLE**:
- `8 + 1 = 9 cells`

**WHY**:
- **Discretization safety buffer**: Accounts for rounding errors
- **Grid boundary effects**: Ensures clearance at cell edges
- **Conservative approach**: Better to have slightly more clearance

---

### **Complete Example Calculation**

Given:
- `robot_width = 0.6m`
- `safety_margin = 0.2m`
- `resolution = 20 cells/m`

**Step-by-step:**
1. `robot_clearance = 0.6 + 0.2 = 0.8m`
2. Convert to cells: `0.8 × 20 = 16 cells`
3. Get radius: `16 / 2 = 8 cells`
4. Round up: `ceil(8) = 8 cells`
5. Add buffer: `8 + 1 = 9 cells`

**Final: `clearance_cells = 9`**

**Physical meaning:**
- Each obstacle grows by 9 cells in all directions
- Total clearance diameter = 9 × 2 = 18 cells
- Real-world clearance = 18 / 20 = 0.9m
- Slightly larger than 0.8m due to `+1` safety buffer ✓

---

### **Visual Representation**

```
Before inflation:              After inflation (9 cells):
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . █ . . . . . .  →   █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █
. . . . . . . . . . . . .      █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █ █

Legend: . = free, █ = occupied     9 cells ← → 9 cells (total 19 cells)
Original: 1 occupied cell          Result: 19×19 = 361 occupied cells
```

---

### **Common Mistakes and Fixes**

❌ **Mistake 1: Using `max(robot_width, robot_length)`**
```matlab
robot_clearance = max(robot_width, robot_length) + safety_margin  % WRONG
```
**Problem**: Assumes circular robot, overestimates clearance for rectangular wheelchairs

✅ **Better**: Use just the width (or calculate diagonal for rotation)
```matlab
robot_clearance = robot_width + safety_margin  % BETTER
```

❌ **Mistake 2: Forgetting the `/2`**
```matlab
clearance_cells = ceil(robot_clearance * resolution) + 1  % WRONG
```
**Problem**: Inflates by full clearance in each direction, doubles the buffer

✅ **Correct**: Include `/2` for radius calculation
```matlab
clearance_cells = ceil(robot_clearance * resolution / 2) + 1  % CORRECT
```

❌ **Mistake 3: Rounding down (floor instead of ceil)**
```matlab
clearance_cells = floor(robot_clearance * resolution / 2) + 1  % UNSAFE
```
**Problem**: Under-inflates obstacles, wheelchair might collide

✅ **Safe**: Always round up
```matlab
clearance_cells = ceil(robot_clearance * resolution / 2) + 1  # SAFE
```

### 3. Inflation Function
```matlab
function inflated_map = inflateMap(occ_matrix, clearance)
    for r = 1:rows
        for c = 1:cols
            if occ_matrix(r, c) >= 0.5  % If occupied
                % Mark square region around it as occupied
                r_min = max(1, r - clearance);
                r_max = min(rows, r + clearance);
                c_min = max(1, c - clearance);
                c_max = min(cols, c + clearance);
                
                inflated_map(r_min:r_max, c_min:c_max) = 1;
            end
        end
    end
end
```

## A* Search Process

### 1. Initialization
```matlab
% Data structures
open_set = [start, 0, heuristic(start, goal)]; % [r, c, g_score, f_score]
closed_set = false(rows, cols);               % Explored nodes
came_from = zeros(rows, cols, 2);             % Parent tracking
g_score = inf(rows, cols);                    % Cost from start
g_score(start(1), start(2)) = 0;
```

### 2. Movement Directions
```matlab
% 8-directional movement
directions = [-1,0; 1,0; 0,-1; 0,1; -1,-1; -1,1; 1,-1; 1,1];
costs = [1, 1, 1, 1, sqrt(2), sqrt(2), sqrt(2), sqrt(2)];
```

- **Orthogonal moves**: Cost = 1
- **Diagonal moves**: Cost = √2 ≈ 1.414

### 3. Heuristic Function
```matlab
function h = heuristic(a, b)
    h = sqrt((a(1) - b(1))^2 + (a(2) - b(2))^2);
end
```

Uses **Euclidean distance** - straight-line distance to goal.

### 4. Main Search Loop
```matlab
while size(open_set, 1) > 0
    % 1. Get node with lowest f-score
    [~, idx] = min(open_set(:, 4));
    current = open_set(idx, 1:2);
    
    % 2. Check if goal reached
    if current(1) == goal(1) && current(2) == goal(2)
        % Reconstruct path and return
    end
    
    % 3. Move to closed set
    closed_set(current(1), current(2)) = true;
    
    % 4. Explore neighbors
    for each neighbor
        if neighbor not blocked and not in closed_set
            tentative_g = g_score(current) + movement_cost;
            if tentative_g < g_score(neighbor)
                % Found better path - update
                came_from(neighbor) = current;
                g_score(neighbor) = tentative_g;
                f_score = tentative_g + heuristic(neighbor, goal);
                % Add/update in open_set
            end
        end
    end
end
```

### 5. Path Reconstruction
```matlab
% Backtrack from goal to start using came_from
path = [];
while ~(current == start)
    path = [current; path];
    current = came_from(current(1), current(2), :);
end
path = [start; path];
```

## Debug Visualization

### Real-time Visualization Features
- **Explored cells**: Cyan overlay
- **Open set**: Yellow dots  
- **Current position**: Magenta circle
- **Final path**: Red line with waypoints
- **Statistics**: Iteration count, f-scores, distances

### Video Recording
```matlab
video_writer = VideoWriter('astar_visualization_timestamp.avi');
% Records entire search process
% Adjustable frame rates and quality
```

## Key Parameters

### Wheelchair Dimensions
```matlab
robot_width = 0.6;     % meters
robot_length = 1.0;    % meters  
safety_margin = 0.8;   % Additional clearance
```

### Search Configuration
```matlab
% Visualization intervals
EARLY_RECORD_ITERATIONS = 10;    % Record every iteration initially
MAIN_RECORD_INTERVAL = 10000;    % Record every N iterations later
VIDEO_FRAME_RATE = 10;           % fps
```

## Output Processing

### 1. Waypoint Subsampling
```matlab
% Too many points for smooth control
subsample_factor = max(1, floor(size(astar_path, 1) / 50));
indices = 1:subsample_factor:size(astar_path, 1);
waypoints = [astar_path(indices(1:end-1), :); goal_pos];
```

### 2. Zone and Velocity Assignment
```matlab
% Navigation zones for obstacle avoidance
selectZone = ones(size(waypoints,1), 1);

% Speed profile
V_ref = zeros(size(waypoints,1), 1) + 0.5;  % 0.5 m/s default
V_ref(end-1) = 0.2;  % Slow down before goal
V_ref(end) = 0;      % Stop at goal
```

## Common Issues and Debugging

### Problem: Path too close to walls
- Check `clearance_cells` calculation
- Verify obstacle inflation is working
- Ensure wheelchair dimensions are correct

### Problem: No path found
- Start/goal in occupied space
- Insufficient clearance for narrow passages
- Disconnected map regions

### Problem: Jerky/suboptimal paths
- Increase subsampling factor
- Check heuristic function
- Verify movement costs

## Performance Considerations

- **Grid size**: 800×4000 = 3.2M cells
- **Memory usage**: Multiple arrays of this size
- **Computation time**: Depends on path length and complexity
- **Visualization**: Can slow down search significantly

## A* Algorithm Flowchart

### High-Level Overview with Reasoning

```
┌─────────────────────────────────────────────────────────────────┐
│                    START: PathSetting_AStar                     │
│         Inputs: start_pos, goal_pos, robot dimensions           │
│                                                                 │
│  WHY: User wants wheelchair to navigate from point A to B      │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│                      STEP 1: Load Map                           │
│  • Load map2.mat → occupancy grid (800×4000 cells)             │
│  • Resolution: 20 cells/meter (1 cell = 5cm)                   │
│  • occ_matrix: 0=free space, 1=wall/obstacle                   │
│                                                                 │
│  WHY: A* needs to know where obstacles are to avoid them       │
│  REASONING: Can't plan path without knowing environment layout  │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│              STEP 2: Convert World → Grid Coordinates           │
│  • start_pos [4.0m, -0.2m] → grid [245, 1023]                 │
│  • goal_pos [30m, 12.5m] → grid [800, 3500]                   │
│                                                                 │
│  WHY: Real-world meters don't match array indices              │
│  REASONING: A* works on discrete grid cells, not continuous    │
│             coordinates. Must convert to array indices.         │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│                 STEP 3: Calculate Clearance                     │
│  robot_clearance = max(width, length) + safety_margin          │
│  clearance_cells = ceil(clearance * resolution / 2) + 1        │
│  Example: (1.0 + 0.8) * 20 / 2 + 1 = 19 cells                 │
│                                                                 │
│  WHY: Wheelchair isn't a point - it has physical size          │
│  REASONING: Need to know how much space wheelchair needs       │
│             around it to safely pass obstacles.                 │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│                   STEP 4: Inflate Obstacles                     │
│  For each occupied cell (wall/obstacle):                       │
│    • Grow it by clearance_cells in all directions              │
│    • Mark expanded region as "no-go zone"                      │
│  Result: inflated_map with safety buffers                      │
│                                                                 │
│  WHY: Treat wheelchair as a point on inflated map              │
│  REASONING: Easier to plan path for point than rectangle.      │
│             By growing obstacles, we ensure wheelchair body     │
│             won't collide even when center follows path.        │
│                                                                 │
│  ANALOGY: Like wearing a padded suit - obstacles appear        │
│           bigger so your body won't hit them                    │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│            STEP 5: Initialize A* Data Structures                │
│  • open_set = [start_node]     ← To-do list starts with start │
│  • closed_set = empty           ← No cells explored yet        │
│  • g_score[start] = 0           ← Zero cost at start           │
│  • g_score[others] = infinity   ← Unknown costs elsewhere      │
│  • came_from = empty            ← No path history yet          │
│                                                                 │
│  WHY: Need to track exploration progress and costs             │
│  REASONING: A* needs memory to remember:                       │
│    - What to explore next (open_set)                           │
│    - What's already explored (closed_set)                      │
│    - Shortest known distances (g_score)                        │
│    - How we got to each cell (came_from)                       │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
              ┌──────────────────────────────────────────┐
              │        A* MAIN LOOP (The Search)         │
              │                                          │
              │  GOAL: Find shortest path by exploring   │
              │        most promising cells first        │
              └──────────────┬───────────────────────────┘
                             │
                             ▼
               ┌─────────────────────────────────────────┐
               │  Is open_set empty?                     │
               │                                         │
               │  CHECK: Do we have candidates to explore?│
               └─────┬───────────────────────┬───────────┘
                 YES │                       │ NO
                     │                       │
                     ▼                       ▼
      ┌──────────────────────────┐  ┌──────────────────────────────┐
      │     NO PATH EXISTS       │  │ Pick cell with lowest f(n)   │
      │                          │  │ from open_set                │
      │  WHY: Explored all       │  │                              │
      │  reachable cells, goal   │  │ WHY: Explore most promising  │
      │  not found. Likely:      │  │      path first (f = g + h)  │
      │  - Goal inside obstacle  │  │                              │
      │  - Path blocked by walls │  │ REASONING: Cell with lowest  │
      │  - Insufficient clearance│  │ f(n) has best combo of:      │
      │                          │  │ • Short distance traveled    │
      └──────────────────────────┘  │ • Short distance to goal     │
                                    └───────────┬──────────────────┘
                                                │
                                                ▼
                                    ┌──────────────────────────┐
                                    │ Is current = goal?       │
                                    │                          │
                                    │ CHECK: Reached target?   │
                                    └────┬──────────────┬──────┘
                                    YES  │              │ NO
                                         │              │
                                         ▼              ▼
                          ┌──────────────────────┐  ┌──────────────────────┐
                          │  SUCCESS!            │  │ Mark current as      │
                          │  Reconstruct Path    │  │ EXPLORED             │
                          │                      │  │ (add to closed_set)  │
                          │  WHY: Found goal!    │  │                      │
                          │  Now trace back      │  │ WHY: Don't revisit   │
                          │  using came_from     │  │      this cell again │
                          └───────┬──────────────┘  └──────────┬───────────┘
                                  │                            │
                                  │                            ▼
                                  │              ┌──────────────────────────┐
                                  │              │ For each of 8 neighbors: │
                                  │              │ ↑ ↓ ← → ↗ ↘ ↖ ↙        │
                                  │              │                          │
                                  │              │ WHY: Check all possible  │
                                  │              │      next moves          │
                                  │              └──────────┬───────────────┘
                                  │                         │
                                  │                         ▼
                                  │              ┌─────────────────────────────┐
                                  │              │ Is neighbor valid?          │
                                  │              │ • Not an obstacle?          │
                                  │              │ • Not already explored?     │
                                  │              │                             │
                                  │              │ REASONING: Skip if:         │
                                  │              │ - Can't move through walls  │
                                  │              │ - Already found best path   │
                                  │              └──┬──────────────────┬───────┘
                                  │            SKIP │                  │ VALID
                                  │                 │                  │
                                  │                 │                  ▼
                                  │                 │   ┌─────────────────────────┐
                                  │                 │   │ Calculate tentative_g:  │
                                  │                 │   │ cost to reach neighbor  │
                                  │                 │   │ via current cell        │
                                  │                 │   │                         │
                                  │                 │   │ tentative_g =           │
                                  │                 │   │   g[current] +          │
                                  │                 │   │   movement_cost         │
                                  │                 │   │                         │
                                  │                 │   │ WHY: Calculate cost of  │
                                  │                 │   │      this potential path│
                                  │                 │   └──────────┬──────────────┘
                                  │                 │              │
                                  │                 │              ▼
                                  │                 │   ┌─────────────────────────┐
                                  │                 │   │ Is tentative_g better   │
                                  │                 │   │ than g[neighbor]?       │
                                  │                 │   │                         │
                                  │                 │   │ REASONING: Only update  │
                                  │                 │   │ if found SHORTER path   │
                                  │                 │   └──┬─────────────┬────────┘
                                  │                 │  YES │             │ NO
                                  │                 │      │             │
                                  │                 │      ▼             │
                                  │                 │   ┌──────────────┐ │
                                  │                 │   │ UPDATE:      │ │
                                  │                 │   │ • came_from  │ │
                                  │                 │   │ • g_score    │ │
                                  │                 │   │ • f_score    │ │
                                  │                 │   │ • open_set   │ │
                                  │                 │   │              │ │
                                  │                 │   │ WHY: Record  │ │
                                  │                 │   │ better path  │ │
                                  │                 │   └──────┬───────┘ │
                                  │                 │          │         │
                                  │                 └──────────┴─────────┘
                                  │                            │
                                  │               ┌────────────┘
                                  │               │
                                  │               │ (Continue with
                                  │               │  next neighbor)
                                  │               │
                                  └───────────────┴─────(Loop back to check open_set)


┌─────────────────────────────────────────────────────────────────┐
│                  STEP 6: Path Reconstruction                    │
│  Starting from goal, backtrack using came_from breadcrumbs:    │
│    path = []                                                    │
│    current = goal                                              │
│    while current != start:                                     │
│      path.insert_at_beginning(current)                         │
│      current = came_from[current]  ← Follow breadcrumbs back   │
│    path.insert_at_beginning(start)                             │
│  Result: path in grid coordinates [row, col]                   │
│                                                                 │
│  WHY: A* found goal but only stored "breadcrumbs"              │
│  REASONING: came_from array shows how to get to each cell.     │
│             By following it backward from goal→start, we        │
│             reconstruct the optimal path that A* discovered.    │
│                                                                 │
│  ANALOGY: Like retracing your steps by following footprints    │
│           you left behind                                       │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│              STEP 7: Convert Grid → World Coordinates           │
│  For each [row, col] in path:                                  │
│    world_pos = grid2world(map_obj, [row, col])                │
│  Result: path in real-world meters [x, y]                      │
│                                                                 │
│  WHY: Path is in array indices, need real-world positions      │
│  REASONING: Wheelchair controller needs actual meter positions,│
│             not grid cell indices. Convert back to meters.      │
│                                                                 │
│  EXAMPLE: Grid [245,1023] → World [4.0m, -0.2m]               │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│                   STEP 8: Subsample Waypoints                   │
│  Path may have 1000s of points, reduce to ~50 waypoints       │
│  subsample_factor = floor(path_length / 50)                    │
│  waypoints = path[1:subsample_factor:end]                      │
│                                                                 │
│  WHY: Too many waypoints overwhelms controller                 │
│  REASONING: A* returns every single grid cell in path          │
│             (could be 1000+ points). Wheelchair only needs      │
│             key waypoints to follow. Keep start, end, and       │
│             evenly-spaced points in between.                    │
│                                                                 │
│  ANALOGY: Like giving driving directions - don't need every    │
│           meter, just key turns and landmarks                   │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│            STEP 9: Assign Zones and Velocities                  │
│  • selectZone = ones() for normal navigation                   │
│  • V_ref = 0.5 m/s (default speed)                            │
│  • V_ref[end-1] = 0.2 m/s (slow before goal)                  │
│  • V_ref[end] = 0 (stop at goal)                              │
│                                                                 │
│  WHY: Need speed profile for smooth, safe navigation           │
│  REASONING:                                                     │
│    • Zones: Tell controller which obstacle avoidance mode      │
│    • V_ref: Target velocity at each waypoint                   │
│    • Slow down near goal: Prevent overshooting destination     │
│    • Stop at goal: Ensure precise positioning                  │
│                                                                 │
│  ANALOGY: Like speed limit signs along a route                 │
└────────────────────────────┬────────────────────────────────────┘
                             │
                             ▼
┌─────────────────────────────────────────────────────────────────┐
│                    OUTPUT: Return Results                       │
│  • waypoints: [x,y] positions in meters                        │
│  • selectZone: navigation zone for each waypoint               │
│  • V_ref: velocity profile for each waypoint                   │
│                                                                 │
│  SUCCESS! Wheelchair controller can now execute path           │
│                                                                 │
│  NEXT STEP: Controller tracks waypoints sequentially,          │
│             avoiding dynamic obstacles in real-time             │
└─────────────────────────────────────────────────────────────────┘
```

### Detailed A* Cost Calculation

```
For each neighbor being evaluated:

┌──────────────────────────────────────┐
│  Current node: (r, c)                │
│  g_score[current] = 10.5             │
└──────────────┬───────────────────────┘
               │
               ▼
┌──────────────────────────────────────┐
│  Neighbor node: (r+1, c+1)           │
│  Movement: Diagonal                  │
│  Movement cost = √2 ≈ 1.414          │
└──────────────┬───────────────────────┘
               │
               ▼
┌──────────────────────────────────────┐
│  Calculate tentative_g:              │
│  tentative_g = g[current] + cost     │
│  tentative_g = 10.5 + 1.414 = 11.914 │
└──────────────┬───────────────────────┘
               │
               ▼
┌──────────────────────────────────────┐
│  Calculate h (heuristic):            │
│  h = Euclidean distance to goal      │
│  h = √((r-goal_r)² + (c-goal_c)²)   │
│  h = 50.3                            │
└──────────────┬───────────────────────┘
               │
               ▼
┌──────────────────────────────────────┐
│  Calculate f (total cost):           │
│  f = g + h                           │
│  f = 11.914 + 50.3 = 62.214         │
└──────────────┬───────────────────────┘
               │
               ▼
┌──────────────────────────────────────┐
│  Is tentative_g < g[neighbor]?       │
│  YES → Update neighbor               │
│    g[neighbor] = 11.914              │
│    f[neighbor] = 62.214              │
│    came_from[neighbor] = current     │
│    Add to open_set                   │
└──────────────────────────────────────┘
```

### Movement Directions (8-directional)

```
         Cost = 1        Cost = √2      Cost = 1
            ↑               ↗              →
            │             /
Cost = 1 ← [Current] → Cost = 1
            │             \
            ↓               ↘              →
         Cost = 1        Cost = √2      Cost = 1

Orthogonal moves (↑↓←→): Cost = 1
Diagonal moves (↗↘↙↖): Cost = √2 ≈ 1.414
```

### Key Formulas Summary

```
┌─────────────────────────────────────────────────┐
│  f(n) = g(n) + h(n)                            │
│                                                 │
│  g(n) = actual cost from start to node n       │
│  h(n) = heuristic (Euclidean distance to goal) │
│  f(n) = estimated total cost through node n    │
└─────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────┐
│  Heuristic Function:                            │
│  h(a,b) = √((a_row - b_row)² + (a_col - b_col)²) │
└─────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────┐
│  Clearance Calculation:                         │
│  robot_clearance = max(W, L) + safety_margin    │
│  clearance_cells = ceil(clearance × res / 2) + 1│
└─────────────────────────────────────────────────┘
```

---

*This document explains the A* implementation in `PathSetting_AStar.m` for the wheelchair navigation project.*