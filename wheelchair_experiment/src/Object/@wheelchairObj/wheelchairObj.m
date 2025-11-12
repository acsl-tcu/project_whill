classdef wheelchairObj < handle
    properties
        App
        AppMode
        LoopMode
        FilePath
        FileName
        Display
        DispInterval
        DispFunction
        DataSave
        SaveFunction
        StartTime
        EndTime
        DeltaT
        InitPose
        RosbagFullPath
        ControllerObj
        EstimatorObj
        DataObj
        Datadir
        UserModeRequest  % Store user mode requests from menu
        pauseRequested   % Flag for keyboard interrupt detection (increased responsiveness)
    end
    properties (Access = private)
        Mode
        Count
        Sensor
%         Datadir
        natnetObj
        Autoware
    end
    properties (Access = private, Constant)
        ConstArg  = 4;
        Argument  = 7;
        % 
        appMode   = 1;
        loopMode  = 2;
        Te        = 3;
        Ts        = 4;
        IPAddr	  = 5;
        Md		  = 6;
        SensorNum = 7;
        Rgt		  = 8;
        StartState= 9;
        Rosbag    = 10;
        MySavePath= 11;
        MyFileName= 12;
        MyCnt     = 13;
        MyCntVar  = 14;
        MyEst     = 15;
        MyEstVar  = 16;
        AutowareNum = 11;
        % Senser Number
        Prime	  = 1;
        LiDAR	  = 2;
        RealSence = 3;
        autoware  = 1;
        Names     = {'X','Y','Z','roll','pitch','yaw','qx','qy','qz','qw','V','ComputationTime'};
        est       = colon(1,10);
        ctl       = colon(11,12);
        % Plot configuration
        MarkerSize= 5;
        ColorNum  = 16;
    end
    methods(Static)
%         function Datadir = folderInfo(FilePath, FileName)
%             % filesep...OS?��ɂ�?��?��?��\?��?��/?��?��?��?��?��ς�?��
%             Datadir	= strcat(FilePath, filesep, datestr(datetime('today'), 'yyyymmdd'), filesep, FileName);
%         end
        function [] = waitPressEnterkey()
            kbhit('stop'); 
            kbhit('init');
            disp('Press "Enter" key to start simulation/expriment.');
            waitTime = 1.e-3;
            while 1
                event = kbhit('event');
                key = get(event, 'KeyCode');
                pause(waitTime);
                if ~isempty(key) && key == 10
                    break;
                end
            end
        end
    end
    methods
        % varagin...?��ϓ�?��͂�?��\?��ƂȂ�֐�
        function obj = wheelchairObj(varargin)
            % ?��x?��?��?��?��?��?��
            warning('off','backtrace')
            % ?��?��?��͈�?��?��?��?��m?��ȏ�n?��ȉ�?��ł�?��邩?��?��?��m?��F?��?��?��?��?��?��?��
            % ?��?��ɕς�?��?��?��?��悤?��ɂ�?��̏�?��?��?��?��?��?��?��?��?��Ă�?��?��
            narginchk(obj.ConstArg, obj.Argument + obj.ConstArg);
            % ?��v?��?��?��p?��e?��B?��ɑ�?��
            obj.AppMode     = varargin{obj.appMode};
            obj.LoopMode    = varargin{obj.loopMode};
            obj.Mode        = 1;
            obj.FilePath	= pwd;
            obj.FileName	= string(datetime('now','TimeZone','local','Format','HH-mm-ss'));
            obj.Display		= true;
            obj.DispInterval= 1.;
            obj.Count		= 0.;
            obj.StartTime	= 0.;
            obj.EndTime		= varargin{obj.Te};
            obj.DeltaT		= varargin{obj.Ts};
            obj.Datadir     = '';
            obj.UserModeRequest = struct('requested', false); % Initialize user mode request
            obj.pauseRequested = false; % Initialize pause flag for keyboard detection
            info.HostIP		= '';
            info.ROSHostIP  = varargin{obj.IPAddr}.ROSHostIP;
            if varargin{obj.appMode}
                obj.App = ElectricWheelchairApp(varargin);
            else
                %- Mode Selection -%
                % obj.Argument...?��?��?��Ԃ⍏?��ݎ�?��ԂȂǁC?��Œ�?��?��K?��v?��Ȃ�?��̂�?��o?��?��?��Ă�?��?��
                if nargin == (obj.Argument + obj.ConstArg)
                    %Mode?��?��?��?��
                    obj.Mode = varargin{obj.Md};
                    %- Acquisition and setting of IP address -%
                    info.HostIP		 = varargin{obj.IPAddr}.HostIP;
                    info.ROSHostIP   = varargin{obj.IPAddr}.ROSHostIP;
                    % ?��?��?��?��?��?��IP?��?��?��?��?��?��Ɏ擾?��?��?��?��֐�
                    IP = split(info.HostIP, ".");
                    client_ips = IPAddress.SearchOwnIP(join({IP{1:3}, '\d+'}, "."));
                    if ~isempty(client_ips)
                        info.ClientIP = client_ips{1};  % Take first matching IP (handles multiple network interfaces)
                    else
                        info.ClientIP = '';
                    end
                    IP = split(info.ROSHostIP, ".");
                    ros_client_ips = IPAddress.SearchOwnIP(join({IP{1:3}, '\d+'}, "."));
                    if ~isempty(ros_client_ips)
                        info.ROSClientIP = ros_client_ips{1};  % Take first matching IP (handles multiple network interfaces)
                    else
                        info.ROSClientIP = '';
                    end
                    % ?��?��?��?��?��ʒu?��?��ݒ�
                    info.StartState  = varargin{obj.StartState};
                    % ?��p?��?��?��?��?��?��?��Ōv?��Z?��?��?��?��Ƃ�?��Ɏg?��p
                    obj.InitPose     = varargin{obj.StartState};
                    sensor = varargin{obj.SensorNum};
                    autoware = varargin{obj.AutowareNum};
                    obj.Sensor = sensor;
                    obj.Autoware = autoware;
                    if all(~sensor) && all(~autoware)
                        % ?��?��?��?��?��?��̓Z?��?��?��T?��?��?��g?��?��?��?��?��?��!!
                        error('No sensors are switched on. Please turn on either sensor.');
                    end
                    switch obj.Mode
                        % ?��N?��?��?��X?��̒�?��ŃN?��?��?��X?��?��ړI?��ɉ�?��?��?��ČĂяo?��?��
                        case {'Numerical', 1}
                            disp('You selected numerical simulation.');
                            obj.DataObj = simulationObj(info, obj.StartTime, obj.EndTime, obj.DeltaT, sensor, obj.Mode);
                        case {'Physics',   2}
                            disp('You selected physics simulation.');
                            obj.DataObj = rosConnectorObj(info, obj.Mode, sensor, autoware);
                        case {'Expriment', 3}
                            disp('You selected expriment.');
                            if sensor(obj.Prime) == true
                                obj.natnetObj = natnetConnectorObj(info, sensor);
                                obj.natnetObj.ControlRigid = varargin{obj.Rgt};
                            end
                            obj.DataObj = rosConnectorObj(info, obj.Mode, sensor, autoware);
                        case {'Offline',  4}
                            disp('You selected offline simulation.');
                            if sensor(obj.Prime) == true
                                error('Prime data are not provided for offline simulation.');
                            end
                            obj.RosbagFullPath = varargin{obj.Rosbag};
                            obj.DataObj = rosBagPlayObj(obj.Te,obj. Ts, obj.Mode, sensor, obj.RosbagFullPath);
                        otherwise
                            error('Wrong number. Select the correct number again.');
                    end
                else
                    error('There are no enough arguments.');
                end
            end
        end
        ret = makeFolder(obj)
        ret = mainLoop(obj, varargin)
        ret = endProcessing(obj, varargin)
    end
    methods(Access = protected)
        ret = setParallel(obj)
        ret = executeCommand(obj)
        ret = integrateData(obj)
        ret = structGeneration(obj)
        ret = modeLogical(obj, Rawdata)
        []  = displayData(obj, T, RawData, EstimatedData, ControledData)
        []  = checkData(obj, Data, Md)
    end
end