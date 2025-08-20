function plotObstacle(x,y,th,a,b,color,line)
%% plotObstacle(x,y,th,a,b,color)
% (x,y) 図形の中心
% th [rad] 回転角度

% 図形のサイズ
width = b*2;
height =(a+b)*2;

% 角の丸みの半径
cornerRadius = width / 2;
% 半円部分を作成
theta = linspace(0, pi, 50);
halfCircleX = cornerRadius * cos(theta);
halfCircleY = cornerRadius * sin(theta);

% 上半分の半円
topHalfCircleX = halfCircleX;
topHalfCircleY = halfCircleY+ (height - width) / 2;

% 下半分の半円
bottomHalfCircleX = halfCircleX ;
bottomHalfCircleY = -halfCircleY- (height - width) / 2;

% 図形全体の座標を結合
shapeX = [bottomHalfCircleX, fliplr(topHalfCircleX),bottomHalfCircleX(1)];
shapeY = [bottomHalfCircleY, fliplr(topHalfCircleY),bottomHalfCircleY(1)];

% 回転行列を作成
R = [cos(th), -sin(th); sin(th), cos(th)];

% 図形全体を回転
rotatedShape = R * [shapeX; shapeY];
rotatedShape = [rotatedShape(1,:)+x;rotatedShape(2,:)+y];

% 図形を描画
fill(rotatedShape(1, :), rotatedShape(2, :),color,'FaceAlpha',.2);
hold on
plot(rotatedShape(1, :), rotatedShape(2, :), 'Color',color,'LineWidth', line);
hold on
plot(x, y, '-o','Color',color,'LineWidth', line); % 中心点をプロット
