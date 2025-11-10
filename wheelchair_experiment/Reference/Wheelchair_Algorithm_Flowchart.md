# Wheelchair Navigation Algorithm - High Level Flowchart

This flowchart shows the complete execution flow from `main_astar.m` to program completion.

```mermaid
flowchart TB
    Start([main_astar.m START]) --> Init[Initialize System<br/>- Load map2.mat<br/>- Load room_database.json<br/>- Create PhaseManager]

    Init --> CreateObjects[Create Objects<br/>- wheelchairObj<br/>- Estimate<br/>- Control]

    CreateObjects --> PlanInitial[Plan Initial Mission<br/>Estimate Constructor<br/>planMission target_action='elevator_entry']

    PlanInitial --> BuildSequence[Build Action Sequence<br/>- Dijkstra room path<br/>- A* waypoints per segment<br/>- path_follow → door_entry → elevator_entry]

    BuildSequence --> MainLoop[Enter mainLoop]

    MainLoop --> CheckMenu{checkForModeMenu<br/>User input?}

    CheckMenu -->|floor_change| Replan[Replan Mission<br/>planMission 'elevator_entry'<br/>from current position]
    CheckMenu -->|navigation_only| ReuseWaypoints[Reuse Waypoints<br/>planMission 'elevator_entry'<br/>reuse existing segments]
    CheckMenu -->|door_detection| DoorDebug[Door Detection Mode<br/>planMission 'door_detection'<br/>single action]
    CheckMenu -->|ndt_pose| NDTMode[NDT Pose Mode<br/>planMission 'ndt_pose_detection'<br/>manual control]
    CheckMenu -->|No input| ExecCmd[executeCommand]

    Replan --> ExecCmd
    ReuseWaypoints --> ExecCmd
    DoorDebug --> ExecCmd
    NDTMode --> ExecCmd

    ExecCmd --> IntegrateData[integrateData<br/>Get sensor data]

    IntegrateData --> Estimate[exeEstimate<br/>Estimate.main]

    Estimate --> EstimateProcess[Estimator Processing<br/>- LiDAR clustering<br/>- Object detection<br/>- Bounding boxes<br/>- Position update]

    EstimateProcess --> Control[exeControl<br/>Control.main]

    Control --> GetPhase[getCurrentPhaseInfo<br/>Query current action from sequence]

    GetPhase --> SwitchMode{Switch<br/>control_mode}

    SwitchMode -->|path_following| PathFollow[Path Following Control<br/>- MPC/FPM<br/>- Obstacle avoidance<br/>- Waypoint tracking]

    SwitchMode -->|door_entry| DoorEntry[Door Entry Control<br/>- Align to door<br/>- Cross threshold<br/>- Exit to next room]

    SwitchMode -->|elevator_entry| ElevatorEntry[Elevator Entry Control<br/>- Phase 0: Approach<br/>- Phase 1: Align<br/>- Phase 2: Open door<br/>- Phase 2.5: Position correction<br/>- Phase 3: Enter]

    SwitchMode -->|door_detection| DoorDetection[Door Detection Mode<br/>Manual control active<br/>Door analysis only]

    SwitchMode -->|ndt_pose_detection| NDTPose[NDT Pose Mode<br/>Manual control active<br/>Pose broadcast only]

    SwitchMode -->|completed| Completed[Mission Complete<br/>Stop wheelchair]

    PathFollow --> CheckComplete{Action<br/>complete?}
    DoorEntry --> CheckComplete
    ElevatorEntry --> CheckComplete
    DoorDetection --> CheckComplete
    NDTPose --> CheckComplete

    CheckComplete -->|Yes| CompleteTransition[completeTransition2<br/>Advance to next action<br/>loadNextSegmentWaypoints]

    CheckComplete -->|No| UpdateDisplay[updateData<br/>displayData]

    CompleteTransition --> UpdateDisplay

    UpdateDisplay --> CheckEnd{Mission<br/>complete?}

    CheckEnd -->|No| MainLoop
    CheckEnd -->|Yes| EndProcessing[endProcessing<br/>Save data]

    EndProcessing --> PlotResult[myplotResult<br/>Visualize trajectory]

    PlotResult --> End([END])

    Completed --> UpdateDisplay

    style Start fill:#90EE90
    style End fill:#FFB6C1
    style PlanInitial fill:#FFE4B5
    style BuildSequence fill:#FFE4B5
    style GetPhase fill:#87CEEB
    style SwitchMode fill:#DDA0DD
    style PathFollow fill:#F0E68C
    style DoorEntry fill:#F0E68C
    style ElevatorEntry fill:#F0E68C
    style CompleteTransition fill:#98FB98
    style Completed fill:#FFB6C1
```

## Color Legend

- **Green (Start/End):** Program entry and exit points
- **Light Orange:** Mission planning and action sequence generation
- **Light Blue:** Phase management and decision points
- **Purple:** Control mode dispatch (main switch statement)
- **Yellow:** Active control execution phases
- **Light Green:** Transition handling between actions
- **Pink:** Completion states

## Key Components

### 1. Initialization
- Load occupancy map (`map2.mat`)
- Load room database for multi-room navigation
- Create shared PhaseManager instance

### 2. Mission Planning
- Generate action sequence based on `target_action`
- Use Dijkstra for high-level room routing
- Use A* for low-level waypoint generation

### 3. Main Control Loop
- Continuous sensor data acquisition
- Estimation (LiDAR clustering, object detection)
- Control (MPC path following, door entry, elevator entry)
- Real-time display and data logging

### 4. Phase Management
- PhaseManager tracks current action in sequence
- `getCurrentPhaseInfo()` returns appropriate control mode
- `completeTransition2()` advances to next action

### 5. Control Modes
- **path_following:** MPC-based waypoint tracking
- **door_entry:** 4-phase door crossing sequence
- **elevator_entry:** 6-phase elevator entry/exit sequence
- **door_detection:** Debug mode for door sensing
- **ndt_pose_detection:** Manual control with pose broadcast

## File References

- **Main:** `main_astar.m`
- **Main Loop:** `src/Object/@wheelchairObj/mainLoop.m`
- **Execute:** `src/Object/@wheelchairObj/executeCommand.m`
- **Estimate:** `src/Estimator/Estimate.m`
- **Control:** `src/Controller/@Control/Control.m`
- **Phase Manager:** `src/PhaseManager.m`

---

*Generated: 2025-01-27*
*Part of wheelchair_experiment project documentation*
