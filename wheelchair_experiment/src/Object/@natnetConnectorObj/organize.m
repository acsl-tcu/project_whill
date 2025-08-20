function [] = organize(obj, model)
	% Count number of marker and rigid
	% Get number of marker and rigid
	obj.RigidBodyCount= model.RigidBodyCount;
	obj.markerNum = System.Array.IndexOf(obj.getFrame.UnlabeledMarker, []);
	CountMarker = System.Array.IndexOf(obj.getFrame.LabeledMarker, []) - obj.markerNum;

	% data marker count
	if obj.CountMarker_max < CountMarker
		obj.CountMarker_max = CountMarker;
	end

	% %If rigidbody count = 0,stop program
	if (System.Array.IndexOf(obj.getFrame.RigidBody,[]) == 0)
		error('Make sure the server is in Live mode or playing in playback.')
	end

	% %Get obj.data and Organize
	% %also organizing obj.data in the same way in main.m
	for idx = 1:obj.RigidBodyCount
		obj.data.Rigid{idx}.Time = obj.Time;
		body = obj.getFrame.RigidBody(idx);
		obj.data.Rigid{idx}.x = body.x;
		obj.data.Rigid{idx}.y = -body.z;
		obj.data.Rigid{idx}.z = body.y;

		% % quaternion
		getQ(obj, body, idx);
	end

	for idx = 1:obj.markerNum
		obj.data.MarkerData{idx}.Time = obj.Time;
		marker = obj.getFrame.LabeledMarker(idx);
		obj.data.MarkerData{idx}.x = marker.x;
		obj.data.MarkerData{idx}.y = -marker.z;
		obj.data.MarkerData{idx}.z = marker.y;
	end

	for idx = 1:CountMarker + obj.markerNum
		obj.data.Unmarkerobj.data{idx}.obj.Time = obj.Time;
		marker = obj.getFrame.LabeledMarker(idx);
		obj.data.UnmarkerData{idx}.x = marker.x;
		obj.data.UnmarkerData{idx}.y = -marker.z;
		obj.data.UnmarkerData{idx}.z = marker.y;
	end
end