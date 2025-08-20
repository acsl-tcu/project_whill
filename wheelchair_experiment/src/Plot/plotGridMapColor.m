function plotGridMapColor(map)
occupancyMatrix = getOccupancy(map);
xWorldLimits = map.XWorldLimits;
yWorldLimits = map.YWorldLimits;
% figure;
% imagesc(xWorldLimits, yWorldLimits, occupancyMatrix(end:-1:1,:));
imagesc(xWorldLimits, yWorldLimits, occupancyMatrix(end:-1:1,:));

axis equal;
axis tight;
% xlabel('X [m]');
% ylabel('Y [m]');
% title('カスタムカラーマップ');

% カラーマップを変更可能
customColormap = jet; 
customColormap(1, :) = [1 1 1]; 
colormap(customColormap); colorbar;
set(gca, 'YDir', 'normal'); % Y軸の向きを修正
end
