function ret = endProcessing(obj, varargin)
    kbhit('stop'); 
    % exist��7(�ۑ������l�������7)���f�[�^�ۑ���true�̎�
    if exist(obj.Datadir, 'dir') == 7 && isempty(varargin) == 1
        if obj.DataSave == 1
            % �����ŕۑ�����֐�������̂ł����ɓ���
            feval(obj.SaveFunction, obj.Datadir, obj.DataObj.Data);
        else
            % �f�t�H���g�̕ۑ��̎d���ŕۑ�����
            saveData2file(obj.DataObj, obj.Datadir);
        end
        
    elseif varargin{1} == "emergency"
        switch obj.Mode
			case {'Physics', 2, 'Expriment', 3}
				endExperiment(obj.DataObj);
        end

    end
    ret = obj.DataObj.Data;
end