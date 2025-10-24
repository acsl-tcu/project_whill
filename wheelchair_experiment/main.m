% memo
% 5 0.6
% 10 -0.6
% 35 -0.6
% 25 7.3
% 10 7.3
% -10 5.5
% -10 4.5



%------------------------------------------------------------------------%
% main.m for numerical/physics simulation and experiment
% version 4.0.0
% 2019.7.12 Electric wheelchair group
% Advanced Control Systems Laboratory.
%------------------------------------------------------------------------%

%% Global configurations (path setup and cleanup)
clc; close all; clear global; clear variables;
clear mexLidarTracker; clear mexLidarTracker_mex; 
conf.pc = [ismac; isunix; ispc];
conf.mk = [":"; ":"; ";"];
conf.def= "AppData/Local/Temp/Editor";
conf.usr= "./src";
conf.fpath = split(path, conf.mk(conf.pc));
conf.fcheck = and(~contains(conf.fpath, matlabroot), ~contains(conf.fpath, conf.def));
rmpath(strjoin(conf.fpath(conf.fcheck), conf.mk(conf.pc)));
addpath(genpath(conf.usr));

%% User configurations (simulation mode, network, sensors, paths)
%{
%----- Configuration about IP address of Motive PC and ROS PC and so on -----%
% You can select the mode from numerical simulation, physics simulation, experiment and offline simulation by choosing "Mode".
% If you want to select the numerical simulation, you have to type the number "1" or "Numerical".
% The correspondences are as follows:
% "Mode = 1;" or "Mode = 'Numerical';" -> Numerical simulation,
% "Mode = 2;" or "Mode = 'Physics';"   -> Physics simulation,
% "Mode = 3;" or "Mode = 'Experiment';"-> Experiment,
% "Mode = 4;" or "Mode = 'Offline';"   -> Offline simulation.
% Then, when you selected the mode "Physics" or "Experiment", you have to type the ROS core IP address into "Addr.ROSHostIP".
% Also, type the Motive IP address into "Addr.HostIP" if you attempt your experiment .
% Be sure to specify the rigid body number on "RgtNum".
% In your numerical/offline simulations, "Te" and "dt" means the simulation end time and sampling time.
% You can use LiDAR and Prime differently by switching the "sensor" value between "true" and "false".
% "Startstate" is the initial position of an autonomous electric wheelchair in your numerical simulation.
% Specify the full path of the rosbag file in offline simulation in "RbPath".
% GOOD LUCK TO YOU!!
%}
appMode        = false;
loopMode       = false;
% addr.ROSHostIP = '192.168.1.6'; % Online
% addr.HostIP	   = '192.168.1.35'; % Online
addr.ROSHostIP = '127.0.0.1'; % Gazebo
addr.HostIP	   = '127.0.0.1'; % Gazebo
te             = 50;
dt             = 0.2;
rgtNum         = 1;
mode           = 2;             % 2:Gazebo, 3:Online
sensor(1)      = true;          %--> Prime (Gazebo)
sensor(2)      = true;          %--> LiDAR (Gazebo, online)
sensor(3)      = false;         %--> realSence
autoware(1)    = false;         %--> Autoware(Online)

% Prime=true(1),autoware=true(1)
%   ...Vehicle runs by Autoware(estimated) and get Autoware(estimated) and Prime(measured) position
% Prime=true(1),autoware=2 
%   ...Vehicle runs by Prime(measured) position and get Autoware(estimated) and Prime(measured) position
% Prime=false(0),autoware=1 
%   ...Vehicle runs by Autoware(estimated)

startstate     = [0; 0; 0];
rbPath         = "test.bag";
mySavePath     = './data';
mySaveFileName = datestr(now, 'yyyymmdd_HHMMSS_FFF');
% mySaveFileName = 'obstacle_turn';
warning('off','all');
Datadir        = strcat(mySavePath, filesep, datestr(datetime('today'), 'yyyymmdd'), filesep, mySaveFileName);
mkdir(Datadir);
	warning('on');
dataSave       = false;

saveFunction   = [];

display        = true;
dispInterval   = 0.5;

dispFunction   = [];

%% Initialize wheelchair object
obj = wheelchairObj(appMode, loopMode, te, dt, addr, mode, sensor, rgtNum, startstate, rbPath, autoware);

%% Configure display and data saving
obj.Display		= display;
obj.DispInterval= dispInterval;
obj.DispFunction= dispFunction;
obj.DataSave	= dataSave;
obj.SaveFunction= saveFunction;
obj.Datadir     = Datadir;

%% Create data folder
% If you need to output file of your simulation or experiment data, you have to name "obj.FileName".
% Then, the folder will be made by calling the function "makeFolder".
obj.FilePath = mySavePath;
obj.FileName = mySaveFileName;
folderPath   = makeFolder(obj);

%% Initialize core system components
% Create shared control mode instance
sharedControlMode = SharedControlMode('path_following');

% Load occupancy map once and share between Estimate and Control (avoid redundant loading)
map_data = load('map2.mat');
occupancyMap = map_data.map;

obj.ControllerObj = Control(te,dt,mode,rgtNum,Datadir,sensor,autoware,sharedControlMode,occupancyMap);
obj.EstimatorObj = Estimate(dt,mode,Datadir,sharedControlMode,occupancyMap);

%% Wait for user confirmation
obj.waitPressEnterkey();

%% Execute main control loop
data = mainLoop(obj);

%% Plot and save results
if ~loopMode
    disp('Plot result.'); % array of character vectors, or character array.

     plotResult(folderPath);
     myplotResult(folderPath);
end
disp('This is end of simulation/expriment.');
% 　　　　　 　 , -､ ＿＿＿　 __
% 　　　　　　 _〉　´　　　　 ｀(　 l_
% 　　　　 ,.　´　　　 　 　 　 　 　 `､
% 　　 　 ;′　　　　　　　　　　　　　ﾞ:,
% 　　　 :　　　　 '´o　　　o"¨　　　　　　,
% 　　　 {　　　　⌒　　　⌒ 　　　　　 }
% 　　　人　/:/:/:　｀t^ァ´ /:/:/:　　 /⌒i
% 　　　　 ＞　　　　 ｀´　　　　　　 /ー ´
% 　　　　(__人　　　 　 　 　 　 　 /
% 　　　　　　　＼　　　　　　　　 /_)
% 　　　　　 　 　 ｀T__= ､　　　／
% 　　　　　 　 , -､ ＿＿＿　 __
% 　　　　　　 _〉　´　　　　 ｀(　 l_
% 　　　　 ,.　´　　　 　 　 　 　 　 `､
% 　　 　 ;′　　　　　　　　　　　　　ﾞ:,
% 　　　 :　　　　 '´　　　"¨　　　　　　,
% 　　　 {　　　　⌒　　　⌒ 　　　　　 }
% 　　　人　/:/:/:　｀t^ァ´ /:/:/:　　 /⌒i
% 　　　　 ＞　　　　 ｀´　　　　　　 /ー ´
% 　　　　(__人　　　 　 　 　 　 　 /
% 　　　　　　　＼　　　　　　　　 /_)
% 　　　　　 　 　 ｀T__= ､　　　／




