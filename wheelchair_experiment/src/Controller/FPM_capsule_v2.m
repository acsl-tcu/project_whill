function [Grade,Grade_old] = FPM_capsule_v2(obj,x,y,th,obs_now,target)
% function [Grade,Grade_old,phio_min,phio_max,grade_trgt,grade_obs,d_c1c2] = FPM_capsule_v2(a_wheel,b_wheel,a_obs,b_obs,obsnum,x,y,th,OBS_NOW,tho,goal)  % テスト用
    

    %--テスト用--------------------------------------
    % state = [x y];      % 車椅子の位置
    % a_wheel           % 車椅子の横幅
    % b_wheel           % 車椅子の縦幅
    % goal              % 目標位置
    % obsnum            % 障害物の数
    % OBS_NOW           % 障害物の位置
    % a_obs             % 歩行者の横幅
    % b_obs             % 歩行者の縦幅
    % tho               % 歩行者が向いている方向
    %-----------------------------------------------


    %--組み込み用--------------------------------------
    state = [x y];              % 車椅子の位置
    a_wheel = obj.wheel_wide;        % 車椅子の横幅
    b_wheel = obj.wheel_len_front;              % 車椅子の縦幅
    goal = target;              % 目標位置
    obsnum = obj.ObsNum;        % 障害物の数
    OBS_NOW = obs_now(:,1:2);          % 障害物の位置
    %-----------------------------------------------

    
    %--未完成用------------------------------
    % a_obs = obj.r_obs;          % 歩行者の横幅
    % b_obs = (obj.r_obs)*0.4;    % 歩行者の縦幅
    % tho = zeros(obsnum,1);      % 歩行者が向いている方向
    %---------------------------------------


    %--完成用--------------------------------
    a_obs = obs_now(:,6);       % 歩行者の横幅
    b_obs = obs_now(:,7)+0.15;       % 歩行者の縦幅
    % b_obs = obs_now(:,4)+0.1;
    tho   = obs_now(:,8);       % 歩行者が向いている方向
    %---------------------------------------

    %--パラメータ----------------------------
    eta = 0.2;     % PMF for the goalの最小値と最大値の比率
    alpha = 10;    % PMF for the Obstacle の障害物を考慮する距離
    %---------------------------------------

    d_o = zeros(obsnum,1);          % 車両と障害物の距離
    phio_max = zeros(obsnum,1);
    phio_min = zeros(obsnum,1);
    % a = zeros(obsnum,1);            
    grade_obs = ones(obsnum,1);     % 障害物のFPM      
    OBS_NOW_2 = zeros(obsnum,2);    % 障害物の位置 (車両位置が原点，車両の方向角がx軸正)
    % phio_2 = zeros(obsnum,1);       % 障害物がある方向 (車両位置が原点，車両の方向角がx軸正)
    closest_point = zeros(obsnum,2);
    d_c1c2 = zeros(obsnum,1); 
    obs_r = zeros(obsnum,1);
    phi_c3_max = zeros(obsnum,1);
    phi_c3_min = zeros(obsnum,1);
    % OBS = obs;?????????

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   
%--PMF of Goal (begin)-----------------------------------------------------
    
    g_a = 1.0;      % PMF for the goal の最大値
    g_b = eta*g_a; % PMF for the goal の最小値
    
    phig = atan2((goal(1,2) - y),(goal(1,1) - x)) - th;     % 車椅子から見たgoal がある方向
    %--三角波ver.--------------------------------------------------------------
    phaierror = atan2(sin(phig - 0),cos(phig - 0));
    grade_trgt = -((g_a - g_b)/pi)*abs(phaierror) + g_a;    % PMF of Goal
    
    %--特殊カーブver.----------------------------------------------------------
    % phia = 0.7390851512278;
    % grade_trgt = (1-g_b)/2*cos(0-phia-phig+cos(cos(0-phia-phig)))+(g_b+1)/2;


%--PMF of Goal (end)-------------------------------------------------------

%--PFM of Obstacle (begin)-------------------------------------------------

    R = [cos(-th), -sin(-th); sin(-th), cos(-th)];          % 回転行列
    for i = 1:obsnum
        OBS_NOW_2(i,:) = (R*[OBS_NOW(i,1)-state(1);OBS_NOW(i,2)-state(2)])';    % 障害物の位置 (車両位置が原点，車両の方向角がx軸正)
        d_o(i,1) = norm(OBS_NOW_2(i,:));                                             % 車両と障害物の距離
    end

    phio_2 = atan2(OBS_NOW_2(:,2),OBS_NOW_2(:,1));     % 障害物がある方向 (車両位置が原点，車両の方向角がx軸正)
    
    tho_2 = tho-th;
    tho_3 = tho_2-phio_2;
    
    for i = 1:obsnum
        % obs_r(i) = sqrt(a_obs(i)^2+b_obs(i)^2)+0.15;
        obs_r(i) = 0.6;
        if d_o(i) >= a_wheel+obs_r(i)
            phi_c3_max(i) = phio_2(i)+(asin((a_wheel+obs_r(i)/d_o(i))));
            phi_c3_min(i) = phio_2(i)-(asin((a_wheel+obs_r(i)/d_o(i))));
        else
            phi_c3_max(i) = phio_2(i)+(pi-asin(d_o(i)/(a_wheel+obs_r(i))));
            phi_c3_min(i) = phio_2(i)-(pi-asin(d_o(i)/(a_wheel+obs_r(i))));
        end
    end

    % c1 = [OBS_NOW(:,1) + a_obs * cos(tho(:,1)-1/2*pi), OBS_NOW(:,2) + a_obs * sin(tho(:,1)-1/2*pi)];               % 障害物の円1の位置
    % c2 = [OBS_NOW(:,1) - a_obs * cos(tho(:,1)-1/2*pi), OBS_NOW(:,2) - a_obs * sin(tho(:,1)-1/2*pi)];               % 障害物の円2の位置
    % 
    c1_2 = [OBS_NOW_2(:,1) + a_obs .* cos(tho_2-1/2*pi), OBS_NOW_2(:,2) + a_obs .* sin(tho_2(:,1)-1/2*pi)];    % 障害物の円1の位置 (車両位置が原点，車両の方向角がx軸正)
    c2_2 = [OBS_NOW_2(:,1) - a_obs .* cos(tho_2-1/2*pi), OBS_NOW_2(:,2) - a_obs .* sin(tho_2(:,1)-1/2*pi)];    % 障害物の円2の位置 (車両位置が原点，車両の方向角がx軸正)

    c1_3 = [d_o + a_obs .* cos(tho_3-1/2*pi),  a_obs .* sin(tho_3-1/2*pi)];                          % 円1の位置 (車両位置が原点，車両から障害物へ向かってx軸正)
    c2_3 = [d_o - a_obs .* cos(tho_3-1/2*pi), -a_obs .* sin(tho_3-1/2*pi)];                          % 円2の位置 (車両位置が原点，車両から障害物へ向かってx軸正)

    phi_c1 = atan2(c1_3(:,2), c1_3(:,1));           % [車両と障害物を結ぶ線] と [車両と円c1を結ぶ線]のなす角
    phi_c2 = atan2(c2_3(:,2), c2_3(:,1));           % [車両と障害物を結ぶ線] と [車両と円c2を結ぶ線]のなす角

    d_c1 = sqrt(c1_3(:,1).^2 + c1_3(:,2).^2);       % 車両と円1との距離
    d_c2 = sqrt(c2_3(:,1).^2 + c2_3(:,2).^2);       % 車両と円2との距離
    % ノルム
    
    %--c1,c2を結ぶ線分と車椅子との距離 (begin)-----------------------------
    % % for i = 1:obsnum
    % %     dx(i,1) = c2_2(i,1) - c1_2(i,1);
    % %     dy(i,1) = c2_2(i,2) - c1_2(i,2);
    % % 
    % %     % Parameter t for the projection of the origin onto the line segment
    % %     t(i,1) = -(c1_2(i,1) * dx(i,1) + c1_2(i,2) * dy(i,1)) / (dx(i,1)^2 + dy(i,1)^2);
    % % end
    % % Vector from (x1, y1) to (x2, y2)
    % dx = c2_2(:,1) - c1_2(:,1);
    % dy = c2_2(:,2) - c1_2(:,2);
    % 
    % % Parameter t for the projection of the origin onto the line segment
    % t = -(c1_2(:,1) .* dx + c1_2(:,2) .* dy) / (dx.^2 + dy.^2);
    % for i = 1:obsnum
    %     if t(i,1) < 0
    %         % Closest point is c1
    %         closest_point(i,:) = [c1_2(i,1), c1_2(i,2)];
    %     elseif t(i,1) > 1
    %         % Closest point is c2
    %         closest_point(i,:) = [c2_2(i,1), c2_2(i,2)];
    %     else
    %         % Closest point is on the segment
    %         closest_point(i,:) = [c1_2(i,1) + t(i,1) * dx(i,1), c1_2(i,2) + t(i,1) * dy(i,1)];
    %     end
    %     d_c1c2(i,1) = norm(closest_point(i,:));
    % end
    
    for i = 1:obsnum
        [d_c1c2(i,1), closest_point(i,:)] = distance_to_origin(c1_2(i,1), c1_2(i,2), c2_2(i,1), c2_2(i,2));
    end

    %--c1,c2を結ぶ線分と車椅子との距離 (end)-------------------------------

    for i = 1:obsnum
        if d_c1c2(i,1) >= a_wheel+b_obs(i,1)    % 通常(車両と障害物が重なっていない場合)
            phi_c1_max = phi_c1(i,1) + asin((b_obs(i,1) + a_wheel) / d_c1(i,1));    % [車両と障害物を結ぶ線] と [車両と円1の接線1] のなす角
            phi_c1_min = phi_c1(i,1) - asin((b_obs(i,1) + a_wheel) / d_c1(i,1));    % [車両と障害物を結ぶ線] と [車両と円1の接線2] のなす角
            phi_c2_max = phi_c2(i,1) + asin((b_obs(i,1) + a_wheel) / d_c2(i,1));    % [車両と障害物を結ぶ線] と [車両と円2の接線1] のなす角
            phi_c2_min = phi_c2(i,1) - asin((b_obs(i,1) + a_wheel) / d_c2(i,1));    % [車両と障害物を結ぶ線] と [車両と円2の接線2] のなす角
    
            phio_max(i,1) = phio_2(i,1) + max(phi_c1_max, phi_c2_max);              % [車両の進行方向] と [車両と障害物の接線(プラス側)] のなす角
            phio_min(i,1) = phio_2(i,1) + min(phi_c1_min, phi_c2_min);              % [車両の進行方向] と [車両と障害物の接線(マイナス側)] のなす角
        
        else                                    % 例外(車両と障害物が重なっている場合)
            phio_2(i,1) = atan2(closest_point(i,2),closest_point(i,1));
            phio_max(i,1) = phio_2(i,1) + (pi-asin(d_c1c2(i,1)/(a_wheel+b_obs(i,1))));
            phio_min(i,1) = phio_2(i,1) - (pi-asin(d_c1c2(i,1)/(a_wheel+b_obs(i,1))));
        end
    end
    

    % for i = 1:obsnum
    %     if d_c1c2(i,1) < a_wheel+b_obs(i,1)
    %         if (phio_min(i,1) <= 0) && (0 <= phio_max(i,1))
    %             phio_max(i,1) = phio_2(i,1) + (pi-asin(d_c1c2(i,1)/(a_wheel+b_obs(i,1))))
    %             phio_min(i,1) = phio_2(i,1) - (pi-asin(d_c1c2(i,1)/(a_wheel+b_obs(i,1))))
    %             disp("pass");
    %         else
    %             disp("No");
    %             i
    %         end
    %     end
    % end

    for i = 1:obsnum
        if d_o(i,1) < alpha     % alpha よりも障害物が遠い場合
            if (phio_min(i,1) <= 0) && (0 <= phio_max(i,1))
                grade_obs_min = 1-exp(-(d_c1c2(i,1)-b_obs(i,1)-0.76)/2);
                d_th = abs(phio_2(i));
                % grade_obs(i,1) = grade_obs_min+d_th*tan(1/30*pi);
                grade_obs(i,1) = grade_obs_min;
                if d_c1c2(i,1)-b_obs(i,1)-0.76 <=0
                    grade_obs(i,1) = -20;
                end
            elseif (phi_c3_min(i,1) <=0) && (0 <= phi_c3_max(i,1))
                grade_obs_min = 1-1/4*exp(-(d_c1c2(i,1)-b_obs(i,1)-b_wheel)/1);
                 if grade_obs_min(i,1) < 0
                    grade_obs_min(i,1) = 0;
                end
                d_th = abs(phio_2(i));
                % grade_obs(i,1) = grade_obs_min+d_th*tan(1/30*pi);
                grade_obs(i,1) = grade_obs_min;
            end
        end
        % FPMの最小値は0
        % if grade_obs(i,1) < 0
        %     grade_obs(i,1) = 0;
        % end
    end

%--PFM of Obstacle (end)---------------------------------------------------

%--最終的なPMF-------------------------------------------------------------
    Grade_old = min(grade_trgt,min(grade_obs));
%--------------------------------------------------------------------------
    Grade = -10;


    function [distance, closest_point] = distance_to_origin(x1, y1, x2, y2)
        % Function to find the distance from a line segment to the origin and
        % the closest point on the segment to the origin.
        %
        % Inputs:
        %   (x1, y1) - coordinates of the first point of the segment
        %   (x2, y2) - coordinates of the second point of the segment
        %
        % Outputs:
        %   distance - minimum distance from the origin to the line segment
        %   closest_point - coordinates of the closest point on the segment to the origin
    
        % Vector from (x1, y1) to (x2, y2)
        dx = x2 - x1;
        dy = y2 - y1;
    
        % Parameter t for the projection of the origin onto the line segment
        t = -(x1 * dx + y1 * dy) / (dx^2 + dy^2);
    
        if t < 0
            % Closest point is (x1, y1)
            closest_point = [x1, y1];
        elseif t > 1
            % Closest point is (x2, y2)
            closest_point = [x2, y2];
        else
            % Closest point is on the segment
            closest_point = [x1 + t * dx, y1 + t * dy];
        end
    
        % Distance from the origin to the closest point
        distance = norm(closest_point);
    
    end
end