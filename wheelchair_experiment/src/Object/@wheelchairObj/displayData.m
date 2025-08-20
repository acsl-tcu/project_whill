function displayData(obj, T, RawData, EstimatedData, ControledData)
	obj.Count = obj.Count + 1;
	if  obj.Display == 1 && isempty(obj.DispFunction) == 1 && rem(round(T,1),obj.DispInterval) == 0
		clc; warning('off','backtrace');
		Notation = '%.3f';
		PerNum   = 80;
		disp(repelem('%', PerNum));
		disp(['Time: ', num2str(T, Notation)]);
		disp(['State X: ', num2str(EstimatedData.X, Notation), ' Y: ',  num2str(EstimatedData.Y, Notation), ' Th: ', num2str(EstimatedData.yaw, Notation)]);
		disp(['Input V: ', num2str(ControledData.V(1,1),  Notation), ' omg:', num2str(ControledData.V(2,1), Notation)]);
		disp(repelem('%', PerNum));

        if isempty(obj.EstimatorObj)
            warning('Your class file for estimation was not founded. Measurement data are returned.');
        elseif isempty(obj.ControllerObj)
            warning('Your class file for control was not founded. Zero control inputs are returned.');
		end
		
    elseif obj.Display == 1 && rem(T,obj.DispInterval) == 0 && ~isempty(obj.DispFunction)
        clc;
        Plant.T = T;
        Plant.RawData = RawData;
        Plant.EstimatedData = EstimatedData;
        Plant.ControledData = ControledData;
        feval(obj.DispFunction, Plant);
	end
end