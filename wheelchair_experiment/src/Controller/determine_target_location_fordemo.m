function [tgt,lim,tgt_n] = determine_target_location_fordemo(obj,px,resetWPIdx)
    tgt = zeros(2,obj.K,obj.NP);
    lim = zeros(4,obj.K,obj.NP);
    for j = 1:obj.NP
        for i = 1:obj.K
            d = (obj.abc(obj.target_n(i,j)-1,1)*px(1,i,j) + obj.abc(obj.target_n(i,j)-1,2)*px(2,i,j) + obj.abc(obj.target_n(i,j)-1,3))/sqrt(obj.abc(obj.target_n(i,j)-1,1)^2+obj.abc(obj.target_n(i,j)-1,2)^2);
            if d > -0.15 && d < 0.15
                obj.target_n(i,j) = obj.target_n(i,j) + 1;
                if obj.target_n(i,j) == length(obj.waypoint)+1
                    obj.target_n(i,j) = resetWPIdx;
                end
            end
            tgt(:,i,j) = obj.waypoint(obj.target_n(i,j),:);
            lim(:,i,j) = obj.wall(obj.target_n(i,j),:); 
        end
    end
    tgt_n = obj.target_n;
end