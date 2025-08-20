function trackStorage = predict_track(delta,validTrackIdx,DimSta,trackStorage,Q) %#codegen
    [~,~, B] = makeModel(delta); % ノイズ印加モデルの算出
    Xhbar = zeros(DimSta,nnz(trackStorage.Logical));
    Pbar = cell(nnz(trackStorage.Logical),1);
    Pnoise = B*Q*B';
    % Pnoise_ptCOG = B*Qp*B';
    % Difficult to change parfor due to IMM objects' properties saving
    for i = coder.unroll(1:length(validTrackIdx))
        EKF = trackStorage.tracker{validTrackIdx(i),1}; % temptracker{i}
        % プロセスノイズの更新--------------------------------------
        EKF.ProcessNoise = Pnoise; 
        % 予測ステップ----------------------------------------------
        [Xhbar(:,i), Pbar{i}] = predict(EKF, delta);
        %----------------------------------------------------------
    end

end