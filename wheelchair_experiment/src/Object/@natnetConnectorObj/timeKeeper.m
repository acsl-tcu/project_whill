function [] = timeKeeper(obj)
	obj.getFrame= obj.NatnetClient.getFrame;
	%Acquire time data from prime
	Timenew     = obj.getFrame.Timestamp;
	dTime       = Timenew - obj.Timeold;
	obj.Time    = obj.Time + dTime;
	obj.Timeold = Timenew;
end
