classdef trackingEKF2 < trackingEKF
    methods
        function obj = trackingEKF2(varargin)
            % コンストラクタ：親クラスのコンストラクタを呼び出す
            obj@trackingEKF(varargin{:});
        end
        function setMeasurementSizes(EKF, measurementSize, measurementNoiseSize)
            EKF.pN = measurementSize;
            EKF.pV = measurementNoiseSize;
        end


    end
    





end