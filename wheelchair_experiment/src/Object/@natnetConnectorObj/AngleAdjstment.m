function ret = AngleAdjstment(ret, obj)
    while ret.roll - obj.data.Rigid{obj.ControlRigid}.roll > pi
       ret.roll = ret.roll - 2 * pi;
    end

    while ret.roll - obj.data.Rigid{obj.ControlRigid}.roll <= -pi
       ret.roll = ret.roll + 2 * pi;
    end

    while ret.pitch - obj.data.Rigid{obj.ControlRigid}.pitch > pi
       ret.pitch = ret.pitch - 2 * pi;
    end

    while ret.pitch - obj.data.Rigid{obj.ControlRigid}.pitch <= -pi
       ret.pitch = ret.pitch + 2 * pi;
    end

    while ret.yaw - obj.data.Rigid{obj.ControlRigid}.yaw > pi
       ret.yaw = ret.yaw - 2 * pi;
    end

    while ret.yaw - obj.data.Rigid{obj.ControlRigid}.yaw <= -pi
       ret.yaw = ret.yaw + 2 * pi;
    end
end