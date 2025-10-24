# Complete Control Loop Print Statements Reference

**Date Created:** 2025-01-27
**Last Updated:** 2025-01-27
**Purpose:** Comprehensive documentation of ALL print statements executed during the wheelchair control loop

---

## Table of Contents

1. [Overview](#overview)
2. [Frequency Classification](#frequency-classification)
3. [Estimator (Estimate.m)](#estimator-estimatem)
4. [Controller (Control.m)](#controller-controlm)
5. [Phase Manager](#phase-manager)
6. [Elevator Entry System](#elevator-entry-system)
7. [Door Entry System](#door-entry-system)
8. [Movement Helper Functions](#movement-helper-functions)
9. [Door/Elevator Control](#doorelevator-control)
10. [Path Planning Functions](#path-planning-functions)
11. [Tracking and Estimation](#tracking-and-estimation)
12. [Quick Reference: Most Frequent Prints](#quick-reference-most-frequent-prints)
13. [Recommendations](#recommendations)

---

## Overview

This document catalogs **ALL** fprintf, disp, printf, warning, and error statements that can execute during the main wheelchair control loop (`main.m` → `mainLoop()` → `Estimate.main()` → `Control.main()`).

### Control Loop Flow
```
main.m
  └─ mainLoop(obj)
       └─ Loop iteration
            ├─ Estimate.main(Plant)         [Estimation phase]
            │    ├─ LiDAR processing
            │    ├─ Object tracking
            │    └─ Phase management
            │
            └─ Control.main(Plant)          [Control phase]
                 ├─ displayStatusMessage()  [EVERY ITERATION]
                 ├─ Path following OR
                 ├─ enterElevator() OR
                 ├─ enterDoor() OR
                 └─ Manual control
```

---

## Frequency Classification

### 🔴 **EVERY ITERATION** (Runs constantly)
- **Control.m displayStatusMessage()** - Lines 592-659 (clc + 5-8 fprintf)
- **Estimate.m NDT Pose Broadcasting** - Line 515 (if in NDT mode)
- **enterElevator() status** - Multiple fprintf when in elevator_entry phase
- **checkDoorPassable() detection** - Lines 40-137+ during door detection
- **turnTowardsTarget()** - Lines 42/50/54 during turning
- **moveDistance()** - Line 69 during movement

### 🟡 **PERIODIC** (Every N iterations)
- **Estimate.m Position Debug** - Lines 543/547 (every 50 iterations)

### 🟢 **PHASE TRANSITIONS** (Occasional)
- **PhaseManager.setPhase()** - When phase changes
- **PhaseManager.updatePathFollower()** - Segment/transition updates
- **Control.m segment loading** - Line 830 when loading new segment
- **Estimate.m replanning** - Lines 1524-1563 when replanning triggered

### ⚪ **INITIALIZATION ONLY** (Once)
- **Estimate.m Constructor** - Waypoint selection menu
- **Control.m Constructor** - ROS initialization
- **PhaseManager.planMission()** - Mission planning
- **controlElevatorDoor('close')** - Initial door close

### 🔵 **DEBUG/ERROR** (Rare)
- **FPM_boundingbox_vec_true** - Debug visualization (if enabled)
- **Various error() calls** - Exception handling
- **Track limit warnings** - manage_track.m

---

## Estimator (Estimate.m)

**File:** `src/Estimator/Estimate.m`

### Constructor Initialization ⚪
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 209-212 | Constructor | Once | Waypoint selection menu | User prompt |
| 226 | Constructor | Once | `'[ESTIMATE] Generating default path to elevator...\n'` | Path generation start |
| 239-240 | Constructor | Once | `'[ESTIMATE] Default path created. Waiting for mode selection...\n'` | Path complete |
| 280 | Constructor | Once | `'Estimate: Path visualization plotted in world coordinates\n'` | Visualization success |
| 282 | Constructor | Once | `'Estimate: Could not create path visualization: %s\n'` | Visualization error |

### Main Loop - Mode Request Handling 🟢
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 423 | main() | Error | `error('No such a configured mode.')` | Invalid mode |
| 443 | main() | Mode 1 | `'[ESTIMATE] Mode 1: Using pre-planned elevator path from constructor\n'` | floor_change first use |
| 445 | main() | Mode 1 | `'[ESTIMATE] Action sequence already created (elevator goal)\n'` | Confirmation |
| 448 | main() | Mode 1 | `'[ESTIMATE] Replanning floor_change - generating new path from current position\n'` | Replanning |
| 456 | main() | Mode 4 | `'[ESTIMATE] Mode 4: Using pre-planned path with navigation_only action sequence\n'` | navigation_only |
| 466 | main() | Mode 4 | `'[ESTIMATE] Mode 4: Action sequence updated (same waypoints as Mode 1)\n'` | Confirmation |
| 470 | main() | Mode 2 | `'[ESTIMATE] Door detection mode - creating door detection action\n'` | door_detection |
| 481 | main() | Mode 2 | `'[ESTIMATE] Mode 2: Door detection action created\n'` | Confirmation |
| 485 | main() | Mode 3 | `'[ESTIMATE] NDT pose detection mode - creating NDT pose action\n'` | ndt_pose_detection |
| 496 | main() | Mode 3 | `'[ESTIMATE] Mode 3: NDT pose detection action created\n'` | Confirmation |
| 499 | main() | Error | `'[ESTIMATE] Unknown user mode request: %s\n'` | Unknown mode |

### Main Loop - NDT Pose Broadcasting 🔴
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 515 | main() | **EVERY ITER** | `'[NDT_POSE] X: %8.3f m \| Y: %8.3f m \| Z: %8.3f m \| Yaw: %7.2f° \| Time: %.2f s\n'` | **Continuous broadcast in NDT mode** |

**⚠️ HIGH FREQUENCY WARNING:** This prints EVERY iteration when in NDT mode. Can flood console if dt is small.

### Main Loop - Position Debug 🟡
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 543-545 | main() | Every 50 | `'[ESTIMATE] Position: [%.3f, %.3f] - Target: %d/%d, Distance to final: %.2fm, Phase: %s\n'` | With waypoints |
| 547-548 | main() | Every 50 | `'[ESTIMATE] Position: [%.3f, %.3f] - Phase: %s\n'` | Without waypoints |

**Note:** `mod(obj.cnt, 50) == 0` condition prevents spam

### Replanning Function 🟢
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 1524-1528 | replanPathFromCurrentPosition() | Replan trigger | `'[ESTIMATE] ═══ REPLANNING from current position ═══\n'` | Multi-line header |
| 1561-1563 | replanPathFromCurrentPosition() | Replan complete | `'[ESTIMATE] Replanning complete\n'` | Confirmation |

---

## Controller (Control.m)

**File:** `src/Controller/@Control/Control.m`

### Constructor Initialization ⚪
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 146-154 | Constructor | Once | `'=== ROS INITIALIZATION CHECK ===\n'` + mode detection | ROS/Gazebo setup |
| 160-162 | Constructor | Once | `'[CONTROL PRE-DEBUG] BEFORE getWaypoints() call:\n'` | 🔵 DEBUG - Remove? |
| 167-186 | Constructor | Once | `'[CONTROL DEBUG] Waypoint data from SharedControlMode:\n'` | 🔵 DEBUG - Remove? |
| 190 | Constructor | Once | `'[CONTROL DEBUG] Extracted obj.waypoint: %dx%d\n'` | 🔵 DEBUG - Remove? |
| 197 | Constructor | Once | `'Control: Multi-room mode AUTO-DETECTED (%d segments)\n'` | Mode detection |
| 200 | Constructor | Once | `'Control: Single-room mode (%d waypoints)\n'` | Mode detection |
| 218 | Constructor | Once | `'Control: Using fallback waypoints (%d points)\n'` | ⚠️ Fallback warning |
| 225 | Constructor | Once | `'Control: Failed to get zones (%s), using defaults\n'` | ⚠️ Error warning |

**Recommendation:** Remove debug prints (160-190), keep initialization and warnings.

### Main Loop - NDT Mode Notification 🔴 (REDUNDANT)
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 460 | main() | **EVERY ITER** | `'[CONTROL] NDT Pose Detection mode: Autonomous control disabled - manual control active\n'` | ❌ **REDUNDANT** - Already in displayStatusMessage |

**⚠️ REDUNDANCY:** This message is duplicated in displayStatusMessage (lines 645-651). **Remove line 460.**

### Main Loop - Elevator Door Control 🟢
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 573 | pathFollowingControl() | Phase 2.5 | `'Control: Opening elevator door for Phase 2.5 verification (Gazebo)\n'` | Gazebo door open |
| 575 | pathFollowingControl() | Phase 2.5 | `'Control: Phase 2.5 detected - Real system, no door control needed\n'` | Real system skip |

**Note:** Useful action logging for elevator sequence debugging.

### Main Loop - Status Display 🔴
**Function:** `displayStatusMessage()` (Lines 581-661)
**Frequency:** **EVERY ITERATION**
**Behavior:** Uses `clc` to clear screen, then prints current status

#### Multi-Room Navigation Mode (Lines 592-603)
```matlab
fprintf('=== MULTI-ROOM NAVIGATION MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Nav Mode: %s\n', obj.multiRoomNavState.mode);
fprintf('Status: %s\n', obj.multiRoomNavState.status);
fprintf('Segment: %d/%d\n', obj.multiRoomNavState.current_segment, length(...));
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('===================================\n');
```
**Total:** 7 fprintf per iteration

#### Path Following Mode (Lines 607-612)
```matlab
fprintf('=== PATH FOLLOWING MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Goal Distance: %.2f m\n', goal_distance);
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('Target Waypoint: %d/%d\n', obj.target_n(1,1), size(obj.waypoint,1));
fprintf('==========================\n');
```
**Total:** 6 fprintf per iteration

#### Door Crossing Mode (Lines 616-629)
```matlab
fprintf('=== DOOR CROSSING MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Status: Navigating through door\n');
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('Door Center: [%.2f, %.2f]\n', ...);  // If available
fprintf('Exit Target: [%.2f, %.2f]\n', ...);  // If available
fprintf('==========================\n');
```
**Total:** 5-7 fprintf per iteration

#### Elevator Entry Mode (Lines 634-641)
```matlab
fprintf('=== ELEVATOR ENTRY MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Phase: %d - %s\n', elevator_result.phase, elevator_result.status);  // If available
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('Elevator Center: [%.1d, %.1d]\n', ...);
fprintf('===========================\n');
```
**Total:** 5-6 fprintf per iteration

#### NDT Pose Detection Mode (Lines 645-651)
```matlab
fprintf('=== NDT POSE DETECTION MODE ===\n');
fprintf('** MANUAL CONTROL ACTIVE **\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Autonomous Control: DISABLED\n');
fprintf('Use your manual controls to move the wheelchair\n');
fprintf('Pose is being continuously broadcast in Estimate.m\n');
fprintf('===========================\n');
```
**Total:** 7 fprintf per iteration

#### System Completed Mode (Lines 655-659)
```matlab
fprintf('=== SYSTEM COMPLETED ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Status: STOPPED\n');
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('========================\n');
```
**Total:** 5 fprintf per iteration

**⚠️ HIGH FREQUENCY WARNING:** All these messages print EVERY iteration (typically 5-10 Hz). The `clc` command prevents scrolling but updates screen constantly.

### Segment Loading 🟢
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 830 | loadNextSegmentWaypoints() | Segment transition | `'[CONTROL] Loaded new segment waypoints (%d waypoints)\n'` | Multi-room transition |

### Multi-Room Navigation 🟢
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 755 | executeMultiRoomNavigation() | Init | `'[CONTROL] Initializing multi-room navigation...\n'` | Multi-room start |
| 785 | executeMultiRoomNavigation() | Completion | `'=== MODE CHANGE: Multi-room navigation COMPLETED ===\n'` | Multi-room done |

---

## Phase Manager

**File:** `src/PhaseManager.m`

### Initialization ⚪
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 65 | Constructor | Error | `error('PhaseManager requires a SharedControlMode object')` | Missing dependency |
| 101 | Constructor | Once | `'[PHASE MANAGER] Universal Path Follower Initialized\n'` | Init confirmation |

### Phase Transitions 🟢
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 125 | setPhase() | Phase change | `'[PHASE MANAGER] Marking is_first_use = false (user-triggered: %s)\n'` | First use tracking |
| 128-144 | setPhase() | Phase change | Multiple phase transition messages | 10+ different messages |
| 183 | update() | Goal reach | `'[PHASE] Segment complete - GOAL REACHED!\n'` | Goal notification |
| 196 | completeDoorCrossing() | Deprecated call | `'[PHASE] WARNING: completeDoorCrossing is deprecated and not used\n'` | Deprecation warning |
| 212-220 | completeWaypoint() | Waypoint done | Multiple waypoint completion messages | Waypoint transitions |
| 303 | markPathReplanned() | Replan | `'[PHASE MANAGER] Path replanning marked - is_first_use set to false\n'` | Replan notification |
| 393-496 | updatePathFollower() | Navigation | Multiple segment/transition updates | Navigation progress |

### Mission Planning ⚪
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 554-603 | loadWaypoints() | Init | Multiple waypoint loading messages | Waypoint setup |
| 573 | setFinalGoalType() | Error | `error('Invalid goal_type: must be ''room'' or ''elevator''')` | Invalid goal |
| 579 | setFinalGoalType() | Init | `'[PHASE MANAGER] Final goal type changed: %s → %s\n'` | Goal type change |
| 585-603 | displayStatus() | Manual | Multiple status display messages | Status function |
| 624-829 | planMission() | Init | 20+ fprintf for mission planning | Mission setup |
| 874-961 | generateActionSequence() | Init | 15+ fprintf for action generation | Action planning |

---

## Elevator Entry System

**File:** `enterElevator.m`

**⚠️ CALLED FROM:** `Control.m main()` during `elevator_entry` phase
**⚠️ FREQUENCY:** Runs in loop until elevator entry complete

### Initial State (Lines 130-147) 🔴
```matlab
fprintf('*** DOOR DETECTION MODE: Setting DEBUG_MODE = true ***\n');  // If debug
fprintf('enterElevator called:\n');
fprintf('  Current position: [%.2f, %.2f]\n', ...);
fprintf('  Current yaw: %.2f rad (%.1f deg)\n', ...);
fprintf('  Elevator center: [%.2f, %.2f]\n', ...);
fprintf('  Elevator entry: [%.2f, %.2f]\n', ...);
fprintf('  Current phase: %d\n', phase);
fprintf('  Phase 1 correction complete: %d\n', phase1_correction_complete);
fprintf('  Phase 2 turning complete: %d\n', phase2_turning_complete);
fprintf('  Door open: %d\n', door_open);
fprintf('  Phase 3 forward complete: %d\n', phase3_forward_complete);
fprintf('  Phase 4 reverse complete: %d\n', phase4_reverse_complete);
```
**Total:** 12 fprintf **EVERY CALL**

### Phase Transitions 🔴
| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 161 | enterElevator() | Debug mode | `'*** DOOR DETECTION MODE: Bypassing Phase 1 and Phase 2 ***\n'` | Phase bypass |
| 180 | enterElevator() | Phase 1→2 | `'Phase 1 completed - proceeding to Phase 2 (turning)\n'` | Phase transition |
| 188 | enterElevator() | Phase 2 start | `'Phase 2: Turning towards elevator\n'` | Turn start |
| 199-208 | enterElevator() | Debug | Door detection debug messages | Debug mode |
| 239-244 | enterElevator() | **Every call** | Phase 2.5 door state messages | Door checking |
| 257-273 | enterElevator() | Phase 3 | Phase 3 movement messages | Forward motion |
| 279-321 | enterElevator() | Phase 4 | Phase 4 floor input and door control | User interaction |
| 363-389 | enterElevator() | Phase 4 | Phase 4 door verification | Door checking |
| 406 | enterElevator() | Phase 5 | `'Simulation COMPLETED! Wheelchair exited elevator.\n'` | Completion |
| 423-424 | enterElevator() | **Every call** | `'Command: V=[%.2f, %.2f] (linear, angular)\n'` | Command output |

**⚠️ CRITICAL:** Lines 133-147 print **EVERY CALL** (up to 12 lines per iteration). This runs in a tight loop during elevator entry.

---

## Door Entry System

**File:** `MultiRoomNav/enterDoor.m`

**⚠️ CALLED FROM:** `Control.m main()` during `door_entry` phase

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 116 | enterDoor() | Door open | `'Door detected as OPEN - waiting 2 seconds before moving forward...\n'` | Open detection |
| 122 | enterDoor() | Door closed | `'Door CLOSED - performing idle motion to trigger sensor...\n'` | Closed detection |

**Note:** Much simpler than elevator entry, minimal prints.

---

## Movement Helper Functions

### turnTowardsTarget.m 🔴
**File:** `src/turnTowardsTarget.m`
**⚠️ CALLED FROM:** Multiple phases during turning

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 42 | turnTowardsTarget() | **Every call** | `'  Turn: ALIGNED (error: %.1f deg)\n'` | Aligned state |
| 50 | turnTowardsTarget() | **Every call** | `'  Turn: LEFT (%.1f deg remaining)\n'` | Turning left |
| 54 | turnTowardsTarget() | **Every call** | `'  Turn: RIGHT (%.1f deg remaining)\n'` | Turning right |

**⚠️ HIGH FREQUENCY:** Prints **EVERY CALL** during turning phases.

### moveDistance.m 🔴
**File:** `src/moveDistance.m`
**⚠️ CALLED FROM:** Multiple phases during movement

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 31 | moveDistance() | Error | `error('Direction must be ''forward'' or ''reverse''')` | Invalid direction |
| 45 | moveDistance() | Warning | `'  WARNING: Large dt detected (%.2fs) - setting to 0 to prevent distance corruption\n'` | Large dt warning |
| 69 | moveDistance() | **Every call** | `'  Move: Distance traveled: %.2f m, Remaining: %.2f m (dt=%.3fs, direction=%s)\n'` | Progress update |
| 79 | moveDistance() | Forward | `'  Move: Moving FORWARD (%.1f m/s)\n'` | Forward motion |
| 82 | moveDistance() | Reverse | `'  Move: Moving REVERSE (%.1f m/s)\n'` | Reverse motion |
| 88 | moveDistance() | Complete | `'  Move: COMPLETED! Total distance: %.2f m\n'` | Completion |

**⚠️ HIGH FREQUENCY:** Line 69 prints **EVERY CALL** during movement phases.

### positionCorrectionPhase.m 🔴
**File:** `src/Controller/positionCorrectionPhase.m`
**⚠️ CALLED FROM:** Elevator entry Phase 1

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 63-66 | positionCorrectionPhase() | **Every call** | `'Phase 1: Position Correction\n'` + position info | Phase start (4 lines) |
| 82 | positionCorrectionPhase() | Turning | `'  Action: Turning towards target position (%.1f deg remaining)\n'` | Turn action |
| 88 | positionCorrectionPhase() | Moving | `'  Action: Moving FORWARD to target (%.2fm to go)\n'` | Move action |
| 99-100 | positionCorrectionPhase() | Complete | `'Phase 1: COMPLETED - Position verified!\n'` + errors | Completion (2 lines) |

**⚠️ HIGH FREQUENCY:** Lines 63-66 print **EVERY CALL** (4 lines per call).

---

## Door/Elevator Control

### controlElevatorDoor.m 🟢
**File:** `controlElevatorDoor.m`
**⚠️ CALLED FROM:** enterElevator.m, Control.m initialization

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 14 | controlElevatorDoor() | Open cmd | `'Opening elevator door...\n'` | Open action |
| 17 | controlElevatorDoor() | Close cmd | `'Closing elevator door...\n'` | Close action |
| 19 | controlElevatorDoor() | Error | `'Error: Invalid action. Use "open" or "close".\n'` | Invalid input |
| 28 | controlElevatorDoor() | Error | `'Error controlling elevator door: %s\n'` | Exception |

**Note:** Simple action logging, called occasionally.

### checkDoorPassable.m 🔴
**File:** `src/checkDoorPassable.m`
**⚠️ CALLED FROM:** enterElevator.m during door checking

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 36 | checkDoorPassable() | Warning | `'  Warning: Invalid door_type ''%s'', defaulting to ''regular''\n'` | Invalid type |
| 40 | checkDoorPassable() | **Every call** | `'  Checking door passability (Type: %s, Mode: %s)...\n'` | Start check |
| 45 | checkDoorPassable() | Warning | `'  Warning: No LiDAR data available\n'` | No LiDAR |
| 60-87 | checkDoorPassable() | Warnings | Multiple coordinate system warnings | Coord handling |
| 97-102 | checkDoorPassable() | **Every call** | Point cloud info and warnings | LiDAR stats |
| 124 | checkDoorPassable() | Visualization | `'  [VIS] Plotting door detection (iteration %d)\n'` | Vis counter |
| 137+ | checkDoorPassable() | **Every call** | 20+ fprintf for detection results | **Very verbose** |

**⚠️ CRITICAL:** This function prints **20+ lines EVERY CALL** during door detection. Extremely verbose.

---

## Path Planning Functions

### generateMultiRoomPath.m ⚪
**File:** `src/Estimator/generateMultiRoomPath.m`

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 33 | generateMultiRoomPath() | Error | `error('Room database not found at: %s\n...')` | Missing DB |
| 39-91 | generateMultiRoomPath() | Init | 20+ fprintf for planning progress | Path planning |
| 129-186 | generateMultiRoomPath() | Init | Multiple fprintf and warning for doors | Door extraction |

**Note:** Only runs during initialization/replanning, not in main loop.

### selectWaypointMethod.m ⚪
**File:** `src/Estimator/selectWaypointMethod.m`

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 18-68 | selectWaypointMethod() | Init | 15+ fprintf for menu and results | Waypoint selection |

**Note:** Only runs during initialization.

---

## Tracking and Estimation

### manage_track.m 🔵
**File:** `src/Estimator/manage_track.m`

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 99 | manage_track() | Rare | `warning('トラック管理許容数を超えました．新しいトラックを追加できません．')` | Track limit exceeded |

**Note:** Japanese warning message. Only when track limit exceeded (rare).

### FPM_boundingbox_vec_true.m 🔵
**File:** `src/Controller/FPM_boundingbox_vec_true.m`

| Line | Function | Frequency | Statement | Notes |
|------|----------|-----------|-----------|-------|
| 339 | FPM_boundingbox_vec_true() | Debug | `'Plotting %d obstacles...\n'` | Debug viz |
| 377 | FPM_boundingbox_vec_true() | Debug | `'Plotting %d paths...\n'` | Debug viz |
| 508 | FPM_boundingbox_vec_true() | Debug | `'FPM Debug plot updated (Best path: %d, Cost: %.3f)\n'` | Debug update |
| 511 | FPM_boundingbox_vec_true() | Debug | `'FPM Debug visualization failed: %s\n'` | Debug error |

**Note:** Only active if debug mode enabled. Not normally running.

---

## Quick Reference: Most Frequent Prints

### 🔴 **EVERY ITERATION** (Highest Priority to Review)

| Function | File | Lines | Count/Iter | Notes |
|----------|------|-------|------------|-------|
| **displayStatusMessage()** | Control.m | 592-659 | **5-8** | clc + status display |
| **enterElevator() initial state** | enterElevator.m | 133-147 | **12** | When in elevator_entry phase |
| **enterElevator() command** | enterElevator.m | 423-424 | **2** | Every elevator call |
| **turnTowardsTarget()** | turnTowardsTarget.m | 42/50/54 | **1** | During turning |
| **moveDistance() progress** | moveDistance.m | 69 | **1** | During movement |
| **positionCorrectionPhase()** | positionCorrectionPhase.m | 63-66 | **4** | Phase 1 of elevator |
| **checkDoorPassable()** | checkDoorPassable.m | 40-137+ | **20+** | Door detection (very verbose!) |
| **Estimate NDT pose** | Estimate.m | 515 | **1** | Only in NDT mode |

**⚠️ WORST OFFENDERS:**
1. **checkDoorPassable()** - 20+ lines per call during door detection
2. **enterElevator()** - 12+ lines per call during elevator entry
3. **displayStatusMessage()** - 5-8 lines per iteration (but uses clc)

### 🟡 **PERIODIC**

| Function | File | Frequency | Notes |
|----------|------|-----------|-------|
| **Estimate position debug** | Estimate.m | Every 50 iter | Controlled by `mod(cnt, 50)` |

### 🟢 **PHASE TRANSITIONS**

| Function | File | Trigger | Notes |
|----------|------|---------|-------|
| **PhaseManager.setPhase()** | PhaseManager.m | Phase change | Multiple messages |
| **Control segment loading** | Control.m | Segment switch | 1 message |
| **Estimate replanning** | Estimate.m | Replan trigger | 2 messages |

---

## Recommendations

### 🔴 **High Priority - Reduce Console Spam**

#### 1. checkDoorPassable.m (20+ lines per call)
**Problem:** Extremely verbose, prints 20+ lines every call during door detection
**Solution Options:**
- Add `verbose` parameter (default false)
- Keep only critical messages (warnings/errors)
- Use single status line with key info
- Collect messages and print summary at end

**Impact:** Could reduce console output by 100+ lines during door detection

#### 2. enterElevator.m Initial State (12 lines per call)
**Problem:** Prints complete state every call
**Solution Options:**
- Only print on phase transitions (not every iteration)
- Add verbose flag for debugging
- Reduce to 2-3 key status lines

**Impact:** Reduce elevator entry output by ~80%

#### 3. Control.m Line 460 NDT Message (REDUNDANT)
**Problem:** Duplicates displayStatusMessage
**Solution:** **Remove line 460** completely

**Impact:** Eliminate duplicate message

### 🟡 **Medium Priority - Cleanup Debug Prints**

#### 4. Control.m Constructor Debug (Lines 160-190)
**Problem:** Verbose debug output during initialization
**Solution:** Remove or gate behind debug flag
**Impact:** Cleaner initialization output

#### 5. positionCorrectionPhase.m (4 lines per call)
**Problem:** Prints every call
**Solution:** Only print on state changes
**Impact:** Reduce Phase 1 output by ~75%

### 🟢 **Low Priority - Keep As-Is**

These prints are useful and not excessive:
- **displayStatusMessage()** - Uses clc, provides good feedback
- **Phase transitions** - Important milestone notifications
- **Initialization messages** - One-time, informative
- **Error/warning messages** - Critical information

### 💡 **Best Practices for Adding New Prints**

1. **Runtime Status:** Add to displayStatusMessage(), not scattered code
2. **Debugging:** Gate behind debug flag (`if obj.debug_mode`)
3. **Progress:** Only on state changes, not every iteration
4. **Errors/Warnings:** Use MATLAB's `warning()` and `error()`
5. **Verbosity Levels:**
   - Level 0: Errors/warnings only
   - Level 1: Phase transitions and completions
   - Level 2: Progress updates (every N iterations)
   - Level 3: Full debug (every call)

### 📊 **Estimated Output Reduction**

| Action | Current Lines/Sec* | After Lines/Sec* | Reduction |
|--------|-------------------|------------------|-----------|
| Remove checkDoorPassable verbose | 100+ | 5 | **95%** |
| Fix enterElevator spam | 60+ | 10 | **83%** |
| Remove Control.m debug | 15+ | 0 | **100%** |
| Fix positionCorrectionPhase | 20 | 5 | **75%** |

*Assuming 5 Hz control loop during relevant phases

---

## Summary Statistics

### Total Print Statements Found
- **Estimate.m:** ~30 unique locations
- **Control.m:** ~25 unique locations
- **PhaseManager.m:** ~40 unique locations
- **Helper functions:** ~50 unique locations
- **Total:** **~145 unique print locations**

### Frequency Breakdown
- 🔴 **Every iteration:** 8 functions (potentially 50+ lines per iteration)
- 🟡 **Periodic:** 1 function (every 50 iterations)
- 🟢 **Phase transitions:** ~15 functions (occasional)
- ⚪ **Initialization:** ~20 functions (once)
- 🔵 **Debug/Error:** ~20 functions (rare)

---

**End of Complete Reference Document**

*For implementation of recommendations, see Control.m refactoring branch or create debug flag system.*
