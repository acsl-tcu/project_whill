%% latest 2024/11/17~
function [detections,survivedIndices,obstacleIndices,labels,numClusters] = Faster_processingPcloud(pt,theta,trans,roi,distThreshold,time) %#codegen
    persistent detectorModel
    if isempty(detectorModel)
        detectorModel = HelperBoundingBoxDetector('SegmentationMinDistance',distThreshold,...   % minimum Euclidian distance
                        'MinDetectionsPerCluster',5,...     % minimum points per cluster
                        'MeasurementNoise',0.001*eye(3),...       % measurement noise in detection report.
                        'GroundMaxDistance',0.9);           % maximum distance of ground points from ground plane
    end
    ptCloud = pointCloud(pt);
    Plant.X = trans(1);
    Plant.Y = trans(2);
    Plant.Z = trans(3);
    Plant.yaw = theta;
    SP = 0; % Sensor(LiDAR) position
    [detections,survivedIndices,croppedIndices,obstacleIndices,groundIndices,numClusters,labels] = detectorModel(ptCloud,time, ...
        Plant,roi,3,SP);
end


