classdef PhaseManager < handle
    % PhaseManager - Universal path follower for wheelchair navigation
    %
    % This class provides a unified path following system that handles:
    %   - Both single-room and multi-room navigation
    %   - Automatic waypoint tracking and segment transitions
    %   - Door/elevator detection and entry dispatch
    %   - Mode management (path_following, door_entry, elevator_entry, etc.)
    %
    % Usage:
    %   phaseManager = PhaseManager(occupancyMap, roomGraph);
    %   phaseManager.planMission(start_position, goal_type, goal_data, robot_params);
    %   [control_mode, target_info] = phaseManager.update(position, current_waypoint_idx);

    properties
        % Phase state
        current_phase           % Current phase name string
        previous_phase          % Previous phase (for history/debugging)
        is_first_use            % Boolean: track if this is the first time any phase is set

        % Map data (loaded once in main_astar.m and passed through system)
        occupancyMap            % Occupancy map object for path planning and visualization
        roomGraph               % RoomGraphWithDoorDistances object for Dijkstra room planning

        % Universal path following state
        current_segment         % Current segment index (1, 2, 3, ...)
        total_segments          % Total number of segments
        current_waypoint_local  % Current waypoint within segment (local index)
        total_waypoints_segment % Total waypoints in current segment

        % Door/elevator crossing state
        at_transition           % Boolean: currently at a door/elevator?
        current_transition      % Current transition index (1, 2, 3, ...)
        total_transitions       % Total number of transitions (doors + elevators)
        transition_completed    % Boolean: track if current transition is done

        % Final goal configuration
        target_action          % String: action type for final mission goal
                               %   'elevator_entry' - navigate to elevator and enter
                               %   'door_detection' - debug door detection only
                               %   'ndt_pose_detection' - manual control with pose broadcast

        % Waypoint and navigation data
        waypoint_segments       % Cell array of waypoint matrices
        room_sequence           % Cell array of room ID strings
        door_info               % Struct with door/elevator information
                                %   .type: 'door' or 'elevator'
                                %   .center: [x, y] position
                                %   .exit: [x, y] position after passing

        % Legacy multi-room properties (kept for backward compatibility)
        multi_room_enabled      % Boolean: is multi-room mode active? (auto-set by total_segments > 1)

        % Action Sequence Planner (NEW)
        action_sequence         % Cell array of action structs defining the mission plan
        current_action_index    % Current action being executed (index into action_sequence)
        action_sequence_active  % Boolean: is action sequence mode active?

        % Status display data (centralized display system)
        estimator_data          % Struct with estimator info (position, sensors, waypoints)
        control_data            % Struct with control info (velocities, phase-specific data)
    end

    methods
        function obj = PhaseManager(occupancyMap, roomGraph)
            % Constructor - initialize universal path follower
            % Inputs:
            %   occupancyMap - Occupancy map object (loaded in main_astar.m)
            %   roomGraph - (Optional) RoomGraphWithDoorDistances object for Dijkstra planning

            obj.current_phase = 'path_following';
            obj.previous_phase = '';
            obj.is_first_use = true;  % This is the first time using the system

            % Store occupancy map for path planning and visualization
            obj.occupancyMap = occupancyMap;

            % Store room graph for Dijkstra planning (optional)
            if nargin >= 2 && ~isempty(roomGraph)
                obj.roomGraph = roomGraph;
                fprintf('[PHASE MANAGER] Room graph loaded with %d rooms\n', roomGraph.rooms.Count);
            else
                obj.roomGraph = [];
                fprintf('[PHASE MANAGER] No room graph provided - Dijkstra planning disabled\n');
            end

            % Initialize universal path following state
            obj.current_segment = 1;
            obj.total_segments = 0;  % Will be set when waypoints are loaded
            obj.current_waypoint_local = 1;
            obj.total_waypoints_segment = 0;

            % Initialize transition state
            obj.at_transition = false;
            obj.current_transition = 0;
            obj.total_transitions = 0;
            obj.transition_completed = false;

            % Initialize target action (default: 'elevator_entry')
            obj.target_action = 'elevator_entry';

            % Initialize data structures
            obj.waypoint_segments = {};
            obj.room_sequence = {};
            obj.door_info = struct('type', {}, 'center', {}, 'exit', {});

            % Initialize legacy multi-room property
            obj.multi_room_enabled = false;

            % Initialize action sequence planner
            obj.action_sequence = {};
            obj.current_action_index = 0;
            obj.action_sequence_active = false;

            % Initialize status display data
            obj.estimator_data = struct();
            obj.control_data = struct();

            fprintf('[PHASE MANAGER] Universal Path Follower Initialized\n');
        end

        function setPhase(obj, new_phase, varargin)
            % Set current phase with logging and state updates
            %
            % Inputs:
            %   new_phase - String: phase name
            %   varargin - Optional phase-specific parameters

            if strcmp(obj.current_phase, new_phase)
                return; % No change needed
            end

            obj.previous_phase = obj.current_phase;
            obj.current_phase = new_phase;

            % CRITICAL FIX: Only mark is_first_use = false when user explicitly requests
            % a mode change (NOT when setting up multi-room navigation initially)
            % This prevents the bug where multi_room_navigation incorrectly marks is_first_use = false
            user_triggered_phases = {'path_following', 'floor_change', 'door_detection', 'ndt_pose_detection', 'elevator_entry'};
            if ismember(new_phase, user_triggered_phases) && ~strcmp(new_phase, 'path_following') && obj.is_first_use
                % User explicitly requested a mode change (not initial setup)
                obj.is_first_use = false;
                fprintf('[PHASE MANAGER] Marking is_first_use = false (user-triggered: %s)\n', new_phase);
            end

            fprintf('[PHASE MANAGER] %s → %s\n', obj.previous_phase, new_phase);

            % Handle phase-specific initialization
            switch new_phase
                case 'path_following'
                    if obj.multi_room_enabled
                        fprintf('  Segment: %d/%d (Room %s)\n', ...
                                obj.current_segment, obj.total_segments, ...
                                obj.room_sequence{obj.current_segment});
                    end

                case 'elevator_entry'
                    fprintf('  Entering elevator mode\n');

                case 'completed'
                    fprintf('  ✓ Navigation completed!\n');
            end
        end

        function completeDoorCrossing(obj)
            % DEPRECATED: This function is no longer used.
            % Multi-room navigation is now handled by executeMultiRoomNavigation.
            % Kept for backward compatibility only.

            fprintf('[PHASE] WARNING: completeDoorCrossing is deprecated and not used\n');
        end

        function checkSingleRoomTransitions(obj, current_position, current_waypoint_index, total_waypoints)
            % Check transitions for single-room navigation
            %
            % State machine:
            %   path_following → (final waypoint reached) → elevator_entry
            %   elevator_entry → (elevator complete) → completed

            switch obj.current_phase
                case 'path_following'
                    % Check if reached final waypoint
                    if current_waypoint_index >= total_waypoints
                        % Transition to elevator entry
                        obj.setPhase('elevator_entry');
                        fprintf('[PHASE] Final waypoint reached\n');
                        fprintf('[PHASE] Transitioning to elevator entry\n');
                    end

                case 'floor_change'
                    % Legacy mode - treat same as path_following
                    if current_waypoint_index >= total_waypoints
                        obj.setPhase('elevator_entry');
                        fprintf('[PHASE] Floor change complete - transitioning to elevator entry\n');
                    end

                case 'elevator_entry'
                    % Elevator entry handled by Control.m
                    % Will call setPhase('completed') when done

                case 'completed'
                    % Stay in completed state
            end
        end

        function phase = getCurrentPhase(obj)
            % Get current phase name
            phase = obj.current_phase;
        end

        function [is_multi, segment, total] = getMultiRoomStatus(obj)
            % Get multi-room navigation status
            %
            % Outputs:
            %   is_multi - Boolean: multi-room enabled?
            %   segment - Current segment index
            %   total - Total number of segments

            is_multi = obj.multi_room_enabled;
            segment = obj.current_segment;
            total = obj.total_segments;
        end

        function waypoints = getCurrentSegmentWaypoints(obj)
            % Get waypoints for current segmenti 
            if obj.current_segment > 0 && obj.current_segment <= length(obj.waypoint_segments)
                waypoints = obj.waypoint_segments{obj.current_segment};
            else
                waypoints = [];
            end
        end

        function transition_info = getTransitionInfo(obj)
            % Get current transition information
            %
            % Returns struct with transition info or empty if not at a transition
            %
            % Outputs:
            %   transition_info - struct with fields:
            %       .door_center - [x, y] door/elevator center
            %       .exit_position - [x, y] exit position
            %       .type - 'door' or 'elevator'
            %   Returns empty struct if not at a transition

            transition_info = struct();

            % Check if we are currently at a transition
            if ~obj.at_transition || obj.current_transition <= 0
                return;
            end

            % Get transition info from door_info array
            if obj.current_transition <= length(obj.door_info)
                transition = obj.door_info(obj.current_transition);
                transition_info.door_center = transition.center;
                transition_info.exit_position = transition.exit;
                transition_info.type = transition.type;
            else
                % No transition info available - return empty
                return;
            end
        end

        function is_first = isFirstTimeUse(obj)
            % Check if this is the first time the system is being used
            % Returns true if user has never triggered a mode change (e.g., 'floor_change')
            is_first = obj.is_first_use;
        end

        function markPathReplanned(obj)
            % Mark that a path replanning has occurred
            % This is called when the user triggers 'floor_change' for the first time
            % to distinguish between:
            %   - First navigation (just use initial waypoints)
            %   - Replanning (recompute waypoints from current position)
            obj.is_first_use = false;
            fprintf('[PHASE MANAGER] Path replanning marked - is_first_use set to false\n');
        end

        %% ==============================================================
        %  UNIVERSAL PATH FOLLOWER - Core Methods
        %  ==============================================================

        function [control_mode, target_info] = getCurrentPhaseInfo(obj)
            % getCurrentPhaseInfo - Get current phase and target info from action sequence
            %
            % This function queries the current action in action_sequence and returns
            % the appropriate control mode and target information.
            %
            % NO PARAMETERS NEEDED - Uses internal PhaseManager state:
            %   - obj.current_action_index (which action we're on)
            %   - obj.current_waypoint_local (current waypoint index, default 1)
            %
            % Logic:
            %   1. Check current action type from action_sequence
            %   2. Return appropriate control_mode and target_info
            %   3. Wait for Control.m to call completeTransition2() when action is done
            %   4. Advance to next action in completeTransition2()
            %
            % Outputs:
            %   control_mode - String: 'path_following', 'door_entry', 'elevator_entry', 'completed'
            %   target_info - Struct with target information for Control.m

            % Initialize output
            target_info = struct();
            target_info.type = 'waypoint';
            target_info.position = [];
            target_info.door_center = [];
            target_info.exit_position = [];
            target_info.door_type = '';

            % Check if action sequence is active
            if ~obj.action_sequence_active || isempty(obj.action_sequence)
                % No action sequence - fallback to 'completed'
                control_mode = 'completed';
                target_info.type = 'completed';
                obj.setPhase('completed');
                return;
            end

            % Check if all actions completed
            if obj.current_action_index > length(obj.action_sequence)
                % All actions done - mission complete
                control_mode = 'completed';
                target_info.type = 'completed';
                obj.setPhase('completed');
                fprintf('[UPDATE2] All actions completed - mission complete!\n');
                return;
            end

            % Get current action
            current_action = obj.action_sequence{obj.current_action_index};

            % Dispatch based on action type
            switch current_action.type
                case 'path_follow'
                    % Path following action
                    control_mode = 'path_following';
                    obj.setPhase('path_following');

                    % Populate waypoint target_info using internal waypoint index
                    target_info.type = 'waypoint';
                    if isfield(current_action, 'waypoints') && ~isempty(current_action.waypoints)
                        % Get target waypoint from action's waypoint array
                        num_waypoints = size(current_action.waypoints, 1);

                        % Use internal waypoint tracking (defaults to 1 on first call)
                        current_waypoint_idx = obj.current_waypoint_local;

                        if current_waypoint_idx <= num_waypoints
                            target_info.position = current_action.waypoints(current_waypoint_idx, :);
                        else
                            % Reached end of waypoints - return last waypoint
                            % Control.m will detect completion and call completeTransition2()
                            target_info.position = current_action.waypoints(end, :);
                        end
                    end

                case 'door_entry'
                    % Door entry action
                    control_mode = 'door_entry';
                    obj.setPhase('door_entry');

                    % Populate door target_info
                    target_info.type = 'door';
                    target_info.door_type = 'door';
                    if isfield(current_action, 'door_center')
                        target_info.door_center = current_action.door_center;
                    end
                    if isfield(current_action, 'door_exit')
                        target_info.exit_position = current_action.door_exit;
                    end

                case 'elevator_entry'
                    % Elevator entry action
                    control_mode = 'elevator_entry';
                    obj.setPhase('elevator_entry');

                    % Populate elevator target_info
                    target_info.type = 'elevator';
                    target_info.door_type = 'elevator';
                    if isfield(current_action, 'elevator_center')
                        target_info.door_center = current_action.elevator_center;
                    else
                        % Fallback to LocationMetadata
                        elevator_metadata = LocationMetadata.getLocation('elevator');
                        target_info.door_center = elevator_metadata.door_center;
                    end
                    target_info.exit_position = []; % No exit for elevator

                case 'door_detection'
                    % Door detection mode (debug/testing)
                    control_mode = 'door_detection';
                    obj.setPhase('door_detection');
                    target_info.type = 'door_detection';

                case 'ndt_pose_detection'
                    % NDT pose detection mode (manual control)
                    control_mode = 'ndt_pose_detection';
                    obj.setPhase('ndt_pose_detection');
                    target_info.type = 'ndt_pose_detection';

                otherwise
                    % Unknown action type - stop
                    control_mode = 'completed';
                    target_info.type = 'completed';
                    obj.setPhase('completed');
                    fprintf('[UPDATE2] WARNING: Unknown action type: %s\n', current_action.type);
            end
        end

        function completeTransition2(obj)
            % completeTransition2 - Mark current action as complete and advance to next
            %
            % This is called by Control.m when an action is completed
            % (e.g., door_entry returns completed=true, elevator_entry returns completed=true)
            %
            % Simpler than completeTransition() - just advances action index

            if ~obj.action_sequence_active || isempty(obj.action_sequence)
                fprintf('[UPDATE2] WARNING: completeTransition2 called but no action sequence active\n');
                return;
            end

            % Mark current action as complete
            fprintf('[UPDATE2] Action %d/%d completed: [%s] %s\n', ...
                obj.current_action_index, length(obj.action_sequence), ...
                obj.action_sequence{obj.current_action_index}.type, ...
                obj.action_sequence{obj.current_action_index}.description);

            % Advance to next action
            obj.current_action_index = obj.current_action_index + 1;

            if obj.current_action_index <= length(obj.action_sequence)
                % More actions to do
                next_action = obj.action_sequence{obj.current_action_index};
                fprintf('[UPDATE2] Starting action %d/%d: [%s] %s\n', ...
                    obj.current_action_index, length(obj.action_sequence), ...
                    next_action.type, next_action.description);
            else
                % All actions complete
                fprintf('[UPDATE2] All actions completed!\n');
                obj.setPhase('completed');
            end
        end

        %% ==============================================================
        %  MISSION PLANNING - Unified waypoint generation + action sequence
        %  ==============================================================

        function planMission(obj, start_position, target_action, goal_data, robot_params)
            % planMission - Complete mission planning: action sequence + waypoints
            %
            % NEW APPROACH:
            % 1. Determine if target_action requires navigation
            % 2. If yes: generate waypoints and build action sequence
            % 3. If no: create single action
            %
            % Inputs:
            %   start_position - [x, y] starting position
            %   target_action - String: 'elevator_entry', 'door_detection', 'ndt_pose_detection'
            %   goal_data - Goal-specific data (struct with .center for elevator, etc.)
            %   robot_params - struct with .width, .length, .safety_margin

            fprintf('\n╔══════════════════════════════════════════════════╗\n');
            fprintf('║         PHASE MANAGER - MISSION PLANNING                                          ║\n');
            fprintf('╚═══════════════════════════════════════════════════╝\n\n');

            fprintf('Start: [%.2f, %.2f]\n', start_position(1), start_position(2));
            fprintf('Target Action: %s\n\n', target_action);

            % Store target action
            obj.target_action = target_action;

            % Check user choice
            user_choice = '2';  % Default to A* planning
            if isfield(robot_params, 'user_choice')
                user_choice = robot_params.user_choice;
            end

            % Handle manual waypoint selection (option 1)
            if strcmp(user_choice, '1')
                fprintf('STEP 1: Opening interactive waypoint selection...\n');
                waypoint_matrix = interactiveWaypointSelection();

                if isempty(waypoint_matrix)
                    fprintf('  No waypoints selected. Falling back to A* pathfinding...\n\n');
                    user_choice = '2';  % Fallback to option 2
                else
                    fprintf('  ✓ Selected %d manual waypoints\n\n', size(waypoint_matrix, 1));
                    % Create simple action sequence with manual waypoints
                    action1 = struct();
                    action1.type = 'path_follow';
                    action1.start_room = 'manual';
                    action1.end_room = 'manual';
                    action1.start_position = start_position;
                    action1.goal_position = goal_data.center;
                    action1.waypoints = waypoint_matrix;
                    action1.description = 'Manual waypoint following';

                    action2 = struct();
                    action2.type = 'elevator_entry';
                    action2.elevator_center = goal_data.center;
                    action2.description = 'Enter elevator';

                    obj.action_sequence = {action1, action2};
                    obj.extractWaypointsFromActions();
                    obj.action_sequence_active = true;
                    obj.current_action_index = 1;  % Start at first action
                    fprintf('Manual waypoint mode activated\n');
                    return;  % Skip the rest of planning
                end
            end

            % Option 2: A* pathfinding (multi-room planner)
            % Clear previous action sequence
            obj.action_sequence = {};

            % Determine if target_action requires navigation
            requires_navigation = PhaseManager.requiresNavigation(target_action);

            if requires_navigation
                % Navigation-based actions (e.g., elevator_entry)
                fprintf('STEP 1: Target action requires navigation\n');

                % Check if we should reuse existing waypoints
                if ~isempty(obj.waypoint_segments)
                    fprintf('  Reusing existing waypoint segments\n\n');
                    waypoint_segments = obj.waypoint_segments;
                    room_sequence = obj.room_sequence;
                    door_info_struct = obj.door_info;
                else
                    % Generate new path
                    fprintf('  Running multi-room path planner (Dijkstra + A*)...\n');

                    multiroom_path = fullfile(fileparts(mfilename('fullpath')), '../MultiRoomNav');
                    addpath(multiroom_path);

                    % Determine goal position based on target_action
                    if strcmp(target_action, 'elevator_entry')
                        if isfield(goal_data, 'center')
                            goal_position = goal_data.center;
                        else
                            elevator_metadata = LocationMetadata.getLocation('elevator');
                            goal_position = elevator_metadata.door_center;
                        end
                    else
                        error('Unknown navigation target_action: %s', target_action);
                    end

                    % Generate multi-room path
                    [~, waypoint_segments, room_sequence, door_info] = generateMultiRoomPath(...
                        start_position, goal_position, ...
                        robot_params.width, robot_params.length, robot_params.safety_margin, ...
                        obj.occupancyMap, obj.roomGraph);

                    fprintf('  ✓ Generated %d segments across rooms: %s\n\n', ...
                            length(waypoint_segments), strjoin(room_sequence, ' → '));

                    % Store waypoint data
                    obj.waypoint_segments = waypoint_segments;
                    obj.room_sequence = room_sequence;
                    obj.door_info = door_info;
                    door_info_struct = door_info;
                end

                % Build action sequence with navigation + target_action
                target_data = PhaseManager.prepareTargetData(target_action, goal_data);
                obj.buildActionSequenceFromSegments(waypoint_segments, room_sequence, ...
                                                   door_info_struct, target_action, target_data);

                % Store for backward compatibility
                obj.extractWaypointsFromActions();

                fprintf('═══════════════════════════════════════════════════\n');
                fprintf('Mission Planning Complete:\n');
                fprintf('  Actions: %d\n', length(obj.action_sequence));
                fprintf('  Rooms: %s\n', strjoin(room_sequence, ' → '));
                fprintf('  Waypoint Segments: %d\n', obj.total_segments);
                fprintf('  Target Action: %s\n', obj.target_action);
                fprintf('═══════════════════════════════════════════════════\n\n');

            else
                % Non-navigation actions (e.g., door_detection, ndt_pose_detection)
                fprintf('STEP 1: Creating single action (no navigation required)\n');

                action = struct();
                action.type = target_action;
                action.description = PhaseManager.getActionDescription(target_action);
                obj.action_sequence{end+1} = action;

                fprintf('  ✓ Created %s action\n\n', target_action);

                fprintf('═══════════════════════════════════════════════════\n');
                fprintf('Mission Planning Complete:\n');
                fprintf('  Actions: %d\n', length(obj.action_sequence));
                fprintf('  Target Action: %s\n', obj.target_action);
                fprintf('═══════════════════════════════════════════════════\n\n');
            end

            obj.action_sequence_active = true;
            obj.current_action_index = 1;  % Start at first action

            % Print action sequence for debugging
            obj.printActionSequence();
        end

        function buildActionSequenceFromSegments(obj, waypoint_segments, room_sequence, door_info_struct, target_action, target_data)
            % buildActionSequenceFromSegments - Convert waypoint segments to action sequence
            %
            % This is a REUSABLE function that builds action_sequence from waypoint data.
            % Used by all navigation-requiring target actions.
            %
            % Inputs:
            %   waypoint_segments - Cell array of Nx2 waypoint matrices
            %   room_sequence - Cell array of room ID strings
            %   door_info_struct - Struct array with .type, .center, .exit
            %   target_action - String: 'elevator_entry', etc.
            %   target_data - Struct with target-specific data (e.g., .elevator_center)
            %
            % Updates:
            %   obj.action_sequence - Built from segments

            fprintf('STEP 2: Building action sequence from path segments...\n');

            % Clear old action sequence
            obj.action_sequence = {};

            % Build path_follow and door_entry actions for each segment
            for seg_idx = 1:length(waypoint_segments)
                % Add path_follow action
                action = struct();
                action.type = 'path_follow';
                if ~isempty(room_sequence) && seg_idx <= length(room_sequence)
                    action.start_room = room_sequence{seg_idx};
                    action.end_room = room_sequence{min(seg_idx+1, length(room_sequence))};
                else
                    action.start_room = 'Unknown';
                    action.end_room = 'Unknown';
                end
                action.waypoints = waypoint_segments{seg_idx};
                action.start_position = waypoint_segments{seg_idx}(1, :);
                action.goal_position = waypoint_segments{seg_idx}(end, :);
                action.description = sprintf('Path follow in room %s (%d waypoints)', ...
                                             action.start_room, size(action.waypoints, 1));
                obj.action_sequence{end+1} = action;

                % Add door_entry action if not last segment
                if seg_idx < length(waypoint_segments) && ~isempty(door_info_struct)
                    door_action = struct();
                    door_action.type = 'door_entry';

                    % Handle both old struct format and new array format
                    if isfield(door_info_struct, 'door_centers')
                        % Old format (from generateMultiRoomPath)
                        door_action.door_center = door_info_struct.door_centers(seg_idx, :);
                        door_action.door_exit = door_info_struct.door_exit_positions(seg_idx, :);
                    else
                        % New format (struct array)
                        door_action.door_center = door_info_struct(seg_idx).center;
                        door_action.door_exit = door_info_struct(seg_idx).exit;
                    end

                    if ~isempty(room_sequence) && seg_idx < length(room_sequence)
                        door_action.description = sprintf('Cross door from %s to %s', ...
                                                          room_sequence{seg_idx}, room_sequence{seg_idx+1});
                    else
                        door_action.description = 'Cross door';
                    end
                    obj.action_sequence{end+1} = door_action;
                end
            end

            % Append target_action at the end
            switch target_action
                case 'elevator_entry'
                    elev_action = struct();
                    elev_action.type = 'elevator_entry';
                    elev_action.elevator_center = target_data.elevator_center;
                    elev_action.description = 'Enter elevator';
                    obj.action_sequence{end+1} = elev_action;

                % Add other navigation-requiring actions here in the future
                otherwise
                    warning('target_action %s not handled in buildActionSequenceFromSegments', target_action);
            end

            fprintf('  ✓ Created %d actions (target action: %s)\n\n', length(obj.action_sequence), target_action);
        end

        function printActionSequence(obj)
            % Print current action sequence (for debugging)

            if isempty(obj.action_sequence)
                fprintf('No action sequence generated\n');
                return;
            end

            fprintf('\n=== ACTION SEQUENCE ===\n');

            for i = 1:length(obj.action_sequence)
                action = obj.action_sequence{i};
                marker = ' ';
                if obj.action_sequence_active && obj.current_action_index == i
                    marker = '→';
                elseif obj.action_sequence_active && i < obj.current_action_index
                    marker = '✓';
                end

                fprintf('%s %d. [%s] %s\n', marker, i, upper(action.type), action.description);
            end

            fprintf('=======================\n\n');
        end

        function extractWaypointsFromActions(obj)
            % extractWaypointsFromActions - Convert action_sequence to waypoint_segments
            %
            % For backward compatibility with old PhaseManager.update() system
            % Extracts waypoints from path_follow actions into waypoint_segments

            obj.waypoint_segments = {};
            obj.room_sequence = {};
            obj.door_info = struct('type', {}, 'center', {}, 'exit', {});

            for i = 1:length(obj.action_sequence)
                action = obj.action_sequence{i};

                if strcmp(action.type, 'path_follow')
                    % Add waypoints to segments
                    obj.waypoint_segments{end+1} = action.waypoints;

                    % Track room
                    if isfield(action, 'start_room') && ~isempty(action.start_room)
                        if isempty(obj.room_sequence) || ~strcmp(obj.room_sequence{end}, action.start_room)
                            obj.room_sequence{end+1} = action.start_room;
                        end
                    end

                elseif strcmp(action.type, 'door_entry')
                    % Store door info
                    door_idx = length(obj.door_info) + 1;
                    obj.door_info(door_idx).type = 'door';
                    obj.door_info(door_idx).center = action.door_center;
                    obj.door_info(door_idx).exit = action.door_exit;

                elseif strcmp(action.type, 'elevator_entry')
                    % Store elevator as final transition
                    door_idx = length(obj.door_info) + 1;
                    obj.door_info(door_idx).type = 'elevator';
                    obj.door_info(door_idx).center = action.elevator_center;
                    obj.door_info(door_idx).exit = [];  % No exit for elevator
                    obj.target_action = 'elevator_entry';
                end
            end

            obj.total_segments = length(obj.waypoint_segments);
            obj.current_segment = 1;
            obj.current_waypoint_local = 1;
            if obj.total_segments > 0
                obj.total_waypoints_segment = size(obj.waypoint_segments{1}, 1);
            end
        end

        %% ==============================================================
        %  ACTION SEQUENCE TRACKING
        %  ==============================================================

        function action = getCurrentAction(obj)
            % Get the current action being executed
            %
            % Outputs:
            %   action - Current action struct with fields:
            %            .type - 'path_follow', 'door_entry', 'elevator_entry'
            %            .description - Human-readable description
            %            (and other action-specific fields)
            %   Returns empty struct if no action sequence or invalid index

            action = struct();

            % Check if action sequence is active
            if ~obj.action_sequence_active || isempty(obj.action_sequence)
                return;
            end

            % Check if current index is valid
            if obj.current_action_index < 1 || obj.current_action_index > length(obj.action_sequence)
                return;
            end

            % Return current action
            action = obj.action_sequence{obj.current_action_index};
        end

        function action_info = getActionSequenceInfo(obj)
            % Get comprehensive action sequence information
            %
            % Outputs:
            %   action_info - Struct with:
            %       .is_active - Boolean: is action sequence mode active?
            %       .current_index - Current action index (0 if not active)
            %       .total_actions - Total number of actions
            %       .current_action - Current action struct (empty if not active)
            %       .progress_percent - Progress percentage (0-100)

            action_info = struct();
            action_info.is_active = obj.action_sequence_active;
            action_info.current_index = obj.current_action_index;
            action_info.total_actions = length(obj.action_sequence);
            action_info.current_action = obj.getCurrentAction();

            if obj.action_sequence_active && action_info.total_actions > 0
                action_info.progress_percent = (obj.current_action_index / action_info.total_actions) * 100;
            else
                action_info.progress_percent = 0;
            end
        end
        %% ==============================================================
        %  CENTRALIZED STATUS DISPLAY SYSTEM
        %  ==============================================================

        function updateEstimatorData(obj, position, yaw_deg, time, waypoint_info, sensor_info)
            % updateEstimatorData - Store estimator data for centralized display
            %
            % Inputs:
            %   position - [X, Y, Z] position in meters
            %   yaw_deg - Yaw angle in degrees
            %   time - Current simulation/experiment time in seconds
            %   waypoint_info - struct with fields:
            %       .current - Current waypoint index
            %       .total - Total number of waypoints
            %       .distance - Distance to final goal in meters
            %   sensor_info - struct with fields:
            %       .lidar_points - Number of LiDAR points
            %       .objects - Number of detected objects
            %       .tracks - Number of active tracks

            obj.estimator_data.position = position;
            obj.estimator_data.yaw_deg = yaw_deg;
            obj.estimator_data.time = time;
            obj.estimator_data.waypoint_current = waypoint_info.current;
            obj.estimator_data.waypoint_total = waypoint_info.total;
            obj.estimator_data.distance_to_goal = waypoint_info.distance;
            obj.estimator_data.lidar_points = sensor_info.lidar_points;
            obj.estimator_data.num_objects = sensor_info.objects;
            obj.estimator_data.num_tracks = sensor_info.tracks;
        end

        function updateControlData(obj, velocities, phase_data)
            % updateControlData - Store control data for centralized display
            %
            % Inputs:
            %   velocities - [v; omega] control commands
            %   phase_data - struct with phase-specific fields:
            %       For 'path_following':
            %           .target_waypoint - Current target waypoint index
            %           .total_waypoints - Total waypoints
            %           .mpc_cost - (optional) MPC cost value
            %       For 'door_entry':
            %           .door_center - [x, y] door center position
            %           .door_exit - [x, y] door exit position
            %       For 'elevator_entry':
            %           .elevator_phase - Elevator phase number
            %           .elevator_status - Elevator status string

            obj.control_data.velocities = velocities;
            obj.control_data.phase_data = phase_data;
        end

        function displayStatus(obj)
            % displayStatus - Unified status display with fixed 25-line format
            %
            % Displays:
            %   - Estimator status (position, sensors, navigation)
            %   - Control status (phase, commands, phase-specific data)
            %   - Action sequence progress
            %
            % Uses clc to clear screen for consistent terminal output

            % Clear screen (clc is more reliable across different MATLAB terminals)
            clc;

            % Get action sequence info for progress display
            action_info = obj.getActionSequenceInfo();

            %% ESTIMATOR STATUS SECTION
            fprintf('╔═══════════════════════════════════════════════╗\n');
            fprintf('║              ESTIMATOR STATUS                         ║\n');
            fprintf('╚═══════════════════════════════════════════════╝\n');

            if isempty(fieldnames(obj.estimator_data))
                fprintf('Position    : No data\n');
                fprintf('Orientation : No data\n');
                fprintf('Navigation  : No data\n');
                fprintf('Sensors     : No data\n');
            else
                fprintf('Position    : X=%7.3f m | Y=%7.3f m | Z=%6.3f m\n', ...
                    obj.estimator_data.position(1), obj.estimator_data.position(2), obj.estimator_data.position(3));
                fprintf('Orientation : Yaw=%6.1f° | Time: %7.2f s\n', ...
                    obj.estimator_data.yaw_deg, obj.estimator_data.time);
                fprintf('Navigation  : Waypoint %3d/%3d | Distance: %6.2f m\n', ...
                    obj.estimator_data.waypoint_current, obj.estimator_data.waypoint_total, obj.estimator_data.distance_to_goal);
                fprintf('Sensors     : LiDAR %4d pts | Objects: %2d | Tracks: %2d\n', ...
                    obj.estimator_data.lidar_points, obj.estimator_data.num_objects, obj.estimator_data.num_tracks);
            end

            fprintf('\n');

            %% CONTROL STATUS SECTION
            fprintf('╔═══════════════════════════════════════════════╗\n');
            fprintf('║              CONTROL STATUS                           ║\n');
            fprintf('╚═══════════════════════════════════════════════╝\n');

            % Get current phase
            current_phase = obj.current_phase;
            fprintf('Phase       : %s\n', current_phase);

            if isempty(fieldnames(obj.control_data))
                fprintf('Command     : No data\n');
                fprintf('Status      : Waiting for control data\n');
            else
                % Display command velocities
                v = obj.control_data.velocities(1);
                omega = obj.control_data.velocities(2);
                fprintf('Command     : V=%6.3f m/s | Ω=%+6.3f rad/s\n', v, omega);

                % DYNAMIC THIRD ROW based on current phase
                phase_data = obj.control_data.phase_data;
                switch current_phase
                    case 'path_following'
                        if isfield(phase_data, 'target_waypoint')
                            if isfield(phase_data, 'mpc_cost')
                                fprintf('Target      : Waypoint %3d/%3d | MPC Cost: %8.2f\n', ...
                                    phase_data.target_waypoint, phase_data.total_waypoints, phase_data.mpc_cost);
                            else
                                fprintf('Target      : Waypoint %3d/%3d\n', ...
                                    phase_data.target_waypoint, phase_data.total_waypoints);
                            end
                        else
                            fprintf('Target      : Waypoint data unavailable\n');
                        end

                    case 'door_entry'
                        if isfield(phase_data, 'door_center')
                            fprintf('Door        : Center [%5.1f, %5.1f] → Exit [%5.1f, %5.1f]\n', ...
                                phase_data.door_center(1), phase_data.door_center(2), ...
                                phase_data.door_exit(1), phase_data.door_exit(2));
                        else
                            fprintf('Door        : Crossing in progress\n');
                        end

                    case 'elevator_entry'
                        if isfield(phase_data, 'elevator_phase')
                            fprintf('Elevator    : Phase %.1f - %s\n', ...
                                phase_data.elevator_phase, phase_data.elevator_status);
                        else
                            fprintf('Elevator    : Entry in progress\n');
                        end

                    case 'door_detection'
                        fprintf('Detection   : Door analysis mode (testing)\n');

                    case 'ndt_pose_detection'
                        fprintf('NDT Mode    : Manual control active (pose broadcast)\n');

                    case 'completed'
                        fprintf('Status      : Mission complete - STOPPED\n');

                    otherwise
                        fprintf('Status      : Unknown phase\n');
                end
            end

            fprintf('\n');

            %% ACTION SEQUENCE PROGRESS SECTION
            fprintf('╔═══════════════════════════════════════════════╗\n');
            fprintf('║              ACTION SEQUENCE PROGRESS                 ║\n');
            fprintf('╚═══════════════════════════════════════════════╝\n');

            if action_info.is_active && ~isempty(fieldnames(action_info.current_action))
                fprintf('Progress    : Action %d/%d (%.1f%% complete)\n', ...
                    action_info.current_index, action_info.total_actions, action_info.progress_percent);
                fprintf('Current     : [%s] %s\n', ...
                    upper(action_info.current_action.type), action_info.current_action.description);
            else
                fprintf('Progress    : No active action sequence\n');
                fprintf('Current     : N/A\n');
            end

            fprintf('════════════════════════════════════════════════════════\n');
        end

        %% Waypoint Management Methods (replaces SharedControlMode)

        function setWaypoints(obj, waypoint_cell_array)
            % Update waypoint segments (cell array)
            % Input: waypoint_cell_array - {segment1, segment2, ...}
            obj.waypoint_segments = waypoint_cell_array;
            obj.total_segments = length(waypoint_cell_array);
            obj.current_segment = 1; % Reset to first segment

            % Update waypoint tracking for first segment
            if ~isempty(waypoint_cell_array) && ~isempty(waypoint_cell_array{1})
                obj.total_waypoints_segment = size(waypoint_cell_array{1}, 1);
            else
                obj.total_waypoints_segment = 0;
            end

            fprintf('[PHASE MANAGER] Waypoints updated: %d segments\n', obj.total_segments);
        end

        function waypoint = getWaypoints(obj)
            % Get the full waypoint cell array
            waypoint = obj.waypoint_segments;
        end

        function has_waypoints = hasWaypoints(obj)
            % Check if waypoints are available
            has_waypoints = ~isempty(obj.waypoint_segments) && length(obj.waypoint_segments) > 0;
        end

        function setCurrentTargetWaypoint(obj, target_n)
            % Update the current target waypoint number (called by Control.m)
            % Input: target_n - current target waypoint index from obj.target_n(1,1)
            obj.current_waypoint_local = target_n;
        end

        function target_n = getCurrentTargetWaypoint(obj)
            % Get the current target waypoint number
            target_n = obj.current_waypoint_local;
        end

    end

    methods (Static, Access = private)
        function requires_nav = requiresNavigation(target_action)
            % Determine if target_action requires navigation to a position
            %
            % Inputs:
            %   target_action - String: 'elevator_entry', 'door_detection', 'ndt_pose_detection'
            %
            % Outputs:
            %   requires_nav - Boolean: true if navigation is required, false otherwise

            switch target_action
                case 'elevator_entry'
                    requires_nav = true;

                case 'door_detection'
                    requires_nav = false;

                case 'ndt_pose_detection'
                    requires_nav = false;

                otherwise
                    error('Unknown target_action: %s', target_action);
            end
        end

        function target_data = prepareTargetData(target_action, goal_data)
            % Prepare action-specific data structure for buildActionSequenceFromSegments
            %
            % Inputs:
            %   target_action - String: action type
            %   goal_data - Struct with goal-specific data
            %
            % Outputs:
            %   target_data - Struct with prepared target data

            target_data = struct();

            switch target_action
                case 'elevator_entry'
                    if isfield(goal_data, 'center')
                        target_data.elevator_center = goal_data.center;
                    else
                        elevator_metadata = LocationMetadata.getLocation('elevator');
                        target_data.elevator_center = elevator_metadata.door_center;
                    end

                otherwise
                    % No additional data needed for other actions
            end
        end

        function description = getActionDescription(target_action)
            % Get human-readable description for target_action
            %
            % Inputs:
            %   target_action - String: action type
            %
            % Outputs:
            %   description - String: human-readable description

            switch target_action
                case 'elevator_entry'
                    description = 'Enter elevator';
                case 'door_detection'
                    description = 'Door detection mode';
                case 'ndt_pose_detection'
                    description = 'NDT pose detection mode';
                otherwise
                    description = sprintf('Unknown action: %s', target_action);
            end
        end
    end
end
