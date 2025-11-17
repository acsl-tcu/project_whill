classdef Control < handle
    properties (Access = public)
        Gazebo = false; % Flag to indicate if running in Gazebo simulation
        elevator_odom_mode = true; % Flag to use odometry mode (local coordinates) vs map mode (global coordinates)

        % Core motion control properties
        v

        % MPC properties
        Vinit
        count
        mu
        mu_v
        sigma
        sigma_v
        DT
        ObsNum
        obs
        reset_flag

        % Path following properties
        target
        target_n
        v_old
        t_old
        ltheta

        Grid_Xlim
        Grid_Ylim
        Grid_Matrix
        Grid_Size
        Cell_Size

        points
        % Bounding boxes from LiDAR object detection
        boundingBoxes
        map
    end
    properties (Constant)
        %% --MPC パラメータ--
        K                   = 21;           % ホライゾン数
        st                  = 0.3;          % ホライゾン間の刻み時間
        SwitchingPoint      = 1;            % ホライゾン数の後ろから何番目で切り替えるか defolt 6
        NP                  = 1000;         % サンプリング数

        R                   = [0.5,0.1];   % 入力の重み (v,omega)  [1.0,3.0]
        W                   = 0;            % 1
        Wo                  = 0;            % 1  0.1

        sigma_0             = 0.08;         % MCのomegaの分散 0.04
        sigma_v0            = 0.10;         % MCのvの分散  0.15

        % Vref                = 0.5;          % 目標速度  2
        % Vref                = 1;
        % wall_penalty1       = 50;           % 壁面制約 (Defolt)
        wall_penalty1       = 10;
        % wall_penalty2       = 10000;
        wall_threshold      = 0.10;

        Inputmode = "switch";
        Resamplingmode = "LVS";

        %% --FPM パラメータ--
        param_FPM = struct( 'eta',      0.5,... % 0.2
            'alpha',    10,...  % 10
            'margin',   0.15,...   % 0.15
            'obs_cost', 1);     % 1000

        %% --車椅子のサイズ情報--
        wheel_width         = 0.65/2;                   % 横幅/2
        wheel_len_rear      = 0.35;                 % 回転中心から後方までの長さ
        wheel_len_front     = 0.76;        % 回転中心から前方までの長さ
        r_wheel             = 0.3;                          % 車椅子半径(円形)

        % r_wid = 0.55/2;                   % 横幅/2
        % r_len_rear = 0.225;                 % 回転中心から後方までの長さ
        % r_len_front = 0.985 - 0.225;        % 回転中心から前方までの長さ
        %% --LiDARの位置及び設置角度
        % 白車椅子
        % L_x         = -0.2
        % L_z         =  1.4
        % L_roll      =  0.0
        % L_pitch     =  0.0
        % L_yaw       =  0.0
        % Gazebo
        L_x         =  0;
        L_z         =  1.4;
        L_roll      =  0.0;
        L_pitch     =  0.0;
        L_yaw       =  0.0;

        %% --Door/Elevator Entry Parameters (enterElevator.m)--
        door_params = struct(...
            'POSITION_TOLERANCE', 0.15, ...          % ±15cm acceptable distance error
            'POSITION_ANGLE_TOLERANCE', 0.087, ...   % ±5 degrees acceptable heading error (radians)
            'CORRECTION_TURN_SPEED', 0.3, ...        % rad/s for correction turns
            'CORRECTION_MOVE_SPEED', 0.4, ...        % m/s for correction movement (slower than entry)
            'TURN_TOLERANCE', deg2rad(1), ...        % radians (1 degree) - when to stop turning
            'TURN_SPEED', 0.1, ...                   % rad/s for Phase 2 turning
            'ANGLE_TOLERANCE', 30, ...               % ±30 degrees cone towards elevator (initial filtering)
            'NARROW_ROI_ANGLE', 4, ...               % ±4 degrees for wheelchair safe passage (critical ROI)
            'DOOR_HEIGHT_MIN', 0.5, ...              % Minimum height (avoid floor)
            'DOOR_HEIGHT_MAX', 1.7, ...              % Maximum door height
            'MIN_POINTS_THRESHOLD', 5, ...           % Minimum points needed for analysis
            'DEPTH_THRESHOLD', 0.3, ...              % Points must be this much deeper than elevator center
            'MOVE_DISTANCE', 2.35, ...               % meters to move into/out of elevator
            'MOVE_SPEED', 0.2 ...                    % m/s for forward/reverse movement
        );
        %%

        animation = [0,0,0];
        c_obstacles    = 10;    %Stationary obstacles
     end
    properties(Constant,Access = private)
        X  = 1;
        Y  = 2;
        Th = 3;
        Trans=1;
        Rot  =2;
    end
    properties
        waypoint
        waypoint_all_segments  % Cell array containing all waypoint segments for multi-room nav
        selectZone
        NoEntryZone
        ZoneNum
        V_ref
        th_target_w
        limit             % MPC limit array (4 x K x NP)
        phaseManager      % PhaseManager object reference (single source of truth for all state)

        % Multi-room navigation properties
        multiRoomNavState  % Navigation state struct (from executeMultiRoomNavigation)
        multiRoomEnabled   % Boolean flag to enable multi-room navigation
        roomDatabasePath   % Path to room_database.json
    end


    methods
        %         function obj = Control(dt, Mode, FolderPath,sensor,autoware)
        function obj = Control(~, dt, mode ,rgtNum, FolderPath,sensor,autoware,phaseManager)
            % obj.wall = repmat([-0.5 8 -3 3],[size(obj.waypoint,1),1]);
            % Set Gazebo flag based on mode parameter from main_astar.m
            % mode = 2: Gazebo simulation, mode = 3: Real experiment
            fprintf('=== ROS INITIALIZATION CHECK ===\n');
            if mode == 2
                obj.Gazebo = true;
                fprintf('Mode %d detected - Setting obj.Gazebo = true (Gazebo simulation)\n', mode);
            else
                obj.Gazebo = false;
                fprintf('Mode %d detected - Setting obj.Gazebo = false (real system/experiment)\n', mode);
            end
            fprintf('=================================\n');
            
            % Store PhaseManager reference
            obj.phaseManager = phaseManager;

            % Get waypoints from PhaseManager (path planning now done in Estimate.m)
            % Initialize empty waypoints - will be loaded when user selects mode and planning completes
            obj.waypoint = [];  % Empty until first segment is loaded
            obj.waypoint_all_segments = {};  % Empty cell array
            obj.V_ref = 0.5;  % Default velocity until waypoints are loaded (will be regenerated)
            obj.multiRoomEnabled = false;
            fprintf('[CONTROL] Waiting for mode selection and path planning...\n');
            
            % Initialize zones with empty defaults - will be set when waypoints load
            obj.selectZone = [];
            obj.NoEntryZone = [];
            obj.ZoneNum = [];

            %初期化
            obj.v_old = 0.5;
            obj.t_old = 0.2;
            % PhaseManager already stored at line 157

            % Initialize multi-room navigation (disabled by default)
            obj.multiRoomEnabled = false;
            obj.multiRoomNavState = struct();
            obj.multiRoomNavState.initialized = false;
            obj.roomDatabasePath = fullfile(fileparts(mfilename('fullpath')), ...
                                             '../../MultiRoomNav/room_database.json');

            obj.Vinit = rand();
            NamedConst = findAttrValue(obj,'Constant');
            obj.target_n = ones(obj.K,obj.NP)*2;
            obj.target = zeros(2,obj.K,obj.NP);
            obj.limit = zeros(4,obj.K,obj.NP);
            % obj.abc = get_abc(obj);
            obj.ltheta = get_ltheta(obj);

            % Initialize empty - will be generated when waypoints are loaded
            obj.th_target_w = [];

            obj.count = 1;
            obj.mu = zeros(obj.K,obj.NP);
            obj.mu_v = 0.5 * ones(1,obj.NP);  % Default velocity 0.5 m/s
            obj.sigma = repmat(obj.sigma_0,obj.K,obj.NP);
            obj.sigma_v = repmat(obj.sigma_v0,1,obj.NP);

            obj.DT = repmat(obj.st,obj.K,1);

            % obj.DT(1:obj.K/2,1) = dt;         % 謎

            %             obj.px = zeros(3,obj.K,obj.NP);
            obj.reset_flag = 0;

            LP.x     = obj.L_x;
            LP.z     = obj.L_z;
            LP.roll  = obj.L_roll;
            LP.pitch = obj.L_pitch;
            LP.yaw   = obj.L_yaw;

            %% 車椅子を近似する点を作成
            obj.points = gpuArray(gen_vehicle_points(obj.wheel_width,obj.wheel_len_rear,obj.wheel_len_front,[3,2]));

            %% 占有格子図の準備 (map loaded in main.m and stored in PhaseManager)
            obj.map         = phaseManager.occupancyMap;
            obj.Grid_Xlim   = gpuArray(phaseManager.occupancyMap.XWorldLimits);
            obj.Grid_Ylim   = gpuArray(phaseManager.occupancyMap.YWorldLimits);
            obj.Grid_Matrix = gpuArray(getOccupancy(phaseManager.occupancyMap));
            obj.Grid_Size   = gpuArray(size(obj.Grid_Matrix));
            obj.Cell_Size   = gpuArray(1/phaseManager.occupancyMap.Resolution);
            % 値の範囲をProbabilitySaturationから[0-1]へマッピング
            obj.Grid_Matrix = (obj.Grid_Matrix-phaseManager.occupancyMap.ProbabilitySaturation(1))/(phaseManager.occupancyMap.ProbabilitySaturation(2)-phaseManager.occupancyMap.ProbabilitySaturation(1));



            %% settingを保存
            % NamedConst.dt = obj.dt;
            NamedConst.autoware         = autoware;
            NamedConst.sensor           = sensor;
            NamedConst.param_FPM        = obj.param_FPM;
            NamedConst.waypoint         = obj.waypoint;  % First segment only (for backwards compat)
            NamedConst.waypoint_all_segments = obj.waypoint_all_segments;  % ALL segments for plotting
            NamedConst.selectZone       = obj.selectZone;
            NamedConst.NoEntryZone      = obj.NoEntryZone;
            NamedConst.ZoneNum          = obj.ZoneNum;

            NamedConst.wheel_width      = obj.wheel_width;
            NamedConst.wheel_len_rear   = obj.wheel_len_rear;
            NamedConst.wheel_len_front  = obj.wheel_len_front;
            NamedConst.r_wheel          = obj.r_wheel;
            NamedConst.map              = obj.map;

            NamedConst.LP    = LP;



            save(strcat(FolderPath,'/','settings.mat'), 'NamedConst');
            copyfile('./src/Plot/plotResult.m', FolderPath,'f');
            copyfile('./src/Plot/myplotResult.m', FolderPath,'f');
            copyfile('./src/Plot/ShowErrorEllipse2.m', FolderPath,'f');
            %%
            % obj.Selectmode = mode;
            % if obj.Selectmode == 2 % For Gazebo
            %     obj = ROS_Setting(obj);
            % end
        end
        function result = main(obj, Plant)
            tic
            %% Get data from Estimator (PhaseManager, LiDAR, bounding boxes)
            % Get PhaseManager reference from Estimate.m (passed via Plant.local)
            if isfield(Plant, 'local') && isfield(Plant.local, 'phaseManager')
                obj.phaseManager = Plant.local.phaseManager;
            end

            % Extract data from estimator
            if isfield(Plant, 'local') && isfield(Plant.local, 'boundingBoxes')
                obj.boundingBoxes = Plant.local.boundingBoxes;
            else
                obj.boundingBoxes = {};
            end

            % Extract both local and global xyz data for door detection
            xyz_global = [];
            xyz_local = [];
            if isfield(Plant, 'local')
                if isfield(Plant.local, 'xyz_global')
                    xyz_global = Plant.local.xyz_global;
                end
                if isfield(Plant.local, 'xyz_local')
                    xyz_local = Plant.local.xyz_local;
                end
            end

            % Combine both coordinate systems for elevator function
            lidar_data = struct();
            lidar_data.xyz_global = xyz_global;
            lidar_data.xyz_local = xyz_local;

            %% Initialize door and counter
            % Initialize door (close it) only on first iteration
            if obj.count == 1
                controlElevatorDoor('close');
            end
            obj.count = obj.count + 1;

            %% Transform LiDAR position to rear wheel center position
            % LiDAR位置から後輪間中心位置へ変換
            % Rxyz = eul2rotm([Plant.yaw-obj.L_roll, Plant.pitch-obj.L_pitch, Plant.roll-obj.L_roll], 'ZYX'); % roll pitch yaw
            Rxyz = eul2rotm([Plant.yaw-obj.L_roll, 0, 0], 'ZYX'); % yaw
            XYZ=Rxyz*[-obj.L_x;0;-obj.L_z]+[Plant.X;Plant.Y;Plant.Z];
            Position.X = XYZ(1);
            Position.Y = XYZ(2);
            Position.Z = XYZ(3);
            Position.yaw = Plant.yaw-obj.L_roll;

            %% Predict pedestrian states (6-state prediction for horizon)
            % 歩行者6状態の予測  (状態数, 歩行者数, ホライゾン数)
            % obsnow =[ x y theta v a b]
            if isfield(Plant, 'local') && isfield(Plant.local, 'AllTracks') && isfield(Plant.local.AllTracks, 'xhat') && ~isempty(Plant.local.AllTracks.xhat{1,1})
                obsnow = Plant.local.AllTracks.xhat{1,1};
                obsnum = size(obsnow,2);
            else
                obsnum = 0;
            end
            if obsnum>0
                preobs=zeros(6,obsnum,obj.K);
                t = permute(repmat((0:obj.K-1)' * obj.st,1,obsnum),[3,2,1]);
                preobs(3:6,:,:) = repmat(obsnow(3:6,:),1,1,obj.K);
                preobs(1,:,:) = obsnow(1,:) + preobs(4,:,:).*cos(preobs(3,:,:)).*t;
                preobs(2,:,:) = obsnow(2,:) + preobs(4,:,:).*sin(preobs(3,:,:)).*t;
            else
                preobs=zeros(6,0,obj.K);
            end

            %% Universal path follower and phase management
            % Update universal path follower - IT decides the phase
            % NEW SYSTEM: Use getCurrentPhaseInfo() - queries phase from action sequence
            % NO PARAMETERS: Uses internal PhaseManager state (DRY principle)
            [control_mode, target_info] = obj.phaseManager.getCurrentPhaseInfo();

            %% Load first segment waypoints when mission starts or replans
            % When user selects Mode 1/4, planMission() sets waypoints_need_reload = true
            % This handles both initial planning AND re-selection of modes
            if obj.phaseManager.waypoints_need_reload && obj.phaseManager.current_action_index == 1 && strcmp(control_mode, 'path_following')
                fprintf('[CONTROL] Loading first segment waypoints (new mission planned)...\n');
                obj.loadNextSegmentWaypoints();
                obj.phaseManager.waypoints_need_reload = false;  % Clear flag after loading
            end

            % Calculate goal-related values (only if waypoints exist)
            if ~isempty(obj.waypoint)
                goal_position = obj.waypoint(end, :); % Final waypoint
                current_position = [Position.X, Position.Y];
                goal_distance = norm(current_position - goal_position);
                current_waypoint_idx = obj.target_n(1,1);
            else
                % No waypoints yet - use dummy values
                goal_position = [0, 0];
                current_position = [Position.X, Position.Y];
                goal_distance = 0;
                current_waypoint_idx = 1;
            end

            %% Execute control based on current phase
            % PhaseManager returns the appropriate control mode
            switch control_mode
                case 'path_following'
                    % Normal path following control
                    [U, pu, px, pw, BestCost, BestCostId, uOpt, fval, removed] = obj.pathFollowingControl(Position, preobs);
                    elevator_result = [];

                    % Check if path_follow action is complete (reached last waypoint)
                    % UNIFORM COMPLETION: Same pattern as door_entry and elevator_entry
                    if obj.target_n(1,1) >= size(obj.waypoint, 1)
                        % Reached last waypoint - complete this action
                        obj.phaseManager.completeTransition2();
                        fprintf('[CONTROL] Path follow action completed - advancing to next action\n');

                        % Load next segment waypoints (if next action is path_follow)
                        obj.loadNextSegmentWaypoints();
                    end

                case 'door_entry'
                    % Door entry control
                    door_center = target_info.door_center;
                    exit_position = target_info.exit_position;

                    door_result = enterDoor(current_position, Position.yaw, door_center, exit_position, ...
                                           lidar_data, obj.door_params, 'regular');
                    U = door_result.V;

                    % Report completion to PhaseManager
                    if door_result.completed
                        obj.phaseManager.completeTransition2();  % NEW: Use simpler transition system

                        % Update to next segment's waypoints (refactored method)
                        obj.loadNextSegmentWaypoints();
                    end

                    % Fill empty variables with proper structure for plotting
                    pu = {}; px = {}; pw = {}; BestCost = []; BestCostId = [];
                    uOpt = struct('u', []); % Empty uOpt struct (not empty cell)
                    fval = [];
                    removed = struct('pu', [], 'px', [], 'pw', []); % Empty removed struct
                    elevator_result = [];

                case {'elevator_entry', 'door_detection'}
                    % Elevator entry control (includes door_detection mode for testing)
                    if ~isempty(target_info.door_center)
                        elevator_center = target_info.door_center;
                    else
                        elevator_metadata = LocationMetadata.getLocation('elevator');
                        elevator_center = elevator_metadata.door_center;
                    end

                    % Check for door detection mode (debug mode)
                    door_detection_mode = strcmp(obj.phaseManager.getCurrentPhase(), 'door_detection');

                    elevator_result = obj.executeElevatorEntry(current_position, Position.yaw, lidar_data, door_detection_mode);
                    U = elevator_result.V;

                    % Report completion to PhaseManager
                    if isfield(elevator_result, 'completed') && elevator_result.completed
                        obj.phaseManager.completeTransition2();  % NEW: Use simpler transition system
                        controlElevatorDoor('close');

                        % Update to next segment's waypoints (refactored method)
                        obj.loadNextSegmentWaypoints();
                    end

                    % Fill empty variables with proper structure for plotting
                    pu = {}; px = {}; pw = {}; BestCost = []; BestCostId = [];
                    uOpt = struct('u', []); % Empty uOpt struct (not empty cell)
                    fval = [];
                    removed = struct('pu', [], 'px', [], 'pw', []); % Empty removed struct

                case 'ndt_pose_detection'
                    % NDT Pose Detection Mode - Manual control only
                    fprintf('[CONTROL] NDT Pose Detection mode: Autonomous control disabled - manual control active\n');
                    U = [0; 0]; % Let manual joystick/controls handle movement
                    pu = {}; px = {}; pw = {}; BestCost = []; BestCostId = [];
                    uOpt = struct('u', []); % Empty uOpt struct (not empty cell)
                    fval = [];
                    removed = struct('pu', [], 'px', [], 'pw', []); % Empty removed struct
                    elevator_result = [];

                case 'completed'
                    % Navigation complete - stop
                    U = [0; 0];
                    pu = {}; px = {}; pw = {}; BestCost = []; BestCostId = [];
                    uOpt = struct('u', []); % Empty uOpt struct (not empty cell)
                    fval = [];
                    removed = struct('pu', [], 'px', [], 'pw', []); % Empty removed struct
                    elevator_result = [];

                otherwise
                    % Fallback - stop
                    U = [0; 0];
                    pu = {}; px = {}; pw = {}; BestCost = []; BestCostId = [];
                    uOpt = struct('u', []); % Empty uOpt struct (not empty cell)
                    fval = [];
                    removed = struct('pu', [], 'px', [], 'pw', []); % Empty removed struct
                    elevator_result = [];
            end

            %% Dynamic path replanning (TODO)
            % TODO: Dynamic path replanning from Estimate.m (not yet implemented)

            %% Update PhaseManager with control data and display unified status
            % Build phase-specific data struct based on control mode
            phase_data = struct();
            switch control_mode
                case 'path_following'
                    phase_data.target_waypoint = obj.target_n(1,1);
                    phase_data.total_waypoints = size(obj.waypoint, 1);
                    if ~isempty(BestCost)
                        phase_data.mpc_cost = BestCost;
                    end

                case 'door_entry'
                    if ~isempty(target_info) && isfield(target_info, 'door_center')
                        phase_data.door_center = target_info.door_center;
                        phase_data.door_exit = target_info.exit_position;
                    end

                case 'elevator_entry'
                    if ~isempty(elevator_result)
                        phase_data.elevator_phase = elevator_result.phase;
                        phase_data.elevator_status = elevator_result.status;
                    end

                % Other cases don't need phase-specific data
            end

            % Update PhaseManager with control data
            obj.phaseManager.updateControlData(U, phase_data);

            % Display unified status (called once per loop)
            obj.phaseManager.displayStatus();

            obj.v_old = U(1);
            obj.t_old = Plant.T;

            %% Prepare result output
            result.V = U;
            result.local.Vinit = obj.Vinit;
            % result.local.obstra = {obj.obs};
            % result.local.obstacle = {obstacle};
            result.local.preobs   = {preobs};
            result.local.pu = {pu};
            result.local.px = {px};
            result.local.pw = {pw};
            result.local.BestCost = BestCost;
            result.local.fval = fval;

            % Handle BestCostId indexing for different modes
            if strcmp(control_mode, 'path_following') && ~isempty(BestCostId)
                result.local.Bestpx = {px(:,:,BestCostId)};
                result.local.Bestpu = {pu(:,:,BestCostId)};
            else
                result.local.Bestpx = {};
                result.local.Bestpu = {};
            end

            result.local.uOpt   = {uOpt};
            result.local.Contime   = toc;
            result.local.removed = removed;
            result.local.target_n = obj.target_n(1,1);
            result.local.Position_X = Position.X;
            result.local.Position_Y = Position.Y;
            result.local.Position_yaw = Position.yaw;
            result.local.control_mode = control_mode; % Pass control mode to Estimate (from PhaseManager)
            result.local.BB = {obj.boundingBoxes}; % Save bounding boxes for plotting


        end

        [pu] = GenerateInput(obj)
        [px] = Discretemodel(obj,px,pu)
        %        [pw,remove_sample] = EvaluationPath(obj,px,pu,preobs,target)
        [pw,remove_sapmle] = EvaluationPath_mex(obj,px,pu,preobs,target)
        [Grade,Grade_old,th_min,th_max,GRADE_TRGT,GRADE_ANGL,GRADE_OBS] = FPM_4(obj,x,y,th,obs,obs_now)
        [obj,pw_new] = Normalize(obj,pw)
        [px,pw,pv] = Resampling(obj,pu,pw)
        [uOpt,fval,removed] = clustering(obj,tempobj,pw,pu,px)
%% Elevator Entry Algorithm
        function elevator_result = executeElevatorEntry(obj, current_position, current_yaw, lidar_data, door_detection_mode)
            % Execute elevator entry sequence with door detection and opening
            % This calls the external enterElevator function and handles door opening
            %
            % Inputs:
            %   lidar_data - struct containing both xyz_global and xyz_local coordinate data
            %   door_detection_mode - boolean flag or debug mode (bypass to Phase 1.5)

            
            
            % Use the elevator_odom_mode property from the Control class
            % This can be configured when creating the Control object:
            % - false (default): use global coordinates (map mode) 
            % - true: use local coordinates (odometry mode) for map-independent operation
            
            if nargin < 5
                door_detection_mode = false; % Default: normal elevator entry
            end

            % Get elevator metadata for target_position and door_center parameters
            elevator_metadata = LocationMetadata.getLocation('elevator');
            target_position = elevator_metadata.target_position;  % Phase 1 target position
            door_center = elevator_metadata.door_center;          % Elevator door center

            elevator_result = enterElevator(current_position, current_yaw, door_center, [], lidar_data, obj.Gazebo, obj.elevator_odom_mode, door_detection_mode, obj.door_params, target_position);
            
            % Check if we need to open the door (Phase 2.5 - door verification)
            if isfield(elevator_result, 'phase') && elevator_result.phase == 2.5
                % Check if door is closed and open it
                if isfield(elevator_result, 'door_state') && strcmp(elevator_result.door_state, 'closed')
                    % Open elevator door only in Gazebo simulation
                    if obj.Gazebo
                        controlElevatorDoor('open');
                        fprintf('Control: Opening elevator door for Phase 2.5 verification (Gazebo)\n');
                    else
                        fprintf('Control: Phase 2.5 detected - Real system, no door control needed\n');
                    end
                end
            end
        end


        function [U, pu, px, pw, BestCost, BestCostId, uOpt, fval, removed] = pathFollowingControl(obj, Position, preobs)
            % Path following control using MPC algorithm
            % Contains all the original MPC computation logic
            % Returns all variables needed for result.local

            %% Generating the Input Column
            pu = GenerateInput(obj);

            %% Generation of Predictive Paths
            px_now = [Position.X; Position.Y; Position.yaw];
            pu = gpuArray(pu);
            px = Discretemodel(obj, px_now, pu);

            %% --目標地点の切り替え---------------------------------------------
            tempobj_d.NP        = gpuArray(obj.NP);
            tempobj_d.K         = gpuArray(obj.K);
            tempobj_d.waypoint  = gpuArray(obj.waypoint);
            tempobj_d.target_n  = gpuArray(obj.target_n);
            % px                  = gpuArray(px);
            obj.target_n        = determine_target_location(tempobj_d, px);

            % Update PhaseManager with current target waypoint
            obj.phaseManager.setCurrentTargetWaypoint(obj.target_n(1,1));
            %--------------------------------------------------------------

            tempobj.K               = obj.K;
            tempobj.NP              = obj.NP;
            tempobj.ObsNum          = size(preobs, 2);
            tempobj.R               = obj.R;
            tempobj.W               = obj.W;
            tempobj.Wo              = obj.Wo;
            tempobj.target          = obj.target;
            tempobj.ltheta          = obj.ltheta;

            tempobj.wall_penalty1   = obj.wall_penalty1;

            tempobj.wheel_width     = obj.wheel_width;
            tempobj.wheel_len_front = obj.wheel_len_front;
            tempobj.wheel_len_rear  = obj.wheel_len_rear;

            tempobj.target_n        = obj.target_n;
            tempobj.V_ref           = obj.V_ref;

            tempobj.th_target_w     = obj.th_target_w;
            tempobj.waypoint        = obj.waypoint;

            % 占有格子図
            tempobj.Grid_Xlim       = obj.Grid_Xlim;
            tempobj.Grid_Ylim       = obj.Grid_Ylim;
            tempobj.Grid_Size       = obj.Grid_Size;
            tempobj.Cell_Size       = obj.Cell_Size;

            tempobj.points          = obj.points;

            %% 評価計算
            % Load map object for world coordinate visualization

                % [pw, remove_sample] = EvaluationPath_vec_gpu(tempobj, px, pu, preobs, obj.param_FPM, obj.Grid_Matrix, obj.boundingBoxes, obj.map);

                [pw, remove_sample] = EvaluationPath_vec_gpu(tempobj, px, pu, preobs, obj.param_FPM, obj.Grid_Matrix);
           

            [BestCost, BestCostId] = min(pw);

            pu = gather(pu);
            px = gather(px);

            %% Clustering of Predictive Paths
            [uOpt, fval, removed] = clustering(obj, pw, pu, px, remove_sample);

            %% 統計抽出サンプリング
            %評価値の正規化
            [obj, L_norm] = Normalize(obj, pw);
            %リサンプリング
            [obj.mu, ~, obj.mu_v] = Resampling(obj, pu, L_norm);

            %% Extract control input
            U = uOpt.u(1).u(:,1);
        end

        function [U, pu, px, pw, BestCost, BestCostId, uOpt, fval, removed] = multiRoomNavigationControl(obj, Position, preobs, lidar_data)
            % Multi-room navigation control with door crossings
            % Combines path following and door entry algorithms

            % Add path to MultiRoomNav directory
            addpath(fullfile(fileparts(mfilename('fullpath')), '../../MultiRoomNav'));

            current_position = [Position.X, Position.Y];
            current_yaw = Position.yaw;

            % Initialize on first call
            if ~obj.multiRoomNavState.initialized
                fprintf('[CONTROL] Initializing multi-room navigation...\n');
                % Call HybridPathPlanner (this should be called once externally before switching to this mode)
                % For now, create placeholder state
                obj.multiRoomNavState.initialized = false;
                obj.multiRoomNavState.mode = 'planning';
                obj.multiRoomNavState.status = 'Not initialized - call planMultiRoomPath first';
                U = [0; 0];
                % Return empty variables
                pu = {};
                px = {};
                pw = {};
                BestCost = [];
                BestCostId = [];
                uOpt = {};
                fval = [];
                removed = [];
                return;
            end

            % Execute multi-room navigation
            [nav_state, control_cmd] = executeMultiRoomNavigation(current_position, current_yaw, ...
                                                                   lidar_data, obj.door_params);

            % Update state
            obj.multiRoomNavState = nav_state;
            U = control_cmd.V;

            % Check if completed
            if nav_state.completed
                obj.phaseManager.setPhase('completed');
                fprintf('=== MODE CHANGE: Multi-room navigation COMPLETED ===\n');
            end

            % Return empty variables for MPC-specific outputs
            pu = {};
            px = {};
            pw = {};
            BestCost = [];
            BestCostId = [];
            uOpt = {};
            fval = [];
            removed = [];
        end

        function loadNextSegmentWaypoints(obj)
            % loadNextSegmentWaypoints - Load waypoints for next segment after transition
            %
            % NEW SYSTEM (update2): Load waypoints from current action in action_sequence
            %
            % This method:
            %   1. Gets current action from PhaseManager
            %   2. Extracts waypoints from action (if it's a path_follow action)
            %   3. Updates obj.waypoint
            %   4. Resets target_n to first waypoint
            %   5. Regenerates V_ref speed profile
            %   6. Regenerates target heading array
            %
            % Called after completing door/elevator transitions

            % Get current action from PhaseManager
            current_action = obj.phaseManager.getCurrentAction();

            % Check if action is empty (all actions completed)
            if isempty(current_action) || ~isstruct(current_action) || ~isfield(current_action, 'type')
                fprintf('[CONTROL] No more actions - mission complete\n');
                return;
            end

            % Check if current action is a path_follow action with waypoints
            if strcmp(current_action.type, 'path_follow') && isfield(current_action, 'waypoints')
                new_waypoints = current_action.waypoints;

                if ~isempty(new_waypoints)
                    obj.waypoint = new_waypoints;

                    % Reset target_n to point to first waypoint (correct dimensions: [K, NP])
                    obj.target_n = ones(obj.K, obj.NP);

                    % Regenerate V_ref for new segment waypoints
                    obj.V_ref = zeros(size(obj.waypoint,1), 1) + 0.3;  % 0.5 m/s default
                    if size(obj.waypoint,1) >= 2
                        obj.V_ref(end-1) = 0.1;  % Slow down before goal
                    end
                    if size(obj.waypoint,1) >= 1
                        obj.V_ref(end) = 0.1;      % Stop at goal
                    end

                    % Regenerate target heading array
                    obj.th_target_w = get_th_target(obj.waypoint);

                    % Regenerate mu_v based on first V_ref value
                    obj.mu_v = obj.V_ref(1) * ones(1, obj.NP);

                    % Regenerate selectZone for new waypoints
                    obj.selectZone = ones(size(obj.waypoint, 1), 1);

                    fprintf('[CONTROL] Loaded waypoints from action: [%s] (%d waypoints)\n', ...
                        current_action.type, size(obj.waypoint, 1));
                end
            else
                fprintf('[CONTROL] Current action [%s] has no waypoints to load\n', current_action.type);
            end
        end

    end
end