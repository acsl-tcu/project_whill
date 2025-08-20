function ret = endProcessing(obj, varargin)
    kbhit('stop'); 
    % existが7(保存した値があれば7)且つデータ保存がtrueの時
    if exist(obj.Datadir, 'dir') == 7 && isempty(varargin) == 1
        if obj.DataSave == 1
            % 自分で保存する関数があるのでそこに入る
            feval(obj.SaveFunction, obj.Datadir, obj.DataObj.Data);
        else
            % デフォルトの保存の仕方で保存する
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