function [pw,remove_sample] = EvaluationPath_vec(obj,px,pu,preobs,param_FPM)
%�@EVALUATIONPATH ���̊֐��̊T�v�������ɋL�q

    %%�@�d���Ԉ֎q4�_�̍��W
    vehicle_corner = zeros(4,2,obj.K,obj.NP);
    % �����
    vehicle_corner(1,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,1,1) .* sin(obj.ltheta(2,1,1) + reshape(px(3,:,:),obj.K,obj.NP));
    vehicle_corner(1,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,1,2) .* cos(obj.ltheta(2,1,2) + reshape(px(3,:,:),obj.K,obj.NP));
    %�@���O
    vehicle_corner(2,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,2,1) .* cos(obj.ltheta(2,2,1) + reshape(px(3,:,:),obj.K,obj.NP));
    vehicle_corner(2,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,2,2) .* sin(obj.ltheta(2,2,2) + reshape(px(3,:,:),obj.K,obj.NP));
    %�@�E���
    vehicle_corner(3,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,3,1) .* cos(obj.ltheta(2,3,1) - reshape(px(3,:,:),obj.K,obj.NP));
    vehicle_corner(3,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,3,2) .* sin(obj.ltheta(2,3,2) - reshape(px(3,:,:),obj.K,obj.NP));
    %�@�E�O
    vehicle_corner(4,1,:,:) = reshape(px(1,:,:),obj.K,obj.NP) + obj.ltheta(1,4,1) .* cos(obj.ltheta(2,4,1) + reshape(px(3,:,:),obj.K,obj.NP));
    vehicle_corner(4,2,:,:) = reshape(px(2,:,:),obj.K,obj.NP) + obj.ltheta(1,4,2) .* sin(obj.ltheta(2,4,2) + reshape(px(3,:,:),obj.K,obj.NP));
     
    %% wall
    B= obj.selectZone(obj.target_n(1:obj.K,:));
    [m, n, k] = size(obj.NoEntryZone);
    [p, q] = size(B);
    % B��1��x�N�g���ɕϊ�
    Bvec = B(:); % [p*q, 1]
    % NoEntryZone�̊e�X���C�X��2�����ɓW�J
    NoEntryZone2 = reshape(obj.NoEntryZone, m*n, k); % [m*n, k]
    % Bvec��NoEntryZone2�����𒊏o
    NoEntryZone3 = NoEntryZone2(:, Bvec); % [m*n, p*q]
    % ���̌`�ɖ߂�
    NoEntryZone4 = pagetranspose(reshape(NoEntryZone3, m, n, p, q)); % [m, n, p, q]
    
    %% �ǖʐ���
    remove_sample = reshape(any(vehicle_corner(:,1,1:end,:) >= NoEntryZone4(1,:,:,:) & vehicle_corner(:,1,1:end,:) <= NoEntryZone4(2,:,:,:) &...
                                vehicle_corner(:,2,1:end,:) >= NoEntryZone4(3,:,:,:) & vehicle_corner(:,2,1:end,:) <= NoEntryZone4(4,:,:,:),[1,2,3]) , [] , 1);

    %% Wall cost
    wall_near = any(vehicle_corner(:,1,1:end,:) >= NoEntryZone4(1,:,:,:) - obj.wall_threshold & vehicle_corner(:,1,1:end,:) <= NoEntryZone4(2,:,:,:)+obj.wall_threshold &...
                    vehicle_corner(:,2,1:end,:) >= NoEntryZone4(3,:,:,:) - obj.wall_threshold & vehicle_corner(:,2,1:end,:) <= NoEntryZone4(4,:,:,:)+obj.wall_threshold,[1,2]);
    wall_near_sum =sum(wall_near,[3]);
    WALLcost = obj.wall_penalty1*wall_near_sum(:)';

    %% FPM cost
    preobs2=pagetranspose(preobs);
    target2=pagetranspose(reshape(obj.target,[2,1,obj.K,obj.NP]));
    px2 = reshape(px,[3,1,obj.K,obj.NP]);
    % [grade] = FPM_capsule_v3_2vec(obj,px2(1,:,2:obj.K,:),px2(2,:,2:obj.K,:),px2(3,:,2:obj.K,:),preobs2(:,:,1:obj.K-1),target2(:,:,2:obj.K,:),param_FPM);
     [grade] = FPM_capsule_v3_3vec(obj,px2(1,:,2:obj.K,:),px2(2,:,2:obj.K,:),px2(3,:,2:obj.K,:),preobs2(:,:,1:obj.K-1),target2(:,:,2:obj.K,:),param_FPM);
    FPMcost = reshape((obj.K-1) - sum(grade,3) , 1 , []);

    %% Velocity cost
    v_max= 0.55;
    v_min=-0.25;
    v_cost=5000;
    Vcost = reshape(((pu(1,1,:)-v_max)*v_cost).*(pu(1,1,:) > v_max)+((pu(1,1,:)-v_min)*-v_cost).*(pu(1,1,:) < v_min),1,[]);
	
    %% Input cost
    Vref = reshape(obj.V_ref(obj.target_n(1:obj.K-1,:)), 1, obj.K-1, obj.NP);       % ���ꂼ��̃|�C���g���ƂɖڕW���x������
    % Vref =obj.V_ref(obj.target_n(1,1));     % ���ׂē����ڕW���x
    Inputcost = reshape(sum(pu(2,1:end-1,:).^2)*obj.R(2) +  sum((pu(1,1:end-1,:) - Vref).^2)*obj.R(1),[1,obj.NP]);
	
    %% Distance cost
    Q = 0.15;  % �d��
    w0 = reshape(obj.waypoint(obj.target_n-1,:)',1,2,obj.K,obj.NP);
    w1 = reshape(obj.waypoint(obj.target_n  ,:)',1,2,obj.K,obj.NP);
    state = pagetranspose(px2(1:2,:,:,:));
    d_target = get_distance(w0,w1,state);
    Dcost = reshape(sum(d_target,3)*Q,1,[]);

    %% Cost SUM
    % pw = FPMcost + Inputcost + Vcost + WALLcost;
    pw = FPMcost + Inputcost + Vcost + WALLcost+Dcost;

end