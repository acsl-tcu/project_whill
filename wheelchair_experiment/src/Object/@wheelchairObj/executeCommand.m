function ret = executeCommand(obj)
% データの統合
% 推定器を回す
% 制御器を回す
% データの更新と表示
% 上記4つを行っている
% try ~~ catch 
	try 
        % データの収集
        %RawData = Plant
		RawData   = integrateData(obj);
		StopWatch = tic;
        T = RawData.T;
        % 推定器
		EstimatedData = exeEstimate(obj, RawData);
        checkData(obj, EstimatedData, "estimate");
        % 制御器
		ControledData = exeControl(obj, EstimatedData);
		ControledData.ComputationTime = toc(StopWatch);
        checkData(obj, ControledData, "control");
        % データの更新，表示
		updateData(obj.DataObj, RawData, EstimatedData, ControledData);
		displayData(obj, T, RawData, EstimatedData, ControledData);
        
        ret = modeLogical(obj, RawData);
	catch ME
		switch obj.Mode
			case {'Expriment', 3}
                % 0入力を出す
				endExperiment(obj.DataObj);
                warning('off', 'backtrace')
				warning('Emergency stop! Modify the cause of failure in your algorithm.');
                % エラーを吐く
                rethrow(ME);
			otherwise
				rethrow(ME);
		end
	end
end
function result = exeEstimate(obj, RawData)
    if isempty(obj.EstimatorObj) == 0
		result = main(obj.EstimatorObj, RawData);
    else	
		result = RawData;
    end
end
function result = exeControl(obj, RawData)
	if isempty(obj.ControllerObj) == 0
		result = main(obj.ControllerObj, RawData);
    else
		result.V = zeros(2,1);
	end
end