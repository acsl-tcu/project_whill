function RawData = integrateData(obj)
	switch obj.Mode
	case {'Numerical', 1}
		RawData= getData(obj.DataObj);
	case {'Physics',   2}
		RawData= getData(obj.DataObj);
	case {'Expriment', 3}
		RawRosData= getData(obj.DataObj);
		if obj.Sensor(obj.Prime)
			RawNatnet = getData(obj.natnetObj, obj.Autoware);
            DataCell = [struct2cell(RawNatnet); struct2cell(RawRosData)];
            DataName = [fieldnames(RawNatnet);  fieldnames(RawRosData)];
        elseif obj.Autoware
            DataCell = struct2cell(RawRosData);
            DataName = fieldnames(RawRosData);
        else
			RawNatnet = structGeneration(obj);
            DataCell = [struct2cell(RawNatnet); struct2cell(RawRosData)];
            DataName = [fieldnames(RawNatnet);  fieldnames(RawRosData)];
        end
		RawData  = cell2struct(DataCell, DataName, 1);
    case {'Offline',  4}
		RawRosData= getData(obj.DataObj);
        RawNatnet = structGeneration(obj);
		DataCell = [struct2cell(RawNatnet); struct2cell(RawRosData)];
		DataName = [fieldnames(RawNatnet);  fieldnames(RawRosData)];
		RawData  = cell2struct(DataCell, DataName, 1);
	end
end
	
function ret = structGeneration(obj)
    for L = obj.est
       ret.(obj.Names{L}) = 0.;
    end
end
