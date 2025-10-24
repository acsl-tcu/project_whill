# Control.m Print Statements Reference

**Date Created:** 2025-01-27
**Purpose:** Document all fprintf/disp statements in Control.m for future reference and debugging

---

## Overview

This document catalogs all print statements in `src/Controller/@Control/Control.m`, organized by location and purpose. Use this reference when debugging or modifying console output behavior.

---

## 1. Constructor Prints (Lines 142-225)

### 1.1 ROS/Gazebo Initialization (Lines 146-154) ✅ KEEP
**Purpose:** Display system initialization mode
**Location:** `Control()` constructor
**Trigger:** On object creation

```matlab
fprintf('=== ROS INITIALIZATION CHECK ===\n');
if mode == 2
    obj.Gazebo = true;
    fprintf('Mode %d detected - Setting obj.Gazebo = true (Gazebo simulation)\n', mode);
else
    obj.Gazebo = false;
    fprintf('Mode %d detected - Setting obj.Gazebo = false (real system/experiment)\n', mode);
end
fprintf('=================================\n');
```

**When to modify:** If adding new simulation modes or changing mode detection logic

---

### 1.2 SharedControlMode Debug (Lines 160-162) ❌ DEBUG - Consider removing
**Purpose:** Debug SharedControlMode object state
**Location:** `Control()` constructor
**Trigger:** When `sharedControlMode.hasWaypoints()` returns true

```matlab
fprintf('\n[CONTROL PRE-DEBUG] BEFORE getWaypoints() call:\n');
fprintf('  sharedControlMode class: %s\n', class(sharedControlMode));
fprintf('  sharedControlMode is handle: %d\n', isa(sharedControlMode, 'handle'));
```

**Notes:**
- Debug-only output, very verbose
- Can be safely removed once SharedControlMode is stable
- Useful when debugging waypoint passing issues

---

### 1.3 Waypoint Data Type Debug (Lines 167-186) ❌ DEBUG - Consider removing
**Purpose:** Validate waypoint data structure
**Location:** `Control()` constructor
**Trigger:** After `getWaypoints()` call

```matlab
fprintf('\n[CONTROL DEBUG] Waypoint data from SharedControlMode:\n');
fprintf('  Type: %s\n', class(waypoint_cell_array));
fprintf('  Is cell: %d\n', iscell(waypoint_cell_array));
fprintf('  Length: %d\n', length(waypoint_cell_array));
fprintf('  Size: %s\n', mat2str(size(waypoint_cell_array)));
fprintf('  ndims: %d\n', ndims(waypoint_cell_array));

if ~iscell(waypoint_cell_array)
    fprintf('  *** ERROR: waypoint_cell_array is NOT a cell array! ***\n');
    fprintf('  *** It is a %s with value: %s ***\n', class(waypoint_cell_array), mat2str(waypoint_cell_array));
end

if iscell(waypoint_cell_array)
    for seg = 1:length(waypoint_cell_array)
        fprintf('  Segment %d: %dx%d waypoints\n', seg, size(waypoint_cell_array{seg}, 1), size(waypoint_cell_array{seg}, 2));
    end
end
fprintf('\n');
```

**Notes:**
- Very verbose debug output (15+ lines)
- Useful for diagnosing cell array vs matrix issues
- Can be removed once waypoint data structure is stable
- Consider keeping the error check but removing detailed debug prints

---

### 1.4 Extracted Waypoint Size Debug (Line 190) ❌ DEBUG - Consider removing
**Purpose:** Confirm waypoint extraction succeeded
**Location:** `Control()` constructor
**Trigger:** After extracting first segment

```matlab
fprintf('[CONTROL DEBUG] Extracted obj.waypoint: %dx%d\n\n', size(obj.waypoint, 1), size(obj.waypoint, 2));
```

**Notes:**
- Redundant with line 197/200 messages
- Can be removed

---

### 1.5 Multi-Room Mode Detection (Lines 197 & 200) ✅ KEEP
**Purpose:** Inform user of navigation mode
**Location:** `Control()` constructor
**Trigger:** After analyzing waypoint segments

```matlab
% Multi-room case
fprintf('Control: Multi-room mode AUTO-DETECTED (%d segments)\n', length(waypoint_cell_array));

% Single-room case
fprintf('Control: Single-room mode (%d waypoints)\n', size(obj.waypoint, 1));
```

**Notes:**
- Important initialization information
- Helps user understand system behavior
- Keep these messages

**When to modify:** If adding new navigation modes or changing mode detection logic

---

### 1.6 Fallback Waypoint Warning (Line 218) ✅ KEEP
**Purpose:** Warn user that default waypoints are being used
**Location:** `Control()` constructor
**Trigger:** When `sharedControlMode.hasWaypoints()` returns false

```matlab
fprintf('Control: Using fallback waypoints (%d points)\n', size(obj.waypoint, 1));
```

**Notes:**
- Important warning - indicates potential configuration issue
- Should be kept or upgraded to `warning()` for visibility

---

### 1.7 Zone Loading Error (Line 225) ✅ KEEP
**Purpose:** Report zone loading failure
**Location:** `Control()` constructor, catch block
**Trigger:** When `PathSetting_original` throws error

```matlab
fprintf('Control: Failed to get zones (%s), using defaults\n', ME.message);
```

**Notes:**
- Important error handling message
- Consider upgrading to `warning()` for better visibility

---

## 2. Runtime Prints in main() Function

### 2.1 NDT Pose Detection Mode (Line 460) ⚠️ REDUNDANT
**Purpose:** Notify that autonomous control is disabled
**Location:** `main()` function, 'ndt_pose_detection' case
**Trigger:** When phase is 'ndt_pose_detection'

```matlab
fprintf('[CONTROL] NDT Pose Detection mode: Autonomous control disabled - manual control active\n');
```

**Notes:**
- **REDUNDANT**: Same message already displayed in `displayStatusMessage()` (line 645-651)
- **Recommendation:** Remove this line (460), keep displayStatusMessage version
- The displayStatusMessage version is more comprehensive and properly formatted

---

### 2.2 Elevator Door Control Messages (Lines 573 & 575) ✅ KEEP
**Purpose:** Log elevator door control actions
**Location:** `pathFollowingControl()` method
**Trigger:** When elevator phase is 2.5 and door opening is detected

```matlab
% Gazebo simulation
fprintf('Control: Opening elevator door for Phase 2.5 verification (Gazebo)\n');

% Real system
fprintf('Control: Phase 2.5 detected - Real system, no door control needed\n');
```

**Notes:**
- Important action logging
- Helps debug elevator entry sequence
- Different behavior for Gazebo vs real system
- Keep both messages

**When to modify:** If changing elevator control logic or adding new phases

---

## 3. Runtime Prints in Helper Methods

### 3.1 Multi-Room Navigation Initialization (Line 755) ✅ KEEP
**Purpose:** Log multi-room navigation start
**Location:** `multiRoomNavigationControl()` method
**Trigger:** First call to multiRoomNavigationControl

```matlab
fprintf('[CONTROL] Initializing multi-room navigation...\n');
```

**Notes:**
- Important state transition message
- Helps track navigation mode switches
- Keep this message

---

### 3.2 Multi-Room Navigation Completion (Line 785) ✅ KEEP
**Purpose:** Announce navigation completion
**Location:** `multiRoomNavigationControl()` method
**Trigger:** When `nav_state.completed` is true

```matlab
fprintf('=== MODE CHANGE: Multi-room navigation COMPLETED ===\n');
```

**Notes:**
- Important completion notification
- Formatted with separators for visibility
- Keep this message

---

### 3.3 Segment Waypoint Loading (Line 830) ✅ KEEP
**Purpose:** Confirm new segment waypoints loaded
**Location:** `loadNextSegmentWaypoints()` method
**Trigger:** After successfully loading new segment

```matlab
fprintf('[CONTROL] Loaded new segment waypoints (%d waypoints)\n', size(obj.waypoint, 1));
```

**Notes:**
- Important transition message for multi-room navigation
- Helps debug segment switching
- Keep this message

---

## 4. displayStatusMessage() Function (Lines 581-661)

### Purpose
Central status display function that shows current system state in command window.

### Trigger
Called every control loop iteration from `main()` (line 492)

### Behavior
- Uses `clc` to clear command window (prevents message stacking)
- Displays different formats based on current phase from PhaseManager

### Messages by Phase

#### 4.1 Multi-Room Navigation Mode
```matlab
fprintf('=== MULTI-ROOM NAVIGATION MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Nav Mode: %s\n', obj.multiRoomNavState.mode);
fprintf('Status: %s\n', obj.multiRoomNavState.status);
fprintf('Segment: %d/%d\n', obj.multiRoomNavState.current_segment, ...);
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('===================================\n');
```

#### 4.2 Path Following Mode (path_following, floor_change)
```matlab
fprintf('=== PATH FOLLOWING MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Goal Distance: %.2f m\n', goal_distance);
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('Target Waypoint: %d/%d\n', obj.target_n(1,1), size(obj.waypoint,1));
fprintf('==========================\n');
```

#### 4.3 Door Entry Mode
```matlab
fprintf('=== DOOR CROSSING MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Status: Navigating through door\n');
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('Door Center: [%.2f, %.2f]\n', transition_info.door_center(1), transition_info.door_center(2));
fprintf('Exit Target: [%.2f, %.2f]\n', transition_info.exit_position(1), transition_info.exit_position(2));
fprintf('==========================\n');
```

#### 4.4 Elevator Entry Mode
```matlab
fprintf('=== ELEVATOR ENTRY MODE ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Phase: %d - %s\n', elevator_result.phase, elevator_result.status);
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('Elevator Center: [%.1d, %.1d]\n', elevator_metadata.door_center(1), elevator_metadata.door_center(2));
fprintf('===========================\n');
```

#### 4.5 NDT Pose Detection Mode
```matlab
fprintf('=== NDT POSE DETECTION MODE ===\n');
fprintf('** MANUAL CONTROL ACTIVE **\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Autonomous Control: DISABLED\n');
fprintf('Use your manual controls to move the wheelchair\n');
fprintf('Pose is being continuously broadcast in Estimate.m\n');
fprintf('===========================\n');
```

#### 4.6 System Completed/Stopped
```matlab
fprintf('=== SYSTEM COMPLETED ===\n');
fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
fprintf('Status: STOPPED\n');
fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
fprintf('========================\n');
```

### Notes on displayStatusMessage
- **All messages in this function should be kept** - they provide essential runtime feedback
- Uses `clc` to prevent screen clutter (refreshes every loop iteration)
- Format is consistent across all modes
- Position, yaw, and control commands always shown
- Mode-specific information added as appropriate

---

## 5. Recommended Cleanup Actions

### High Priority - Remove Debug Prints
These prints clutter output and provide minimal value in normal operation:

1. **Line 160-162:** SharedControlMode pre-debug
2. **Line 167-186:** Waypoint data type validation (keep error check, remove debug)
3. **Line 190:** Extracted waypoint size debug
4. **Line 460:** NDT mode message (redundant with displayStatusMessage)

### Medium Priority - Consider Upgrading to warning()
These are important messages that could benefit from MATLAB's warning system:

1. **Line 218:** Fallback waypoints warning
2. **Line 225:** Zone loading error

### Keep As-Is
These provide valuable initialization and runtime information:

1. **Lines 146-154:** ROS/Gazebo mode detection
2. **Lines 197, 200:** Multi-room/single-room mode detection
3. **Lines 573, 575:** Elevator door control actions
4. **Line 755:** Multi-room navigation initialization
5. **Line 785:** Multi-room navigation completion
6. **Line 830:** Segment waypoint loading
7. **All displayStatusMessage content (lines 592-659)**

---

## 6. Quick Reference Table

| Line | Function | Message Type | Status | Notes |
|------|----------|--------------|--------|-------|
| 146-154 | Constructor | INFO | ✅ KEEP | ROS/Gazebo mode |
| 160-162 | Constructor | DEBUG | ❌ REMOVE | Verbose debug |
| 167-186 | Constructor | DEBUG | ❌ REMOVE | Verbose debug |
| 190 | Constructor | DEBUG | ❌ REMOVE | Redundant |
| 197 | Constructor | INFO | ✅ KEEP | Multi-room detection |
| 200 | Constructor | INFO | ✅ KEEP | Single-room detection |
| 218 | Constructor | WARNING | ⚠️ UPGRADE | Fallback waypoints |
| 225 | Constructor | WARNING | ⚠️ UPGRADE | Zone error |
| 460 | main() | INFO | ❌ REMOVE | Redundant with displayStatusMessage |
| 573 | pathFollowingControl() | INFO | ✅ KEEP | Door control action |
| 575 | pathFollowingControl() | INFO | ✅ KEEP | Door control action |
| 592-659 | displayStatusMessage() | INFO | ✅ KEEP | All runtime status |
| 755 | multiRoomNavigationControl() | INFO | ✅ KEEP | Init message |
| 785 | multiRoomNavigationControl() | INFO | ✅ KEEP | Completion message |
| 830 | loadNextSegmentWaypoints() | INFO | ✅ KEEP | Segment loading |

---

## 7. Future Considerations

### Adding New Print Statements
When adding new print statements to Control.m:

1. **Runtime Status:** Add to `displayStatusMessage()` function, not scattered in main code
2. **Initialization:** Add to constructor with clear `[CONTROL]` prefix
3. **Error/Warning:** Consider using MATLAB's `warning()` or `error()` instead of fprintf
4. **Debug:** Use a debug flag to conditionally enable/disable verbose output

### Debug Flag Pattern
Consider adding a debug property to enable/disable verbose output:

```matlab
% In properties section
properties (Access = public)
    debug_mode = false;  % Set to true for verbose debug output
end

% In code
if obj.debug_mode
    fprintf('[DEBUG] Detailed information...\n');
end
```

### Logging System
For production use, consider replacing fprintf with a proper logging system that supports:
- Log levels (DEBUG, INFO, WARNING, ERROR)
- Log file output
- Timestamp prefixes
- Conditional compilation

---

**End of Reference Document**
