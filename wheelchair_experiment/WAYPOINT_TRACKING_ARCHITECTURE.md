# Waypoint Tracking Architecture

## Design Philosophy: Single Source of Truth

**Control.m is the SINGLE SOURCE OF TRUTH for `target_n` (current target waypoint)**

This design ensures clear ownership and prevents conflicting state between modules.

## Data Flow

```
┌─────────────────────────────────────────────────────────────────┐
│                         Control.m                                │
│  • Computes target_n via determine_target_location()            │
│  • Updates obj.target_n(1,1) every iteration                     │
│  • Shares target_n with others via SharedControlMode            │
└───────────────────────────┬─────────────────────────────────────┘
                            │
                            │ setCurrentTargetWaypoint(target_n)
                            ↓
┌─────────────────────────────────────────────────────────────────┐
│                    SharedControlMode.m                           │
│  • Stores current_target_n (from Control.m)                      │
│  • Stores total_waypoints (from waypoint array)                  │
│  • Provides isAtFinalWaypoint() helper function                  │
└───────────────────────────┬─────────────────────────────────────┘
                            │
                            │ isAtFinalWaypoint()
                            ↓
┌─────────────────────────────────────────────────────────────────┐
│                         Estimate.m                               │
│  • Reads waypoint status via isAtFinalWaypoint()                 │
│  • Does NOT compute target_n independently                       │
│  • Uses status for mode transitions (path → elevator entry)      │
└─────────────────────────────────────────────────────────────────┘
```

## Implementation Details

### 1. Control.m (Source of Truth)
**File:** `src/Controller/@Control/Control.m:656-659`

```matlab
% Compute current target waypoint using MPC prediction
obj.target_n = determine_target_location(tempobj_d, px);

% Share with other modules via SharedControlMode
obj.sharedControlMode.setCurrentTargetWaypoint(obj.target_n(1,1));
```

**When:** Every iteration during path following mode

### 2. SharedControlMode.m (Data Sharing Layer)
**File:** `src/SharedControlMode.m`

```matlab
function setCurrentTargetWaypoint(obj, target_n)
    % Called by Control.m to update current waypoint
    obj.current_target_n = target_n;
end

function is_final = isAtFinalWaypoint(obj)
    % Check if current waypoint is the final waypoint
    % NOTE: Relies on Control.m updating current_target_n
    if obj.total_waypoints == 0
        is_final = false;
    else
        is_final = (obj.current_target_n >= obj.total_waypoints);
    end
end
```

**Properties:**
- `current_target_n` - Current waypoint index (from Control.m)
- `total_waypoints` - Total number of waypoints (updated when waypoints change)

### 3. Estimate.m (Data Consumer)
**File:** `src/Estimator/Estimate.m:443-448`

```matlab
% Check if wheelchair has reached the final waypoint
% NOTE: Control.m is the SINGLE SOURCE OF TRUTH for target_n
passed_final_waypoint = obj.sharedControlMode.isAtFinalWaypoint();

% Use status for mode transitions
if strcmp(obj.sharedControlMode.getMode(), 'floor_change') && passed_final_waypoint
    obj.sharedControlMode.setMode('elevator_entry');
    fprintf('[ESTIMATE] MODE CHANGE: Final waypoint passed - Switching to ELEVATOR_ENTRY\n');
end
```

**Role:** Estimate.m only READS the waypoint status; it does NOT compute target_n

## Key Benefits

1. **Clear Ownership**
   - Control.m owns waypoint tracking logic
   - No conflicting state between modules
   - Single place to debug waypoint issues

2. **Separation of Concerns**
   - Control.m: Path planning and waypoint targeting
   - Estimate.m: State estimation and mode transitions
   - SharedControlMode: Data sharing interface

3. **Maintainability**
   - Easy to understand data flow
   - Changes to waypoint logic only affect Control.m
   - Other modules use simple getter functions

4. **Performance**
   - No redundant waypoint calculations
   - Efficient: `total_waypoints` cached when waypoints change
   - No repeated `size(waypoint, 1)` calls

## Update Sequence (Normal Operation)

```
Iteration N:
1. Control.m computes target_n = 5
2. Control.m calls setCurrentTargetWaypoint(5)
3. SharedControlMode stores current_target_n = 5
4. Estimate.m calls isAtFinalWaypoint()
5. SharedControlMode returns: 5 >= 10? → false
6. Estimate.m: continue path_following mode

Iteration M (reached final waypoint):
1. Control.m computes target_n = 10
2. Control.m calls setCurrentTargetWaypoint(10)
3. SharedControlMode stores current_target_n = 10
4. Estimate.m calls isAtFinalWaypoint()
5. SharedControlMode returns: 10 >= 10? → true
6. Estimate.m: switch to elevator_entry mode
```

## Waypoint Update Flow (Dynamic Replanning)

```
User requests path replanning:
1. Estimate.m generates new waypoints via PathSetting_AStar
2. Estimate.m calls sharedControlMode.setWaypoints(waypoint)
3. SharedControlMode updates:
   - obj.waypoint = waypoint
   - obj.total_waypoints = size(waypoint, 1)
   - obj.waypoint_updated = true
4. Control.m detects update via areWaypointsUpdated()
5. Control.m loads new waypoints and regenerates V_ref
6. Control.m clears update flag
7. Next iteration: Control.m computes target_n for new waypoints
8. Normal flow continues...
```

## Testing and Verification

### Check 1: Verify Control.m Updates
```matlab
% In Control.m pathFollowingControl()
fprintf('DEBUG: Updated target_n to %d/%d\n', ...
    obj.target_n(1,1), size(obj.waypoint, 1));
```

### Check 2: Verify SharedControlMode State
```matlab
% In Estimate.m
current_target = obj.sharedControlMode.getCurrentTargetWaypoint();
fprintf('DEBUG: SharedControlMode target_n = %d\n', current_target);
```

### Check 3: Verify Final Waypoint Detection
```matlab
% In Estimate.m
is_final = obj.sharedControlMode.isAtFinalWaypoint();
fprintf('DEBUG: At final waypoint? %d (target=%d, total=%d)\n', ...
    is_final, ...
    obj.sharedControlMode.getCurrentTargetWaypoint(), ...
    size(obj.sharedControlMode.getWaypoints(), 1));
```

## Common Issues and Solutions

### Issue: Estimate.m doesn't detect final waypoint
**Cause:** Control.m not updating SharedControlMode
**Solution:** Verify `setCurrentTargetWaypoint()` is called in `pathFollowingControl()`

### Issue: Wrong waypoint count
**Cause:** `total_waypoints` not updated when waypoints change
**Solution:** Ensure `setWaypoints()` updates `total_waypoints`

### Issue: Mode transitions too early/late
**Cause:** Logic using `>=` instead of `==` for final waypoint
**Solution:** Current implementation uses `>=` to handle edge cases (correct)

## Related Files

- `src/Controller/@Control/Control.m` - Source of truth for target_n
- `src/Estimator/Estimate.m` - Consumer of waypoint status
- `src/SharedControlMode.m` - Data sharing layer
- `src/Controller/determine_target_location.m` - Computes target_n

---
*Last Updated: 2025-01-27*
*Architecture designed for clear single-source-of-truth pattern*
