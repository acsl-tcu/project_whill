function obj = ROS_Setting(obj)
%       % -- subscrib obstacle initial state and publish obstacle initial velocity --%
    obj.Obstacle_Topic1 = rossubscriber('/obstacle/obs_pose1','geometry_msgs/Pose');
    obj.Obstacle_Topic2 = rossubscriber('/obstacle2/obs_pose2','geometry_msgs/Pose');
    obj.Obstacle_Topic3 = rossubscriber('/obstacle3/obs_pose3','geometry_msgs/Pose');
    obj.Obstacle_Topic4 = rossubscriber('/obstacle4/obs_pose4','geometry_msgs/Pose');
    obj.Obstacle_Topic5 = rossubscriber('/obstacle5/obs_pose5','geometry_msgs/Pose');
    obj.Obstacle_Topic6 = rossubscriber('/obstacle6/obs_pose6','geometry_msgs/Pose');
    obj.Obstacle_Topic7 = rossubscriber('/obstacle7/obs_pose7','geometry_msgs/Pose');
    obj.Obstacle_Topic8 = rossubscriber('/obstacle8/obs_pose8','geometry_msgs/Pose');
    obj.Obstacle_Topic9 = rossubscriber('/obstacle9/obs_pose9','geometry_msgs/Pose');

    obj.Obstacle_Topic101 = rossubscriber('/obstacle101/obs_pose101','geometry_msgs/Pose');
    obj.Obstacle_Topic102 = rossubscriber('/obstacle102/obs_pose102','geometry_msgs/Pose');
    obj.Obstacle_Topic103 = rossubscriber('/obstacle103/obs_pose103','geometry_msgs/Pose');
    obj.Obstacle_Topic104 = rossubscriber('/obstacle104/obs_pose104','geometry_msgs/Pose');
    obj.Obstacle_Topic105 = rossubscriber('/obstacle105/obs_pose105','geometry_msgs/Pose');
    obj.Obstacle_Topic106 = rossubscriber('/obstacle106/obs_pose106','geometry_msgs/Pose');
    obj.Obstacle_Topic107 = rossubscriber('/obstacle107/obs_pose107','geometry_msgs/Pose');
    obj.Obstacle_Topic108 = rossubscriber('/obstacle108/obs_pose108','geometry_msgs/Pose');
    obj.Obstacle_Topic109 = rossubscriber('/obstacle109/obs_pose109','geometry_msgs/Pose');
    obj.Obstacle_Topic110 = rossubscriber('/obstacle110/obs_pose110','geometry_msgs/Pose');

    obj.obs_Topic{1}            = rospublisher('/obstacle/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle/cmd_vel initialzing.');
    obj.obs_Message{1}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{1}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{1}, obj.obs_Message{1});

    obj.obs_Topic{2}            = rospublisher('/obstacle2/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle2/cmd_vel initialzing.');
    obj.obs_Message{2}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{2}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{2}, obj.obs_Message{2});

    obj.obs_Topic{3}            = rospublisher('/obstacle3/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle3/cmd_vel initialzing.');
    obj.obs_Message{3}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{3}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{3}, obj.obs_Message{3});

    obj.obs_Topic{4}            = rospublisher('/obstacle4/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle4/cmd_vel initialzing.');
    obj.obs_Message{4}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{4}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{4}, obj.obs_Message{4});

    obj.obs_Topic{5}            = rospublisher('/obstacle5/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle5/cmd_vel initialzing.');
    obj.obs_Message{5}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{5}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{5}, obj.obs_Message{5});

    obj.obs_Topic{6}            = rospublisher('/obstacle6/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle2/cmd_vel initialzing.');
    obj.obs_Message{6}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{6}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{6}, obj.obs_Message{6});

    obj.obs_Topic{7}            = rospublisher('/obstacle7/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle7/cmd_vel initialzing.');
    obj.obs_Message{7}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{7}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{7}, obj.obs_Message{7});

    obj.obs_Topic{8}            = rospublisher('/obstacle8/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle8/cmd_vel initialzing.');
    obj.obs_Message{8}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{8}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{8}, obj.obs_Message{8});

    obj.obs_Topic{9}            = rospublisher('/obstacle9/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle9/cmd_vel initialzing.');
    obj.obs_Message{9}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{9}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{9}, obj.obs_Message{9});

    obj.obs_Topic{obj.Stationary_obstacles + 1}            = rospublisher('/obstacle101/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle101/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 1}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 1}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 1}, obj.obs_Message{obj.Stationary_obstacles + 1});

    obj.obs_Topic{obj.Stationary_obstacles + 2}            = rospublisher('/obstacle102/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle102/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 2}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 2}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 2}, obj.obs_Message{obj.Stationary_obstacles + 2});

    obj.obs_Topic{obj.Stationary_obstacles + 3}            = rospublisher('/obstacle103/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle103/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 3}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 3}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 3}, obj.obs_Message{obj.Stationary_obstacles + 3});

    obj.obs_Topic{obj.Stationary_obstacles + 4}            = rospublisher('/obstacle104/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle104/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 4}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 4}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 4}, obj.obs_Message{obj.Stationary_obstacles + 4});

    obj.obs_Topic{obj.Stationary_obstacles + 5}            = rospublisher('/obstacle105/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle105/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 5}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 5}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 5}, obj.obs_Message{obj.Stationary_obstacles + 5});

    obj.obs_Topic{obj.Stationary_obstacles + 6}            = rospublisher('/obstacle106/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle106/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 6}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 6}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 6}, obj.obs_Message{obj.Stationary_obstacles + 6});

    obj.obs_Topic{obj.Stationary_obstacles + 7}            = rospublisher('/obstacle107/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle107/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 7}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 7}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 7}, obj.obs_Message{obj.Stationary_obstacles + 7});

    obj.obs_Topic{obj.Stationary_obstacles + 8}            = rospublisher('/obstacle108/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle108/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 8}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 8}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 8}, obj.obs_Message{obj.Stationary_obstacles + 8});

    obj.obs_Topic{obj.Stationary_obstacles + 9}            = rospublisher('/obstacle109/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle109/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 9}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 9}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 9}, obj.obs_Message{obj.Stationary_obstacles + 9});

    obj.obs_Topic{obj.Stationary_obstacles + 10}            = rospublisher('/obstacle110/cmd_vel','geometry_msgs/Twist');
    obj.obs_Message				= cellfun(@rosmessage, obj.obs_Topic, 'UniformOutput', false);
    disp('ROSpublisher /obstacle110/cmd_vel initialzing.');
    obj.obs_Message{obj.Stationary_obstacles + 10}.Linear.X  = obj.InitialVelocity(1,1);
    obj.obs_Message{obj.Stationary_obstacles + 10}.Angular.Z = obj.InitialVelocity(1,2);
    send(obj.obs_Topic{obj.Stationary_obstacles + 10}, obj.obs_Message{obj.Stationary_obstacles + 10});
end