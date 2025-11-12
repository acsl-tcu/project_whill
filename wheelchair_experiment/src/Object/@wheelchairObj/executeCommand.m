function ret = executeCommand(obj)
% �f�[�^�̓���
% ��������
% ��������
% �f�[�^�̍X�V�ƕ\��
% ��L4���s���Ă���
% try ~~ catch 
	try 
        % �f�[�^�̎��W
        %RawData = Plant
		RawData   = integrateData(obj);
		StopWatch = tic;
        T = RawData.T;
        % �����
		EstimatedData = exeEstimate(obj, RawData);
        checkData(obj, EstimatedData, "estimate");

        % Check for keyboard interrupt after Estimate (increase responsiveness)
        if isletter(kbhit)
            obj.pauseRequested = true;
        end

        % �����
		ControledData = exeControl(obj, EstimatedData);
		ControledData.ComputationTime = toc(StopWatch);

        % Check for keyboard interrupt after Control (increase responsiveness)
        if isletter(kbhit)
            obj.pauseRequested = true;
        end
        checkData(obj, ControledData, "control");
        % �f�[�^�̍X�V�C�\��
		updateData(obj.DataObj, RawData, EstimatedData, ControledData);
		displayData(obj, T, RawData, EstimatedData, ControledData);
        
        ret = modeLogical(obj, RawData);
	catch ME
		switch obj.Mode
			case {'Expriment', 3}
                % 0���͂��o��
				endExperiment(obj.DataObj);
                warning('off', 'backtrace')
				warning('Emergency stop! Modify the cause of failure in your algorithm.');
                % �G���[��f��
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