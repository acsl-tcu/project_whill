function [Grade,Grade_old] = FPM_4_goal(obj,x,y,th,obs,obs_now,target,prob)
    obsnum = obj.ObsNum;
    goal = target;
	r_wheel = obj.r_wheel;
	r_obs = obj.r_obs;
	g_a = 1.0;
    eta = 0.3;
    g_b = eta*g_a;
    alpha = 8;
    distance_obs = zeros(obsnum,1);
    tho = zeros(obsnum,1);
    PoQo = zeros(obsnum,1);
    phaiR = zeros(obsnum,1);
    a = zeros(obsnum,1);
    grade_obs = ones(obsnum,1);
    th_max = zeros(obsnum,1);
    th_min = zeros(obsnum,1);
    OBS_NOW = obs_now;
%     OBS_NOW = cell2mat(obs_now);
    OBS = obs;
%     OBS = cell2mat(obs);
    state = [x y]; % サンプルにおける車両の位置

    thg = atan2((goal(1,2) - y),(goal(1,1) - x)) - th; % 自車両(sample)の角度と目標角度の誤差


    % phaierror = atan2(sin(thg - 0),cos(thg - 0));
    % grade_trgt = -((g_a - g_b)/pi)*abs(phaierror) + g_a;

    grade_trgt = ((g_a-g_b)/pi)*(pi-abs(thg))+g_b;

    Grade_old = grade_trgt; % 目標角度のグレードと障害物グレードのなかで最低グレードを取得
    Grade = -10;
end