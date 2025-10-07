# Claude Code Project Notes

This file contains important notes and reminders for the wheelchair experiment project to help Claude provide better assistance.

## MATLAB Color Limitations

### ❌ INVALID MATLAB Color Names
The following color names are **NOT valid** in MATLAB and will cause errors:

**Text/Background Colors:**
- `'lightyellow'` → Use `'yellow'` or `[1 1 0.8]`
- `'lightgray'` → Use `[0.8 0.8 0.8]`
- `'lightblue'` → Use `[0.7 0.9 1]`
- `'lightgreen'` → Use `[0.7 1 0.7]`
- `'darkred'` → Use `[0.5 0 0]`
- `'darkblue'` → Use `[0 0 0.5]`
- `'darkgreen'` → Use `[0 0.5 0]`

**Plotting Colors:**
- `'orange'` → Use `[1 0.5 0]`
- `'pink'` → Use `[1 0.7 0.8]`
- `'purple'` → Use `[0.5 0 0.5]`
- `'brown'` → Use `[0.6 0.3 0]`
- `'gray'` → Use `[0.5 0.5 0.5]`
- `'lightcoral'` → Use `[1 0.5 0.5]`
- `'gold'` → Use `[1 0.8 0]`
- `'silver'` → Use `[0.7 0.7 0.7]`

### ✅ VALID MATLAB Color Options

**Named Colors (Built-in):**
- `'red'`, `'green'`, `'blue'`
- `'cyan'`, `'magenta'`, `'yellow'` 
- `'black'`, `'white'`
- `'none'` (transparent)

**RGB Triplets:**
- Format: `[R G B]` where R, G, B are values from 0 to 1
- Example: `[1 0.5 0]` for orange, `[0.2 0.8 0.3]` for light green

**Hex Color Codes:**
- 6-digit: `'#FF5733'` (recommended)
- 3-digit: `'#F53'` (shorthand)

### 🎨 Recommended Color Palette for Plotting

```matlab
% Safe color array for multiple plots
safe_colors = {
    'red', 'blue', 'green', 'cyan', 'magenta', 'yellow', ...
    [1 0.5 0],    % orange
    [1 0.7 0.8],  % pink  
    [0.5 0 0.5],  % purple
    [0.6 0.3 0],  % brown
    [0.8 0.8 0.8], % light gray
    [0.2 0.8 0.3]  % light green
};
```

## Git/GitHub Configuration

### GitHub Personal Access Token
**Token:** `[Stored in git remote URL - not displayed for security]`

**Usage for authentication:**
```bash
# When pushing, use token as password, or configure:
git config credential.helper store
# Then on next push, enter username and use token as password
```

**Repository:**
- URL: `https://github.com/acsl-tcu/project_whill.git`
- Current branch: `Elevator_Gazebo`
- Main branch: `main`

## Project Structure Notes

### Key Files and Directories
- `map2.mat` - Main occupancy grid map
- `src/Estimator/Estimate.m` - Main estimation class with flood fill integration
- `src/Controller/FPM_capsule.m` - Current capsule-based obstacle avoidance
- `Floodfill/` - Flood fill ROI implementation

### Integration Points
- Flood fill ROI can replace static ROI in `Estimate.m:558`
- Bounding boxes are already generated in `Estimate.m:572`
- FPM controller in `Control.m` uses obstacle data from Estimate.m

## Common MATLAB Issues

### Text Display
- Always use valid color names for `BackgroundColor` and `EdgeColor`
- Use `sprintf()` for dynamic text formatting
- Use `'Units', 'normalized'` for position-independent text placement

### Plotting
- Use `hold on` after `show(occupancyMap)` 
- Call `drawnow` after complex plotting operations
- Use `axis equal` for proper aspect ratios with maps

### File Paths
- Use relative paths like `'../map2.mat'` from subdirectories
- Always check file existence with `exist(filename, 'file')`
- Use absolute paths when passing between functions

## Flood Fill Implementation Notes

### Performance
- Stack-based implementation preferred over recursive (memory efficient)
- Limit max cells to prevent memory issues (10,000 cell limit)
- Use grid coordinates for computation, world coordinates for display

### Visualization
- Paint individual cells with `scatter()` for room visualization
- Use different colors for different rooms/areas
- Show statistics (cell count, area in m²) for user feedback

## Project Implementation Plan

### 🎯 Current Goals

#### 1. ROI Implementation (Room-Based Point Cloud Filtering) ✅ COMPLETED
**Status: ✅ DONE**
- ✅ Flood fill algorithm implemented in `Floodfill/FloodFillROI.m`
- ✅ Interactive testing tools created
- ✅ Visualization and debugging tools ready
- ✅ Integration point identified: `Estimate.m:558`

**Next Steps for ROI:**
- [ ] Integrate flood fill into main `Estimate.m` (replace static ROI)
- [ ] Test performance in real wheelchair system
- [ ] Fine-tune parameters (distance limits, wall thresholds)

#### 2. Bounding Box Obstacle Avoidance (Replace Capsules) 🚧 IN PROGRESS
**Status: 🚧 PLANNING**

**Current Problem:**
- Using capsule-based obstacle representation in `FPM_capsule.m`
- Capsules = two circles connected by line segment
- Poor fit for rectangular obstacles (furniture, doors, walls)
- Overestimates collision risk, suboptimal path planning

**Proposed Solution:**
- Replace capsule geometry with rectangular bounding boxes
- Use existing bounding boxes from `Estimate.m:572` → `generateBoundingBoxes()`
- Create new `FPM_boundingbox.m` function

**Implementation Plan:**

**Phase 2.1: Analysis and Design**
- [ ] Analyze current `FPM_capsule.m` algorithm structure
- [ ] Document capsule collision detection math
- [ ] Design rectangular collision detection approach
- [ ] Plan integration with existing bounding box data structure

**Phase 2.2: Core Algorithm Development**
- [ ] Create `FPM_boundingbox.m` function
- [ ] Implement rectangular collision detection
  - [ ] Point-to-rectangle distance calculation
  - [ ] Angular range calculation for rectangles
  - [ ] Handle rectangle orientation/rotation
- [ ] Port FPM cost function to bounding boxes
- [ ] Add safety margins for wheelchair dimensions

**Phase 2.3: Integration**
- [ ] Modify `Control.m` to call `FPM_boundingbox` instead of `FPM_capsule`
- [ ] Update data flow from `Estimate.m` bounding boxes
- [ ] Ensure backward compatibility during testing

**Phase 2.4: Testing and Validation**
- [ ] Create test scenarios comparing capsule vs bounding box
- [ ] Validate collision detection accuracy
- [ ] Performance comparison (computation time)
- [ ] Path planning quality assessment

**Data Flow:**
```
Estimate.m:572 → generateBoundingBoxes() → result.local.boundingBoxes
                                           ↓
Control.m → FPM_boundingbox(boundingBoxes) → obstacle avoidance commands
```

**Key Technical Challenges:**
1. **Rectangle-to-point distance** - More complex than circle-to-point
2. **Angular range calculation** - Need corner-based approach vs circle tangents
3. **Orientation handling** - Rectangles can be rotated, circles are symmetric
4. **Performance** - Ensure real-time capability

**Files to Create/Modify:**
- [ ] `src/Controller/FPM_boundingbox.m` - New main function
- [ ] `src/Controller/@Control/Control.m` - Update to use bounding boxes
- [ ] `Floodfill/testBoundingBoxFPM.m` - Test script for validation
- [ ] Documentation and comparison analysis

**Success Metrics:**
- [ ] Bounding box FPM produces smoother paths around rectangular obstacles
- [ ] Computation time ≤ capsule-based approach
- [ ] No collisions in test scenarios
- [ ] Better utilization of free space around obstacles

### 🔧 Technical Implementation Notes

**Current System Architecture:**
```
LiDAR → Estimate.m → Object Detection → Capsule Parameters → FPM_capsule → Control Commands
```

**Target Architecture:**
```
LiDAR → Estimate.m → Object Detection → Bounding Boxes → FPM_boundingbox → Control Commands
                                    ↓
                              (ROI filtering via flood fill)
```

**Integration Timeline:**
1. **Week 1**: Complete bounding box FPM implementation
2. **Week 2**: Integration and testing
3. **Week 3**: ROI integration (if bounding boxes successful)
4. **Week 4**: Combined system validation

---
*Last updated: 2025-01-27*
*This file helps Claude provide consistent, error-free assistance for the wheelchair navigation project.*