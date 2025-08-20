classdef pseudo2dLidar    
    properties(Access = private)
        Room
        Object
    end
    properties(Constant)
        X = 1;
        Y = 2;
        %- Configuration for LiDAR -%
        maxRange   = 100; % [m]
        resolution = 0.4; % [degree]
        %- settings of a homogeneous transformation matrix -%
        H = @(X, Y, Th) [ cos(Th), -sin(Th), X; sin(Th), cos(Th), Y; 0., 0., 1.];
    end
    methods
        function obj = pseudo2dLidar()
            [room, object] = initObjects(obj);
            obj.Room   = room;
            obj.Object = object;
        end
        ret = makeScanData(obj, Plant)
        ret = makeEllipse(obj, x, y, th, a, b)
        ret = getObjects(obj)
        [room, object] = initObjects(obj)
    end
end

