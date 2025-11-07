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

## Coding Best Practices

### DRY Principle (Don't Repeat Yourself)
**IMPORTANT:** Minimize coding redundant things. If data or functionality already exists somewhere in the code, reuse it instead of passing it as parameters or duplicating logic.

**Examples of good practice:**
- ✅ Use PhaseManager properties instead of passing same data as parameters
- ✅ Store data once, access from multiple places (single source of truth)
- ✅ Use existing getter methods instead of duplicating data retrieval logic
- ✅ Access internal object state rather than passing redundant parameters

**Examples of redundancy to avoid:**
- ❌ Passing `current_waypoint_idx` as parameter when it's already in `obj.current_waypoint_local`
- ❌ Passing `current_position` when it's stored in `obj.estimator_data.position`
- ❌ Creating duplicate functions that do the same thing with different names
- ❌ Passing data through function parameters that already exists in object properties

**Real Example from Project:**
```matlab
% ❌ BAD: Redundant parameters
[control_mode, target_info] = obj.phaseManager.update2(current_position, current_waypoint_idx);

% ✅ GOOD: Uses internal state (DRY principle)
[control_mode, target_info] = obj.phaseManager.getCurrentPhaseInfo();
```

---

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

### Files to Ignore (DO NOT Commit/Push)
The following files and folders should **NOT** be committed or pushed to GitHub:

**Large Data Files:**
- `data/` - Experimental data folders (contains large video/result files)
- `*.avi` - Video files (often > 100MB)
- `*.dae` - Large 3D model files (can be > 100MB)
- `*.asv` - MATLAB autosave temporary files

**Why these are ignored:**
- GitHub has a 100MB file size limit
- Experimental data is local and regeneratable
- Temporary files are not needed in version control

These files are listed in `.gitignore` to prevent accidental commits.

## Project Structure Notes

### Key Files and Directories
- `map2.mat` - Main occupancy grid map
- `src/Estimator/Estimate.m` - Main estimation class with flood fill integration
- `src/Controller/FPM_capsule.m` - Current capsule-based obstacle avoidance
- `Floodfill/` - Flood fill ROI implementation
- `data/` - **[IGNORED]** Experimental data (do not commit)

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

### ⚠️ CURRENT STATUS: NOT WORKING - DO NOT USE
**Status:** The flood fill algorithm in `Floodfill/FloodFillROI.m` has implementation issues and is currently non-functional.

**DO NOT:**
- Use flood fill for automatic room detection
- Integrate flood fill into `Estimate.m`
- Rely on `Floodfill/` directory for any functionality

**Alternative approach:**
- Multi-room navigation will use **manual room graph configuration** instead
- See `MultiRoomNav/` folder for prototype implementation

### Original Implementation Notes (for reference)
- Stack-based implementation preferred over recursive (memory efficient)
- Limit max cells to prevent memory issues (10,000 cell limit)
- Use grid coordinates for computation, world coordinates for display

### Visualization Notes
- Paint individual cells with `scatter()` for room visualization
- Use different colors for different rooms/areas
- Show statistics (cell count, area in m²) for user feedback

## Project Implementation Plan

### 🎯 Current Goals

#### 0. URGENT: Architecture Bug Fix - PhaseManager vs SharedControlMode Redundancy 🔥 CRITICAL
**Status: 🐛 BUG IDENTIFIED**

**Problem Found:**
- PhaseManager and SharedControlMode both track modes/phases causing conflicts
- Bug at `Estimate.m:233`: `setPhase('multi_room_navigation')` → calls `SharedControlMode.setMode()` → sets `is_first_use = false`
- Later when user triggers 'floor_change', `isFirstTimeUse()` returns false → incorrectly triggers path replanning
- **Root cause**: Redundant state tracking between two classes

**TODO (Priority Order):**
- [ ] **Make PhaseManager the single source of truth for all phase/mode state**
  - Remove `control_mode`, `is_first_use` from SharedControlMode
  - Keep only waypoint data in SharedControlMode (waypoint cell array, target_n, etc.)
  - Move all mode/phase queries to PhaseManager
  - Update all `sharedControlMode.getMode()` calls to use `phaseManager.getCurrentPhase()`
  - Update all `sharedControlMode.setMode()` calls to use `phaseManager.setPhase()`

- [ ] **Fix the `is_first_use` logic to work correctly**
  - Move `is_first_use` tracking to PhaseManager
  - Fix the 'floor_change' check at `Estimate.m:451-461` to properly detect first-time vs replan scenarios
  - Ensure multi-room navigation doesn't incorrectly set `is_first_use = false`

**Files to Modify:**
- `src/SharedControlMode.m` - Remove mode tracking, keep only waypoint data
- `src/PhaseManager.m` - Add `is_first_use` property and logic
- `src/Estimator/Estimate.m` - Update all mode queries to use PhaseManager
- `src/Controller/@Control/Control.m` - Update all mode queries to use PhaseManager

**Expected Result:**
- Clean separation: SharedControlMode = data container, PhaseManager = state machine
- No more redundant state tracking
- `is_first_use` logic works correctly for both single-room and multi-room navigation

---

#### 1. Multi-Room Navigation System 🚧 IN PROGRESS
**Status: 🚧 PROTOTYPING**
- Location: `MultiRoomNav/` folder
- Approach: Manual room graph configuration (flood fill not working)
- Goal: Enable navigation between disconnected rooms (A → B → D)

**Implementation:**
- [x] Design document created (`Reference/Multi_Room_Navigation_Design.md`)
- [ ] Create simple 2-room prototype
- [ ] Implement manual room graph builder
- [ ] Test A* path stitching between rooms
- [ ] Integrate Dijkstra high-level planner

**Key Components:**
- `RoomNode.m` - Room representation with manual boundaries
- `DoorConnection.m` - Door/passage between rooms
- `RoomGraph.m` - Graph structure with Dijkstra search
- `TopologicalPlanner.m` - High-level room-to-room planning
- Manual configuration file for room/door positions

#### 2. ROI Implementation (Room-Based Point Cloud Filtering) ❌ BLOCKED
**Status: ❌ NOT WORKING**
- ❌ Flood fill algorithm has issues in `Floodfill/FloodFillROI.m`
- ❌ Do not use for automatic room detection
- ❌ Integration with `Estimate.m` postponed

**Next Steps for ROI:**
- [ ] Debug flood fill algorithm (low priority)
- [ ] OR use manual ROI definition as fallback
- [ ] Test performance in real wheelchair system (when fixed)

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