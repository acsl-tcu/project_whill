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
        % Phase 1: Position Correction
        DOOR_POSITION_TOLERANCE = 0.15   ;       % ±15cm acceptable distance error
        DOOR_POSITION_ANGLE_TOLERANCE = 0.087;   % ±5 degrees acceptable heading error (radians)
        DOOR_CORRECTION_TURN_SPEED = 0.3      ;  % rad/s for correction turns
        DOOR_CORRECTION_MOVE_SPEED = 0.4       ; % m/s for correction movement (slower than entry)
        % Phase 2: Turning towards elevator
        DOOR_TURN_TOLERANCE = 0.1               ;% radians (~6 degrees) - when to stop turning
        DOOR_TURN_SPEED = 0.1;                   % rad/s for Phase 2 turning
        % Phase 2.5: Door Detection
        DOOR_ANGLE_TOLERANCE = 30;               % ±30 degrees cone towards elevator (initial filtering)
        DOOR_NARROW_ROI_ANGLE = 4 ;              % ±4 degrees for wheelchair safe passage (critical ROI)
        DOOR_HEIGHT_MIN = 0.5      ;             % Minimum height (avoid floor)
        DOOR_HEIGHT_MAX = 1.7       ;            % Maximum door height
        DOOR_MIN_POINTS_THRESHOLD = 5;           % Minimum points needed for analysis
        DOOR_DEPTH_THRESHOLD = 0.3    ;          % Points must be this much deeper than elevator center
        DOOR_FIXED_ELEVATOR_DISTANCE = 2.2;      % Fixed elevator center distance in odometry mode (meters)
        % Phase 3 & 5: Movement into/out of elevator
        DOOR_MOVE_DISTANCE = 2.4     ;           % meters to move into elevator (reduced by 10cm to avoid back wall)
        DOOR_MOVE_SPEED = 0.2       ;          % m/s for forward/reverse movement
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
        sharedControlMode  % Shared control mode handle object
        phaseManager      % PhaseManager object reference (from Estimate.m)

        % Multi-room navigation properties
        multiRoomNavState  % Navigation state struct (from executeMultiRoomNavigation)
        multiRoomEnabled   % Boolean flag to enable multi-room navigation
        roomDatabasePath   % Path to room_database.json
    end


    methods
        %         function obj = Control(dt, Mode, FolderPath,sensor,autoware)
        function obj = Control(~, dt, mode ,rgtNum, FolderPath,sensor,autoware,sharedControlMode)
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
            
            % Get waypoints from SharedControlMode (path planning now done in Estimate.m)
            % Waypoints are now stored as cell array {segment1, segment2, ...}
            if sharedControlMode.hasWaypoints()
                % DEBUG: Check SharedControlMode object state BEFORE calling getWaypoints
                fprintf('\n[CONTROL PRE-DEBUG] BEFORE getWaypoints() call:\n');
                fprintf('  sharedControlMode class: %s\n', class(sharedControlMode));
                fprintf('  sharedControlMode is handle: %d\n', isa(sharedControlMode, 'handle'));

                waypoint_cell_array = sharedControlMode.getWaypoints();

                % DEBUG: Check waypoint data received in Control
                fprintf('\n[CONTROL DEBUG] Waypoint data from SharedControlMode:\n');
                fprintf('  Type: %s\n', class(waypoint_cell_array));
                fprintf('  Is cell: %d\n', iscell(waypoint_cell_array));
                fprintf('  Length: %d\n', length(waypoint_cell_array));
                fprintf('  Size: %s\n', mat2str(size(waypoint_cell_array)));
                fprintf('  ndims: %d\n', ndims(waypoint_cell_array));

                % Check if it's actually a numeric array instead of cell array
                if ~iscell(waypoint_cell_array)
                    fprintf('  *** ERROR: waypoint_cell_array is NOT a cell array! ***\n');
                    fprintf('  *** It is a %s with value: %s ***\n', class(waypoint_cell_array), mat2str(waypoint_cell_array));
                end

                % Only loop if it's actually a cell array
                if iscell(waypoint_cell_array)
                    for seg = 1:length(waypoint_cell_array)
                        fprintf('  Segment %d: %dx%d waypoints\n', seg, size(waypoint_cell_array{seg}, 1), size(waypoint_cell_array{seg}, 2));
                    end
                end
                fprintf('\n');

                % Extract first segment for initial control
                obj.waypoint = waypoint_cell_array{1};  % Nx2 matrix for Control to use
                fprintf('[CONTROL DEBUG] Extracted obj.waypoint: %dx%d\n\n', size(obj.waypoint, 1), size(obj.waypoint, 2));

                % Store ALL waypoint segments for plotting (to be saved to NamedConst)
                obj.waypoint_all_segments = waypoint_cell_array;

                % Detect multi-room mode automatically
                if length(waypoint_cell_array) > 1
                    fprintf('Control: Multi-room mode AUTO-DETECTED (%d segments)\n', length(waypoint_cell_array));
                    obj.multiRoomEnabled = true;
                else
                    fprintf('Control: Single-room mode (%d waypoints)\n', size(obj.waypoint, 1));
                    obj.multiRoomEnabled = false;
                end

                % Generate V_ref based on first segment waypoints
                obj.V_ref = zeros(size(obj.waypoint,1), 1) + 0.5;  % 0.5 m/s default
                if size(obj.waypoint,1) >= 2
                    obj.V_ref(end-5:end-1) = 0.3;  % Slow down before goal
                end
                if size(obj.waypoint,1) >= 1
                    obj.V_ref(end) = 0.2;      % Stop at goal
                end
            else
                % Fallback to simple default waypoints if none available
                obj.waypoint = [28.9, 6; 30, 12]; % Basic start->elevator path
                obj.waypoint_all_segments = {obj.waypoint}; % Single segment
                obj.V_ref = [0.5; 0]; % Default velocities
                obj.multiRoomEnabled = false;
                fprintf('Control: Using fallback waypoints (%d points)\n', size(obj.waypoint, 1));
            end
            
            % Get zones from original path setting (kept separate for now)
            try
                [~, obj.selectZone,obj.NoEntryZone,obj.ZoneNum,~]=PathSetting_original;
            catch ME
                fprintf('Control: Failed to get zones (%s), using defaults\n', ME.message);
                obj.selectZone = ones(size(obj.waypoint, 1), 1);
                obj.NoEntryZone = [];
                obj.ZoneNum = [];
            end

            %初期化
            obj.v_old = 0.5;
            obj.t_old = 0.2;
            obj.sharedControlMode = sharedControlMode;  % Store shared control mode object
            obj.phaseManager = [];  % Will be set by Estimate.m via Plant.local

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

            obj.th_target_w =get_th_target(obj.waypoint);

            obj.count = 1;
            obj.mu = zeros(obj.K,obj.NP);
            obj.mu_v = obj.V_ref(1)*ones(1,obj.NP);
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

            %% 占有格子図の準備
            load map2.mat map;
            obj.map         = map;
            obj.Grid_Xlim   = gpuArray(map.XWorldLimits);
            obj.Grid_Ylim   = gpuArray(map.YWorldLimits);
            obj.Grid_Matrix = gpuArray(getOccupancy(map));
            obj.Grid_Size   = gpuArray(size(obj.Grid_Matrix));
            obj.Cell_Size   = gpuArray(1/map.Resolution);
            % 値の範囲をProbabilitySaturationから[0-1]へマッピング
            obj.Grid_Matrix = (obj.Grid_Matrix-map.ProbabilitySaturation(1))/(map.ProbabilitySaturation(2)-map.ProbabilitySaturation(1));



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
            NamedConst.map              = map;

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

            % Initialize door (close it) only on first iteration
            if obj.count == 1
                controlElevatorDoor('close');
            end
            obj.count = obj.count + 1;
            %% LiDAR位置から後輪間中心位置へ変換
            % Rxyz = eul2rotm([Plant.yaw-obj.L_roll, Plant.pitch-obj.L_pitch, Plant.roll-obj.L_roll], 'ZYX'); % roll pitch yaw
            Rxyz = eul2rotm([Plant.yaw-obj.L_roll, 0, 0], 'ZYX'); % yaw
            XYZ=Rxyz*[-obj.L_x;0;-obj.L_z]+[Plant.X;Plant.Y;Plant.Z];
            Position.X = XYZ(1);
            Position.Y = XYZ(2);
            Position.Z = XYZ(3);
            Position.yaw = Plant.yaw-obj.L_roll;

            %%--歩行者6状態の予測  (状態数, 歩行者数, ホライゾン数)-----
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
            %------------------------------------------------------------------------

            %% State-based control system with universal path follower
            goal_position = obj.waypoint(end, :); % Final waypoint
            current_position = [Position.X, Position.Y];
            goal_distance = norm(current_position - goal_position);
            current_waypoint_idx = obj.target_n(1,1);

            % Update universal path follower - IT decides the phase
            [control_mode, target_info] = obj.phaseManager.update(current_position, current_waypoint_idx);

            % Execute control based on mode returned by PhaseManager
            switch control_mode
                case 'path_following'
                    % Normal path following control
                    [U, pu, px, pw, BestCost, BestCostId, uOpt, fval, removed] = obj.pathFollowingControl(Position, preobs);
                    elevator_result = [];

                case 'door_entry'
                    % Door entry control
                    door_center = target_info.door_center;
                    exit_position = target_info.exit_position;

                    door_result = enterDoor(current_position, Position.yaw, door_center, exit_position, ...
                                           lidar_data, obj.door_params, 'regular');
                    U = door_result.V;

                    % Report completion to PhaseManager
                    if door_result.completed
                        obj.phaseManager.completeTransition();

                        % Update to next segment's waypoints
                        new_waypoints = obj.phaseManager.getCurrentSegmentWaypoints();
                        if ~isempty(new_waypoints)
                            obj.waypoint = new_waypoints;

                            % Reset target_n to point to first waypoint (correct dimensions: [K, NP])
                            obj.target_n = ones(obj.K, obj.NP);

                            % Regenerate V_ref for new segment waypoints
                            obj.V_ref = zeros(size(obj.waypoint,1), 1) + 0.5;  % 0.5 m/s default
                            if size(obj.waypoint,1) >= 2
                                obj.V_ref(end-1) = 0.5;  % Slow down before goal
                            end
                            if size(obj.waypoint,1) >= 1
                                obj.V_ref(end) = 0.5;      % Stop at goal
                            end

                            % Regenerate target heading array
                            obj.th_target_w = get_th_target(obj.waypoint);

                            fprintf('[CONTROL] Loaded new segment waypoints (%d waypoints)\n', size(obj.waypoint, 1));
                        end
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
                        obj.phaseManager.completeTransition();
                        controlElevatorDoor('close');

                        % Update to next segment's waypoints
                        new_waypoints = obj.phaseManager.getCurrentSegmentWaypoints();
                        if ~isempty(new_waypoints)
                            obj.waypoint = new_waypoints;

                            % Reset target_n to point to first waypoint (correct dimensions: [K, NP])
                            obj.target_n = ones(obj.K, obj.NP);

                            % Regenerate V_ref for new segment waypoints
                            obj.V_ref = zeros(size(obj.waypoint,1), 1) + 0.5;  % 0.5 m/s default
                            if size(obj.waypoint,1) >= 2
                                obj.V_ref(end-1) = 0.5;  % Slow down before goal
                            end
                            if size(obj.waypoint,1) >= 1
                                obj.V_ref(end) = 0.5;      % Stop at goal
                            end

                            % Regenerate target heading array
                            obj.th_target_w = get_th_target(obj.waypoint);

                            fprintf('[CONTROL] Loaded new segment waypoints (%d waypoints)\n', size(obj.waypoint, 1));
                        end
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

            % Check for updated waypoints from Estimate.m (dynamic replanning) - only when flagged
            if obj.sharedControlMode.areWaypointsUpdated()
                waypoint_cell_array = obj.sharedControlMode.getWaypoints();

                % Extract first segment
                obj.waypoint = waypoint_cell_array{1};

                % Reset target_n to point to first waypoint (correct dimensions: [K, NP])
                obj.target_n = ones(obj.K, obj.NP);

                % Update multi-room mode detection
                if length(waypoint_cell_array) > 1
                    obj.multiRoomEnabled = true;
                    fprintf('[CONTROL] Updated to multi-room path (%d segments)\n', length(waypoint_cell_array));
                else
                    obj.multiRoomEnabled = false;
                    fprintf('[CONTROL] Updated to single-room path (%d waypoints)\n', size(obj.waypoint, 1));
                end

                % Regenerate V_ref for new waypoints (same logic as constructor)
                obj.V_ref = zeros(size(obj.waypoint,1), 1) + 0.5;  % 0.5 m/s default
                if size(obj.waypoint,1) >= 2
                    obj.V_ref(end-1) = 0.5;  % Slow down before goal
                end
                if size(obj.waypoint,1) >= 1
                    obj.V_ref(end) = 0.5;      % Stop at goal
                end

                % Regenerate target heading array
                obj.th_target_w = get_th_target(obj.waypoint);

                % Clear the update flag
                obj.sharedControlMode.clearWaypointUpdateFlag();
            end
            
            % Display status message for current mode
            obj.displayStatusMessage(Position, goal_distance, U, elevator_result);

            obj.v_old = U(1);
            obj.t_old = Plant.T;

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
        function door_params = getDoorParams(obj)
            % Build door_params struct from constant properties
            % This allows easy modification of parameters without changing enterElevator calls
            door_params = struct();
            % Phase 1: Position Correction
            door_params.POSITION_TOLERANCE = obj.DOOR_POSITION_TOLERANCE;
            door_params.POSITION_ANGLE_TOLERANCE = obj.DOOR_POSITION_ANGLE_TOLERANCE;
            door_params.CORRECTION_TURN_SPEED = obj.DOOR_CORRECTION_TURN_SPEED;
            door_params.CORRECTION_MOVE_SPEED = obj.DOOR_CORRECTION_MOVE_SPEED;
            % Phase 2: Turning towards elevator
            door_params.TURN_TOLERANCE = obj.DOOR_TURN_TOLERANCE;
            door_params.TURN_SPEED = obj.DOOR_TURN_SPEED;
            % Phase 2.5: Door Detection
            door_params.ANGLE_TOLERANCE = obj.DOOR_ANGLE_TOLERANCE;
            door_params.NARROW_ROI_ANGLE = obj.DOOR_NARROW_ROI_ANGLE;
            door_params.DOOR_HEIGHT_MIN = obj.DOOR_HEIGHT_MIN;
            door_params.DOOR_HEIGHT_MAX = obj.DOOR_HEIGHT_MAX;
            door_params.MIN_POINTS_THRESHOLD = obj.DOOR_MIN_POINTS_THRESHOLD;
            door_params.DEPTH_THRESHOLD = obj.DOOR_DEPTH_THRESHOLD;
            door_params.FIXED_ELEVATOR_DISTANCE = obj.DOOR_FIXED_ELEVATOR_DISTANCE;
            % Phase 3 & 5: Movement into/out of elevator
            door_params.MOVE_DISTANCE = obj.DOOR_MOVE_DISTANCE;
            door_params.MOVE_SPEED = obj.DOOR_MOVE_SPEED;
        end

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

            elevator_result = enterElevator(current_position, current_yaw, door_center, [], lidar_data, obj.Gazebo, obj.elevator_odom_mode, door_detection_mode, obj.getDoorParams(), target_position);
            
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

        function displayStatusMessage(obj, Position, goal_distance, U, elevator_result)
            % Display status message based on current control mode
            % Clears previous output to avoid message stacking

            clc;  % Clear command window

            % Get current phase from PhaseManager
            current_phase = obj.phaseManager.getCurrentPhase();

            if strcmp(current_phase, 'multi_room_navigation')
                % Multi-room navigation mode status
                fprintf('=== MULTI-ROOM NAVIGATION MODE ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                if isfield(obj.multiRoomNavState, 'mode')
                    fprintf('Nav Mode: %s\n', obj.multiRoomNavState.mode);
                    fprintf('Status: %s\n', obj.multiRoomNavState.status);
                    if isfield(obj.multiRoomNavState, 'current_segment')
                        fprintf('Segment: %d/%d\n', obj.multiRoomNavState.current_segment, ...
                                length(obj.multiRoomNavState.waypoint_segments));
                    end
                end
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
                fprintf('===================================\n');

            elseif any(strcmp(current_phase, {'path_following', 'floor_change'}))
                % Path following mode status
                fprintf('=== PATH FOLLOWING MODE ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                fprintf('Goal Distance: %.2f m\n', goal_distance);
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
                fprintf('Target Waypoint: %d/%d\n', obj.target_n(1,1), size(obj.waypoint,1));
                fprintf('==========================\n');

            elseif strcmp(current_phase, 'door_entry')
                % Door entry/crossing mode status
                fprintf('=== DOOR CROSSING MODE ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                fprintf('Status: Navigating through door\n');
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));

                % Display door center if available from PhaseManager
                transition_info = obj.phaseManager.getTransitionInfo();
                if ~isempty(transition_info) && isfield(transition_info, 'door_center')
                    fprintf('Door Center: [%.2f, %.2f]\n', transition_info.door_center(1), transition_info.door_center(2));
                end
                if ~isempty(transition_info) && isfield(transition_info, 'exit_position')
                    fprintf('Exit Target: [%.2f, %.2f]\n', transition_info.exit_position(1), transition_info.exit_position(2));
                end
                fprintf('==========================\n');

            elseif any(strcmp(current_phase, {'elevator_entry', 'door_detection'}))
                % Elevator entry mode status
                elevator_metadata = LocationMetadata.getLocation('elevator');
                fprintf('=== ELEVATOR ENTRY MODE ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                if nargin >= 5 && ~isempty(elevator_result)
                    fprintf('Phase: %d - %s\n', elevator_result.phase, elevator_result.status);
                end
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
                fprintf('Elevator Center: [%.1d, %.1d]\n', elevator_metadata.door_center(1), elevator_metadata.door_center(2));
                fprintf('===========================\n');

            elseif strcmp(current_phase, 'ndt_pose_detection')
                % NDT Pose Detection mode status
                fprintf('=== NDT POSE DETECTION MODE ===\n');
                fprintf('** MANUAL CONTROL ACTIVE **\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                fprintf('Autonomous Control: DISABLED\n');
                fprintf('Use your manual controls to move the wheelchair\n');
                fprintf('Pose is being continuously broadcast in Estimate.m\n');
                fprintf('===========================\n');

            else
                % Completed/stopped state status
                fprintf('=== SYSTEM COMPLETED ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                fprintf('Status: STOPPED\n');
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
                fprintf('========================\n');
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

            % Update SharedControlMode with current target waypoint
            obj.sharedControlMode.setCurrentTargetWaypoint(obj.target_n(1,1));
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

    end
end