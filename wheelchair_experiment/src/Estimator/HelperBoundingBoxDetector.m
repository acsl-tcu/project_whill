classdef HelperBoundingBoxDetector < matlab.System %#codegen
% function [detections,obstacleIndices,groundIndices,croppedIndices,...
%     confirmedTracks, modelProbs,numClusters,labels] = HelperBoundingBoxDetector(ptCloudLocations,time,Plant)
    % HelperBoundingBoxDetector A helper class to segment the point cloud
    % into bounding box detections.
    % The step call to the object does the following things:
    %
    % 1. Removes point cloud outside the limits.
    % 2. From the survived point cloud, segments out ground
    % 3. From the obstacle point cloud, forms clusters and puts bounding
    %    box on each cluster.
    
   
    % Ground Segmentation Properties
    properties
        % GroundMaxDistance Maximum distance of point to the ground plane
        GroundMaxDistance = 0.2;
        % GroundReferenceVector Reference vector of ground plane
        GroundReferenceVector = [0 0 1];
        roi = [-inf,inf;-inf,inf;-inf,inf];
        % GroundMaxAngularDistance Maximum angular distance of point to reference vector
        GroundMaxAngularDistance = 5;

        % Ground segment by SMRF algorithm
        maxWindowRadius = 3;
        slopeThreshold = 0.15;
        elevationThreshold = 0.2;
        elevationScale = 0.25;
    end
    
    % Bounding box Segmentation properties
    properties
        % SegmentationMinDistance Distance threshold for segmentation
        SegmentationMinDistance = 0.5;
        % MinDetectionsPerCluster Minimum number of detections per cluster
        MinDetectionsPerCluster = 20;
        % MaxZDistanceCluster Maximum Z-coordinate of cluster
        MaxZDistanceCluster = 2;
        % MinZDistanceCluster Minimum Z-coordinate of cluster
        MinZDistanceCluster = -2;
    end
    
    % Ego vehicle radius to remove ego vehicle point cloud.
    properties
        % EgoVehicleRadius Radius of ego vehicle
        EgoVehicleRadius = 0;
    end
    
    properties
        % MeasurementNoise Measurement noise for the bounding box detection
%         MeasurementNoise = blkdiag(eye(3),eye(3));
        MeasurementNoise = 0.1 * eye(3);
    end
    
    properties (Nontunable)
        MeasurementParameters = struct.empty(0,1);
    end
    
    methods 
        function obj = HelperBoundingBoxDetector(varargin)
            setProperties(obj,nargin,varargin{:})
        end
    end
    
    methods (Access = protected)
        function [detBBoxes,survivedIndices,croppedIndices,obstacleIndices,groundIndices,numClusters,labels] = stepImpl(obj,currentPointCloud,time,Plant,wall,axis,SP)
            % [detBBoxes,survivedIndices,croppedIndices,numClusters,labels]

            % % Use remove ground
            % % Crop point cloud---------------------------------------------
            % [pcSurvived,survivedIndices,croppedIndices] = cropPointCloud2(currentPointCloud,Plant,wall,axis);
            % %--------------------------------------------------------------
            % % Remove ground plane------------------------------------------
            % [pcObstacles,obstacleIndices,groundIndices] = removeGroundPlane(pcSurvived,obj.maxWindowRadius, ...
            %     obj.elevationThreshold,obj.elevationScale,survivedIndices,currentPointCloud);                
            % %--------------------------------------------------------------
            % % Form clusters and get bounding boxes-------------------------
            % [detBBoxes,numClusters,labels] = getBoundingBoxes(pcObstacles,obj.SegmentationMinDistance, ...
            %     obj.MinDetectionsPerCluster,obj.MaxZDistanceCluster,obj.MinZDistanceCluster,Plant,time,SP);
            % %--------------------------------------------------------------

            % Nouse remove ground
            % Crop point cloud---------------------------------------------
            % [pcSurvived,survivedIndices,croppedIndices] = cropPointCloud(currentPointCloud,obj.XLimits,obj.YLimits,obj.ZLimits,obj.EgoVehicleRadius);
            [pcSurvived,survivedIndices,croppedIndices] = cropPointCloud2(currentPointCloud,Plant,wall,axis);
            obstacleIndices = survivedIndices;
            groundIndices = croppedIndices;
            % removeGroundPlane(pcSurvived,obj.GroundMaxDistance,obj.GroundReferenceVector,obj.GroundMaxAngularDistance,survivedIndices,obj.roi);
            %--------------------------------------------------------------
            % Form clusters and get bounding boxes-------------------------
            [detBBoxes,numClusters,labels] = getBoundingBoxes(pcSurvived,obj.SegmentationMinDistance, ...
            obj.MinDetectionsPerCluster,obj.MaxZDistanceCluster,obj.MinZDistanceCluster,Plant,time,SP);
            %--------------------------------------------------------------

            % Assemble detections------------------------------------------
            % if isempty(obj.MeasurementParameters)
            %     measParams = {};
            % else
            %     measParams = obj.MeasurementParameters;
            % end
            % bboxDets = assembleDetections(detBBoxes,obj.MeasurementNoise,measParams,time);
            %--------------------------------------------------------------
        end
    end
end
    
function detections = assembleDetections(bboxes,measNoise,measParams,time)
% This method assembles the detections in objectDetection format.
numBoxes = size(bboxes,2);
detections = cell(numBoxes,1);
    for i = 1:numBoxes
        detections{i} = objectDetection(time,cast(bboxes(:,i),'double'),...
            'MeasurementNoise',double(measNoise),'ObjectAttributes',struct,...
            'MeasurementParameters',measParams);
    end
end

function [bboxes,numClusters,labels] = getBoundingBoxes(ptCloud,minDistance,minDetsPerCluster,maxZDistance,minZDistance,Plant,time,SP)
    % This method fits bounding boxes on each cluster with some basic
    % rules.
    % Cluster must have atleast minDetsPerCluster points.
    % Its mean z must be between maxZDistance and minZDistance.
    % length, width and height are calculated using min and max from each
    % dimension.

    % PCAによる壁面などの形状クラスタを除去====================================
    % % クラスタリング
    % [labels,numClusters] = pcsegdist(ptCloud,minDistance);
    % pointData = ptCloud.Location;
    % % 主成分分析で歩行者クラスタを抽出
    % contributions = zeros(numClusters,3);
    % eig = zeros(numClusters,3);
    % isPedestrian = ones(numClusters,1);
    % for i = 1:numClusters
    %     thisPointData = pointData(labels == i,:);
    %     [~,~,latent,~,explained,~] = pca(thisPointData);
    %     if size(explained,1) == 3 % 寄与率が存在しない場合スキップ
    %         contributions(i,:) = explained(1:3)';
    %         eig(i,:) = latent(1:3)';
    %     end
    % 
    %     if any([any(explained < 0.1);any(latent > 0.6)])
    %         isPedestrian(i) = 0;
    %     end
    % end
    % pedestrianClusters = find(isPedestrian == 1); % 主成分の寄与率と固有値から歩行者を判別
    % % クラスタ数，ラベル共に歩行者クラスタ以外を無効化
    % pedestrianLabels = ismember(labels, pedestrianClusters);    
    % labels(~pedestrianLabels) = 0;
    % numClusters = length(pedestrianClusters);
    % % ラベル番号の振り直し
    % newLabels = zeros(size(labels));
    % currentLabel = 1;
    % for i = 1:length(pedestrianClusters)
    %     clusterIdx = pedestrianClusters(i);
    %     newLabels(labels == clusterIdx) = currentLabel;
    %     currentLabel = currentLabel + 1;
    % end
    % labels = newLabels;
    %========================================================================   


% ここがオリジナル．PCAが無いので疎点群でも取得可能-------------------------
    [labels,numClusters] = pcsegdist(ptCloud,minDistance);
    pointData = ptCloud.Location;
%--------------------------------------------------------------------------
    bboxes = nan(3,numClusters,'double');
    isValidCluster = false(1,numClusters);
    % M = mode(labels(:));

    for i = 1:numClusters
        thisPointData = pointData(labels == i,:);
        meanPoint = mean(thisPointData,1);
        if size(thisPointData,1) > minDetsPerCluster && ...
               meanPoint(3) < maxZDistance && meanPoint(3) > minZDistance %&& i ~= M
            xMin = min(thisPointData(:,1));
            xMax = max(thisPointData(:,1));
            yMin = min(thisPointData(:,2));
            yMax = max(thisPointData(:,2));
            zMin = min(thisPointData(:,3));
            zMax = max(thisPointData(:,3));
            l = (xMax - xMin);
            w = (yMax - yMin);
            h = (zMax - zMin);
            x = (xMin + xMax)/2;
            y = (yMin + yMax)/2;
            z = (zMin + zMax)/2;
            r = (sqrt(l^2 + w^2))/2;
%             bboxes(:,i) = [x y z l w h]';
%             bboxes(:,i) = [x y z]';
           
            [x_global, y_global] = homogeneous(Plant, x, y, SP);
            % bboxes(:,i) = [x;y;r];
            bboxes(:,i) = [x_global y_global r]';
            isValidCluster(i) = r < 0.8; % max radius of 2 meters % 有効なクラスタを番号を抽出
        end
    end
    pedestrianClusters = find(isValidCluster == 1); 
    % クラスタ数，ラベル共に有効クラスタ以外を無効化
    pedestrianLabels = ismember(labels, pedestrianClusters);    
    labels(~pedestrianLabels) = 0;
    numClusters = length(pedestrianClusters);
    % ラベル番号の振り直し
    newLabels = zeros(size(labels));
    currentLabel = 1;
    for i = 1:length(pedestrianClusters)
        clusterIdx = pedestrianClusters(i);
        newLabels(labels == clusterIdx) = currentLabel;
        currentLabel = currentLabel + 1;
    end
    labels = newLabels;
    bboxes = bboxes(:,isValidCluster);
end


% function [circle,numClusters,labels] = getobstaclecylinder(ptCloud,minDistance,minDetsPerCluster,maxZDistance,minZDistance,Plant,time,SP)   
%     [labels,numClusters] = pcsegdist(ptCloud,minDistance);
%     pointData = ptCloud.Location;  
%     %CIRCLEFITTING 最小二乗法による円フィッテングをする関数
%     % input: x,y 円フィッティングする点群
%     % output cx 中心x座標
%     %        cy 中心y座標
%     %        r  半径
%     circle = nan(3,numClusters,'double');
%     isValidCluster = false(1,numClusters);
%     M = mode(labels(:));
%     for i = 1:numClusters
%         thisPointData = pointData(labels == i,:);
%         meanPoint = mean(thisPointData,1);
%         if size(thisPointData,1) > minDetsPerCluster && ...
%                meanPoint(3) < maxZDistance && meanPoint(3) > minZDistance %&& i ~= M
% 
%             x = thisPointData(:,1);
%             y = thisPointData(:,2);
% 
%             sumx=sum(x);
%             sumy=sum(y);
%             sumx2=sum(x.^2);
%             sumy2=sum(y.^2);
%             sumxy=sum(x.*y);
% 
%             F=[sumx2 sumxy sumx;
%                sumxy sumy2 sumy;
%                sumx  sumy  length(x)];
% 
%             G=[-sum(x.^3+x.*y.^2);
%                -sum(x.^2.*y+y.^3);
%                -sum(x.^2+y.^2)];
% 
%             T=F\G;
% 
%             cx=T(1)/-2;
%             cy=T(2)/-2;
%             r=sqrt(cx^2+cy^2-T(3));
% 
%             [x_global, y_global] = homogeneous(Plant, cx, cy, SP);
%             circle(:,i) = [x_global y_global r]';
%             isValidCluster(i) = r < 4;
%         end
%     end
%     circle = circle(:,isValidCluster);
%     if isempty(circle) && time< 8e-3
%         circle = [100000;100000;0.001];
%     end
% end


function [ptCloudOut,originalObstacleIndices,originalGroundIndices] = removeGroundPlane(ptCloudIn,maxWindowRadius,elevationThreshold,elevationScale,survivedIndices,currentPointCloud)
% removeGroundPlane(ptCloudIn,maxGroundDist,referenceVector,maxAngularDist,currentIndices,roi)
    % This method removes the ground plane from point cloud using
    % pcfitplane.
    % sampleIndices = findPointsInROI(ptCloudIn,roi);
    % [~,groundIndices,outliers] = pcfitplane(ptCloudIn,maxGroundDist,referenceVector,maxAngularDist,'SampleIndices',sampleIndices);    
    % ptCloudOut = select(ptCloudIn,outliers);
    % obstacleIndices = currentIndices(outliers);
    % groundIndices = currentIndices(groundIndices);

    [groundIndices,nonGroundptCloud,groundptCloud] = segmentGroundSMRF(ptCloudIn,MaxWindowRadius=maxWindowRadius, ...
        ElevationThreshold=elevationThreshold,ElevationScale=elevationScale);
    ptCloudOut = pointCloud(rmmissing(nonGroundptCloud.Location));
    obstacleIndices = ~groundIndices;
    % Match the original indices
    originalGroundIndices = false(size(currentPointCloud.Location, 1), 1);
    originalGroundIndices(survivedIndices) = groundIndices;
    originalObstacleIndices = false(size(currentPointCloud.Location, 1), 1);
    originalObstacleIndices(survivedIndices) = obstacleIndices;
    
end




% function [ptCloudOut,indices,croppedIndices] = cropPointCloud(ptCloudIn,xLim,yLim,zLim,egoVehicleRadius)
%     % This method selects the point cloud within limits and removes the
%     % ego vehicle point cloud using findNeighborsInRadius
%     locations = ptCloudIn.Location;
%     locations = reshape(locations,[],3);
%     insideX = locations(:,1) < xLim(2) & locations(:,1) > xLim(1);
%     insideY = locations(:,2) < yLim(2) & locations(:,2) > yLim(1);
%     insideZ = locations(:,3) < zLim(2) & locations(:,3) > zLim(1);
%     inside = insideX & insideY & insideZ;
% 
%     % Remove ego vehicle
%     nearIndices = findNeighborsInRadius(ptCloudIn,[0 0 0],egoVehicleRadius);
%     nonEgoIndices = true(ptCloudIn.Count,1);
%     nonEgoIndices(nearIndices) = false;
%     validIndices = inside & nonEgoIndices;
%     indices = find(validIndices);
%     croppedIndices = find(~validIndices);
%     ptCloudOut = select(ptCloudIn,indices);
% end


function [ptCloudOut,indices,croppedIndices] = cropPointCloud2(ptCloudIn,Plant,limit,axis)
    % This method selects the point cloud within limits and removes the
    % ego vehicle point cloud using findNeighborsInRadius
   % pcshow(ptCloudIn);
    rot = [cos(Plant.yaw) sin(Plant.yaw)  0;...
           -sin(Plant.yaw) cos(Plant.yaw) 0;...
           0                0             1];
       
    if axis == 1
    trans = [0 Plant.Y 0];
    elseif axis == 2
    trans = [Plant.X 0 0];
    else  % axis == 3
    trans = [Plant.X Plant.Y Plant.Z];%[Plant.X Plant.Y 0];
    end
    
    tform = rigid3d(rot,trans);
    ptCloud_obs = pctransform(ptCloudIn,tform);
    locations = ptCloud_obs.Location;
    locations = reshape(locations,[],3);
    insideX = locations(:,1) < limit(1,2) & locations(:,1) > limit(1,1);
    insideY = locations(:,2) < limit(2,2) & locations(:,2) > limit(2,1);
    insideZ = locations(:,3) < limit(3,2) & locations(:,3) > limit(3,1);
    inside = insideX & insideY & insideZ;
    
    
    % Remove ego vehicle
%     nearIndices = findNeighborsInRadius(ptCloudIn,[0 0 0],egoVehicleRadius);
%     nonEgoIndices = true(ptCloudIn.Count,1);
%     nonEgoIndices(nearIndices) = false;
    
    validIndices = inside; %& nonEgoIndices;
    indices = find(validIndices);
    croppedIndices = find(~validIndices);
    ptCloudOut = select(ptCloudIn,indices);
end

