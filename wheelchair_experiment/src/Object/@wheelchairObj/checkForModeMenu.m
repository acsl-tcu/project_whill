function exit_requested = checkForModeMenu(obj)
    % Check for keyboard input and show mode menu if key pressed
    % Returns true if user wants to exit simulation
    clear enterElevator %Clear this to prevent hitting the door.
    exit_requested = false;
    
    % Always show menu when called (no keyboard check needed)
    fprintf('\n*** SIMULATION PAUSED ***\n');
    [exit_requested, mode_change] = wheelchairModeMenu();
    
    % Handle mode change if requested
    if mode_change.requested
        % Store mode change in object for access by integrateData
        obj.UserModeRequest = mode_change;
        obj.UserModeRequest.processed = false; % Mark as not processed yet
        fprintf('[MAIN_LOOP] Mode change requested: %s\n', mode_change.new_phase);
        if mode_change.door_detection_mode
            fprintf('[MAIN_LOOP] Door detection debug mode activated\n');
        end
    else
        % Clear any previous mode request
        obj.UserModeRequest = struct('requested', false, 'processed', true);
    end
    
    if exit_requested
        fprintf('[MAIN_LOOP] User requested simulation exit\n');
    else
        fprintf('*** SIMULATION RESUMED ***\n\n');
    end
end

function [exit_requested, mode_change] = wheelchairModeMenu()
    % Interactive menu for wheelchair mode selection
    % Returns:
    %   exit_requested - true if user wants to exit simulation
    %   mode_change - struct with mode change information
    
    % Initialize return values
    exit_requested = false;
    mode_change = struct();
    mode_change.requested = false;
    mode_change.new_phase = '';
    mode_change.door_detection_mode = false;
    
    fprintf('\n=== WHEELCHAIR CONTROL MENU ===\n');
    fprintf('Current simulation is running...\n');
    fprintf('Choose an option:\n');
    fprintf('1. Set Floor Change Mode (allows elevator entry)\n');
    fprintf('2. Door Detection Debug Mode (bypass to Phase 1.5)\n');
    fprintf('3. Exit Simulation\n');
    fprintf('================================\n');
    
    % Get user input with validation
    valid_input = false;
    while ~valid_input
        choice_str = input('Enter your choice (1-3): ', 's'); % Get as string first
        choice = str2double(choice_str); % Convert to number
        
        if ~isnan(choice) && isscalar(choice) && ismember(choice, [1, 2, 3])
            valid_input = true;
        else
            fprintf('Invalid input. Please enter 1, 2, or 3.\n');
        end
    end
    
    switch choice
        case 1
            % Floor Change Mode
            fprintf('\n[MENU] Setting wheelchair to FLOOR_CHANGE mode\n');
            fprintf('This will allow elevator entry when reaching elevator door area.\n');
            mode_change.requested = true;
            mode_change.new_phase = 'floor_change';
            mode_change.door_detection_mode = false;
            
        case 2
            % Door Detection Debug Mode
            fprintf('\n[MENU] Setting wheelchair to DOOR_DETECTION mode\n');
            fprintf('This will bypass Phase 1 and go directly to Phase 1.5 debug mode.\n');
            mode_change.requested = true;
            mode_change.new_phase = 'door_detection';
            mode_change.door_detection_mode = true;
            
        case 3
            % Exit simulation
            fprintf('\n[MENU] Exiting simulation...\n');
            exit_requested = true;
            
        otherwise
            % Invalid choice - continue running
            fprintf('\n[MENU] Invalid choice. Continuing simulation without changes...\n');
    end
    
    fprintf('\n');
end