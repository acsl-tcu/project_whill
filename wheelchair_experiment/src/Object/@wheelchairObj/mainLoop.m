function Data = mainLoop(obj, varargin)
if obj.LoopMode
    setParallel(obj);
    Data = [];
else
    waitTime = 1.e-12;
    while 1
        % Check for keyboard input and show menu before executing command
        if obj.checkForModeMenu()
            break; % Exit if user requested
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