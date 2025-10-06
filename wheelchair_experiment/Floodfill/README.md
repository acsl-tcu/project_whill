# Flood Fill ROI Detection

This folder contains the flood fill algorithm implementation for room-based Region of Interest (ROI) detection in wheelchair navigation systems.

## Overview

The flood fill algorithm automatically detects room boundaries from occupancy maps and generates dynamic ROI that adapts to the robot's current environment. This replaces static ROI with intelligent, room-aware boundaries.

## Files

### 1. `FloodFillROI.m`
Main class implementing the flood fill algorithm:
- **Constructor**: `FloodFillROI(mapFile)` - Initialize with occupancy map
- **loadMap()**: Load occupancy map from .mat file
- **getFloodFillROI()**: Compute ROI using flood fill from robot position
- **visualizeFloodFill()**: Visualize flood fill results
- **analyzeROI()**: Analyze ROI properties (area, dimensions, etc.)

### 2. `testFloodFillROI.m`
Comprehensive test script demonstrating:
- Multiple test positions
- Performance analysis
- Interactive testing (click to test)
- Comparison with static ROI
- Visual results

### 3. `visualizeFloodFillComparison.m`
Advanced visualization function creating:
- Overview comparison plots
- Individual detailed results
- Statistical analysis charts
- Adaptive vs static ROI comparison

## How to Use

### Basic Usage
```matlab
% Initialize detector
detector = FloodFillROI('../map2.mat');

% Get ROI for robot at position [x, y]
robot_pos = [10.0, 2.0];
roi = detector.getFloodFillROI(robot_pos, 50, 0.5);

% roi format: [x_min, x_max; y_min, y_max; z_min, z_max]
```

### Run Tests
```matlab
% Run comprehensive test
cd Floodfill
run('testFloodFillROI.m')

% Create advanced visualizations
visualizeFloodFillComparison('../map2.mat');
```

### Integration with Estimate.m
```matlab
% In Estimate.m constructor:
obj.floodFillDetector = FloodFillROI('map2.mat');

% In main() function, replace static ROI:
dynamic_roi = obj.floodFillDetector.getFloodFillROI([Plant.X, Plant.Y], 50, 0.5);
[detections,~,~,~,~] = Faster_processingPcloud_mex(xyz, obj.theta, obj.trans, dynamic_roi, obj.th_eClustering, obj.cnt*delta);
```

## Algorithm Details

### Flood Fill Process
1. **Start**: Robot's current position in occupancy grid
2. **Expand**: Iteratively add neighboring free cells (occupancy < threshold)
3. **Stop**: When hitting walls/obstacles (occupancy ≥ threshold)
4. **Result**: Bounding box around all connected free space = current room ROI

### Parameters
- **max_distance**: Maximum expansion distance (grid cells) - default: 50
- **wall_threshold**: Occupancy threshold for walls - default: 0.5
- **margin**: Safety margin added to ROI boundaries - default: 0.5m

### Benefits
- **Automatic room detection** - no manual room definition needed
- **Adaptive boundaries** - ROI changes based on actual room geometry
- **Reduced false positives** - ignores objects through walls/in other rooms
- **Better performance** - focuses processing on relevant nearby area
- **Handles any room shape** - works with irregular/non-rectangular rooms

## Test Results

The test script demonstrates:
- **Computation time**: ~0.001-0.01 seconds per ROI
- **Room detection**: Accurately identifies current room boundaries  
- **Adaptive sizing**: ROI area varies from 10-200 m² based on room size
- **Efficiency**: 20-150% of static ROI area (adapts to room size)

## Visual Examples

The visualization shows:
- **Green rectangles**: Generated flood fill ROI
- **Red circles**: Robot positions
- **Blue dots**: Flood filled area (optional)
- **Color coding**: Different positions use different colors

## Integration Notes

1. **Memory efficient**: Uses iterative (stack-based) flood fill, not recursive
2. **Error handling**: Graceful fallback to default ROI if issues occur
3. **Performance**: Suitable for real-time operation
4. **Flexible**: Easy to adjust parameters for different environments

## Future Enhancements

Possible extensions:
- Multi-level flood fill for different room types
- Temporal smoothing to prevent ROI flickering
- Door detection to connect adjacent rooms
- Obstacle-aware expansion for furniture detection