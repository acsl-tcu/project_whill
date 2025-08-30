function [collision_flag] = myplotResult(DATAPath)
    %% Settings
    warning('off','all');
    
    if nargin == 1
        DATAdir = DATAPath;
    else
        clear variables; close all; clc;
        tmp     = matlab.desktop.editor.getActive;
        DATAdir = cd(fileparts(tmp.Filename));
    end
    
    File  = strcat(DATAdir, '/state.mat');
    load(File, 'DATA');
    
    File  = strcat(DATAdir, '/userLocal.mat');
    load(File, 'USER');
    
    File  = strcat(DATAdir, '/settings.mat');
    load(File, 'NamedConst');
    
    Outputdir = strcat(DATAdir,'/result');
    mkdir(Outputdir,'jpeg');
    mkdir(Outputdir,'eps');
    mkdir(Outputdir,'fig');
    mkdir(Outputdir,'png');
    mkdir(Outputdir,'pdf');
    mkdir(Outputdir,'video');
    mkdir(strcat(Outputdir,'/video'),'snapshot');
    
    % starttime = min(DATA.T);
    % endtime   = max(DATA.T);
    % Size      = length(DATA.T);
    % Interval  = 25;
    % Count     = 1;

    % ptCloud = USER.ObsPC;

    DATA.X      = USER.Position_X;
    DATA.Y      = USER.Position_Y;
    DATA.yaw    = USER.Position_yaw;
    DATA.X(end+1)   = USER.Position_X(end);
    DATA.Y(end+1)   = USER.Position_Y(end);
    DATA.yaw(end+1) = USER.Position_yaw(end);


    %% Path
%     fig = figure(1);
%     ax = gca;
% 
%     plot(DATA.X,DATA.Y,'LineWidth',1.75);hold on
% 
%     s = 0;
%     for count = 2:length(DATA.T)-1
%         if DATA.T(count) > 1.0*s
%             x = DATA.X(count);
%             y = DATA.Y(count);
%             u = 0.7*cos(DATA.yaw(count));
%             v = 0.7*sin(DATA.yaw(count)); 
%             q = quiver(x,y,u,v,'LineWidth',1.75);
%             q.Color = [255,94,25]/255;
%             q.Marker = 'o';
%             q.MaxHeadSize = 2.;
%             Wheel_posi = [x y];
%             viscircles(Wheel_posi,NamedConst.r_wheel,'LineWidth',0.1,'Color',[255,94,25]/255);
%             obs = [USER.obstacle{count-1}.x;USER.obstacle{count-1}.y]';
%             for num = 1:size(obs,1)
%                 plot(obs(num,1),obs(num,2),'ko','MarkerSize',3,'LineWidth',3);hold on;
%                 Obs_posi = [obs(num,1),obs(num,2)];
%                 if(USER.obstacle{count-1}(1,num).size<0)
%                         USER.obstacle{count-1}(1,num).size = 0;
%                 end
% %                 viscircles(Obs_posi,NamedConst.obsSetup.ObstacleSize(num),'LineWidth',0.1,'Color','black');
%                 viscircles(Obs_posi,USER.obstacle{count-1}(1,num).size,'LineWidth',0.1,'Color','black');
% %                 viscircles(Obs_posi,0.5,'LineWidth',0.1,'Color','black');
%             end
%             s = s + 1;
%         end
%     end
%     ax.YLim = [-4 8];
%     ax.XLim = [-10 10];
%     grid minor;
%     set(gca,'FontSize',20,'FontName','Times');
%     xlabel('$$X$$(m)','Interpreter', 'Latex');
%     ylabel('$$Y$$(m)','Interpreter', 'Latex');
%     fig.Units = 'normalized';
%     lgn = legend({'Wheelchair','Reference','Obstacle'},'Location','best');
%     lgn.NumColumns = 3;
%     Xleng = ax.XLim(1,2) - ax.XLim(1,1);
%     Yleng = ax.YLim(1,2) - ax.YLim(1,1);
%     pbaspect([Xleng,Yleng,1]);
%     fig.Position = [0.253645833333333,0.215740740740741,0.5,0.5];
%     saveas(gcf,strcat(Outputdir,'/eps/Path'),'epsc');
%     savefig(gcf,strcat(Outputdir,'/fig/Path'),'compact');
%     saveas(gcf,strcat(Outputdir,'/png/Path'),'png');
    %%

% Path_2
    a1 = NamedConst.wheel_len_rear;
    a2 = NamedConst.wheel_len_front;
    b  = NamedConst.wheel_width;
    right_rear  = [DATA.X-sqrt(a1^2+b^2).*sin( atan(a1/b)+DATA.yaw) DATA.Y+sqrt(a1^2+b^2).*cos( atan(a1/b)+DATA.yaw)];
    right_front = [DATA.X+sqrt(a2^2+b^2).*cos( atan(b/a2)+DATA.yaw) DATA.Y+sqrt(a2^2+b^2).*sin( atan(b/a2)+DATA.yaw)];
    left_rear   = [DATA.X-sqrt(a1^2+b^2).*cos(-atan(b/a1)-DATA.yaw) DATA.Y+sqrt(a1^2+b^2).*sin(-atan(b/a1)-DATA.yaw)];
    left_front  = [DATA.X+sqrt(a2^2+b^2).*cos(-atan(b/a2)+DATA.yaw) DATA.Y+sqrt(a2^2+b^2).*sin(-atan(b/a2)+DATA.yaw)];

    WheelchairSAM = polyshape([right_rear(1,:);right_front(1,:);left_front(1,:);left_rear(1,:)]);
    for count = 2:length(DATA.T)
        wheelchair = polyshape([right_rear(count,:);right_front(count,:);left_front(count,:);left_rear(count,:)]);
        WheelchairSAM = union(WheelchairSAM,wheelchair);
    end
    Interval = 10;
    

    PlotCount(1) = 2;
    count = 1;
    for i = 1:length(DATA.T)
        if DATA.T(i)>count*Interval
            count = count+1;
            PlotCount(count) = i;
        end
    end
    PlotCount(count+1) = length(DATA.T);

    figure(2);
    ax = gca;
    plot(WheelchairSAM,'FaceColor','#0072BD','EdgeColor', 'none'); hold on;
    plot(DATA.X,DATA.Y,'b','LineWidth',2); hold on
    for i = 1:length(PlotCount)
        count = PlotCount(i);
        if isfield(USER, 'AllTracks') && length(USER.AllTracks) >= count-1 && ~isempty(USER.AllTracks(count-1).xhat{1, 1})
            obs = USER.AllTracks(count-1).xhat{1, 1};
            if size(obs,2)>0
                scatter(obs(1,:),obs(2,:),6^2,'MarkerEdgeColor','r','LineWidth',1.75); hold on;
            end
            for num = 1:size(obs,2)
                %--capsule----------------------------
                x=obs(1,num);
                y=obs(2,num);
                th=obs(3,num);
                a=obs(5,num);
                b=obs(6,num);
                plot(CapuselShape(x,y,th,a,b),'FaceColor', 'none', 'EdgeColor','r','LineWidth',2); hold on;
                %-------------------------------------
            end
        end
        wheelchair = polyshape([right_rear(count,:);right_front(count,:);left_front(count,:);left_rear(count,:)]);
        plot(wheelchair,'FaceAlpha',0,'EdgeColor','k','LineWidth',2); hold on;
        quiver(DATA.X(count),DATA.Y(count),0.7*cos(DATA.yaw(count)),0.7*sin(DATA.yaw(count)),'LineWidth',1.75,'Color', [255,94,25]/255,'Marker','o','MarkerSize',6,'MaxHeadSize',2.); hold on;
    end

    set(gcf, 'Color', 'w');
    set(gca,'FontSize',20,'FontName','Times');
    xlabel('$$X$$(m)','Interpreter', 'Latex','FontSize',20);
    ylabel('$$Y$$(m)','Interpreter', 'Latex','FontSize',20);
    axis equal
    grid on
    box on;  % 枠線を表示
    ax.YLim = [-1.5 1.5];
    % % ax.YLim = [y-4 y+4];
    ax.XLim = [-1 10];

    % 軸範囲取得
    xRange = diff(xlim);
    yRange = diff(ylim);
    % 画面サイズ取得
    screenSize = get(0, 'ScreenSize'); % [left, bottom, width, height]
    figureWidth = screenSize(3) * 0.9; % 横幅90%
    figureHeight = screenSize(4) * 0.9; % 縦幅90%
    % 図サイズ設定（縦横比調整）
    if xRange > yRange
        scaleFactor = figureWidth / xRange;
        adjustedHeight = yRange * scaleFactor;
        set(gcf, 'Position', [50, 50, figureWidth, adjustedHeight]);
    else
        scaleFactor = figureHeight / yRange;
        adjustedWidth = xRange * scaleFactor;
        set(gcf, 'Position', [50, 50, adjustedWidth, figureHeight]);
    end

    % saveas(gcf,strcat(Outputdir,'/eps/Path_2'),'epsc');
    savefig(gcf,strcat(Outputdir,'/fig/Path_2'));
    saveas(gcf,strcat(Outputdir,'/png/Path_2'),'png');
    exportgraphics(gcf, strcat(Outputdir,'/pdf/Path_2.pdf'), 'ContentType', 'vector')

% 歩行者点群クラスタリング動画---------------------------------------------------------------------------

    % if ispc
    %     writerObj = VideoWriter(strcat(Outputdir,'/video/animation_cluster'),'MPEG-4');
    % else
    %     writerObj = VideoWriter(strcat(Outputdir,'/video/animation_cluster'));
    % end
    % open(writerObj)
    % 
    % for count = 2:length(DATA.T)-2
    %     figure(99)
    %     numClusters = USER.numClusters{count,1}+1;
    %     labelColorIndex = USER.labels{count,1}+1;
    %     ptCloud_all = pointCloud(readXYZ(USER.RawData(count).ptCloud));
    %     ptCloudLocation_obs = ptCloud_all.Location(USER.obstacleIndices{count, 1},:);
    %     if USER.obstacleIndices{count, 1} ~= 0
    %         pcshow(ptCloudLocation_obs,labelColorIndex,'MarkerSize',50)
    % 
    %         colormap([hsv();[1 1 1]])
    %     end
    %     title('Point Cloud Clusters')
    %     view(0,90)
    %     xlim([-10 10])
    %     ylim([-10 10])
    %     ax = gca;
    %     ax.XColor = 'white';
    %     ax.YColor = 'white';
    %     refreshdata(gcf);
    %     %-- get frames as images --%
    %     frame = getframe(gcf);
    %     %- Add frame to video object -%
    %     writeVideo(writerObj, frame);
    %     drawnow limitrate;
    %     hold off;  
    % end
    % close(writerObj);
    
    %% collison flag
%     figure
%     dis = zeros(length(DATA.T)-1,NamedConst.obsSetup.ObstacleNum);
%     for count = 2:length(DATA.T)
% %         obs = [USER.obstacle{count}.x;USER.obstacle{count}.y]';
% %         if count == 1
% %             dis(count,:) = [(((DATA.X(count) - NamedConst.obsSetup.InitialPosition(:,1)).^2) + ((DATA.Y(count) - NamedConst.obsSetup.InitialPosition(:,2)).^2)).^(1/2)]';
% %         else
%             obs = [USER.obstacle{count-1}.x;USER.obstacle{count-1}.y]';
%             for num = 1:size(obs,1)
%                 dis(count-1,num) = (((DATA.X(count) - obs(num,1)).^2) + ((DATA.Y(count) - obs(num,2)).^2)).^(1/2);
%             end
% %         end
%     end
%     T = (starttime:NamedConst.dt:endtime-NamedConst.dt)';
%     plot(DATA.T(1:end-1),dis,'o','MarkerSize',3,'LineWidth',3);hold on;
%     for num = 1:NamedConst.obsSetup.ObstacleNum
%         yline(NamedConst.r_wheel+NamedConst.obsSetup.ObstacleSize(num),'--','LineWidth',3);
%     end
%     grid on;
%     ylim([0 6])
%     % ylim([0.995 1.005])
%     % xlim([8. 9])
%     set(gca,'FontSize',18,'FontName','Times');
%     xlabel('Time[s]','Interpreter', 'Latex');
%     ylabel('Distance (m)','Interpreter', 'Latex');
%     saveas(gcf,strcat(Outputdir,'/eps/distance_obs2'),'epsc');
%     savefig(gcf,strcat(Outputdir,'/fig/distance_obs2'),'compact');
%     saveas(gcf,strcat(Outputdir,'/png/distance_obs2'),'png');
%     disp(min(dis));

%---------------------------------------------------------------------------------------------------------------------
    
    if NamedConst.animation(2) == 0
        Color_map = (169/255)*ones(30000,3);
        Color_map(1:10,:) = jet(10);

        a1 = NamedConst.wheel_len_rear;
        a2 = NamedConst.wheel_len_front;
        b  = NamedConst.wheel_width;
        
        % フレーム調整 ----------------------------
        dt=zeros(length(DATA.T),1);
        for i=1:length(DATA.T)-1
            dt(i)=DATA.T(i+1)-DATA.T(i);
        end
        num_frame=0;
        %-----------------------------------------

        if ispc
            writerObj=VideoWriter(strcat(Outputdir,'/video/animation_v2_2'),'MPEG-4');
        else
            writerObj=VideoWriter(strcat(Outputdir,'/video/animation_v2_2'));
        end
        % フレーム調整 ----------------------------
        % writerObj.FrameRate = 60; % フレームレートの設定
        writerObj.FrameRate = 1/0.05; % フレームレートの設定
        %-----------------------------------------

        open(writerObj);
        
        % AspectRatio =[4 2]; % 横　縦

        fig999 = figure(99);
        pause(0.05)
        fig999.Units = 'normalized';
        % fig999.Visible = 'off';
        % fig999.Position = [0,0,800*AspectRatio(1) 800*AspectRatio(2)];
        fig999.Position = [0.17143,0.2074,0.5,0.5102];
        
        %
        right_rear  = [DATA.X-sqrt(a1^2+b^2).*sin( atan(a1/b)+DATA.yaw) DATA.Y+sqrt(a1^2+b^2).*cos( atan(a1/b)+DATA.yaw)];
        right_front = [DATA.X+sqrt(a2^2+b^2).*cos( atan(b/a2)+DATA.yaw) DATA.Y+sqrt(a2^2+b^2).*sin( atan(b/a2)+DATA.yaw)];
        left_rear   = [DATA.X-sqrt(a1^2+b^2).*cos(-atan(b/a1)-DATA.yaw) DATA.Y+sqrt(a1^2+b^2).*sin(-atan(b/a1)-DATA.yaw)];
        left_front  = [DATA.X+sqrt(a2^2+b^2).*cos(-atan(b/a2)+DATA.yaw) DATA.Y+sqrt(a2^2+b^2).*sin(-atan(b/a2)+DATA.yaw)];
        
        WheelchairSAM = polyshape([right_rear(1,:);right_front(1,:);left_front(1,:);left_rear(1,:)]);
        % ---plotの設定----------------------------------------
        plotGridMapColor(NamedConst.map); hold on
        pWall = NaN(6,1);
        pWallcost = NaN(6,1);
        for i=1:6
            pWall(i)  = plot(polyshape(), 'FaceColor', 'red', 'EdgeColor','red','LineWidth',1); hold on;
            pWallcost(i)  = plot(polyshape(), 'FaceColor', 'none', 'EdgeColor',[1, 0.5, 0],'LineWidth',1); hold on;
        end
        pRemovedSample = NaN(NamedConst.NP,1);
        for j = 1:NamedConst.NP
            pRemovedSample(j) = plot(NaN,NaN,'Color',[0.7 0.7 0.7],'LineWidth',1); hold on;
        end
        plot(NamedConst.waypoint(:,1),NamedConst.waypoint(:,2),'k--o','LineWidth',1 ); hold on;

        pWheelchairSAM =plot(polyshape(),'FaceColor','r','FaceAlpha',0.2,'EdgeColor', 'none'); hold on;
        pWheelchair = plot(polyshape(),'FaceColor','#0072BD'); hold on;
        pAngle = quiver(NaN,NaN,NaN,NaN,'LineWidth',1.75,'Color', [255,94,25]/255,'Marker','o','MarkerSize',6,'MaxHeadSize',2.); hold on;
        pRight_rea   = plot(NaN,NaN,'-','Color','k','LineWidth',1); hold on;
        pRight_front = plot(NaN,NaN,'-','Color','k','LineWidth',1); hold on;
        pLeft_rear   = plot(NaN,NaN,'-','Color','k','LineWidth',1); hold on;
        pLeft_front  = plot(NaN,NaN,'-','Color','k','LineWidth',1); hold on;
        pObsP = scatter(NaN,NaN,6^2,'MarkerEdgeColor','r','LineWidth',1.75); hold on;
        pObs = NaN(30,1);
        pObsM = NaN(30,1);
        pObsH = NaN(30,1);
        for num = 1:30
            pObs(num)  = plot(polyshape(), 'FaceColor', 'none', 'EdgeColor','r','LineWidth',2); hold on;
            pObsM(num) = plot(polyshape(), 'FaceColor', 'none', 'EdgeColor',[1, 0.5, 0],'LineWidth',2); hold on;
            pObsH(num) = plot(NaN,NaN,'-','Color','m','LineWidth',1.5); hold on;
        end
        pRemovedPt = scatter(NaN,NaN,10,'filled', 'MarkerFaceColor', 'b','MarkerFaceAlpha', 0.2);hold on;
       
        pBest2 = plot(NaN,NaN,'Color','k','LineWidth',3); hold on;
        pBest = plot(NaN,NaN,'Color','g','LineWidth',2); hold on;
        % pBest = plot(NaN,NaN,'Marker','o','Color','g','LineWidth',2); hold on;
        % ----------------------------------------------------

        ax = gca;
        % ax.OuterPosition = [0.0,0.0,1.15,1.];
        % ax.Position = [0.08,0.14,0.89,0.778];
        set(gcf, 'Color', 'w');
        set(gca,'FontSize',20,'FontName','Times');
        xlabel('$$X$$(m)','Interpreter', 'Latex','FontSize',20);
        ylabel('$$Y$$(m)','Interpreter', 'Latex','FontSize',20);
        axis equal
        grid on
        box on  % 枠線を表示

        time = text(NaN,NaN,'','FontSize',20,'Interpreter', 'Latex','BackgroundColor',[1 1 1],'EdgeColor',[0 0 0]);

        for count = 2:length(DATA.T)-2
        % for count = 2:10
            % --Plot wall------------------------------------
            % for i = 1:4
            %     if wall(1,i)==Inf
            %         wall(1,i) = 1000;
            %     elseif wall(1,i)==-Inf
            %         wall(1,i) = -1000;
            %     end
            % end
            % set(pWall, 'XData', [wall(1,1),wall(1,2),wall(1,2),wall(1,1),wall(1,1)], 'YData',[wall(1,3),wall(1,3),wall(1,4),wall(1,4),wall(1,3)]);
            
            % wall1 = wall(USER.target_n(count-1)-1,:);
            % wall2 = wall(USER.target_n(count-1)  ,:);
            % wall3 = wall(USER.target_n(count-1)+1,:);
            % polywall1 = polyshape([wall1(1),wall1(2),wall1(2),wall1(1)],[wall1(3),wall1(3),wall1(4),wall1(4)]);
            % polywall2 = polyshape([wall2(1),wall2(2),wall2(2),wall2(1)],[wall2(3),wall2(3),wall2(4),wall2(4)]);
            % polywall3 = polyshape([wall3(1),wall3(2),wall3(2),wall3(1)],[wall3(3),wall3(3),wall3(4),wall3(4)]);
            % set(pWall,'Shape',union([polywall1,polywall2,polywall3]));
            

            % if NamedConst.selectZone(USER.target_n(count-1)) == NamedConst.selectZone(USER.target_n(count))  && count==1
            % else
            %     NoEntryZone=NamedConst.NoEntryZone(:,:,NamedConst.selectZone(USER.target_n(count)));
            %     d= NamedConst.wall_threshold;
            %     for i = 1:size(NoEntryZone,1)
            %         set(pWall(i),'Shape',polyshape())
            %         set(pWallcost(i),'Shape',polyshape())
            %         if NoEntryZone(i,:) == [inf -inf inf -inf]
            %             break
            %         end
            %         set(pWall(i),'Shape' ,polyshape([NoEntryZone(i,1),NoEntryZone(i,2),NoEntryZone(i,2),NoEntryZone(i,1)],[NoEntryZone(i,3),NoEntryZone(i,3),NoEntryZone(i,4),NoEntryZone(i,4)]))
            %         set(pWallcost(i),'Shape' ,polyshape([NoEntryZone(i,1)-d,NoEntryZone(i,2)+d,NoEntryZone(i,2)+d,NoEntryZone(i,1)-d],[NoEntryZone(i,3)-d,NoEntryZone(i,3)-d,NoEntryZone(i,4)+d,NoEntryZone(i,4)+d]))
            % 
            %     end
            % end

            %-------------------------------------------------
            % if ~isempty(USER.confirmd{count,1})
            %     ShowErrorEllipse2(USER.covpredict{count,1},USER.statpredict{count,1});
            % end
            %--Horizon of Sample------------------------------------------
            if count ~= 2 && size(USER.removed(count-1).px,3)<size(USER.removed(count-2).px,3)
                for j = size(USER.removed(count-1).px,3)+1:size(USER.removed(count-2).px,3)
                    set(pRemovedSample(j),'XData',NaN,'YData',NaN);
                end
            end
            for j = 1:size(USER.removed(count-1).px,3)
                % grey
                % set(pRemovedSample(j),'XData',USER.removed(count-1).px(1,:,j),'YData',USER.removed(count-1).px(2,:,j));
                % Colorful
                set(pRemovedSample(j),'XData',USER.removed(count-1).px(1,:,j),'YData',USER.removed(count-1).px(2,:,j),'Color',[Color_map(ceil(USER.removed(count-1).pw(1,j)),:),0.4]);
            end
            %---------------------------------------------------

            x = DATA.X(count);
            y = DATA.Y(count);
            % th = DATA.yaw(count);
            u = 0.7*cos(DATA.yaw(count));
            v = 0.7*sin(DATA.yaw(count)); 
            set(pAngle,'XData',x,'YData',y,'UData',u,'VData',v);

            % right_rear = [x-sqrt(a1^2+b^2)*sin(atan(a1/b)+th) y+sqrt(a1^2+b^2)*cos(atan(a1/b)+th)];
            % right_front = [x+sqrt(a2^2+b^2)*cos(atan(b/a2)+th) y+sqrt(a2^2+b^2)*sin(atan(b/a2)+th)];
            % left_rear = [x-sqrt(a1^2+b^2)*cos(-th-atan(b/a1)) y+sqrt(a1^2+b^2)*sin(-th-atan(b/a1))];
            % left_front = [x+sqrt(a2^2+b^2)*cos(th-atan(b/a2)) y+sqrt(a2^2+b^2)*sin(th-atan(b/a2))];
            
            wheelchair = [right_rear(count,:);right_front(count,:);left_front(count,:);left_rear(count,:)];
            
            % WheelchairSAM = union(WheelchairSAM, polyshape(wheelchair));
            % WheelchairSAM2 =  subtract(WheelchairSAM, polyshape(wheelchair));
            % set(pWheelchairSAM,'Shape', WheelchairSAM2);

            % set(pRight_rea,  'XData',right_rear(1:count,1), 'YData',right_rear(1:count,2));
            % set(pRight_front,'XData',right_front(1:count,1),'YData',right_front(1:count,2));
            % set(pLeft_rear,  'XData',left_rear(1:count,1),  'YData',left_rear(1:count,2));
            % set(pLeft_front, 'XData',left_front(1:count,1), 'YData',left_front(1:count,2));
            
            % set(pRemovedPt,'XData',ptCloud{count-1,1}(:,1)','YData',ptCloud{count-1,1}(:,2))';  
            set(pWheelchair,'Shape',polyshape(wheelchair));
            
           if isfield(USER, 'AllTracks') && length(USER.AllTracks) >= count-1 && ~isempty(USER.AllTracks(count-1).xhat{1, 1})
               obs = USER.AllTracks(count-1).xhat{1, 1};
           else
               obs = [];
           end
           
           if count ~= 2 && isfield(USER, 'AllTracks') && length(USER.AllTracks) >= count-2 && ~isempty(USER.AllTracks(count-2).xhat{1, 1}) && size(obs,2)<size(USER.AllTracks(count-2).xhat{1, 1},2)
               for num = size(obs,2)+1:size(USER.AllTracks(count-2).xhat{1, 1},2)
                   set(pObs(num),'Shape',polyshape())
                   set(pObsM(num),'Shape',polyshape())
                   set(pObsH(num),'XData',NaN,'YData',NaN)
               end
           end
           if size(obs,2) > 0
               set(pObsP,'XData',obs(1,:),'YData',obs(2,:));
           end
           for num = 1:size(obs,2)
                   %--capsule----------------------------
                   x_obs   = obs(1,num);
                   y_obs   = obs(2,num);
                   th_obs = obs(3,num);
                   a_obs   = obs(5,num);
                   b_obs   = obs(6,num);
                   set(pObs(num),'Shape',CapuselShape(x_obs,y_obs,th_obs,a_obs,b_obs))
                   if NamedConst.param_FPM.margin > 0
                       set(pObsM(num),'Shape',CapuselShape(x_obs,y_obs,th_obs,a_obs,b_obs+NamedConst.param_FPM.margin))
                   end
                   %-------------------------------------
           end
           for num = 1:size(obs,2)
               if isfield(USER, 'preobs') && length(USER.preobs) >= count-1 && ~isempty(USER.preobs{count-1,1})
                   ObsHorizon = zeros(6,NamedConst.K);
                   for k = 1:NamedConst.K
                       ObsHorizon(:,k) = USER.preobs{count-1,1}(:,num,k);
                   end
                   set(pObsH(num),'XData',ObsHorizon(1,:),'YData',ObsHorizon(2,:))
               end
           end

            
            set(pBest,'XData',USER.uOpt{count-1}.u(1).x(1,:),'YData',USER.uOpt{count-1}.u(1).x(2,:));
            set(pBest2,'XData',USER.uOpt{count-1}.u(1).x(1,:),'YData',USER.uOpt{count-1}.u(1).x(2,:));
            % ax.XLim = [0 8];
            % ax.YLim = [-2 2];
            ax.YLim = [y-4 y+4];
            ax.XLim = [x-8 x+8];
            str = ['$$t =$$ ',num2str(DATA.T(count),'%.2f'),' s'];
            set(time,'String',str,'Position',[ax.XLim(1,1) + 0.2,ax.YLim(1,2) - 0.2,0])
            

            %-- get frames as images --%
            frame = getframe(fig999);
            % フレーム調整 -----------------------------
            while 1
                if num_frame*(1/writerObj.FrameRate)>DATA.T(count)
                    break
                end
                writeVideo(writerObj, frame);
                num_frame=num_frame+1;
            end
            %------------------------------------------
            

            % -- その時刻のフレームをPDFで保存-------------------------------------
            % ScreenShotTime = [3.43];
            % if any(ismember(round(DATA.T(count),2),ScreenShotTime))
            %     f = gcf;
            %     f.RendererMode = 'manual';
            %     f.Renderer = 'painters';
            %     FileName = num2str(round(DATA.T(count),2));
            %     exportgraphics(gcf, strcat(Outputdir,'/video/snapshot/result_',FileName,'s.pdf'), 'ContentType', 'vector')
            % end
            % ----------------------------------------------------------------------
            
            drawnow limitrate;
        end
        close(writerObj);
    end

    % -- その時の点群を表示 --------------------------------------------------------
    % LookTime = 27.06;
    % count = find(round(DATA.T,2)==LookTime,1);
    % LookPc = USER.ptCloudLimit{count,1};
    % figure(20);
    % pcshow(LookPc,'MarkerSize', 30)
    % axis equal
    % xlim([LookPc.XLimits(1)-0.2 LookPc.XLimits(2)+0.2])
    % ylim([LookPc.YLimits(1)-0.2 LookPc.YLimits(2)+0.2])
    % zlim([0 LookPc.ZLimits(2)+0.2])
    % set(gcf, 'Color', 'w');
    % set(gca, 'Color', 'w', 'XColor', 'k', 'YColor', 'k', 'ZColor', 'k');
    % set(get(gca, 'Title'), 'Color', 'k');
    % set(get(gca, 'XLabel'), 'Color', 'k');
    % set(get(gca, 'YLabel'), 'Color', 'k');
    % set(get(gca, 'ZLabel'), 'Color', 'k');
    % ax = gca; % 現在の軸ハンドルを取得
    % ax.Projection = 'orthographic'; % 正投影法
    % ---------------------------------------------------------------------------

end

%% FUNCTION
function [fig, ax, lgd] = setFigure(Name, Count)
	figure(Count)
    fig = gcf;
    fig.Name = Name;
    fig.Color= [1., 1., 1.];
    ax  = gca;
    ax.FontSize = 16;
    ax.Box      = 'on';
    ax.XGrid    = 'on';
    ax.YGrid    = 'on';
    ax.NextPlot = 'add';
    ax.XLabel.Interpreter  = 'Latex';
    ax.YLabel.Interpreter  = 'Latex';
    lgd = legend;
    lgd.FontSize    = 16;
    lgd.Location    = 'best';
    lgd.Interpreter = 'Latex';
end
function ret = saveFigure(Name, Count, Outputdir)
	hold off;
	saveas(gcf,strcat(Outputdir,strcat('/eps/',Name)),'epsc');
    saveas(gcf,strcat(Outputdir,strcat('/jpeg/',Name)),'jpeg');
	savefig(gcf,strcat(Outputdir,strcat('/fig/',Name)));
	ret = Count + 1;
end
function shape = CapuselShape(x,y,th,a,b)
    %% plotObstacle(x,y,th,a,b,color)
    % (x,y) 図形の中心
    % th [rad] 回転角度
    
    % 図形のサイズ
    width = b*2;
    height =(a+b)*2;
    % 角の丸みの半径
    cornerRadius = width / 2;
    % 半円部分を作成
    theta = linspace(0, pi, 50);
    halfCircleX = cornerRadius * cos(theta);
    halfCircleY = cornerRadius * sin(theta);
    % 上半分の半円
    topHalfCircleX = halfCircleX;
    topHalfCircleY = halfCircleY+ (height - width) / 2;
    % 下半分の半円
    bottomHalfCircleX = halfCircleX ;
    bottomHalfCircleY = -halfCircleY- (height - width) / 2;
    % 図形全体の座標を結合
    shapeX = [bottomHalfCircleX, fliplr(topHalfCircleX),bottomHalfCircleX(1)];
    shapeY = [bottomHalfCircleY, fliplr(topHalfCircleY),bottomHalfCircleY(1)];
    % 回転行列を作成
    R = [cos(th), -sin(th); sin(th), cos(th)];
    % 図形全体を回転
    rotatedShape = R * [shapeX; shapeY];
    rotatedShape = [rotatedShape(1,:)+x;rotatedShape(2,:)+y];
    
    shape=polyshape(rotatedShape');
    
end