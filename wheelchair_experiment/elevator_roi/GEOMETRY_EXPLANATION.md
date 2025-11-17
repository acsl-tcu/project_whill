# Elevator-Wheelchair Geometry Explanation

## Critical Understanding: Wheelchair Heading vs Elevator Orientation

### Top View Diagram

```
                    Elevator (Top View)

     Y↑
      |
      |     ┌─────────────────────┐
      |     │                     │ ← Longer side (Length L = 2.0m)
      |     │                     │
      |     │         ×           │ ← Elevator center
      |     │                     │
      |     │      [DOOR]         │ ← Entrance (on longer side)
      |     └──────────┬──────────┘
      |                │
      |                ↓ Wheelchair heading (INTO elevator)
      |              [■→]  Wheelchair
      |
      └──────────────────────────→ X

Legend:
  × = Elevator center
  ■→ = Wheelchair (arrow shows heading direction)
  ┌─┐ = Elevator walls
  [DOOR] = Elevator entrance
```

### Key Geometric Relationships

1. **Elevator Orientation (θ_elevator)**
   - Defined as the angle of the **longer side** (length L)
   - In the diagram above: θ_elevator ≈ 0° (parallel to X-axis)

2. **Wheelchair Heading (θ_wheelchair)**
   - Points INTO the elevator (forward motion)
   - **Perpendicular** to the elevator entrance
   - In the diagram above: θ_wheelchair ≈ 90° (parallel to Y-axis)

3. **Mathematical Relationship**
   ```
   θ_elevator = θ_wheelchair ± 90°
   ```
   - The ± depends on which way is "forward" for the elevator orientation
   - Algorithm tries both and picks the better fit

### Example Scenarios

#### Scenario 1: Elevator facing East
```
Elevator orientation: θ_elevator = 0° (East)
Wheelchair heading: θ_wheelchair = 90° (North, going into elevator)
Relationship: θ_elevator = θ_wheelchair - 90°
```

#### Scenario 2: Elevator facing North
```
Elevator orientation: θ_elevator = 90° (North)
Wheelchair heading: θ_wheelchair = 0° (East, going into elevator)
Relationship: θ_elevator = θ_wheelchair + 90°
```

#### Scenario 3: Elevator facing at 25°
```
Elevator orientation: θ_elevator = 25°
Wheelchair heading: θ_wheelchair = 115° (perpendicular, going into elevator)
Relationship: θ_elevator = θ_wheelchair - 90°
```

### Why This Matters for the Algorithm

**OLD (WRONG) Assumption:**
```matlab
theta_elevator = theta_wheelchair;  % WRONG! They are perpendicular, not parallel!
```

**CORRECT Implementation:**
```matlab
% Wheelchair heading is PERPENDICULAR to elevator orientation
% Try both ±90° options and pick the better fit
theta_option1 = wheelchair_heading + pi/2;
theta_option2 = wheelchair_heading - pi/2;
best_theta = selectBestOrientation(points, theta_option1, theta_option2);
```

### How to Determine ± Sign

The algorithm doesn't need to guess! It tries **both** ±90° rotations and picks the one where:
- Point cloud spread better matches expected dimensions [L, W]
- This is done by the `selectBestOrientationSimple()` helper function

**Method:**
1. Rotate points by `θ_wheelchair + 90°` → measure spread → compare to [L, W]
2. Rotate points by `θ_wheelchair - 90°` → measure spread → compare to [L, W]
3. Pick the rotation with smaller error

### Visual Example of Selection

```
Option 1: θ = θ_wheelchair + 90°
Points spread: [2.1m × 1.4m] ≈ [L=2.0m, W=1.5m] ✓ Good fit!
Error = 0.14m

Option 2: θ = θ_wheelchair - 90°
Points spread: [1.4m × 2.1m] ≈ [W=1.5m, L=2.0m] ✓ Also good, but transposed
Error = 0.14m (same)

→ Algorithm picks Option 1 (convention: angle represents longer side direction)
```

### Common Mistake to Avoid

❌ **WRONG:**
```matlab
% Assuming wheelchair heading = elevator orientation
elevator_pose = fitElevator(points, wheelchair_heading);
% This would fit the elevator PARALLEL to wheelchair direction!
```

✅ **CORRECT:**
```matlab
% Algorithm internally computes elevator_orientation = wheelchair_heading ± 90°
elevator_pose = fitElevatorSimplified(points, wheelchair_heading, W, L);
% Automatically handles the perpendicular relationship
```

---

## Summary

| Concept | Value | Direction |
|---------|-------|-----------|
| **Elevator Orientation** | θ_elevator | Longer side direction |
| **Wheelchair Heading** | θ_wheelchair | INTO elevator (forward) |
| **Relationship** | θ_elevator = θ_wheelchair ± 90° | Perpendicular |
| **Entrance Location** | On longer side | Where wheelchair enters |

The simplified algorithm handles this geometry automatically by:
1. Computing both ±90° options from wheelchair heading
2. Testing which fits the point cloud better
3. Returning the correct elevator center and orientation

---

*Created: 2025-01-27*
*Critical geometry clarification for wheelchair-elevator navigation*
