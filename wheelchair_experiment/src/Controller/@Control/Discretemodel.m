function [px] = Discretemodel(obj,px_now,pu)%#codegen
    px = gpuArray(zeros(3,obj.K,obj.NP));
    px(1,1,:) = px_now(1);
    px(2,1,:) = px_now(2);
    px(3,1,:) = px_now(3);
    for i = 1:obj.K-1
	    px(1,i+1,:)  = px(1,i,:) + pu(1,i,:).*cos(px(3,i,:))*obj.DT(i,1);
	    px(2,i+1,:)  = px(2,i,:) + pu(1,i,:).*sin(px(3,i,:))*obj.DT(i,1);
	    px(3,i+1,:)  = px(3,i,:) + pu(2,i,:).*obj.DT(i,1);
    end
end

