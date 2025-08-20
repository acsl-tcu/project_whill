function ltheta = get_ltheta(obj)
% 車椅子の4隅の位置を求めるためのパラメータ(1:左後ろ　2:左前　3:右後ろ　4:右前)
% a1:wheel_len_rear  a2:wheel_len_front  b:wheel_width
    ltheta = zeros(2,4,2);
    l = zeros(4,2);
    theta = zeros(4,2);
    % 半径
    l(1,1) = -sqrt(obj.wheel_len_rear^2  + obj.wheel_width^2);
    l(2,1) =  sqrt(obj.wheel_len_front^2 + obj.wheel_width^2);
    l(3,1) = -sqrt(obj.wheel_len_rear^2  + obj.wheel_width^2);
    l(4,1) =  sqrt(obj.wheel_len_front^2 + obj.wheel_width^2);
    
    l(1,2) =  sqrt(obj.wheel_len_rear^2  + obj.wheel_width^2);
    l(2,2) =  sqrt(obj.wheel_len_front^2 + obj.wheel_width^2);
    l(3,2) =  sqrt(obj.wheel_len_rear^2  + obj.wheel_width^2);
    l(4,2) =  sqrt(obj.wheel_len_front^2 + obj.wheel_width^2);
    % 角度
    theta(1,1) =  atan(obj.wheel_len_rear / obj.wheel_width    );
    theta(2,1) =  atan(obj.wheel_width    / obj.wheel_len_front);
    theta(3,1) = -atan(obj.wheel_width    / obj.wheel_len_rear );
    theta(4,1) = -atan(obj.wheel_width    / obj.wheel_len_front);
    
    theta(1,2) =  atan(obj.wheel_len_rear / obj.wheel_width    );
    theta(2,2) =  atan(obj.wheel_width    / obj.wheel_len_front);
    theta(3,2) = -atan(obj.wheel_width    / obj.wheel_len_rear );
    theta(4,2) = -atan(obj.wheel_width    / obj.wheel_len_front);
    
    ltheta(1,:,:) = l;
    ltheta(2,:,:) = theta;
end