function waypoints = interactiveWaypointSelection()
    % Interactive waypoint selection on the map
    % User clicks points on the map to create custom waypoints
    % Press 'Enter' or right-click to finish selection
    %
    % Returns:
    %   waypoints - Nx2 array of [x, y] coordinates in world frame

    % Load the map
    fprintf('\n=== INTERACTIVE WAYPOINT SELECTION ===\n');
    fprintf('Loading map...\n');

    try
        map_data = load('map2.mat');
        map_obj = map_data.map;
        fprintf('Map loaded successfully\n');
    catch ME
        fprintf('Error loading map2.mat: %s\n', ME.message);
        fprintf('Cannot proceed without map. Returning empty waypoints.\n');
        waypoints = [];
        return;
    end

    % Create figure for waypoint selection
    fig = figure('Name', 'Interactive Waypoint Selection', 'NumberTitle', 'off');
    set(fig, 'Position', [100, 100, 1200, 800]);

    % Display the map in world coordinates (same as PathSetting_AStar.m line 119)
    fprintf('Displaying map in world coordinates...\n');
    show(map_obj);
    hold on;
    xlabel('X Position (meters)');
    ylabel('Y Position (meters)');
    title({'Click on the map to set waypoints', ...
           'Press ENTER or RIGHT-CLICK when done', ...
           'Press BACKSPACE to undo last point'}, ...
          'FontSize', 12, 'FontWeight', 'bold');
    hold on;
    grid on;

    % Initialize waypoint storage
    waypoints = [];
    point_handles = [];
    line_handles = [];
    text_handles = [];

    % Instructions text box
    annotation('textbox', [0.02, 0.02, 0.3, 0.1], ...
        'String', {'LEFT CLICK: Add waypoint', ...
                   'RIGHT CLICK: Finish', ...
                   'BACKSPACE: Undo last', ...
                   'ENTER: Finish'}, ...
        'EdgeColor', [0 0.5 0], ...
        'BackgroundColor', [0.9 1 0.9], ...
        'FontSize', 10, ...
        'FontWeight', 'bold', ...
        'FitBoxToText', 'on');

    % Status text (dynamic)
    status_text = annotation('textbox', [0.65, 0.02, 0.3, 0.1], ...
        'String', 'Waypoints: 0', ...
        'EdgeColor', [0 0 0.5], ...
        'BackgroundColor', [0.9 0.9 1], ...
        'FontSize', 11, ...
        'FontWeight', 'bold', ...
        'HorizontalAlignment', 'center', ...
        'FitBoxToText', 'on');

    fprintf('\n=== INSTRUCTIONS ===\n');
    fprintf('• LEFT CLICK on the map to add waypoints\n');
    fprintf('• RIGHT CLICK or press ENTER when finished\n');
    fprintf('• Press BACKSPACE to remove the last waypoint\n');
    fprintf('• Waypoints will be connected in the order you click them\n');
    fprintf('====================\n\n');

    % Main interaction loop
    done = false;
    while ~done
        try
            % Wait for user input
            [x, y, button] = ginput(1);

            if isempty(button)
                % User pressed Enter
                done = true;
                fprintf('Selection finished (ENTER pressed)\n');

            elseif button == 1
                % Left click - add waypoint
                waypoints = [waypoints; x, y];
                num_points = size(waypoints, 1);

                % Plot the new point
                h_point = plot(x, y, 'ro', 'MarkerSize', 10, 'MarkerFaceColor', 'r', 'LineWidth', 2);
                point_handles = [point_handles; h_point];

                % Add number label
                h_text = text(x, y, sprintf(' %d', num_points), ...
                    'FontSize', 12, 'FontWeight', 'bold', ...
                    'Color', [1 0 0], 'BackgroundColor', [1 1 1 0.7]);
                text_handles = [text_handles; h_text];

                % Draw line from previous point
                if num_points > 1
                    h_line = plot([waypoints(num_points-1, 1), x], ...
                                  [waypoints(num_points-1, 2), y], ...
                                  'r-', 'LineWidth', 2);
                    line_handles = [line_handles; h_line];
                end

                % Update status
                set(status_text, 'String', sprintf('Waypoints: %d\nLast: [%.2f, %.2f]', num_points, x, y));

                fprintf('Waypoint %d added: [%.2f, %.2f]\n', num_points, x, y);

            elseif button == 3
                % Right click - finish
                done = true;
                fprintf('Selection finished (RIGHT CLICK)\n');

            elseif button == 8 || button == 127
                % Backspace or Delete - remove last point
                if ~isempty(waypoints)
                    num_points = size(waypoints, 1);
                    fprintf('Removing waypoint %d: [%.2f, %.2f]\n', ...
                            num_points, waypoints(end, 1), waypoints(end, 2));

                    % Remove the last waypoint
                    waypoints(end, :) = [];

                    % Remove the last point plot
                    if ~isempty(point_handles)
                        delete(point_handles(end));
                        point_handles(end) = [];
                    end

                    % Remove the last text label
                    if ~isempty(text_handles)
                        delete(text_handles(end));
                        text_handles(end) = [];
                    end

                    % Remove the last line
                    if ~isempty(line_handles)
                        delete(line_handles(end));
                        line_handles(end) = [];
                    end

                    % Update status
                    if isempty(waypoints)
                        set(status_text, 'String', 'Waypoints: 0');
                    else
                        set(status_text, 'String', sprintf('Waypoints: %d\nLast: [%.2f, %.2f]', ...
                            size(waypoints, 1), waypoints(end, 1), waypoints(end, 2)));
                    end
                else
                    fprintf('No waypoints to remove\n');
                end
            end

        catch ME
            if strcmp(ME.identifier, 'MATLAB:ginput:FigureDeletionPause')
                % Figure was closed
                fprintf('Figure closed by user\n');
                done = true;
            else
                rethrow(ME);
            end
        end
    end

    % Final summary
    fprintf('\n=== WAYPOINT SELECTION COMPLETE ===\n');
    fprintf('Total waypoints selected: %d\n', size(waypoints, 1));
    if ~isempty(waypoints)
        fprintf('Waypoint list:\n');
        for i = 1:size(waypoints, 1)
            fprintf('%2d: [%7.2f, %7.2f]\n', i, waypoints(i, 1), waypoints(i, 2));
        end

        % Calculate total path length
        if size(waypoints, 1) > 1
            total_length = 0;
            for i = 1:size(waypoints, 1)-1
                segment_length = norm(waypoints(i+1, :) - waypoints(i, :));
                total_length = total_length + segment_length;
            end
            fprintf('Total path length: %.2f m\n', total_length);
        end
    else
        fprintf('No waypoints selected!\n');
    end
    fprintf('===================================\n\n');

    % Keep figure open for review
    if ~isempty(waypoints)
        title({'Waypoint Selection Complete', ...
               sprintf('%d waypoints selected - Close window when ready', size(waypoints, 1))}, ...
              'FontSize', 12, 'FontWeight', 'bold', 'Color', [0 0.5 0]);
        fprintf('Review the waypoints in the figure. Close the window when ready to continue.\n');
    else
        title('No waypoints selected - Close window', ...
              'FontSize', 12, 'FontWeight', 'bold', 'Color', [0.7 0 0]);
    end

    % Wait for user to close the figure
    waitfor(fig);
end
