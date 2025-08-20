function ret = getData(obj)
    obj.Count = obj.Count + 1;
    Msglgc = true(1,obj.topicNum-sum(obj.Logic));
    while any(Msglgc) == 1
        obj.MsgCnt = obj.MsgCnt + 1;
        T = obj.StartTime + (obj.MsgCnt - 1)*obj.dt;
        MsgNum = arrayfun(@(L) find(obj.TimeMsg{L}.Time < T, 1, 'last'), colon(1,obj.topicNum-sum(obj.Logic)), 'UniformOutput', false);
%         MsgNum = arrayfun(@(L) find(obj.TimeMsg{L}.Time < T, 2, 3), colon(1,obj.topicNum-sum(obj.Logic)), 'UniformOutput', false);
        Msglgc = cellfun(@(X) isempty(X), MsgNum);
        obj.data.T = (obj.Count - 1)*obj.dt;
    end
    if obj.Logic(obj.odom) ~= 1
        gtp{obj.odom}   = obj.Message{obj.odom}{MsgNum{obj.odom}};
        obj.data.odm(1) = gtp{obj.odom}.Pose.Pose.Position.X;
        obj.data.odm(2) = gtp{obj.odom}.Pose.Pose.Position.Y;
        obj.data.odm(3) = gtp{obj.odom}.Pose.Pose.Position.Z;
        obj.data.odm(4) = gtp{obj.odom}.Twist.Twist.Linear.X;
        obj.data.odm(5) = gtp{obj.odom}.Twist.Twist.Linear.Y;
        obj.data.odm(6) = gtp{obj.odom}.Twist.Twist.Linear.Z;
        obj.data.odm(7) = gtp{obj.odom}.Twist.Twist.Angular.X;
        obj.data.odm(8) = gtp{obj.odom}.Twist.Twist.Angular.Y;
        obj.data.odm(9) = gtp{obj.odom}.Twist.Twist.Angular.Z;
    end
    if obj.Logic(obj.gyr) ~= 1
        gtp{obj.gyr}    = obj.Message{obj.gyr}{MsgNum{obj.gyr}};
        obj.data.gyr(1) = gtp{obj.gyr}.X;
        obj.data.gyr(2) = gtp{obj.gyr}.Y;
        obj.data.gyr(3) = gtp{obj.gyr}.Z;
    end
    if obj.Logic(obj.pose) ~= 1
        gtp{obj.pose}   = obj.Message{obj.pose}{MsgNum{obj.pose}};
        obj.data.X = double(gtp{obj.pose}.Position.X);
        obj.data.Y = double(gtp{obj.pose}.Position.Y);
        obj.data.Z = double(gtp{obj.pose}.Position.Z);
        obj.data.qx =double(gtp{obj.pose}.Orientation.X);
        obj.data.qy =double(gtp{obj.pose}.Orientation.Y);
        obj.data.qz =double(gtp{obj.pose}.Orientation.Z);
        obj.data.qw =double(gtp{obj.pose}.Orientation.W);
        quat = [obj.data.qx, obj.data.qy, obj.data.qz, obj.data.qw];
        eulZYX = quat2eul(quat);
        obj.data.roll  = double(eulZYX(1));
        obj.data.pitch = double(eulZYX(2));
        obj.data.yaw   = double(eulZYX(3));
    end
    if obj.Sensor(obj.LiDAR) == true && any(obj.Logic(obj.scan:obj.ptCloud)) ~= 1
        obj.data.scan   = obj.Message{obj.scan}{MsgNum{obj.scan}};
        obj.data.ptCloud=obj.Message{obj.ptCloud}{MsgNum{obj.ptCloud}};
    end
	ret = obj.data;
end