% function [Grade] = FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM)
function [Grade,phi_o,phi_o_l,phi_o_r,grade_trgt,grade_obs] = FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM)  % テスト用
% function [Grade,phi_o,phi_Q1,phi_Q2,grade_trgt,grade_obs] = FPM_capsule_v3_1(obj,x,y,th,obs_now,target,param_FPM)  % テスト用
% ベクトルで計算
% インデックスで計算
% 「 _2 」がつく変数は車両座標系

    %--パラメータ--------------------------------------
    eta         = param_FPM.eta;                % PMF for the goalの最小値と最大値の比率
    alpha       = param_FPM.alpha;              % PMF for the Obstacle の障害物を考慮する距離
    ds          = param_FPM.margin;             % PMF for the Obstacle の障害物のマージン
    obs_cost    = param_FPM.obs_cost;           % 障害物に接触する場合のコスト
    %-------------------------------------------------

    %--組み込み用--------------------------------------
    Po          = [x y];                        % 車椅子の位置
    a_wheel     = obj.wheel_width;              % 車椅子の横幅
    b_wheel     = obj.wheel_len_front;          % 車椅子の縦幅
    r_wheel     = norm([a_wheel b_wheel]);      % 車椅子の回転中心から角の距離
     %-----------------------------------------------
    obsnum      = obj.ObsNum;                   % 歩行者の数
    Qo          = obs_now(:,1:2);               % 歩行者の位置
    a_obs       = obs_now(:,5);                 % 歩行者の横幅
    b_obs       = obs_now(:,6);                 % 歩行者の縦幅
    tho         = obs_now(:,3);                 % 歩行者が向いている方向
     %-----------------------------------------------
    goal        = target;                       % 目標位置
    %-----------------------------------------------
    
    
    grade_obs   = ones(max(obsnum,1),1);           % 障害物のPFM      

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   
%--PMF of Goal (begin)-----------------------------------------------------
    g_a = 1.0;      % PMF for the goal の最大値
    g_b = eta*g_a;  % PMF for the goal の最小値
    
    phig        = atan2((goal(1,2) - y),(goal(1,1) - x)) - th;      % 車椅子から見たgoal がある方向
    phaierror   = atan2(sin(phig - 0),cos(phig - 0));
    grade_trgt  = -((g_a - g_b)/pi)*abs(phaierror) + g_a;           % PMF of Goal
%--PMF of Goal (end)-------------------------------------------------------
%--PFM of Obstacle (begin)-------------------------------------------------
    % Po 車両中心
    % Qo 歩行者中心
    % Q1 歩行者端円中心1
    % Q2 歩行者端円中心2

    if obsnum>0
        % ---事前初期化------------------
        phi_o       = zeros(obsnum,1);
        phi_Q1      = zeros(obsnum,1);
        phi_Q2      = zeros(obsnum,1);
        phi_Q1_l    = zeros(obsnum,1);
        phi_Q1_r    = zeros(obsnum,1);
        phi_Q2_l    = zeros(obsnum,1);
        phi_Q2_r    = zeros(obsnum,1);
        phi_o_l     = zeros(obsnum,1);
        phi_o_r     = zeros(obsnum,1);
        PoQo        = zeros(obsnum,1);
        PoQ1        = zeros(obsnum,1);
        PoQ2        = zeros(obsnum,1);
        z1          = zeros(obsnum,1);
        z2          = zeros(obsnum,1);
        z3          = zeros(obsnum,1);
        z4          = zeros(obsnum,1);
        z5          = zeros(obsnum,1);
        mark        = zeros(obsnum,1);
        %-------------------------------
        D = a_wheel+b_obs + ds;
    
        Q1 =  [-sin(tho),cos(tho)].* [a_obs,a_obs] + Qo;
        Q2 =  [-sin(tho),cos(tho)].*-[a_obs,a_obs] + Qo;
    
        phiQo_global = atan2(Qo(:,2)-Po(2), Qo(:,1)-Po(1));
        phiQo = atan2(sin(phiQo_global-th), cos(phiQo_global-th));      % 車両から見た歩行者が存在する方向
        % ---PoとQ1Q2の距離PoQ3とphi_Q3を計算------------------------------
        R = [cos(-th) -sin(-th);sin(-th) cos(-th)];
        Q1_2 = (R*(Q1-Po)')';                       % 車両から見たQ1の位置
        Q2_2 = (R*(Q2-Po)')';                       % 車両から見たQ2の位置
        
        v = Q2_2 - Q1_2;                            % ベクトル Q1 → Q2
        t = -dot(Q1_2, v, 2) ./ dot(v, v, 2);       % 内積を使って係数 t を計算
        t = max(0, min(1, t));                      % t を 0 ≤ t ≤ 1 に制限
    
        Q1Q2_2 = Q1_2 + t .* v;                     % 交点の座標
        PoQ3 = vecnorm(Q1Q2_2, 2, 2);               % 原点からの最短距離
        phi_Q3 =atan2(Q1Q2_2(:,2),Q1Q2_2(:,1));     % 車両から見た交点のある方向
        % ----------------------------------------------------------------
        idx = PoQ3 > D; 
        % --- 重なっていない場合--------------------------------------------
        phi_o(idx,1)     = phiQo(idx,1);
        PoQo(idx,1)     = vecnorm(Qo(idx,:)-Po,2,2);
        PoQ1(idx,1)     = vecnorm(Q1(idx,:)-Po,2,2);
        PoQ2(idx,1)     = vecnorm(Q2(idx,:)-Po,2,2);
        
        mark(idx,1) = sign(cos(phiQo(idx,:)-tho(idx,:)+th));
        z1(idx,1) = max(-1, min(1,(PoQo(idx,:).^2+PoQ1(idx,:).^2-a_obs(idx,:).^2)./(2.*PoQo(idx,:).*PoQ1(idx,:))));
        z2(idx,1) = max(-1, min(1,(PoQo(idx,:).^2+PoQ2(idx,:).^2-a_obs(idx,:).^2)./(2.*PoQo(idx,:).*PoQ2(idx,:))));
        phi_Q1(idx,1)   =  mark(idx,1).*acos(z1(idx,1));
        phi_Q2(idx,1)   = -mark(idx,1).*acos(z2(idx,1));
    
        z3(idx,1) = max(-1,min(D(idx,:) ./ PoQ1(idx,:),1));
        z4(idx,1) = max(-1,min(D(idx,:) ./ PoQ2(idx,:),1));
        phi_Q1_l(idx,:) = phi_Q1(idx,:)+asin(z3(idx,1));
        phi_Q1_r(idx,:) = phi_Q1(idx,:)-asin(z3(idx,1));
        phi_Q2_l(idx,:) = phi_Q2(idx,:)+asin(z4(idx,1));
        phi_Q2_r(idx,:) = phi_Q2(idx,:)-asin(z4(idx,1));
    
        phi_o_l(idx,:)  = max([phi_Q1_l(idx,:), phi_Q2_l(idx,:)], [], 2);
        phi_o_r(idx,:)  = min([phi_Q1_r(idx,:), phi_Q2_r(idx,:)], [], 2);
        % -----------------------------------------------------------------
        % ---重なっている場合------------------------------------------------
        phi_o(~idx,1)    = phi_Q3(~idx,1);
        z5(~idx,1) = max(-1,min(PoQ3(~idx,:)./D(~idx,:),1));
        phi_o_l(~idx,:) =  (pi-asin(z5(~idx,1)));
        phi_o_r(~idx,:) = -phi_o_l(~idx,:);
        % -----------------------------------------------------------------
        phi_o = atan2(sin(phi_o),cos(phi_o));
        % ---障害物のある方向のPMFを下げる------------------------------------
        idx2 = phi_o+phi_o_l>=0 & phi_o+phi_o_r<0 & PoQ3 < alpha;
        grade_obs(idx2,1) =  1-exp(-(PoQ3(idx2,1)-b_obs(idx2,1)-r_wheel)/1);
        % grade_obs(idx2,1) = 1-(alpha-PoQ3(idx2,1))./(alpha-(b_obs(idx2,1) + ds + r_wheel));
        % -----------------------------------------------------------------
        % ---障害物のコストを計算--------------------------------------------
        idx3 = idx2 & PoQ3 - b_obs - ds -r_wheel <= 0;
        grade_obs(idx3,1) = grade_obs(idx3,1)-obs_cost;
        % -----------------------------------------------------------------
    else
        phi_o  =double([]);
        phi_o_l=double([]);
        phi_o_r=double([]);
    end
%--PFM of Obstacle (end)---------------------------------------------------
%--最終的なPMF--------------------------------------------------------------
    Grade = min(grade_trgt,min(grade_obs));
%--------------------------------------------------------------------------