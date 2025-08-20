function [pw,remove_sample] = EvaluationPath(obj,px,pu,preobs,param_FPM)
%EVALUATIONPATH この関数の概要をここに記述
%   詳細説明をここに記述

	grade = zeros(obj.K-1,obj.NP);
    % remove_sample = false(1,obj.NP);
    obscost = zeros(obj.K-1,obj.NP);
    % wallcost = zeros(obj.K-1,obj.NP);
    vcost = zeros(1,obj.NP);

    %高速化のための変数
    
     vehicle_corner = zeros(4,2,obj.K,obj.NP);
     % 左後ろ
     vehicle_corner(1,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,1,1) .* sin(obj.ltheta(2,1,1) + reshape(px(3,:,:),obj.K,obj.NP));
     vehicle_corner(1,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,1,2) .* cos(obj.ltheta(2,1,2) + reshape(px(3,:,:),obj.K,obj.NP));
     %　左前
     vehicle_corner(2,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,2,1) .* cos(obj.ltheta(2,2,1) + reshape(px(3,:,:),obj.K,obj.NP));
     vehicle_corner(2,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,2,2) .* sin(obj.ltheta(2,2,2) + reshape(px(3,:,:),obj.K,obj.NP));
     %　右後ろ
     vehicle_corner(3,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,3,1) .* cos(obj.ltheta(2,3,1) - reshape(px(3,:,:),obj.K,obj.NP));
     vehicle_corner(3,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,3,2) .* cos(obj.ltheta(2,3,2) - reshape(px(3,:,:),obj.K,obj.NP));
     %　右前
     vehicle_corner(4,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,4,1) .* sin(obj.ltheta(2,4,1) + reshape(px(3,:,:),obj.K,obj.NP));
     vehicle_corner(4,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,4,2) .* sin(obj.ltheta(2,4,2) + reshape(px(3,:,:),obj.K,obj.NP));
     
    %% wall
    B= obj.selectZone(obj.target_n(2:obj.K,:));
    [m, n, k] = size(obj.NoEntryZone);
    [p, q] = size(B);
    % Bを1列ベクトルに変換
    Bvec = B(:); % [p*q, 1]
    % Aの各スライスを2次元に展開
    NoEntryZone2 = reshape(obj.NoEntryZone, m*n, k); % [m*n, k]
    % BvecでA2から列を抽出
     NoEntryZone3 = NoEntryZone2(:, Bvec); % [m*n, p*q]
    % 元の形に戻す
    NoEntryZone4 = pagetranspose(reshape(NoEntryZone3, m, n, p, q)); % [m, n, p, q]
    
    remove_temp = any(vehicle_corner(:,1,2:end,:) >= NoEntryZone4(1,:,:,:) & vehicle_corner(:,1,2:end,:) <= NoEntryZone4(2,:,:,:) &...
                                     vehicle_corner(:,2,2:end,:) >= NoEntryZone4(3,:,:,:) & vehicle_corner(:,2,2:end,:) <= NoEntryZone4(4,:,:,:),[1,2,3]);



    for j = 1:obj.NP    % 確認用
    % parfor j = 1:obj.NP
        grade_temp = zeros(obj.K-1,1);
        % remove_temp = false;
        obscost_temp = zeros(obj.K-1,1);
        % wallcost_x_temp = zeros(obj.K-1,1);
        % wallcost_y_temp = zeros(obj.K-1,1);
        for i = 1:obj.K-1           
            
            %% 壁面制約　1個前の壁面も含む
            
            % ver.1
%             if any(vehicle_corner(:,1,i+1,j) < obj.limit(1,i+1,j) | vehicle_corner(:,1,i+1,j) > obj.limit(2,i+1,j) | vehicle_corner(:,2,i+1,j) < obj.limit(3,i+1,j) | vehicle_corner(:,2,i+1,j) > obj.limit(4,i+1,j)) %壁面の考慮
%                 remove_temp = true;
%             end
            
            % ver.2
%             if any(vehicle_corner(:,1,i+1,j) < obj.wall(obj.target_n(i+1,j)  ,1) | vehicle_corner(:,1,i+1,j) > obj.wall(obj.target_n(i+1,j)  ,2) | vehicle_corner(:,2,i+1,j) < obj.wall(obj.target_n(i+1,j)  ,3) | vehicle_corner(:,2,i+1,j) > obj.wall(obj.target_n(i+1,j)  ,4)) &&... %壁面の考慮
%                any(vehicle_corner(:,1,i+1,j) < obj.wall(obj.target_n(i+1,j)-1,1) | vehicle_corner(:,1,i+1,j) > obj.wall(obj.target_n(i+1,j)-1,2) | vehicle_corner(:,2,i+1,j) < obj.wall(obj.target_n(i+1,j)-1,3) | vehicle_corner(:,2,i+1,j) > obj.wall(obj.target_n(i+1,j)-1,4)) &&...
%                any(vehicle_corner(:,1,i+1,j) < obj.wall(obj.target_n(i+1,j)+1,1) | vehicle_corner(:,1,i+1,j) > obj.wall(obj.target_n(i+1,j)+1,2) | vehicle_corner(:,2,i+1,j) < obj.wall(obj.target_n(i+1,j)+1,3) | vehicle_corner(:,2,i+1,j) > obj.wall(obj.target_n(i+1,j)+1,4))
%                 remove_temp = true;
%             end
            
            % ver .3
            % 全ての点が少なくとも1つの四角形内にあるか確認
            % insideWall1 = vehicle_corner(:,1,i+1,j) >= obj.wall(obj.target_n(i+1,j)-1,1) & vehicle_corner(:,1,i+1,j) <= obj.wall(obj.target_n(i+1,j)-1,2) & ...
            %               vehicle_corner(:,2,i+1,j) >= obj.wall(obj.target_n(i+1,j)-1,3) & vehicle_corner(:,2,i+1,j) <= obj.wall(obj.target_n(i+1,j)-1,4);
            % 
            % insideWall2 = vehicle_corner(:,1,i+1,j) >= obj.wall(obj.target_n(i+1,j)+1,1) & vehicle_corner(:,1,i+1,j) <= obj.wall(obj.target_n(i+1,j)+1,2) & ...
            %               vehicle_corner(:,2,i+1,j) >= obj.wall(obj.target_n(i+1,j)+1,3) & vehicle_corner(:,2,i+1,j) <= obj.wall(obj.target_n(i+1,j)+1,4);
            % 
            % insideWall3 = vehicle_corner(:,1,i+1,j) >= obj.wall(obj.target_n(i+1,j)  ,1) & vehicle_corner(:,1,i+1,j) <= obj.wall(obj.target_n(i+1,j)  ,2) & ...
            %               vehicle_corner(:,2,i+1,j) >= obj.wall(obj.target_n(i+1,j)  ,3) & vehicle_corner(:,2,i+1,j) <= obj.wall(obj.target_n(i+1,j)  ,4);
            % いずれかの四角形内に各点があるか
            % inside_any = insideWall1 | insideWall2 | insideWall3;
            % if ~all(inside_any)
            %     remove_temp = true;
            % end

            % ver.4
            % if remove_temp == false
            %     Zone=obj.NoEntryZone{obj.selectZone(obj.target_n(i+1,j),1),1};
            %     for k=1:size(Zone,1)
            %         if any(vehicle_corner(:,1,i+1,j) >=Zone(k,1) & vehicle_corner(:,1,i+1,j) <= Zone(k,2) &...
            %                vehicle_corner(:,2,i+1,j) >=Zone(k,3) & vehicle_corner(:,2,i+1,j) <= Zone(k,4))
            %             remove_temp = true;
            %             break
            %         end
            %     end
            % end

            % ver.5
            % if remove_temp == false
            %     Zone=obj.NoEntryZone(:,:,obj.selectZone(obj.target_n(i+1,j)));
            %     for k=1:obj.ZoneNum(obj.selectZone(obj.target_n(i+1,j)))
            %         if any(vehicle_corner(:,1,i+1,j) >=Zone(k,1) & vehicle_corner(:,1,i+1,j) <= Zone(k,2) &...
            %                vehicle_corner(:,2,i+1,j) >=Zone(k,3) & vehicle_corner(:,2,i+1,j) <= Zone(k,4))
            %             remove_temp = true;
            %             break
            %         end
            %     end
            % end
            % if remove_temp == true
            %     break
            % end


            %% 壁面コスト
            % wallcost_x_temp(i,1) = max(obj.wall_penalty1*((vehicle_corner(:,1,i+1,j)-(obj.limit(2,i+1,j)-obj.wall_threshold)).*(vehicle_corner(:,1,i+1,j)>(obj.limit(2,i+1,j)-obj.wall_threshold))) + -obj.wall_penalty1*((vehicle_corner(:,1,i+1,j)+-1*(obj.limit(1,i+1,j)+obj.wall_threshold)).*((obj.limit(1,i+1,j)+obj.wall_threshold)>vehicle_corner(:,1,i+1,j))) + obj.wall_penalty2*(vehicle_corner(:,1,i+1,j)>obj.limit(2,i+1,j) | vehicle_corner(:,1,i+1,j)<obj.limit(1,i+1,j)));
            % wallcost_y_temp(i,1) = max(obj.wall_penalty1*((vehicle_corner(:,2,i+1,j)-(obj.limit(4,i+1,j)-obj.wall_threshold)).*(vehicle_corner(:,2,i+1,j)>(obj.limit(4,i+1,j)-obj.wall_threshold))) + -obj.wall_penalty1*((vehicle_corner(:,2,i+1,j)+-1*(obj.limit(3,i+1,j)+obj.wall_threshold)).*((obj.limit(3,i+1,j)+obj.wall_threshold)>vehicle_corner(:,2,i+1,j))) + obj.wall_penalty2*(vehicle_corner(:,2,i+1,j)>obj.limit(4,i+1,j) | vehicle_corner(:,2,i+1,j)<obj.limit(3,i+1,j)));
            %%

            %xmin xmax ymin ymax

            %% obstacle cost(only nearest)
%             obsdis = -inf;
%             
%             for k=1:obj.ObsNum
%                 obsdis_temp = norm(preobs{i+2,1}(k,:)-[px(1,i+1,j),px(2,i+1,j)]);
%                 if obsdis_temp > obsdis
%                    obsdis = obsdis_temp;
%                    nearest = k;
%                 end
%             end
% %             obscost_temp(i,1) = pu(1,i+1,j)^2/(abs(obsdis)+0.1);
%             obscost_temp(i,1) = sqrt(((pu(1,i+1,j)^2)*sin(px(3,i+1,j)) - obj.VOBS(k,2))^2 + ((pu(1,i+1,j)^2)*cos(px(3,i+1,j)) - obj.VOBS(k,1))^2)/(abs(obsdis));

            %obstacle cost(all detection)

%             if obj.ObsNum == 0
%                 obsdis = zeros(1,1);
%                 obsdis = -inf;
%             end
%             obsdis = -inf;
%             for k=1:obj.ObsNum
%                 obsdis(k) =  norm(preobs{i+2,1}(k,:)-[px(1,i+1,j),px(2,i+1,j)]);
%             end
            
            %probability
%             k = 1;
%             %i:horizon j:samples k:obsnum
%             sig=obscov{1,1}{1,i}{1,k}([1 3],[1 3]);
%             loc = px([1,2],i+1,j);
%             Obsloc = obsstat{1,1}{1,i}{1,k}([1,3],:);
%             vel = [pu(1,i+1,j)*cos(px(3,i+1,j));pu(1,i+1,j)*sin(px(3,i+1,j))];
%             Obsvel = obsstat{1,1}{1,i}{1,k}([2,4],:);
% %             (norm(vel)*norm(Obsvel)-dot(vel,Obsvel))*exp((-1/2)*(loc-Obsloc)'*inv(sig)*(loc-Obsloc));
%             (norm(vel)*norm(Obsvel)-dot(vel,Obsvel))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
%           
% -- prob-------------------------------------------------
%             prob = zeros(1,obj.ObsNum);
%             obsprob = prob;
%             if obscov{1,1}{1,1}{1,1}(1,1) == 0
%                 prob = 0;
%                 obsprob = 0;
%             else
%                 for k=1:obj.ObsNum
%                     sig=obscov{1,1}{1,i}{1,k}([1 3],[1 3]);
%                     loc = px([1,2],i+1,j);
%                     Obsloc = obsstat{1,1}{1,i}{1,k}([1,3],:);
%                     vel = [pu(1,i+1,j)*cos(px(3,i+1,j));pu(1,i+1,j)*sin(px(3,i+1,j))];
%                     Obsvel = obsstat{1,1}{1,i}{1,k}([2,4],:);
%                     if norm(loc-Obsloc)
%                         % loc_r = move_point(Obsloc,loc,preobs{i,1}(k,5));
% %                         prob(k) = 1/(sqrt(det(sig)*(2*pi)^2))*exp((-1/2)*(loc_r)'*(sig\(loc_r)));
%                         prob(k) = 1/(sqrt(det(sig)*(2*pi)^2));
%                     else
%                         loc = move_point(loc,Obsloc,preobs{i,1}(k,5));
%                         prob(k) = 1/(sqrt(det(sig)*(2*pi)^2))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
%                     end
% % %                     prob(k) = 1/(sqrt(det(sig)*(2*pi)^2))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
%                     obsprob(k) = (norm(vel)-dot(vel,Obsvel))*prob(k);
% %                     obsprob(k) = (norm(vel)*norm(Obsvel))*exp((-1/2)*(loc-Obsloc)'*(sig\(loc-Obsloc)));
%                 end
%             end
% 
%             obscost_temp(i,1) = sum(obsprob);
% ------------------------------------------------------

%             obscost_temp(i,1) = sum(sqrt((obj.VOBS(1:obj.ObsNum,2) - (repmat(pu(1,i+1,j),obj.ObsNum,1)).*sin(repmat(px(3,i+1,j),obj.ObsNum,1))).^2 + (obj.VOBS(1:obj.ObsNum,1) - (repmat(pu(1,i+1,j),obj.ObsNum,1)).*cos(repmat(px(3,i+1,j),obj.ObsNum,1))).^2)./(abs(obsdis)'));
        %% FPM cost
            % [~,grade_temp(i,1)] = FPM_capsule_v2(obj,px(1,i+1,j),px(2,i+1,j),px(3,i+1,j),obsstat2{1,i}',obj.target(:,i+1,j)',param_FPM);
            [grade_temp(i,1),~] = FPM_capsule_v3_1(obj,px(1,i+1,j),px(2,i+1,j),px(3,i+1,j),preobs(:,:,i)',obj.target(:,i+1,j)',param_FPM);
        end
        %% velocity cost
        vcost(:,j) = ((pu(1,1,j)-0.55)*5000)*(pu(1,1,j) > 0.55)+((pu(1,1,j)+0.25)*-5000)*(pu(1,1,j) < -0.25);
        
        %% wall cost
        % wallcost_x_temp(isnan(wallcost_x_temp)) = 0;
        % wallcost_y_temp(isnan(wallcost_y_temp)) = 0;
        % wallcost(:,j) = wallcost_x_temp + wallcost_y_temp;
        
        grade(:,j) = grade_temp;
        % remove_sample(1,j) = remove_temp;
        obscost(:,j) = obscost_temp;
    end
     remove_sample=remove_temp(:);
    
%     tocBytes(gcp);obscov
	FPMcost = sum(1 - grade);
	Inputcost = reshape(sum(pu(2,1:end-1,:).^2)*obj.R(2) +  sum((pu(1,1:end-1,:) - obj.Vref).^2)*obj.R(1),[1,obj.NP]);
%     Turningcost = reshape(sum((pu(1,1:end-1,:).*pu(2,1:end-1,:)).^2),[1,obj.NP])*obj.W;
    OBScost = obj.Wo*sum(obscost);
    % WALLcost = 0.5*sum(wallcost);
	% pw = FPMcost + Inputcost + OBScost + vcost + WALLcost;
    pw = FPMcost + Inputcost + OBScost + vcost;
end