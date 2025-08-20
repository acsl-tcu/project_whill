% ROSで障害物を出す際に使用する
function [obj, Plant] = Obs_Setting(obj, Plant)
% 
    if obj.Selectmode == 1%simulation
        % -- subscrib obstacle state--%
        for i = 1:length(obj.InitialPosition)
            Plant.local.Obstacle(2 * i - 1, 1)      = obj.InitialPosition(i, 1) +  obj.InitialVelocity(i, 1) * Plant.T;
            Plant.local.Obstacle(2 * i, 1)          = obj.InitialPosition(i, 2) +  obj.InitialVelocity(i, 2) * Plant.T;
            Plant.local.ObstaclePos(2 * i - 1, 1)   = obj.InitialPosition(i, 1) +  obj.InitialVelocity(i, 1) * Plant.T;
            Plant.local.ObstaclePos(2 * i, 2)       = obj.InitialPosition(i, 2) +  obj.InitialVelocity(i, 2) * Plant.T;
        end
        Plant.obs_state_L =0;


        % stop obstacle%
        if Plant.local.ObstaclePos(1,1) <= 0
            obj.InitialVelocity(1,1) = 0;
        elseif Plant.local.ObstaclePos(2,1) <= 1
            obj.InitialVelocity(2,1) = 0;
        elseif Plant.local.ObstaclePos(3,1) <= 2
            obj.InitialVelocity(3,1) = 0;
        elseif Plant.local.ObstaclePos(4,1) <= 3
            obj.InitialVelocity(4,1) = 0;
        elseif Plant.local.ObstaclePos(5,1) <= 4
            obj.InitialVelocity(5,1) = 0;
        elseif Plant.local.ObstaclePos(6,1) <= 5
            obj.InitialVelocity(6,1) = 0;
        elseif Plant.local.ObstaclePos(7,1) <= 6
            obj.InitialVelocity(7,1) = 0;
        elseif Plant.local.ObstaclePos(8,1) <= 7
            obj.InitialVelocity(8,1) = 0;
        elseif Plant.local.ObstaclePos(9,1) <= 8
            obj.InitialVelocity(9,1) = 0;
        elseif Plant.X >= 1 && Plant.X <= 80 && Plant.Y <= 2
            obj.InitialVelocity(1,1) = 0.5;
        end


%        % --  send obstacle velocity --%
        obj.obs_Message{1}.Linear.X  = obj.InitialVelocity(1,1);
        obj.obs_Message{1}.Angular.Z = obj.InitialVelocity(1,2);

        obj.obs_Message{2}.Linear.X  = obj.InitialVelocity(2,1);
        obj.obs_Message{2}.Angular.Z = obj.InitialVelocity(2,2);

        obj.obs_Message{3}.Linear.X  = obj.InitialVelocity(3,1);
        obj.obs_Message{3}.Angular.Z = obj.InitialVelocity(3,2);

        obj.obs_Message{4}.Linear.X  = obj.InitialVelocity(4,1);
        obj.obs_Message{4}.Angular.Z = obj.InitialVelocity(4,2);

        obj.obs_Message{5}.Linear.X  = obj.InitialVelocity(5,1);
        obj.obs_Message{5}.Angular.Z = obj.InitialVelocity(5,2);

        obj.obs_Message{6}.Linear.X  = obj.InitialVelocity(6,1);
        obj.obs_Message{6}.Angular.Z = obj.InitialVelocity(6,2);

        obj.obs_Message{7}.Linear.X  = obj.InitialVelocity(7,1);
        obj.obs_Message{7}.Angular.Z = obj.InitialVelocity(7,2);

        obj.obs_Message{8}.Linear.X  = obj.InitialVelocity(8,1);
        obj.obs_Message{8}.Angular.Z = obj.InitialVelocity(8,2);

        obj.obs_Message{9}.Linear.X  = obj.InitialVelocity(9,1);
        obj.obs_Message{9}.Angular.Z = obj.InitialVelocity(9,2);

        obj.obs_Message{obj.Stationary_obstacles + 1}.Linear.X  = obj.InitialVelocity(1,1);
        obj.obs_Message{obj.Stationary_obstacles + 1}.Angular.Z = obj.InitialVelocity(1,2);

        obj.obs_Message{obj.Stationary_obstacles + 2}.Linear.X  = obj.InitialVelocity(2,1);
        obj.obs_Message{obj.Stationary_obstacles + 2}.Angular.Z = obj.InitialVelocity(2,2);

        obj.obs_Message{obj.Stationary_obstacles + 3}.Linear.X  = obj.InitialVelocity(3,1);
        obj.obs_Message{obj.Stationary_obstacles + 3}.Angular.Z = obj.InitialVelocity(3,2);

        obj.obs_Message{obj.Stationary_obstacles + 4}.Linear.X  = obj.InitialVelocity(4,1);
        obj.obs_Message{obj.Stationary_obstacles + 4}.Angular.Z = obj.InitialVelocity(4,2);

        obj.obs_Message{obj.Stationary_obstacles + 5}.Linear.X  = obj.InitialVelocity(5,1);
        obj.obs_Message{obj.Stationary_obstacles + 5}.Angular.Z = obj.InitialVelocity(5,2);

        obj.obs_Message{obj.Stationary_obstacles + 6}.Linear.X  = obj.InitialVelocity(6,1);
        obj.obs_Message{obj.Stationary_obstacles + 6}.Angular.Z = obj.InitialVelocity(6,2);

        obj.obs_Message{obj.Stationary_obstacles + 7}.Linear.X  = obj.InitialVelocity(7,1);
        obj.obs_Message{obj.Stationary_obstacles + 7}.Angular.Z = obj.InitialVelocity(7,2);

        obj.obs_Message{obj.Stationary_obstacles + 8}.Linear.X  = obj.InitialVelocity(8,1);
        obj.obs_Message{obj.Stationary_obstacles + 8}.Angular.Z = obj.InitialVelocity(8,2);

        obj.obs_Message{obj.Stationary_obstacles + 9}.Linear.X  = obj.InitialVelocity(9,1);
        obj.obs_Message{obj.Stationary_obstacles + 9}.Angular.Z = obj.InitialVelocity(9,2);

        obj.obs_Message{obj.Stationary_obstacles + 10}.Linear.X  = obj.InitialVelocity(10,1);
        obj.obs_Message{obj.Stationary_obstacles + 10}.Angular.Z = obj.InitialVelocity(10,2);

    elseif obj.Selectmode == 2

%        % -- subscrib obstacle state--%
        Plant.local.Obstacle(1,1) = obj.Obstacle_Topic1.LatestMessage.Position.X ;
        Plant.local.Obstacle(2,1) = obj.Obstacle_Topic1.LatestMessage.Position.Y ;
        obj.qx1 = obj.Obstacle_Topic1.LatestMessage.Orientation.X;
        obj.qy1 = obj.Obstacle_Topic1.LatestMessage.Orientation.Y;
        obj.qz1 = obj.Obstacle_Topic1.LatestMessage.Orientation.Z;
        obj.qw1 = obj.Obstacle_Topic1.LatestMessage.Orientation.W;
        quat1 = [obj.qx1, obj.qy1, obj.qz1, obj.qw1];
        eulZYX1 = quat2eul(quat1);
        Plant.local.Obstacle(3,1)   = double(eulZYX1(3));%YAW

        Plant.local.Obstacle(4,1) = obj.Obstacle_Topic2.LatestMessage.Position.X ;
        Plant.local.Obstacle(5,1) = obj.Obstacle_Topic2.LatestMessage.Position.Y ;
        obj.qx2 = obj.Obstacle_Topic2.LatestMessage.Orientation.X;
        obj.qy2 = obj.Obstacle_Topic2.LatestMessage.Orientation.Y;
        obj.qz2 = obj.Obstacle_Topic2.LatestMessage.Orientation.Z;
        obj.qw2 = obj.Obstacle_Topic2.LatestMessage.Orientation.W;
        quat2 = [obj.qx2, obj.qy2, obj.qz2, obj.qw2];
        eulZYX2 = quat2eul(quat2);
        Plant.local.Obstacle(6,1)   = double(eulZYX2(3));%YAW

        Plant.local.Obstacle(7,1) = obj.Obstacle_Topic3.LatestMessage.Position.X ;
        Plant.local.Obstacle(8,1) = obj.Obstacle_Topic3.LatestMessage.Position.Y ;
        obj.qx3 = obj.Obstacle_Topic3.LatestMessage.Orientation.X;
        obj.qy3 = obj.Obstacle_Topic3.LatestMessage.Orientation.Y;
        obj.qz3 = obj.Obstacle_Topic3.LatestMessage.Orientation.Z;
        obj.qw3 = obj.Obstacle_Topic3.LatestMessage.Orientation.W;
        quat3 = [obj.qx3, obj.qy3, obj.qz3, obj.qw3];
        eulZYX3 = quat2eul(quat3);
        Plant.local.Obstacle(9,1)   = double(eulZYX3(3));%YAW
% 
%         Plant.local.Obstacle(10,1) = obj.Obstacle_Topic4.LatestMessage.Position.X ;
%         Plant.local.Obstacle(11,1) = obj.Obstacle_Topic4.LatestMessage.Position.Y ;
%         obj.qx4 = obj.Obstacle_Topic4.LatestMessage.Orientation.X;
%         obj.qy4 = obj.Obstacle_Topic4.LatestMessage.Orientation.Y;
%         obj.qz4 = obj.Obstacle_Topic4.LatestMessage.Orientation.Z;
%         obj.qw4 = obj.Obstacle_Topic4.LatestMessage.Orientation.W;
%         quat4 = [obj.qx4, obj.qy4, obj.qz4, obj.qw4];
%         eulZYX4 = quat2eul(quat4);
%         Plant.local.Obstacle(12,1)   = double(eulZYX4(3));%YAW
% 
%         Plant.local.Obstacle(13,1) = obj.Obstacle_Topic5.LatestMessage.Position.X ;
%         Plant.local.Obstacle(14,1) = obj.Obstacle_Topic5.LatestMessage.Position.Y ;
%         obj.qx5 = obj.Obstacle_Topic5.LatestMessage.Orientation.X;
%         obj.qy5 = obj.Obstacle_Topic5.LatestMessage.Orientation.Y;
%         obj.qz5 = obj.Obstacle_Topic5.LatestMessage.Orientation.Z;
%         obj.qw5 = obj.Obstacle_Topic5.LatestMessage.Orientation.W;
%         quat5 = [obj.qx5, obj.qy5, obj.qz5, obj.qw5];
%         eulZYX5 = quat2eul(quat5);
%         Plant.local.Obstacle(15,1)   = double(eulZYX5(3));%YAW
% 
%         Plant.local.Obstacle(16,1) = obj.Obstacle_Topic6.LatestMessage.Position.X ;
%         Plant.local.Obstacle(17,1) = obj.Obstacle_Topic6.LatestMessage.Position.Y ;
%         obj.qx6 = obj.Obstacle_Topic6.LatestMessage.Orientation.X;
%         obj.qy6 = obj.Obstacle_Topic6.LatestMessage.Orientation.Y;
%         obj.qz6 = obj.Obstacle_Topic6.LatestMessage.Orientation.Z;
%         obj.qw6 = obj.Obstacle_Topic6.LatestMessage.Orientation.W;
%         quat6 = [obj.qx6, obj.qy6, obj.qz6, obj.qw6];
%         eulZYX6 = quat2eul(quat6);
%         Plant.local.Obstacle(18,1)   = double(eulZYX6(3));%YAW
% 
%         Plant.local.Obstacle(19,1) = obj.Obstacle_Topic7.LatestMessage.Position.X ;
%         Plant.local.Obstacle(20,1) = obj.Obstacle_Topic7.LatestMessage.Position.Y ;
%         obj.qx7 = obj.Obstacle_Topic7.LatestMessage.Orientation.X;
%         obj.qy7 = obj.Obstacle_Topic7.LatestMessage.Orientation.Y;
%         obj.qz7 = obj.Obstacle_Topic7.LatestMessage.Orientation.Z;
%         obj.qw7 = obj.Obstacle_Topic7.LatestMessage.Orientation.W;
%         quat7 = [obj.qx7, obj.qy7, obj.qz7, obj.qw7];
%         eulZYX7 = quat2eul(quat7);
%         Plant.local.Obstacle(21,1)   = double(eulZYX7(3));%YAW
% 
%         Plant.local.Obstacle(22,1) = obj.Obstacle_Topic8.LatestMessage.Position.X ;
%         Plant.local.Obstacle(23,1) = obj.Obstacle_Topic8.LatestMessage.Position.Y ;
%         obj.qx8 = obj.Obstacle_Topic8.LatestMessage.Orientation.X;
%         obj.qy8 = obj.Obstacle_Topic8.LatestMessage.Orientation.Y;
%         obj.qz8 = obj.Obstacle_Topic8.LatestMessage.Orientation.Z;
%         obj.qw8 = obj.Obstacle_Topic8.LatestMessage.Orientation.W;
%         quat8 = [obj.qx8, obj.qy8, obj.qz8, obj.qw8];
%         eulZYX8 = quat2eul(quat8);
%         Plant.local.Obstacle(24,1)   = double(eulZYX8(3));%YAW
% 
%         Plant.local.Obstacle(25,1) = obj.Obstacle_Topic9.LatestMessage.Position.X ;
%         Plant.local.Obstacle(26,1) = obj.Obstacle_Topic9.LatestMessage.Position.Y ;
%         obj.qx9 = obj.Obstacle_Topic9.LatestMessage.Orientation.X;
%         obj.qy9 = obj.Obstacle_Topic9.LatestMessage.Orientation.Y;
%         obj.qz9 = obj.Obstacle_Topic9.LatestMessage.Orientation.Z;
%         obj.qw9 = obj.Obstacle_Topic9.LatestMessage.Orientation.W;
%         quat9 = [obj.qx9, obj.qy9, obj.qz9, obj.qw9];
%         eulZYX9 = quat2eul(quat9);
%         Plant.local.Obstacle(27,1)   = double(eulZYX9(3));%YAW

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 1,1) = obj.Obstacle_Topic101.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 2,1) = obj.Obstacle_Topic101.LatestMessage.Position.Y ;

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 4,1) = obj.Obstacle_Topic102.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 5,1) = obj.Obstacle_Topic102.LatestMessage.Position.Y ;

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 7,1) = obj.Obstacle_Topic103.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 8,1) = obj.Obstacle_Topic103.LatestMessage.Position.Y ;

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 10,1) = obj.Obstacle_Topic104.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 11,1) = obj.Obstacle_Topic104.LatestMessage.Position.Y ;

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 13,1) = obj.Obstacle_Topic105.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 14,1) = obj.Obstacle_Topic105.LatestMessage.Position.Y ;

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 16,1) = obj.Obstacle_Topic106.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 17,1) = obj.Obstacle_Topic106.LatestMessage.Position.Y ;

        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 19,1) = obj.Obstacle_Topic107.LatestMessage.Position.X ;
        Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 20,1) = obj.Obstacle_Topic107.LatestMessage.Position.Y ;

%         Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 22,1) = obj.Obstacle_Topic108.LatestMessage.Position.X ;
%         Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 23,1) = obj.Obstacle_Topic108.LatestMessage.Position.Y ;
% 
%         Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 25,1) = obj.Obstacle_Topic109.LatestMessage.Position.X ;
%         Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 26,1) = obj.Obstacle_Topic109.LatestMessage.Position.Y ;
% 
%         Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 28,1) = obj.Obstacle_Topic110.LatestMessage.Position.X ;
%         Plant.local.Obstacle(obj.Stationary_obstacles * 3 + 29,1) = obj.Obstacle_Topic110.LatestMessage.Position.Y ;



        Plant.local.ObstaclePos(1,1) = obj.Obstacle_Topic1.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(1,2) = obj.Obstacle_Topic1.LatestMessage.Position.Y ;
        Plant.local.ObstaclePos(1,3) = double(eulZYX1(3));%YAW

        Plant.local.ObstaclePos(2,1) = obj.Obstacle_Topic2.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(2,2) = obj.Obstacle_Topic2.LatestMessage.Position.Y ;
        Plant.local.ObstaclePos(2,3) = double(eulZYX2(3));%YAW

        Plant.local.ObstaclePos(3,1) = obj.Obstacle_Topic3.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(3,2) = obj.Obstacle_Topic3.LatestMessage.Position.Y ;
        Plant.local.ObstaclePos(3,3) = double(eulZYX3(3));%YAW
% 
%         Plant.local.ObstaclePos(4,1) = obj.Obstacle_Topic4.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(4,2) = obj.Obstacle_Topic4.LatestMessage.Position.Y ;
%         Plant.local.ObstaclePos(4,3) = double(eulZYX4(3));%YAW
% 
%         Plant.local.ObstaclePos(5,1) = obj.Obstacle_Topic5.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(5,2) = obj.Obstacle_Topic5.LatestMessage.Position.Y ;
%         Plant.local.ObstaclePos(5,3) = double(eulZYX5(3));%YAW
% 
%         Plant.local.ObstaclePos(6,1) = obj.Obstacle_Topic6.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(6,2) = obj.Obstacle_Topic6.LatestMessage.Position.Y ;
%         Plant.local.ObstaclePos(6,3) = double(eulZYX6(3));%YAW
% 
%         Plant.local.ObstaclePos(7,1) = obj.Obstacle_Topic7.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(7,2) = obj.Obstacle_Topic7.LatestMessage.Position.Y ;
%         Plant.local.ObstaclePos(7,3) = double(eulZYX7(3));%YAW
% 
%         Plant.local.ObstaclePos(8,1) = obj.Obstacle_Topic8.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(8,2) = obj.Obstacle_Topic8.LatestMessage.Position.Y ;
%         Plant.local.ObstaclePos(8,3) = double(eulZYX8(3));%YAW
% 
%         Plant.local.ObstaclePos(9,1) = obj.Obstacle_Topic9.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(9,2) = obj.Obstacle_Topic9.LatestMessage.Position.Y ;
%         Plant.local.ObstaclePos(9,3) = double(eulZYX9(3));%YAW

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 1,1) = obj.Obstacle_Topic101.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 1,2) = obj.Obstacle_Topic101.LatestMessage.Position.Y ;

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 2,1) = obj.Obstacle_Topic102.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 2,2) = obj.Obstacle_Topic102.LatestMessage.Position.Y ;

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 3,1) = obj.Obstacle_Topic103.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 3,2) = obj.Obstacle_Topic103.LatestMessage.Position.Y ;

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 4,1) = obj.Obstacle_Topic104.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 4,2) = obj.Obstacle_Topic104.LatestMessage.Position.Y ;

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 5,1) = obj.Obstacle_Topic105.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 5,2) = obj.Obstacle_Topic105.LatestMessage.Position.Y ;

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 6,1) = obj.Obstacle_Topic106.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 6,2) = obj.Obstacle_Topic106.LatestMessage.Position.Y ;

        Plant.local.ObstaclePos(obj.Stationary_obstacles + 7,1) = obj.Obstacle_Topic107.LatestMessage.Position.X ;
        Plant.local.ObstaclePos(obj.Stationary_obstacles + 7,2) = obj.Obstacle_Topic107.LatestMessage.Position.Y ;
% 
%         Plant.local.ObstaclePos(obj.Stationary_obstacles + 8,1) = obj.Obstacle_Topic108.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(obj.Stationary_obstacles + 8,2) = obj.Obstacle_Topic108.LatestMessage.Position.Y ;
% 
%         Plant.local.ObstaclePos(obj.Stationary_obstacles + 9,1) = obj.Obstacle_Topic109.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(obj.Stationary_obstacles + 9,2) = obj.Obstacle_Topic109.LatestMessage.Position.Y ;
% 
%         Plant.local.ObstaclePos(obj.Stationary_obstacles + 10,1) = obj.Obstacle_Topic110.LatestMessage.Position.X ;
%         Plant.local.ObstaclePos(obj.Stationary_obstacles + 10,2) = obj.Obstacle_Topic110.LatestMessage.Position.Y ;

        Plant.obs_state_L =0;


        % stop obstacle%

        if Plant.local.ObstaclePos(1,1) <= 0
            obj.InitialVelocity(1,1) = 0;
        elseif Plant.local.ObstaclePos(2,1) <= 1
            obj.InitialVelocity(2,1) = 0;
        elseif Plant.local.ObstaclePos(3,1) <= 2
            obj.InitialVelocity(3,1) = 0;
        elseif Plant.local.ObstaclePos(4,1) <= 3
            obj.InitialVelocity(4,1) = 0;
        elseif Plant.local.ObstaclePos(5,1) <= 4
            obj.InitialVelocity(5,1) = 0;
        elseif Plant.local.ObstaclePos(6,1) <= 5
            obj.InitialVelocity(6,1) = 0;
        elseif Plant.local.ObstaclePos(7,1) <= 6
            obj.InitialVelocity(7,1) = 0;
        elseif Plant.local.ObstaclePos(8,1) <= 7
            obj.InitialVelocity(8,1) = 0;
        elseif Plant.local.ObstaclePos(9,1) <= 8
            obj.InitialVelocity(9,1) = 0;
        elseif Plant.X >= 1 && Plant.X <= 80 && Plant.Y <= 2
            obj.InitialVelocity(1,1) = 0.2;
            obj.InitialVelocity(2,1) = 0.2;
            obj.InitialVelocity(3,1) = 0.3;
            obj.InitialVelocity(4,1) = 0.2;
            obj.InitialVelocity(5,1) = 0.4;
            obj.InitialVelocity(6,1) = 0.6;
            obj.InitialVelocity(7,1) = 0.6;
            obj.InitialVelocity(8,1) = 0.6;
            obj.InitialVelocity(9,1) = 0.6;
        end

%        % -- Obstacles feedback --%
        for L=1:1:obj.Stationary_obstacles
            obj.obsL=L;
            obj.ObstaclePosX = Plant.local.ObstaclePos(L,1);
            obj.ObstaclePosY = Plant.local.ObstaclePos(L,2);
            obj.ObstaclePosYAW = Plant.local.ObstaclePos(L,3);

%            % -- Section of obstacles --%
            if obj.ObstaclePosX >= 15.5 && obj.ObstaclePosY >= 0
                obj.obstaclesection = 1;
%             elseif obj.ObstaclePosX < 15.5
%                 obj.obstaclesection = 2;
            else
                obj.obstaclesection = 3;
            end

%            % -- caluculate obstacle reference --%
            if obj.obstaclesection == 1 || obj.obstaclesection == 3
                [yd ,thd] = ObsReference(obj);
            else
                [r ,thd] = ObsPolarReference(obj);
            end

%            % -- caluculate --%
            if obj.obstaclesection == 1 || obj.obstaclesection == 3
                obj.obsYdifferent=obj.ObstaclePosY - yd;
                if thd == 3.14 || thd == -3.14
                    obj.obsYdifferent = - ( obj.ObstaclePosY - yd );
                end
                obj.InitialVelocity(L,2) = - obj.obsk1 * obj.obsYdifferent - obj.obsk2 * (obj.ObstaclePosYAW - thd);
            else
                obj.InitialVelocity(L,2) = obj.InitialVelocity(1,1)/obj.obsrd - obj.obsf1 * (r - obj.obsrd) - obj.obsf2 * (obj.ObstaclePosYAW - thd);
            end
        end

%       %  --  send obstacle velocity --%
        obj.obs_Message{1}.Linear.X  = obj.InitialVelocity(1,1);
        obj.obs_Message{1}.Angular.Z = obj.InitialVelocity(1,2);
        send(obj.obs_Topic{1,1}, obj.obs_Message{1,1});

        obj.obs_Message{2}.Linear.X  = obj.InitialVelocity(2,1);
        obj.obs_Message{2}.Angular.Z = obj.InitialVelocity(2,2);
        send(obj.obs_Topic{1,2}, obj.obs_Message{1,2});

        obj.obs_Message{3}.Linear.X  = obj.InitialVelocity(3,1);
        obj.obs_Message{3}.Angular.Z = obj.InitialVelocity(3,2);
        if Plant.local.ObstaclePos(3,1) > 22
            obj.obs_Message{3}.Linear.X  = 0;
            obj.obs_Message{3}.Angular.Z = 0;
        end
        send(obj.obs_Topic{1,3}, obj.obs_Message{1,3});
% 
%         obj.obs_Message{4}.Linear.X  = obj.InitialVelocity(4,1);
%         obj.obs_Message{4}.Angular.Z = obj.InitialVelocity(4,2);
%         send(obj.obs_Topic{1,4}, obj.obs_Message{1,4});
% 
%         obj.obs_Message{5}.Linear.X  = obj.InitialVelocity(5,1);
%         obj.obs_Message{5}.Angular.Z = obj.InitialVelocity(5,2);
%         send(obj.obs_Topic{1,5}, obj.obs_Message{1,5});
% 
%         obj.obs_Message{6}.Linear.X  = obj.InitialVelocity(6,1);
%         obj.obs_Message{6}.Angular.Z = obj.InitialVelocity(6,2);
%         send(obj.obs_Topic{1,6}, obj.obs_Message{1,6});
% 
%         obj.obs_Message{7}.Linear.X  = obj.InitialVelocity(7,1);
%         obj.obs_Message{7}.Angular.Z = obj.InitialVelocity(7,2);
%         send(obj.obs_Topic{1,7}, obj.obs_Message{1,7});

%         obj.obs_Message{8}.Linear.X  = obj.InitialVelocity(8,1);
%         obj.obs_Message{8}.Angular.Z = obj.InitialVelocity(8,2);
%         send(obj.obs_Topic{1,8}, obj.obs_Message{1,8});
% 
%         obj.obs_Message{9}.Linear.X  = obj.InitialVelocity(9,1);
%         obj.obs_Message{9}.Angular.Z = obj.InitialVelocity(9,2);
%         send(obj.obs_Topic{1,9}, obj.obs_Message{1,9});

        obj.obs_Message{obj.Stationary_obstacles + 1}.Linear.X  = obj.InitialVelocity(1,1);
        obj.obs_Message{obj.Stationary_obstacles + 1}.Angular.Z = obj.InitialVelocity(1,2);
        send(obj.obs_Topic{1,obj.Stationary_obstacles + 1}, obj.obs_Message{1,obj.Stationary_obstacles + 1});

        obj.obs_Message{obj.Stationary_obstacles + 2}.Linear.X  = obj.InitialVelocity(2,1);
        obj.obs_Message{obj.Stationary_obstacles + 2}.Angular.Z = obj.InitialVelocity(2,2);
        send(obj.obs_Topic{1,obj.Stationary_obstacles + 2}, obj.obs_Message{1,obj.Stationary_obstacles + 2});

        obj.obs_Message{obj.Stationary_obstacles + 3}.Linear.X  = obj.InitialVelocity(3,1);
        obj.obs_Message{obj.Stationary_obstacles + 3}.Angular.Z = obj.InitialVelocity(3,2);
        send(obj.obs_Topic{1,obj.Stationary_obstacles + 3}, obj.obs_Message{1,obj.Stationary_obstacles + 3});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 4}.Linear.X  = obj.InitialVelocity(4,1);
%         obj.obs_Message{obj.Stationary_obstacles + 4}.Angular.Z = obj.InitialVelocity(4,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 4}, obj.obs_Message{1,obj.Stationary_obstacles + 4});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 5}.Linear.X  = obj.InitialVelocity(5,1);
%         obj.obs_Message{obj.Stationary_obstacles + 5}.Angular.Z = obj.InitialVelocity(5,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 5}, obj.obs_Message{1,obj.Stationary_obstacles + 5});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 6}.Linear.X  = obj.InitialVelocity(6,1);
%         obj.obs_Message{obj.Stationary_obstacles + 6}.Angular.Z = obj.InitialVelocity(6,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 6}, obj.obs_Message{1,obj.Stationary_obstacles + 6});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 7}.Linear.X  = obj.InitialVelocity(7,1);
%         obj.obs_Message{obj.Stationary_obstacles + 7}.Angular.Z = obj.InitialVelocity(7,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 7}, obj.obs_Message{1,obj.Stationary_obstacles + 7});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 8}.Linear.X  = obj.InitialVelocity(8,1);
%         obj.obs_Message{obj.Stationary_obstacles + 8}.Angular.Z = obj.InitialVelocity(8,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 8}, obj.obs_Message{1,obj.Stationary_obstacles + 8});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 9}.Linear.X  = obj.InitialVelocity(9,1);
%         obj.obs_Message{obj.Stationary_obstacles + 9}.Angular.Z = obj.InitialVelocity(9,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 9}, obj.obs_Message{1,obj.Stationary_obstacles + 9});
% 
%         obj.obs_Message{obj.Stationary_obstacles + 10}.Linear.X  = obj.InitialVelocity(10,1);
%         obj.obs_Message{obj.Stationary_obstacles + 10}.Angular.Z = obj.InitialVelocity(10,2);
%         send(obj.obs_Topic{1,obj.Stationary_obstacles + 10}, obj.obs_Message{1,obj.Stationary_obstacles + 10});
    end
end