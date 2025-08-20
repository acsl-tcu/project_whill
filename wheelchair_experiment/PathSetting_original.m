function [waypoints, selectZone,NoEntryZone,ZoneNum,V_ref]=PathSetting
    % 経路のセッティング
    % waypoints : 通過する点
    % NoEntryZone : 進入禁止領域 [Xmin,Xmax,Ymin,Ymax]*領域数*グループ数
    % selectZone : waypointのインデックスに対して何番目の進入禁止領域のグループを選択するのか
    % V_ref :

    NoEntryZone = inf(3,4,10).*[1 -1 1 -1];

    %% ver.1 L字
   %  waypoints = [5 0
   %                        9.0000         0
   %  9.5000         0
   %  9.7500    0.0670
   %  9.9330    0.2500
   % 10.0000    0.5000
   % 10.0000    1.0000
   %               10 2
   %               10 5
   %               10 100];
   % 
   %  waypoints(:,[1 2]) = waypoints(:,[2 1]);
   % 
   %  % NoEntryZone(1:3,:,1) = [-2 11 -3 -0.8
   %  %                       -2 9.35 0.8 10
   %  %                       10.65 12 0.8 10];
   % 
   %  selectZone=ones(size(waypoints,1),1);
   % 
   %  V_ref = zeros(size(waypoints,1),1)+0.5;

    %% ver.2  10号館4階_模擬_縮小
    % waypoints =[  0.00, -1.80
    %             -14.20, -1.80
    %             -15.20, -1.80
    %             -15.70, -1.30
    %             -15.70, -0.30
    %             -15.70,  0.30  %
    %             -15.70,  1.30
    %             -15.20,  1.80
    %             -14.20,  1.80
    %               9.15,  1.80  %
    %              10.15,  1.80
    %              10.65,  2.30
    %              10.65,  2.80
    %              10.65, 20.00
    %              10.65, 90.00];
    % 
    % NoEntryZone(1:3,:,1)=[-15.00, 11.30, -1.00,  1.00
    %                       -18.00, 10.00, -4.00, -2.60
    %                       -18.00,-16.40, -2.60,  2.60];
    % 
    % NoEntryZone(1:3,:,2)=[-15.00, 11.30, -1.00,  1.00
    %                       -18.00, 10.00,  2.60,  4.00
    %                       -18.00,-16.40, -2.60,  2.60];
    % 
    % NoEntryZone(1:3,:,3)=[-15.00, 11.30, -1.00,  1.00
    %                       -18.00, 10.00,  2.60,  4.00
    %                        11.30, 13.00, -1.00,  4.00];
    % 
    % selectZone = [1;1;1;1;1;2;2;2;2;2;3;3;3;3;3];
    % 
    % V_ref = [0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5];

    %%  直線
    % waypoints =[  0.00, 0.00
    %               2.00, 0.00
    %               4.00, 0.00
    %               6.00, 0.00
    %               8.00, 0.00
    %              10.00, 0.00
    %              12.00, 0.00
    %              14.00, 0.00
    %              16.00, 0.00
    %              18.00, 0.00
    %              20.00, 0.00];

    % waypoints =[  0.00, 0.00
    %              20.00, 0.00];


    % % NoEntryZone(1:2,:,1)=[-20, 20,  -3.00,  -0.75
    % %                       -20, 20,   0.75,   3.00];

    % selectZone=ones(size(waypoints,1),1);
    % 
    % V_ref = zeros(size(waypoints,1),1)+1;

    %%  直線停止
    % waypoints =[  0.00, 0.00
    %               2.00, 0.00
    %               4.00, 0.00
    %               6.00, 0.00
    %               8.00, 0.00
    %               9.50, 0.00
    %               9.80, 0.00
    %               9.95, 0.00
    %              10.00, 0.00
    %              20.00, 0.00];
    % 
    % NoEntryZone(1:2,:,1)=[-20, 20,  -3.00,  -0.75
    %                       -20, 20,   0.75,   3.00];
    % 
    % selectZone=ones(size(waypoints,1),1);
    % 
    % V_ref = [0.5;0.5;0.5;0.5;0.5;0.25;0.1;0.05;0.00];
    % % V_ref = [0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.5;0.00;0.00];

    %% 10号館4階

    waypoints =[4.0000   -0.2000
                1.9100   -0.2000
               -0.1800   -0.2000%1
               -0.6800    0.3000%1
               -0.6800    2.1000
               -0.6800    3.9000
               -0.6800,   5.7000%2
                 -0.18,   6.2000%2
                1.8787    6.2000
                3.9373    6.2000
                5.9960    6.2000
                8.0547    6.2000
               10.1133    6.2000
               12.1720    6.2000
               14.2307    6.2000
               16.2893    6.2000
               18.3480    6.2000
               20.4067    6.2000
               22.4653    6.2000
               24.5240    6.2000
               26.5827    6.2000
               28.6413    6.2000
               30.7000,   6.2000%3
               31.2000,   6.7000%3
               31.2000,   7.8500
               31.2000,   9.0000%4
               31.7000,   9.5000%4
               33.0000,   9.5000
               34.0000,   9.5000
               34.2000,   9.5000
               38.0000,   9.5000];


    % 使ってない

    NoEntryZone(1:3,:,1)=[ -0.05, 38.00,  0.60,  5.40
                           -5.00, -1.40, -6.00, 12.00
                           -1.40, 38.00, -6.00, -1.00];

    NoEntryZone(1:3,:,2)=[ -0.05, 38.00,  0.60,  5.40
                           -5.00, -1.40, -6.00, 12.00
                           -1.40, 30.50,  7.00, 12.00];

    NoEntryZone(1:3,:,3)=[ -0.05, 38.00,  0.60,  5.40
                            31.8, 38.00,  5.40,  8.20
                           -1.40, 30.50,  7.00, 12.00];

    NoEntryZone(1:3,:,4)=[  30.5, 38.00, 10.70, 14.00
                            31.8, 38.00,  5.40,  8.20
                           -1.40, 30.50,  7.00, 12.00];

    selectZone=[1;1;1;1;1;1;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;2;3;3;3;4;4;4;4;4;4];
    %-----------------------------------------------------

    V_ref = zeros(size(waypoints,1),1)+0.5;
    V_ref(end-1)=0.2;
    V_ref(end)=0;
    %%
    % selectZone=ones(size(waypoints,1),1);

    ZoneNum=zeros(size(NoEntryZone,3),1);
    for i = 1:size(NoEntryZone,3)
        for k = 1:size(NoEntryZone,1)
            if NoEntryZone(k,:,i)==[inf -inf inf -inf]
                break
            else
                ZoneNum(i) =k;
            end
        end
    end
    
    for i = 1:size(NoEntryZone,3)
        if NoEntryZone(1,:,i)==[inf -inf inf -inf] 
            GrupuNum=i-1;
            break
        elseif i==size(NoEntryZone,3)
            GrupuNum=i-1;
            break
        end
    end

    %% check
    flag=0;
    for i=1:size(NoEntryZone,3)
        for j=1:ZoneNum(i)
            if NoEntryZone(j,1,i)>NoEntryZone(j,2,i) || NoEntryZone(j,3,i)>NoEntryZone(j,4,i)
                fprintf('NoEnttyZoneの(%d,:%d)が間違っている!!\n',j,i)
                flag=1;
            end
        end
    end

    if max(selectZone)>GrupuNum
        disp('selectZoneの値がNoEnttyZoneのグループ数を超えている!!')
        flag=1;
    end

    if flag==1
        return
    end

    
    %%  plot
    % close all
    %     for j=1:GrupuNum
    %          figure
    %         for i=1:ZoneNum(j)
    %             plot(polyshape([NoEntryZone(i,1,j),NoEntryZone(i,2,j),NoEntryZone(i,2,j),NoEntryZone(i,1,j)],[NoEntryZone(i,3,j),NoEntryZone(i,3,j),NoEntryZone(i,4,j),NoEntryZone(i,4,j)]),'FaceColor','r')
    %             hold on
    %             plot(waypoints(:,1)',waypoints(:,2)','k-o')
    %             hold on
    %             idx = selectZone ==j;
    %             scatter(waypoints(idx,1),waypoints(idx,2),'b','filled')
    %             hold on
    %         end
    %         axis equal
    %         grid on
    %     end
    %      figure
    %     for j=1:GrupuNum
    %         for i=1:ZoneNum(j)
    %             plot(polyshape([NoEntryZone(i,1,j),NoEntryZone(i,2,j),NoEntryZone(i,2,j),NoEntryZone(i,1,j)],[NoEntryZone(i,3,j),NoEntryZone(i,3,j),NoEntryZone(i,4,j),NoEntryZone(i,4,j)]),'FaceColor','r')
    %             hold on
    %         end
    %         plot(waypoints(:,1)',waypoints(:,2)','k-o')
    %         hold on
    %         axis equal
    %         grid on
    %     end
end