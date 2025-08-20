function [] = getQ(obj, body, idx)
    % %Acquire quartanion from prime
    obj.data.Rigid{idx}.qx = body.qx;
    obj.data.Rigid{idx}.qy = body.qy;
    obj.data.Rigid{idx}.qz = body.qz;
    obj.data.Rigid{idx}.qw = body.qw;

    % %Calculate roll, pitch, yaw
    % %Adjusted to be correct value
    % % -180<roll<180
    % % -90<pitch<90
    % % -180<yaw<180

    tmp = body.qx * body.qy + body.qz * body.qw;
    if tmp > 0.499
        r_pos(idx,1) = 2 * atan2(body.qx, body.qw);
        r_pos(idx,2) = - pi / 2;
        r_pos(idx,3) = 0.;
    elseif tmp < -0.499
        r_pos(idx,1) = -2 * atan2(body.qx, body.qw);
        r_pos(idx,2) = -1 - pi / 2;
        r_pos(idx,3) = 0.;
    else
        r_pos(idx,1) = atan2(2 * (body.qw * body.qx - body.qy * body.qz), 1 - 2 * (body.qx * body.qx + body.qz * body.qz));
        r_pos(idx,2) = -asin(2 * tmp);
        r_pos(idx,3) = atan2(2 * (body.qw * body.qy - body.qx * body.qz), 1 - 2 * (body.qy * body.qy + body.qz * body.qz));
    end
    obj.data.Rigid{idx}.roll  = r_pos(idx,1) * 180.0 / pi;
    obj.data.Rigid{idx}.pitch = r_pos(idx,2) * 180.0 / pi;
    obj.data.Rigid{idx}.yaw   = r_pos(idx,3) * 180.0 / pi;
end