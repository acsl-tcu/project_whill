function [Ae,Be,Bp] = makeModel(dt,varargin)
        Ae = [1 0 0 dt 0 0 0 0
             0 1 0 0 dt 0 0 0
             0 0 1 0 0 dt 0 0
             0 0 0 1 0 0  0 0
             0 0 0 0 1 0  0 0
             0 0 0 0 0 1  0 0
             0 0 0 0 0 0  1 0
             0 0 0 0 0 0  0 1];
    
        Be = [0 0 0 0 0
             0 0 0 0 0
             0 0 0 0 0
             dt 0 0 0 0
             0 dt 0 0 0
             0 0 dt 0 0
             0 0 0  dt 0
             0 0 0  0 dt];
    
        
        Bp = [0 0 0 0
              0 0 0 0
              dt 0 0 0
              0 dt 0 0
              0 0 dt 0
              0 0 0 dt];
end