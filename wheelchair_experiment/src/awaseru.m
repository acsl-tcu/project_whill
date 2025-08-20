clc; clear variables ;

prompt = 'Number of reference points?:';
ref = input(prompt);

true = zeros(ref,3);
est = zeros(ref,2);
q = zeros(ref,4);
% for i = 1:ref
%     fprintf('Groundtruth coordinates?:%d\n',i);
%     for j = 1:3
%         switch j
%             case 1
%                 prompt = 'x?:';
%             case 2
%                 prompt = 'y?:';
%             case 3
%                 prompt = 'yaw?:';
%         end
%         true(i,j) = input(prompt);
%     end
% end

% true = [0 0 0;
%         2 0 0;
%         4 2 1.57;
%         0 4 3.14];
true = [0 0 0];

clc;
for i = 1:ref
    fprintf('Estimated value of xy?:%d\n',i);
    for j = 1:2
        switch j
            case 1
                prompt = 'x?:';
            case 2
                prompt = 'y?:';
        end
        est(i,j) = input(prompt);
    end
end
clc;

for i = 1:ref
    fprintf('Estimated value of quaternion?:%d\n',i);
    for j = 1:4
        switch j
            case 1
                prompt = 'w?:';
            case 2
                prompt = 'x?:';
            case 3
                prompt = 'y?:';
            case 4
                prompt = 'z?:';
        end
        q(i,j) = input(prompt);
    end
end
clc;

eul = quat2eul(q);
temp = -(true - [est(:,1),est(:,2),eul(:,1)])/ref;
err = sum(temp);

fprintf('Adjust the estimated position to this value:\n[x,y,yaw]=[%d,%d,%d]\n',err(1),err(2),err(3));



% % true = [x,y,yaw];
% true1 = [-10 0 0];
% true2 = [37 0 0];
% true3 = [38 7 0];
% true4 = [-10 7 0];
% 
% %est = [x,y];
% est1 = [-10.0619 -0.031978];
% est2 = [36.8561019 0.01293124];
% est3 = [37.901985 6.978394];
% est4 = [-10.048975 6.9741158];
% 
% % q = [w,x,y,z];
% q1 = [0.9999725 0.00012627 0.007374176 0.00074221997];
% q2 = [0.999988 0.003298 0.0019476155 0.002845594];
% q3 = [0.9999919 -0.0009979428 0.003346454 0.00196472];
% q4 = [0.999933 0.003726658 0.01045648 0.002978124];
% 
% %eul = [yaw pitch roll]
% eul1 = quat2eul(q1);
% eul2 = quat2eul(q2);
% eul3 = quat2eul(q3);
% eul4 = quat2eul(q4);
% 
% err1 = true1 - [est1(1) est1(2) eul1(1)];
% err2 = true2 - [est2(1) est2(2) eul2(1)];
% err3 = true3 - [est3(1) est3(2) eul3(1)];
% err4 = true4 - [est4(1) est4(2) eul4(1)];
% 
% err = err1 + err2 + err3 + err4;
% 
% -err/4