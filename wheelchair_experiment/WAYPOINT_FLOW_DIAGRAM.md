# Waypoint Tracking - Visual Flow Diagram

## High-Level Architecture

```
┌──────────────────────────────────────────────────────────────────────┐
│                      WHEELCHAIR CONTROL SYSTEM                        │
└──────────────────────────────────────────────────────────────────────┘
                                   │
                    ┌──────────────┴──────────────┐
                    │                             │
         ┌──────────▼──────────┐     ┌───────────▼──────────┐
         │    Control.m        │     │    Estimate.m        │
         │  (Path Following)   │     │  (State Estimation)  │
         └──────────┬──────────┘     └───────────┬──────────┘
                    │                            │
                    │ Updates                    │ Reads
                    │ target_n                   │ waypoint status
                    │                            │
         ┌──────────▼────────────────────────────▼──────────┐
         │          SharedControlMode.m                      │
         │  • Stores current_target_n (from Control)         │
         │  • Stores total_waypoints (from waypoints)        │
         │  • Provides isAtFinalWaypoint() helper            │
         └───────────────────────────────────────────────────┘
```

## Detailed Data Flow (Every Iteration)

```
┌─────────────────────────────────────────────────────────────────┐
│ ITERATION START                                                  │
└───────────────────────┬─────────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ 1. Control.m: MPC Path Planning        │
    │    - Generate predicted paths (px)      │
    │    - Evaluate costs                     │
    │    - Determine best path                │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ 2. Control.m: Update Target Waypoint   │
    │    obj.target_n = determine_target_    │
    │                   location(px)          │
    │    // Computes: target_n = 5            │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ 3. Control.m: Share with SharedControlMode             │
    │    obj.sharedControlMode.setCurrentTargetWaypoint(     │
    │        obj.target_n(1,1)                               │
    │    )                                                   │
    │    // Sends: current_target_n = 5                      │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ 4. SharedControlMode: Store State      │
    │    obj.current_target_n = 5            │
    │    obj.total_waypoints = 10            │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ 5. Estimate.m: Check Waypoint Status                   │
    │    passed_final = obj.sharedControlMode.               │
    │                   isAtFinalWaypoint()                  │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ 6. SharedControlMode: Evaluate Status                  │
    │    is_final = (current_target_n >= total_waypoints)    │
    │    is_final = (5 >= 10) → FALSE                        │
    │    // Returns: false                                   │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ 7. Estimate.m: Mode Decision                           │
    │    if floor_change && passed_final:                    │
    │        // FALSE - continue path following              │
    │    else:                                               │
    │        // Continue current mode                        │
    └───────────────────┬────────────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────────────────┐
│ ITERATION END                                                    │
│ • Control outputs: U = [v, omega]                               │
│ • Estimate outputs: state estimates                             │
│ • Mode: path_following                                          │
└──────────────────────────────────────────────────────────────────┘
```

## Final Waypoint Reached Scenario

```
┌─────────────────────────────────────────────────────────────────┐
│ WHEELCHAIR APPROACHING FINAL WAYPOINT                            │
└───────────────────────┬─────────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ Control.m: Detects Final Waypoint      │
    │    obj.target_n = 10 (computed)         │
    │    Total waypoints = 10                 │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ Control.m → SharedControlMode                          │
    │    setCurrentTargetWaypoint(10)                        │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ SharedControlMode: Update State        │
    │    current_target_n = 10               │
    │    total_waypoints = 10                │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ Estimate.m: Check Status                               │
    │    passed_final = isAtFinalWaypoint()                  │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ SharedControlMode: Final Waypoint Check                │
    │    is_final = (10 >= 10) → TRUE                        │
    │    // Returns: true                                    │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ Estimate.m: Mode Transition                            │
    │    if floor_change && passed_final:                    │
    │        setMode('elevator_entry')                       │
    │        fprintf('MODE CHANGE: Switching to ELEVATOR')   │
    └───────────────────┬────────────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────────────────┐
│ MODE CHANGED: ELEVATOR_ENTRY                                     │
│ • Path following complete                                       │
│ • Ready for elevator navigation                                 │
│ • Control.m will use elevator entry algorithm                   │
└──────────────────────────────────────────────────────────────────┘
```

## Dynamic Waypoint Replanning Scenario

```
┌─────────────────────────────────────────────────────────────────┐
│ USER REQUESTS NEW PATH (Floor Change)                           │
└───────────────────────┬─────────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ Estimate.m: Generate New Path          │
    │    waypoint = PathSetting_AStar(...)   │
    │    // 15 new waypoints generated        │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ Estimate.m → SharedControlMode                         │
    │    setWaypoints(waypoint)                              │
    │    // Updates waypoint array                           │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ SharedControlMode: Update Waypoints    │
    │    obj.waypoint = waypoint             │
    │    obj.total_waypoints = 15  // NEW!   │
    │    obj.waypoint_updated = true         │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ Control.m: Detect Waypoint Update                      │
    │    if areWaypointsUpdated():                           │
    │        obj.waypoint = getWaypoints()                   │
    │        regenerate V_ref                                │
    │        clearWaypointUpdateFlag()                       │
    └───────────────────┬────────────────────────────────────┘
                        │
    ┌───────────────────▼────────────────────┐
    │ Control.m: Reset Target Tracking       │
    │    obj.target_n = determine_target_... │
    │    // Starts from waypoint 1 of new    │
    │    // 15-waypoint path                 │
    └───────────────────┬────────────────────┘
                        │
    ┌───────────────────▼────────────────────────────────────┐
    │ Control.m → SharedControlMode                          │
    │    setCurrentTargetWaypoint(1)                         │
    │    // Now tracking: 1/15                               │
    └───────────────────┬────────────────────────────────────┘
                        │
┌───────────────────────▼─────────────────────────────────────────┐
│ REPLANNING COMPLETE                                              │
│ • New path: 15 waypoints                                        │
│ • Current target: 1/15                                          │
│ • Path following continues with new path                        │
└──────────────────────────────────────────────────────────────────┘
```

## Method Call Summary

### Control.m Methods (Called Every Iteration)
```matlab
// In pathFollowingControl():
obj.target_n = determine_target_location(tempobj_d, px);  // Compute target
obj.sharedControlMode.setCurrentTargetWaypoint(obj.target_n(1,1));  // Share
```

### Estimate.m Methods (Called Every Iteration)
```matlab
// In main():
passed_final_waypoint = obj.sharedControlMode.isAtFinalWaypoint();  // Check status
if strcmp(obj.sharedControlMode.getMode(), 'floor_change') && passed_final_waypoint
    obj.sharedControlMode.setMode('elevator_entry');  // Trigger mode change
end
```

### SharedControlMode.m Methods
```matlab
// Setter (called by Control.m)
function setCurrentTargetWaypoint(obj, target_n)
    obj.current_target_n = target_n;
end

// Getter (called by Estimate.m)
function is_final = isAtFinalWaypoint(obj)
    if obj.total_waypoints == 0
        is_final = false;
    else
        is_final = (obj.current_target_n >= obj.total_waypoints);
    end
end

// Waypoint updater (called by Estimate.m during replanning)
function setWaypoints(obj, waypoint)
    obj.waypoint = waypoint;
    obj.total_waypoints = size(waypoint, 1);  // Update total count
    obj.waypoint_updated = true;
end
```

## Timing Diagram (Single Iteration)

```
Time →

Control.m:      ╔════════════════════════════╗
                ║ MPC Computation            ║
                ║ • Generate paths (px)      ║
                ║ • Evaluate costs (pw)      ║
                ║ • Determine target_n       ║
                ╚═══════════════╤════════════╝
                                │
                                │ setCurrentTargetWaypoint(5)
                                ↓
SharedCtrl:                   ┌─────────────┐
                              │ Store:       │
                              │ target_n = 5 │
                              └──────┬───────┘
                                     │
                                     │ isAtFinalWaypoint()
                                     ↓
Estimate.m:                    ╔═══════════════════╗
                              ║ Mode Evaluation    ║
                              ║ • Check waypoint   ║
                              ║ • Decide mode      ║
                              ╚════════════════════╝

Total Time: ~10-50ms (typical)
```

## Key Takeaways

1. **Control.m drives waypoint tracking** - It computes `target_n` every iteration
2. **SharedControlMode is a passive data store** - No computation, just storage and simple checks
3. **Estimate.m consumes waypoint status** - It reads status to make mode decisions
4. **Single source of truth** - Only Control.m modifies `target_n`
5. **Efficient design** - No redundant calculations, cached values

---
*Last Updated: 2025-01-27*
*Visual diagrams for waypoint tracking architecture*
