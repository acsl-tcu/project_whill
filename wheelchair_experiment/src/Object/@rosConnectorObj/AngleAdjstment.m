function ret = AngleAdjstment(ret, obj)
    while ret.roll - obj.Data.roll(1,obj.Count-1) > pi
       ret.roll = ret.roll - 2 * pi;
    end

    while ret.roll - obj.Data.roll(1,obj.Count-1) <= -pi
       ret.roll = ret.roll + 2 * pi;
    end

    while ret.pitch - obj.Data.pitch(1,obj.Count-1) > pi
       ret.pitch = ret.pitch - 2 * pi;
    end

    while ret.pitch - obj.Data.pitch(1,obj.Count-1) <= -pi
       ret.pitch = ret.pitch + 2 * pi;
    end

    while ret.yaw - obj.Data.yaw(1,obj.Count-1) > pi
       ret.yaw = ret.yaw - 2 * pi;
    end

    while ret.yaw - obj.Data.yaw(1,obj.Count-1) <= -pi
       ret.yaw = ret.yaw + 2 * pi;
    end
end