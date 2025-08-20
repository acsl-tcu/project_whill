function [Yd,Thd] = ObsReference(obj)
%% feedback gain
			obj.obsk1 = obj.obswn * obj.obswn;
            obj.obsk2 = 2 * obj.obswn * obj.obsz;
%% cartesian 
    if  obj.ObstaclePosX <= 86 && obj.ObstaclePosX >= -7
        if  obj.ObstaclePosY < 1.25 && obj.ObstaclePosY > 0.85
            Yd = 0.9;
		elseif  obj.ObstaclePosY <= 0.85 && obj.ObstaclePosY > 0.75
			Yd = 0.8;
		elseif  obj.ObstaclePosY <= 0.75 && obj.ObstaclePosY > 0.65
			Yd = 0.7;
		elseif  obj.ObstaclePosY <= 0.65 && obj.ObstaclePosY > 0.55
			Yd = 0.6;
		elseif  obj.ObstaclePosY <= 0.55 && obj.ObstaclePosY > 0.45
			Yd = 0.5;
		elseif  obj.ObstaclePosY <= 0.45 && obj.ObstaclePosY > 0.35
			Yd = 0.4;
		elseif  obj.ObstaclePosY <= 0.35 && obj.ObstaclePosY > 0.25
			Yd = 0.3;
		elseif  obj.ObstaclePosY <= 0.25 && obj.ObstaclePosY > 0.15
			Yd = 0.2;
		elseif  obj.ObstaclePosY <= 0.15 && obj.ObstaclePosY > 0.05
			Yd = 0.1;
		elseif  obj.ObstaclePosY <= 0.05 && obj.ObstaclePosY >= -0.05
			Yd = 0;
		elseif  obj.ObstaclePosY < 0.05 && obj.ObstaclePosY >= -0.15
			Yd = -0.1;
		elseif  obj.ObstaclePosY < -0.15 && obj.ObstaclePosY >= -0.25
			Yd = -0.2;
		elseif  obj.ObstaclePosY < -0.25 && obj.ObstaclePosY >= -0.35
			Yd = -0.3;
		elseif  obj.ObstaclePosY < -0.35 && obj.ObstaclePosY >= -0.45
			Yd = -0.4;
		elseif  obj.ObstaclePosY < -0.45 && obj.ObstaclePosY >= -0.55
			Yd = -0.5;
		elseif  obj.ObstaclePosY < -0.55 && obj.ObstaclePosY >= -0.65
			Yd = -0.6;
		elseif  obj.ObstaclePosY < -0.65 && obj.ObstaclePosY >= -0.75
			Yd = -0.7;
		elseif  obj.ObstaclePosY < -0.75 && obj.ObstaclePosY >= -0.85
			Yd = -0.8;
		elseif  obj.ObstaclePosY < -0.85 && obj.ObstaclePosY > -1.25
			Yd = -0.9;
        end
   end
    
    if obj.ObstaclePosYAW > 0
        Thd = 3.14;
    else
        Thd = -3.14;
    end
    
%% reference Yd when moving obstacle avoids moving obstacles

%     if  obj.ObstaclePosX <= 22 && obj.ObstaclePosX >= 15
%         Yd = -0.1;
%     else
%         Yd = -0.6;
%     end
% 
%     if obj.ObstaclePosYAW > 0
%         Thd = 3.14;
%     else
%         Thd = -3.14;
%     end
   
%% Reference when an obstacle advances diagonally

%     Yd = -0.5 * obj.ObstaclePosX + 14.3;
%     if obj.ObstaclePosX <= 27
%         Yd = 0.8;
%     end
% 
% % YAW calculate
% 
%     if obj.ObstaclePosYAW > 0
%         Thd = 3.14;
%     else
%         Thd = -3.14;
%     end
    
%% U turn
% 
%     if  obj.obstaclesection == 1
%         Yd = 0.5;
%     elseif obj.obstaclesection == 3
%         Yd = -0.5;
%     end
%     
% % YAW calculate
%     
%     if  obj.obstaclesection == 1
%         if obj.ObstaclePosYAW > 0
%             Thd = 3.14;
%         else
%             Thd = -3.14;
%         end
%     elseif obj.obstaclesection == 3
%          Thd = 0;
%     end

%% hukusuu
% 
% if obj.obsL==1
%     
%     Yd = 0.3;
% 
%     if obj.ObstaclePosYAW > 0
%         Thd = 3.14;
%     else
%         Thd = -3.14;
%     end
%     
% elseif obj.obsL==2
%     
%     Yd = 0.7;
%     Thd = 0;
%     
% elseif obj.obsL==3
%     
%     Yd = 0.1;
%     Thd = 0;
%     
% elseif obj.obsL==4
%     
%     if  obj.ObstaclePosX <= 17 && obj.ObstaclePosX >= 12
%         Yd = -0.2;
%     else
%         Yd = -0.8;
%     end
% 
%     if obj.ObstaclePosYAW > 0
%         Thd = 3.14;
%     else
%         Thd = -3.14;
%     end
%     
% elseif obj.obsL==5
%     
%     if  obj.ObstaclePosX <= 19 && obj.ObstaclePosX >= 9
%         Yd = -0.1;
%     else
%         Yd = -0.7;
%     end
% 
%     Thd = 0;
%     
% end

end
