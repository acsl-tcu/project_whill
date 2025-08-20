function [isObserved,ekf] = convertMeasModel(modelName,ekf,isObserved,R_crr)
    switch modelName
        case 'ellipse'
            R = ekf.MeasurementNoise;
            if isObserved
                setMeasurementSizes(ekf,5,5)
                ekf.MeasurementNoise = R_crr;
            else
                setMeasurementSizes(ekf,2,2)
                ekf.MeasurementNoise = R(1:2,1:2);
            end
        otherwise
            error('想定外のフィルタ名です．')

    end

end