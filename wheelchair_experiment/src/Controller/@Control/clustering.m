function [uOpt,fval,removed] = clustering(obj,pw,pu,px,remove_sample)
% Remove samples that were rejected before clustering
    % Increase sampling to remove samples (is this necessary for processing results?)
    % Note: From here on, px, pu, pw and indices must correspond
	DT = obj.DT;
	
    k_sigma = 20.0;
    thr = k_sigma;
%     x2 = reshape(x,[1,size(x)]);
%     y2 = reshape(y,[1,size(y)]);
%     th2 = reshape(th,[1,size(th)]);
%     px = [x2;y2;th2];
%     v2 = reshape(v,[1,size(v)]);
%     w2 = reshape(w,[1,size(w)]);
%     pu = [v2;w2];


%     removeF = (pw>=10000);% || px(1,:,:) < tempobj.wall(1,1) || px(1,:,:) > tempobj.wall(1,2) || px(2,:,:) < tempobj.wall(2,1) || px(2,:,:) > tempobj.wall(2,2));
%     pu(:,:,removeF)=[];
%     px(:,:,removeF)=[];
%     pw(removeF)=[];
    %if violate constraint of position then remove
     pu(:,:,remove_sample)=[];
     px(:,:,remove_sample)=[];
     pw(remove_sample)=[];
     
    %if v > 0.7m/s then remove
%      remove_sample = reshape(pu(1,1,:)>0.3,1,length(pu));
%      pu(:,:,remove_sample)=[];
%      px(:,:,remove_sample)=[];
%      pw(remove_sample)=[];
    
    %if omega > 0.7 rad/s then remove

    
    %if acceleration > 1m/s^2 then remove
%      acc = (obj.v_old - )
     
    % Calculate optimal solution (extract samples before resampling based on evaluation function values, and perform clustering based on distance in input space)
    [sortFval,sortIdx]=sort(pw);
    % Sort by evaluation values before resampling and extract top x% of good samples
    sortIdxT=sortIdx(1:ceil(0.05*length(pw)));
    pwT = pw(sortIdxT);
    puT = pu(:,:,sortIdxT);
    pxT = px(:,:,sortIdxT);
    
%     figure
%     for i = 1:length(sortIdxT)
%         plot(pxT(1,:,i),pxT(2,:,i));hold on
%     end
%     axis equal
    % Assign the first sample to cluster 1
    pcT=zeros(1,length(pwT));
    pcT(1) = 1;
    cNum=1;
    
    % Compare the 2nd and subsequent samples with all existing clusters (for the 2nd sample, only cluster 1 exists)
    % If distance is below threshold, add to same cluster; if above threshold, create new cluster. Repeat for all extracted samples
    for i=2:length(pwT)
        for j=1:cNum
%             dist(j) = norm(puT(:,:,i) - mean(puT(:,:,pcT==j),3)); % Calculate distance from i-th sample to j-th cluster center
            dist(j) = sum((pxT(:,:,i) - mean(pxT(:,:,pcT==j),3)).^2,'all');
        end
        [minDist, minIdx]=min(dist);
        if minDist < thr(minIdx)
            pcT(i) = minIdx;
%             thr(minIdx) = minDist;
        else
            cNum=cNum+1;
            pcT(i) = cNum;
            thr(cNum) = k_sigma;
        end
    end
    % For each cluster, take weighted average and output input sequence and evaluation value per cluster (evaluation value -> only the best cluster)
%     if isempty(puT)
%         fval = [];
%     else
        for j=1:cNum
            try
                uOpt.u(j).u = mean(puT(:,:,pcT==j),3);
                fval(1) = mean(pwT(pcT==j));
            catch ME

                % Pause to allow inspection
                keyboard; % This will pause execution and enter debug mode
                
                % Re-throw the error
                rethrow(ME);
            end
        end
        for j = 1:cNum
            uOpt.u(j).x = px(:,1,1);
            for i = 1:length(DT)
                uOpt.u(j).x(1,i+1) = uOpt.u(j).x(1,i) + uOpt.u(j).u(1,i)*cos(uOpt.u(j).x(3,i))*DT(i,1);
                uOpt.u(j).x(2,i+1) = uOpt.u(j).x(2,i) + uOpt.u(j).u(1,i)*sin(uOpt.u(j).x(3,i))*DT(i,1);
                uOpt.u(j).x(3,i+1) = uOpt.u(j).x(3,i) + uOpt.u(j).u(2,i)*DT(i,1);
            end
        end
%     end
    uOpt.cNum = cNum;
    uOpt.pcT = pcT;
    uOpt.puT = puT;
    uOpt.pxT = pxT;
    removed.pu = pu;
    removed.px = px;
    removed.pw = pw;
%     cNum
end