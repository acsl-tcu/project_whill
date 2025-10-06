function controlElevatorDoor(action)
    % Control elevator door function
    % Input: action - 'open' or 'close'
    % Note: Door control is reversed - 0.0 = open, 1.1 = close
    
    try
        % Create fresh ROS publisher and message each time
        
        doorPub = rospublisher('/sliding_door/door_joint_position_controller/command', 'std_msgs/Float64');
        doorMsg = rosmessage(doorPub);
        
        % Set door position based on action (reversed logic)
        if strcmp(action, 'open')
            doorMsg.Data = 0.0;              fprintf('Opening elevator door...\n');
        elseif strcmp(action, 'close')
            doorMsg.Data = -1.4;   
            fprintf('Closing elevator door...\n');
        else
            fprintf('Error: Invalid action. Use "open" or "close".\n');
            return;
        end
        
        % Send command to door
        send(doorPub, doorMsg);
        pause(3)
        
    catch ME
        fprintf('Error controlling elevator door: %s\n', ME.message);
    end
end