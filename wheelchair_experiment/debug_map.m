function debug_map()
    % Debug the occupancyMap object to understand its structure
    
    try
        map_data = load('map2.mat');
        map_obj = map_data.map;
        
        fprintf('=== occupancyMap Object Debug ===\n');
        fprintf('Class: %s\n', class(map_obj));
        
        % List all properties
        fprintf('\nProperties:\n');
        props = properties(map_obj);
        for i = 1:length(props)
            try
                prop_value = map_obj.(props{i});
                if isnumeric(prop_value) && length(prop_value) <= 5
                    fprintf('  %s: %s\n', props{i}, mat2str(prop_value));
                else
                    fprintf('  %s: [%s] %s\n', props{i}, mat2str(size(prop_value)), class(prop_value));
                end
            catch
                fprintf('  %s: <cannot access>\n', props{i});
            end
        end
        
        % List all methods
        fprintf('\nMethods:\n');
        methods_list = methods(map_obj);
        for i = 1:min(10, length(methods_list))
            fprintf('  %s\n', methods_list{i});
        end
        if length(methods_list) > 10
            fprintf('  ... and %d more methods\n', length(methods_list) - 10);
        end
        
        % Try to access occupancy data
        fprintf('\n=== Trying to access occupancy data ===\n');
        
        % Method 1: occupancy()
        try
            occ_data = occupancy(map_obj);
            fprintf('occupancy(): SUCCESS - Size: %s\n', mat2str(size(occ_data)));
        catch ME
            fprintf('occupancy(): FAILED - %s\n', ME.message);
        end
        
        % Method 2: getOccupancy()
        try
            occ_data = getOccupancy(map_obj);
            fprintf('getOccupancy(): SUCCESS - Size: %s\n', mat2str(size(occ_data)));
        catch ME
            fprintf('getOccupancy(): FAILED - %s\n', ME.message);
        end
        
        % Method 3: Direct property access
        common_props = {'occupancyMatrix', 'GridData', 'Data', 'Matrix', 'Grid'};
        for i = 1:length(common_props)
            prop_name = common_props{i};
            if isprop(map_obj, prop_name)
                try
                    prop_data = map_obj.(prop_name);
                    fprintf('%s property: SUCCESS - Size: %s\n', prop_name, mat2str(size(prop_data)));
                catch ME
                    fprintf('%s property: FAILED - %s\n', prop_name, ME.message);
                end
            else
                fprintf('%s property: NOT FOUND\n', prop_name);
            end
        end
        
    catch ME
        fprintf('Error: %s\n', ME.message);
    end
end