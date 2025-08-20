classdef rosBagPlayObj < handle
    properties(NonCopyable = true, SetAccess = private)
		data
		Data
		Topic
		Message
	end
    properties(Access = private)
        dt
		Count
        MsgCnt
		Mode
        Sensor
        Bag
        Logic
        TimeMsg
        StartTime
    end
	properties(Constant)
        Wheel = 0.256/2;
        Width = 0.490/2;
        IPcell  = 1;
		TimeOut = 1.e-3;
		%- Topic -%
		topicNum= 6;
		scan	= 1;
		ptCloud = 2;
        odom	= 3;
		gyr		= 4;
		pose	= 5;
		cmdVel  = 6;
		%- Sensor -%
		Prime	= 1;
		LiDAR	= 2;
        TopicName = {'/scan','/velodyne_points','/wheelchair/odom','/wheelchair/gyr','/wheelchair/pose','/wheelchair/cmd_vel'};
	end
	methods
		function obj = rosBagPlayObj(Te, dt, Mode, Sensor, RosbagFullPath)
            %--
			obj.Count   = 1;
            obj.MsgCnt  = 1;
            obj.dt      = dt;
			obj.Mode	= Mode;
			obj.Sensor	= Sensor;
			obj.Topic	= cell(obj.topicNum,1);
			obj.Message	= cell(obj.topicNum,1);
            obj.Logic	= zeros(obj.topicNum,1);
			disp('Loading your rosbag file...');
            obj.Bag     = rosbag(RosbagFullPath);
            obj.StartTime = obj.Bag.StartTime;
            if obj.Bag.EndTime - obj.StartTime < Te
                X = ['rosbag end time: ', num2str(obj.Bag.EndTime - obj.StartTime)];
                disp(X);
                error('You have to set the simulation end time less than the rosbag end time.')
            end
            obj.Topic   = cellfun(@(X) select(obj.Bag, 'Topic', X),  obj.TopicName, 'UniformOutput', false);
            obj.Message = cellfun(@(X) readMessages(X), obj.Topic, 'UniformOutput', false);
            obj.TimeMsg = cellfun(@(X) timeseries(X), obj.Topic, 'UniformOutput', false);
            obj.Logic   = cellfun(@(X) isempty(X), obj.Message);
		end
		ret = getData(obj)
		[]  = updateData(obj, RawData, EstimatedData, ControledData)
		[]  = saveData2file(obj, Datadir)
	end
end