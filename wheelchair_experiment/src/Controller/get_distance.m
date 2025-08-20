function distance = get_distance(A, B, P)
    % 2点A, Bを通る直線と点Pとの距離を計算
    % 点Aから点Bへのベクトル
    AB = B - A;
    % 点Aから点Pへのベクトル
    AP = P - A;
    % 面積の公式から距離を計算する ---
    % d = |AP x AB| / |AB|
    % 外積の大きさ |AP(1)*AB(2) - AP(2)*AB(1)|
    cross_product_magnitude = abs(AP(1,1,:,:) .* AB(1,2,:,:) - AP(1,2,:,:) .* AB(1,1,:,:));
    % ベクトルABの大きさ
    norm_AB = vecnorm(AB);
    % 距離
    distance = cross_product_magnitude ./ norm_AB;
end