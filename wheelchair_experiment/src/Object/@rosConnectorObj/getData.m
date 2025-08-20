function ret = getData(obj)
obj.Count = obj.Count + 1;
if obj.Count == 1
    obj.StartTime = rostime('now');
end
t = rostime('now') - obj.StartTime;
ret.T = double(t.Sec) + double(t.Nsec) * 10^-9;

% LiDAR‚Ì’²®
L = 0;
theta = 0;


pause(obj.TimeOut);
try
    switch obj.Mode
        case {'Physics',   2}
            theta = 0;
            L = 0;
            gtp{obj.odom}   = obj.subTopic{obj.odom}.LatestMessage;
            gtp{obj.gyr}    = obj.subTopic{obj.gyr}.LatestMessage;
            %%%% Autoware only %%%%
            if obj.Autoware == true && obj.Sensor(obj.Prime) == false
                gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                
                ret.qx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                ret.qy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                ret.qz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                ret.qw =double(gtp{obj.ndtpose}.Pose.Orientation.W);
                
                quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                eulZYX = quat2eul(quat);
                ret.roll  = double(eulZYX(3));
                ret.pitch = double(eulZYX(2));                                                      
                ret.yaw   = double(eulZYX(1));                                                                                                                                                                                                                                                                                                                                                      
                if obj.Count > 2
                    ret = AngleAdjstment(ret, obj);
                end

                ret.X = double(gtp{obj.ndtpose}.Pose.Position.X) + L * cos(ret.yaw - theta) + 3.50;
                ret.Y = double(gtp{obj.ndtpose}.Pose.Position.Y) + L * sin(ret.yaw - theta) - 0.08;
                ret.Z = double(gtp{obj.ndtpose}.Pose.Position.Z);
                
                %%%% True and Autoware %%%%
            elseif obj.Autoware == 2 && obj.Sensor(obj.Prime) == true
                gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                gtp{obj.pose}    = obj.subTopic{obj.pose}.LatestMessage;
                ret.X = double(gtp{obj.pose}.Position.X);
                ret.Y = double(gtp{obj.pose}.Position.Y);
                ret.Z = double(gtp{obj.pose}.Position.Z);
                ret.qx =double(gtp{obj.pose}.Orientation.X);
                ret.qy =double(gtp{obj.pose}.Orientation.Y);
                ret.qz =double(gtp{obj.pose}.Orientation.Z);
                ret.qw =double(gtp{obj.pose}.Orientation.W);
                
                quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                eulZYX = quat2eul(quat);
                ret.roll  = double(eulZYX(3));
                ret.pitch = double(eulZYX(2));
                ret.yaw   = double(eulZYX(1));

                if obj.Count > 1
                     ret = AngleAdjstment(ret, obj);
                end
                
                ret.Autowareqx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                ret.Autowareqy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                ret.Autowareqz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                ret.Autowareqw =double(gtp{obj.ndtpose}.Pose.Orientation.W);
                
                quat = [ret.Autowareqw, ret.Autowareqx, ret.Autowareqy, ret.Autowareqz];
                eulZYX = quat2eul(quat);
                ret.Autowareroll  = double(eulZYX(3));
                ret.Autowarepitch = double(eulZYX(2));
                ret.Autowareyaw   = double(eulZYX(1));
                ret.Autowareyaw = ret.Autowareyaw;


                ret.AutowareX = double(gtp{obj.ndtpose}.Pose.Position.X) + L * cos(ret.Autowareyaw - theta);
                ret.AutowareY = double(gtp{obj.ndtpose}.Pose.Position.Y) + L * sin(ret.Autowareyaw - theta);
                ret.AutowareZ = double(gtp{obj.ndtpose}.Pose.Position.Z);
                
                if obj.Count > 1
                     ret = AngleAdjstmentRef(ret, obj);
                end
                
                %%%% Autoware and True %%%%
            elseif obj.Autoware == true && obj.Sensor(obj.Prime) == true
                gtp{obj.pose}    = obj.subTopic{obj.pose}.LatestMessage;
                gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                
                ret.PrimeX = double(gtp{obj.pose}.Position.X);
                ret.PrimeY = double(gtp{obj.pose}.Position.Y);
                ret.PrimeZ = double(gtp{obj.pose}.Position.Z);
                ret.Primeqx =double(gtp{obj.pose}.Orientation.X);
                ret.Primeqy =double(gtp{obj.pose}.Orientation.Y);
                ret.Primeqz =double(gtp{obj.pose}.Orientation.Z);
                ret.Primeqw =double(gtp{obj.pose}.Orientation.W);
                
                Primequat = [ret.Primeqw, ret.Primeqx, ret.Primeqy, ret.Primeqz];
                PrimeeulZYX = quat2eul(Primequat);
                ret.Primeroll  = double(PrimeeulZYX(3));
                ret.Primepitch = double(PrimeeulZYX(2));
                ret.Primeyaw   = double(PrimeeulZYX(1));
                

                if obj.Count > 1
                    ret = AngleAdjstmentRef_prime(ret, obj);
                end
                
                
                ret.qx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                ret.qy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                ret.qz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                ret.qw =double(gtp{obj.ndtpose}.Pose.Orientation.W);

                quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                eulZYX = quat2eul(quat);
                ret.roll  = double(eulZYX(3));
                ret.pitch = double(eulZYX(2));
                ret.yaw   = double(eulZYX(1));
                ret.yaw = ret.yaw + 0.0019;
                if obj.Count > 2
                     ret = AngleAdjstment(ret, obj);
                end

                ret.X = double(gtp{obj.ndtpose}.Pose.Position.X) + L * cos(ret.yaw - theta) + 2.984;
                ret.Y = double(gtp{obj.ndtpose}.Pose.Position.Y) + L * sin(ret.yaw - theta) - 0.0976;
                ret.Z = double(gtp{obj.ndtpose}.Pose.Position.Z);

                
                %     				ret.gyr(1) = gtp{obj.gyr}.X;
                %     				ret.gyr(2) = gtp{obj.gyr}.Y;
                %     				ret.gyr(3) = gtp{obj.gyr}.Z;
                
            else
                if obj.Autoware == true
                    gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                    
                    ret.qx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                    ret.qy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                    ret.qz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                    ret.qw =double(gtp{obj.ndtpose}.Pose.Orientation.W);
                    
                    quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                    eulZYX = quat2eul(quat);
                    ret.roll  = double(eulZYX(3));
                    ret.pitch = double(eulZYX(2));
                    ret.yaw   = double(eulZYX(1));


                    ret.X = double(gtp{obj.ndtpose}.Pose.Position.X) + L * cos(ret.yaw - theta);
                    ret.Y = double(gtp{obj.ndtpose}.Pose.Position.Y) + L * sin(ret.yaw - theta);
                    ret.Z = double(gtp{obj.ndtpose}.Pose.Position.Z);
                    
                        if obj.Count > 2
                            ret = AngleAdjstment(ret, obj);
                        end
                end
                if obj.Sensor(obj.Prime) == true
                    gtp{obj.pose}    = obj.subTopic{obj.pose}.LatestMessage;

                    ret.X = double(gtp{obj.pose}.Position.X);
                    ret.Y = double(gtp{obj.pose}.Position.Y);
                    ret.Z = double(gtp{obj.pose}.Position.Z);
                    ret.qx =double(gtp{obj.pose}.Orientation.X);
                    ret.qy =double(gtp{obj.pose}.Orientation.Y);
                    ret.qz =double(gtp{obj.pose}.Orientation.Z);
                    ret.qw =double(gtp{obj.pose}.Orientation.W);
                    
                    quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                    eulZYX = quat2eul(quat);
                    ret.roll  = double(eulZYX(3));
                    ret.pitch = double(eulZYX(2));
                    ret.yaw   = double(eulZYX(1));
                    if obj.Count > 2
                        ret = AngleAdjstment(ret, obj);
                    end
                end
            end
                ret.odm(1) = gtp{obj.odom}.Pose.Pose.Position.X;
                ret.odm(2) = gtp{obj.odom}.Pose.Pose.Position.Y;
                ret.odm(3) = gtp{obj.odom}.Pose.Pose.Position.Z;
                ret.odm(4) = gtp{obj.odom}.Twist.Twist.Linear.X;
                ret.odm(5) = gtp{obj.odom}.Twist.Twist.Linear.Y;
                ret.odm(6) = gtp{obj.odom}.Twist.Twist.Linear.Z;
                ret.odm(7) = gtp{obj.odom}.Twist.Twist.Angular.X;
                ret.odm(8) = gtp{obj.odom}.Twist.Twist.Angular.Y;
                ret.odm(9) = gtp{obj.odom}.Twist.Twist.Angular.Z;
                
%     				ret.gyr(1) = gtp{obj.gyr}.X;
%     				ret.gyr(2) = gtp{obj.gyr}.Y;
%     				ret.gyr(3) = gtp{obj.gyr}.Z;

        case {'Expriment', 3}
            gtp{obj.odom}   = obj.subTopic{obj.odom}.LatestMessage;
            gtp{obj.gyr}    = obj.subTopic{obj.gyr}.LatestMessage;
            %%%% Autoware only %%%%
            if obj.Autoware == true && obj.Sensor(obj.Prime) == false
                gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                
                ret.qx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                ret.qy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                ret.qz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                ret.qw =double(gtp{obj.ndtpose}.Pose.Orientation.W);
                
                quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                eulZYX = quat2eul(quat);
                ret.roll  = double(eulZYX(3));
                ret.pitch = double(eulZYX(2));
                ret.yaw   = double(eulZYX(1));
                
                if obj.Count > 1
                     ret = AngleAdjstment(ret, obj);
                end

                ret.X = double(gtp{obj.ndtpose}.Pose.Position.X);
                ret.Y = double(gtp{obj.ndtpose}.Pose.Position.Y);
                ret.Z = double(gtp{obj.ndtpose}.Pose.Position.Z);
                
                %%%% Autoware and Prime %%%%
            elseif obj.Autoware == 2 && obj.Sensor(obj.Prime) == true
                gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                
                ret.Autowareqx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                ret.Autowareqy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                ret.Autowareqz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                ret.Autowareqw =double(gtp{obj.ndtpose}.Pose.Orientation.W);
                
                quat = [ret.Autowareqw, ret.Autowareqx, ret.Autowareqy, ret.Autowareqz];
                eulZYX = quat2eul(quat);
                ret.Autowareroll  = double(eulZYX(3));
                ret.Autowarepitch = double(eulZYX(2));
                ret.Autowareyaw   = double(eulZYX(1));
                
                if obj.Count > 1
                     ret = AngleAdjstmentRef(ret, obj);
                end

                ret.AutowareX = double(gtp{obj.ndtpose}.Pose.Position.X) + L * cos(ret.Autowareyaw - theta);
                ret.AutowareY = double(gtp{obj.ndtpose}.Pose.Position.Y) + L * sin(ret.Autowareyaw - theta);
                ret.AutowareZ = double(gtp{obj.ndtpose}.Pose.Position.Z);
                
                %%%% AUtoware and Prime %%%% bug?????
            else
                if obj.Autoware == true
                    gtp{obj.ndtpose}   = obj.subTopic{obj.ndtpose}.LatestMessage;
                    
                    ret.qx =double(gtp{obj.ndtpose}.Pose.Orientation.X);
                    ret.qy =double(gtp{obj.ndtpose}.Pose.Orientation.Y);
                    ret.qz =double(gtp{obj.ndtpose}.Pose.Orientation.Z);
                    ret.qw =double(gtp{obj.ndtpose}.Pose.Orientation.W);
                    
                    quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                    eulZYX = quat2eul(quat);
                    ret.roll  = double(eulZYX(3));
                    ret.pitch = double(eulZYX(2));
                    ret.yaw   = double(eulZYX(1));
                    
                if obj.Count > 1
                     ret = AngleAdjstment(ret, obj);
                end

                    ret.X = double(gtp{obj.ndtpose}.Pose.Position.X) + L * cos(ret.yaw - theta);
                    ret.Y = double(gtp{obj.ndtpose}.Pose.Position.Y) + L * sin(ret.yaw - theta);
                    ret.Z = double(gtp{obj.ndtpose}.Pose.Position.Z);
                    
%                         if obj.Count > 2
%                             ret = AngleAdjstmentRef(ret, obj);
%                         end
                %%% Prime only %%%%
                else
                    gtp{obj.pose}    = obj.subTopic{obj.pose}.LatestMessage;

                    ret.X = double(gtp{obj.pose}.Position.X);
                    ret.Y = double(gtp{obj.pose}.Position.Y);
                    ret.Z = double(gtp{obj.pose}.Position.Z);
                    ret.qx =double(gtp{obj.pose}.Orientation.X);
                    ret.qy =double(gtp{obj.pose}.Orientation.Y);
                    ret.qz =double(gtp{obj.pose}.Orientation.Z);
                    ret.qw =double(gtp{obj.pose}.Orientation.W);
                    
                    quat = [ret.qw, ret.qx, ret.qy, ret.qz];
                    eulZYX = quat2eul(quat);
                    ret.roll  = double(eulZYX(3));
                    ret.pitch = double(eulZYX(2));
                    ret.yaw   = double(eulZYX(1));
                    
                    if obj.Count > 1
                        ret = AngleAdjstment(ret, obj);
                    end
                end
            end
                ret.odm(1) = gtp{obj.odom}.Pose.Pose.Position.X;
                ret.odm(2) = gtp{obj.odom}.Pose.Pose.Position.Y;
                ret.odm(3) = gtp{obj.odom}.Pose.Pose.Position.Z;
                ret.odm(4) = gtp{obj.odom}.Twist.Twist.Linear.X;
                ret.odm(5) = gtp{obj.odom}.Twist.Twist.Linear.Y;
                ret.odm(6) = gtp{obj.odom}.Twist.Twist.Linear.Z;
                ret.odm(7) = gtp{obj.odom}.Twist.Twist.Angular.X;
                ret.odm(8) = gtp{obj.odom}.Twist.Twist.Angular.Y;
                ret.odm(9) = gtp{obj.odom}.Twist.Twist.Angular.Z;
                
%     				ret.gyr(1) = gtp{obj.gyr}.X;
%     				ret.gyr(2) = gtp{obj.gyr}.Y;
%     				ret.gyr(3) = gtp{obj.gyr}.Z;
       otherwise
                error('Wrong number. Select the correct number again.');
    end
    
    if obj.Sensor(obj.LiDAR) == true
        ret.scan	= obj.subTopic{obj.scan}.LatestMessage;
        ret.ptCloud= obj.subTopic{obj.ptCloud}.LatestMessage;
        if obj.Autoware == true
            ret.points_raw= obj.subTopic{obj.refptCloud}.LatestMessage;
        end
    end
    if obj.Sensor(obj.RealSence) == true
        ret.rgbPtCloud= obj.subTopic{obj.rgbPtCloud}.LatestMessage;
        ret.rawImage  = obj.subTopic{obj.images}.LatestMessage;
    end
catch ME
    endExperiment(obj);
    warning('off','backtrace')
    warning('Emergency stop! Please check the connection between the computer network and your electric wheelchair.');
    rethrow(ME);
end
end