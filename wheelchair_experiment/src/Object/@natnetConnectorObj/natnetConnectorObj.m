classdef natnetConnectorObj < handle
	properties 
		ControlRigid
		NowData
	end
	properties (NonCopyable = true, SetAccess = private)
		data
		old_data
		RigidBodyCount
		markerNum
		CountMarker
		CountMarker_max
		Time
		Timeold
		loopcount
		cmarker
		cunmarker
		crigid
		getFrame
		yaw
		n
        local
	end
	properties(Access = private)
		NatnetClient
	end
	properties(Constant)
		%-- Sensor 
		Prime	= 1;
		LiDAR	= 2;
        realsense = 3;
        Autoware = 4;
	end
	methods
		function obj = natnetConnectorObj(info, sensor)
			%-- connection NatNetClient
			disp('Start to get data')
			%-- connection takes about 0.3 seconds
			%-- setting ClientIP 

			obj.NatnetClient = natnet;
			obj.NatnetClient.HostIP	  = info.HostIP;
			obj.NatnetClient.ClientIP = info.ClientIP;
			obj.NatnetClient.ConnectionType = 'Multicast';
			obj.NatnetClient.connect;
			if obj.NatnetClient.IsConnected == 0 
				error( 'Please check whether it is connected to the net. Is the IP address correctly specified?' )
			end
			%-- Initial definition
			obj.CountMarker_max = 0;
			obj.Time      = 0.;
			obj.Timeold   = 0.;
			obj.loopcount = 0;
			%-- count of set marker
			obj.cmarker   = 20;
			obj.cunmarker = 50;
			%-- count of set rigid
			obj.crigid = 10;
			obj.yaw    = 0;
			obj.n	   = 1;
			%-- settting default control rigid body number
			obj.ControlRigid = 1;
		end
		ret= getData(obj, sensor);
	end
	methods(Access = protected)
		[] = timeKeeper(obj);
		[] = organize(obj, model);
		[] = getQ(obj, body, i);
		[] = cicle(obj);
	end
end