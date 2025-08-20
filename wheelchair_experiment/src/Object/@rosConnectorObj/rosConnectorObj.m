classdef rosConnectorObj < handle
	properties(NonCopyable = true, SetAccess = private)
 		Data
		Count
		Mode
		Node
		subTopic
        pubTopic
		subMessage
        pubMessage
        Tmp
	end
	properties(Access = private)
		Sensor
		StartTime
        Autoware
    end
    properties(Access = private, Constant)
        Wheel = 0.256/2;
        Width = 0.490/2;
		TimeOut = 1.e-3;
		%- Subscriber topic -%
		odom	   = 1;
		gyr		   = 2;
		scan	   = 3;
		ptCloud    = 4;
		rgbPtCloud = 5;
        images     = 6;
		pose       = 7;
        ndtpose    = 8;
        refptCloud = 9;
        refmapptCloud = 10;
        odomAutoware = 11;
        next_target=12;
  		%- Publisher topic -%     
		cmdVel  = 1;
		%- Sensor -%
		Prime	 = 1;
		LiDAR	 = 2;
        RealSence= 3;
		%- Topic Names -%
        subTopicName = {'/wheelchair/odom';
                        '/wheelchair/gyr';
                        '/scan';
                        '/velodyne_points';
                        '/realSense_D435/depth/color/points';
						'/realSense_D435/color/image_raw';
                        '/wheelchair/pose';
                        '/current_pose'; %'/ndt_pose';
                        '/points_raw';
                        '/filtered_points';
                        '/wheelchair/odom_Autoware'
                        '/next_target_mark'};

        pubTopicName = {'/wheelchair/cmd_vel'};

        subMsgName = {'nav_msgs/Odometry';
                      'geometry_msgs/Point';
                      'sensor_msgs/LaserScan';
                      'sensor_msgs/PointCloud2';
                      'sensor_msgs/PointCloud2';
					  'sensor_msgs/Image';
                      'geometry_msgs/Pose';
                      'geometry_msgs/PoseStamped';
                      'sensor_msgs/PointCloud2';
                      'sensor_msgs/PointCloud2';
                      'nav_msgs/Odometry'
                      'visualization_msgs/Marker'};

        pubMsgName = {'geometry_msgs/Twist'};
    end
	methods
		function obj = rosConnectorObj(info, mode, sensor, autoware)
			disp('Now is preparing to setup for robot operating system...');
            
			%-- Configulations for ROS
			obj.Count  = 0;
			obj.Mode   = mode;
			obj.Sensor = sensor;
            obj.Autoware = autoware;
			obj.subTopic   = cell(size(obj.subTopicName));
			obj.subMessage = cell(size(obj.subTopicName));
            obj.pubTopic   = cell(size(obj.pubTopicName));
			obj.pubMessage = cell(size(obj.pubTopicName));
            
            %-- Setting the environment variables to connect to ROS
			URL = strcat('http://', info.ROSHostIP, ':11311');
			setenv('ROS_MASTER_URI', URL);

            % 応急処置
            if isempty( info.ROSClientIP)
                 info.ROSClientIP = info.ROSHostIP;
            end
			setenv('ROS_IP', info.ROSClientIP);
            
			%-- Connection of ROS core using "rosinit"
			rosshutdown;
			rosinit(URL);
            
			%-- Declaring the node, publishers and subscribers 
			obj.Node	 = robotics.ros.Node('/matlab');
			obj.subTopic = cellfun(@(X, Y) robotics.ros.Subscriber(obj.Node, X, Y), obj.subTopicName, obj.subMsgName, 'UniformOutput', false);
			obj.pubTopic = cellfun(@(X, Y) robotics.ros.Publisher(obj.Node, X, Y),  obj.pubTopicName, obj.pubMsgName, 'UniformOutput', false);
			obj.subMessage = cellfun(@rosmessage, obj.subTopic, 'UniformOutput', false);
            obj.pubMessage = cellfun(@rosmessage, obj.pubTopic, 'UniformOutput', false);

			disp('Translational and rotational Velocities of the wheelchair are being initialized...');
			obj.pubMessage{obj.cmdVel}.Linear.X  = 0.;
			obj.pubMessage{obj.cmdVel}.Angular.Z = 0.;
			send(obj.pubTopic{obj.cmdVel}, obj.pubMessage{obj.cmdVel});
		end
		ret = getData(obj, sensor)
		[]  = sendTopic(obj, DataSet)
		[]  = endExperiment(obj)
		[]  = updateData(obj, RawData, EstimatedData, ControledData)
		[]  = saveData2file(obj, Datadir)
	end
end