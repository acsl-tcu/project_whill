function [isObserved,model1] = calc_observation(RANSAC,numAssignments, ...
    assignment,Xhbar_observed_ellipse,Pbar_observed_ellipse,ObsptClouds,doRANSAC,R,Xhbar_observed,trans,Plant) %#codegen
    %% MEX & 並列化用の変数作成
    % 各モデルの観測値の構造体
    max_inlierpoint = 2000;
    model1 = repmat(struct('model',zeros(5,1),'inlierpoints',zeros(max_inlierpoint,2),'ModelType',0),numAssignments,1); % Ellipse model
    % 観測判定
    isObserved1 = zeros(numAssignments,1); % Ellipse model
    % ransacに使う変数を構造体から解体
    sampleSize = RANSAC.sampleSize;
    maxDistance = RANSAC.maxDistance;
    TrialNum = RANSAC.TrialNum;
    confDegree = RANSAC.confDegree;
    A = RANSAC.A;
    B = RANSAC.B;
    Aeq = RANSAC.Aeq;
    Beq = RANSAC.Beq;
    tth = RANSAC.tth;
    MD_threshold = RANSAC.MD_threshold;
    MSANum = RANSAC.MSANum;
    selectedArea = RANSAC.selectedArea;
    eta = RANSAC.eta;
    %% 観測値の計算
    parfor i = 1:size(assignment,1)
    % for i = 1:size(assignment,1)
        detectionIdx = assignment(i,2);
        meas = pointCloud(ObsptClouds(1:3,ObsptClouds(4,:)==detectionIdx)'); % 対応付けインデックスと障害物点群ラベルが対応する点群を取得
        
        % Ellipse model
        % ptPedestrian = removeleg(meas.Location,trans); % RANSAC精度悪化防止のため脚点群除去
        r_removelegCluster = trans(3)/tand(15); % LiDARの高さ/LiDARの垂直視野角15度
        if norm(mean(meas.Location, 1) - trans(1:2)') >= r_removelegCluster % 3 [m]
            % 体の45%が脚，上10cmが頭としてそれらを除去
            ptPedestrian = meas.Location((meas.Location(:,3) > max(meas.Location(:,3))*0.45) & meas.Location(:,3) < max(meas.Location(:,3))-0.1,:);
        else
            ptPedestrian = meas.Location;
        end
        % 予測値周辺の点群でRANSACを実行するため，点群を条件に従って抽出
        distances = hypot(ptPedestrian(:,1) - Xhbar_observed_ellipse(1,i), ptPedestrian(:,2) - Xhbar_observed_ellipse(2,i));
        idx = distances < selectedArea; % 指定半径内に存在する点群のインデックス
        points = double([ptPedestrian(idx,1), ptPedestrian(idx,2)]); % RANSACに入力する点群
        if all([size(points,1) >= doRANSAC, meas.Count > doRANSAC]) % 点群が十分に得られる場合に実行
            isObserved1(i) = 1;
            %RANSACの初期値には事前推定値(x,y,alpha,beta,theta)
            aaa = Xhbar_observed_ellipse(:,i); % 事前推定値
            a0 = double([aaa(1),aaa(2),aaa(5),aaa(6),aaa(3)]);
            lb = double([-Inf,-Inf,0.1,0.05,a0(5)-tth]); % 下限制約(x,y,alpha,beta,theta)
            ub = double([Inf,Inf,0.2,0.1,a0(5)+tth]);   % 上限制約(x,y,alpha,beta,theta)
                c = [1 0 0 0 0 0
                     0 1 0 0 0 0
                     0 0 1 0 0 0
                     0 0 0 0 1 0
                     0 0 0 0 0 1];
            % 課題：モデル適合度が不足 (初期値の割り当ては前時刻で重心モデル回すor観測値テンプレから評価値高を選択)
            [model1(i).model, inlierpoints,~,~,~] = pcfitellipse(points,a0,sampleSize,maxDistance, ...
                A,B,Aeq,Beq,lb,ub,TrialNum,confDegree,Pbar_observed_ellipse{i,1},c,R,MD_threshold,MSANum, ...
                Xhbar_observed_ellipse(:,i),eta,Plant);
            % 可変のインライアを割り当てるためにこねこねする(＠ω＠)
            n = size(inlierpoints, 1);
            inlierpoints_full = zeros(max_inlierpoint, 2); % インライアが2000個以下と仮定
            if n > 0
                inlierpoints_full(1:n, :) = inlierpoints;
            end
            model1(i).inlierpoints = inlierpoints_full;
            model1(i).ModelType = 1;
        else
            isObserved1(i) = 0;
            [cog,~] = pcfitptCOG(meas,Xhbar_observed(:,i));
            model1(i).model = [cog; nan(3,1)];
            model1(i).inlierpoints = zeros(max_inlierpoint,2);
            model1(i).ModelType = 2; % COGモデルを使用
        end
        %--------------------------------------------------------------------------

    end
    isObserved = [isObserved1];
end