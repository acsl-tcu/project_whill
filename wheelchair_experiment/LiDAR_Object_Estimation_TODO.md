# LiDAR Object Estimation Implementation Plan

## Todo List

1. ✅ **Analyze current LiDAR processing code in Estimate.m** - COMPLETED
2. ✅ **Design object detection function using LiDAR point cloud data** - COMPLETED
3. ⏳ **Implement point cloud preprocessing (ground removal, filtering)** - PENDING
4. ⏳ **Add clustering algorithm for object segmentation** - PENDING
5. ⏳ **Create object classification and size estimation** - PENDING
6. ⏳ **Integrate object estimation with existing tracking system** - PENDING

## Implementation Notes

### Current Analysis
- The Estimate.m file already contains comprehensive LiDAR processing infrastructure
- Existing features include: point cloud processing, ground removal, clustering, RANSAC ellipse fitting, multi-object tracking with EKF
- Most of the advanced functionality is currently commented out

### Proposed Function: estimateObjectsFromLiDAR

#### Point Cloud Preprocessing
- Ground plane removal using RANSAC
- ROI filtering based on robot position  
- Noise filtering

#### Object Detection
- Euclidean clustering to segment objects
- Minimum point threshold for valid objects
- Size-based filtering (reject too small/large clusters)

#### Object Classification
- Geometric feature extraction (height, width, aspect ratio)
- Simple classification (person, obstacle, wall, etc.)
- Confidence scoring

#### Position & Velocity Estimation
- Centroid calculation for object position
- Kalman filtering for smooth tracking
- Velocity estimation from position changes

### Integration Strategy
- Use existing parameters: `roi`, `th_eClustering`, etc.
- Leverage existing tracking infrastructure
- Maintain compatibility with current Plant structure