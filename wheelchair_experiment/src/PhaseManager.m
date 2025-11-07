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
        final_goal_type         % String: 'room' or 'elevator' - defines what happens at final waypoint
                                %   'room' - mission completes immediately at final waypoint
                                %   'elevator' - final elevator_entry phase must complete before mission ends

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

            % Initialize final goal type (default: 'room' for backward compatibility)
            obj.final_goal_type = 'room';

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

        function [control_mode, target_info] = update2(obj, current_position, current_waypoint_idx)
            % update2 - Simplified action sequence-based update (NEW SYSTEM)
            %
            % This is a simpler approach that directly uses action_sequence
            % instead of the complex segment/transition tracking.
            %
            % Logic:
            %   1. Check current action type from action_sequence
            %   2. Return appropriate control_mode and target_info
            %   3. Wait for Control.m to call completeTransition() when action is done
            %   4. Advance to next action automatically in completeTransition()
            %
            % Inputs:
            %   current_position - [x, y] current wheelchair position
            %   current_waypoint_idx - Index of current target waypoint from Control.m
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

                    % Populate waypoint target_info
                    target_info.type = 'waypoint';
                    if isfield(current_action, 'waypoints') && ~isempty(current_action.waypoints)
                        % Get target waypoint from action's waypoint array
                        num_waypoints = size(current_action.waypoints, 1);
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

        function planMission(obj, start_position, goal_type, goal_data, robot_params)
            % planMission - Complete mission planning: action sequence + waypoints
            %
            % NEW APPROACH:
            % 1. Plan action sequence FIRST (high-level blueprint)
            % 2. Generate waypoints for each path_follow action
            % 3. Store waypoints in actions
            %
            % Inputs:
            %   start_position - [x, y] starting position
            %   goal_type - 'elevator', 'room', or 'position'
            %   goal_data - Goal-specific data (struct with .center for elevator, etc.)
            %   robot_params - struct with .width, .length, .safety_margin

            fprintf('\n╔══════════════════════════════════════════════════╗\n');
            fprintf('║         PHASE MANAGER - MISSION PLANNING                                          ║\n');
            fprintf('╚═══════════════════════════════════════════════════╝\n\n');

            fprintf('Start: [%.2f, %.2f]\n', start_position(1), start_position(2));
            fprintf('Goal Type: %s\n\n', goal_type);

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
            % Branch based on goal_type for universal planning
            obj.action_sequence = {};

            % Handle different goal types
            if strcmp(goal_type, 'door_detection')
                % Mode 2: Door detection only - single action
                fprintf('STEP 1: Creating door detection action...\n');

                action = struct();
                action.type = 'door_detection';
                action.description = 'Door detection mode';
                obj.action_sequence{end+1} = action;

                fprintf('  ✓ Created door detection action\n\n');

            elseif strcmp(goal_type, 'ndt_pose_detection')
                % Mode 3: NDT pose detection only - single action
                fprintf('STEP 1: Creating NDT pose detection action...\n');

                action = struct();
                action.type = 'ndt_pose_detection';
                action.description = 'NDT pose detection mode';
                obj.action_sequence{end+1} = action;

                fprintf('  ✓ Created NDT pose detection action\n\n');

            elseif strcmp(goal_type, 'navigation_only')
                % Mode 4: Navigation-only mode - reuse existing waypoints, just rebuild action sequence
                fprintf('STEP 1: Rebuilding action sequence for navigation_only mode...\n');
                fprintf('  (Reusing waypoints from constructor - no new path planning)\n\n');

                % Get existing waypoints from obj.waypoint_segments (already set in constructor)
                if isempty(obj.waypoint_segments)
                    error('No waypoints available! Must call planMission with elevator goal first.');
                end

                waypoint_segments = obj.waypoint_segments;
                room_sequence = obj.room_sequence;
                door_info_struct = obj.door_info;

                % Get elevator center from last segment's final waypoint (or from door_info if available)
                if ~isempty(door_info_struct) && length(door_info_struct) > 0 && isfield(door_info_struct(end), 'center')
                    elevator_center = door_info_struct(end).center;
                elseif ~isempty(waypoint_segments)
                    elevator_center = waypoint_segments{end}(end, :);  % Last waypoint of last segment
                else
                    % Fallback to LocationMetadata
                    elevator_metadata = LocationMetadata.getLocation('elevator');
                    elevator_center = elevator_metadata.door_center;
                end

                % STEP 2: Build action sequence using reusable function
                % Since you changed final_goal_type to 'elevator', this will include elevator_entry
                obj.buildActionSequenceFromSegments(waypoint_segments, room_sequence, door_info_struct, 'elevator', elevator_center);

                fprintf('═══════════════════════════════════════════════════\n');
                fprintf('Mission Planning Complete (Navigation-Only → Elevator):\n');
                fprintf('  Actions: %d\n', length(obj.action_sequence));
                fprintf('  Rooms: %s\n', strjoin(room_sequence, ' → '));
                fprintf('  Waypoint Segments: %d\n', obj.total_segments);
                fprintf('  Final Goal: elevator (enters elevator at end)\n');
                fprintf('═══════════════════════════════════════════════════\n\n');

                % Update final goal type to 'elevator' (enters elevator at end)
                obj.final_goal_type = 'elevator';

            elseif strcmp(goal_type, 'elevator')
                % Mode 1: Multi-room path planning with elevator entry
                fprintf('STEP 1: Running multi-room path planner (Dijkstra + A*)...\n');

                multiroom_path = fullfile(fileparts(mfilename('fullpath')), '../MultiRoomNav');
                addpath(multiroom_path);

                % Call generateMultiRoomPath to get waypoint segments, room sequence, and doors
                [~, waypoint_segments, room_sequence, door_info] = generateMultiRoomPath(...
                    start_position, goal_data.center, ...
                    robot_params.width, robot_params.length, robot_params.safety_margin, ...
                    obj.occupancyMap, obj.roomGraph);

                fprintf('  ✓ Generated %d segments across rooms: %s\n\n', ...
                        length(waypoint_segments), strjoin(room_sequence, ' → '));

                % STEP 2: Build action sequence using reusable function
                obj.buildActionSequenceFromSegments(waypoint_segments, room_sequence, door_info, 'elevator', goal_data.center);

                % STEP 3: Store for backward compatibility with old system
                obj.extractWaypointsFromActions();  % Convert to waypoint_segments format

                fprintf('═══════════════════════════════════════════════════\n');
                fprintf('Mission Planning Complete:\n');
                fprintf('  Actions: %d\n', length(obj.action_sequence));
                fprintf('  Rooms: %s\n', strjoin(room_sequence, ' → '));
                fprintf('  Waypoint Segments: %d\n', obj.total_segments);
                fprintf('  Final Goal: %s\n', obj.final_goal_type);
                fprintf('═══════════════════════════════════════════════════\n\n');

            else
                error('Unknown goal_type: %s', goal_type);
            end

            obj.action_sequence_active = true;
            obj.current_action_index = 1;  % Start at first action

            % Print action sequence for debugging
            obj.printActionSequence();
        end

        function buildActionSequenceFromSegments(obj, waypoint_segments, room_sequence, door_info_struct, final_goal_type, elevator_center)
            % buildActionSequenceFromSegments - Convert waypoint segments to action sequence
            %
            % This is a REUSABLE function that builds action_sequence from waypoint data.
            % Used by both mode 1 (elevator) and mode 4 (navigation_only).
            %
            % Inputs:
            %   waypoint_segments - Cell array of Nx2 waypoint matrices
            %   room_sequence - Cell array of room ID strings
            %   door_info_struct - Struct array with .type, .center, .exit
            %   final_goal_type - 'room' or 'elevator'
            %   elevator_center - [x, y] elevator position (only needed if final_goal_type='elevator')
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

            % Add elevator_entry action if final_goal_type is 'elevator'
            if strcmp(final_goal_type, 'elevator')
                elev_action = struct();
                elev_action.type = 'elevator_entry';
                elev_action.elevator_center = elevator_center;
                elev_action.description = 'Enter elevator';
                obj.action_sequence{end+1} = elev_action;
            end

            fprintf('  ✓ Created %d actions (final goal: %s)\n\n', length(obj.action_sequence), final_goal_type);
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
                    obj.final_goal_type = 'elevator';
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
end
