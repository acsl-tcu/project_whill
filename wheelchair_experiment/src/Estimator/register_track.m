function [tempxhat,tempP] = register_track(confirmedIdx,newTrackCandidates, xhat3to6_init, P_init,dt,DimSta)
    tempxhat = zeros(DimSta,length(confirmedIdx)); % トラックの推定値
    tempP = cell(length(confirmedIdx),1); % トラックの誤差共分散
    parfor j = 1:length(confirmedIdx)
    % for j = 1:length(confirmedIdx)
        m = confirmedIdx(j);
        % 一時的なフィルタを作成
        numBuffer = size(newTrackCandidates(m).Buffer, 2) % 過去情報の数
        eststartIdx = 1; % 推定を始める時刻
        % フィルタを初期化
        xhat = [newTrackCandidates(m).Buffer(:,eststartIdx); xhat3to6_init];
        P = P_init;
        Q = diag([0; 0; 0.1; 0.1; 1E-4; 1E-4]);
        R = diag([9E-4; 9E-4]);
        % バッファ内の観測データでフィルタを更新
        for k = eststartIdx:numBuffer %最初
        % for k = numBuffer
            Xhbar = [xhat(1)+xhat(4)*dt*cos(xhat(3))
                     xhat(2)+xhat(4)*dt*sin(xhat(3))
                     xhat(3)
                     xhat(4)
                     xhat(5)
                     xhat(6)];
            jF = [1 0 -Xhbar(4)*dt*sin(Xhbar(3)) dt*cos(Xhbar(3)) 0 0
                  0 1 Xhbar(4)*dt*cos(Xhbar(3)) dt*sin(Xhbar(3)) 0 0
                  0 0 1 0 0 0
                  0 0 0 1 0 0
                  0 0 0 0 1 0
                  0 0 0 0 0 1];
            Pbar = jF*P*jF' + Q; % Q:ProcessNoise
            jH = [1 0 0 0 0 0
                  0 1 0 0 0 0];
            G = Pbar*jH'/(jH*Pbar*jH'+R); % R:MeasurementNoise
            y = newTrackCandidates(m).Buffer(:,k);
            xhat = Xhbar+G*(y-Xhbar(1:2));
            P = (eye(DimSta)-G*jH)*Pbar;            
        end
        tempxhat(:,j) = xhat;
        tempP{j} = P;
    end
end