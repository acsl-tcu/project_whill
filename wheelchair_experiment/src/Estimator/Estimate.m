classdef Estimate < handle
    %------------------------------------------------------------------------%
    % 電動車椅子班 推定器用クラスファイル
    % 2019.7.10 Electric wheelchair group
    % Advanced Control Systems Laboratory.
    %------------------------------------------------------------------------%
    % これは新規で推定器を作成しようとしている人や
    % 初めて電動車椅子班プログラム群を使おうとしている人向けに
    % 必要最低限の内容を掲載したクラスファイルです，
    %
    % 1. 関数名
    %    関数の中にはは必ず"main"関数を用意してください．
    %    プログラム実行において推定器を呼び出す際に最初に呼ばれる関数となります．
    % 2．入力引数
    %    "main"関数の入力引数として"obj"と"Plant"とした上で
    %    main(obj, Plant)のように記載してください．
    %    objは，このクラス自身を指していて，Plantは推定器で得られる
    %    計測値データが構造体として格納されています．
    % 3．計測値データ
    %    Plantには計測値データが構造体として格納されています．
    %    センサやモードの指定によって内容は若干異なりますので，各自その都度確認してください．
    %    基本的な計測値データとその意味を以下に記載しますので，参考にしてください．
    %    X    : 慣性座標系における x 位置 (double/single 型，スカラー) [m]
    %    Y    : 慣性座標系における y 位置 (double/single 型，スカラー) [m]
    %    Z    : 慣性座標系における z 位置 (double/single 型，スカラー) [m]
    %    roll : 慣性座標系における roll 方向角度 (double/single 型，スカラー) [rad]
    %    pitch: 慣性座標系における pitch方向角度 (double/single 型，スカラー) [rad]
    %    yaw  : 慣性座標系における yaw  方向角度 (double/single 型，スカラー) [rad]
    %    qx, qy, qz, qw :クォータニオン (double/single 型，スカラー) [-]
    %    Omega :電動車椅子左右輪回転速度 (double/single 型，2行1列配列) [m/s]
    %           Omega(1,1) -> 左車輪速度，Omega(2,1) -> 右車輪速度
    % 4．出力引数
    %    出力引数は"result"の1つのみを受け付けます．
    %    "result"には X, Y, Z, roll, pitch, yaw, qx, qy, qz, qw を
    %    構造体で大文字や小文字を間違えないように格納してください．
    %    推定終了後，どれか一つでも欠けている場合はエラーが発生します．
    %    これらの変数は自動的に保存されいるので推定器で保存する必要はありません，
    %    シミュレーション及び実験終了後，保存フォルダの指定を行っていれば，state.matに保存されます．
    %    また，ユーザが保存したい変数は"result.local.(変数名)"として格納してください．
    %    ユーザが保存したい変数も別途保存されています，
    %    この変数はシミュレーション及び実験終了後，保存フォルダの指定を行っていれば，
    %    usrLocal.matに保存されます．
    %
    % 注意; 電動車椅子班プログラム群は推定器及び制御器クラスファイルの頒布性，再利用性を
    %       目指して作成されています．
    %       そのため，推定器はこのクラス以外の場所に記載しないようにしてください．
    %       また，推定器や制御器クラスファイル以外の場所を書き換えることは控えてください．
    %
    % ファイル分割はプログラムの可読性を高めるのでおすすめします．
    % 以下のサイトを参考に作成してください．
    % 参考サイト：
    % https://jp.mathworks.com/help/matlab/matlab_oop/class-files-and-folders.html
    properties (Access = public, Constant) %一定値の変数定義
        %% LiDAR 車両中心から見たLiDARの位置
        % Gazebo
        % Ltheta =0;
        % LL = 0;
        % Lh =1.2;
        % 白車椅子
        Ltheta =0;
        LL = 0;
        Lh =1.4;
        %% IMM-------------------------------------------------------------
        DimSta              = 6; %状態数(x,y,theta,v,alpha,beta)
        DimStaV             = 1; %状態に含まれている速度の状態数v
        DimObs              = 5; %観測できる状態の数(x,y,theta,alpha,beta)
        % Ellipse----------------------------------------------------------
        Q                   = diag([0.1; 1; 1E-4; 1E-4]); % システムノイズの共分散行列
        R                   = diag([9E-4; 9E-4; (pi/24)^2; 9E-2; 9E-2])
        %------------------------------------------------------------------
        R_temp = diag([9E-2; 9E-2]);
        %------------------------------------------------------------------
        %% RANSAC-------------------------------
        param_RANSAC = struct('sampleSize',    9, ...               % サンプリング数
            'maxDistance',   0.5, ...               % max allowable distance for inliers
            'TrialNum',      1000, ...              % 試行回数の最大値
            'confDegree',    95, ...                % 信頼度
            'A',             [0, 0, -1, 1, 0], ...  % fminconで使用する制約条件(x,y,alpha,beta,thetaの順), -alpha+beta < 0
            'B',             0, ...                 % fminconで使用する制約条件
            'Aeq',           [], ...                % fminconで使用する制約条件
            'Beq',           [], ...                % fminconで使用する制約条件
            'tth',           pi/12, ...             % fminconで使用する制約条件
            'MD_threshold',  30, ...                % モデル棄却の閾値(マハラノビス距離)
            'MSANum',        500, ...               % MaxSamplingAttempts
            'selectedArea',  0.4, ...               % 予測値周辺のフィッティング対象とする点の探索領域
            'eta',           0.1 ...                % イノベーション崩壊判定の上下限割合
            );
        %--------------------------------------
        %% 点群処理-----------------------------
        % 剛体変換
        % クラスタリング
        th_eClustering = 0.3;
        % 関心領域
        % roi = [-2 15; -2 2; 0.2 2];
        roi = [-inf inf; -inf inf; 0.4 2];
        %---------------------------------------
        %% トラック管理と対応付け
        % 割り当て設定
        distanceThreshold = 0.5;      % 検出点を同一物体とみなす距離閾値
        requiredFrames = 5;          % トラック登録に必要な連続フレーム数
        % 対応付け設定
        associatecost = 3;
        deletionFrames = 20;
        % トラック初期値
        xhat3to6_init = [pi/2;0;0.18;0.08]; % [theta v alpha beta]
        P_init = diag([.01;.01;(pi)^2;4;0.1;0.1]); % 姿勢角はtheta=0のため誤差を十分に許容

    end
    properties (Access = public) %変数定義
        dt                      %刻み時間(main.mのdt)
        cnt                     %カウント
        estimatestarttime       %推定の時変の刻み時間算出に使用
        oldtime                 %推定の時変の刻み時間算出に使用
        timeStep                %時変の刻み時間
        modeNumber              %main.mのmodeと同一。オンラインかオフラインか
        pcloudOffline           %userLocal.matにある点群を各時刻保存
        thetaOffline            %userLocal.matにある剛体1(LiDARの上に取り付けたマーカー)の方向角(yaw)を各時刻保存
        timeOffline             %userLocal.matにあるLiDARの測定時刻を各時刻保存
        transOffline            %userLocal.matにある剛体1(LiDAR)の位置x,y,zを各時刻保存

        % Theater Plot
        trackP
        detectionP
        waypointP
        wheelchairP

        % Processing point cloud
        trans
        theta

        % Occupancy map for wall filtering
        occupancyMap
        occupancyMatrix

        % Track Manager
        tempFilter

        % Fitting threshold
        doRANSAC = 20;

        % EKF filter
        ellipsefilter

        Allxhat

        trackStorage
        newTrackCandidates
        tempStorage
        
        % Phase detection for elevator control
        elevator_center         % Elevator center position [x, y]
        control_phase           % Current control phase: 'path_following', 'elevator_entry', or 'floor_change'
        sharedControlMode       % Shared control mode handle object
        
        % Tracking control switch
        track_on                % Boolean switch to enable/disable LiDAR processing and tracking





    end
    methods
        function obj = Estimate(dt, mode,File,sharedControlMode) % 実行して最初の1度だけ呼び出される所


            obj.modeNumber = mode; % main.mで指定したmodeを代入
            obj.cnt = 1; % カウントの初期定義
            
            % Initialize shared control mode
            obj.sharedControlMode = sharedControlMode; % Store shared control mode object
            
            % Initialize phase detection
            % obj.elevator_center = [27, 9.3]; % Elevator center position (same as Control.m)
            obj.control_phase = 'floor_change'; % Start in floor change mode to allow elevator entry
            
            % Initialize tracking switch (default enabled)
            obj.track_on = true;
            
            % Path planning - moved from Control.m constructor
            initial_position = [31,6]; %set custom initial and goal positions if needed but if you want the default leave it as []
            goal_position =[];
            
            % Calculate robot dimensions (using same constants as Control.m)
            wheel_width = 0.55/2;           % wheel_width from Control.m
            wheel_len_rear = 0.35;          % wheel_len_rear from Control.m  
            wheel_len_front = 0.76;         % wheel_len_front from Control.m
            robot_width = wheel_width * 2;  % Total width = 0.55m
            robot_length = wheel_len_rear + wheel_len_front; % Total length = 1.11m
            
            % Try A* pathfinding first, fallback to original if it fails
            try
                [waypoint, ~, ~, ~, ~] = PathSetting_AStar(initial_position, goal_position, robot_width, robot_length);
                fprintf('Estimate: Using A* generated waypoints (%d points) with vehicle size %.2fx%.2fm\n', size(waypoint, 1), robot_width, robot_length);
            catch ME
                fprintf('Estimate: A* pathfinding failed (%s), using original waypoints\n', ME.message);
                [waypoint, ~, ~, ~, ~] = PathSetting_original;
            end
            
            % Store waypoints in SharedControlMode for Control.m to access
            obj.sharedControlMode.setWaypoints(waypoint);
            
            % Plot the generated path for visualization (world coordinates)
            try
                % Load map for visualization
                map_data = load('map2.mat');
                map_obj = map_data.map;
                
                figure('Name', 'Generated Path Visualization', 'Position', [100, 100, 900, 600]);
                hold on;
                
                % Show occupancy grid in world coordinates
                show(map_obj);
                
                % Plot generated waypoints
                plot(waypoint(:,1), waypoint(:,2), 'ro-', 'LineWidth', 2, 'MarkerSize', 8);
                plot(waypoint(1,1), waypoint(1,2), 'gs', 'MarkerSize', 12, 'LineWidth', 3);
                plot(waypoint(end,1), waypoint(end,2), 'rs', 'MarkerSize', 12, 'LineWidth', 3);
                
                xlabel('X (m)');
                ylabel('Y (m)');
                title('Generated Path in World Coordinates');
                legend('Occupancy Grid', 'Waypoints', 'Start', 'Goal', 'Location', 'best');
                grid on;
                axis equal;
                hold off;
                
                fprintf('Estimate: Path visualization plotted in world coordinates\n');
            catch ME
                fprintf('Estimate: Could not create path visualization: %s\n', ME.message);
            end

            % Theater Plot---------------------------------------------
            tp = theaterPlot('XLim',obj.roi(1,1:2),'YLim',obj.roi(2,1:2)); grid on;
            obj.trackP = trackPlotter(tp,"DisplayName",'Tracks','MarkerFaceColor','g','HistoryDepth',0);
            obj.detectionP = detectionPlotter(tp,"DisplayName",'Detections','MarkerFaceColor','r');
            % Add waypoints and wheelchair plotters
            obj.waypointP = trackPlotter(tp,"DisplayName",'Waypoints','MarkerFaceColor','b','MarkerSize',8,'HistoryDepth',0);
            obj.wheelchairP = trackPlotter(tp,"DisplayName",'Wheelchair','MarkerFaceColor','m','MarkerSize',12,'HistoryDepth',10);
            %----------------------------------------------------------

            obj.dt  = dt;
            obj.oldtime = 0;            % 時変の刻み時間算出用
            obj.estimatestarttime = tic;% 時変の刻み時間算出用

            % Load occupancy map for wall filtering
            try
                map_data = load('map2.mat');
                obj.occupancyMap = map_data.map;
                obj.occupancyMatrix = getOccupancy(obj.occupancyMap);
            catch ME
                warning('Could not load map2.mat for wall filtering: %s', ME.message); %#ok<MEXCEP>
                obj.occupancyMap = [];
                obj.occupancyMatrix = [];
            end

            % 推定値の初期化
            obj.Allxhat = [];

            % 新規トラック候補の追加
            obj.newTrackCandidates = struct('Obs', {}, 'Count', {}, 'Buffer', {});
            %
            % EKFフィルタ
            obj.ellipsefilter = trackingEKF2(@f,@h, ...
                'State', zeros(obj.DimSta,1), ...
                'StateTransitionJacobianFcn',@jacobF, ...
                'MeasurementJacobianFcn',@jacobH, ...
                'MeasurementNoise',obj.R);


            % 一時フィルタ(EKF)
            obj.tempFilter = trackingEKF(@f, @h, ...
                'State', zeros(obj.DimSta,1), ...
                'StateTransitionJacobianFcn', @jacobF, ...
                'MeasurementJacobianFcn', @jacobH, ...
                'MeasurementNoise', diag([9E-2;9E-2]), ...
                'ProcessNoise',diag([0;0;0.1;0.1;0.0001;0.0001]));

            % tracker管理------------------------------------------
            % トラックを包括的に管理．全ての推定情報を含む
            numAllowableTracks = 50; % トラック管理許容数
            obj.trackStorage = struct();
            obj.trackStorage.Logical = false(numAllowableTracks,1); % アクティブなトラックの識別 0 or 1
            obj.trackStorage.CheckAssign = zeros(numAllowableTracks, 1); % トラックの未検出回数
            obj.trackStorage.States = zeros(obj.DimSta,numAllowableTracks); % トラックの推定値
            obj.trackStorage.P = cell(numAllowableTracks,1); % トラックの誤差共分散
            obj.trackStorage.tracker = arrayfun(@(~) clone(obj.ellipsefilter), 1:numAllowableTracks, 'UniformOutput', false)'; % EKFインスタンス
            % 一時tracker管理---------------------------------------
            % 候補となったトラックを登録する際にEKFで初期値を求める
            numAllowabletempTracks = 20; % 一括トラック登録の許容数
            obj.tempStorage = struct();
            obj.tempStorage.tracker = cell(numAllowabletempTracks,1);
            obj.tempStorage.tracker = arrayfun(@(~) clone(obj.tempFilter), 1:numAllowabletempTracks, 'UniformOutput', false)';
            %------------------------------------------------------
            %
            % EKF関数---------------------------------------------------------
            function Xhbar = f(xhat,dt)
                Xhbar(1,1) = xhat(1)+xhat(4)*dt*cos(xhat(3)); % x
                Xhbar(2,1) = xhat(2)+xhat(4)*dt*sin(xhat(3)); % y
                Xhbar(3,1) = xhat(3); % theta
                Xhbar(4,1) = xhat(4); % v
                Xhbar(5,1) = xhat(5); % alpha
                Xhbar(6,1) = xhat(6); % beta
            end
            function jF = jacobF(Xhbar,dt)
                jF = [1 0 -Xhbar(4)*dt*sin(Xhbar(3)) dt*cos(Xhbar(3)) 0 0
                    0 1 Xhbar(4)*dt*cos(Xhbar(3)) dt*sin(Xhbar(3)) 0 0
                    0 0 1 0 0 0
                    0 0 0 1 0 0
                    0 0 0 0 1 0
                    0 0 0 0 0 1];
            end
            function Yhbar = h(state,varargin)
                pos = [1 2];
                if isempty(varargin)
                    Yhbar = state(pos);
                else
                    is_Observed = varargin{1};
                    allObs = [1 2 3 5 6];
                    if is_Observed
                        Yhbar = state(allObs);
                    else
                        Yhbar = state(pos);
                    end
                end
            end
            function jH = jacobH(~, varargin)
                if isempty(varargin)
                    jH = [1 0 0 0 0 0
                        0 1 0 0 0 0];
                else
                    is_Observed = varargin{1};
                    if is_Observed
                        jH = [1 0 0 0 0 0
                            0 1 0 0 0 0
                            0 0 1 0 0 0
                            0 0 0 0 1 0
                            0 0 0 0 0 1];
                    else
                        jH = [1 0 0 0 0 0
                            0 1 0 0 0 0];
                    end

                end
            end
            %------------------------------------------------------------------

        end
        function [result, obj] = main(obj, Plant) %この部分に推定に必要なプログラムを書いていく

            % Plant.X     = Plant.X;
            % Plant.Y     = Plant.Y;
            % Plant.Z     = Plant.Z;
            % Plant.yaw   = Plant.yaw;
            %
            % Plant.yaw       = Plant.yaw-obj.Ltheta;
            % Plant.X         = Plant.X -obj.LL*cos(Plant.yaw);
            % Plant.Y         = Plant.Y -obj.LL*sin(Plant.yaw);

            result.T    = Plant.T;
            result.X    = Plant.X;
            result.Y    = Plant.Y;
            result.Z    = Plant.Z;
            result.roll = Plant.roll;
            result.pitch= Plant.pitch;
            result.yaw  = Plant.yaw;
            result.qx   = Plant.qx;
            result.qy   = Plant.qy;
            result.qz   = Plant.qz;
            result.qw   = Plant.qw;
            % disp(obj.cnt)

            switch obj.modeNumber
                case {2,3}     %Online estimation(LiDARやモーションキャプチャーの計測値は構造体のPlantに入っている)
                    pcloud                  = Plant.ptCloud; %点群を保存
                    xyz                     = rosReadXYZ(struct(pcloud)); %pointCloud2からpointCloudに変換
                    nowtime                 = toc(obj.estimatestarttime); %ticからの計算時間
                    delta                   = nowtime - obj.oldtime; %時変の刻み時間を計算
                    obj.timeStep(obj.cnt,1) = delta; %各刻み時間を時刻ごとに保存
                    obj.oldtime             = nowtime;%時変の刻み時間計算の処理
                    obj.trans = [Plant.X Plant.Y 1.2];
                    obj.theta = Plant.yaw;
                otherwise
                    error('No such a configured mode.')
                    %
            end
            %
            %     %%
            %     Zone=[-0.15 30.00 -0.90 0.80  0.2 2
            %           -1.30 -0.15 -0.90 5.20  0.2 2
            %           -1.30 30.60  5.20 6.90  0.2 2
            %           30.60 31.70  5.20 8.30  0.2 2
            %           30.60 36.00  8.30 10.6  0.2 2];
            %     dx =0.1;
            %
            %     % figure
            %     % for i= 1:size(Zone,1)
            %     %     plot(polyshape([Zone(i,1),Zone(i,2),Zone(i,2),Zone(i,1)],[Zone(i,3),Zone(i,3),Zone(i,4),Zone(i,4)]))
            %     %     hold on
            %     % end
            %     % axis equal
            %     % grid on
            %     %%
            %
            %     if Plant.X>=Zone(1,1) && Plant.X<=Zone(1,2) && Plant.Y>=Zone(1,3) && Plant.Y<=Zone(1,4)
            %         Limit= [Zone(1,1:2)+[-dx 0]; Zone(1,3:4)+[dx -dx]; Zone(1,5:6)];
            %     elseif Plant.X>=Zone(2,1) && Plant.X<=Zone(2,2) && Plant.Y>=Zone(2,3) && Plant.Y<=Zone(2,4)
            %         Limit= [Zone(2,1:2)+[dx -dx]; Zone(2,3:4)+[dx dx]; Zone(2,5:6)];
            %     elseif Plant.X>=Zone(3,1) && Plant.X<=Zone(3,2) && Plant.Y>=Zone(3,3) && Plant.Y<=Zone(3,4)
            %         Limit= [Zone(3,1:2)+[dx dx]; Zone(3,3:4)+[dx -dx]; Zone(3,5:6)];
            %     elseif Plant.X>=Zone(4,1) && Plant.X<=Zone(4,2) && Plant.Y>=Zone(4,3) && Plant.Y<=Zone(4,4)
            %         Limit= [Zone(4,1:2)+[dx -dx]; Zone(4,3:4)+[dx dx]; Zone(4,5:6)];
            %     elseif Plant.X>=Zone(5,1) && Plant.X<=Zone(5,2) && Plant.Y>=Zone(5,3) && Plant.Y<=Zone(5,4)
            %         Limit= [Zone(5,1:2)+[dx 0]; Zone(5,3:4)+[dx -dx]; Zone(5,5:6)];
            %     end
            %
            %     % figure
            %     % plot(polyshape([Limit(1,1),Limit(1,2),Limit(1,2),Limit(1,1)],[Limit(2,1),Limit(2,1),Limit(2,2),Limit(2,2)]))
            %     % hold on
            %     % axis equal
            %     % grid on
            %     %%
            %
            %% Handle user mode requests from menu
            if isfield(Plant, 'UserModeRequest') && Plant.UserModeRequest.requested
                user_request = Plant.UserModeRequest;
                fprintf('[ESTIMATE] Processing user mode request: %s\n', user_request.new_phase);
                
                % Set tracking switch based on menu selection
                if isfield(user_request, 'track_on')
                    obj.track_on = user_request.track_on;
                    fprintf('[ESTIMATE] Tracking switch set to: %s\n', string(obj.track_on));
                end
                
                switch user_request.new_phase
                    case 'floor_change'
                        % Check if this is the first time using the system
                        if obj.sharedControlMode.isFirstTimeUse()
                            % First time - just set mode, use existing waypoints
                            obj.sharedControlMode.setMode('floor_change');
                            fprintf('[ESTIMATE] User set mode to FLOOR_CHANGE (first time) - using existing waypoints\n');
                        else
                            % Not first time - replan path from current position and reset trackers
                            fprintf('[ESTIMATE] User set mode to FLOOR_CHANGE (returning) - replanning path from current position\n');
                            
                            % Replan path from current position
                            obj.replanPathFromCurrentPosition(Plant);
                            
                            % Reset all trackers
                            obj.resetAllTrackers();
                            
                            obj.sharedControlMode.setMode('floor_change');
                            fprintf('[ESTIMATE] Path replanning and tracker reset completed\n');
                        end
                        
                    case 'door_detection'
                        obj.sharedControlMode.setMode('door_detection');
                        fprintf('[ESTIMATE] User set mode to DOOR_DETECTION - debug mode activated\n');
                        
                    case 'ndt_pose_detection'
                        obj.sharedControlMode.setMode('ndt_pose_detection');
                        fprintf('[ESTIMATE] User set mode to NDT_POSE_DETECTION - manual control with pose broadcasting\n');
                        fprintf('[ESTIMATE] Use manual controls to move wheelchair - pose will be continuously displayed\n');
                        
                    otherwise
                        fprintf('[ESTIMATE] Unknown user mode request: %s\n', user_request.new_phase);
                end
            end
            
            %% Phase detection for elevator control
            current_position = [Plant.X, Plant.Y];
            
            % Define elevator door approach area (rectangular zone in front of door)
            elevator_door_area.x_min = 29.3;  % x > 29.3
            elevator_door_area.x_max = 30.8;  % x <= 30.8
            elevator_door_area.y_min = 9.1;  % y >= 12.0
            elevator_door_area.y_max = 9.4;  % y < 12.3
            
            % Check if wheelchair is in the elevator door approach area
            in_elevator_area = (current_position(1) > elevator_door_area.x_min) && ...
                              (current_position(1) <= elevator_door_area.x_max) && ...
                              (current_position(2) >= elevator_door_area.y_min) && ...
                              (current_position(2) < elevator_door_area.y_max);
            
            % Check for mode transitions
            if strcmp(obj.sharedControlMode.getMode(), 'floor_change') && in_elevator_area
                % Transition from floor_change to elevator entry
                obj.sharedControlMode.setMode('elevator_entry');
                obj.control_phase = 'elevator_entry';
                fprintf('[ESTIMATE] MODE CHANGE: Switching from FLOOR_CHANGE to ELEVATOR ENTRY mode\n');
                fprintf('           Position: [%.3f, %.3f] entered elevator door area\n', current_position(1), current_position(2));
                fprintf('           Area bounds: X(%.1f,%.1f], Y[%.1f,%.1f)\n', ...
                    elevator_door_area.x_min, elevator_door_area.x_max, ...
                    elevator_door_area.y_min, elevator_door_area.y_max);
            elseif strcmp(obj.sharedControlMode.getMode(), 'door_detection')
                % Door detection mode: immediately switch to elevator_entry for debug
                obj.control_phase = 'elevator_entry';
                fprintf('[ESTIMATE] MODE CHANGE: Door detection mode - switching to ELEVATOR ENTRY for debug\n');
                fprintf('           Control.m will bypass Phase 1 and go directly to Phase 1.5\n');
            elseif strcmp(obj.sharedControlMode.getMode(), 'elevator_entry') && ~in_elevator_area
                % Optional: Switch back if wheelchair leaves the area (uncomment if needed)
                % obj.control_phase = 'floor_change';
                % fprintf('[ESTIMATE] MODE CHANGE: Leaving elevator area, switching back to FLOOR_CHANGE\n');
            end
            
            %% NDT Pose Detection Mode - Continuous pose broadcasting
            if strcmp(obj.sharedControlMode.getMode(), 'ndt_pose_detection')
                % Convert yaw from radians to degrees for better readability
                yaw_degrees = Plant.yaw * 180 / pi;
                
                % Broadcast current pose continuously (every iteration)
                fprintf('[NDT_POSE] X: %8.3f m | Y: %8.3f m | Z: %8.3f m | Yaw: %7.2f° | Time: %.2f s\n', ...
                    Plant.X, Plant.Y, Plant.Z, yaw_degrees, Plant.T);
                
                % Continue with normal processing (don't skip)
                obj.control_phase = 'ndt_pose_detection';
            end
            
            % Debug info for position tracking
            if mod(obj.cnt, 50) == 0 % Print every 50 iterations to avoid spam
                if in_elevator_area
                    fprintf('[ESTIMATE] Position: [%.3f, %.3f] - IN elevator door area, Mode: %s\n', ...
                        current_position(1), current_position(2), obj.control_phase);
                else
                    distance_to_area_x = min(abs(current_position(1) - elevator_door_area.x_min), ...
                                           abs(current_position(1) - elevator_door_area.x_max));
                    distance_to_area_y = min(abs(current_position(2) - elevator_door_area.y_min), ...
                                           abs(current_position(2) - elevator_door_area.y_max));
                    fprintf('[ESTIMATE] Position: [%.3f, %.3f] - Distance to elevator area: X=%.2fm, Y=%.2fm, Mode: %s\n', ...
                        current_position(1), current_position(2), distance_to_area_x, distance_to_area_y, obj.control_phase);
                end
            end

            %% 地面除去および検出点抽出
            xyz = double(xyz);
            ptCloud = pointCloud(xyz); % 全点群

            Rxyz = eul2rotm([0, Plant.pitch,Plant.roll], 'ZYX');
            tform = rigidtform3d([Rxyz,[0; 0; 0];zeros(1,3),1]);
            ptCloud = pctransform(ptCloud, tform);
            xyz = ptCloud.Location;

            % Skip heavy processing when tracking is disabled (only odometry needed)
            if ~obj.track_on
                % Minimal processing when tracking is disabled
                fprintf('[ESTIMATE] Tracking disabled: Skipping heavy LiDAR processing\n');
                
                % Set empty values for variables that won't be computed
                detections2 = [];
                zk = [];
                boundingBoxes = {};
                ptCloudWithoutGround = pointCloud.empty;
                
            else
                % Normal path following mode: Full LiDAR processing
                
                % Filter wall points using occupancy map
                debug_on = false; % Set to true to enable filtering visualization
                if ~isempty(obj.occupancyMap)
                    xyz_before = xyz; % Save original for plotting
                    xyz = obj.filterWallPoints(xyz, Plant);

                end

                % 地面除去+剛体変換+クラスタリング
                [detections,survivedIndices,obstacleIndices,labels,numClusters] = Faster_processingPcloud_mex(xyz,obj.theta, ...
                    obj.trans,obj.roi,obj.th_eClustering,obj.cnt*delta);
                % [detections,survivedIndices,obstacleIndices,labels,numClusters] = Faster_processingPcloud(xyz,obj.theta, ...
                    % obj.trans,obj.roi,obj.th_eClustering,obj.cnt*delta);

                ptCloudWithoutGround_local = select(pointCloud(xyz),obstacleIndices); % 障害物点群(地面除去済)
                NotGround = ptCloudWithoutGround_local.Location;
                [NotGround(:,1), NotGround(:,2), NotGround(:,3)] = homogeneous(Plant, NotGround(:,1)', NotGround(:,2)', NotGround(:,3)', obj.trans(3)); % Convert coordinate system(local -> global)
                ptCloudWithoutGround = pointCloud(NotGround);
                labelLocation = [NotGround, double(labels)]'; % 障害物点群とラベルのセット

                % Filter out wall clusters from detections
                [detections2, wall_indices, labelLocation] = obj.filterWallClusters(detections, labelLocation, numClusters);

                % Generate bounding boxes around clustered objects
                boundingBoxes = obj.generateBoundingBoxes(NotGround, labels, numClusters);

                % Plot comparison with bounding boxes if debug enabled
                if debug_on
                    obj.plotFilteringComparison(xyz_before, xyz, Plant, boundingBoxes, detections, wall_indices, labelLocation, obj.trans);
                end

                % 検出値の抽出-------------------
                zk = detections2(1:2,:); % detections:[x;y;radius]
                %--------------------------------
            end

            %% Transform xyz to global coordinates for door detection
            xyz_global = [];
            if ~isempty(xyz)
                % Transform from LiDAR local coordinates to global coordinates
                cos_yaw = cos(Plant.yaw);
                sin_yaw = sin(Plant.yaw);
                
                % Apply rotation and translation to convert local to global
                xyz_global = zeros(size(xyz));
                xyz_global(:,1) = xyz(:,1) * cos_yaw - xyz(:,2) * sin_yaw + Plant.X;
                xyz_global(:,2) = xyz(:,1) * sin_yaw + xyz(:,2) * cos_yaw + Plant.Y;
                xyz_global(:,3) = xyz(:,3) + obj.trans(3); % Add wheelchair height offset
                
                fprintf('[ESTIMATE] Transformed %d points from local to global coordinates\n', size(xyz, 1));
            end

            %% result.localに各変数を保存
            result.local.boundingBoxes = boundingBoxes;  % LiDAR bounding boxes for controller
            result.local.delta = delta;
            result.local.control_phase = obj.control_phase; % Pass control phase to Control.m
            result.local.xyz_global = {xyz_global}; % Pass global xyz data for door detection (as cell array)
            result.local.xyz_local = {xyz}; % Keep local xyz for reference if needed (as cell array)
            
            % Pass door detection mode flag to Control.m
            if isfield(Plant, 'UserModeRequest') && Plant.UserModeRequest.requested
                result.local.door_detection_mode = Plant.UserModeRequest.door_detection_mode;
            else
                result.local.door_detection_mode = false;
            end
            if ~obj.track_on
                % Skip tracking when tracking is disabled
                fprintf('[ESTIMATE] Skipping object tracking (tracking disabled)\n');
                obj.Allxhat = [];
                AllP = {};
                model = [];
            else
                %% トラック候補のバッファリングとトラックの追加
                % 新規トラック候補の距離閾値と必要連続フレーム数の設定-------
                % distanceThreshold:同一検出点とみなす距離閾値sor
                % requiredFrames:必要連続観測フレーム数
                % Description: This function is track manager which
                % continueously check observations and decide tracks at current
                % time that should be estimated based on Hungarian method.
                % It also supports intermittent detections.
                %------------------------------------------------------------
                [obj.trackStorage, obj.newTrackCandidates] = manage_track(zk,obj.trackStorage, obj.newTrackCandidates, ...
                    obj.Allxhat, obj.distanceThreshold,obj.requiredFrames, obj.xhat3to6_init, obj.P_init, delta, obj.tempStorage,obj.DimSta);

            if ~isempty(obj.trackStorage)
                %% 予測
                validTrackIdx = find(obj.trackStorage.Logical); % 有効なトラックのインデックスを取り出す
                obj.trackStorage = predict_track(delta,validTrackIdx,obj.DimSta,obj.trackStorage,obj.Q);
                %% 対応付け(ハンガリアン法)
                [assignment,obj.trackStorage,Xhbar_observed,validTrackIdx,ObsptClouds,assignedStatesIdx] = associate_track(zk,obj.associatecost, ...
                    obj.deletionFrames,obj.R_temp,obj.trackStorage,validTrackIdx,labelLocation);
                %
                %% 各フィルタの観測値の算出+フィルタリング-------------------------------------------------
                model = cell(size(assignment,1),1);
                if all([~isempty(assignment) ,~isnan(sum(assignment,'all'))])
                    [xhat,P,obj.trackStorage,model,inlierpoints] = update_track(obj.param_RANSAC,obj.DimSta,...
                        assignment,obj.trackStorage,assignedStatesIdx,ObsptClouds,obj.doRANSAC, ...
                        obj.R,Xhbar_observed,obj.trans,Plant);
                end
                %% Trackの表示-------------------------------------------------
                if ~isempty(zk)
                    obj.detectionP.plotDetection([zk(1,:)',zk(2,:)',zeros(size(zk,2),1)]);
                end
                [obj.Allxhat, AllP] = deal([]);
                if ~isempty(validTrackIdx)
                    % アクティブなトラック情報を取り出す
                    validTracks = obj.trackStorage.tracker(validTrackIdx,1);
                    obj.Allxhat = cell2mat(cellfun(@(x) x.State', validTracks, 'UniformOutput', false))';
                    AllP = cellfun(@(x) x.StateCovariance, validTracks, 'UniformOutput', false);
                    % Plotに必要な速度計算
                    vx = obj.Allxhat(4,:).*cos(obj.Allxhat(3,:));
                    vy = obj.Allxhat(4,:).*sin(obj.Allxhat(3,:));
                    obj.trackP.plotTrack([obj.Allxhat(1,:)',obj.Allxhat(2,:)',zeros(size(obj.Allxhat,2),1)],[vx',vy',zeros(size(obj.Allxhat,2),1)]);
                end
                %---------------------------------------------------------------
                end
            end

            %% result.localに各変数を保存
            result.local.AllTracks.xhat             = {obj.Allxhat};                % 全トラックの推定値
            result.local.AllTracks.P                = {AllP};                       % 全トラックの誤差共分散
            result.local.ObsPC                      = {ptCloudWithoutGround.Location}; % 障害物点群

            % 推定に関係する変数は2時刻目以降で計算できるので1時刻目と別処理
            if obj.cnt >= 2
                result.local.model                      = {model};
            else
                result.local.model                      = [];
            end
            %
            %     % if obj.cnt >= 2
            %     %     if obj.cnt == 2
            %     %         result.local.Q                          = obj.Q;
            %     %         % result.local.Q_pt                       = obj.Q_ptCOG;
            %     %         result.local.R                          = obj.R;
            %     %         result.local.R_pt                       = obj.R_temp;
            %     %         % result.local.R_bbox                     = obj.R_bbox;
            %     %         result.local.param_RANSAC               = obj.param_RANSAC;
            %     %         result.local.trans                      = obj.trans;
            %     %         result.local.theta                      = obj.theta;
            %     %         result.local.roi                        = obj.roi;
            %     %         result.local.th_clustering              = obj.th_eClustering;
            %     %         result.local.th_newTrackCandidates      = obj.distanceThreshold;
            %     %         result.local.comfirmFrames              = obj.requiredFrames;
            %     %         result.local.associatecost              = obj.associatecost;
            %     %         result.local.deletionFrames             = obj.deletionFrames;
            %     %         result.local.initXhat3to6               = obj.xhat3to6_init;
            %     %         result.local.initP                      = obj.P_init;
            %     %         result.local.doRANSAC                   = obj.doRANSAC;
            %     %         % result.local.dobbox                     = obj.dobbox;
            %     %     else % 1時刻だけ保存したい変数は2時刻目以外を空で保存
            %     %         result.local.Q                          = [];
            %     %         % result.local.Q_pt                       = [];
            %     %         result.local.R                          = [];
            %     %         result.local.R_pt                       = [];
            %     %         % result.local.R_bbox                     = [];
            %     %         result.local.param_RANSAC               = [];
            %     %         result.local.trans                      = [];
            %     %         result.local.theta                      = [];
            %     %         result.local.roi                        = [];
            %     %         result.local.th_clustering              = [];
            %     %         result.local.th_newTrackCandidates      = [];
            %     %         result.local.comfirmFrames              = [];
            %     %         result.local.associatecost              = [];
            %     %         result.local.deletionFrames             = [];
            %     %         result.local.initXhat3to6               = [];
            %     %         result.local.initP                      = [];
            %     %         result.local.doRANSAC                   = [];
            %     %         % result.local.dobbox                     = [];
            %     %     end
            %     %     result.local.model                      = {model};
            %     % else
            %     %     % 2時刻目以降で使う変数の1時刻目における処理
            %     %     result.local.Q                          = [];
            %     %     % result.local.Q_pt                       = [];
            %     %     result.local.R                          = [];
            %     %     result.local.R_pt                       = [];
            %     %     % result.local.R_bbox                     = [];
            %     %     result.local.param_RANSAC               = [];
            %     %     result.local.trans                      = [];
            %     %     result.local.theta                      = [];
            %     %     result.local.roi                        = [];
            %     %     result.local.th_clustering              = [];
            %     %     result.local.th_newTrackCandidates      = [];
            %     %     result.local.comfirmFrames              = [];
            %     %     result.local.associatecost              = [];
            %     %     result.local.deletionFrames             = [];
            %     %     result.local.initXhat3to6               = [];
            %     %     result.local.initP                      = [];
            %     %     result.local.doRANSAC                   = [];
            %     %     % result.local.dobbox                     = [];
            %     %     result.local.model                      = [];
            %     % end
            %% Plot waypoints and wheelchair position in theater plot
            % Plot current wheelchair position with orientation (yaw)
            % Use velocity vector to show yaw direction
            arrow_length = 1.0; % 1 meter arrow length
            vel_x = arrow_length * cos(Plant.yaw);
            vel_y = arrow_length * sin(Plant.yaw);
            obj.wheelchairP.plotTrack([Plant.X, Plant.Y, Plant.Z], [vel_x, vel_y, 0]);
            
            % Plot waypoints (only once, when cnt == 1, or when waypoints change)
            if obj.cnt == 1
                waypoints = obj.sharedControlMode.getWaypoints();
                if ~isempty(waypoints)
                    % Plot all waypoints as track points
                    waypoint_z = zeros(size(waypoints, 1), 1); % Set Z to 0 for waypoints
                    waypoint_vel = zeros(size(waypoints, 1), 3); % No velocity for waypoints
                    obj.waypointP.plotTrack([waypoints, waypoint_z], waypoint_vel);
                end
            end
            
            %
            obj.cnt     = obj.cnt + 1; % カウントの更新
        end

        function plotFilteringComparison(obj, xyz_before, xyz_after, Plant, boundingBoxes, detections, wall_indices, labelLocation,trans)
            % Plot comparison of point clouds before and after wall filtering

            figure('Name', sprintf('Wall Filtering Comparison - Frame %d', obj.cnt), ...
                'Position', [100, 100, 1200, 500]);

            % Convert to global coordinates for plotting
            cos_yaw = cos(Plant.yaw);
            sin_yaw = sin(Plant.yaw);

            % Before filtering - global coordinates
            global_x_before = xyz_before(:,1) * cos_yaw - xyz_before(:,2) * sin_yaw + Plant.X;
            global_y_before = xyz_before(:,1) * sin_yaw + xyz_before(:,2) * cos_yaw + Plant.Y;
            global_z_before = xyz_before(:,3) + trans(3);

            % After filtering - global coordinates
            global_x_after = xyz_after(:,1) * cos_yaw - xyz_after(:,2) * sin_yaw + Plant.X;
            global_y_after = xyz_after(:,1) * sin_yaw + xyz_after(:,2) * cos_yaw + Plant.Y;
            global_z_after = xyz_after(:,3) + trans(3);

            % Convert detection positions to global coordinates
            detection_x_global = [];
            detection_y_global = [];
            if nargin > 5 && ~isempty(detections) && size(detections, 1) >= 2
                % detections is [x; y; radius] in global coordinates already
                detection_x_global = detections(1, :);
                detection_y_global = detections(2, :);
            end

            % Extract wall cluster points for visualization
            wall_points_x = [];
            wall_points_y = [];
            wall_points_z = [];
            if nargin > 6 && ~isempty(wall_indices) && nargin > 7 && ~isempty(labelLocation)
                for i = 1:length(wall_indices)
                    cluster_id = wall_indices(i);
                    cluster_mask = (labelLocation(4, :) == cluster_id);
                    wall_points_x = [wall_points_x, labelLocation(1, cluster_mask)];
                    wall_points_y = [wall_points_y, labelLocation(2, cluster_mask)];
                    wall_points_z = [wall_points_z, labelLocation(3, cluster_mask)];
                end
            end

            % Plot before filtering (3D)
            subplot(1,2,1);
            scatter3(global_x_before, global_y_before, global_z_before, 2, 'b', 'filled');
            hold on;
            scatter3(Plant.X, Plant.Y, Plant.Z, 100, 'ro', 'filled', 'MarkerEdgeColor', 'k', 'LineWidth', 2); % Robot position

            % Plot wall cluster points if available
            if ~isempty(wall_points_x)
                scatter3(wall_points_x, wall_points_y, wall_points_z, 8, 'black', 'filled', 'MarkerFaceAlpha', 0.6);
            end

            % Plot detection centers if available
            legend_entries = {'LiDAR Points', 'Robot'};
            title_parts = {sprintf('BEFORE Wall Filtering\n%d points', length(global_x_before))};

            if ~isempty(wall_points_x)
                legend_entries{end+1} = 'Wall Clusters';
                title_parts{end+1} = sprintf('%d walls', length(wall_indices));
            end

            if ~isempty(detection_x_global)
                detection_z = Plant.Z * ones(size(detection_x_global)); % Use robot Z for detection height
                scatter3(detection_x_global, detection_y_global, detection_z, 100, 'y', 'diamond', ...
                    'filled', 'MarkerEdgeColor', 'k', 'LineWidth', 2);
                legend_entries{end+1} = 'Detection Centers';
                title_parts{end+1} = sprintf('%d detections', length(detection_x_global));
            end

            title_str = strjoin(title_parts, ', ');

            title(title_str);
            xlabel('X (m)');
            ylabel('Y (m)');
            zlabel('Z (m)');
            axis equal;
            grid on;
            view(45, 30);  % Nice 3D viewing angle
            legend(legend_entries, 'Location', 'best');

            % Plot after filtering (3D)
            subplot(1,2,2);
            scatter3(global_x_after, global_y_after, global_z_after, 2, 'g', 'filled');
            hold on;
            scatter3(Plant.X, Plant.Y, Plant.Z, 100, 'ro', 'filled', 'MarkerEdgeColor', 'k', 'LineWidth', 2); % Robot position

            % Plot wall cluster points if available
            if ~isempty(wall_points_x)
                scatter3(wall_points_x, wall_points_y, wall_points_z, 8, 'black', 'filled', 'MarkerFaceAlpha', 0.6);
            end

            % Plot detection centers if available
            legend_entries_after = {'Filtered Points', 'Robot'};
            title_parts_after = {sprintf('AFTER Wall Filtering\n%d points (%.1f%% removed)', ...
                length(global_x_after), 100*(1-length(global_x_after)/length(global_x_before)))};

            if ~isempty(wall_points_x)
                legend_entries_after{end+1} = 'Wall Clusters';
                title_parts_after{end+1} = sprintf('%d walls filtered', length(wall_indices));
            end

            if ~isempty(detection_x_global)
                detection_z = Plant.Z * ones(size(detection_x_global)); % Use robot Z for detection height
                scatter3(detection_x_global, detection_y_global, detection_z, 100, 'y', 'diamond', ...
                    'filled', 'MarkerEdgeColor', 'k', 'LineWidth', 2);
                legend_entries_after{end+1} = 'Detection Centers';
                title_parts_after{end+1} = sprintf('%d detections', length(detection_x_global));
            end

            title_str_after = strjoin(title_parts_after, ', ');

            title(title_str_after);
            xlabel('X (m)');
            ylabel('Y (m)');
            zlabel('Z (m)');
            axis equal;
            grid on;
            view(45, 30);  % Same 3D viewing angle
            legend(legend_entries_after, 'Location', 'best');

            % Make sure both plots have same axis limits (3D)
            % subplot(1,2,1);
            % xlims1 = xlim; ylims1 = ylim; zlims1 = zlim;
            % subplot(1,2,2);
            % xlims2 = xlim; ylims2 = ylim; zlims2 = zlim;

            % common_xlim = [min(xlims1(1), xlims2(1)), max(xlims1(2), xlims2(2))];
            % common_ylim = [min(ylims1(1), ylims2(1)), max(ylims1(2), ylims2(2))];
            % common_zlim = [min(zlims1(1), zlims2(1)), max(zlims1(2), zlims2(2))];

            % subplot(1,2,1); xlim(common_xlim); ylim(common_ylim); zlim(common_zlim);
            % subplot(1,2,2); xlim(common_xlim); ylim(common_ylim); zlim(common_zlim);

            % Plot 3D bounding boxes on the filtered points subplot
            if nargin > 4 && ~isempty(boundingBoxes)
                subplot(1,2,2);
                hold on;

                for i = 1:length(boundingBoxes)
                    bbox = boundingBoxes{i};
                    center = bbox.center;
                    dimensions = bbox.dimensions;

                    % Draw 3D bounding box
                    obj.plot3DBoundingBox(center, dimensions, bbox.orientation);

                    % Add cluster ID label at center
                    text(center(1), center(2), center(3), sprintf('%d', bbox.clusterID), ...
                        'Color', 'red', 'FontSize', 12, 'FontWeight', 'bold', ...
                        'HorizontalAlignment', 'center');
                end

                % Update legend and title with all elements
                legend_bbox = legend_entries_after;
                legend_bbox{end+1} = 'Bounding Boxes';
                legend(legend_bbox, 'Location', 'best');

                title_bbox_parts = title_parts_after;
                title_bbox_parts{end+1} = sprintf('%d objects', length(boundingBoxes));
                title_str_bbox = strjoin(title_bbox_parts, ', ');
                title(strrep(title_str_bbox, 'AFTER Wall Filtering', 'AFTER Wall Filtering + 3D Bounding Boxes'));
            end

            drawnow;
        end

        function plot3DBoundingBox(obj, center, dimensions, orientation)
            % Plot a 3D bounding box
            % center: [x, y, z] center position
            % dimensions: [length, width, height]
            % orientation: rotation around Z-axis in radians

            length_val = dimensions(1);
            width_val = dimensions(2);
            height_val = dimensions(3);

            % Define the 8 vertices of a box centered at origin
            vertices = [
                -length_val/2, -width_val/2, -height_val/2;  % 1: bottom back left
                length_val/2, -width_val/2, -height_val/2;  % 2: bottom back right
                length_val/2,  width_val/2, -height_val/2;  % 3: bottom front right
                -length_val/2,  width_val/2, -height_val/2;  % 4: bottom front left
                -length_val/2, -width_val/2,  height_val/2;  % 5: top back left
                length_val/2, -width_val/2,  height_val/2;  % 6: top back right
                length_val/2,  width_val/2,  height_val/2;  % 7: top front right
                -length_val/2,  width_val/2,  height_val/2]; % 8: top front left

            % Rotation matrix around Z-axis
            cos_theta = cos(orientation);
            sin_theta = sin(orientation);
            R = [cos_theta, -sin_theta, 0;
                sin_theta,  cos_theta, 0;
                0,          0,         1];

            % Rotate vertices
            rotated_vertices = (R * vertices')';

            % Translate to center position
            final_vertices = rotated_vertices + center;

            % Define the 12 edges of the box (pairs of vertex indices)
            edges = [
                1,2; 2,3; 3,4; 4,1;  % bottom face
                5,6; 6,7; 7,8; 8,5;  % top face
                1,5; 2,6; 3,7; 4,8]; % vertical edges

            % Plot the 6 faces of the box as patches (surfaces)
            faces = [
                1,2,3,4;  % bottom face
                5,8,7,6;  % top face
                1,5,6,2;  % back face
                4,3,7,8;  % front face
                1,4,8,5;  % left face
                2,6,7,3]; % right face

            % Plot each face as a semi-transparent patch
            for i = 1:size(faces, 1)
                face_vertices = final_vertices(faces(i,:), :);
                patch(face_vertices(:,1), face_vertices(:,2), face_vertices(:,3), ...
                    'red', 'FaceAlpha', 0.3, 'EdgeColor', 'red', 'LineWidth', 2);
            end
        end

        function boundingBoxes = generateBoundingBoxes(obj, points, labels, numClusters)
            % Generate bounding boxes around clustered point clouds
            % Input: points - Nx3 point cloud [x,y,z]
            %        labels - Nx1 cluster labels
            %        numClusters - number of clusters
            % Output: boundingBoxes - struct array with bounding box info

            boundingBoxes = [];

            if isempty(points) || numClusters == 0
                return;
            end

            % Initialize bounding boxes cell array
            boundingBoxes = {};
            bbox_count = 0;

            for i = 1:numClusters
                % Get points belonging to this cluster
                cluster_mask = (labels == i);
                cluster_points = points(cluster_mask, :);

                if size(cluster_points, 1) < 3  % Need at least 3 points for meaningful bounding box
                    continue;
                end

                % Calculate 2D bounding box (ignore Z for now, focus on X-Y plane)
                x_coords = cluster_points(:, 1);
                y_coords = cluster_points(:, 2);
                z_coords = cluster_points(:, 3);

                % Simple axis-aligned bounding box
                x_min = min(x_coords); x_max = max(x_coords);
                y_min = min(y_coords); y_max = max(y_coords);
                z_min = min(z_coords); z_max = max(z_coords);

                % Calculate center and dimensions
                center_x = (x_min + x_max) / 2;
                center_y = (y_min + y_max) / 2;
                center_z = (z_min + z_max) / 2;

                width = x_max - x_min;   % X dimension
                length = y_max - y_min;  % Y dimension
                height = z_max - z_min;  % Z dimension

                % Calculate oriented bounding box using PCA for better fit
                if size(cluster_points, 1) >= 5  % Need sufficient points for PCA
                    % Center the points
                    centered_points = cluster_points - mean(cluster_points, 1);

                    % Perform PCA on X-Y coordinates only
                    [coeff, ~, ~] = pca(centered_points(:, 1:2));

                    % Get the principal directions
                    main_axis = coeff(:, 1);  % First principal component
                    orientation = atan2(main_axis(2), main_axis(1));  % Angle in radians

                    % Project points onto principal axes to get oriented dimensions
                    proj_main = centered_points(:, 1:2) * coeff(:, 1);
                    proj_minor = centered_points(:, 1:2) * coeff(:, 2);

                    oriented_length = max(proj_main) - min(proj_main);
                    oriented_width = max(proj_minor) - min(proj_minor);
                else
                    % Fallback to axis-aligned
                    orientation = 0;
                    oriented_length = length;
                    oriented_width = width;
                end

                % Calculate corner points for visualization
                corners = obj.calculateBoundingBoxCorners([center_x, center_y], ...
                    oriented_length, oriented_width, orientation);

                % Store bounding box information
                bbox.center = [center_x, center_y, center_z];
                bbox.dimensions = [oriented_length, oriented_width, height];
                bbox.orientation = orientation;  % Rotation around Z-axis
                bbox.corners = corners;
                bbox.pointCount = size(cluster_points, 1);
                bbox.clusterID = i;

                bbox_count = bbox_count + 1;
                boundingBoxes{bbox_count} = bbox;
            end


        end

        function corners = calculateBoundingBoxCorners(obj, center, length, width, orientation)
            % Calculate 2D bounding box corner points
            % Returns 4x2 matrix of corner coordinates

            % Half dimensions
            half_length = length / 2;
            half_width = width / 2;

            % Corner points in local coordinates (before rotation)
            local_corners = [-half_length, -half_width;   % Bottom-left
                half_length, -half_width;    % Bottom-right
                half_length,  half_width;    % Top-right
                -half_length,  half_width];   % Top-left

            % Rotation matrix
            cos_theta = cos(orientation);
            sin_theta = sin(orientation);
            R = [cos_theta, -sin_theta; sin_theta, cos_theta];

            % Rotate and translate corners
            corners = (R * local_corners')' + center;
        end

        function [filtered_detections, wall_indices, relabeled_labelLocation] = filterWallClusters(obj, detections, labelLocation, numClusters)
            % Filter out wall clusters from detections based on geometric analysis
            % Input: detections - [x; y; radius] detection centers
            %        labelLocation - [x, y, z, label] point cloud with cluster labels
            %        numClusters - total number of clusters
            % Output: filtered_detections - detections with walls removed
            %         wall_indices - indices of detected wall clusters

            if isempty(detections) || numClusters == 0
                filtered_detections = detections;
                wall_indices = [];
                relabeled_labelLocation = labelLocation;  % Assign output argument
                return;
            end

            wall_indices = [];
            insufficient_indices = [];



            % Debug visualization flag
            debug_clusters = false; % Set to false to disable cluster debugging
            if debug_clusters && numClusters > 0
                figure('Name', sprintf('Cluster Analysis Debug - Frame %d', obj.cnt), ...
                    'Position', [50, 50, 1400, 800]);
            end

            for i = 1:numClusters
                % Extract points belonging to this cluster
                cluster_mask = (labelLocation(4, :) == i);
                cluster_points = labelLocation(1:3, cluster_mask)'; % [N x 3] format

                if size(cluster_points, 1) < 20  % Need minimum points for analysis
                    % Plot insufficient point cluster for debugging
                    if debug_clusters
                        obj.plotSingleCluster(cluster_points, i, 'insufficient', numClusters);
                    end

                    % Mark cluster for removal
                    insufficient_indices(end+1) = i;
                    continue;
                end

                % Analyze geometric properties
                isWall = obj.classifyClusterAsWall(cluster_points, i);

                % Debug visualization for this cluster
                if debug_clusters
                    obj.plotSingleCluster(cluster_points, i, isWall, numClusters);
                end

                if isWall
                    wall_indices(end+1) = i;
                end
            end

            % Remove clusters (both wall and insufficient) from detections
            % Assuming direct 1:1 mapping between cluster index and detection index
            clusters_to_remove = [wall_indices, insufficient_indices];
            valid_detection_mask = true(1, size(detections, 2));

            for cluster_idx = clusters_to_remove
                if cluster_idx <= size(detections, 2)
                    valid_detection_mask(cluster_idx) = false;
                end
            end

            % Filter detections
            filtered_detections = detections(:, valid_detection_mask);

            % Create relabeled labelLocation with new sequential cluster IDs
            relabeled_labelLocation = labelLocation;

            % Create mapping from old cluster IDs to new sequential IDs
            valid_clusters = setdiff(1:numClusters, clusters_to_remove);

            % Reset all labels to 0 first
            relabeled_labelLocation(4, :) = 0;

            % Reassign new sequential labels (1,2,3...) to kept clusters
            for new_id = 1:length(valid_clusters)
                old_id = valid_clusters(new_id);
                % Find points belonging to old cluster ID and assign new ID
                old_cluster_mask = (labelLocation(4, :) == old_id);
                relabeled_labelLocation(4, old_cluster_mask) = new_id;
            end

            % Remove points from filtered-out clusters (set to label 0)
            for removed_cluster = clusters_to_remove
                removed_mask = (labelLocation(4, :) == removed_cluster);
                relabeled_labelLocation(4, removed_mask) = 0;
            end

                 end

        function isWall = classifyClusterAsWall(obj, cluster_points, cluster_id)
            % Classify cluster as wall based on geometric properties
            % Input: cluster_points - [N x 3] array of points [x, y, z]
            %        cluster_id - cluster identifier for debugging

            % Calculate basic statistics
            center = mean(cluster_points, 1);
            point_count = size(cluster_points, 1);

            % 1. SIZE ANALYSIS
            x_range = max(cluster_points(:,1)) - min(cluster_points(:,1));
            y_range = max(cluster_points(:,2)) - min(cluster_points(:,2));
            z_range = max(cluster_points(:,3)) - min(cluster_points(:,3));

            max_dimension = max([x_range, y_range]);
            min_dimension = min([x_range, y_range]);

            % 2. ASPECT RATIO ANALYSIS
            if min_dimension < 0.05  % Avoid division by zero
                aspect_ratio = inf;
            else
                aspect_ratio = max_dimension / min_dimension;
            end

            % 3. PCA LINEARITY ANALYSIS
            centered_points = cluster_points(:, 1:2) - mean(cluster_points(:, 1:2), 1);
            if point_count >= 3
                [coeff, ~, explained] = pca(centered_points);
                linearity = explained(1) / sum(explained); % Ratio of first principal component

                % Calculate scatter perpendicular to main axis
                proj_main = centered_points * coeff(:, 1);
                proj_minor = centered_points * coeff(:, 2);
                perpendicular_std = std(proj_minor);
            else
                linearity = 0.5;
                perpendicular_std = 0.1;
            end

            % 4. HEIGHT ANALYSIS
            height_range = z_range;

            % 5. DENSITY ANALYSIS
            area_2d = x_range * y_range;
            if area_2d > 0
                point_density = point_count / area_2d;
            else
                point_density = 0;
            end

            % CLASSIFICATION CRITERIA
            % Pedestrian expectations: 0.3-0.8m width, 0.5-1.2m length, ~1.7m height
            % Wall characteristics: long, thin, tall, linear

            wall_votes = 0;
            total_criteria = 0;

            % Criterion 1: Aspect Ratio (walls are long and thin)
            if aspect_ratio > 6.0  % Very elongated
                wall_votes = wall_votes + 2;
            elseif aspect_ratio > 2.0  % Somewhat elongated
                wall_votes = wall_votes + 1;
            end
            total_criteria = total_criteria + 2;

            % % Criterion 2: Size (walls are often larger than pedestrians)
            % if max_dimension > 2.0  % Much larger than typical pedestrian
            %     wall_votes = wall_votes + 2;
            % elseif max_dimension > 1.5  % Larger than typical pedestrian
            %     wall_votes = wall_votes + 1;
            % end
            % total_criteria = total_criteria + 2;

            % Criterion 3: Linearity (walls are more linear)
            if linearity > 0.95  % Very linear
                wall_votes = wall_votes + 2;
            elseif linearity > 0.75  % Somewhat linear
                wall_votes = wall_votes + 1;
            end
            total_criteria = total_criteria + 2;

            % Criterion 4: Perpendicular spread (walls have low spread perpendicular to main axis)
            if perpendicular_std < 0.1  % Very tight perpendicular spread
                wall_votes = wall_votes + 2;
            elseif perpendicular_std < 0.2  % Moderate perpendicular spread
                wall_votes = wall_votes + 1;
            end
            total_criteria = total_criteria + 2;

            % % Criterion 5: Height (walls are often taller)
            % if height_range > 2.5  % Much taller than pedestrian
            %     wall_votes = wall_votes + 1;
            % end
            % total_criteria = total_criteria + 1;

            % Criterion 6: Point count (walls often have many points)
            % if point_count > 100  % Very dense cluster
            %     wall_votes = wall_votes + 1;
            % end
            % total_criteria = total_criteria + 1;

            % Final classification
            wall_confidence = wall_votes / total_criteria;
            isWall = wall_confidence > 0.8;  % 60% confidence threshold

        end

        function plotSingleCluster(obj, cluster_points, cluster_id, isWall, numClusters)
            % Plot individual cluster for debugging wall classification
            % Input: cluster_points - [N x 3] array of points [x, y, z]
            %        cluster_id - cluster identifier
            %        isWall - classification result
            %        numClusters - total number of clusters for subplot layout

            % Calculate subplot layout
            cols = min(4, numClusters);
            rows = ceil(numClusters / cols);

            subplot(rows, cols, cluster_id);

            % Plot cluster points
            if ischar(isWall) && strcmp(isWall, 'insufficient')
                scatter3(cluster_points(:,1), cluster_points(:,2), cluster_points(:,3), ...
                    20, 'red', 'filled', 'MarkerFaceAlpha', 0.7);
                title_color = 'red';
                classification = 'Insufficient PC';
            elseif isWall
                scatter3(cluster_points(:,1), cluster_points(:,2), cluster_points(:,3), ...
                    20, 'red', 'filled', 'MarkerFaceAlpha', 0.7);
                title_color = 'red';
                classification = 'WALL';
            else
                scatter3(cluster_points(:,1), cluster_points(:,2), cluster_points(:,3), ...
                    20, 'green', 'filled', 'MarkerFaceAlpha', 0.7);
                title_color = 'green';
                classification = 'OBJECT';
            end

            hold on;

            % Calculate and show geometric properties
            center = mean(cluster_points, 1);
            x_range = max(cluster_points(:,1)) - min(cluster_points(:,1));
            y_range = max(cluster_points(:,2)) - min(cluster_points(:,2));
            z_range = max(cluster_points(:,3)) - min(cluster_points(:,3));

            max_dimension = max([x_range, y_range]);
            min_dimension = min([x_range, y_range]);

            if min_dimension < 0.05
                aspect_ratio = inf;
            else
                aspect_ratio = max_dimension / min_dimension;
            end

            % Plot cluster center
            scatter3(center(1), center(2), center(3), 100, 'black', 'diamond', ...
                'filled', 'MarkerEdgeColor', 'white', 'LineWidth', 1);

            % Plot bounding box
            x_min = min(cluster_points(:,1)); x_max = max(cluster_points(:,1));
            y_min = min(cluster_points(:,2)); y_max = max(cluster_points(:,2));
            z_min = min(cluster_points(:,3)); z_max = max(cluster_points(:,3));

            % Draw bounding box edges
            box_corners = [
                x_min, y_min, z_min; x_max, y_min, z_min; x_max, y_max, z_min; x_min, y_max, z_min;
                x_min, y_min, z_max; x_max, y_min, z_max; x_max, y_max, z_max; x_min, y_max, z_max
                ];

            % Bottom face
            plot3([box_corners([1,2,3,4,1], 1)], [box_corners([1,2,3,4,1], 2)], [box_corners([1,2,3,4,1], 3)], ...
                'k-', 'LineWidth', 1);
            % Top face
            plot3([box_corners([5,6,7,8,5], 1)], [box_corners([5,6,7,8,5], 2)], [box_corners([5,6,7,8,5], 3)], ...
                'k-', 'LineWidth', 1);
            % Vertical edges
            for j = 1:4
                plot3([box_corners(j, 1), box_corners(j+4, 1)], ...
                    [box_corners(j, 2), box_corners(j+4, 2)], ...
                    [box_corners(j, 3), box_corners(j+4, 3)], 'k-', 'LineWidth', 1);
            end

            % Formatting
            axis equal;
            grid on;
            xlabel('X (m)');
            ylabel('Y (m)');
            zlabel('Z (m)');

            % Title with cluster info
            title(sprintf('Cluster %d: %s\nSize: %.2fx%.2fx%.2f m\nAspect: %.1f, Points: %d', ...
                cluster_id, classification, x_range, y_range, z_range, aspect_ratio, size(cluster_points, 1)), ...
                'Color', title_color, 'FontWeight', 'bold');

            % Set consistent view angle
            view(45, 30);

            drawnow;
        end

        function detection_idx = findDetectionForCluster(obj, detections, cluster_points)
            % Find which detection corresponds to this cluster
            % Simple approach: find detection closest to cluster centroid

            if isempty(detections) || isempty(cluster_points)
                detection_idx = 0;
                return;
            end

            cluster_center = mean(cluster_points(:, 1:2), 1);
            detection_centers = detections(1:2, :)';  % [N x 2]

            % Calculate distances from cluster center to all detections
            distances = sqrt(sum((detection_centers - cluster_center).^2, 2));

            % Find closest detection
            [min_dist, detection_idx] = min(distances);

            % Only associate if reasonably close (within 1 meter)
            if min_dist > 1.0
                detection_idx = 0;
            end
        end

        function filtered_xyz = filterWallPoints(obj, xyz, Plant)
            % Filter out points that correspond to walls in the occupancy map

            if isempty(obj.occupancyMatrix) || isempty(xyz)
                filtered_xyz = xyz;
                return;
            end

            % Convert LiDAR points from local to global coordinates
            global_points = xyz;

            % Transform points to global coordinate system
            cos_yaw = cos(Plant.yaw);
            sin_yaw = sin(Plant.yaw);

            % Apply rotation and translation to get global coordinates
            global_x = global_points(:,1) * cos_yaw - global_points(:,2) * sin_yaw + Plant.X;
            global_y = global_points(:,1) * sin_yaw + global_points(:,2) * cos_yaw + Plant.Y;

            % Convert global coordinates to grid coordinates
            valid_mask = true(size(global_x));

            for i = 1:length(global_x)
                try
                    % Use the occupancy map's coordinate conversion
                    grid_pos = world2grid(obj.occupancyMap, [global_x(i), global_y(i)]);
                    grid_r = grid_pos(1);
                    grid_c = grid_pos(2);

                    % Check if point is within map bounds
                    [rows, cols] = size(obj.occupancyMatrix);
                    if grid_r >= 1 && grid_r <= rows && grid_c >= 1 && grid_c <= cols
                        % Check if point is on a wall (occupied space)
                        occupancy_value = obj.occupancyMatrix(grid_r, grid_c);
                        if occupancy_value >= 0.5  % Wall threshold
                            valid_mask(i) = false;  % Filter out wall points
                        end
                    end
                catch
                    % Keep point if coordinate conversion fails
                    continue;
                end
            end

            % Return filtered points
            filtered_xyz = xyz(valid_mask, :);
        end
        
        function replanPathFromCurrentPosition(obj, Plant)
            % Replan path using current wheelchair position as start
            fprintf('[ESTIMATE] Replanning path from current position [%.2f, %.2f]\n', Plant.X, Plant.Y);
            
            current_position = [Plant.X, Plant.Y]; % Current wheelchair position
            goal_position = []; % Default goal (will use elevator)
            
            % Calculate robot dimensions (same as constructor)
            wheel_width = 0.55/2;           % wheel_width from Control.m
            wheel_len_rear = 0.35;          % wheel_len_rear from Control.m  
            wheel_len_front = 0.76;         % wheel_len_front from Control.m
            robot_width = wheel_width * 2;  % Total width = 0.55m
            robot_length = wheel_len_rear + wheel_len_front; % Total length = 1.11m
            
            % Try A* pathfinding first, fallback to original if it fails
            try
                [waypoint, ~, ~, ~, ~] = PathSetting_AStar(current_position, goal_position, robot_width, robot_length);
                fprintf('[ESTIMATE] A* replanning SUCCESS: Generated %d waypoints from [%.2f, %.2f]\n', size(waypoint, 1), current_position(1), current_position(2));
            catch ME
                fprintf('[ESTIMATE] A* replanning FAILED (%s), using simple fallback path\n', ME.message);
                % Simple fallback: current position -> elevator
                waypoint = [current_position; 30.0, 12.5]; % Current -> elevator center
            end
            
            % Update waypoints in SharedControlMode
            obj.sharedControlMode.setWaypoints(waypoint);
            fprintf('[ESTIMATE] Updated SharedControlMode with %d new waypoints\n', size(waypoint, 1));
        end
        
        function resetAllTrackers(obj)
            % Reset all tracking-related variables to clean state
            fprintf('[ESTIMATE] Resetting all trackers to clean state\n');
            
            % Reset tracking variables
            obj.Allxhat = [];
            
            % Reset track storage to clean state
            numAllowableTracks = 50; % Same as constructor
            obj.trackStorage.Logical = false(numAllowableTracks,1);
            obj.trackStorage.CheckAssign = zeros(numAllowableTracks, 1);
            obj.trackStorage.States = zeros(obj.DimSta,numAllowableTracks);
            obj.trackStorage.P = cell(numAllowableTracks,1);
            
            % Reset tracker instances (clone fresh filters)
            obj.trackStorage.tracker = arrayfun(@(~) clone(obj.ellipsefilter), 1:numAllowableTracks, 'UniformOutput', false)';
            
            % Reset temporary storage
            numAllowabletempTracks = 20; % Same as constructor
            obj.tempStorage.tracker = arrayfun(@(~) clone(obj.tempFilter), 1:numAllowabletempTracks, 'UniformOutput', false)';
            
            % Reset new track candidates
            obj.newTrackCandidates = struct('Obs', {}, 'Count', {}, 'Buffer', {});
            
            fprintf('[ESTIMATE] All trackers reset - ready for fresh tracking\n');
        end
        

    end
end