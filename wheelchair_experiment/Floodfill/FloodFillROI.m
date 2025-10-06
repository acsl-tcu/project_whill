classdef FloodFillROI < handle
    %FLOODFILLROI Class for flood fill based region of interest detection
    % This class implements flood fill algorithm to automatically detect
    % room boundaries from occupancy maps and generate dynamic ROI
    
    properties (Access = private)
        occupancyMap        % Occupancy map object
        occupancyMatrix     % Binary occupancy matrix (0=free, 1=occupied)
        gridResolution      % Map resolution (meters per grid cell)
        mapLimits           % [x_min, x_max, y_min, y_max] in world coordinates
    end
    
    methods
        function obj = FloodFillROI(mapFile)
            % Constructor - load occupancy map
            % Input: mapFile - path to .mat file containing occupancy map
            
            if nargin > 0 && ~isempty(mapFile)
                obj.loadMap(mapFile);
            end
        end
        
        function success = loadMap(obj, mapFile)
            % Load occupancy map from .mat file
            try
                fprintf('[FloodFillROI] Loading occupancy map from: %s\n', mapFile);
                map_data = load(mapFile);
                
                % Assume map is stored with variable name 'map'
                if isfield(map_data, 'map')
                    obj.occupancyMap = map_data.map;
                else
                    % Try to find occupancy map in the loaded data
                    fields = fieldnames(map_data);
                    for i = 1:length(fields)
                        if isa(map_data.(fields{i}), 'occupancyMap')
                            obj.occupancyMap = map_data.(fields{i});
                            break;
                        end
                    end
                end
                
                if isempty(obj.occupancyMap)
                    error('No occupancy map found in the file');
                end
                
                % Extract occupancy matrix and properties
                obj.occupancyMatrix = getOccupancy(obj.occupancyMap);
                obj.gridResolution = obj.occupancyMap.Resolution;
                obj.mapLimits = [obj.occupancyMap.XWorldLimits, obj.occupancyMap.YWorldLimits];
                
                fprintf('[FloodFillROI] Map loaded successfully:\n');
                fprintf('                Size: %d x %d cells\n', size(obj.occupancyMatrix));
                fprintf('                Resolution: %.3f m/cell\n', obj.gridResolution);
                fprintf('                World limits: X[%.1f, %.1f], Y[%.1f, %.1f]\n', obj.mapLimits);
                
                success = true;
                
            catch ME
                fprintf('[FloodFillROI] ERROR loading map: %s\n', ME.message);
                success = false;
            end
        end
        
        function [roi, room_cells] = getFloodFillROI(obj, robot_pos, max_distance, wall_threshold)
            % Compute ROI using flood fill algorithm
            % Input: robot_pos - [x, y] robot position in world coordinates
            %        max_distance - maximum flood fill distance in grid cells
            %        wall_threshold - occupancy threshold for walls (default: 0.5)
            % Output: roi - [x_min, x_max; y_min, y_max; z_min, z_max]
            %         room_cells - Nx2 array of [row, col] grid cells that were flooded
            
            if nargin < 4, wall_threshold = 0.5; end
            if nargin < 3, max_distance = 50; end
            
            room_cells = [];
            
            if isempty(obj.occupancyMap)
                fprintf('[FloodFillROI] WARNING: No map loaded, returning default ROI\n');
                roi = [-inf inf; -inf inf; 0.4 2];
                return;
            end
            
            try
                % Convert robot position to grid coordinates
                robot_grid = world2grid(obj.occupancyMap, robot_pos);
                start_row = round(robot_grid(1));
                start_col = round(robot_grid(2));
                
                [rows, cols] = size(obj.occupancyMatrix);
                
                % Validate starting position
                if start_row < 1 || start_row > rows || start_col < 1 || start_col > cols
                    fprintf('[FloodFillROI] WARNING: Robot position [%.2f, %.2f] outside map bounds\n', robot_pos);
                    roi = [-inf inf; -inf inf; 0.4 2];
                    return;
                end
                
                % Check if starting position is in free space
                if obj.occupancyMatrix(start_row, start_col) >= wall_threshold
                    fprintf('[FloodFillROI] WARNING: Robot at occupied position, expanding search\n');
                    % Find nearest free space
                    [start_row, start_col] = obj.findNearestFreeSpace(start_row, start_col, wall_threshold);
                    if start_row == -1
                        roi = [-inf inf; -inf inf; 0.4 2];
                        return;
                    end
                end
                
                fprintf('[FloodFillROI] Starting flood fill from grid [%d, %d] = world [%.2f, %.2f]\n', ...
                    start_row, start_col, robot_pos(1), robot_pos(2));
                
                % Perform flood fill
                room_cells = obj.floodFillIterative(start_row, start_col, max_distance, wall_threshold);
                
                % Convert room cells back to world coordinates and create ROI
                roi = obj.createROIFromCells(room_cells);
                
                fprintf('[FloodFillROI] Flood fill completed: %d cells found\n', size(room_cells, 1));
                fprintf('[FloodFillROI] Generated ROI: X[%.2f, %.2f], Y[%.2f, %.2f]\n', roi(1,:), roi(2,:));
                
            catch ME
                fprintf('[FloodFillROI] ERROR in flood fill: %s\n', ME.message);
                roi = [-inf inf; -inf inf; 0.4 2];
            end
        end
        
        function room_cells = floodFillIterative(obj, start_row, start_col, max_distance, wall_threshold)
            % Iterative flood fill implementation (stack-based)
            % More memory efficient than recursive approach
            
            [rows, cols] = size(obj.occupancyMatrix);
            visited = false(rows, cols);
            room_cells = [];
            
            % Initialize stack with starting position
            stack = [start_row, start_col, 0]; % [row, col, distance_from_start]
            room_cells = [start_row, start_col];
            visited(start_row, start_col) = true;
            
            cells_found = 1;
            
            while size(stack, 1) > 0
                % Pop from stack
                current = stack(end, :);
                stack(end, :) = [];
                curr_row = current(1);
                curr_col = current(2);
                curr_dist = current(3);
                
                % Check 4-connected neighbors (up, down, left, right)
                neighbors = [
                    curr_row-1, curr_col;  % Up
                    curr_row+1, curr_col;  % Down  
                    curr_row, curr_col-1;  % Left
                    curr_row, curr_col+1   % Right
                ];
                
                for i = 1:size(neighbors, 1)
                    nr = neighbors(i, 1);
                    nc = neighbors(i, 2);
                    new_dist = curr_dist + 1;
                    
                    % Check bounds, visited status, occupancy, and distance limit
                    if nr >= 1 && nr <= rows && nc >= 1 && nc <= cols && ...
                       ~visited(nr, nc) && ...
                       obj.occupancyMatrix(nr, nc) < wall_threshold && ...
                       new_dist <= max_distance
                        
                        visited(nr, nc) = true;
                        room_cells = [room_cells; nr, nc];
                        stack = [stack; nr, nc, new_dist];
                        cells_found = cells_found + 1;
                        
                        % Prevent memory issues with very large rooms
                        if cells_found > 100000
                            fprintf('[FloodFillROI] WARNING: Large room detected (%d cells), limiting expansion\n', cells_found);
                            break;
                        end
                    end
                end
                
                if cells_found > 100000
                    break;
                end
            end
            
            fprintf('[FloodFillROI] Flood fill found %d connected cells\n', size(room_cells, 1));
        end
        
        function [free_row, free_col] = findNearestFreeSpace(obj, start_row, start_col, wall_threshold)
            % Find nearest free space if starting position is occupied
            
            [rows, cols] = size(obj.occupancyMatrix);
            max_search_radius = 10; % Search within 10 cells
            
            for radius = 1:max_search_radius
                for dr = -radius:radius
                    for dc = -radius:radius
                        if abs(dr) + abs(dc) == radius % Manhattan distance = radius
                            r = start_row + dr;
                            c = start_col + dc;
                            
                            if r >= 1 && r <= rows && c >= 1 && c <= cols && ...
                               obj.occupancyMatrix(r, c) < wall_threshold
                                free_row = r;
                                free_col = c;
                                fprintf('[FloodFillROI] Found free space at grid [%d, %d] (offset: [%d, %d])\n', ...
                                    r, c, dr, dc);
                                return;
                            end
                        end
                    end
                end
            end
            
            % No free space found
            free_row = -1;
            free_col = -1;
            fprintf('[FloodFillROI] ERROR: No free space found near starting position\n');
        end
        
        function roi = createROIFromCells(obj, room_cells)
            % Convert grid cells to world coordinates and create bounding box ROI
            
            if isempty(room_cells)
                roi = [-inf inf; -inf inf; 0.4 2]; % Default fallback
                return;
            end
            
            % Convert grid cells to world coordinates
            world_coords = grid2world(obj.occupancyMap, room_cells);
            
            % Find bounding box of room
            x_min = min(world_coords(:, 1));
            x_max = max(world_coords(:, 1));
            y_min = min(world_coords(:, 2));
            y_max = max(world_coords(:, 2));
            
            % Add small margin for safety
            margin = 0.5; % meters
            roi = [x_min - margin, x_max + margin;
                   y_min - margin, y_max + margin;
                   0.4, 2]; % Keep Z limits same as original
        end
        
        function visualizeFloodFill(obj, robot_pos, roi, room_cells)
            % Visualize flood fill result
            % Input: robot_pos - robot position
            %        roi - generated ROI
            %        room_cells - flood filled cells (optional)
            
            if isempty(obj.occupancyMap)
                fprintf('[FloodFillROI] Cannot visualize: No map loaded\n');
                return;
            end
            
            figure('Name', 'Flood Fill ROI Result', 'Position', [100, 100, 1000, 800]);
            
            % Plot occupancy map
            show(obj.occupancyMap);
            hold on;
            
            % Plot robot position
            plot(robot_pos(1), robot_pos(2), 'ro', 'MarkerSize', 15, 'LineWidth', 3, ...
                'DisplayName', 'Robot Position');
            
            % Plot ROI boundary
            roi_x = [roi(1,1), roi(1,2), roi(1,2), roi(1,1), roi(1,1)];
            roi_y = [roi(2,1), roi(2,1), roi(2,2), roi(2,2), roi(2,1)];
            plot(roi_x, roi_y, 'g-', 'LineWidth', 3, 'DisplayName', 'Flood Fill ROI');
            
            % Plot flood filled area if provided
            if nargin > 3 && ~isempty(room_cells)
                world_coords = grid2world(obj.occupancyMap, room_cells);
                scatter(world_coords(:,1), world_coords(:,2), 2, 'blue', 'filled', ...
                    'DisplayName', 'Flooded Area', 'MarkerFaceAlpha', 0.3);
            end
            
            title('Flood Fill ROI Detection');
            xlabel('X (m)');
            ylabel('Y (m)');
            legend('Location', 'best');
            grid on;
            axis equal;
            
            % Add text annotation
            text(robot_pos(1) + 1, robot_pos(2) + 1, ...
                sprintf('ROI: X[%.1f,%.1f] Y[%.1f,%.1f]', roi(1,:), roi(2,:)), ...
                'BackgroundColor', 'white', 'EdgeColor', 'black', 'FontSize', 10);
            
            drawnow;
        end
        
        function stats = analyzeROI(obj, roi, robot_pos)
            % Analyze ROI properties
            
            stats = struct();
            stats.area = (roi(1,2) - roi(1,1)) * (roi(2,2) - roi(2,1)); % m^2
            stats.width = roi(1,2) - roi(1,1); % X direction
            stats.height = roi(2,2) - roi(2,1); % Y direction
            stats.center = [(roi(1,1) + roi(1,2))/2, (roi(2,1) + roi(2,2))/2];
            stats.robot_offset = stats.center - robot_pos;
            
            fprintf('[FloodFillROI] ROI Analysis:\n');
            fprintf('               Area: %.2f m²\n', stats.area);
            fprintf('               Dimensions: %.2f x %.2f m\n', stats.width, stats.height);
            fprintf('               Center: [%.2f, %.2f]\n', stats.center);
            fprintf('               Robot offset from center: [%.2f, %.2f]\n', stats.robot_offset);
        end
        
        function map = getOccupancyMap(obj)
            % Get the occupancy map (public getter method)
            map = obj.occupancyMap;
        end
        
        function matrix = getOccupancyMatrix(obj)
            % Get the occupancy matrix (public getter method)  
            matrix = obj.occupancyMatrix;
        end
        
        function limits = getMapLimits(obj)
            % Get the map limits (public getter method)
            limits = obj.mapLimits;
        end
        
        function resolution = getGridResolution(obj)
            % Get the grid resolution (public getter method)
            resolution = obj.gridResolution;
        end
        
        function paintRoom(obj, robot_pos, max_distance, wall_threshold, paint_color)
            % Paint the entire room using flood fill - visual "paint bucket" effect
            % Input: robot_pos - [x, y] robot position
            %        max_distance - max flood distance (default: 100)
            %        wall_threshold - wall detection threshold (default: 0.5)  
            %        paint_color - color for painted area (default: 'cyan')
            
            if nargin < 5, paint_color = 'cyan'; end
            if nargin < 4, wall_threshold = 0.5; end
            if nargin < 3, max_distance = 100; end
            
            if isempty(obj.occupancyMap)
                fprintf('[FloodFillROI] ERROR: No map loaded\n');
                return;
            end
            
            fprintf('[FloodFillROI] Painting room from position [%.2f, %.2f]...\n', robot_pos(1), robot_pos(2));
            
            % Get flood filled cells
            [~, room_cells] = obj.getFloodFillROI(robot_pos, max_distance, wall_threshold);
            
            if isempty(room_cells)
                fprintf('[FloodFillROI] No room found to paint!\n');
                return;
            end
            
            % Convert grid cells to world coordinates for painting
            world_coords = grid2world(obj.occupancyMap, room_cells);
            
            % Create figure
            figure('Name', sprintf('Room Painting from [%.1f, %.1f]', robot_pos(1), robot_pos(2)), ...
                'Position', [100, 100, 1000, 800]);
            
            % Show base map
            show(obj.getOccupancyMap());
            hold on;
            
            % Paint the room cells
            scatter(world_coords(:,1), world_coords(:,2), 20, paint_color, 'filled', ...
                'MarkerFaceAlpha', 0.7, 'DisplayName', sprintf('Painted Room (%d cells)', size(room_cells, 1)));
            
            % Show robot position
            plot(robot_pos(1), robot_pos(2), 'ro', 'MarkerSize', 15, 'LineWidth', 3, ...
                'DisplayName', 'Robot Position');
            
            % Add title and labels
            title(sprintf('Flood Fill Room Painting - %d cells painted', size(room_cells, 1)), ...
                'FontSize', 14, 'FontWeight', 'bold');
            xlabel('X (m)'); ylabel('Y (m)');
            legend('Location', 'best');
            grid on; axis equal;
            
            % Calculate room statistics
            room_area_cells = size(room_cells, 1);
            room_area_m2 = room_area_cells * (obj.gridResolution^2);
            
            % Add statistics text
            stats_text = sprintf(['Room Statistics:\n' ...
                                  '• Painted cells: %d\n' ...
                                  '• Room area: %.1f m²\n' ...
                                  '• Grid resolution: %.3f m/cell\n' ...
                                  '• Paint color: %s'], ...
                                room_area_cells, room_area_m2, obj.gridResolution, paint_color);
                                
            text(0.02, 0.98, stats_text, 'Units', 'normalized', 'VerticalAlignment', 'top', ...
                'BackgroundColor', 'white', 'EdgeColor', 'black', 'FontSize', 10);
            
            fprintf('[FloodFillROI] Room painted! %d cells (%.1f m²) painted with %s\n', ...
                room_area_cells, room_area_m2, paint_color);
            
            drawnow;
        end
    end
end