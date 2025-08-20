function [assignment,trackStorage,Xhbar_observed,validTrackIdx,ObsptClouds,assignedStatesIdx] = associate_track(zk,lim, ...
    limitH,R_ptCOG,trackStorage,validTrackIdx,labelLocation)
    %% ハンガリアン法
    % 入力------------------------------------
    % trackStorage.Logical:各トラックの有効性
    % validTrackIdx:有効トラックのインデックス取得
    % xhat:事後推定値
    % zk:検出値
    % pms.lim:割り当て時のコスト（距離）の閾値
    % pms.limitH:トラックが削除されるまでの未検出許容回数
    %-----------------------------------------
    % 出力------------------------------------
    % assignment:トラックと検出値の割り当て結果（ペアのインデックス）
    % unassignedDetections:割り当てられなかった検出のインデックス
    % checkAssign(ptlStorage.Logical):検出された未検出回数
    % deleteIdx:削除されたトラックのインデックス
    %-----------------------------------------
    % pms.lim = 5;
    % pms.limitH = 10;
    % 二項分布と正規分布の関係から閾値を導出可能
    [assignment, unassignedTracks, unassignedDetections, ~, deleteIdx] = ...
            Hungarian(trackStorage.States(:,validTrackIdx),zk,lim, trackStorage.CheckAssign(validTrackIdx), ...
            limitH, trackStorage.P(validTrackIdx,1), R_ptCOG);
    %----------------------------------------------------------

    % 割り当てられたトラックのインデックス
    if any([isnan(sum(assignment,'all')), isempty(assignment)])
        assignedStatesIdx = [];
        Xhbar_observed = [];
    else
        assignedStatesIdx = validTrackIdx(assignment(:,1));
        Xhbar_observed = trackStorage.States(:, assignedStatesIdx); % トラックの対応付け．ここに対応付けできた事前推定値が格納される．
        % Pbar_observed = trackStorage.P(assignedStatesIdx,1);
    end
    
    
    % 未検出回数の更新
    if all([~isempty(assignment) ,~isnan(sum(assignment,'all'))])
        trackStorage.CheckAssign(assignedStatesIdx) = 0; % 割り当てられたトラックの未検出回数をリセット
    end

    % 割り当てられなかったトラックの未検出回数を更新
    if ~isempty(unassignedTracks)
        trackStorage.CheckAssign(validTrackIdx(unassignedTracks)) = trackStorage.CheckAssign(validTrackIdx(unassignedTracks)) + 1; 
    end

    % 未検出回数が閾値を超えたトラックを無効化
    if ~isempty(deleteIdx)
        trackStorage.Logical(validTrackIdx(deleteIdx)) = false; % 削除対象のトラックを無効化
        trackStorage.CheckAssign(validTrackIdx(deleteIdx)) = 0; % 未検出回数をリセット
        validTrackIdx = find(trackStorage.Logical); % 無効化後の有効なトラックのインデックスを求めるため更新
    end
    
    % 検出の対応付け
    if ~isnan(assignment)
        assignedObsIdx = ismember(labelLocation(4,:), assignment(:,2));    % 割り当てられた検出のインデックス
        ObsptClouds = labelLocation(:, assignedObsIdx);  % 割り当てられた検出の点群
    else
        ObsptClouds = [];
    end
    % newObs = zk(:, unassignedDetections);   % 割り当てられなかった検出の重心.


end