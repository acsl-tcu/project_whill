function [cxe_global, cye_global, cze_global] = homogeneous(state, cxe, cye, cze, lidar_height)
    %HOMOGENEOUS Transfer to GLOBAL
    % state: Ego-vehicle's position in global system coordinates X Y Z Theta which are
    % measured by Autoware/Gazebo.
    % cxe, cye, cze: Obstacle's position in local system coordinates
    % lidar_height: LiDAR height above ground level (from obj.trans(3))
    
    % Handle both 2D and 3D transformations
    if nargin < 4 || isempty(cze)
        % 2D transformation (backward compatibility)
        L = [cxe; cye; ones(1,length(cxe))];
        T = [1, 0, state.X;
             0, 1, state.Y;
             0, 0,    1   ];
        H = [cos(state.yaw), -sin(state.yaw), 0;
             sin(state.yaw),  cos(state.yaw), 0;
             0,               0,              1];
        G = T*H*L;
        
        cxe_global = G(1,:)';
        cye_global = G(2,:)';
        cze_global = [];
    else
        % 3D transformation
        if nargin < 5 || isempty(lidar_height)
            lidar_height = 1.2; % Default LiDAR height (from Estimate.m line 332)
        end
        
        % 3D homogeneous coordinates
        L = [cxe; cye; cze; ones(1,length(cxe))];
        
        % 3D transformation matrices
        T = [1, 0, 0, state.X;
             0, 1, 0, state.Y;
             0, 0, 1, lidar_height;  % LiDAR height above ground (z=0)
             0, 0, 0,    1   ];
        
        H = [cos(state.yaw), -sin(state.yaw), 0, 0;
             sin(state.yaw),  cos(state.yaw), 0, 0;
             0,               0,              1, 0;
             0,               0,              0, 1];
        
        G = T*H*L;
        
        cxe_global = G(1,:)';
        cye_global = G(2,:)';
        cze_global = G(3,:)';
    end
end

