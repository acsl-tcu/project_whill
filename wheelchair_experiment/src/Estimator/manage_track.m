function [trackStorage, newTrackCandidates] = manage_track(zk,trackStorage, newTrackCandidates, Allxhat, distanceThreshold, ...
    requiredFrames, xhat3to6_init, P_init, delta, tempStorage,DimSta)
    %% トラック候補の判別
    numCandidates = length(newTrackCandidates);
    if ~isempty(zk)
        if ~isempty(newTrackCandidates) || ~isempty(Allxhat)
            numTracks = size(Allxhat,2);
            
            % トラック候補と現在のトラックを対象に割り当てコストを計算
            existingObs = zeros(2, numCandidates + numTracks);
            if numCandidates > 0
                existingObs(:,1:numCandidates) = reshape([newTrackCandidates(:).Obs], 2, numCandidates);
            end
            if numTracks > 0
                existingObs(:,numCandidates+1:end) = Allxhat(1:2, :);
            end
            % コスト行列の計算（ベクトル化された距離計算）
            costMatrix = pdist2(existingObs', zk', 'euclidean');
            
            % トラック候補+既存トラックvs現時刻の検出で対応付け
            [assignment, unassignedCandidates, unassignedDetections] = ...
                assignDetectionsToTracks(costMatrix, distanceThreshold);

            % 割り当てをトラック候補と既存トラックに分離
            isCandidateAssignment = assignment(:,1) <= numCandidates;
            candidateAssignments = assignment(isCandidateAssignment, :); % トラック候補検出点への検出点の割り当てインデックス
            % trackAssignments = assignment(~isCandidateAssignment, :); % 既存トラックへの検出点割り当てインデックス
    
            % マッチしたトラック候補の更新
            bufferSize = requiredFrames;
            for idx = 1:size(candidateAssignments, 1)
                candidateIdx = candidateAssignments(idx, 1);
                detectionIdx = candidateAssignments(idx, 2);
    
                obs = zk(:, detectionIdx);
                newTrackCandidates(candidateIdx).Count = newTrackCandidates(candidateIdx).Count + 1;
                newTrackCandidates(candidateIdx).Obs = obs;
                % バッファの更新
                buffer = newTrackCandidates(candidateIdx).Buffer;
                buffer = [buffer, obs];
                if size(buffer, 2) > bufferSize % バッファサイズ上限を超えたら過去分を削除
                    buffer = buffer(:, end - bufferSize + 1 : end);
                end
                newTrackCandidates(candidateIdx).Buffer = buffer;
            end
    
            % 未割り当ての検出点を新しいトラック候補として追加
            for idx = 1:length(unassignedDetections)
                detectionIdx = unassignedDetections(idx);
                obs = zk(:, detectionIdx);
                newCandidate.Obs = obs;
                newCandidate.Count = 1;
                newCandidate.Buffer = obs;
                newTrackCandidates = [newTrackCandidates newCandidate];
            end
    
            % 未対応のトラック候補を管理
            unassignedCandidateIndices = unassignedCandidates(unassignedCandidates <= numCandidates);
            for idx = length(unassignedCandidateIndices):-1:1
                candidateIdx = unassignedCandidateIndices(idx);
                newTrackCandidates(candidateIdx).Count = newTrackCandidates(candidateIdx).Count - 1;
                if newTrackCandidates(candidateIdx).Count <= 0
                    newTrackCandidates(candidateIdx) = [];
                end
            end
        else
            % トラック候補が存在しない場合、すべての検出値を新しいトラック候補として追加
            for i = 1:size(zk, 2)
                obs = zk(:, i);
                newTrackCandidates(end+1).Obs = obs;
                newTrackCandidates(end).Count = 1;
                newTrackCandidates(end).Buffer = obs;
            end
        end
    end
    
    %% トラック候補の登録
    isConfirmed = [newTrackCandidates.Count] >= requiredFrames;
    confirmedIdx = find(isConfirmed);
    if ~isempty(confirmedIdx)
        if nnz(~trackStorage.Logical) >= length(confirmedIdx)
            % 空きインデックスを探す
            newTrackIdx = find(~trackStorage.Logical, length(confirmedIdx));
            % EKFで推定初期値を求める(並列化済)
            [tempxhat,tempP] = register_track(confirmedIdx,newTrackCandidates, xhat3to6_init, P_init,delta,DimSta);
            for j = 1:length(confirmedIdx)
                % トラックとして追加
                n = newTrackIdx(j);
                trackStorage.Logical(n) = true;
                trackStorage.States(:,n) = tempxhat(:,j);
                trackStorage.CheckAssign(n) = 0;
                trackStorage.P{n,1} = tempP{j};
                % trackerの初期化
                initialize(trackStorage.tracker{n,1}, trackStorage.States(:,n), trackStorage.P{n,1});
            end
            % 新規トラック候補を削除
            newTrackCandidates(isConfirmed) = [];
        else
            warning('トラック管理許容数を超えました．新しいトラックを追加できません．');
        end
    end
    
end