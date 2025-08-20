function testDoor()
    % Final MATLAB script to control the sliding door in Gazebo

fprintf('Starting door control test...\n');

try

    % Create publisher for the door command topic
    doorPub = rospublisher('/sliding_door/door_joint_position_controller/command', 'std_msgs/Float64');
    doorMsg = rosmessage(doorPub);
    
    % --- OPEN THE DOOR ---
    fprintf('Sending command to OPEN the door (position 0.5)...\n');
    doorMsg.Data = 1.1;
    send(doorPub, doorMsg);
    pause(5); % Wait for door to move

    % --- CLOSE THE DOOR ---
    fprintf('Sending command to CLOSE the door (position 0.0)...\n');
    doorMsg.Data = 0.0;
    send(doorPub, doorMsg);
    
    fprintf('Script finished.\n');

    
catch ME
    fprintf('An error occurred: %s\n', ME.message);

end

end