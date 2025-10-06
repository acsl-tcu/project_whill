function FPMcost = calculateBoundingBoxFPMCost(obj, px2, boundingBoxes, param_FPM)
    % Calculate FPM cost using bounding box obstacles instead of capsules
    % Vectorized version for high performance - processes all paths simultaneously
    % 
    % Inputs:
    %   obj - object with wheelchair parameters
    %   px2 - predicted paths [3, 1, K, NP] (x, y, theta for each path point)
    %   boundingBoxes - cell array of bounding box structures
    %   param_FPM - FPM parameters
    %
    % Outputs:
    %   FPMcost - cost array [1, NP] for each path
    
    % Initialize cost array
    FPMcost = zeros(1, obj.NP, 'like', px2);
    
    if isempty(boundingBoxes)
        return;
    end
    
    % Extract positions and orientations for all paths and time steps
    x = px2(1, 1, :, :);    % [1, 1, K, NP]
    y = px2(2, 1, :, :);    % [1, 1, K, NP] 
    th = px2(3, 1, :, :);   % [1, 1, K, NP]
    
    % Use TRUE vectorized FPM calculation with exact rectangular processing (no circle approximation)
    Grade = FPM_boundingbox_vec_true(obj, x, y, th, boundingBoxes, [], param_FPM);
    
    % Convert grades to costs and sum over path steps (skip first point)
    % Grade is [1, 1, K-1, NP], we want cost [1, NP]
    step_costs = 1 - max(0, min(1, Grade));  % Clamp and invert grades
    FPMcost = squeeze(sum(step_costs, 3));   % Sum over K-1 time steps
    
    % Ensure correct dimensions [1, NP]
    if size(FPMcost, 1) ~= 1
        FPMcost = reshape(FPMcost, 1, []);
    end
    
    % Convert to GPU array if input was GPU array
    if isa(px2, 'gpuArray')
        FPMcost = gpuArray(FPMcost);
    end
end