function [obj,pw_new] = Normalize(obj,pw)
    %重みベクトルを正規化する関数
	NP = obj.NP;
% 	pwnotcollision = 1./pw(pw<10);
%     pwnotcollision = exp(-pw(pw<10));
%     pwnotcollisionID = pw < 10;
%     sumnotcollision = sum(pwnotcollision);
%     if sumnotcollision~=0
%         pw_new = exp(-pw)/sum(sumnotcollision);
%     else
%         pw_new=zeros(1,NP)+1/NP;
%     end
%     pw_new = pw_new.*pwnotcollisionID;
    if isempty(pw(pw<=20))
        obj.reset_flag = 1;
    end
    pw = exp(-pw);
    sumw=sum(pw);
    if sumw~=0
        pw=pw/sum(pw);%正規化
    else
        pw=zeros(1,NP)+1/NP;
    end
    pw_new = pw;
end
