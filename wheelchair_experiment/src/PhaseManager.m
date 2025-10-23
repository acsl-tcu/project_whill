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
    %   phaseManager = PhaseManager(sharedControlMode);
    %   phaseManager.setWaypoints(waypoint_segments, room_sequence, door_info);
    %   [control_mode, target_info] = phaseManager.update(position, current_waypoint_idx);

    properties
        sharedControlMode       % Reference to SharedControlMode object

        % Phase state
        current_phase           % Current phase name string
        previous_phase          % Previous phase (for history/debugging)
        phase_data              % Struct with phase-specific data
        is_first_use            % Boolean: track if this is the first time any phase is set

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
        multi_room_enabled      % Boolean: is multi-room mode active?
        at_door                 % Boolean: currently at a door crossing?
        current_door            % Current door index (1, 2, 3, ...)
        total_doors             % Total number of doors
        door_centers            % Array of door center positions
        door_exit_positions     % Array of door exit positions

        % Action Sequence Planner (NEW)
        action_sequence         % Cell array of action structs defining the mission plan
        current_action_index    % Current action being executed (index into action_sequence)
        action_sequence_active  % Boolean: is action sequence mode active?
    end

    methods
        function obj = PhaseManager(sharedControlMode)
            % Constructor - initialize universal path follower
            %
            % Input:
            %   sharedControlMode - SharedControlMode object (required)

            if nargin < 1 || isempty(sharedControlMode)
                error('PhaseManager requires a SharedControlMode object');
            end

            obj.sharedControlMode = sharedControlMode;
            obj.current_phase = 'path_following';
            obj.previous_phase = '';
            obj.phase_data = struct();
            obj.is_first_use = true;  % This is the first time using the system

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

            % Initialize legacy multi-room properties
            obj.multi_room_enabled = false;
            obj.at_door = false;
            obj.current_door = 0;
            obj.total_doors = 0;
            obj.door_centers = [];
            obj.door_exit_positions = [];

            % Initialize action sequence planner
            obj.action_sequence = {};
            obj.current_action_index = 0;
            obj.action_sequence_active = false;

            fprintf('[PHASE MANAGER] Universal Path Follower Initialized\n');
        end

        function enableMultiRoom(obj, waypoint_segments, room_sequence, door_info)
            % Enable multi-room navigation mode
            %
            % Inputs:
            %   waypoint_segments - Cell array of Nx2 waypoint matrices
            %   room_sequence - Cell array of room ID strings
            %   door_info - Struct with fields:
            %               - door_centers: Mx2 array of door center positions
            %               - door_exit_positions: Mx2 array of door exit positions

            obj.multi_room_enabled = true;
            obj.waypoint_segments = waypoint_segments;
            obj.room_sequence = room_sequence;

            % Extract door information from struct
            if isfield(door_info, 'door_centers')
                obj.door_centers = door_info.door_centers;
            else
                obj.door_centers = [];
            end

            if isfield(door_info, 'door_exit_positions')
                obj.door_exit_positions = door_info.door_exit_positions;
            else
                obj.door_exit_positions = [];
            end

            obj.total_segments = length(waypoint_segments);
            obj.total_doors = length(room_sequence) - 1;
            obj.current_segment = 1;
            obj.current_door = 0;
            obj.at_door = false;

            % Start in path_following mode
            obj.setPhase('path_following');

            fprintf('[PHASE MANAGER] Multi-room navigation enabled\n');
            fprintf('  Segments: %d\n', obj.total_segments);
            fprintf('  Doors: %d\n', obj.total_doors);
            fprintf('  Room sequence: %s\n', strjoin(room_sequence, ' → '));
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
                    obj.at_door = false;
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

        function checkTransitions(obj, current_position, current_waypoint_index, total_waypoints)
            % Check if phase transitions are needed
            %
            % This is the main transition logic dispatcher
            %
            % Inputs:
            %   current_position - [x, y] current position
            %   current_waypoint_index - Index of current target waypoint
            %   total_waypoints - Total number of waypoints in current segment

            if obj.multi_room_enabled
                % Multi-room navigation transitions
                obj.checkMultiRoomTransitions(current_position, current_waypoint_index, total_waypoints);
            else
                % Single-room navigation transitions
                obj.checkSingleRoomTransitions(current_position, current_waypoint_index, total_waypoints);
            end
        end

        function checkMultiRoomTransitions(obj, current_position, current_waypoint_index, total_waypoints)
            % Check transitions for multi-room navigation
            %
            % NOTE: Multi-room navigation is now handled by executeMultiRoomNavigation
            % which manages its own state machine internally.
            % This function is kept for backward compatibility but not actively used.
            %
            % State machine (legacy, not used):
            %   path_following → (segment complete) → completed

            switch obj.current_phase
                case 'path_following'
                    % Check if reached end of current segment
                    if current_waypoint_index >= total_waypoints
                        % Segment complete - goal reached
                        obj.setPhase('completed');
                        fprintf('[PHASE] Segment complete - GOAL REACHED!\n');
                    end

                case 'completed'
                    % Stay in completed state
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
            % Get waypoints for current segment
            %
            % Returns empty if not in multi-room mode or invalid segment

            if ~obj.multi_room_enabled
                waypoints = [];
                return;
            end

            if obj.current_segment > 0 && obj.current_segment <= length(obj.waypoint_segments)
                waypoints = obj.waypoint_segments{obj.current_segment};
            else
                waypoints = [];
            end
        end

        function [door_center, exit_position] = getCurrentDoorInfo(obj)
            % Get current door information
            %
            % Returns empty arrays if not at a door

            if ~obj.at_door || obj.current_door <= 0 || obj.current_door > size(obj.door_centers, 1)
                door_center = [];
                exit_position = [];
                return;
            end

            door_center = obj.door_centers(obj.current_door, :);
            exit_position = obj.door_exit_positions(obj.current_door, :);
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

        function [control_mode, target_info] = update(obj, current_position, current_waypoint_idx)
            % Universal path follower update - main interface
            %
            % This is the main method that should be called every control loop.
            % It handles:
            %   - Segment transitions
            %   - Door/elevator detection
            %   - Control mode selection (MPC, enterDoor, enterElevator)
            %
            % Inputs:
            %   current_position - [x, y] current wheelchair position
            %   current_waypoint_idx - Index of current target waypoint from Control.m
            %
            % Outputs:
            %   control_mode - String: 'path_following', 'door_entry', 'elevator_entry', 'completed'
            %   target_info - Struct with target information:
            %       .type - 'waypoint', 'door', or 'elevator'
            %       .position - Target position [x, y]
            %       .door_center - (for doors/elevators) Door center [x, y]
            %       .exit_position - (for doors) Exit position [x, y]
            %       .door_type - (for doors) 'door' or 'elevator'

            % Initialize output
            control_mode = obj.current_phase;
            target_info = struct();
            target_info.type = 'waypoint';
            target_info.position = [];
            target_info.door_center = [];
            target_info.exit_position = [];
            target_info.door_type = '';

            % Special modes that bypass normal path following logic
            if any(strcmp(obj.current_phase, {'door_detection', 'ndt_pose_detection'}))
                % Return immediately without path following logic
                return;
            end

            % Track waypoint progress within current segment
            obj.current_waypoint_local = current_waypoint_idx;

            % Update total waypoints for current segment
            if obj.current_segment <= length(obj.waypoint_segments)
                waypoints = obj.waypoint_segments{obj.current_segment};
                obj.total_waypoints_segment = size(waypoints, 1);
            end

            % Check if we need to handle a transition (door/elevator)
            if obj.at_transition && ~obj.transition_completed
                % Currently at a transition point
                target_info = obj.handleTransition(current_position, target_info);
                control_mode = obj.current_phase;
                return;
            end

            % Check if current segment is complete
            if obj.current_waypoint_local >= obj.total_waypoints_segment
                % Segment complete - check if there are more segments
                if obj.current_segment < obj.total_segments
                    % Move to next segment (requires door/elevator crossing)
                    obj.startTransition(current_waypoint_idx);

                    % Populate target_info immediately (fixes missing door_center bug)
                    target_info = obj.handleTransition(current_position, target_info);

                    control_mode = obj.current_phase;
                else
                    % Last segment complete - check final goal type
                    % IMPORTANT: Only trigger final elevator entry ONCE (not if already completed)
                    if strcmp(obj.current_phase, 'completed')
                        % Already completed - stay in completed state
                        control_mode = 'completed';
                        target_info.type = 'completed';
                    elseif strcmp(obj.final_goal_type, 'elevator')
                        % Final goal is elevator entry - initiate final elevator maneuver
                        obj.at_transition = true;
                        obj.current_transition = obj.current_transition + 1;
                        obj.transition_completed = false;
                        obj.setPhase('elevator_entry');

                        % Populate target_info for final elevator entry
                        target_info = obj.handleTransition(current_position, target_info);
                        control_mode = 'elevator_entry';

                        fprintf('[PATH FOLLOWER] Last segment complete - initiating final elevator entry\n');
                    else
                        % Final goal is room - mission accomplished immediately
                        obj.setPhase('completed');
                        control_mode = 'completed';
                        target_info.type = 'completed';

                        fprintf('[PATH FOLLOWER] Last segment complete - mission accomplished (room goal)\n');
                    end
                end
                return;
            end

            % Normal path following
            control_mode = 'path_following';
            target_info.type = 'waypoint';

            % Get current segment waypoints
            if obj.total_segments > 0 && obj.current_segment <= length(obj.waypoint_segments)
                waypoints = obj.waypoint_segments{obj.current_segment};
                if ~isempty(waypoints) && current_waypoint_idx <= size(waypoints, 1)
                    target_info.position = waypoints(current_waypoint_idx, :);
                end
            end
        end

        function startTransition(obj, current_waypoint_idx)
            % Start a transition (door or elevator crossing)
            %
            % Called when a segment is complete and we need to cross a door/elevator

            obj.at_transition = true;
            obj.current_transition = obj.current_transition + 1;
            obj.transition_completed = false;

            % Determine transition type from door_info
            if obj.current_transition <= length(obj.door_info)
                transition = obj.door_info(obj.current_transition);

                if strcmp(transition.type, 'elevator')
                    obj.setPhase('elevator_entry');
                    fprintf('[PATH FOLLOWER] Starting elevator entry (transition %d/%d)\n', ...
                            obj.current_transition, obj.total_transitions);
                else
                    obj.setPhase('door_entry');
                    fprintf('[PATH FOLLOWER] Starting door entry (transition %d/%d)\n', ...
                            obj.current_transition, obj.total_transitions);
                end
            else
                % No transition info - default to elevator (backward compatibility)
                obj.setPhase('elevator_entry');
                fprintf('[PATH FOLLOWER] Starting transition %d (default: elevator)\n', obj.current_transition);
            end
        end

        function target_info = handleTransition(obj, current_position, target_info)
            % Handle active transition (door or elevator crossing)
            %
            % This is called when at_transition = true
            %
            % IMPORTANT: Returns modified target_info (MATLAB pass-by-value)

            if obj.current_transition <= length(obj.door_info)
                transition = obj.door_info(obj.current_transition);

                % Populate target_info for Control.m
                target_info.type = transition.type;
                target_info.door_center = transition.center;
                target_info.exit_position = transition.exit;
                target_info.door_type = transition.type;
            else
                % Fallback - no transition info available
                target_info.type = 'elevator';
                target_info.door_center = []; % Will use default from LocationMetadata
                target_info.exit_position = [];
                target_info.door_type = 'elevator';
            end
        end

        function completeTransition(obj)
            % Mark current transition as complete and move to next segment
            %
            % This should be called by Control.m when enterDoor/enterElevator returns completed=true

            obj.transition_completed = true;
            obj.at_transition = false;

            % Move to next segment
            obj.current_segment = obj.current_segment + 1;
            obj.current_waypoint_local = 1; % Reset to first waypoint of new segment

            if obj.current_segment <= obj.total_segments
                % Update segment waypoint count
                waypoints = obj.waypoint_segments{obj.current_segment};
                obj.total_waypoints_segment = size(waypoints, 1);

                % Return to path following
                obj.setPhase('path_following');
                fprintf('[PATH FOLLOWER] Transition complete - now in segment %d/%d\n', ...
                        obj.current_segment, obj.total_segments);
            else
                % All segments complete
                obj.setPhase('completed');
                fprintf('[PATH FOLLOWER] All segments complete - navigation finished!\n');
            end
        end

        function setWaypointsUniversal(obj, waypoint_segments, room_sequence, door_info_struct, final_goal_type)
            % Set waypoints for universal path follower
            %
            % Inputs:
            %   waypoint_segments - Cell array of Nx2 waypoint matrices
            %   room_sequence - Cell array of room ID strings (can be empty for single-room)
            %   door_info_struct - Struct array with fields:
            %       .type - 'door' or 'elevator'
            %       .center - [x, y] door/elevator center
            %       .exit - [x, y] exit position after passing
            %   final_goal_type - (Optional) String: 'room' or 'elevator'
            %       'room' - mission completes when final waypoint is reached
            %       'elevator' - mission requires final elevator_entry before completion
            %       Default: 'room' (for backward compatibility)

            obj.waypoint_segments = waypoint_segments;
            obj.room_sequence = room_sequence;
            obj.door_info = door_info_struct;

            % Set final goal type (default to 'room' if not provided)
            if nargin >= 5 && ~isempty(final_goal_type)
                obj.final_goal_type = final_goal_type;
            else
                obj.final_goal_type = 'room';  % Backward compatibility
            end

            % Set segment counts
            obj.total_segments = length(waypoint_segments);
            obj.current_segment = 1;
            obj.current_waypoint_local = 1;

            if obj.total_segments > 0
                obj.total_waypoints_segment = size(waypoint_segments{1}, 1);
            else
                obj.total_waypoints_segment = 0;
            end

            % Set transition counts
            if ~isempty(door_info_struct)
                obj.total_transitions = length(door_info_struct);
            else
                obj.total_transitions = 0;
            end

            obj.current_transition = 0;
            obj.at_transition = false;
            obj.transition_completed = false;

            % Determine if multi-room mode
            obj.multi_room_enabled = (obj.total_segments > 1);

            % Start in path_following mode
            obj.setPhase('path_following');

            fprintf('[PATH FOLLOWER] Waypoints loaded:\n');
            fprintf('  Segments: %d\n', obj.total_segments);
            fprintf('  Transitions: %d\n', obj.total_transitions);
            fprintf('  Final Goal Type: %s\n', obj.final_goal_type);
            if ~isempty(room_sequence)
                fprintf('  Rooms: %s\n', strjoin(room_sequence, ' → '));
            end
        end

        function setFinalGoalType(obj, goal_type)
            % Override the final goal type
            %
            % Input:
            %   goal_type - String: 'room' or 'elevator'
            %
            % This is useful when the user wants to force elevator entry at the end
            % regardless of the initial navigation plan

            if ~ismember(goal_type, {'room', 'elevator'})
                error('Invalid goal_type: must be ''room'' or ''elevator''');
            end

            old_type = obj.final_goal_type;
            obj.final_goal_type = goal_type;

            fprintf('[PHASE MANAGER] Final goal type changed: %s → %s\n', old_type, goal_type);
        end

        function printStatus(obj)
            % Print current phase manager status (for debugging)

            fprintf('\n=== PHASE MANAGER STATUS ===\n');
            fprintf('Current Phase: %s\n', obj.current_phase);
            fprintf('First Time Use: %s\n', mat2str(obj.is_first_use));

            fprintf('\n--- Path Follower State ---\n');
            fprintf('Segment: %d/%d\n', obj.current_segment, obj.total_segments);
            fprintf('Waypoint (local): %d/%d\n', obj.current_waypoint_local, obj.total_waypoints_segment);
            fprintf('At Transition: %s\n', mat2str(obj.at_transition));
            if obj.at_transition
                fprintf('Transition: %d/%d (completed: %s)\n', obj.current_transition, ...
                        obj.total_transitions, mat2str(obj.transition_completed));
            end

            if ~isempty(obj.room_sequence)
                fprintf('\n--- Room Sequence ---\n');
                fprintf('%s\n', strjoin(obj.room_sequence, ' → '));
            end

            fprintf('===========================\n\n');
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
            fprintf('║         PHASE MANAGER - MISSION PLANNING         ║\n');
            fprintf('╚══════════════════════════════════════════════════╝\n\n');

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
                    fprintf('Manual waypoint mode activated\n');
                    return;  % Skip the rest of planning
                end
            end

            % Option 2: A* pathfinding (multi-room planner)
            % STEP 1: Load room database (required for A* path planning)
            if ~isfield(robot_params, 'room_database_path')
                robot_params.room_database_path = fullfile(fileparts(mfilename('fullpath')), ...
                    '../MultiRoomNav/room_database.json');
            end

            fprintf('STEP 1: Loading room database...\n');
            multiroom_path = fullfile(fileparts(mfilename('fullpath')), '../MultiRoomNav');
            addpath(multiroom_path);

            if ~exist(robot_params.room_database_path, 'file')
                error('Room database not found: %s\nMulti-room planner requires room_database.json', ...
                      robot_params.room_database_path);
            end

            db = RoomDatabase(robot_params.room_database_path);
            room_graph = db.buildGraph();
            fprintf('  ✓ Loaded %d rooms\n\n', length(db.rooms_data));

            % STEP 2: Plan action sequence (high-level blueprint)
            fprintf('STEP 2: Planning action sequence...\n');
            obj.action_sequence = obj.planActionSequence(start_position, goal_type, goal_data, room_graph);
            fprintf('  ✓ Generated %d actions\n\n', length(obj.action_sequence));

            % STEP 3: Generate waypoints for all path_follow actions
            fprintf('STEP 3: Pre-generating waypoints for path_follow actions...\n');
            for i = 1:length(obj.action_sequence)
                action = obj.action_sequence{i};

                if strcmp(action.type, 'path_follow')
                    fprintf('  Action %d: Generating waypoints... ', i);

                    % Generate waypoints using A*
                    [waypoints, ~, ~, ~, ~] = PathSetting_AStar(...
                        action.start_position, action.goal_position, ...
                        robot_params.width, robot_params.length, robot_params.safety_margin);

                    obj.action_sequence{i}.waypoints = waypoints;
                    fprintf('✓ %d waypoints\n', size(waypoints, 1));
                end
            end
            fprintf('\n');

            % STEP 4: Store for backward compatibility with old system
            obj.extractWaypointsFromActions();  % Convert to waypoint_segments format

            fprintf('═══════════════════════════════════════════════════\n');
            fprintf('Mission Planning Complete:\n');
            fprintf('  Actions: %d\n', length(obj.action_sequence));
            fprintf('  Waypoint Segments: %d\n', obj.total_segments);
            fprintf('  Final Goal: %s\n', obj.final_goal_type);
            fprintf('═══════════════════════════════════════════════════\n\n');

            obj.action_sequence_active = true;
        end

        %% ==============================================================
        %  ACTION SEQUENCE PLANNER - New systematic approach
        %  ==============================================================

        function action_sequence = planActionSequence(obj, start_position, goal_type, goal_data, room_graph)
            % planActionSequence - Create systematic action sequence from start to goal
            %
            % This function analyzes the start position, goal, and room connectivity
            % to generate a complete action sequence that the robot should execute.
            %
            % Inputs:
            %   start_position - [x, y] current wheelchair position
            %   goal_type - String: 'elevator', 'room', or 'position'
            %   goal_data - Goal-specific data:
            %       For 'elevator': struct with .center [x,y]
            %       For 'room': string room_id (e.g., 'A', 'B')
            %       For 'position': [x, y] target position
            %   room_graph - (Optional) RoomGraph object with room/door connectivity
            %
            % Outputs:
            %   action_sequence - Cell array of action structs, each with:
            %       .type - 'path_follow', 'door_entry', 'elevator_entry'
            %       .start_room - Starting room ID
            %       .end_room - Ending room ID (for path_follow)
            %       .waypoints - Nx2 waypoint array (for path_follow)
            %       .door_center - [x, y] (for door_entry)
            %       .door_exit - [x, y] (for door_entry)
            %       .elevator_center - [x, y] (for elevator_entry)
            %       .description - Human-readable description
            %
            % Example:
            %   % Start in room A, goal is elevator
            %   goal.center = [27.0, 12.2];
            %   seq = phaseManager.planActionSequence([30, 6], 'elevator', goal, roomGraph);
            %   % Returns: {path_follow_1, door_entry_1, path_follow_2, elevator_entry}

            fprintf('\n=== ACTION SEQUENCE PLANNER ===\n');
            fprintf('Start Position: [%.2f, %.2f]\n', start_position(1), start_position(2));
            fprintf('Goal Type: %s\n', goal_type);

            % Initialize action sequence
            action_sequence = {};

            % Determine start room (find which room contains start_position)
            if nargin >= 5 && ~isempty(room_graph)
                start_room = obj.findRoomAtPosition(start_position, room_graph);
            else
                start_room = 'unknown';
            end

            fprintf('Start Room: %s\n', start_room);

            % Plan based on goal type
            switch goal_type
                case 'elevator'
                    % Goal is to reach elevator
                    elevator_center = goal_data.center;
                    fprintf('Goal: Elevator at [%.2f, %.2f]\n', elevator_center(1), elevator_center(2));

                    % Determine elevator room
                    if nargin >= 5 && ~isempty(room_graph)
                        elevator_room = obj.findRoomAtPosition(elevator_center, room_graph);
                    else
                        elevator_room = 'unknown';
                    end

                    fprintf('Elevator Room: %s\n', elevator_room);

                    % Check if we're in the same room as elevator
                    if strcmp(start_room, elevator_room)
                        % Same room - direct path to elevator
                        action_sequence = obj.createSingleRoomElevatorSequence(start_position, elevator_center, start_room);
                    else
                        % Different rooms - multi-room navigation required
                        action_sequence = obj.createMultiRoomElevatorSequence(start_position, elevator_center, ...
                                                                              start_room, elevator_room, room_graph);
                    end

                case 'room'
                    % Goal is to reach a specific room
                    target_room = goal_data;
                    fprintf('Goal: Room %s\n', target_room);

                    if strcmp(start_room, target_room)
                        fprintf('Already in target room - no navigation needed\n');
                        action_sequence = {};
                    else
                        % Navigate from start_room to target_room
                        action_sequence = obj.createRoomToRoomSequence(start_position, start_room, target_room, room_graph);
                    end

                case 'position'
                    % Goal is to reach a specific position
                    target_position = goal_data;
                    fprintf('Goal: Position [%.2f, %.2f]\n', target_position(1), target_position(2));

                    % Determine which room contains target
                    if nargin >= 5 && ~isempty(room_graph)
                        target_room = obj.findRoomAtPosition(target_position, room_graph);
                    else
                        target_room = 'unknown';
                    end

                    if strcmp(start_room, target_room)
                        % Same room - direct path
                        action_sequence = obj.createSingleRoomPathSequence(start_position, target_position, start_room);
                    else
                        % Multi-room path required
                        action_sequence = obj.createMultiRoomPathSequence(start_position, target_position, ...
                                                                          start_room, target_room, room_graph);
                    end

                otherwise
                    error('Invalid goal_type: %s. Must be ''elevator'', ''room'', or ''position''', goal_type);
            end

            % Print action sequence summary
            fprintf('\n--- Generated Action Sequence ---\n');
            for i = 1:length(action_sequence)
                action = action_sequence{i};
                fprintf('%d. [%s] %s\n', i, upper(action.type), action.description);
            end
            fprintf('Total Actions: %d\n', length(action_sequence));
            fprintf('================================\n\n');
        end

        function room_id = findRoomAtPosition(obj, position, room_graph)
            % Find which room contains the given position
            %
            % Returns room ID string, or 'unknown' if not in any room

            if isempty(room_graph)
                room_id = 'unknown';
                return;
            end

            % TODO: Implement room boundary checking
            % For now, return 'unknown' - this will be implemented when integrating with RoomGraph
            room_id = 'unknown';
            fprintf('  [findRoomAtPosition] Position check not yet implemented\n');
        end

        function action_sequence = createSingleRoomElevatorSequence(obj, start_pos, elevator_center, room_id)
            % Create action sequence for elevator in same room
            %
            % Sequence: path_follow → elevator_entry

            action_sequence = {};

            % Action 1: Path follow to elevator approach position
            action1 = struct();
            action1.type = 'path_follow';
            action1.start_room = room_id;
            action1.end_room = room_id;
            action1.start_position = start_pos;  % For A* generation
            action1.goal_position = elevator_center;  % For A* generation
            action1.waypoints = [];  % Will be filled in planMission()
            action1.description = sprintf('Path follow in room %s to elevator', room_id);
            action_sequence{end+1} = action1;

            % Action 2: Enter elevator
            action2 = struct();
            action2.type = 'elevator_entry';
            action2.elevator_center = elevator_center;
            action2.description = 'Enter elevator';
            action_sequence{end+1} = action2;
        end

        function action_sequence = createMultiRoomElevatorSequence(obj, start_pos, elevator_center, start_room, elevator_room, room_graph)
            % Create action sequence for elevator in different room
            %
            % Sequence: path_follow_1 → door → path_follow_2 → ... → elevator_entry

            action_sequence = {};

            % TODO: Use room_graph to find path from start_room to elevator_room
            % For now, create a placeholder sequence
            fprintf('  [Multi-room to elevator] Requires room graph integration\n');

            % Placeholder: assume single door between rooms
            action1 = struct();
            action1.type = 'path_follow';
            action1.start_room = start_room;
            action1.end_room = start_room;
            action1.waypoints = [];
            action1.goal_position = [];  % Door approach position
            action1.description = sprintf('Path follow in room %s to door', start_room);
            action_sequence{end+1} = action1;

            action2 = struct();
            action2.type = 'door_entry';
            action2.door_center = [];  % Will be filled from room_graph
            action2.door_exit = [];
            action2.description = sprintf('Cross door from %s to %s', start_room, elevator_room);
            action_sequence{end+1} = action2;

            action3 = struct();
            action3.type = 'path_follow';
            action3.start_room = elevator_room;
            action3.end_room = elevator_room;
            action3.waypoints = [];
            action3.goal_position = elevator_center;
            action3.description = sprintf('Path follow in room %s to elevator', elevator_room);
            action_sequence{end+1} = action3;

            action4 = struct();
            action4.type = 'elevator_entry';
            action4.elevator_center = elevator_center;
            action4.description = 'Enter elevator';
            action_sequence{end+1} = action4;
        end

        function action_sequence = createSingleRoomPathSequence(obj, start_pos, target_pos, room_id)
            % Create action sequence for target position in same room
            %
            % Sequence: path_follow

            action_sequence = {};

            action1 = struct();
            action1.type = 'path_follow';
            action1.start_room = room_id;
            action1.end_room = room_id;
            action1.waypoints = [];  % Will be computed by A*
            action1.goal_position = target_pos;
            action1.description = sprintf('Path follow in room %s to target', room_id);
            action_sequence{end+1} = action1;
        end

        function action_sequence = createMultiRoomPathSequence(obj, start_pos, target_pos, start_room, target_room, room_graph)
            % Create action sequence for target position in different room
            %
            % Sequence: path_follow_1 → door → path_follow_2 → ...

            action_sequence = {};

            % TODO: Use room_graph to find path
            fprintf('  [Multi-room path] Requires room graph integration\n');

            % Placeholder sequence
            action_sequence = {};
        end

        function action_sequence = createRoomToRoomSequence(obj, start_pos, start_room, target_room, room_graph)
            % Create action sequence to navigate from one room to another
            %
            % Sequence: path_follow_1 → door_1 → path_follow_2 → door_2 → ...

            action_sequence = {};

            % TODO: Use Dijkstra on room_graph to find room sequence
            fprintf('  [Room-to-room] Requires room graph integration\n');

            % Placeholder
            action_sequence = {};
        end

        function printActionSequence(obj)
            % Print current action sequence (for debugging)

            if ~obj.action_sequence_active || isempty(obj.action_sequence)
                fprintf('No active action sequence\n');
                return;
            end

            fprintf('\n=== ACTION SEQUENCE STATUS ===\n');
            fprintf('Active: %s\n', mat2str(obj.action_sequence_active));
            fprintf('Current Action: %d/%d\n', obj.current_action_index, length(obj.action_sequence));
            fprintf('\n');

            for i = 1:length(obj.action_sequence)
                action = obj.action_sequence{i};
                marker = ' ';
                if i == obj.current_action_index
                    marker = '→';
                elseif i < obj.current_action_index
                    marker = '✓';
                end

                fprintf('%s %d. [%s] %s\n', marker, i, upper(action.type), action.description);
            end

            fprintf('==============================\n\n');
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
    end
end
