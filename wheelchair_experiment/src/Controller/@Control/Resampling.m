function [px,pw,pv] = Resampling(obj,ppu,pw)
    %RESAMPLING この関数の概要をここに記述
    %   詳細説明をここに記述
%     if obj.Resamplingmode == "LVS"
        NP = obj.NP;
        px = reshape(ppu(2,:,:),[],NP);
        v  = reshape(ppu(1,:,:),[],NP); 
        %px:パーティクル，pw:重み
        %リサンプリングを実施する関数
        %アルゴリズムはLow Variance Sampling
        wcum=cumsum(pw);
        base=cumsum(pw*0+1/NP)-1/NP;%乱数を加える前のbase
        resampleID=base+rand/NP;%ルーレットを乱数分増やす
        ppx=px;%データ格納用
        pv = v;
        ind=1;%新しいID
        for ip=1:NP
            while(resampleID(ip)>wcum(ind))
                ind=ind+1;
            end
            px(1:end,ip)= [ppx(2:end,ind);ppx(end,ind)];%LVSで選ばれたパーティクルに置き換えppx(:,ind);%
            pv(1:end,ip)= [v(2:end,ind);v(end,ind)];%v(:,ind);%
            pw(ip)=1/NP;%尤度は初期化
        end
%     elseif obj.Resamplingmode == "Date"
        
%     end
end

