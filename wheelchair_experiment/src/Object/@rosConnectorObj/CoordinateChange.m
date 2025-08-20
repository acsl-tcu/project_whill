function ret = CoordinateChange(ret, obj)
    Change =  [cos(obj.Tmp.yaw), -sin(obj.Tmp.yaw), 0; sin(obj.Tmp.yaw), cos(obj.Tmp.yaw), 0; 0, 0, 1]...
            * [cos(obj.Tmp.pitch), 0, sin(obj.Tmp.pitch); 0, 1, 0; -sin(obj.Tmp.pitch), 0, cos(obj.Tmp.pitch)]...
            * [1, 0, 0; 0, cos(obj.Tmp.roll), -sin(obj.Tmp.roll); 0, sin(obj.Tmp.roll), cos(obj.Tmp.roll)];

    ref = Change * [ret.refX; ret.refY; ret.refZ];
    ret.refX = ref(1, :) + obj.Tmp.X;
    ret.refY = ref(2, :) + obj.Tmp.Y;
    ret.refZ = ref(3, :) + obj.Tmp.Z;
    ret.refroll = ret.refroll + obj.Tmp.roll;
    ret.refpitch = ret.refpitch +obj.Tmp.pitch;
    ret.refyaw = ret.refyaw + obj.Tmp.yaw;
end