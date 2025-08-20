function ret = getData(obj, sensor)
	obj.loopcount = obj.loopcount + 1;
	%-- Getting the data from Motive 
	%-- If the rigid data cannot be measured, it will stop this program.
	model = obj.NatnetClient.getModelDescription;
	if  model.RigidBodyCount < 1 
		error('Please check whether the rigid bodies is defined in Motive.')
	end
	%--Getting time from Motive 
	timeKeeper(obj);
	if obj.loopcount == 1
		obj.Time = 0.;
	end
	%-- Organize 
	organize(obj, model);
	if obj.loopcount == 1
		temp = obj.data.Rigid{obj.ControlRigid}.yaw;
		if obj.data.Rigid{obj.ControlRigid}.yaw < 0
			temp = temp + 360;
		end
		obj.old_data.rigid = obj.data.Rigid;
		obj.yaw = temp;
	end
	cicle(obj);
	obj.old_data.rigid = obj.data.Rigid;
	ret.Tpr = obj.Time;
    
    if sensor == 1
        ret.PrimeX   = double(obj.data.Rigid{obj.ControlRigid}.x);
        ret.PrimeY   = double(obj.data.Rigid{obj.ControlRigid}.y);
        ret.PrimeZ   = double(obj.data.Rigid{obj.ControlRigid}.z);
        ret.Primeqx  = double(obj.data.Rigid{obj.ControlRigid}.qx);
        ret.Primeqy  = double(obj.data.Rigid{obj.ControlRigid}.qy);
        ret.Primeqz  = double(obj.data.Rigid{obj.ControlRigid}.qz);
        ret.Primeqw  = double(obj.data.Rigid{obj.ControlRigid}.qw);
        ret.Primeroll  = double(obj.data.Rigid{obj.ControlRigid}.roll) * pi / 180;
        ret.Primepitch = double(obj.data.Rigid{obj.ControlRigid}.pitch) * pi / 180;
        ret.Primeyaw   = double(obj.yaw) * pi / 180;
    else
        ret.X   = double(obj.data.Rigid{obj.ControlRigid}.x);
        ret.Y   = double(obj.data.Rigid{obj.ControlRigid}.y);
        ret.Z   = double(obj.data.Rigid{obj.ControlRigid}.z);
        ret.qx  = double(obj.data.Rigid{obj.ControlRigid}.qx);
        ret.qy  = double(obj.data.Rigid{obj.ControlRigid}.qy);
        ret.qz  = double(obj.data.Rigid{obj.ControlRigid}.qz);
        ret.qw  = double(obj.data.Rigid{obj.ControlRigid}.qw);
        ret.roll  = double(obj.data.Rigid{obj.ControlRigid}.roll) * pi / 180;
        ret.pitch = double(obj.data.Rigid{obj.ControlRigid}.pitch) * pi / 180;
        ret.yaw   = double(obj.yaw) * pi / 180;
    end

	ret.Rigid = obj.data.Rigid;
	ret.MarkerData   = obj.data.MarkerData;
	ret.UnmarkerData = obj.data.UnmarkerData;
    
end