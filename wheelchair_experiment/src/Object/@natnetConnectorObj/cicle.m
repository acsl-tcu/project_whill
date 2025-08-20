function [] = cicle(obj)
	dyaw = obj.data.Rigid{obj.ControlRigid}.yaw - obj.old_data.rigid{obj.ControlRigid}.yaw;
	if dyaw < -180
	   dyaw = dyaw + 360;
	end
	if dyaw > 180
	   dyaw = dyaw  - 360;
	end
	obj.yaw = obj.yaw + dyaw;

	if obj.yaw > 360 * obj.n
	  % ç∂âÒÇËÇê≥Ç∆Ç∑ÇÈ 
	  obj.n = obj.n + 1;
	end
end