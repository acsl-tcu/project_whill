classdef trackingKF2 < trackingKF
    methods
        function obj = trackingKF2(varargin)
            % コンストラクタ：親クラスのコンストラクタを呼び出す
            obj@trackingKF(varargin{:});
        end
        %-------------------------------------------------------------------
        % Clone method, cannot be inherited because the correct object type
        % (trackingKF) has to be created
        %-------------------------------------------------------------------
        function newKF = clone(KF)
            %CLONE   Create a copy of the filter
            % Usage: newKF = clone(KF)
                      
            %Enforce scalar filter in method
            cond = (numel(KF) > 1);
            coder.internal.errorIf(cond, ...
                'shared_tracking:dims:NonScalarFilter', ...
                'Kalman filter', 'clone');
                      
            % Create a trackingKF with the minimum set of arguments. Since
            % this uses the same size and type of arguments from the copied
            % object, it will create the necessary properties correctly

            % カスタムモデルを常時使用
            % if ~KF.isCustom(KF.MotionModel)
            %     newKF = trackingKF2('MotionModel',KF.MotionModel,...
            %            'MeasurementModel',KF.MeasurementModel,'State',KF.State); % Call with State for data type
            %     % set.MotionModel will override the STM with dT = 1 if the
            %     % filter was already functioning, set it again to make sure
            %     % cloning is perfect in object sense.
            %     newKF.pIsStateTransitionLocked = false;
            %     newKF.StateTransitionModel = KF.StateTransitionModel;
            %     newKF.pIsStateTransitionLocked = KF.pIsStateTransitionLocked;
            %     newKF.ProcessNoiseModel = KF.ProcessNoiseModel;
            % else
                newKF = trackingKF2(KF.StateTransitionModel,...
                KF.MeasurementModel,...
                KF.ControlModel);
            % end
            % Now set all the rest of the properties.
            newKF.pHasPrediction    = KF.pHasPrediction;
            newKF.pState            = KF.pState;
            newKF.pStateCovariance  = KF.pStateCovariance;
            newKF.pProcessNoise     = KF.pProcessNoise;
            newKF.pMeasurementNoise = KF.pMeasurementNoise;
            newKF.pHasControlInput  = KF.pHasControlInput;
           
            % Clone smoother properties.
            copySmootherProperties(KF,newKF);
           
             % Clone OOSM properties.
            cloneRetroFilter(newKF, KF);
        end

        function setMeasurementSizes(KF, measurementSize, measurementNoiseSize)
            KF.pN = measurementSize;
            KF.pV = measurementNoiseSize;
        end
    end
end
