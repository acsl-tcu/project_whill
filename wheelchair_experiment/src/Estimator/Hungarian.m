function [assignment, unassignedTracks, unassignedDetections, newAssignIdx, overH]...
= Hungarian(X, y, limit, oldAssignIdx, limitHorizon, Pbar, R)
% Detections:観測値
% Predictions:事前推定値
    if isempty(y)
        % 検出がない場合、全トラックが未検出とみなす
        assignment = [];
        unassignedTracks = 1:size(X, 2);
        unassignedDetections = [];
        newAssignIdx = zeros(size(oldAssignIdx,1),1);
        overH = [];
        return;
    else
        detections = y';
        predictions = X(1:2,:)';
        cost = zeros(size(predictions, 1), size(detections, 1));   % コスト行列のメモリ確保
        
        % 検出にマッチする各予測のコストを計算する。コストを予測と検出間のユークリッド距離と定義
        for i = 1:size(predictions, 1)
            diff = detections - repmat(predictions(i,:),[size(detections,1),1]);
            % cost(i, :) = sqrt(sum(diff .^ 2,2));    % ユークリッド距離
            c = [1 0 0 0 0 0
                0 1 0 0 0 0];
            S = c*Pbar{i,1}*c'+R; % イノベーション共分散
            cost(i,:) =  sqrt(diag(diff / S* diff')); % マハラノビス距離
        end
        
        % 検出を予測に関連付ける
        [assignment, unassignedTracks, unassignedDetections] = ...
                assignDetectionsToTracks(cost, limit);
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % 閾値処理
        % 検出判定：検出された場合→0，検出されなかった場合→1
        % 未検出回数 = (前の時刻の未検出回数 + 1) × 現時刻の検出判定
        % _______________________
        % | 格納先ID | 未検出回数 |
        % |    1    |      0     |
        % |____:____|______:_____|
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        newAssignIdx = zeros(size(oldAssignIdx,1),1);
        newAssignIdx(unassignedTracks) = 1;
        newAssignIdx = (oldAssignIdx + 1) .* newAssignIdx;
        
        % 追跡対象の削除
        overH = find(newAssignIdx >= limitHorizon);
        if ~isempty(overH)
            newAssignIdx(overH) = 0;
        end
        if isempty(assignment)
            assignment = NaN;
        end
    end
end
