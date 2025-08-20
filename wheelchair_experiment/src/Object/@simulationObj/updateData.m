function updateData(obj,RawData, EstimatedData, ControledData)
	obj.Count = obj.Count + 1;
    tspan= [obj.data.T - obj.DeltaT, obj.data.T];
    x0   = [EstimatedData.X; EstimatedData.Y; EstimatedData.Z; EstimatedData.roll; EstimatedData.pitch; EstimatedData.yaw];
    solc = ode45(@(t, x) model(t, x ,ControledData.V), tspan, x0);
    xode = deval(solc, linspace(obj.data.T - obj.DeltaT, obj.data.T));
	obj.Data.T(:,obj.Count)     = obj.data.T;
	obj.Data.X(:,obj.Count)     = xode(1,end);
	obj.Data.Y(:,obj.Count)     = xode(2,end);
	obj.Data.Z(:,obj.Count)     = xode(3,end);
	obj.Data.roll(:,obj.Count)  = xode(4,end);
	obj.Data.pitch(:,obj.Count) = xode(5,end);
	obj.Data.yaw(:,obj.Count)   = xode(6,end);
	eul  = [EstimatedData.roll, EstimatedData.pitch,  EstimatedData.yaw];
	quat = eul2quat(eul);
	obj.Data.qx(:,obj.Count)    = quat(1);
	obj.Data.qy(:,obj.Count)    = quat(2);
	obj.Data.qz(:,obj.Count)    = quat(3);
	obj.Data.qw(:,obj.Count)    = quat(4);
	obj.Data.V(:,obj.Count)     = ControledData.V;
	obj.Data.Omega(1,obj.Count) = (obj.Data.V(1,obj.Count) + obj.Width*obj.Data.V(2,obj.Count));
	obj.Data.Omega(2,obj.Count) = (obj.Data.V(1,obj.Count) - obj.Width*obj.Data.V(2,obj.Count));
    obj.Data.ComputationTime(:,obj.Count) = ControledData.ComputationTime;
    
    x0   = [obj.data.X; obj.data.Y; obj.data.Z; obj.data.roll; obj.data.pitch; obj.data.yaw];
    solc = ode45(@(t,x) model(t, x ,ControledData.V), tspan, x0);
    xode = deval(solc, linspace(obj.data.T - obj.DeltaT, obj.data.T));
    trueData.T     = obj.data.T;
	trueData.X     = xode(1,end);
	trueData.Y     = xode(2,end);
	trueData.Z     = xode(3,end);
	trueData.roll  = xode(4,end);
	trueData.pitch = xode(5,end);
	trueData.yaw   = xode(6,end);
	eul  = [trueData.roll, trueData.pitch,  trueData.yaw];
	quat = eul2quat(eul);
	trueData.qx    = quat(1);
	trueData.qy    = quat(2);
	trueData.qz    = quat(3);
	trueData.qw    = quat(4);
	trueData.V     = ControledData.V;
	trueData.Omega(1,1) = (obj.Data.V(1,obj.Count) - obj.Width*obj.Data.V(2,obj.Count));
	trueData.Omega(2,1) = (obj.Data.V(1,obj.Count) + obj.Width*obj.Data.V(2,obj.Count));
    trueData.ComputationTime = ControledData.ComputationTime;
    
    Names = fieldnames(trueData);
    for L = 1:length(Names)
        obj.TrueData.(Names{L})(:,obj.Count) = trueData.(Names{L});
    end

    if isfield(EstimatedData,'local') == 1 && isfield(ControledData,'local') == 1
        DataCell = [{obj.Data.T(:,obj.Count)}; RawData; trueData; struct2cell(EstimatedData.local); struct2cell(ControledData.local)];
        DataName = ["TimeLocal"; "RawData"; "TrueData"; fieldnames(EstimatedData.local); fieldnames(ControledData.local)];
    elseif isfield(EstimatedData,'local') == 0 && isfield(ControledData,'local') == 1
        DataCell = [{obj.Data.T(:,obj.Count)}; RawData; trueData; struct2cell(ControledData.local)];
        DataName = ["TimeLocal"; "RawData"; "TrueData"; fieldnames(ControledData.local)];
    elseif isfield(EstimatedData,'local') == 1 && isfield(ControledData,'local') == 0
        DataCell = [{obj.Data.T(:,obj.Count)}; RawData; trueData; struct2cell(EstimatedData.local)];
        DataName = ["TimeLocal"; "RawData"; "TrueData"; fieldnames(EstimatedData.local)];
    else
        DataCell = [{obj.Data.T(:,obj.Count)}; RawData; trueData];
        DataName = ["TimeLocal"; "RawData"; "TrueData"];   
    end
     obj.Data.local(:,obj.Count) = cell2struct(DataCell, DataName, 1);
end

function dxdt = model(~, x ,V)
    %-- The model of autonomous vehicle (electric wheelchair)
    u = [V(1)*cos(x(6)); V(1)*sin(x(6)); 0.; 0.; 0.; V(2)];
    dxdt = u;
end