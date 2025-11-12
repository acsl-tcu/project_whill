function Data = mainLoop(obj, varargin)
if obj.LoopMode
    setParallel(obj);
    Data = [];
else
    % Show menu at startup before main loop begins
    fprintf('\n*** INITIAL SETUP ***\n');
    fprintf('Please select a mode to start the wheelchair system.\n');
    if obj.checkForModeMenu()
        Data = [];
        return; % Exit if user requested
    end

    waitTime = 1.e-12;
    while 1
        % Check if pause was requested (keyboard detected in executeCommand)
        if obj.pauseRequested
            obj.pauseRequested = false; % Clear flag
            if obj.checkForModeMenu()
                break; % Exit if user requested
            end
        end

        % executeCommand��1�ɂȂ�����E�o
        while 1
            if executeCommand(obj);
                break;
            end
        end
        if ~isempty(varargin)
            varargin{1}.TranslationalvelocityGauge.Value = obj.DataObj.Data.V(1, obj.Count+1);
            varargin{1}.RotationalvelocityGauge.Value    = obj.DataObj.Data.V(2, obj.Count+1);
            if varargin{1}.EndButton.Value == 1
                break;
            end
            pause(waitTime);
        end
    end
end
end