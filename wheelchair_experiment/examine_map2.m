function examine_map2()
    % Load and examine the map2.mat structure
    
    try
        % Load the map
        data = load('map2.mat');
        
        % Display the variable names in the file
        fprintf('Variables in map2.mat:\n');
        var_names = fieldnames(data);
        for i = 1:length(var_names)
            fprintf('  %s\n', var_names{i});
        end
        
        % Examine each variable
        for i = 1:length(var_names)
            var_name = var_names{i};
            var_data = data.(var_name);
            
            fprintf('\n=== Variable: %s ===\n', var_name);
            fprintf('Class: %s\n', class(var_data));
            fprintf('Size: %s\n', mat2str(size(var_data)));
            
            if isnumeric(var_data)
                if numel(var_data) <= 20
                    fprintf('Data:\n');
                    disp(var_data);
                else
                    fprintf('Min: %.4f, Max: %.4f\n', min(var_data(:)), max(var_data(:)));
                    if size(var_data, 2) <= 5 && size(var_data, 1) <= 10
                        fprintf('First few rows:\n');
                        disp(var_data(1:min(5,end), :));
                    end
                end
                
                % If it looks like coordinate data, plot it
                if size(var_data, 2) == 2 && size(var_data, 1) > 2
                    figure;
                    plot(var_data(:, 1), var_data(:, 2), 'o-');
                    title(sprintf('%s - Coordinate Plot', var_name));
                    xlabel('X');
                    ylabel('Y');
                    grid on;
                    axis equal;
                end
                
            elseif isstruct(var_data)
                fprintf('Structure fields:\n');
                struct_fields = fieldnames(var_data);
                for j = 1:length(struct_fields)
                    field_data = var_data.(struct_fields{j});
                    fprintf('  %s: %s [%s]\n', struct_fields{j}, mat2str(size(field_data)), class(field_data));
                end
                
            elseif iscell(var_data)
                fprintf('Cell array contents:\n');
                for j = 1:min(5, numel(var_data))
                    fprintf('  {%d}: %s [%s]\n', j, mat2str(size(var_data{j})), class(var_data{j}));
                end
                
            else
                fprintf('Other data type\n');
                if numel(var_data) < 100
                    disp(var_data);
                end
            end
        end
        
    catch ME
        fprintf('Error loading map2.mat: %s\n', ME.message);
    end
end