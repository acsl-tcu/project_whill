# EvaluationPath_vec_gpu.m - Comprehensive Technical Documentation

## Overview
The `EvaluationPath_vec_gpu.m` function is the **core path evaluation engine** for the Model Predictive Control (MPC) system. It evaluates thousands of predicted robot trajectories simultaneously on GPU and assigns costs based on multiple criteria including wall collision, velocity constraints, path following, and obstacle avoidance.

---

## Function Signature
```matlab
function [pw, remove_sample] = EvaluationPath_vec_gpu(obj, px, pu, preobs, param_FPM, Grid_Matrix, boundingBoxes)
```

### Inputs:
- **`obj`**: Controller object containing parameters (horizons, penalties, vehicle dimensions)
- **`px`**: Predicted robot states `[3 × K × NP]` where:
  - Dimension 1: `[x, y, yaw]` robot pose
  - Dimension 2: `K` prediction horizon steps (typically 21)
  - Dimension 3: `NP` sample trajectories (typically 1000)
- **`pu`**: Predicted control inputs `[2 × K × NP]` where:
  - Dimension 1: `[linear_velocity, angular_velocity]`
- **`preobs`**: Predicted obstacle states `[6 × num_obstacles × K]`
- **`param_FPM`**: Fast Proximity Mapping parameters for dynamic obstacle avoidance
- **`Grid_Matrix`**: Occupancy grid map for static obstacles (walls)
- **`boundingBoxes`**: LiDAR-detected objects as bounding boxes

### Outputs:
- **`pw`**: Path weights/costs `[1 × NP]` - lower is better
- **`remove_sample`**: Boolean array `[1 × NP]` indicating paths that hit walls

---

## Step-by-Step Algorithm Breakdown

### 1. Data Preparation (Lines 3-11)
```matlab
obj.K = gpuArray(obj.K);           % Prediction horizon (21 steps)
obj.NP = gpuArray(obj.NP);         % Number of samples (1000 paths)
px = gpuArray(px);                 % Move to GPU for parallel processing
pu = gpuArray(pu);
```
**Purpose**: Transfers all data to GPU memory for massive parallel computation across 1000+ trajectories.

---

### 2. Vehicle Geometry and Collision Detection

#### 2.1 Robot State Reshaping (Line 18)
```matlab
px2 = reshape(px, 3, 1, obj.K, obj.NP);
```
**What it does**: Reshapes robot states to `[3 × 1 × K × NP]` format for vectorized operations.
- **Dimension 1**: `[x, y, yaw]` coordinates
- **Dimension 2**: Singleton (for broadcasting)
- **Dimension 3**: Time steps (K=21)
- **Dimension 4**: Different trajectory samples (NP=1000)

#### 2.2 Rotation Matrix Calculation (Line 20)
```matlab
roll = [cos(px2(3,:,:,:)) -sin(px2(3,:,:,:)); 
        sin(px2(3,:,:,:))  cos(px2(3,:,:,:))];
```
**What is `roll`?**
- **NOT** the roll angle of the robot (confusing variable name!)
- Actually the **2D rotation matrix** for transforming coordinates
- **Shape**: `[2 × 2 × K × NP]` - one rotation matrix per (timestep, sample)
- **Purpose**: Rotates wheelchair corner points from robot-local to world coordinates

**Mathematical meaning**:
```
For robot yaw angle θ:
roll = [cos(θ) -sin(θ)]  = Standard 2D rotation matrix
       [sin(θ)  cos(θ)]
```

#### 2.3 Vehicle Corner Points Transformation (Line 22)
```matlab
vehicle_Points = pagetranspose(pagemtimes(roll, obj.points') + px2(1:2,:,:,:));
```
**What is `vehicle_Points`?**
- **Physical meaning**: 4 corner points of the wheelchair at each predicted position
- **`obj.points`**: Wheelchair corner coordinates in robot-local frame:
  ```matlab
  obj.points = [-wheel_len_rear,  wheel_width;     % Rear-right corner
                 wheel_len_front, wheel_width;     % Front-right corner  
                -wheel_len_rear, -wheel_width;     % Rear-left corner
                 wheel_len_front, -wheel_width];   % Front-left corner
  ```
- **Shape**: `[4 × 2 × K × NP]` - 4 corners, (x,y) coordinates, K timesteps, NP samples

**Transformation process**:
1. Rotate corner points by robot yaw: `roll × obj.points'`
2. Translate to robot position: `+ px2(1:2,:,:,:)`
3. Result: World coordinates of all 4 wheelchair corners for every predicted position

---

### 3. Wall Collision Detection and Cost

#### 3.1 World to Grid Coordinate Conversion (Line 25)
```matlab
state = vehicle_Points - [obj.Grid_Xlim(1), obj.Grid_Ylim(1)];
```
**Purpose**: Converts world coordinates to grid-relative coordinates by subtracting grid origin.

#### 3.2 Grid Index Calculation (Line 26) ⭐ **CRITICAL**
```matlab
Grid_Idx = [obj.Grid_Size(1) 0] + [-1 1] .* floor(state(:,[2,1],:,:)./obj.Cell_Size) + [0 1];
```
**What is `Grid_Idx`?**
- **Purpose**: Converts grid-relative coordinates to matrix indices
- **Shape**: `[4 × 2 × K × NP]` where each element is `[row_index, col_index]`

**Key Detail - Coordinate Swap**: `state(:,[2,1],:,:)`
- **Original**: `state = [x, y]` (world coordinates)
- **Swapped**: `[y, x]` for grid indexing
- **Why?**: MATLAB matrices are indexed as `Matrix(row, col)` where:
  - `row` corresponds to **Y-coordinate** (North-South)
  - `col` corresponds to **X-coordinate** (East-West)

**Mathematical breakdown**:
```matlab
% For a point at world coordinates (x_world, y_world):
x_grid = (x_world - Grid_Xlim(1)) / Cell_Size   % Grid X-coordinate
y_grid = (y_world - Grid_Ylim(1)) / Cell_Size   % Grid Y-coordinate

% Convert to MATLAB matrix indices:
col_index = floor(x_grid) + 1                   % +1 for 1-based indexing
row_index = floor(y_grid) + 1

% Store as [row, col] = [y_index, x_index]
Grid_Idx = [row_index, col_index]
```

#### 3.3 Boundary Handling (Lines 28-29)
```matlab
flag_out = any(Grid_Idx < [0 0] | Grid_Idx > [obj.Grid_Size(1) obj.Grid_Size(2)], 2);
Grid_Idx = ~flag_out .* Grid_Idx + flag_out .* obj.Grid_Size;
```
**Purpose**: Handle out-of-bounds indices by clamping to grid boundaries.

#### 3.4 Linear Index Conversion (Line 31)
```matlab
Grid_Idx_linear = sub2ind(obj.Grid_Size, Grid_Idx(:,1,:,:), Grid_Idx(:,2,:,:));
```
**What is `Grid_Idx_linear`?**
- **Purpose**: Converts 2D matrix indices `(row, col)` to 1D linear indices
- **Why needed?**: For efficient GPU memory access to `Grid_Matrix`
- **Shape**: `[4 × 1 × K × NP]` - one linear index per corner

**Mathematical meaning**:
```matlab
% For a matrix of size [M, N]:
linear_index = (col-1) * M + row
% This allows: Matrix(row, col) == Matrix(linear_index)
```

#### 3.5 Occupancy Value Lookup (Line 33)
```matlab
Grid_values = max(Grid_Matrix(Grid_Idx_linear));
```
**Purpose**: Look up occupancy probability at each wheelchair corner position.
- **Range**: 0.0 (free space) to 1.0 (occupied/wall)

#### 3.6 Path Removal (Line 35)
```matlab
remove_sample = squeeze(max(Grid_values, [], 3) >= 0.98);
```
**What is `remove_sample`?**
- **Boolean array**: `[1 × NP]` indicating which paths hit walls
- **Logic**: If ANY corner at ANY timestep has occupancy ≥ 0.98 → remove entire path
- **Result**: These paths get infinite cost and are excluded from selection

#### 3.7 Wall Cost Calculation (Line 37)
```matlab
WALLcost = pagetranspose(squeeze(sum(Grid_values, 3)) * obj.wall_penalty1);
```
**What is `WALLcost`?**
- **Continuous penalty** for paths near walls (but not hitting them)
- **Calculation**: Sum occupancy values across all timesteps × penalty weight
- **Range**: 0 (far from walls) to high values (close to walls)

---

### 4. Dynamic Obstacle Avoidance (FPM Cost)

#### 4.1 Fast Proximity Mapping (Lines 39-41)
```matlab
preobs2 = pagetranspose(preobs);
[grade] = FPM_capsule_v3_3vec(obj, px2(1,:,2:obj.K,:), px2(2,:,2:obj.K,:), px2(3,:,2:obj.K,:), preobs2(:,:,1:obj.K-1), param_FPM);
FPMcost = reshape((obj.K-1) - sum(grade, 3), 1, []);
```
**What is `FPMcost`?**
- **Purpose**: Penalize paths that get too close to moving obstacles (people)
- **Algorithm**: Fast Proximity Mapping using capsule-shaped safety zones
- **Input**: Robot trajectory vs. predicted pedestrian trajectories
- **Output**: Higher cost for paths with potential collisions

---

### 5. LiDAR Object Avoidance (Bounding Box Cost)

#### 5.1 Bounding Box Cost Calculation (Lines 44-48)
```matlab
if nargin > 6 && ~isempty(boundingBoxes)
    BBcost = calculateBoundingBoxCost(obj, px2, boundingBoxes);
else
    BBcost = zeros(1, obj.NP, 'gpuArray');
end
```
**What is `BBcost`?**
- **Purpose**: Avoid LiDAR-detected objects (furniture, obstacles)
- **Method**: Check if robot trajectory intersects with oriented bounding boxes
- **Implementation**: Collision penalty + proximity penalty with safety margins

---

### 6. Velocity Constraints (Lines 51-54)

```matlab
v_max = 0.55;  v_min = -0.25;  v_cost = 5000;
Vcost = reshape(((pu(1,1,:) - v_max) * v_cost) .* (pu(1,1,:) > v_max) + 
                ((pu(1,1,:) - v_min) * -v_cost) .* (pu(1,1,:) < v_min), 1, []);
```
**What is `Vcost`?**
- **Purpose**: Enforce velocity limits
- **Logic**: 
  - If `v > v_max` → add penalty proportional to excess speed
  - If `v < v_min` → add penalty for excessive backward speed
- **Result**: Forces robot to stay within safe speed limits

---

### 7. Path Following Cost (Lines 57-59)

```matlab
Vref = reshape(obj.V_ref(obj.target_n(1:obj.K-1,:)), 1, obj.K-1, obj.NP);
Inputcost = reshape(sum(pu(2,1:end-1,:).^2) * obj.R(2) + 
                   sum((pu(1,1:end-1,:) - Vref).^2) * obj.R(1), [1,obj.NP]);
```
**What is `Inputcost`?**
- **Purpose**: Minimize control effort and track reference velocity
- **Components**:
  - `pu(2,...)^2 * R(2)`: Penalize angular velocity (minimize turning)
  - `(pu(1,...) - Vref)^2 * R(1)`: Penalize deviation from target speed
- **Result**: Smoother, more efficient trajectories

---

### 8. Waypoint Following Cost (Lines 62-67)

```matlab
Q = 0.15;
w0 = gpuArray(reshape(obj.waypoint(obj.target_n-1,:)', 1, 2, obj.K, obj.NP));
w1 = gpuArray(reshape(obj.waypoint(obj.target_n,:)', 1, 2, obj.K, obj.NP));
state = gpuArray(pagetranspose(px2(1:2,:,:,:)));
d_target = get_distance(w0, w1, state);
Dcost = reshape(sum(d_target, 3) * Q, 1, []);
```
**What is `Dcost`?**
- **Purpose**: Follow planned waypoint path
- **Method**: Calculate perpendicular distance from robot to line segments between waypoints
- **Result**: Paths that deviate from planned route get higher cost

---

### 9. Final Cost Combination (Line 69)

```matlab
pw = FPMcost + Inputcost + Vcost + WALLcost + Dcost + BBcost;
```
**What is `pw` (Path Weights)?**
- **Total cost** for each trajectory
- **Lower values** = better paths
- **Components balanced** by penalty weights in controller parameters

---

## Cost Function Summary

| Cost Component | Purpose | Typical Range | Penalty Weight |
|----------------|---------|---------------|----------------|
| **WALLcost** | Avoid static obstacles (walls) | 0-1000+ | `wall_penalty1 = 10` |
| **FPMcost** | Avoid moving obstacles (people) | 0-20 | Built into FPM |
| **BBcost** | Avoid LiDAR objects | 0-5000+ | `collision_penalty = 5000` |
| **Vcost** | Enforce speed limits | 0-5000+ | `v_cost = 5000` |
| **Inputcost** | Minimize control effort | 0-10 | `R = [0.5, 0.1]` |
| **Dcost** | Follow waypoint path | 0-5 | `Q = 0.15` |

---

## GPU Optimization Strategy

### Why GPU?
- **Massive parallelization**: Evaluate 1000+ paths simultaneously
- **Vectorized operations**: Single instruction operates on entire arrays
- **Memory bandwidth**: Efficient for large matrix operations

### Key GPU Operations:
1. **`pagemtimes`**: Matrix multiplication across 4D arrays
2. **`pagetranspose`**: Transpose across page dimensions
3. **Broadcast operations**: Automatic array expansion for element-wise ops
4. **`sub2ind`**: Vectorized index conversion

---

## Debugging and Visualization

The enhanced debug system shows:
- **Grid coordinate transformations**: Exact mapping from world to grid indices
- **Vehicle corner tracking**: Yellow rectangles showing checked grid cells
- **Path coloring**: Visual representation of cost values
- **Collision visualization**: Which paths hit walls vs. which avoid them

Enable with: `debug_plot_enabled = true` on line 76.

---

## Common Issues and Solutions

### Issue 1: Reversed Map Orientation
**Problem**: Map appears flipped compared to robot movement
**Cause**: Coordinate system mismatch between visualization and MPC
**Solution**: Use exact same transformations as MPC (see debug functions)

### Issue 2: High Computational Cost
**Problem**: Function takes too long to execute
**Cause**: Large number of samples or prediction horizon
**Solution**: Tune `NP` (samples) and `K` (horizon) parameters

### Issue 3: Robot Stuck Against Walls
**Problem**: Robot cannot find valid paths
**Cause**: All paths removed due to wall collisions
**Solution**: Reduce `wall_penalty1` or increase safety margins

---

This documentation provides a complete understanding of how `EvaluationPath_vec_gpu.m` transforms robot poses into grid coordinates, evaluates multiple cost functions, and selects optimal trajectories for safe autonomous navigation.