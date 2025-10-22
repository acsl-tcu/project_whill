# FPM Bounding Box Algorithm Documentation

## Overview

The new FPM (Fuzzy Potential Method) algorithm replaces capsule-based obstacle representation with oriented rectangular bounding boxes for improved wheelchair navigation around rectangular obstacles like furniture, doors, and walls.

## Algorithm Architecture

### 1. **Data Flow Pipeline**

```
LiDAR Point Cloud → Clustering → Bounding Box Generation → FPM Evaluation → Path Cost
```

#### Input Sources:
- **Estimate.m:573**: `generateBoundingBoxes()` creates oriented rectangles from clustered point clouds
- **Control.m:398**: Receives bounding boxes via `obj.boundingBoxes`  
- **EvaluationPath_vec_gpu.m:46**: Integrates bounding box FPM into path evaluation

### 2. **Bounding Box Data Structure**

Each bounding box contains:
```matlab
bbox.center = [center_x, center_y, center_z];        % 3D center point
bbox.dimensions = [oriented_length, oriented_width, height];  % [length, width, height]  
bbox.orientation = orientation;                       % Rotation angle (radians)
bbox.corners = corners;                              % 4x2 corner points
bbox.pointCount = size(cluster_points, 1);          % Number of points
bbox.clusterID = i;                                  % Cluster identifier
```

## Core Algorithm Components

### 1. **Goal Potential Membership Function (PMF)**

Uses pre-computed target headings for efficiency:

```matlab
% Pre-computed target headings (computed once during initialization)
th_target = obj.th_target_w(reshape(obj.target_n(2:end,:), [1, 1, K-1, NP]));
phig = th_target - th(:,:,2:end,:);  % Angle difference
grade_target = -((g_a - g_b)/pi) * abs(phaierror) + g_a;
```

**Key Insight - Why `th_target_w` Works:**
- `th_target_w` contains **path direction angles** between consecutive waypoints, not position-dependent angles
- These directions are **path-invariant** - they represent the desired heading when traveling from waypoint i to waypoint i+1
- As wheelchair position changes, the target heading remains the same for each waypoint segment
- Only needs to be computed once during initialization via `get_th_target(obj.waypoint)`

**Why K-1 Dimensions:**
- **K** = total prediction steps (including current position at step 1)
- **K-1** = future prediction steps (steps 2 to K) where obstacles matter
- Current position (step 1) doesn't need obstacle avoidance evaluation
- This matches the original FPM approach: evaluate obstacles for future positions only

**Parameters:**
- `g_a = 1.0` (maximum attraction)  
- `g_b = eta * g_a` (minimum attraction, eta ≈ 0.5)

### 2. **Rectangular Obstacle PMF** 

**Key Innovation**: Replaces capsule geometry with oriented rectangles.

#### A. Coordinate Transformation
```matlab
% Transform to wheelchair coordinate frame
R = [cos(-th), -sin(-th); sin(-th), cos(-th)];
bbox_center_wf = (R * (bbox_center - wheelchair_pos)')';
```

#### B. Distance Calculation to Rectangle
```matlab
function [min_dist, closest_point] = distanceToRectangle(rect_center, length, width, orientation, point)
```

**Algorithm Steps:**
1. **Translate** point to rectangle's local coordinate system
2. **Rotate** to align with rectangle axes  
3. **Clamp** point to rectangle bounds
4. **Calculate** minimum distance

**Mathematical Implementation:**
```matlab
% Rotate point to rectangle's local frame
local_point = [cos(-θ) * rel_x - sin(-θ) * rel_y,
               sin(-θ) * rel_x + cos(-θ) * rel_y];

% Clamp to rectangle bounds  
clamped_x = max(-half_length, min(half_length, local_point(1)));
clamped_y = max(-half_width, min(half_width, local_point(2)));

% Distance calculation
min_dist = norm(local_point - [clamped_x, clamped_y]);
```

#### C. Angular Range Calculation
```matlab
function [phi_min, phi_max] = calculateAngularRange(corners, center_point)
```

**Algorithm Steps:**  
1. Calculate angles to all rectangle corners
2. Handle angle wrapping (−π to π)
3. Find angular span occupied by rectangle

**Key Logic:**
```matlab
% Find largest gap between consecutive angles
gaps = diff([sorted_angles; sorted_angles(1) + 2*pi]);
if max_gap > pi
    % Span everything except the gap  
    phi_min = angles(after_gap_idx);
    phi_max = angles(gap_idx);
else
    % Direct span from min to max
    phi_min = min(angles);
    phi_max = max(angles);  
end
```

### 3. **Obstacle Cost Function**

**Collision Detection:**
```matlab
if (phi_min <= 0) && (0 <= phi_max)  % Obstacle blocks forward direction
    if distance_to_center < alpha     % Within consideration threshold
        effective_margin = margin + wheelchair_radius;
        safe_distance = min_dist - effective_margin;
        
        if safe_distance > 0
            % Safe zone - exponential decay
            grade_obs = 1 - exp(-safe_distance / 1.0);  
        else  
            % Collision risk - penalty
            grade_obs = exp(safe_distance / 1.0) - obs_cost;
        end
    end
end
```

**Cost Parameters:**
- `alpha = 5.0` (consideration distance threshold)
- `margin = 0.3` (safety margin)  
- `obs_cost = 1.0` (collision penalty)

### 4. **Final Grade Calculation**

```matlab
Grade_old = min(grade_target, min(grade_obs_all));
```

The final grade combines:
- **Goal attraction** (encourages movement toward target)
- **Obstacle repulsion** (penalizes collision risk)

## Integration with Path Planning

### 1. **Path Evaluation Loop**

```matlab
for path_idx = 1:NP  % For each candidate path
    for k = 2:K      % For each step along path
        [~, Grade_old] = FPM_boundingbox(obj, x, y, th, boundingBoxes, target, param_FPM);
        step_cost = 1 - Grade_old;  % Convert grade to cost
        path_cost = path_cost + step_cost;
    end
    FPMcost(1, path_idx) = path_cost;
end
```

### 2. **Cost Integration**

Final path cost combines multiple factors:
```matlab  
total_cost = FPMcost + InputCost + VelocityCost + WallCost + DistanceCost;
```

## Key Advantages Over Capsule FPM

| Aspect | Capsule FPM | Bounding Box FPM |
|--------|-------------|------------------|
| **Obstacle Fit** | Two circles + line | Oriented rectangle |
| **Furniture/Doors** | Poor approximation | Accurate representation |
| **Collision Risk** | Overestimated | Precise calculation |  
| **Path Quality** | Suboptimal spacing | Better space utilization |
| **Corner Navigation** | Wider clearance needed | Tighter navigation possible |

## Performance Considerations

### 1. **Computational Complexity**
- **Rectangle Distance**: O(1) per obstacle (constant time)
- **Angular Range**: O(4) per obstacle (4 corners)
- **Total**: O(N×K) where N=obstacles, K=path steps

### 2. **Memory Usage**
- **Bounding Box Storage**: ~200 bytes per obstacle
- **GPU Compatibility**: Maintains GPU array support
- **Backward Compatibility**: Falls back to capsule FPM when no bounding boxes

### 3. **Real-time Performance**
- **Target**: <100ms per control cycle  
- **Optimization**: Vectorized calculations where possible
- **Parallel Processing**: GPU acceleration maintained

## Configuration Parameters

### FPM Parameters
```matlab
param_FPM = struct(
    'eta',      0.5,    % Goal PMF ratio (0.2-0.8)
    'alpha',    5.0,    % Obstacle consideration distance (m)  
    'margin',   0.3,    % Safety margin (m)
    'obs_cost', 1.0     % Collision penalty
);
```

### Wheelchair Parameters  
```matlab
wheel_width = 0.6;        % Wheelchair width (m)
wheel_len_front = 0.5;    % Front length (m)  
r_wheel = norm([wheel_width, wheel_len_front]);  % Corner radius
```

## Error Handling & Robustness

### 1. **Edge Cases**
- **Empty bounding boxes**: Falls back to capsule FPM
- **Degenerate rectangles**: Skipped (< 3 points)
- **Numerical stability**: Grade clamped to [0,1]

### 2. **Backward Compatibility**
```matlab
if nargin > 6 && ~isempty(boundingBoxes)
    % Use bounding box FPM
    FPMcost = calculateBoundingBoxFPMCost(...);
else
    % Fallback to capsule FPM  
    FPMcost = capsule_based_calculation(...);
end
```

This ensures the system continues working even if bounding box generation fails or is disabled.

## Implementation Files

### Core Files
- **`FPM_boundingbox.m`**: Main FPM function using rectangular obstacles
- **`calculateBoundingBoxFPMCost.m`**: Path evaluation integration function
- **`EvaluationPath_vec_gpu.m`**: Modified to use bounding box FPM

### Integration Points
- **`Estimate.m:573`**: Bounding box generation from point clouds
- **`Control.m:398`**: Data transfer from estimator to controller
- **`Control.m:724`**: Path evaluation with bounding boxes

## Testing and Validation

### Recommended Test Scenarios
1. **Rectangular Obstacles**: Tables, desks, cabinets
2. **Narrow Passages**: Doorways, corridors
3. **Corner Navigation**: L-shaped obstacles
4. **Mixed Environments**: Combination of rectangular and irregular obstacles

### Performance Metrics
- **Path Quality**: Smoother paths around rectangular obstacles
- **Clearance Optimization**: Better space utilization
- **Computation Time**: Should remain <100ms per cycle
- **Collision Avoidance**: No collisions in test scenarios

## Current Implementation Analysis: Circle vs Box Shape Processing

### **CONFIRMED**: The FPM bounding box system currently uses circle approximation in GPU vectorized mode

After analyzing the codebase, the current implementation has **two distinct processing modes**:

#### 1. **Non-Vectorized Mode** (`FPM_boundingbox.m`)
- ✅ **Full rectangular bounding box processing**
- ✅ Uses exact point-to-rectangle distance calculation (`distanceToRectangle()`)
- ✅ Proper angular range calculation from corner points (`calculateAngularRange()`)
- ✅ True rectangular collision detection
- ❌ **Performance**: Slower, processes obstacles sequentially

#### 2. **Vectorized/GPU Mode** (`FPM_boundingbox_vec.m`)
- ✅ **High performance** - processes all obstacles and paths simultaneously
- ❌ **Uses circle approximation** for computational efficiency
- ❌ Lines 107-108: `equiv_radius = vecnorm(bbox_dims, 2, 2) / 2` (equivalent circle radius)
- ❌ Line 110: `PoQ3 = max(0, PoQo - equiv_radius)` (distance to circle boundary)
- ❌ Line 114: `bbox_angular_extent = 2 * atan(equiv_radius ./ max(PoQo, equiv_radius))` (circular angular calculation)

### **Key Problem Identified**

The **vectorized GPU implementation sacrifices rectangular accuracy for performance**, reverting to the same circle-based approximation issues that the bounding box system was designed to solve:

```matlab
% Current vectorized approximation (FPM_boundingbox_vec.m:105-107)
% Approximate bounding box as equivalent circle for vectorized calculation
% This maintains performance while providing reasonable obstacle avoidance
equiv_radius = vecnorm(bbox_dims, 2, 2) / 2;  % Approximate radius from dimensions
```

### **Solution: True Vectorized Rectangular Processing**

To maintain both **performance** and **rectangular accuracy**, we need to implement fully vectorized rectangular collision detection:

#### **Required Vectorization Improvements**

1. **Vectorized Point-to-Rectangle Distance**
   - Replace circle approximation with vectorized rectangle clamping
   - Process all [obstacles × paths × timesteps] simultaneously
   - Maintain GPU array compatibility

2. **Vectorized Angular Range from Corners**  
   - Calculate angular extent using actual rectangle corners
   - Handle angle wrapping for all obstacles simultaneously
   - Replace circular angular approximation

3. **True Rectangular Collision Detection**
   - Exact rectangular boundary checking
   - Proper orientation handling in vectorized form
   - Accurate safety margin calculation

#### **Implementation Approach**

```matlab
% Proposed vectorized rectangle distance (pseudo-code)
function [min_dist_vec] = vectorizedRectangleDistance(bbox_centers, bbox_dims, bbox_orients, points)
    % Transform all points to all rectangle local frames simultaneously
    % Input: [obsnum, 2, K-1, NP] arrays
    % Output: [obsnum, 1, K-1, NP] distances
    
    % Vectorized coordinate transformation
    rel_points = points - bbox_centers;  % [obsnum, 2, K-1, NP]
    
    % Vectorized rotation for all rectangles simultaneously  
    cos_theta = cos(-bbox_orients);      % [obsnum, 1, K-1, NP]
    sin_theta = sin(-bbox_orients);      % [obsnum, 1, K-1, NP]
    
    local_x = rel_points(:,1,:,:) .* cos_theta - rel_points(:,2,:,:) .* sin_theta;
    local_y = rel_points(:,1,:,:) .* sin_theta + rel_points(:,2,:,:) .* cos_theta;
    
    % Vectorized clamping to rectangle bounds
    half_length = bbox_dims(:,1,:,:) / 2;  % [obsnum, 1, K-1, NP]
    half_width = bbox_dims(:,2,:,:) / 2;   % [obsnum, 1, K-1, NP]
    
    clamped_x = max(-half_length, min(half_length, local_x));
    clamped_y = max(-half_width, min(half_width, local_y));
    
    % Vectorized distance calculation
    min_dist_vec = sqrt((local_x - clamped_x).^2 + (local_y - clamped_y).^2);
end
```

### **Performance Considerations**

| Aspect | Current Circle Approx | Proposed True Rectangle |
|--------|----------------------|-------------------------|
| **Accuracy** | Poor for rectangular obstacles | Exact rectangular collision |
| **GPU Arrays** | ✅ Full support | ✅ Maintains compatibility |
| **Memory** | Low | Moderate increase |
| **Computation** | O(1) per obstacle | O(1) per obstacle (vectorized) |
| **Real-time** | <100ms | Target: <100ms |

### **Next Steps for Implementation**

1. **Create `FPM_boundingbox_vec_true.m`** - Enhanced vectorized version with true rectangular processing
2. **Benchmark Performance** - Ensure GPU processing stays under 100ms requirement  
3. **A/B Testing** - Compare circle vs rectangle accuracy in real wheelchair scenarios
4. **Integration** - Update `calculateBoundingBoxFPMCost.m` to use improved version

## Future Enhancements

### Potential Improvements
1. **Multi-level Rectangles**: Handle obstacles with different heights
2. **Dynamic Obstacles**: Extend to moving rectangular objects
3. **Uncertainty Handling**: Account for bounding box estimation errors
4. **Parameter Tuning**: Adaptive parameters based on obstacle density
5. **True Vectorized Rectangles**: Eliminate circle approximation in GPU mode (High Priority)

### Research Directions
1. **Machine Learning Integration**: Learn optimal parameters from experience
2. **Sensor Fusion**: Combine LiDAR with camera data for better bounding boxes
3. **Multi-robot Systems**: Coordinate multiple wheelchairs using bounding box FPM
4. **Hybrid Processing**: Adaptive switching between circle and rectangle based on obstacle geometry

---

**Last Updated**: January 2025  
**Version**: 1.1  
**Authors**: Phase 2 Implementation Team  
**Status**: Phase 2.3 Integration Complete - Circle Approximation Issue Identified  
**Next Priority**: Implement True Vectorized Rectangular Processing