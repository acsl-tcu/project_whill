function [Y, inlier,SBreakFlag,MD,S_final] = pcfitellipse(points,a0,sampleSize,maxDistance,A,B,Aeq,Beq,lb,ub,Num,CNum,...
    Pbar,c,R,MD_threshold,MSANum,Xhbar,eta,Plant)%#codegen
%% MEXの中にparforを入れると爆速になる
    % points      = zeros(size(x,1),2); %点群を保存する配列の初期化
    % points(:,1) = double(x); %点群のx座標をdouble型へ
    % points(:,2) = double(y); %点群のy座標をdouble型へ

    % % 関心領域の設定,楕円にしたい
    % if cnt >= 0 % selectedCount
    %     xpoints = x(hypot(x-Xhbar(1,1),y-Xhbar(2,1)) < selectedArea);
    %     points = zeros(length(xpoints),2);
    %     points(:,1) = xpoints;
    %     points(:,2) = y(hypot(x-Xhbar(1,1),y-Xhbar(2,1)) < selectedArea);
    %     points = double(points);
    % else
    %     points      = zeros(size(x,1),2); %点群を保存する配列の初期化
    %     points(:,1) = double(x); %点群のx座標をdouble型へ
    %     points(:,2) = double(y); %点群のy座標をdouble型へ
    % end
    
    COG_init = [mean(points(:,1));mean(points(:,2))]; % 歩行者クラスタの重心
    nonlcon = @(points) limitFittingArea(points,COG_init,Plant);
    options = optimoptions('fmincon','Algorithm','sqp'); %ソルバーの設定。このままでOK
    fitEllipseFcn  = @(points) fmincon(@(a)sum(((((points(:,1)-a(1))*-sin(a(5))+(points(:,2)-a(2))*cos(a(5)))/a(3)).^2 ...
        + ((-(points(:,1)-a(1))*cos(a(5))+(points(:,2)-a(2))*-sin(a(5)))/a(4)).^2 - 1).^2+...
        exp(hypot(points(:,1),points(:,2))-hypot(a(1),a(2))),1), a0, A, ...
        B, Aeq, Beq, lb, ub,nonlcon,options); %RANSACでモデルの候補生成のための計算式。サンプリングした点群のみ使ってfminconを解く。
    evalEllipseFcn = ...   %サンプリングした点群から計算した楕円と各点群との誤差を計算する式
                    @(model, points) sum(distanceEllipse(model,points),2);
    Yhbar = c*Xhbar;
    modelCheck = @(model) validateModelFcn(model,Pbar,c,R,Yhbar,MD_threshold);

    %1st RANSAC
    %modelRANSAC:x,y,alpha,beta,theta(楕円中心,長軸,短軸,方向角),inlierIdx:各点群がInlierかどうか1,0で表示
    [modelRANSAC, inlierIdx] = ransac(points,fitEllipseFcn,evalEllipseFcn, ...
            sampleSize,maxDistance, ...
            MaxSamplingAttempts=MSANum,MaxNumTrials=Num,Confidence=CNum,ValidateModelFcn=modelCheck);
    inlier = [points(inlierIdx,1), points(inlierIdx,2)]; %外れ値でない点群を保存
    maxRatio = ub(3)/lb(4); % alpha/betaの最大比率
    minRatio = lb(3)/ub(4); % alpha/betaの最小比率
    % eta = 0.1;
    axis_threshold = (maxRatio - minRatio)*eta; % 共分散行列崩れ判定の閾値
    ratio = modelRANSAC(3)/modelRANSAC(4);
    judgeOverRatio = any([ratio < minRatio + axis_threshold, ratio > maxRatio - axis_threshold]);

    
    if judgeOverRatio % 事後誤差共分散行列を比率調整するための判定,0:異常なし，1:イノベーション共分散の崩れ発生
        SBreakFlag = 1;
    else
        SBreakFlag = 0;
    end
    %
    modelRANSAC = modelRANSAC';
    Y = [modelRANSAC(1);modelRANSAC(2);modelRANSAC(5);modelRANSAC(3);modelRANSAC(4)]; % [x,y,theta,alpha,beta]
    % obj.ellipse.Xhbar(3) = wrapTo2Pi(obj.ellipse.Xhbar(3));
    % obj.ellipse.model(3) = wrapAngle(obj.ellipse.Xhbar(3),obj.ellipse.model(3));
    S_final = c*Pbar*c'+R;
    Ytilde_final = Y - Yhbar;
    MD = sqrt(Ytilde_final'/S_final*Ytilde_final);
    
    %%%% 関数 %%%%
    function [c,ceq] = limitFittingArea(points,COG,Plant) % RANSACで制約条件の追加points(x,y,alpha,beta,theta):観測値,COG:点群重心
        % c(points) <= 0
        x = [COG(1);points(1)];
        y = [COG(2);points(2)];
        [x_local, y_local] = global_to_local(Plant,x,y,0);
        c = hypot(x_local(1),y_local(2)) - hypot(x_local(2),y_local(2));
        ceq = [];

        function [cxe, cye] = global_to_local(state, cxe_global, cye_global, SP)
            %GLOBAL_TO_LOCAL Transfer from GLOBAL to LOCAL
            % state: Ego-vehicle's position in global system coordinates X Y Theta which are
            % measured by Autoware/Gazebo.
            % cxe_global, cye_global: Obstacle's position in global system coordinates
            % SP: distance between LiDAR and vehicle, generally, zero.
            
            %%% Adjust for the sensor's offset from the plant (vehicle center) %%%
            cxe_adjusted = cxe_global + SP * cos(state.yaw);
            cye_adjusted = cye_global + SP * sin(state.yaw);
            
            % Translation vector for the ego-vehicle's position
            T_inv = [1, 0, -state.X;...
                     0, 1, -state.Y;...
                     0, 0, 1];
            
            % Rotation matrix for the ego-vehicle's orientation (inverse rotation)
            H_inv = [cos(state.yaw), sin(state.yaw), 0;...
                    -sin(state.yaw), cos(state.yaw), 0;...
                     0,              0,             1];
            
            % Combine translation and rotation to form the inverse transformation matrix
            G_inv = H_inv * T_inv;
            
            % Represent global coordinates as homogeneous coordinates
            L_global = [cxe_adjusted'; cye_adjusted'; ones(1, length(cxe_global))];
            
            % Apply the inverse transformation
            L_local = G_inv * L_global;
            
            % Extract local coordinates
            cxe = L_local(1, :)';
            cye = L_local(2, :)';
        end
    end
    function  distance = distanceEllipse(p,points) %サンプリングした点群から計算した楕円と各点群との誤差を計算
        x1        = points(:,1); %点群のx座標を代入
        y1        = points(:,2); %点群のy座標を代入
        %以下で誤差を計算. pにはRANSACで計算されたx,y,alpha,beta,thetaがベクトルで入っている。
        distance = ((((x1 - p(1)) * -sin(p(5)) + (y1 - p(2)) * cos(p(5)))/p(3)).^2 + ((-(x1 - p(1)) * cos(p(5)) + (y1 - p(2)) * -sin(p(5)))/p(4)).^2 -1).^2;
    end 
    function isValid = validateModelFcn(model,Pbar,c,R,Yhbar,MD_threshold) % weightも入ってた
        S = c*Pbar*c'+R; %イノベーション共分散行列
        obsM = [model(1);model(2);model(5);model(3);model(4)]; % 観測値
        Ytilde = obsM - Yhbar; % 観測予測誤差
        MahalDist = sqrt(Ytilde'/S*Ytilde);
        isValid = MahalDist < MD_threshold; % MahalDist:(x y theta alpha beta)の順 
    end
end 