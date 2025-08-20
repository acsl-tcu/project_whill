function ret = getData(obj) 			
	obj.data.T = (obj.Count)*obj.DeltaT;
	obj.data.X = obj.TrueData.X(:,obj.Count);
	obj.data.Y = obj.TrueData.Y(:,obj.Count);
	obj.data.Z = obj.TrueData.Z(:,obj.Count);
	obj.data.qx = obj.TrueData.qx(:,obj.Count);
	obj.data.qy = obj.TrueData.qy(:,obj.Count);
	obj.data.qz = obj.TrueData.qz(:,obj.Count);
	obj.data.qw = obj.TrueData.qw(:,obj.Count);
	obj.data.roll  = obj.TrueData.roll(:,obj.Count);
	obj.data.pitch = obj.TrueData.pitch(:,obj.Count);
	obj.data.yaw   = obj.TrueData.yaw(:,obj.Count);
	obj.data.yaw   = obj.TrueData.yaw(:,obj.Count);
	obj.data.Omega = obj.TrueData.Omega(:,obj.Count);

    if obj.Sensor(obj.Prime) == true
        for L = 1:length(obj.DefaultName)
            datatemp.(obj.DefaultName{L}) = obj.TrueData.(obj.DefaultName{L})(:,obj.Count);
        end
    else
        for L = 1:length(obj.DefaultName)
           datatemp.(obj.DefaultName{L}) = 0.;
        end
        datatemp.T     =  obj.Count*obj.DeltaT;
        datatemp.Omega =  obj.TrueData.Omega(:,obj.Count);
    end
    if obj.Sensor(obj.LiDAR) == true
        obj.data.scan  = makeScanData(obj.LidarObj, obj.data);
        datatemp.scan  = obj.data.scan;
    end
	ret = datatemp;
end