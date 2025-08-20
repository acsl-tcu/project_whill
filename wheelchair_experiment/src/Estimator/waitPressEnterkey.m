function [] = waitPressEnterkey(count)
    kbhit('stop'); 
    kbhit('init');
    if count == 0
        disp('Press "Enter" key to calculate initial values of RANSAC.');
    else
        disp('Processing has done. Press "Enter" key to start tracking.');
    end
    waitTime = 1.e-3;
    while 1
        event = kbhit('event');
        key = get(event, 'KeyCode');
        pause(waitTime);
        if ~isempty(key) && key == 10
            break;
        end
    end
end