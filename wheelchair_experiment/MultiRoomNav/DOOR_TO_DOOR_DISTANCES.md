# Door-to-Door Distance Implementation

## Overview

Implemented **actual door-to-door distances** for path cost calculation instead of room center distances.

## What Changed

### Before (Room Center Distance):
```
Edge A↔B cost = norm([15,6] - [4,6]) = 11.0 m
```
- Uses straight line between room centers
- **Path-independent**: same cost regardless of which door you use

### After (Door-to-Door Distance):
```
In Room B, from door A→B to door B→D:
cost = norm([15,4] - [8,6]) = 7.3 m
```
- Uses actual distance between doors **inside the room**
- **Path-dependent**: cost depends on which doors you enter/exit from

---

## Implementation Details

### New Class: `RoomGraphWithDoorDistances.m`

**Key differences from original `RoomGraph.m`:**

1. **State includes entry door:**
   ```matlab
   State = (room_id, entry_from_room)
   Example: "B|A" = "In room B, entered from room A"
   ```

2. **Cost calculation:**
   ```matlab
   if first_room:
       cost = distance from room center to exit door
   else:
       entry_door = door we came through
       exit_door = door we're heading to
       cost = norm(exit_door.position - entry_door.position)
   ```

3. **Returns door sequence:**
   ```matlab
   [room_sequence, door_sequence, total_cost] = findRoomPath('A', 'D')
   % room_sequence = {'A', 'B', 'D'}
   % door_sequence = {'A'}  % Doors we entered FROM
   % total_cost = 11.3 m
   ```

---

## Door-to-Door Distance Tables

### Room A (1 door):
- Only has door to B at [8, 6]
- Cost = distance from center [4, 6] to door = **4.0 m**

### Room B (3 doors):
| From Door | To Door | Position | Distance |
|-----------|---------|----------|----------|
| A [8, 6] | C [22, 6] | Same Y | **14.0 m** |
| A [8, 6] | D [15, 4] | Diagonal | **7.3 m** |
| C [22, 6] | D [15, 4] | Diagonal | **8.6 m** |

### Room C (2 doors):
| From Door | To Door | Position | Distance |
|-----------|---------|----------|----------|
| B [22, 6] | D [26, 4] | Diagonal | **4.5 m** |

### Room D (2 doors):
| From Door | To Door | Position | Distance |
|-----------|---------|----------|----------|
| B [15, 4] | C [26, 4] | Same Y | **11.0 m** |

---

## Path Comparison: A → D

### Path 1: A → B → D (Dijkstra chooses this)
```
Segment 1 (Room A):
  Center [4, 6] → Door A→B [8, 6]
  Distance: 4.0 m

Segment 2 (Room B):
  Door from A [8, 6] → Door to D [15, 4]
  Distance: 7.3 m

TOTAL: 4.0 + 7.3 = 11.3 m ✓
```

### Path 2: A → B → C → D
```
Segment 1 (Room A):
  Center [4, 6] → Door A→B [8, 6]
  Distance: 4.0 m

Segment 2 (Room B):
  Door from A [8, 6] → Door to C [22, 6]
  Distance: 14.0 m

Segment 3 (Room C):
  Door from B [22, 6] → Door to D [26, 4]
  Distance: 4.5 m

TOTAL: 4.0 + 14.0 + 4.5 = 22.5 m
```

**Dijkstra correctly chooses Path 1 (saves 11.2 meters!)**

---

## How to Test

```matlab
clear classes
cd MultiRoomNav

% Run test script
test_door_distances
```

**Expected output:**
1. All door-to-door distances printed
2. Visualization with distance labels
3. Path A → D: **11.3 m** (via B)
4. Path A → C: **18.0 m** (via B)
5. Comparison showing why A → B → D is better than A → B → C → D

---

## Integration with Waypoint Generator

To use door-to-door distances in the interactive generator, replace `RoomGraph()` with `RoomGraphWithDoorDistances()` in `generate_waypoints_interactive.m`.

The rest of the code works the same way!

---

## Advantages

✅ **Accurate costs**: Uses actual distances robot will travel
✅ **Optimizes real path**: Finds truly shortest physical path
✅ **Accounts for room layout**: Different door positions matter
✅ **Better for large rooms**: Room center distance can be misleading

---

## Technical Notes

**State Space:**
- Before: 4 rooms = 4 states
- After: 4 rooms × ~2 entry points each = ~8 states
- Still very efficient for small room graphs!

**Complexity:**
- Same as original Dijkstra: O(R² log R) where R = number of states
- For 4 rooms with 2-3 doors each: ~10 states total → very fast

---

Created: 2025-10-15
Status: ✅ Implemented and tested
