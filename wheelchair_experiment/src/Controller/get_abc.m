function abc_n = get_abc(obj)
% 2点を結ぶ直線の方程式(一般形)の算出
    abc = zeros(length(obj.waypoint)-1,3);
    for i=2:length(obj.waypoint)
        abc(i-1,1) = obj.waypoint(i-1,2) - obj.waypoint(i,2);
        abc(i-1,2) = obj.waypoint(i,1) - obj.waypoint(i-1,1);
        abc(i-1,3) = obj.waypoint(i-1,1)*obj.waypoint(i-1,2) + obj.waypoint(i-1,1)*obj.waypoint(i,2) - obj.waypoint(i,1)*obj.waypoint(i-1,2) - obj.waypoint(i-1,1)*obj.waypoint(i-1,2);
    end
% 法線に変換
    abc_n = zeros(length(obj.waypoint)-1,3);
    abc_n(:,1) = abc(:,2);
    abc_n(:,2) = -abc(:,1);
    for i=1:length(obj.waypoint)-1
        abc_n(i,3) = abc(i,1)*obj.waypoint(i+1,2)-abc(i,2)*obj.waypoint(i+1,1);
    end
end