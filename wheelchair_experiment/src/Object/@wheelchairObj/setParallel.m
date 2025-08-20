function [] = setParallel(obj)
    answer = questdlg( ...
        'Is it OK to run the Monte Carlo simulation under the conditions described in the main.m?', ...
        'WARNING!!' ...
        );
    %-- Handle response
    switch answer
        case 'Yes'
            prompt = '%= Configuration of the parallel conputing =% \n';
            [~] = input(prompt);
            prompt = 'Type the number of iterations: ';
            inputAns = input(prompt);
            status = rmdir(obj.folderInfo(obj.FilePath, obj.FileName), 's');
            if status
                disp('Initialization is complete for the Monte Carlo simulation.')
            else
                disp('Initialization has failed. Please delete the your data file manually...')
            end
            %-- Parameter
            if isempty(inputAns)
                error('Monte Calro simulation were canceled...');
            end
            iter  = inputAns;
            numout= 0;
            idx	  = 1;

            %-- setting of perpool
            delete(gcp('nocreate'));
            p = parpool('local');
            switch obj.Mode
                case {'Numerical', 1}
                    disp('You selected Monte Carlo "Numerical" simulations. The simulations started...');
                case {'Offline',  4}
                    disp('You selected Monte Carlo "Offline" simulations. The simulations started...');
                otherwise
                    error('Wrong number! In Monte Carlo simulations, you can not select "Physics" and "Expriment" modes.');
            end
            conf.appMode         = false;
            conf.loopMode        = false;
            conf.te              = obj.EndTime;
            conf.dt              = obj.DeltaT;
            conf.addr.HostIP     = '127.0.0.1';
            conf.addr.ROSHostIP  = '127.0.0.1';
            conf.mode            = obj.Mode;
            conf.sensor          = obj.Sensor;
            conf.rgtNum          = [];
            conf.startstate      = obj.InitPose;
            conf.rbPath          = obj.RosbagFullPath;
            conf.mySavePath      = obj.FilePath;
            conf.mySaveFileName  = obj.FileName;
            conf.ControllerObj   = obj.ControllerObj;
            conf.EstimatorObj    = obj.EstimatorObj;
            %-- Loop
            while idx <= iter
                f(idx) = parfeval(p, @parallelMain, numout, conf, idx, iter);
                idx = idx + 1;
            end
            wait(f);
            delete(gcp('nocreate'));
        case 'No'
            error('Monte Calro simulation were canceled...');
        otherwise 
            error('Monte Calro simulation were canceled...');
    end
end

function [] = parallelMain(conf, idx, iter)
    clc; close all; 

    obj = wheelchairObj( ...
        conf.appMode, conf.loopMode, conf.te, conf.dt, conf.addr, ...
        conf.mode, conf.sensor, conf.rgtNum, conf.startstate, conf.rbPath ...
        );
    
    obj.ControllerObj = conf.ControllerObj;
    obj.EstimatorObj  = onf.EstimatorObj;
    
    obj.FilePath = conf.mySavePath;
    obj.FileName = [conf.mySaveFileName,'_Parallel', num2str(idx)];
    folderPath   = makeFolder(obj);
    
    save(strcat(folderPath, filesep, 'parallelSettings.mat'), 'iter', 'idx' ,'conf');

    [~] = mainLoop(obj);
    
    plotResult(folderPath);
end