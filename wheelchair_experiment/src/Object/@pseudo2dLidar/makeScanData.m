function scanFinishied = makeScanData(obj, Plant)
    Xt = Plant.X;
    Yt = Plant.Y;
    Tht= Plant.yaw;

    pointNum    = (2*pi)/(obj.resolution*pi/180);
    outTemp     = cell(pointNum,1);
    oScaned     = zeros(pointNum,2);
    oScanedAfRe = zeros(pointNum,2);
    scanAfRe    = zeros(pointNum,2);

    %% settings of scan data
    angles = linspace(-pi ,pi ,pointNum);
    ranges = ones(1,pointNum)*obj.maxRange;
    scan   = lidarScan(ranges, angles);
    for L = 1:pointNum
        scanBeHo = [scan.Cartesian(L,1); scan.Cartesian(L,2); 1.];
        scanAfHo = obj.H(Xt, Yt, Tht)*scanBeHo;
        scanAfRe(L,:) = scanAfHo([obj.X, obj.Y]);
    end

    %% getting both the room and the objects
    Object = getObjects(obj);

    %% settings of both the room and the objects
    polyRoom    = polyshape(obj.Room(obj.X), obj.Room(obj.Y));
    lineArray   = arrayfun(@(L) [Xt, Yt; scanAfRe(L,obj.X), scanAfRe(L,obj.Y)], colon(1, pointNum),'UniformOutput', false);
    [point, ~]  = cellfun(@(X) intersect(polyRoom, X), lineArray, 'UniformOutput', false);

    if isempty(Object) == false
        polyObjects = polyshape(Object(obj.X,:), Object(obj.Y,:));
    end
    %% generating lider data
    for L = 1:pointNum
        if isempty(Object) == false
            [~, outTemp{L}] = intersect(polyObjects, point{L});
        else
            outTemp{L} = point{L};
        end
        column = size(outTemp{L});
        if isempty(outTemp{L}) == true
            outTemp{L} = point{L};
        end
        if column(1,1) > 2
            outTemp{L} = outTemp{L}([obj.X, obj.Y], [obj.X, obj.Y]);
        end
        oScaned(L,:)= outTemp{L}(2,:);
        oScanedBeHo = [oScaned(L, obj.X); oScaned(L, obj.Y); 1.];
        oScanedAfHo = obj.H(Xt, Yt, Tht)\oScanedBeHo;
        oScanedAfRe(L,:) = oScanedAfHo([obj.X, obj.Y], 1);
    end

    scanFinishied = lidarScan(oScanedAfRe);
    plot(scanFinishied)
end