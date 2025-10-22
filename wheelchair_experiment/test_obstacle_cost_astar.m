% Test script for A* with obstacle cost penalty
% This tests the updated PathSetting_AStar.m with wall-avoidance penalty

clear all; close all; clc;

fprintf('==============================================\n');
fprintf('Testing A* with Obstacle Cost Penalty\n');
fprintf('==============================================\n\n');

% Test parameters - wheelchair dimensions
robot_width = 0.6;      % meters
robot_length = 1.0;     % meters
safety_margin = 0.1;    % meters

% Test scenario 1: Start to corridor endpoint
start_position = [4.0, -0.2];
goal_position = [30.0, 6.2];

fprintf('Test 1: Path from start to corridor midpoint\n');
fprintf('  Start: [%.1f, %.1f]\n', start_position(1), start_position(2));
fprintf('  Goal:  [%.1f, %.1f]\n\n', goal_position(1), goal_position(2));

% Run A* path planning with obstacle cost
tic;
[waypoints, selectZone, NoEntryZone, ZoneNum, V_ref] = ...
    PathSetting_AStar(start_position, goal_position, robot_width, robot_length, safety_margin);
elapsed_time = toc;

fprintf('\n==============================================\n');
fprintf('Test Results:\n');
fprintf('==============================================\n');
fprintf('Computation time: %.3f seconds\n', elapsed_time);
fprintf('Number of waypoints: %d\n', size(waypoints, 1));
fprintf('\nFirst 10 waypoints:\n');
for i = 1:min(10, size(waypoints, 1))
    fprintf('  %2d: [%7.2f, %7.2f]\n', i, waypoints(i, 1), waypoints(i, 2));
end

fprintf('\n==============================================\n');
fprintf('SUCCESS: A* with obstacle cost penalty tested!\n');
fprintf('Check if path stays away from walls.\n');
fprintf('==============================================\n');
