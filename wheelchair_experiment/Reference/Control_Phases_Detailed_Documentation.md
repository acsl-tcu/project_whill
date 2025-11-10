# Control Phases - Detailed Documentation

This document provides in-depth explanations of the three main control phases used in the wheelchair navigation system: **Path Following**, **Door Entry**, and **Elevator Entry**.

---

## Table of Contents

1. [Path Following Phase](#1-path-following-phase)
2. [Door Entry Phase](#2-door-entry-phase)
3. [Elevator Entry Phase](#3-elevator-entry-phase)
4. [Phase Transitions](#4-phase-transitions)
5. [Common Components](#5-common-components)

---

## 1. Path Following Phase

### Overview

**control_mode:** `'path_following'`
**Purpose:** Navigate the wheelchair along a predefined path of waypoints using Model Predictive Control (MPC) with obstacle avoidance.
**Used for:** All navigation segments within rooms and corridors.

### Algorithm: MPC (Model Predictive Control)

The path following phase uses an MPC-based approach with the following key steps:

#### 1.1 Input Generation
```matlab
pu = GenerateInput(obj);
```
- Generates a set of candidate control input sequences
- Each input is a pair `[v; ω]` (linear velocity, angular velocity)
- Creates a diverse set of possible control trajectories

#### 1.2 Predictive Path Simulation
```matlab
px = Discretemodel(obj, px_now, pu);
```
- Simulates the wheelchair's future trajectory for each input sequence
- Uses the wheelchair's kinematic model
- Predicts position `[x, y, θ]` over prediction horizon `NP`
- **Current state:** `px_now = [Position.X; Position.Y; Position.yaw]`

#### 1.3 Target Waypoint Selection
```matlab
obj.target_n = determine_target_location(tempobj_d, px);
```
- Dynamically selects which waypoint to target based on predicted paths
- Updates the target waypoint as the wheelchair progresses
- Switches to next waypoint when current one is reached
- **Updated in PhaseManager:** `phaseManager.setCurrentTargetWaypoint(obj.target_n(1,1))`

#### 1.4 Path Evaluation
```matlab
[pw, remove_sample] = EvaluationPath_vec_gpu(tempobj, px, pu, preobs, param_FPM, Grid_Matrix);
```
**Cost function includes:**
- **Waypoint tracking cost:** Distance to target waypoint
- **Orientation cost:** Alignment with desired heading
- **Obstacle avoidance cost:** Penalty for proximity to detected objects
- **Wall penalty:** Avoid collision with map boundaries
- **Smoothness cost:** Prefer smooth control inputs

**FPM (Follow Path Method) integration:**
- Uses bounding boxes from object detection
- Calculates collision risk with detected obstacles
- Incorporates LiDAR point cloud data for obstacle avoidance

#### 1.5 Best Path Selection
```matlab
[BestCost, BestCostId] = min(pw);
[uOpt, fval, removed] = clustering(obj, pw, pu, px, remove_sample);
```
- Selects the path with minimum cost
- Performs clustering to group similar trajectories
- Extracts optimal control input `uOpt`

#### 1.6 Control Command Extraction
```matlab
U = uOpt.u(1).u(:,1);
```
- Extracts the first control command from the optimal sequence
- Applies **receding horizon principle:** only execute first command, then recompute

### Completion Condition

```matlab
if obj.target_n(1,1) >= size(obj.waypoint, 1)
    % Reached last waypoint - complete this action
    obj.phaseManager.completeTransition2();
    obj.loadNextSegmentWaypoints();
end
```

**Path following completes when:**
- The wheelchair reaches the final waypoint in the current segment
- `target_n` (current waypoint index) ≥ total number of waypoints

### Output

**Control command:** `U = [v; ω]`
- `v`: Linear velocity (m/s)
- `ω`: Angular velocity (rad/s)

**Additional outputs for visualization:**
- `pu`: Input samples (candidate control inputs)
- `px`: Predicted paths (simulated trajectories)
- `pw`: Path weights (cost values)
- `BestCost`: Minimum cost value
- `uOpt`: Optimal control sequence

---

## 2. Door Entry Phase

### Overview

**control_mode:** `'door_entry'`
**Purpose:** Navigate through a door passage between two rooms.
**Function:** `enterDoor()` in `MultiRoomNav/enterDoor.m`

### Phase Sequence

The door entry is broken down into 4 sub-phases:

#### Phase 1: Position Correction

**Goal:** Reach the target position before the door (typically ~1m away)

```matlab
phase1_result = positionCorrectionPhase(current_position, current_yaw,
                                        target_position, door_center, door_params);
```

**Actions:**
- Navigate to the pre-door position (determined by A* path planning)
- Align orientation to face the door
- Verify position accuracy within tolerance

**Completion criteria:**
- Distance to target position < threshold
- Orientation aligned within tolerance
- Sets `phase1_completed = true`

#### Phase 2: Turn Towards Exit Position

**Goal:** Align wheelchair to face the exit position in the next room (not just the door center)

```matlab
direction_vector = exit_position - current_position;
required_heading = atan2(direction_vector(2), direction_vector(1));
heading_error = angdiff(required_heading, current_yaw);
```

**Actions:**
- Calculate required heading to face exit position
- Apply pure rotation control: `V = [0; turn_speed]`
- Continue until aligned within `TURN_TOLERANCE`

**Why face exit position?**
- Ensures wheelchair enters the next room with correct orientation
- Avoids need to reorient after passing through door
- Smoother transition to next navigation segment

#### Phase 2.5: Door Verification

**Goal:** Verify the door is passable (open) before attempting to cross

```matlab
door_check = checkDoorPassable(lidar_scan_data, wheelchair_pose, door_center,
                                door_type, odometry_mode, door_params);
```

**Door detection logic:**
- Uses LiDAR point cloud to detect obstacles in front of wheelchair
- Defines a narrow region of interest (ROI) in front of door
- **Door is OPEN:** Few/no points detected in ROI
- **Door is CLOSED:** Significant points detected in ROI (door surface)

**Actions based on detection:**
- **Open:** Wait 2 seconds, then proceed to Phase 3
- **Closed:** Perform idle motion to trigger automatic door sensor
- **Unknown:** Proceed anyway (fail-safe)

**Idle motion for closed doors:**
```matlab
idle_result = idleMotionForDoorSensor(idle_params);
```
- Alternates small forward/backward movements (5 cm/s)
- Triggers motion-activated door sensors
- Continues until door is detected as open

#### Phase 3: Move Through Door

**Goal:** Pass through the door to the exit position

```matlab
TARGET_DOOR_DISTANCE = 2.0; % meters
move_result = moveDistance(TARGET_DOOR_DISTANCE, MOVE_SPEED, 'forward',
                           distance_traveled, last_update_time);
```

**Actions:**
- Move forward at constant velocity (`MOVE_SPEED`)
- Track distance traveled using odometry
- Continue until traveled `TARGET_DOOR_DISTANCE` (typically 2.0m)

**Odometry tracking:**
- Uses delta time and velocity to estimate distance
- Accumulates in `distance_traveled` persistent variable
- More reliable than position-based completion (avoids localization drift during door crossing)

#### Phase 4: Completion

**Goal:** Signal that door entry is complete

```matlab
result.completed = true;
result.phase = 4;
result.status = 'Door entry completed';
```

**Actions:**
- Sets `completed = true` flag
- Control.m calls `phaseManager.completeTransition2()`
- Loads next segment waypoints
- Transitions to next action (typically `path_follow` in next room)

### Door Types

The `enterDoor()` function supports two door types:

1. **'regular':** Standard room-to-room doors
   - Simpler entry sequence
   - No additional phases after crossing

2. **'elevator':** Elevator doors (delegated to `enterElevator()`)
   - Uses Phases 1-3 from `enterDoor()`
   - Adds elevator-specific Phases 4-6 (see Elevator Entry section)

### Key Parameters

```matlab
door_params = struct();
door_params.TURN_TOLERANCE = 0.1;      % rad - alignment tolerance
door_params.TURN_SPEED = 0.3;          % rad/s - rotation speed
door_params.MOVE_SPEED = 0.2;          % m/s - forward speed
door_params.MOVE_DISTANCE = 2.0;       % m - distance to travel in Phase 3
door_params.NARROW_ROI_ANGLE = 15;     % degrees - door detection cone
door_params.NARROW_ROI_DISTANCE = 2.0; % m - door detection range
```

### Persistent State Variables

The `enterDoor()` function uses persistent variables to maintain state across calls:

```matlab
persistent phase1_completed;  % Track Phase 1 completion
persistent door_verified;     % Track Phase 2.5 completion
persistent distance_traveled; % Track Phase 3 odometry
persistent last_update_time;  % For delta time calculation
```

**Important:** These are reset when the action completes.

---

## 3. Elevator Entry Phase

### Overview

**control_mode:** `'elevator_entry'`
**Purpose:** Enter the elevator, travel between floors, and exit.
**Function:** `enterElevatorNew()` in `enterElevatorNew.m`
**Extends:** Uses `enterDoor()` for Phases 1-3, adds elevator-specific Phases 4-6

### Phase Sequence

#### Phases 1-3: Door Entry (Delegated)

```matlab
door_result = enterDoor(current_position, current_yaw, elevator_center,
                        exit_position, lidar_scan_data, door_params, 'elevator');
```

Uses the standard door entry sequence:
- **Phase 1:** Position correction
- **Phase 2:** Turn towards exit
- **Phase 2.5:** Door verification and opening
- **Phase 3:** Move into elevator

**Exit position calculation:**
```matlab
direction_to_elevator = elevator_center - current_position;
direction_angle = atan2(direction_to_elevator(2), direction_to_elevator(1));
entry_distance = door_params.MOVE_DISTANCE; % How far into elevator
exit_position = elevator_center + entry_distance * [cos(direction_angle), sin(direction_angle)];
```

**Special elevator door handling (Phase 2.5):**
```matlab
if elevator_result.phase == 2.5 && strcmp(elevator_result.door_state, 'closed')
    if obj.Gazebo
        controlElevatorDoor('open');  % Open door in simulation
    end
end
```

#### Phase 4: Inside Elevator Waiting

**State:** `elevator_sequence_state = 'door_closed'` → `'inside_waiting'`

**Sub-phase 4a: Door Closing**
```matlab
elevator_sequence_state = 'door_closed';
if is_gazebo
    controlElevatorDoor('close');
end
result.V = [0; 0]; % Stop motion
```

**Actions:**
- Wheelchair stops inside elevator
- Door closes (simulated in Gazebo)
- Wait for floor change

**Sub-phase 4b: Floor Selection**
```matlab
if is_gazebo && ~floor_input_requested
    user_floor = input('Floor number: ');
    current_floor = user_floor;
    floor_input_requested = true;
end
```

**Actions:**
- Prompts user for floor number (Gazebo only)
- In real system: would interface with elevator control panel
- Updates `current_floor` variable

**Sub-phase 4c: Floor Change Simulation**
```matlab
if current_floor == target_floor
    controlElevatorDoor('open');
    elevator_sequence_state = 'inside_waiting';
end
```

**Actions:**
- Checks if current floor matches target floor
- Opens elevator door when destination reached
- Transitions to door opening detection

**Sub-phase 4d: Door Opening Detection**
```matlab
door_state = detectElevatorDoorState(pointCloud, wheelchair_pose,
                                      target_position, false, door_params);
if strcmp(door_state, 'open')
    elevator_sequence_state = 'reversing';
end
```

**Actions:**
- Uses LiDAR to detect when door is fully open
- Looks towards hallway/exit direction
- Transitions to Phase 5 when door confirmed open

#### Phase 5: Reverse Out of Elevator

**State:** `elevator_sequence_state = 'reversing'`

```matlab
REVERSE_DISTANCE = phase5_distance_to_reverse; % Distance entered in Phase 3
reverse_result = moveDistance(REVERSE_DISTANCE, MOVE_SPEED, 'reverse',
                               distance_traveled, last_update_time);
result.V = reverse_result.V;
```

**Actions:**
- Reverses backward out of elevator
- Uses same distance as Phase 3 entry (stored in `phase5_distance_to_reverse`)
- Tracks distance using odometry
- **Control command:** `V = [-MOVE_SPEED; 0]` (negative linear velocity)

**Why reverse?**
- Avoids need to turn around inside elevator (tight space)
- Maintains orientation facing elevator for stability
- Exits smoothly without complex maneuvering

**Completion:**
```matlab
if reverse_result.completed
    elevator_sequence_state = 'completed';
end
```

#### Phase 6: Completion

**State:** `elevator_sequence_state = 'completed'`

```matlab
result.phase = 6;
result.status = 'Elevator sequence completed';
result.completed = true;
result.V = [0; 0];
```

**Actions:**
- Signals elevator entry is complete
- Wheelchair is now outside elevator on new floor
- PhaseManager advances to next action
- Navigation continues from new floor

### Elevator-Specific Features

#### Coordinate Modes

The elevator entry supports two coordinate systems:

1. **Global Mode** (`odometry_mode = false`)
   - Uses map coordinates from OptiTrack/localization
   - More accurate position tracking
   - Default for Gazebo simulation

2. **Odometry Mode** (`odometry_mode = true`)
   - Uses local wheelchair coordinates (relative)
   - Map-independent operation
   - Useful when GPS/localization unavailable

#### Door Detection Mode (Debug)

```matlab
if door_detection_mode
    fprintf('*** DOOR DETECTION MODE ACTIVE ***\n');
end
```

**Purpose:** Testing and debugging door detection without full navigation
- Bypasses Phase 1 (position correction)
- Jumps directly to Phase 1.5 (door detection)
- Allows testing door sensor/LiDAR integration

#### Gazebo Integration

```matlab
if is_gazebo
    controlElevatorDoor('open');  % Open door
    controlElevatorDoor('close'); % Close door
end
```

**Simulated actions in Gazebo:**
- Opens elevator door when needed (Phase 2.5, Phase 4)
- Closes door after entry (Phase 4)
- In real system: doors controlled by elevator's internal system

### State Machine Diagram

```
                    ┌─────────────┐
                    │  'entering' │ (Phases 1-3: enterDoor)
                    └──────┬──────┘
                           │ Phase 3 completed
                           ▼
                  ┌─────────────────┐
                  │ 'door_closed'   │ (Phase 4a: Wait for door close)
                  └────────┬─────────┘
                           │ Door closed
                           ▼
                ┌───────────────────────┐
                │ 'inside_waiting'      │ (Phase 4b-d: Floor change & door opening)
                └──────────┬────────────┘
                           │ Door detected open
                           ▼
                  ┌──────────────────┐
                  │   'reversing'    │ (Phase 5: Reverse out)
                  └────────┬─────────┘
                           │ Reverse distance complete
                           ▼
                    ┌──────────────┐
                    │  'completed' │ (Phase 6: Done)
                    └──────────────┘
```

### Persistent State Variables

```matlab
persistent entry_completed;             % Track if Phases 1-3 done
persistent elevator_sequence_state;     % Current state machine state
persistent sequence_timer;              % Timer for time-based transitions
persistent current_floor;               % Current elevator floor
persistent target_floor;                % Destination floor
persistent floor_input_requested;       % Track if user input received
persistent phase5_distance_to_reverse;  % Distance to reverse in Phase 5
```

**Reset on completion:** All persistent variables cleared when Phase 6 completes.

---

## 4. Phase Transitions

### How Phases Advance

The PhaseManager uses an **action sequence** system to manage phase transitions:

```matlab
[control_mode, target_info] = obj.phaseManager.getCurrentPhaseInfo();
```

**Action sequence example:**
```
Action 1: path_follow (Room A)
Action 2: door_entry (Door A→B)
Action 3: path_follow (Room B)
Action 4: door_entry (Door B→C)
Action 5: path_follow (Room C)
Action 6: elevator_entry (Elevator)
```

### Completion Signal

Each phase signals completion back to PhaseManager:

```matlab
if action_completed
    obj.phaseManager.completeTransition2();
    obj.loadNextSegmentWaypoints();
end
```

**completeTransition2():**
- Increments `current_action_index`
- Prints completion message
- Advances to next action in sequence

**loadNextSegmentWaypoints():**
- Loads waypoints for next path_follow action
- Skips loading for non-navigation actions (door_entry, elevator_entry)

### Transition Examples

#### Path Following → Door Entry
```matlab
% Path following detects last waypoint reached
if obj.target_n(1,1) >= size(obj.waypoint, 1)
    obj.phaseManager.completeTransition2();
end

% Next call to getCurrentPhaseInfo() returns:
control_mode = 'door_entry';
target_info.door_center = [...];
target_info.exit_position = [...];
```

#### Door Entry → Path Following
```matlab
% Door entry Phase 4 completes
result.completed = true;

% Control.m detects completion
if door_result.completed
    obj.phaseManager.completeTransition2();
    obj.loadNextSegmentWaypoints(); % Load next room's waypoints
end

% Next call returns:
control_mode = 'path_following';
target_info.position = waypoint(1, :); % First waypoint of next segment
```

#### Path Following → Elevator Entry → Completed
```matlab
% Final path segment completes
obj.phaseManager.completeTransition2();

% Elevator entry action starts
control_mode = 'elevator_entry';

% Elevator Phase 6 completes
result.completed = true;
obj.phaseManager.completeTransition2();

% No more actions in sequence
control_mode = 'completed';
```

---

## 5. Common Components

### 5.1 LiDAR Point Cloud Processing

All phases use LiDAR data for obstacle detection and door sensing:

```matlab
lidar_scan_data = struct();
lidar_scan_data.xyz_global = {...}; % Point cloud in world coordinates
lidar_scan_data.xyz_local = {...};  % Point cloud in wheelchair frame
```

**Used for:**
- **Path following:** Obstacle detection and avoidance
- **Door entry:** Door open/closed detection (Phase 2.5)
- **Elevator entry:** Door state verification

### 5.2 Coordinate Systems

**Global coordinates (world frame):**
- Origin at map reference point
- Used for waypoint following
- Requires localization (OptiTrack, SLAM, etc.)

**Local coordinates (wheelchair frame):**
- Origin at wheelchair center
- X-axis forward, Y-axis left
- Used for relative obstacle detection

**Conversion:**
```matlab
% Global to local
local_point = R' * (global_point - wheelchair_position);

% Local to global
global_point = R * local_point + wheelchair_position;
```
Where `R` is rotation matrix from wheelchair yaw angle.

### 5.3 Control Command Format

All phases output the same control command structure:

```matlab
U = [v; ω];
```
- `v`: Linear velocity (m/s), positive = forward, negative = backward
- `ω`: Angular velocity (rad/s), positive = counterclockwise

**Typical ranges:**
- Path following: `v ∈ [0, 0.5]`, `ω ∈ [-0.5, 0.5]`
- Door turning: `v = 0`, `ω ∈ [-0.3, 0.3]`
- Door crossing: `v = 0.2`, `ω = 0`
- Elevator reverse: `v = -0.2`, `ω = 0`

### 5.4 Safety Features

**Collision avoidance (Path following):**
- FPM cost penalizes paths too close to obstacles
- Wall penalty prevents map boundary violations
- Emergency stop if no safe path available

**Door verification (Door/Elevator entry):**
- Phase 2.5 prevents moving through closed doors
- Idle motion triggers automatic door sensors
- Timeout fail-safe proceeds anyway if stuck

**Odometry backup (Door/Elevator entry):**
- Uses distance traveled instead of position for completion
- Avoids localization failures during door crossing
- More robust in GPS-denied environments

### 5.5 Parameter Configuration

**Centralized parameter struct:**
```matlab
door_params = struct();
door_params.TURN_TOLERANCE = 0.1;       % rad
door_params.TURN_SPEED = 0.3;           % rad/s
door_params.MOVE_SPEED = 0.2;           % m/s
door_params.MOVE_DISTANCE = 2.0;        % m
door_params.CORRECTION_TURN_SPEED = 0.3;
door_params.NARROW_ROI_ANGLE = 12;      % degrees
door_params.NARROW_ROI_DISTANCE = 2.0;  % m
door_params.IDLE_SPEED = 0.05;          % m/s
```

**Passed to all entry functions:**
- `enterDoor(... door_params ...)`
- `enterElevator(... door_params ...)`
- Ensures consistent behavior across all door/elevator entries

---

## Summary Table

| Phase | Control Mode | Key Algorithm | Completion Criteria | Typical Duration |
|-------|--------------|---------------|---------------------|------------------|
| **Path Following** | `'path_following'` | MPC with FPM obstacle avoidance | Reached last waypoint | 10-60 seconds |
| **Door Entry** | `'door_entry'` | 4-phase sequence (position→turn→verify→cross) | Crossed door threshold (2m traveled) | 5-15 seconds |
| **Elevator Entry** | `'elevator_entry'` | 6-phase sequence (entry→wait→floor change→reverse) | Reversed out of elevator | 20-60 seconds |

---

## File References

- **Path Following:** `src/Controller/@Control/Control.m:625` (`pathFollowingControl`)
- **Door Entry:** `MultiRoomNav/enterDoor.m` (`enterDoor`)
- **Elevator Entry:** `enterElevatorNew.m` (`enterElevatorNew`)
- **Phase Manager:** `src/PhaseManager.m` (`getCurrentPhaseInfo`, `completeTransition2`)
- **Control Main:** `src/Controller/@Control/Control.m:398` (main control switch)

---

*Last updated: 2025-01-27*
*Part of wheelchair_experiment project documentation*
