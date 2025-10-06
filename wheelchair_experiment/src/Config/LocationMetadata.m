classdef LocationMetadata
    % LocationMetadata - Configuration for location-specific parameters
    % Stores ROI areas, target positions, and door centers for different locations
    %
    % Usage:
    %   elevator_data = LocationMetadata.getLocation('elevator');
    %   roi = elevator_data.roi;
    %   target = elevator_data.target_position;

    methods (Static)
        function metadata = getLocation(name)
            % Get metadata for a specific location
            % Input: name - location identifier ('elevator', etc.)
            % Output: metadata - struct with roi, target_position, door_center

            if strcmp(name, 'elevator')
                % Elevator ROI area (approach zone)
                metadata.roi.x_min = 29.3;
                metadata.roi.x_max = 30.5;
                metadata.roi.y_min = 9.0;
                metadata.roi.y_max = 9.6;

                % Target position (where wheelchair should stop before entry)
                metadata.target_position = [30, 9.4];

                % Door center position (inside elevator)
                metadata.door_center = [27, 9.4];

            else
                error('LocationMetadata:UnknownLocation', 'Unknown location: %s', name);
            end
        end
    end
end
