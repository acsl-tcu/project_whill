function [result] = move_point(START, END, distance)    %#codegen
  % 始点から終点に向かって、距離 distance だけ点の座標を移動させる。
  dx = END(1) - START(1);
  dy = END(2) - START(2);
  % 移動方向を求める。
  direction = [dx dy];
  direction = direction / norm(direction);
  % 移動距離だけ移動する。
  tmp = START' + distance * direction;
  result = tmp';
end