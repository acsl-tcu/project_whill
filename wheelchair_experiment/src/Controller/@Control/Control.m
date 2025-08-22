classdef Control < handle
    properties (Access = public)
        Gazebo = false; % Flag to indicate if running in Gazebo simulation
        elevator_odom_mode = true; % Flag to use odometry mode (local coordinates) vs map mode (global coordinates)
        TLeng
        NCnt
        Cnt
        Selectmode
        obs_Message
        obs_Topic
        ObstacleNum
        Obstacle_Topic1
        Obstacle_Topic2
        Obstacle_Topic3
        Obstacle_Topic4
        Obstacle_Topic5
        Obstacle_Topic6
        Obstacle_Topic7
        Obstacle_Topic8
        Obstacle_Topic9
        Obstacle_Topic101
        Obstacle_Topic102
        Obstacle_Topic103
        Obstacle_Topic104
        Obstacle_Topic105
        Obstacle_Topic106
        Obstacle_Topic107
        Obstacle_Topic108
        Obstacle_Topic109
        Obstacle_Topic110
        qx1
        qy1
        qz1
        qw1
        qx2
        qy2
        qz2
        qw2
        qx3
        qy3
        qz3
        qw3
        qx4
        qy4
        qz4
        qw4
        qx5
        qy5
        qz5
        qw5
        qx6
        qy6
        qz6
        qw6
        qx7
        qy7
        qz7
        qw7
        qx8
        qy8
        qz8
        qw8
        qx9
        qy9
        qz9
        qw9
        state_L
        obs_state_L
        old_th
        v
        InitialVelocity
        obsL
        obstaclesection
        ObstaclePosX
        ObstaclePosY
        ObstaclePosYAW
        obsYdifferent
        obsk1
        obsk2
        obstaclephi
        obstacler
        obsf1
        obsf2
        cartesian
        referenced

        %以下移植
        Vinit
        count
        mu
        mu_v
        sigma
        sigma_v
        % dt             重複？
        DT
        ObsNum
        obs
        vobs
        VOBS
        %         px
        reset_flag
        lastLPF
        SelectMode        %重複？
        obstacleObj

        target
        limit
        target_n
        abc
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
            'obs_cost', 0);     % 1000

        %% --車椅子のサイズ情報--
        wheel_width         = 0.55/2;                   % 横幅/2
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
        L_x         =  0
        L_z         =  1.4
        L_roll      =  0.0
        L_pitch     =  0.0
        L_yaw       =  0.0
        %%

        %         % 障害物の数(userInitialPositionやuserInitialVelocityの行数と一致する必要があります．)
        %         % 0に設定すると障害物は表示されません．
        %         userObstacleNum = 3;
        %
        %         % それぞれの障害物の大きさ (半径 [m]で入力してください)
        %         % 行は障害物の数「userObstacleNum」分，作成する必要があります．
        %         userObstacleSize= [0.512;0.512;0.512];
        %
        %         % 障害物の初期位置
        %         % 列が それぞれの障害物位置[x, y]を表しており，
        %         % 行は障害物の数「userObstacleNum」分，作成する必要があります．
        %         userInitialPosition = [5.5, -0.1;4.5, 2.0;8.5, 1.5];
        %
        %         % 障害物の初期速度
        %         % 列が それぞれの障害物速度[vx, vy]を表しており，
        %         % 行は障害物の数「userObstacleNum」分，作成する必要があります．
        %         userInitialVelocity = [-0.3, -0.;-0.0, -0.1;-0.1, 0.0];
        %         % Common configuration
        %         removeRgtNum = 3;
        %
        % %         vehicleSize = 0.4;
        %         gain        = [0.5;0.5];
        %         InputDelay  = 2000.; % Lv.5で使用．
        %         AfterVelocity = [0,0];
        %         randamObstacleFlag = 0;
        %         randamObstacleNum = 2;
        %         randamObstacleRange = [4.0,-1.0;8.0,4.0];
        %         randamVelocityObstacleRange = [-0.5,-0.5;0.0,0.2];
        %         randamObstacleSize= 0.5;
        animation = [0,0,0];
        %         virtualObstacleFlag = 1;
        %         %移植↑
        %
        %
        %
        %         obswn          = 1;          %Obstacle feedback position deviation gain
        %         obsz           = 1;          %Obstacle feedback angle deviation gain
        %         obsrwn         = 0.9;
        %         obsrd          = 0.5;        %Target radius of obstacle
        %
        %         Stationary_obstacles = 3;    %dynamic obstacles douteki1konotoki1nisuru
        %         Dynami
        c_obstacles    = 10;    %Stationary obstacles
        %
        %         InitialPosition = [5,0.5;10.0, -0.6; 15.0, 0.6 ; 42.3 ,4.3];
        %
        %         dT			= 0.05;
        %         Hp			= 15;
        %         Ymax		= 1.0;
        %         Ymin		= -1.0;
        %         dt			= 0.05;
        %         ObstacleSize	= 0.60;

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
        selectZone
        NoEntryZone
        ZoneNum
        V_ref
        th_target_w
        sharedControlMode  % Shared control mode handle object
    end


    methods
        %         function obj = Control(dt, Mode, FolderPath,sensor,autoware)
        function obj = Control(~, dt, mode ,rgtNum, FolderPath,sensor,autoware,sharedControlMode)
            % obj.wall = repmat([-0.5 8 -3 3],[size(obj.waypoint,1),1]);
            initial_position = [28.9,6]; %set custom initial and goal positions if needed but if you want the default leave it as []
            goal_position =[];
            try
                available_topics = rostopic('list');  
                fprintf('=== ROS INITIALIZATION CHECK ===\n');
                gazebo_topics = available_topics(contains(available_topics, 'gazebo'));
                if ~isempty(gazebo_topics)
                    obj.Gazebo = true;
                    fprintf('Gazebo topics detected: %d - Setting obj.Gazebo = true\n', length(gazebo_topics));
                else
                    obj.Gazebo = false;
                    fprintf('No Gazebo topics found - Setting obj.Gazebo = false (real system)\n');
                end
                fprintf('=================================\n');
            catch ME
                obj.Gazebo = false; % Default to real system if detection fails
                fprintf('ROS topic detection failed: %s - Defaulting to real system\n', ME.message);
            end
            
            % Try A* pathfinding first, fallback to original if it fails
            try
                % Calculate robot dimensions from wheel parameters
                robot_width = obj.wheel_width * 2;  % Total width = 0.55m
                robot_length = obj.wheel_len_rear + obj.wheel_len_front;  % Total length = 1.11m
                
                [obj.waypoint, obj.selectZone,obj.NoEntryZone,obj.ZoneNum,obj.V_ref]=PathSetting_AStar(initial_position, goal_position, robot_width, robot_length);
                fprintf('Control: Using A* generated waypoints (%d points) with vehicle size %.2fx%.2fm\n', size(obj.waypoint, 1), robot_width, robot_length);
            catch ME
                fprintf('Control: A* pathfinding failed (%s), using original waypoints\n', ME.message);
                [obj.waypoint, obj.selectZone,obj.NoEntryZone,obj.ZoneNum,obj.V_ref]=PathSetting_original;
            end

            %初期化
            obj.v_old = 0.5;
            obj.t_old = 0.2;
            obj.sharedControlMode = sharedControlMode;  % Store shared control mode object
            obj.sharedControlMode.setMode('path_following');  % Initialize shared control mode

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
            NamedConst.waypoint         = obj.waypoint;
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
            % Extract data from estimator
            if isfield(Plant, 'local') && isfield(Plant.local, 'boundingBoxes')
                obj.boundingBoxes = Plant.local.boundingBoxes;
            else
                obj.boundingBoxes = {};
            end
            % Check for door detection mode from Estimate.m
            door_detection_mode = false;
            if isfield(Plant, 'local') && isfield(Plant.local, 'door_detection_mode')
                door_detection_mode = Plant.local.door_detection_mode;
                if door_detection_mode
                    fprintf('[CONTROL] Door detection debug mode activated - will bypass to Phase 1.5\n');
                end
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

            %% State-based control system
            goal_position = obj.waypoint(end, :); % Final waypoint
            current_position = [Position.X, Position.Y];
            goal_distance = norm(current_position - goal_position);

            % Phase transition is now handled by Estimate.m

            % Execute control based on current mode
            if any(strcmp(obj.sharedControlMode.getMode(), {'path_following', 'floor_change'}))
                % Normal path following control
                [U, pu, px, pw, BestCost, BestCostId, uOpt, fval, removed] = obj.pathFollowingControl(Position, preobs);
                elevator_result = [];  % No elevator result in path following mode

            elseif strcmp(obj.sharedControlMode.getMode(), 'elevator_entry')
                % Elevator entry control
                elevator_result = obj.executeElevatorEntry(current_position, Position.yaw, lidar_data, door_detection_mode);
                U = elevator_result.V;

                % Fill empty variables for result.local
                pu = {};
                px = {};
                pw = {};
                BestCost = [];
                BestCostId = [];
                uOpt = {};
                fval = [];
                removed = [];

                % Check if elevator entry is completed
                if isfield(elevator_result, 'completed') && elevator_result.completed
                    obj.sharedControlMode.setMode('completed');
                    controlElevatorDoor('close');
                    fprintf('=== MODE CHANGE: Elevator entry COMPLETED ===\n');
                end

            else
                % Default: stop the wheelchair
                U = [0; 0];
                elevator_result = [];  % No elevator result in stopped mode
                % Fill empty variables for result.local
                pu = {};
                px = {};
                pw = {};
                BestCost = [];
                BestCostId = [];
                uOpt = {};
                fval = [];
                removed = [];
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
            if strcmp(obj.sharedControlMode.getMode(), 'path_following') && ~isempty(BestCostId)
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
            result.local.control_mode = obj.sharedControlMode.getMode(); % Pass control mode to Estimate


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
            %   door_detection_mode - boolean flag for debug mode (bypass to Phase 1.5)

            elevator_center = [27, 12]; % Elevator center position
            
            % Use the elevator_odom_mode property from the Control class
            % This can be configured when creating the Control object:
            % - false (default): use global coordinates (map mode) 
            % - true: use local coordinates (odometry mode) for map-independent operation
            
            if nargin < 5
                door_detection_mode = false; % Default: normal elevator entry
            end
            
            elevator_result = enterElevator(current_position, current_yaw, elevator_center, [], lidar_data, obj.Gazebo, obj.elevator_odom_mode, door_detection_mode);
            
            % Check if we need to open the door (Phase 1.5 - door verification)
            if isfield(elevator_result, 'phase') && elevator_result.phase == 1.5
                % Open elevator door only in Gazebo simulation
                if obj.Gazebo
                    controlElevatorDoor('open');
                    fprintf('Control: Opening elevator door for Phase 1.5 verification (Gazebo)\n');
                else
                    fprintf('Control: Phase 1.5 detected - Real system, no door control needed\n');
                end
            end
        end

        function displayStatusMessage(obj, Position, goal_distance, U, elevator_result)
            % Display status message based on current control mode
            % Clears previous output to avoid message stacking

            clc;  % Clear command window

            if any(strcmp(obj.sharedControlMode.getMode(), {'path_following', 'floor_change'}))
                % Path following mode status
                fprintf('=== PATH FOLLOWING MODE ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                fprintf('Goal Distance: %.2f m\n', goal_distance);
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
                fprintf('Target Waypoint: %d/%d\n', obj.target_n(1,1), size(obj.waypoint,1));
                fprintf('==========================\n');

            elseif strcmp(obj.sharedControlMode.getMode(), 'elevator_entry')
                % Elevator entry mode status
                fprintf('=== ELEVATOR ENTRY MODE ===\n');
                fprintf('Position: [%.2f, %.2f], Yaw: %.2f°\n', Position.X, Position.Y, rad2deg(Position.yaw));
                if nargin >= 5 && ~isempty(elevator_result)
                    fprintf('Phase: %d - %s\n', elevator_result.phase, elevator_result.status);
                end
                fprintf('Control: V=%.3f m/s, Ω=%.3f rad/s\n', U(1), U(2));
                fprintf('Elevator Center: [27.0, 12.0]\n');
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
            px                  = gpuArray(px);
            obj.target_n        = determine_target_location(tempobj_d, px);
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
            try
                load map2.mat map;
                [pw, remove_sample] = EvaluationPath_vec_gpu(tempobj, px, pu, preobs, obj.param_FPM, obj.Grid_Matrix, obj.boundingBoxes, map);
            catch
                % Fallback if map loading fails
                [pw, remove_sample] = EvaluationPath_vec_gpu(tempobj, px, pu, preobs, obj.param_FPM, obj.Grid_Matrix, obj.boundingBoxes);
            end

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

    end
end