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
%             % filesep...OS?ｿｽﾉゑｿｽ?ｿｽ?ｿｽ?ｿｽ\?ｿｽ?ｿｽ/?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾏゑｿｽ?ｿｽ
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
        % varagin...?ｿｽﾂ変難ｿｽ?ｿｽﾍゑｿｽ?ｿｽﾂ能?ｿｽﾆなゑｿｽﾖ撰ｿｽ
        function obj = wheelchairObj(varargin)
            % ?ｿｽx?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ
            warning('off','backtrace')
            % ?ｿｽ?ｿｽ?ｿｽﾍ茨ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽm?ｿｽﾂ以擾ｿｽn?ｿｽﾂ以会ｿｽ?ｿｽﾅゑｿｽ?ｿｽ驍ｩ?ｿｽ?ｿｽ?ｿｽm?ｿｽF?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ
            % ?ｿｽ?ｿｽﾉ変ゑｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ謔､?ｿｽﾉゑｿｽ?ｿｽﾌ擾ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾄゑｿｽ?ｿｽ?ｿｽ
            narginchk(obj.ConstArg, obj.Argument + obj.ConstArg);
            % ?ｿｽv?ｿｽ?ｿｽ?ｿｽp?ｿｽe?ｿｽB?ｿｽﾉ托ｿｽ?ｿｽ
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
            info.HostIP		= '';
            info.ROSHostIP  = varargin{obj.IPAddr}.ROSHostIP;
            if varargin{obj.appMode}
                obj.App = ElectricWheelchairApp(varargin);
            else
                %- Mode Selection -%
                % obj.Argument...?ｿｽ?ｿｽ?ｿｽﾔや刻?ｿｽﾝ趣ｿｽ?ｿｽﾔなど，?ｿｽﾅ抵ｿｽ?ｿｽ?ｿｽK?ｿｽv?ｿｽﾈゑｿｽ?ｿｽﾌゑｿｽ?ｿｽo?ｿｽ?ｿｽ?ｿｽﾄゑｿｽ?ｿｽ?ｿｽ
                if nargin == (obj.Argument + obj.ConstArg)
                    %Mode?ｿｽ?ｿｽ?ｿｽ?ｿｽ
                    obj.Mode = varargin{obj.Md};
                    %- Acquisition and setting of IP address -%
                    info.HostIP		 = varargin{obj.IPAddr}.HostIP;
                    info.ROSHostIP   = varargin{obj.IPAddr}.ROSHostIP;
                    % ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽIP?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾉ取得?ｿｽ?ｿｽ?ｿｽ?ｿｽﾖ撰ｿｽ
                    IP = split(info.HostIP, ".");
                    info.ClientIP    = cell2mat(IPAddress.SearchOwnIP(join({IP{1:3}, '\d+'}, ".")));
                    IP = split(info.ROSHostIP, ".");
                    info.ROSClientIP = cell2mat(IPAddress.SearchOwnIP(join({IP{1:3}, '\d+'}, ".")));
                    % ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾊ置?ｿｽ?ｿｽﾝ抵ｿｽ
                    info.StartState  = varargin{obj.StartState};
                    % ?ｿｽp?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾅ計?ｿｽZ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾆゑｿｽ?ｿｽﾉ使?ｿｽp
                    obj.InitPose     = varargin{obj.StartState};
                    sensor = varargin{obj.SensorNum};
                    autoware = varargin{obj.AutowareNum};
                    obj.Sensor = sensor;
                    obj.Autoware = autoware;
                    if all(~sensor) && all(~autoware)
                        % ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾂはセ?ｿｽ?ｿｽ?ｿｽT?ｿｽ?ｿｽ?ｿｽg?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ!!
                        error('No sensors are switched on. Please turn on either sensor.');
                    end
                    switch obj.Mode
                        % ?ｿｽN?ｿｽ?ｿｽ?ｿｽX?ｿｽﾌ抵ｿｽ?ｿｽﾅク?ｿｽ?ｿｽ?ｿｽX?ｿｽ?ｿｽﾚ的?ｿｽﾉ会ｿｽ?ｿｽ?ｿｽ?ｿｽﾄ呼び出?ｿｽ?ｿｽ
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