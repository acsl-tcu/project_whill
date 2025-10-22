# Door Navigation System Implementation Plan

**Date**: 2025-10-06
**Project**: Wheelchair Autonomous Navigation - Multi-Door Entry System
**Status**: Planning Phase

---

## Table of Contents

1. [Overview](#overview)
2. [Current System Analysis](#current-system-analysis)
3. [Part 1: Phase 0 - Position Correction](#part-1-phase-0---position-correction)
4. [Part 2: Multi-Door Checkpoint System](#part-2-multi-door-checkpoint-system)
5. [Implementation File Structure](#implementation-file-structure)
6. [Phase Renumbering Summary](#phase-renumbering-summary)
7. [Implementation Timeline](#implementation-timeline)
8. [Testing Strategy](#testing-strategy)
9. [Success Metrics](#success-metrics)

---

## Overview

This document outlines the implementation plan for two new wheelchair navigation algorithms:

1. **Phase 0 (Position Correction)**: Pre-positioning algorithm that ensures the wheelchair is at the correct distance and orientation before attempting door entry
2. **Multi-Door Checkpoint System**: Navigation system that stops and verifies door state at intermediate doors along the path to the final destination

### Motivation

**Current Issues:**
- Wheelchair may arrive at door with incorrect positioning (too close, too far, wrong angle)
- No support for navigating through multiple doors in sequence
- Path following errors accumulate, leading to unsafe door entry attempts

**Proposed Solutions:**
- Add Position Correction phase before door entry
- Create checkpoint-based navigation for intermediate doors
- Reuse elevator door detection logic for general door passage

---

## Current System Analysis

### Existing Elevator Entry System (`enterElevator.m`)

**Current Phase Structure:**

| Phase | Name | Description | Exit Condition |
|-------|------|-------------|----------------|
| 1 | Turning | Rotate to face elevator center | `heading_error < 0.1 rad` (~6°) |
| 1.5 | Door Verification | LiDAR-based door open detection | `door_state == 'open'` |
| 2 | Enter Elevator | Move forward into elevator | `distance_moved >= 2.5m` |
| 3 | Inside Waiting | Door close → reopen → detect open | LiDAR confirms door open |
| 4 | Reversing | Back out of elevator | `distance < 0.3m` from start |
| 5 | Completed | Reset all persistent variables | `completed = true` |

**Door Detection Algorithm** (`detectElevatorDoorState.m`):

1. Filter point cloud by door height (0.3m - 2.2m)
2. Extract points within ±30° cone towards door
3. Find center point (most aligned with door direction)
4. Define narrow ROI: ±12° around center (wheelchair safe passage width ~1.3m)
5. Check if ALL narrow ROI points are "deep" (beyond door surface + 0.3m threshold)
6. **Result**:
   - `'open'`: 100% coverage (all ROI points extend beyond door)
   - `'closed'`: Incomplete coverage (obstacle in path)
   - `'unknown'`: Insufficient data

**Coordinate System Modes:**
- **Map mode**: Uses global coordinates + known door center position
- **Odometry mode**: Uses local LiDAR coordinates + wheelchair forward direction (fixed 2.5m distance)

### Integration Points

**Main Navigation Loop:**
- `main_astar.m`: Main control script with A* path planning
- `PathSetting_AStar.m`: Generates waypoints using A* pathfinding
- `Control.m`: Executes path following and obstacle avoidance
- `enterElevator.m`: Elevator-specific entry logic (called from main loop)

---

## Part 1: Phase 0 - Position Correction

### Purpose

Ensure wheelchair is at the **optimal distance and orientation** relative to the door before attempting entry. This corrects positioning errors accumulated during path following.

### Why This is Needed

- **Path following drift**: A* path following may have ±20-30cm position error
- **LiDAR range optimization**: Door detection works best at 2.5m distance
- **Safety margin**: Ensures wheelchair doesn't start entry too close to door (collision risk) or too far (door detection failure)
- **Predictable behavior**: Consistent starting position for door entry phases

### Algorithm Flow

```
┌─────────────────────────────────────────────────────────────┐
│ Phase 0: Position Correction (NEW)                          │
├─────────────────────────────────────────────────────────────┤
│ 1. Calculate target position (2.5m in front of door)        │
│ 2. Measure position error vector                            │
│ 3. Calculate required heading (towards door center)         │
│ 4. Decision logic:                                           │
│    ┌─ Position error > 15cm?                                │
│    │   ┌─ YES ─→ Heading error > 5°?                        │
│    │   │         ├─ YES ─→ Turn towards target position     │
│    │   │         └─ NO  ─→ Move forward/backward to target  │
│    │   └─ NO  ─→ Position verified → Proceed to Phase 1     │
└─────────────────────────────────────────────────────────────┘
         ↓
┌─────────────────────────────────────────────────────────────┐
│ Phase 1: Turning (existing, unchanged)                      │
└─────────────────────────────────────────────────────────────┘
         ↓
┌─────────────────────────────────────────────────────────────┐
│ Phase 1.5: Door Verification (existing, unchanged)          │
└─────────────────────────────────────────────────────────────┘
         ↓
       ... (rest of phases)
```

### Key Parameters

```matlab
% Position Correction Parameters (Phase 0)
TARGET_DISTANCE = 2.5;              % meters from door center (optimal LiDAR range)
POSITION_TOLERANCE = 0.15;          % ±15cm acceptable distance error
POSITION_ANGLE_TOLERANCE = 0.087;   % ±5 degrees acceptable heading error
CORRECTION_TURN_SPEED = 0.1;        % rad/s for correction turns
CORRECTION_MOVE_SPEED = 0.15;       % m/s for correction movement (slower than entry)
MAX_CORRECTION_ITERATIONS = 50;     % Prevent infinite loops (10 seconds @ 5Hz)
```

### Input/Output Interface

**Inputs:**
- `current_position`: [x, y] wheelchair position (meters, global coordinates)
- `current_yaw`: heading angle (radians)
- `door_center`: [x, y] door center position (meters)
- `door_target_position`: [x, y] desired position in front of door (optional, calculated if empty)

**Outputs:**
```matlab
result.phase = 0;                      % Position correction active
result.status = 'Correcting position'; % or 'Position verified'
result.V = [linear_vel, angular_vel];  % Control commands [m/s, rad/s]
result.position_error = 0.23;          % Distance error (meters)
result.angle_error = 0.05;             % Heading error (radians)
result.target_position = [24.5, 12.0]; % Calculated target position
result.completed = false;              % true when Phase 0 done
```

### Detailed Algorithm Logic

```matlab
%% Phase 0: Position Correction
persistent phase0_completed;
persistent correction_iteration_count;

if isempty(phase0_completed)
    phase0_completed = false;
    correction_iteration_count = 0;
end

if ~phase0_completed
    result.phase = 0;
    correction_iteration_count = correction_iteration_count + 1;

    % Safety: Prevent infinite correction loops
    if correction_iteration_count > MAX_CORRECTION_ITERATIONS
        fprintf('WARNING: Position correction timeout - proceeding anyway\n');
        phase0_completed = true;
        return;
    end

    % Calculate target position (2.5m in front of door)
    direction_to_door = door_center - current_position;
    distance_to_door = norm(direction_to_door);
    door_direction_unit = direction_to_door / distance_to_door;
    target_position = door_center - TARGET_DISTANCE * door_direction_unit;

    % Measure position error
    position_error_vector = target_position - current_position;
    position_error_distance = norm(position_error_vector);

    % Calculate required heading (towards door center, not target position)
    required_heading = atan2(direction_to_door(2), direction_to_door(1));
    heading_error = angdiff(required_heading, current_yaw);

    % Store for debugging
    result.position_error = position_error_distance;
    result.angle_error = heading_error;
    result.target_position = target_position;

    fprintf('Phase 0: Position Correction\n');
    fprintf('  Current pos: [%.2f, %.2f], Target pos: [%.2f, %.2f]\n', ...
            current_position(1), current_position(2), target_position(1), target_position(2));
    fprintf('  Position error: %.2fm, Heading error: %.2f° (%.3f rad)\n', ...
            position_error_distance, rad2deg(heading_error), heading_error);

    % Decision tree
    if position_error_distance > POSITION_TOLERANCE
        result.status = 'Correcting position';

        if abs(heading_error) > POSITION_ANGLE_TOLERANCE
            % First: Turn towards target position
            result.V(2) = sign(heading_error) * CORRECTION_TURN_SPEED;
            result.V(1) = 0; % No forward movement while turning
            fprintf('  Action: Turning towards target (%.1f deg remaining)\n', rad2deg(abs(heading_error)));
        else
            % Then: Move towards target position
            % Determine if we need to move forward or backward
            position_direction = target_position - current_position;
            forward_component = dot(position_direction, [cos(current_yaw), sin(current_yaw)]);

            if forward_component > 0
                result.V(1) = CORRECTION_MOVE_SPEED;  % Move forward
                fprintf('  Action: Moving FORWARD (%.2fm to go)\n', position_error_distance);
            else
                result.V(1) = -CORRECTION_MOVE_SPEED; % Move backward
                fprintf('  Action: Moving BACKWARD (%.2fm to go)\n', position_error_distance);
            end
            result.V(2) = 0; % No turning while moving
        end

        result.completed = false;

    else
        % Position verified - proceed to Phase 1
        result.status = 'Position verified';
        result.V = [0; 0]; % Stop
        result.completed = true;
        phase0_completed = true;

        fprintf('Phase 0: COMPLETED - Position verified!\n');
        fprintf('  Final position error: %.3fm, Heading error: %.2f°\n', ...
                position_error_distance, rad2deg(heading_error));
    end

else
    % Phase 0 already completed - proceed to Phase 1
    % (rest of existing elevator entry code)
end
```

### Integration Steps

1. **Modify `enterElevator.m`**:
   - Add Phase 0 logic before existing Phase 1 (around line 116)
   - Add persistent variables: `phase0_completed`, `correction_iteration_count`
   - Renumber existing phases if needed

2. **Update function signature**:
   ```matlab
   function result = enterElevator(current_position, current_yaw, elevator_center,
                                    door_target_position, start_position,
                                    lidar_scan_data, is_gazebo, odometry_mode,
                                    door_detection_mode, door_params)
   ```

3. **Add Phase 0 parameters to `door_params` struct**:
   ```matlab
   door_params.TARGET_DISTANCE = 2.5;
   door_params.POSITION_TOLERANCE = 0.15;
   door_params.POSITION_ANGLE_TOLERANCE = 0.087;
   door_params.CORRECTION_TURN_SPEED = 0.1;
   door_params.CORRECTION_MOVE_SPEED = 0.15;
   door_params.MAX_CORRECTION_ITERATIONS = 50;
   ```

### Testing Phase 0

**Test Case 1: Too Close**
- Start: 2.0m from door → Should move backward to 2.5m
- Expected: Backward movement, then stop when within tolerance

**Test Case 2: Too Far**
- Start: 3.0m from door → Should move forward to 2.5m
- Expected: Forward movement, then stop when within tolerance

**Test Case 3: Wrong Angle**
- Start: 2.5m from door, but facing 15° off → Should turn first, then verify
- Expected: Turn to correct angle, then verify position (may need minor adjustment)

**Test Case 4: Combined Error**
- Start: 2.2m from door, facing 10° off → Should correct both
- Expected: Turn first, then minor forward movement

---

## Part 2: Multi-Door Checkpoint System

### Purpose

Enable wheelchair to navigate through **multiple doors in sequence** before reaching final destination. Each door is a "checkpoint" requiring:
1. Position correction (Phase 0)
2. Turn towards door (Phase 1)
3. Verify door is open (Phase 1.5)
4. Pass through door (Phase 2)
5. Continue to next checkpoint

### System Architecture

```
                    ┌─────────────────────────────────────────┐
                    │   navigateMultipleDoors.m (Manager)     │
                    │  - Manages checkpoint sequence          │
                    │  - Tracks current checkpoint index      │
                    │  - Calls appropriate door entry function│
                    └─────────────────────────────────────────┘
                                      │
                ┌─────────────────────┼─────────────────────┐
                │                     │                     │
                ▼                     ▼                     ▼
    ┌──────────────────┐  ┌──────────────────┐  ┌──────────────────┐
    │  Checkpoint 1    │  │  Checkpoint 2    │  │  Checkpoint N    │
    │  Type: 'door'    │  │  Type: 'door'    │  │  Type: 'elevator'│
    └──────────────────┘  └──────────────────┘  └──────────────────┘
            │                     │                     │
            ▼                     ▼                     ▼
    ┌──────────────────┐  ┌──────────────────┐  ┌──────────────────┐
    │passThroughDoor.m │  │passThroughDoor.m │  │enterElevator.m   │
    │  Phase 0, 1,     │  │  Phase 0, 1,     │  │  Phase 0-5       │
    │  1.5, 2          │  │  1.5, 2          │  │  (full sequence) │
    └──────────────────┘  └──────────────────┘  └──────────────────┘
```

### Checkpoint Data Structure

```matlab
% Example: 3 checkpoints (2 doors + elevator)
door_checkpoints = struct('door_center', {}, 'target_position', {}, ...
                         'pass_distance', {}, 'type', {}, 'name', {});

% Checkpoint 1: Hallway door
door_checkpoints(1).door_center = [10.0, 6.2];        % Door center position [x, y]
door_checkpoints(1).target_position = [7.5, 6.2];     % Stop position (2.5m before door)
door_checkpoints(1).pass_distance = 3.0;              % Distance to travel through door (meters)
door_checkpoints(1).type = 'door';                     % Type: 'door' or 'elevator'
door_checkpoints(1).name = 'Hallway Door';            % Human-readable name

% Checkpoint 2: Room entrance
door_checkpoints(2).door_center = [20.0, 6.2];
door_checkpoints(2).target_position = [17.5, 6.2];
door_checkpoints(2).pass_distance = 3.0;
door_checkpoints(2).type = 'door';
door_checkpoints(2).name = 'Room Entrance';

% Checkpoint 3: Elevator (final destination)
door_checkpoints(3).door_center = [27.0, 12.0];
door_checkpoints(3).target_position = [24.5, 12.0];
door_checkpoints(3).pass_distance = 2.5;
door_checkpoints(3).type = 'elevator';
door_checkpoints(3).name = 'Elevator';
```

### New Function: `passThroughDoor.m`

**Purpose**: Simplified door passage (no elevator-specific phases 3-5)

**Key Differences from `enterElevator.m`:**
- ✅ **Has Phase 0**: Position correction (identical to elevator)
- ✅ **Has Phase 1**: Turn towards door (identical to elevator)
- ✅ **Has Phase 1.5**: Verify door open (identical to elevator)
- ✅ **Has Phase 2**: Pass through door (modified - different distance)
- ❌ **No Phase 3**: No "door close" simulation
- ❌ **No Phase 4**: No reversing out
- ❌ **No Phase 5**: Completion immediately continues to next checkpoint

**Function Signature:**

```matlab
function result = passThroughDoor(current_position, current_yaw, door_center,
                                  door_target_position, pass_through_distance,
                                  start_position, lidar_scan_data,
                                  odometry_mode, door_params)
% Pass through a single door checkpoint (Phases 0, 1, 1.5, 2 only)
%
% Inputs:
%   current_position - [x, y] current wheelchair position (meters)
%   current_yaw - current heading angle (radians)
%   door_center - [x, y] door center position (meters)
%   door_target_position - [x, y] position to stop before door (for Phase 0)
%   pass_through_distance - distance to travel through door in Phase 2 (meters)
%   start_position - [x, y] position where Phase 2 started (persistent tracking)
%   lidar_scan_data - struct with xyz_global and xyz_local point cloud data
%   odometry_mode - boolean: true = local coordinates, false = global coordinates
%   door_params - struct with detection parameters (see enterElevator.m)
%
% Outputs:
%   result.phase - 0, 1, 1.5, or 2
%   result.status - Human-readable status string
%   result.V - [linear_vel; angular_vel] control commands
%   result.completed - true when door passage complete
%   result.door_state - 'open', 'closed', or 'unknown' (Phase 1.5 only)
```

**Algorithm Flow:**

```matlab
% Persistent variables
persistent phase2_start_pos;
persistent door_verified;

% Phase 0: Position Correction
if ~position_corrected
    % (Use same logic as enterElevator Phase 0)
    % Exit: position within 15cm, angle within 5°
end

% Phase 1: Turning
if abs(heading_error) > TURN_TOLERANCE
    % (Same as enterElevator Phase 1)
    % Turn towards door center
end

% Phase 1.5: Door Verification
if ~door_verified
    % (Same as enterElevator Phase 1.5)
    door_state = detectElevatorDoorState(pointCloud, ...);
    if door_state == 'open'
        door_verified = true;
    else
        % Wait for door to open
    end
end

% Phase 2: Pass Through Door
if door_verified
    distance_moved = norm(current_position - phase2_start_pos);
    remaining_distance = pass_through_distance - distance_moved;

    if remaining_distance > 0.1  % 10cm tolerance
        % Move forward
        result.V = [MOVE_SPEED; 0];
        result.phase = 2;
        result.status = 'Passing through door';
    else
        % Door passage completed
        result.V = [0; 0];
        result.phase = 2;
        result.status = 'Door passage completed';
        result.completed = true;  % Signal to advance to next checkpoint

        % Reset persistent variables for next door
        phase2_start_pos = [];
        door_verified = false;
    end
end
```

### New Function: `navigateMultipleDoors.m`

**Purpose**: Manage sequence of door checkpoints

**Function Signature:**

```matlab
function result = navigateMultipleDoors(current_position, current_yaw,
                                        door_checkpoints, lidar_scan_data,
                                        odometry_mode, door_params, is_gazebo)
% Manage navigation through multiple door checkpoints
%
% Inputs:
%   current_position - [x, y] wheelchair position (meters)
%   current_yaw - heading angle (radians)
%   door_checkpoints - struct array with checkpoint information (see structure above)
%   lidar_scan_data - point cloud data from Estimate.m
%   odometry_mode - boolean for coordinate system mode
%   door_params - door detection parameters
%   is_gazebo - boolean flag for Gazebo simulation
%
% Outputs:
%   result.checkpoint_idx - current checkpoint index
%   result.checkpoint_name - current checkpoint name
%   result.V - control commands from active checkpoint function
%   result.status - status from active checkpoint function
%   result.all_completed - true when all checkpoints completed
```

**Algorithm:**

```matlab
% Persistent state
persistent current_checkpoint_idx;
persistent checkpoint_start_position;

% Initialize on first call
if isempty(current_checkpoint_idx)
    current_checkpoint_idx = 1;
    fprintf('=== MULTI-DOOR NAVIGATION STARTED ===\n');
    fprintf('Total checkpoints: %d\n', length(door_checkpoints));
end

% Check if all checkpoints completed
if current_checkpoint_idx > length(door_checkpoints)
    fprintf('=== ALL CHECKPOINTS COMPLETED ===\n');
    result.all_completed = true;
    result.V = [0; 0];
    result.status = 'Navigation completed';
    result.checkpoint_idx = current_checkpoint_idx;

    % Reset for next navigation
    current_checkpoint_idx = [];
    checkpoint_start_position = [];
    return;
end

% Get current checkpoint
checkpoint = door_checkpoints(current_checkpoint_idx);

fprintf('\n=== CHECKPOINT %d/%d: %s ===\n', ...
        current_checkpoint_idx, length(door_checkpoints), checkpoint.name);

% Initialize start position for this checkpoint
if isempty(checkpoint_start_position)
    checkpoint_start_position = current_position;
end

% Call appropriate function based on checkpoint type
if strcmp(checkpoint.type, 'door')
    % Regular door - use passThroughDoor.m
    checkpoint_result = passThroughDoor(current_position, current_yaw, ...
                                       checkpoint.door_center, ...
                                       checkpoint.target_position, ...
                                       checkpoint.pass_distance, ...
                                       checkpoint_start_position, ...
                                       lidar_scan_data, ...
                                       odometry_mode, door_params);

    % Check if checkpoint completed
    if checkpoint_result.completed
        fprintf('Checkpoint %d (%s) COMPLETED!\n', current_checkpoint_idx, checkpoint.name);
        current_checkpoint_idx = current_checkpoint_idx + 1;
        checkpoint_start_position = []; % Reset for next checkpoint
    end

elseif strcmp(checkpoint.type, 'elevator')
    % Elevator - use full enterElevator.m with all phases
    checkpoint_result = enterElevator(current_position, current_yaw, ...
                                     checkpoint.door_center, ...
                                     checkpoint.target_position, ...
                                     checkpoint_start_position, ...
                                     lidar_scan_data, ...
                                     is_gazebo, odometry_mode, ...
                                     false, door_params); % door_detection_mode = false

    % Check if elevator sequence completed (Phase 5)
    if checkpoint_result.completed
        fprintf('Checkpoint %d (%s) COMPLETED!\n', current_checkpoint_idx, checkpoint.name);
        current_checkpoint_idx = current_checkpoint_idx + 1;
        checkpoint_start_position = [];
    end

else
    % Unknown checkpoint type
    fprintf('ERROR: Unknown checkpoint type "%s"\n', checkpoint.type);
    current_checkpoint_idx = current_checkpoint_idx + 1; % Skip invalid checkpoint
end

% Return result from checkpoint function
result = checkpoint_result;
result.checkpoint_idx = current_checkpoint_idx;
result.checkpoint_name = checkpoint.name;
result.all_completed = false;
```

### Integration with Path Planning

**Option A: Manual Checkpoint Definition**

In main script or configuration file:

```matlab
% Define checkpoints manually
door_checkpoints(1).door_center = [10.0, 6.2];
door_checkpoints(1).target_position = [7.5, 6.2];
door_checkpoints(1).pass_distance = 3.0;
door_checkpoints(1).type = 'door';
door_checkpoints(1).name = 'Hallway Door';

% ... (define all checkpoints)

% Enable checkpoint navigation mode
checkpoint_mode = true;
```

**Option B: Automatic Detection from A* Path**

Create new function `detectDoorsAlongPath.m`:

```matlab
function door_checkpoints = detectDoorsAlongPath(waypoints, map_obj, door_params)
% Automatically detect doors along A* path using occupancy map analysis
%
% Method:
% 1. For each waypoint segment, check for narrow passages (doors)
% 2. Identify door center using occupancy gradient
% 3. Generate checkpoint structure
%
% Inputs:
%   waypoints - Nx2 array of path waypoints from A*
%   map_obj - occupancyMap object
%   door_params - detection parameters
%
% Outputs:
%   door_checkpoints - struct array of detected checkpoints
```

**Detection Algorithm:**

```matlab
% For each segment between waypoints
for i = 1:(size(waypoints, 1) - 1)
    segment_start = waypoints(i, :);
    segment_end = waypoints(i+1, :);

    % Sample points along segment
    num_samples = 20;
    t = linspace(0, 1, num_samples);
    sample_points = segment_start + t' * (segment_end - segment_start);

    % Check for narrow passage (door candidate)
    for j = 1:num_samples
        point = sample_points(j, :);

        % Get perpendicular width at this point
        width = measurePerpendicularClearance(point, map_obj, direction);

        % Door detection criteria:
        % - Width narrows significantly (< 2.0m)
        % - Surrounded by occupied cells (walls)
        % - Aligned with path direction
        if width < 2.0 && hasWallsOnBothSides(point, map_obj)
            % Found door candidate
            door_center = point;

            % Create checkpoint
            checkpoint.door_center = door_center;
            checkpoint.target_position = door_center - 2.5 * direction_unit;
            checkpoint.pass_distance = 3.0;
            checkpoint.type = 'door';
            checkpoint.name = sprintf('Door_%d', checkpoint_count);

            door_checkpoints = [door_checkpoints, checkpoint];
        end
    end
end
```

**Modify `PathSetting_AStar.m`:**

```matlab
% After A* path generation (around line 200)
waypoints = path_result;

% Optional: Automatic door detection
if auto_detect_doors
    fprintf('Detecting doors along path...\n');
    door_checkpoints = detectDoorsAlongPath(waypoints, map_obj, door_params);
    fprintf('Detected %d doors\n', length(door_checkpoints));
else
    door_checkpoints = []; % Use manual checkpoints instead
end

% Return checkpoints along with waypoints
```

### Integration with Main Control Loop

**Modify `Control.m` or main navigation script:**

```matlab
% Add checkpoint mode flag (set in configuration or GUI)
persistent checkpoint_mode;
persistent door_checkpoints;

if isempty(checkpoint_mode)
    checkpoint_mode = false; % Default: normal path following
end

% Main control loop
if checkpoint_mode && ~isempty(door_checkpoints)
    % Checkpoint navigation mode
    result = navigateMultipleDoors(current_position, current_yaw, ...
                                   door_checkpoints, ...
                                   lidar_scan_data, ...
                                   odometry_mode, door_params, is_gazebo);

    % Apply control commands
    V_out = result.V;

    % Check completion
    if result.all_completed
        fprintf('Multi-door navigation completed!\n');
        checkpoint_mode = false; % Exit checkpoint mode
        % Resume normal path following or stop
    end

else
    % Normal A* path following mode
    result = followPathAStar(waypoints, current_position, ...);
    V_out = result.V;
end

% Send control commands to wheelchair
sendVelocityCommand(V_out);
```

---

## Implementation File Structure

### New Files to Create

#### 1. `positionCorrectionPhase.m`
**Location**: `src/Controller/positionCorrectionPhase.m`

**Purpose**: Standalone Phase 0 logic (reusable by both elevator and door functions)

**Key Features:**
- Calculate target position from door center
- Measure position and heading errors
- Generate correction commands (turn or move)
- Return completion status

**Reusability**: Can be called by:
- `enterElevator.m` (Phase 0)
- `passThroughDoor.m` (Phase 0)
- Any future door-entry functions

#### 2. `passThroughDoor.m`
**Location**: `src/Controller/passThroughDoor.m`

**Purpose**: Simplified door passage (Phases 0, 1, 1.5, 2 only)

**Based on**: `enterElevator.m` (copy and modify)

**Modifications:**
- Remove Phase 3 (inside waiting)
- Remove Phase 4 (reversing)
- Remove Phase 5 (completion with reset)
- Simplify Phase 2 (just pass through, no elevator simulation)
- Add `pass_through_distance` parameter

#### 3. `navigateMultipleDoors.m`
**Location**: `src/Controller/navigateMultipleDoors.m`

**Purpose**: Checkpoint sequence manager

**Key Features:**
- Manage checkpoint index (persistent)
- Call `passThroughDoor.m` or `enterElevator.m` based on type
- Detect checkpoint completion
- Advance to next checkpoint
- Report overall progress

#### 4. `detectDoorsAlongPath.m`
**Location**: `src/PathPlanning/detectDoorsAlongPath.m`

**Purpose**: Automatic door detection from A* path

**Algorithm:**
- Analyze waypoint segments
- Detect narrow passages (width < 2.0m)
- Verify wall presence on both sides
- Generate checkpoint structure array

**Integration**: Called from `PathSetting_AStar.m` after path generation

### Files to Modify

#### 1. `enterElevator.m`
**Location**: `src/Controller/enterElevator.m`

**Modifications:**
- **Line ~60**: Add Phase 0 persistent variables
  ```matlab
  persistent phase0_completed;
  persistent correction_iteration_count;
  ```

- **Line ~80**: Add Phase 0 parameters to defaults
  ```matlab
  door_params.TARGET_DISTANCE = 2.5;
  door_params.POSITION_TOLERANCE = 0.15;
  door_params.POSITION_ANGLE_TOLERANCE = 0.087;
  % ... (other Phase 0 parameters)
  ```

- **Line ~116**: Insert Phase 0 logic before existing Phase 1
  ```matlab
  % Phase 0: Position Correction (NEW)
  if ~phase0_completed
      % (Position correction logic here)
      % Call positionCorrectionPhase.m or implement inline
  end

  % Phase 1: Turning (existing code, now only runs after Phase 0)
  if phase0_completed && abs(heading_error) > TURN_TOLERANCE
      % (existing Phase 1 code)
  end
  ```

- **Line ~400**: Reset Phase 0 variables on completion
  ```matlab
  phase0_completed = [];
  correction_iteration_count = [];
  ```

**Phase Renumbering**: Not strictly required - Phase 0 is implicitly before Phase 1

#### 2. `Control.m` or Main Navigation Loop
**Location**: `src/Controller/@Control/Control.m` or main script

**Modifications:**
- Add checkpoint mode flag
- Add checkpoint navigation branch in main loop
- Call `navigateMultipleDoors.m` when checkpoint mode active
- Handle checkpoint completion (resume path following or stop)

**Example Integration:**

```matlab
% In Control.m main loop (around line ~200)

% Check if checkpoint mode is active
if obj.CheckpointMode && ~isempty(obj.DoorCheckpoints)
    % Multi-door checkpoint navigation
    result = navigateMultipleDoors(current_position, current_yaw, ...
                                   obj.DoorCheckpoints, ...
                                   lidar_data, ...
                                   obj.OdometryMode, ...
                                   obj.DoorParams, ...
                                   obj.IsGazebo);

    % Apply control commands
    V_out = result.V;

    % Display checkpoint progress
    fprintf('Checkpoint %d/%d: %s (Phase %g)\n', ...
            result.checkpoint_idx, length(obj.DoorCheckpoints), ...
            result.checkpoint_name, result.phase);

    % Check if all checkpoints completed
    if result.all_completed
        obj.CheckpointMode = false; % Exit checkpoint mode
        fprintf('All checkpoints completed - resuming normal navigation\n');
    end

else
    % Normal path following
    % (existing control logic)
end
```

#### 3. `PathSetting_AStar.m` (Optional)
**Location**: `PathSetting_AStar.m`

**Modifications:**
- **Line ~200**: Add automatic door detection (optional feature)
  ```matlab
  % After A* path generation
  waypoints = path_result;

  % Optional: Detect doors along path
  if nargin >= 6 && auto_detect_doors
      door_checkpoints = detectDoorsAlongPath(waypoints, map_obj, door_params);
      fprintf('Auto-detected %d doors along path\n', length(door_checkpoints));
  else
      door_checkpoints = []; % No automatic detection
  end
  ```

- **Update function signature** to return checkpoints:
  ```matlab
  function [waypoints, selectZone, NoEntryZone, ZoneNum, V_ref, door_checkpoints] = ...
           PathSetting_AStar(start_position, goal_position, robot_width, ...
                            robot_length, safety_margin, auto_detect_doors)
  ```

### File Organization Summary

```
wheelchair_experiment/
├── src/
│   ├── Controller/
│   │   ├── positionCorrectionPhase.m        [NEW - Phase 0 logic]
│   │   ├── passThroughDoor.m                 [NEW - Simplified door entry]
│   │   ├── navigateMultipleDoors.m           [NEW - Checkpoint manager]
│   │   ├── enterElevator.m                   [MODIFY - Add Phase 0]
│   │   └── @Control/
│   │       └── Control.m                     [MODIFY - Add checkpoint mode]
│   │
│   └── PathPlanning/                         [NEW - Create directory]
│       └── detectDoorsAlongPath.m            [NEW - Auto door detection]
│
├── PathSetting_AStar.m                       [MODIFY - Optional, add door detection]
│
└── Reference/
    └── Door_Navigation_System_Plan.md        [THIS DOCUMENT]
```

---

## Phase Renumbering Summary

### Elevator Entry (`enterElevator.m`)

| **Old Phase** | **New Phase** | **Name** | **Description** | **Changes** |
|--------------|--------------|----------|-----------------|-------------|
| -            | **0**        | **Position Correction** | **Verify distance/angle to door** | **NEW** |
| 1            | 1            | Turning | Turn towards elevator | *Unchanged* |
| 1.5          | 1.5          | Door Verification | LiDAR door open check | *Unchanged* |
| 2            | 2            | Enter Elevator | Move forward into elevator | *Unchanged* |
| 3            | 3            | Inside Waiting | Door close, reopen, detect | *Unchanged* |
| 4            | 4            | Reversing | Back out of elevator | *Unchanged* |
| 5            | 5            | Completed | Reset and finish | *Unchanged* |

**Note**: Phase numbers don't change - Phase 0 is inserted before Phase 1.

### Door Passage (`passThroughDoor.m` - NEW)

| **Phase** | **Name** | **Description** | **Exit Condition** |
|----------|----------|-----------------|-------------------|
| **0**    | **Position Correction** | Verify distance/angle to door | `position_error < 15cm` AND `angle_error < 5°` |
| **1**    | **Turning** | Turn towards door | `heading_error < 6°` |
| **1.5**  | **Door Verification** | LiDAR door open check | `door_state == 'open'` |
| **2**    | **Pass Through** | Move forward through door | `distance_moved >= pass_through_distance` |
| -        | *(no phases 3-5)* | N/A | `completed = true` → next checkpoint |

**Comparison with Elevator:**
- ✅ Same: Phases 0, 1, 1.5 (identical logic)
- ⚠️ Modified: Phase 2 (different distance parameter)
- ❌ Removed: Phases 3, 4, 5 (elevator-specific)

---

## Implementation Timeline

### **Week 1: Phase 0 for Elevator**
**Goal**: Add position correction to existing elevator entry

**Tasks:**
- [ ] Create `positionCorrectionPhase.m` (standalone function)
- [ ] Integrate Phase 0 into `enterElevator.m`
- [ ] Add Phase 0 parameters to `door_params` struct
- [ ] Test with Gazebo elevator scenario

**Deliverables:**
- Working Phase 0 in elevator entry
- Test results showing position accuracy (error < 15cm)

**Success Criteria:**
- Wheelchair positions itself at 2.5m ± 15cm before elevator entry
- Heading aligned within ±5° before Phase 1
- No infinite loops or timeout errors

### **Week 2: Door Passage Function**
**Goal**: Create simplified door entry function

**Tasks:**
- [ ] Copy `enterElevator.m` → `passThroughDoor.m`
- [ ] Remove Phase 3, 4, 5 logic
- [ ] Modify Phase 2 to use `pass_through_distance` parameter
- [ ] Integrate Phase 0 from `positionCorrectionPhase.m`
- [ ] Test standalone door passage (manual checkpoint)

**Deliverables:**
- Working `passThroughDoor.m` function
- Test results with single door checkpoint

**Success Criteria:**
- Successfully pass through test door (phases 0 → 1 → 1.5 → 2)
- `completed = true` at end of Phase 2
- Persistent variables reset properly for reuse

### **Week 3: Multi-Door Checkpoint Manager**
**Goal**: Enable sequence navigation through multiple doors

**Tasks:**
- [ ] Create `navigateMultipleDoors.m`
- [ ] Implement checkpoint sequencing logic
- [ ] Add checkpoint structure definition
- [ ] Test with 2-door scenario (manual checkpoints)
- [ ] Add progress reporting (current checkpoint, phase, etc.)

**Deliverables:**
- Working checkpoint manager
- Test results with 2-3 door sequence

**Success Criteria:**
- Successfully navigate through all checkpoints in order
- Proper checkpoint advancement on completion
- Final `all_completed = true` signal

### **Week 4: Automatic Door Detection**
**Goal**: Generate checkpoints automatically from A* path

**Tasks:**
- [ ] Create `detectDoorsAlongPath.m`
- [ ] Implement narrow passage detection algorithm
- [ ] Test with known door locations in map
- [ ] Integrate with `PathSetting_AStar.m`
- [ ] Validate auto-generated checkpoints

**Deliverables:**
- Working automatic door detection
- Comparison: manual vs. auto-detected checkpoints

**Success Criteria:**
- Detect all known doors in test path (100% recall)
- No false positives (narrow corners, etc.)
- Generated checkpoints match manual definition

### **Week 5: Integration & Testing**
**Goal**: Complete system integration and validation

**Tasks:**
- [ ] Modify `Control.m` to support checkpoint mode
- [ ] Add mode switching (checkpoint vs. normal navigation)
- [ ] End-to-end testing (start → multiple doors → elevator)
- [ ] Performance benchmarking
- [ ] Documentation and code cleanup

**Deliverables:**
- Fully integrated multi-door navigation system
- Performance report
- User documentation

**Success Criteria:**
- Complete navigation from start to elevator through all doors
- No collisions or failures
- Performance within acceptable limits (see Success Metrics)

---

## Testing Strategy

### Test Scenarios

#### **Test 1: Elevator Phase 0 Only**
**Purpose**: Validate position correction in isolation

**Setup:**
- Start wheelchair at various positions near elevator:
  - Too close: 2.0m from door
  - Too far: 3.0m from door
  - Wrong angle: 2.5m but facing 15° off
  - Combined error: 2.2m and 10° off

**Expected Results:**
- Wheelchair corrects position to 2.5m ± 15cm
- Heading aligned within ±5°
- Phase 0 → Phase 1 transition smooth

**Pass Criteria:**
- 4/4 scenarios achieve target position within tolerance
- No timeout errors
- Completion time < 10 seconds per scenario

#### **Test 2: Single Door Passage**
**Purpose**: Validate `passThroughDoor.m` standalone

**Setup:**
- Manual checkpoint at hallway door [10, 6.2]
- Door initially closed, then opened manually
- Monitor all phase transitions

**Expected Results:**
- Phase 0: Position correction to 2.5m in front of door
- Phase 1: Turn to face door
- Phase 1.5: Wait for door open, then detect
- Phase 2: Pass through door (3.0m travel)
- Completion: `completed = true`, ready for next checkpoint

**Pass Criteria:**
- All phases execute in correct order
- Door detection correctly identifies open/closed state
- No phases 3-5 execute (no reversing)

#### **Test 3: Two-Door Sequence**
**Purpose**: Validate checkpoint sequencing

**Setup:**
- Checkpoint 1: Door A at [10, 6.2]
- Checkpoint 2: Elevator at [27, 12]
- Both doors initially open

**Expected Results:**
- Navigate to Checkpoint 1 → pass through
- Automatically advance to Checkpoint 2
- Complete elevator sequence (all phases 0-5)
- Final `all_completed = true`

**Pass Criteria:**
- Checkpoint advancement automatic (no manual intervention)
- Both checkpoints completed successfully
- Total completion time reasonable

#### **Test 4: Door Closed → Wait → Open**
**Purpose**: Validate door state handling

**Setup:**
- Single door checkpoint
- Door initially closed
- Open door manually during Phase 1.5

**Expected Results:**
- Phase 1.5 detects door closed → wheelchair stops
- Wheelchair waits (no timeout)
- Door opens → detection switches to 'open'
- Phase 2 begins automatically

**Pass Criteria:**
- Wheelchair doesn't attempt to pass through closed door
- Detection correctly identifies door state change
- No collisions

#### **Test 5: Automatic Door Detection**
**Purpose**: Validate `detectDoorsAlongPath.m`

**Setup:**
- A* path from [4, -0.2] to [30, 12.5]
- Known doors at [10, 6.2] and [27, 12] (elevator)

**Expected Results:**
- Auto-detection finds both doors
- Generated checkpoints match manual definition
- No false positives (corners, narrow corridors, etc.)

**Pass Criteria:**
- 2/2 doors detected (100% recall)
- Checkpoint positions accurate (within 0.5m)
- No false detections

#### **Test 6: End-to-End Navigation**
**Purpose**: Complete system validation

**Setup:**
- Start position: [4, -0.2]
- Goal: Elevator [27, 12]
- Intermediate doors: 2-3 doors along path
- All doors initially open

**Expected Results:**
- A* path generated
- Doors auto-detected (or manual checkpoints)
- Navigate through all checkpoints in sequence
- Arrive at elevator, complete full entry sequence
- Final position inside elevator

**Pass Criteria:**
- No collisions at any checkpoint
- All doors successfully passed
- Elevator entry successful
- Total time < 5 minutes

### Performance Benchmarks

| Metric | Target | Measurement Method |
|--------|--------|-------------------|
| **Phase 0 Accuracy** | Position error < 15cm, Angle < 5° | Measure final error before Phase 1 |
| **Door Detection Rate** | 100% (no missed doors) | Compare auto vs. manual detection |
| **False Positive Rate** | 0% (no fake doors) | Visual validation of checkpoints |
| **Phase Completion Time** | Phase 0: <10s, Phase 1: <5s, Phase 1.5: <2s, Phase 2: <15s | Timestamp each phase transition |
| **Total Navigation Time** | ≤ 10% slower than direct path | Compare checkpoint vs. normal mode |
| **Collision Rate** | 0% | Monitor LiDAR/collision sensors |

### Test Data Collection

**For Each Test Run:**
- [ ] Record start position and goal position
- [ ] Log all phase transitions with timestamps
- [ ] Save position errors at each checkpoint (Phase 0)
- [ ] Record door detection states (Phase 1.5)
- [ ] Log any errors, warnings, or timeouts
- [ ] Save final position and completion status

**Data Format:**
```matlab
test_log.test_id = 'Test_3_TwoDoorSequence_Run1';
test_log.timestamp = '2025-10-15 14:30:00';
test_log.start_position = [4.0, -0.2];
test_log.checkpoints = door_checkpoints;
test_log.phase_transitions = [...]; % [time, checkpoint_idx, phase, status]
test_log.position_errors = [...];   % Phase 0 errors at each checkpoint
test_log.door_states = [...];       % Phase 1.5 detection results
test_log.completion_time = 142.5;   % seconds
test_log.success = true;
```

---

## Success Metrics

### Functional Requirements

| Requirement | Metric | Target |
|-------------|--------|--------|
| **Position Accuracy** | Distance error at Phase 0 completion | < 15cm |
| **Heading Accuracy** | Angle error at Phase 0 completion | < 5° (0.087 rad) |
| **Door Detection** | Detection accuracy (Phase 1.5) | 100% (open vs. closed) |
| **Checkpoint Completion** | Success rate per checkpoint | 100% |
| **Sequence Completion** | Success rate for full multi-door navigation | ≥ 95% |
| **Collision Avoidance** | Collision events | 0 |

### Performance Requirements

| Requirement | Metric | Target | Rationale |
|-------------|--------|--------|-----------|
| **Phase 0 Speed** | Position correction time | < 10 seconds | User patience, efficiency |
| **Phase 1.5 Response** | Door detection latency | < 2 seconds | Real-time responsiveness |
| **Overall Speed** | Total navigation time vs. direct path | ≤ 110% | Acceptable safety tradeoff |
| **CPU Usage** | Processing time per control loop | < 100ms | Real-time control requirement |
| **Memory Usage** | Checkpoint data structure size | < 1MB | Embedded system compatibility |

### Robustness Requirements

| Scenario | Expected Behavior | Pass Criteria |
|----------|-------------------|---------------|
| **Closed Door** | Wait in Phase 1.5, proceed when open | No collision, automatic continuation |
| **Partial Door** | Detect as 'closed' (incomplete ROI coverage) | Reject entry, wait for full open |
| **Door Detection Failure** | Timeout or 'unknown' state | Safe fallback (stop or skip checkpoint) |
| **Position Correction Timeout** | Max 50 iterations reached | Proceed with warning, log error |
| **Multiple Doors in Sequence** | Complete all checkpoints in order | No skipped checkpoints, correct order |
| **Checkpoint Data Error** | Invalid checkpoint structure | Graceful error handling, skip or abort |

### Safety Requirements

| Requirement | Metric | Target |
|-------------|--------|--------|
| **Collision Prevention** | Distance to obstacles during door passage | > 20cm (safety margin) |
| **Emergency Stop** | Response time to manual stop command | < 0.5 seconds |
| **Door Jamming Protection** | Detect if door closes during passage (Phase 2) | Stop within 0.5m, no damage |
| **Timeout Protection** | Maximum wait time for closed door | 60 seconds (configurable) |

---

## Risk Analysis & Mitigation

### Risk 1: Position Correction Oscillation
**Description**: Phase 0 correction causes back-and-forth oscillation, never converging

**Likelihood**: Medium
**Impact**: High (blocks navigation)

**Mitigation:**
- Add iteration counter (max 50 iterations)
- Implement damping factor (reduce speed as error decreases)
- Add convergence detection (error decreasing for N iterations)
- Timeout fallback (proceed with warning if timeout)

### Risk 2: Door Detection False Negatives
**Description**: Phase 1.5 detects door as 'closed' when actually open

**Likelihood**: Low
**Impact**: High (unnecessary waiting, user frustration)

**Mitigation:**
- Tune detection parameters (narrow ROI angle, depth threshold)
- Add multi-sample averaging (check 3-5 times before deciding)
- Provide manual override option
- Log detection details for debugging

### Risk 3: Checkpoint Sequence Errors
**Description**: System skips checkpoint or gets stuck on one checkpoint

**Likelihood**: Low
**Impact**: High (navigation failure)

**Mitigation:**
- Robust checkpoint completion detection
- Add checkpoint timeout (max time per checkpoint)
- Implement checkpoint skip command (manual override)
- Extensive testing with various checkpoint sequences

### Risk 4: Automatic Detection False Positives
**Description**: `detectDoorsAlongPath.m` detects non-door features as doors

**Likelihood**: Medium
**Impact**: Medium (unnecessary stops, inefficiency)

**Mitigation:**
- Conservative detection thresholds (width, wall presence)
- Manual review of auto-generated checkpoints (GUI visualization)
- Allow manual checkpoint editing
- Fallback to manual checkpoint definition

### Risk 5: Performance Degradation
**Description**: Multi-door navigation too slow, blocks normal operations

**Likelihood**: Low
**Impact**: Medium (user dissatisfaction)

**Mitigation:**
- Optimize Phase 0 convergence (faster correction)
- Parallel processing where possible
- Profile and optimize bottlenecks
- Allow user to disable checkpoint mode if needed

---

## Future Enhancements

### Enhancement 1: Adaptive Door Detection Parameters
- **Current**: Fixed parameters (ROI angle, depth threshold)
- **Proposed**: Adapt parameters based on door distance, type, or environment
- **Benefit**: More robust detection in varied conditions

### Enhancement 2: Door Type Classification
- **Current**: All doors treated identically
- **Proposed**: Classify doors (sliding, hinged, automatic, manual)
- **Benefit**: Optimize entry strategy per door type

### Enhancement 3: Multi-Floor Elevator Support
- **Current**: Single floor (no floor selection)
- **Proposed**: Floor selection, multi-floor navigation
- **Benefit**: Full building navigation capability

### Enhancement 4: Dynamic Re-planning
- **Current**: Fixed checkpoint sequence
- **Proposed**: Re-plan if door blocked or new door detected
- **Benefit**: Adaptive navigation, obstacle avoidance

### Enhancement 5: Learning-Based Position Correction
- **Current**: Fixed PID-style correction
- **Proposed**: Learn optimal correction trajectories from data
- **Benefit**: Faster, smoother corrections

---

## Appendix

### A. Coordinate System Reference

**Global Coordinates (Map Mode):**
- Origin: Map origin (defined in `map2.mat`)
- Units: Meters
- Used by: A* path planning, waypoints, door centers
- Wheelchair position from: Prime sensor or Autoware localization

**Local Coordinates (Odometry Mode):**
- Origin: Wheelchair current position
- X-axis: Forward direction of wheelchair
- Y-axis: Left direction of wheelchair
- Units: Meters
- Used by: LiDAR point cloud (local frame)
- Wheelchair position: [0, 0] (by definition)

**Conversions:**
```matlab
% Global → Local
point_local = rotationMatrix(-wheelchair_yaw) * (point_global - wheelchair_pos_global);

% Local → Global
point_global = wheelchair_pos_global + rotationMatrix(wheelchair_yaw) * point_local;
```

### B. Door Detection Parameter Reference

```matlab
% Default door_params structure (complete)
door_params = struct();

% Phase 0: Position Correction
door_params.TARGET_DISTANCE = 2.5;              % meters from door center
door_params.POSITION_TOLERANCE = 0.15;          % ±15cm acceptable error
door_params.POSITION_ANGLE_TOLERANCE = 0.087;   % ±5° acceptable error (radians)
door_params.CORRECTION_TURN_SPEED = 0.1;        % rad/s
door_params.CORRECTION_MOVE_SPEED = 0.15;       % m/s
door_params.MAX_CORRECTION_ITERATIONS = 50;     % Timeout protection

% Phase 1: Turning (existing)
door_params.TURN_TOLERANCE = 0.1;               % radians (~6°)
door_params.TURN_SPEED = 0.1;                   % rad/s

% Phase 1.5: Door Detection (existing)
door_params.ANGLE_TOLERANCE = 30;               % ±30° initial cone (degrees)
door_params.NARROW_ROI_ANGLE = 12;              % ±12° wheelchair path (degrees)
door_params.DOOR_HEIGHT_MIN = 0.3;              % meters (avoid floor)
door_params.DOOR_HEIGHT_MAX = 2.2;              % meters (door top)
door_params.MIN_POINTS_THRESHOLD = 5;           % minimum points for analysis
door_params.DEPTH_THRESHOLD = 0.3;              % meters beyond door surface
door_params.FIXED_ELEVATOR_DISTANCE = 2.5;      % meters (odometry mode)

% Phase 2: Movement (existing)
door_params.MOVE_SPEED = 0.2;                   % m/s forward speed
door_params.PASS_THROUGH_DISTANCE = 3.0;        % meters (door passage)
door_params.DISTANCE_TOLERANCE = 0.1;           % meters (completion tolerance)
```

### C. Function Call Hierarchy

```
main_astar.m
  └── Control.m (main control loop)
      ├── navigateMultipleDoors.m
      │   ├── passThroughDoor.m (for type='door')
      │   │   ├── positionCorrectionPhase.m (Phase 0)
      │   │   ├── detectElevatorDoorState.m (Phase 1.5)
      │   │   └── (Phases 1, 2)
      │   │
      │   └── enterElevator.m (for type='elevator')
      │       ├── positionCorrectionPhase.m (Phase 0)
      │       ├── detectElevatorDoorState.m (Phase 1.5, 3)
      │       ├── controlElevatorDoor.m (Phase 3 - Gazebo only)
      │       └── (Phases 1, 2, 3, 4, 5)
      │
      └── (normal path following if checkpoint_mode=false)

PathSetting_AStar.m
  └── detectDoorsAlongPath.m (optional, auto-detection)
```

### D. Glossary

| Term | Definition |
|------|------------|
| **Checkpoint** | Waypoint requiring door passage (position + door info) |
| **Door Center** | [x, y] position of door center in global coordinates |
| **Target Position** | Position where wheelchair should stop before door (Phase 0 goal) |
| **Pass-Through Distance** | Distance wheelchair travels during Phase 2 (door passage) |
| **Narrow ROI** | ±12° angular region defining wheelchair safe passage width |
| **Deep Points** | LiDAR points beyond door surface (indicating door is open) |
| **Odometry Mode** | Coordinate system using wheelchair-relative (local) coordinates |
| **Map Mode** | Coordinate system using global (map) coordinates |
| **Phase 0** | Position correction phase (NEW) |
| **Phase 1.5** | Door detection phase (existing) |

### E. References

1. **Existing Documentation:**
   - `Reference/AStar_Algorithm_Explanation.md` - A* pathfinding details
   - `Reference/FPM_BoundingBox_Documentation.md` - Obstacle avoidance
   - `Reference/Obstacle_Inflation_Deep_Dive.md` - Safety margins

2. **Key Source Files:**
   - `enterElevator.m` - Current elevator entry implementation
   - `detectElevatorDoorState.m` - LiDAR door detection algorithm
   - `debugElevatorDoorDetection.m` - Door detection visualization
   - `PathSetting_AStar.m` - A* path planning
   - `Control.m` - Main control loop

3. **Related Work:**
   - LiDAR-based door detection: Angular ROI method
   - A* pathfinding with occupancy grid
   - Wheelchair autonomous navigation in indoor environments

---

**Document Version**: 1.0
**Last Updated**: 2025-10-06
**Next Review**: After Phase 0 implementation (Week 1 completion)

