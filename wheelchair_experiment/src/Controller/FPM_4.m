function [Grade,Grade_old,th_min,th_max,GRADE_TRGT,GRADE_ANGL,GRADE_OBS] = FPM_4(obj,x,y,th,obs,obs_now,target,prob)
    obsnum = obj.ObsNum;
	%goal = obj.goal;
    goal = target;
	r_wheel = obj.r_wheel;
	r_obs = obj.r_obs;
	g_a = 1.0;
%    eps = 1.0;
    % eta = -0.2;
    eta = 0.3;
    g_b = eta*g_a;
    % alpha = 2.5;
    alpha = 5;
%     Q = [1:-0.1:0.1];
    distance_obs = zeros(obsnum,1);
    tho = zeros(obsnum,1);
    PoQo = zeros(obsnum,1);
    phaiR = zeros(obsnum,1);
    a = zeros(obsnum,1);
    grade_obs = ones(obsnum,1);
    th_max = zeros(obsnum,1);
    th_min = zeros(obsnum,1);
    OBS_NOW = obs_now;
%     OBS_NOW = cell2mat(obs_now);
    OBS = obs;
%     OBS = cell2mat(obs);
    state = [x y]; % �T���v���ɂ�����ԗ��̈ʒu
    % PMF�̃v���b�g����ۂɃR�����g�O��
%     resolution = 0.1;%PMF�̕���\[deg]
%     GRADE_TRGT = zeros(1,360/resolution);
%     GRADE_OBS = ones(1,360/resolution);
%     GRADE_obs = ones(obsnum,360/resolution);
%     GRADE_ANGL = [-pi + resolution*pi/180:resolution*pi/180:pi];
%     distance = norm(goal-[x y]);
%     tic
%     distance_obs = sqrt(sum((OBS_NOW - state).^2,2));
%     distance_obs = vecnorm(OBS_NOW-state,2,2);
%     toc
%     tic
    for i = 1:obsnum
        % OBS <- OBS_NOW
        distance_obs(i,1) = norm(OBS_NOW(i,:) - state);
    end
%     toc
%     tic
%     for i = 1:obsnum
%         distance_obs(i,1) = norm(obs_now{i,1} - [x y]);
%     end
%    toc
%     if distance < eps
%         g_a = distance / eps;		
%         g_b = eta * g_a;
%     end
    thg = atan2((goal(1,2) - y),(goal(1,1) - x)) - th; % ���ԗ�(sample)�̊p�x�ƖڕW�p�x�̌덷
    % OBS <- OBS_NOW
    tho = atan2(OBS_NOW(:,2) - y,OBS_NOW(:,1) - x) - th; % ���ԗ�(sample)�̊p�x�Ə�Q���p�x�̌덷
%     PoQo = sqrt(sum((OBS - state).^2,2));
%     PoQo = vecnorm(OBS-state,2,2);
%     phaiR = abs(asin((r_wheel + r_obs)./PoQo));
%     a = (alpha - PoQo)/(alpha - (r_wheel + r_obs));

    for i = 1:obsnum
%         tho(i,1) = atan2((obs{i,1}(1,2) - y),(obs{i,1}(1,1) - x)) - th;
%         PoQo(i,1) = norm(obs{i,1} - [x y]);
        % OBS <- OBS_NOW
        PoQo(i,1) = norm(OBS_NOW(i,:) - state); % ���ԗ��Ə�Q���̋���
        phaiR(i,1) = abs(asin(complex((r_wheel + r_obs)/PoQo(i,1)))); % ��Q���Ǝ��ԗ����ڐG���Ȃ��p�x
        a(i,1) = (alpha - PoQo(i,1))/(alpha - (r_wheel + r_obs)); % 
    end
    phaierror = atan2(sin(thg - 0),cos(thg - 0));
    grade_trgt = -((g_a - g_b)/pi)*abs(phaierror) + g_a;

    % grade_trgt = ((g_a-g_b)/pi)*(pi-abs(thg))+g_b;

    % phia = 0.7390851512278;
    % grade_trgt = (1-g_b)/2*cos(0-phia-thg+cos(cos(0-phia-thg)))+(g_b+1)/2;

    for i = 1:obsnum
%         grade_obs(i,1) = 1.0;
%         if tho(i,1) - phaiR(i,1) <= 0.0 && 0.0 <= tho(i,1) + phaiR(i,1)
        th_max(i,1) = atan2(sin(tho(i,1) - phaiR(i,1)),cos(tho(i,1) - phaiR(i,1))); % �O���[�h�ቺ�͈�
        th_min(i,1) = atan2(sin(tho(i,1) + phaiR(i,1)),cos(tho(i,1) + phaiR(i,1))); % �O���[�h�ቺ�͈�
%         th_max_local(i,1) = tho(i,1) - phaiR(i,1);
%         th_min_local(i,1) = tho(i,1) + phaiR(i,1);
        if th_max(i,1) <= 0.0 && 0.0 <= th_min(i,1) % ���̏�Q�������ԗ��̐��ʂɑ��݂��Ă��邩
            if PoQo(i,1) < alpha % alpha�ȓ��ɏ�Q��������ꍇ
%                 grade_obs(i,1) = 1 - a(i,1);
                grade_obs(i,1) = 1 - 100*prob(i); % ��Q���̑��݊m���������قǃO���[�h�ቺ
                % grade_obs(i,1) = 1 - exp(-(PoQo(i,1)-r_obs-r_wheel*2.5)/1.8);
            else
                grade_obs(i,1) = 1.0;
            end
            if grade_obs(i,1) < 0
                grade_obs(i,1) = 0; % �}�C�i�X�̏ꍇ0
            end
        end
    end
    Grade_old = min(grade_trgt,min(grade_obs)); % �ڕW�p�x�̃O���[�h�Ə�Q���O���[�h�̂Ȃ��ōŒ�O���[�h���擾
%     phai = -pi + resolution*pi/180;
%     for j = 1:360/resolution
%         phaierror = atan2(sin(thg - phai),cos(thg - phai));
%         GRADE_TRGT(1,j) = -((g_a - g_b)/pi)*abs(phaierror) + g_a;
%         for i = 1:obsnum
%             if th_min_local(i,1) > pi || th_max_local(i,1) < -pi
%                 if or(th_max(i,1) <= phai && phai <= pi,th_min(i,1) >= phai && phai >= -pi)
%                     if PoQo(i,1) < alpha
%                         GRADE_obs(i,j) = 1 - a(i,1);
%                     end
%                 end
%             else
%                 if th_max(i,1) <= phai && phai <= th_min(i,1)
%                     if PoQo(i,1) < alpha
%                         GRADE_obs(i,j) = 1 - a(i,1);
%                     end
%                 end
%             end
%         end
%         phai = phai + resolution*pi/180;
%     end
%     GRADE_OBS = min(GRADE_obs,[],1);
%     Grade = max(min([GRADE_TRGT;GRADE_OBS],[],1));

    Grade = -10;
%     if any(distance_obs(:,1)<(r_wheel + r_obs))
%         Grade = -100;
%         Grade_old = -100;
%     end
end