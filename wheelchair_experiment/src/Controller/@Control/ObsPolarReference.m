function [r ,thd] = ObsPolarReference(obj)
    
    centerx = 15.5;
    centery = 0;
    x   = obj.ObstaclePosX - centerx;
    y   = obj.ObstaclePosY - centery;
    phi = atan2( y , x );
    r   = sqrt( x^2 + y^2 );
    
    obj.obsf1 = obj.InitialVelocity(1,1) / ( obj.obsrd * obj.obsrd ) - ( obj.obsrwn * obj.obsrwn ) / obj.InitialVelocity(1,1);
    obj.obsf2 = 2 * obj.obsz * obj.obsrwn;
    
    %Adjust declination (correct the range of atan2)
    while phi > obj.ObstaclePosYAW + pi
        phi = phi - 2 * pi;
    end
    while phi < obj.ObstaclePosYAW - pi
        phi = phi + 2 * pi;
    end
            
    %Vehicle target position, angle
%     xd = obj.rd * cos(phi);
% 	yd = obj.rd * sin(phi);
    thd= phi + 0.8 * pi;
    
end

