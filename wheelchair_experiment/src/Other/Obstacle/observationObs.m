classdef observationObs < handle
    properties(Access = private)
        dt
        Cnt
        Flag
        RgtNum
        removeRgtNum
        Selectmode
        InputDelay
        ObstacleNum
        ObstacleSize
        InitialPosition
        InitialVelocity
        virtualObstacleFlag
        AfterVelocity
        True
        sysd
        Ad
        Bd
        Cd
        Dd
    end
    properties(Constant, Access = private)
        A  = [0,0,1,0;0,0,0,1;0,0,0,0;0,0,0,0];
        B  = [0,0;0,0;1,0;0,1];
        C  = [1,0,0,0;0,1,0,0];
        D  = [0,0;0,0];
        InputAcceleration = [0.;0.];
        X  = 1;
        Y  = 2;
    end
    methods
        function obj = observationObs(Setup)
            obj.Cnt          = 1;
            obj.dt           = Setup.dt;
            obj.RgtNum       = Setup.RgtNum;
            obj.Selectmode   = Setup.Selectmode;
            obj.ObstacleNum  = Setup.ObstacleNum;
            obj.ObstacleSize = Setup.ObstacleSize;
            obj.removeRgtNum = Setup.removeRgtNum;
            obj.InputDelay   = Setup.InputDelay;
            obj.InitialPosition = Setup.InitialPosition;
            obj.InitialVelocity = Setup.InitialVelocity;
            obj.AfterVelocity   = Setup.AfterVelocity;
            obj.virtualObstacleFlag = Setup.virtualObstacleFlag;
            if obj.ObstacleNum ~= 0 
                [PosCOL, ~] = size(Setup.InitialPosition);
                [VelCOL, ~] = size(Setup.InitialPosition);
                [SizeCOL,~] = size(Setup.ObstacleSize);
                if VelCOL ~= obj.ObstacleNum || PosCOL ~= obj.ObstacleNum || SizeCOL ~= obj.ObstacleNum
                    error("áŠQ•¨‚Ì”‚ª‰Šúó‘Ô‚à‚µ‚­‚Í‰Šú‘¬“xCáŠQ•¨‘å‚«‚³‚Ìs—ñƒTƒCƒY‚Æˆê’v‚µ‚Ü‚¹‚ñD");
                elseif obj.Selectmode == 3 && any(obj.RgtNum == obj.removeRgtNum)
                    error("RgtNum ‚Æ removeRgtNum ‚Ì”Ô†‚ðˆê’v‚³‚¹‚È‚¢‚Å‚­‚¾‚³‚¢D");
                end
                obj.sysd = c2d(ss(obj.A,obj.B,obj.C,obj.D), Setup.dt);
                obj.Ad = obj.sysd.A;
                obj.Bd = obj.sysd.B;
                obj.Cd = obj.sysd.C;
                obj.Dd = obj.sysd.D;

                for L = 1:obj.ObstacleNum
                    obj.Flag(L) = false;
                    if Setup.InputDelay == 0.
                        obj.True{L,obj.Cnt} = transpose([Setup.InitialPosition(L,:), Setup.InitialVelocity(L,:)]);
                    else
                        obj.True{L,obj.Cnt} = transpose([Setup.InitialPosition(L,:), Setup.InitialVelocity(L,:)]);
                    end
                end
            end
        end
        function y = observeObs(obj, Plant)
            obj.Cnt = obj.Cnt + 1;
            if obj.ObstacleNum ~= 0 
                y = arrayfun(@(L) struct('x',[], 'y',[], 'z',[], 'size',[]), 1:obj.ObstacleNum);
                switch obj.Selectmode
                    case {'Numerical', 1}
                        for L =1:obj.ObstacleNum
                            if obj.InputDelay < Plant.T && obj.Flag(L) ==0
%                                 obj.True{L,obj.Cnt-1}(3:4) =  transpose(obj.InitialVelocity(L,:));
                                obj.True{L,obj.Cnt-1}(3:4) =  transpose(obj.AfterVelocity(L,:));
                                obj.Flag(L) = true;
                            end
                            state   = obj.True{L,obj.Cnt-1};
                            input   = obj.InputAcceleration;
                            obj.True{L,obj.Cnt} = obj.Ad*state + obj.Bd*input;

                            y(L).x = double(obj.True{L,obj.Cnt}(obj.X));
                            y(L).y = double(obj.True{L,obj.Cnt}(obj.Y));
                            y(L).z = 0.;
                            y(L).size = double(obj.ObstacleSize(L));
                        end
                    case {'Physics',   2}
                        error('You are not able to choose this number! Select the correct number again.');
                    case {'Expriment', 3}
                        if obj.virtualObstacleFlag
                            for L =1:obj.ObstacleNum
                                if obj.InputDelay < Plant.T && obj.Flag(L) ==0
%                                     obj.True{L,obj.Cnt-1}(3:4) =  transpose(obj.InitialVelocity(L,:));
                                    obj.True{L,obj.Cnt-1}(3:4) =  transpose(obj.AfterVelocity(L,:));
                                    obj.Flag(L) = true;
                                end
                                state   = obj.True{L,obj.Cnt-1};
                                input   = obj.InputAcceleration;
                                obj.True{L,obj.Cnt} = obj.Ad*state + obj.Bd*input;

                                y(L).x = double(obj.True{L,obj.Cnt}(obj.X));
                                y(L).y = double(obj.True{L,obj.Cnt}(obj.Y));
                                y(L).z = 0.;
                                y(L).size = double(obj.ObstacleSize(L));
                            end
                        else
                            Num = 0;
                            L   = 1;
                            while L <= obj.ObstacleNum
                                Num = Num + 1;
                                if Num ~= obj.RgtNum && all(Num ~= obj.removeRgtNum)
                                    y(L).x = double(Plant.Rigid{Num}.x);
                                    y(L).y = double(Plant.Rigid{Num}.y);
                                    y(L).z = double(Plant.Rigid{Num}.z);
                                    y(L).size = double(obj.ObstacleSize(L));
                                    L = L + 1;
                                end
                            end
                        end
                    otherwise
                        error('Wrong number! Select the correct number again.');
                end 
            else
                y = struct('x', Inf, 'y', Inf, 'z', Inf, 'size', 1.e-15);
            end
        end
    end
end