function [collision_flag] = plotResult(DATAPath)
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
    
    Outputdir = strcat(DATAdir,'/result');
    mkdir(Outputdir,'jpeg');
    mkdir(Outputdir,'eps');
    mkdir(Outputdir,'fig');
    
    starttime = min(DATA.T);
    endtime   = max(DATA.T);
    Size      = length(DATA.T);
    Interval  = 25;
    Count     = 1;
    
    %%	State
    X = cell2mat({USER.RawData.X})';
    Y = cell2mat({USER.RawData.Y})';
    yaw = cell2mat({USER.RawData.yaw})';
    X2 = cell2mat({USER.RawData.PrimeX})';
    Y2 = cell2mat({USER.RawData.PrimeY})';
    yaw2 = cell2mat({USER.RawData.Primeyaw})';
    T = cell2mat({USER.RawData.T});
	[~, ax, lgd] = setFigure('State',Count);
    Pt= [X,  Y, yaw];
    Pt2=[X2,  Y2, yaw2];
    p = plot(T, Pt);
    p2 = plot(T, Pt2);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p2);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p2);

    ax.XLim    = [min(T), max(T)];
    ax.XLabel.String = 'Time [s]';
    ax.YLabel.String = 'State';
    
    lgd.NumColumns = 2;
    lgd.FontSize = 13;
    lgd.String     = {'$$x$$(estimation)','$$y$$(estimation)','$$\theta$$(estimation)','$$x$$(Gazebo)','$$y$$(Gazebo)','$$\theta$$(Gazebo)'};
	Count = saveFigure('state', Count, Outputdir);
    
    %% Position
	[~, ax, lgd] = setFigure('Position',Count);
    p = plot(X, Y);
    p2 = plot(X2,Y2);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p);
    arrayfun(@(x) set(x,'Color', 'magenta'),p);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p2);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p2);
    arrayfun(@(x) set(x,'Color', 'blue'),p2);
    
    for M = 1:Interval:length(T)
        
		q = quiver(X(M),Y(M),0.25*cos(yaw(M)),0.25*sin(yaw(M)));
        q.LineWidth = 1.75;
		q.Color = [255,94,25]/255;
		q.Marker = 'o';
		q.MaxHeadSize = 2.;
        q.Annotation.LegendInformation.IconDisplayStyle = 'off';
        
        q2 = quiver(X2(M),Y2(M),0.25*cos(yaw2(M)),0.25*sin(yaw2(M)));
        q2.LineWidth = 1.75;
		q2.Color = [0,191,255]/255;
		q2.Marker = 'o';
		q2.MaxHeadSize = 2.;
        q2.Annotation.LegendInformation.IconDisplayStyle = 'off';
    end

    ax.XLabel.String = '$$X$$[m]';
    ax.YLabel.String = '$$Y$$[m]';
%     lgd.Orientation  = 'horizontal';
    lgd.String       = {'Trajectory(estimation)','Trajectory(Gazebo)'};
    axis equal;
	Count = saveFigure('position',Count, Outputdir);
    
    %% Angular velocity
	[~, ax, lgd] = setFigure('Angular velocity',Count);
    p = plot(DATA.T, DATA.Omega);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p);
    
    ax.XLim    = [starttime, endtime];
    ax.XLabel.String = 'Time [s]';
    ax.YLabel.String = 'Input $$\omega$$ [m/s]';
    lgd.String = {'$$\omega_{\rm{R}}$$','$$\omega_{\rm{L}}$$'};  
	Count = saveFigure('angular_velocity',Count, Outputdir);
    
    %% Input
	[~, ax, lgd] = setFigure('Input',Count);
    p = plot(DATA.T, DATA.V);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p);
    
    ax.XLim    = [starttime, endtime];
    ax.XLabel.String = 'Time [s]';
    ax.YLabel.String = 'Input $$V$$ [m/s], $$\omega$$ [red/s]';
    lgd.String = {'$$V$$','$$\omega$$'};  
	Count = saveFigure('input',Count, Outputdir);

    %% Computation time
	[~, ax, lgd] = setFigure('Computation time',Count);
    time_cycle = DATA.T(2:end) - DATA.T(1:end-1);
    p = plot(DATA.T, DATA.ComputationTime);
    p2 = plot(DATA.T(2:end), time_cycle);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p2);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p2);
    
    ax.XLim    = [starttime, endtime];
    ax.XLabel.String = 'Time [s]';
    ax.YLabel.String = 'Computation Time[s]';
%    lgd.Visible      = 'off';
    lgd.String = {'Controller','Whole system'}; 
    Count = saveFigure('computation_Time',Count, Outputdir);
    fprintf('mean: %5.4f [s] max: %5.4f [s] min: %5.4f [s] median: %5.4f [s]\n',mean(DATA.ComputationTime),max(DATA.ComputationTime),min(DATA.ComputationTime),median(DATA.ComputationTime))

    %% Evalation value
    [~, ax, lgd] = setFigure('Evaluation value',Count);
    p = plot(USER.TimeLocal, USER.BestCost);
%     fvaltemp = cell2mat(USER.fval);
    p2 = plot(USER.TimeLocal, USER.fval);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p);
    arrayfun(@(x) set(x,'LineWidth', 1.75), p2);
    arrayfun(@(x) set(x,'LineStyle', '-'),  p2);
    
    ax.XLim    = [starttime, endtime];
    ax.XLabel.String = 'Time [s]';
    ax.YLabel.String = 'Evalation value $$J$$';
    lgd.String = {'$$J_\mathrm{best}$$','$$J_\mathrm{cluster}$$'};  
	Count = saveFigure('Evalation_value',Count, Outputdir);
    
    %% collison flag
    collision_flag = false;
    if min(USER.Vinit) < 0.5
        collision_flag = true;
    end
    
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
	savefig(gcf,strcat(Outputdir,strcat('/fig/',Name)),'compact');
	ret = Count + 1;
end