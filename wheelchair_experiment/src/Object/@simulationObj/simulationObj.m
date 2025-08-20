classdef simulationObj < handle
	properties
        Sensor
		StartState
        LidarObj
        Mode
    end
    properties(Constant)
        Wheel = 0.256/2;
        Width = 0.490/2;
        %- Sensor -%
		Prime	= 1;
		LiDAR	= 2;
	end
	properties(NonCopyable = true, SetAccess = private )
		data
		Data
        TrueData
		DeltaT
	end
	properties(Access = private)
		Count
        DefaultName
		TimeLength
	end
	methods
		function obj = simulationObj(info, StartTime, EndTime, DT, Sensor, Mode)
            obj.Count  = 1;
			obj.DeltaT = DT;
            obj.Sensor = Sensor;
            obj.Mode = Mode;
			%-- Define a zero matrices in a structure called "Data". --%
            obj.TimeLength	= length(StartTime: DT: EndTime);
            obj.Data.T		= zeros(1,obj.TimeLength);
            obj.Data.X		= zeros(1,obj.TimeLength);
            obj.Data.Y		= zeros(1,obj.TimeLength);
			obj.Data.Z		= zeros(1,obj.TimeLength);
			obj.Data.qx		= zeros(1,obj.TimeLength);
            obj.Data.qy		= zeros(1,obj.TimeLength);
			obj.Data.qz		= zeros(1,obj.TimeLength);
			obj.Data.qw		= zeros(1,obj.TimeLength);
			obj.Data.roll	= zeros(1,obj.TimeLength);
			obj.Data.pitch	= zeros(1,obj.TimeLength);
			obj.Data.yaw	= zeros(1,obj.TimeLength);
            obj.Data.V		= zeros(2,obj.TimeLength);
            obj.Data.Omega	= zeros(2,obj.TimeLength);
            obj.Data.ComputationTime = zeros(1,obj.TimeLength);
            obj.TrueData    = obj.Data;
            obj.DefaultName = fieldnames(obj.TrueData);
            %-- Attach problem data to the params structure. --%
            obj.TrueData.X(:,obj.Count)	  = info.StartState(1,1);
            obj.TrueData.Y(:,obj.Count)	  = info.StartState(2,1);
            obj.TrueData.yaw(:,obj.Count) = info.StartState(3,1);
            if obj.Sensor(obj.Prime) == true
                obj.Data.X(:,obj.Count)	  = info.StartState(1,1);
                obj.Data.Y(:,obj.Count)	  = info.StartState(2,1);
                obj.Data.yaw(:,obj.Count) = info.StartState(3,1);    
            end
            if obj.Sensor(obj.LiDAR) == true
                obj.LidarObj = pseudo2dLidar();
            end
		end
		ret= getData(obj);	
		[] = updateData(obj,RawData, EstimatedData, ControledData)
		[] = saveData2file(obj,Datadir);
        [Room, Object] = getObjects(obj);
        scanFinishied  =  makeScanData(obj);
	end
end

