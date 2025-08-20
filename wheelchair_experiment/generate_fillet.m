function [final_path, arc_center, arc_radius] = generate_fillet(points, kappa, n_points, enable_debug)
% 3点A,B,Cが作る角Bを、指定された曲率で正しくフィレットします。（確定版）
%
% 入力:
%   points:       [A; B; C] の形式を持つ3x2の行列。各行が点の[x, y]座標。
%   kappa:        フィレットの曲率 (κ = 1/半径)。
%   n_points:     円弧上に生成する点の数。
%   enable_debug: (オプション) trueに設定すると計算過程のデバッグ情報を表示。
%
% 出力:
%   final_path: 補間後の全経路を示す点の座標配列。
%   arc_center: 円弧の中心座標 [ox, oy]。
%   arc_radius: 円弧の半径。

% --- 引数の初期化と検証 ---
if nargin < 4, enable_debug = false; end
if size(points, 1) ~= 3 || size(points, 2) ~= 2, error('入力pointsは3x2の行列である必要があります。'); end
if any(vecnorm(diff(points([1,2,3,1],:)),2,2) < eps), error('点A, B, Cはそれぞれ異なる点である必要があります。'); end
if kappa <= 0, error('曲率は正の値でなければなりません。'); end

% --- 点の抽出 ---
A = points(1, :);
B = points(2, :);
C = points(3, :);

% --- ベクトルの定義 ---
% ジオメトリ計算用（コーナーBを基点とするベクトル）
v_BA = A - B;
v_BC = C - B;
% 経路の進行方向に沿ったベクトル
v_AB = B - A;

% --- 角度と回転方向の計算 ---
u_BA = v_BA / norm(v_BA);
u_BC = v_BC / norm(v_BC);
cos_theta = dot(u_BA, u_BC);
theta = acos(max(min(cos_theta, 1), -1));

% ★★★ 修正点：経路に沿ったベクトルの外積で回転方向を正しく判別 ★★★
% v_AB (A->B) から v_BC (B->C) への回転方向を計算
turn_cross_prod_z = v_AB(1) * v_BC(2) - v_AB(2) * v_BC(1);

if abs(turn_cross_prod_z) < eps
    warning('点が同一直線上にあるため、直線経路を返します。');
    final_path = [A; B; C];
    arc_center = [NaN, NaN]; arc_radius = NaN;
    return;
end

% --- 円弧パラメータの計算 ---
R = 1 / kappa;
arc_radius = R;
T = R / tan(theta / 2); % 接点までの距離

if T > norm(v_BA) || T > norm(v_BC)
    error('指定された曲率が大きすぎます。フィレットが点AまたはCを超えてしまいます。');
end

P1 = B + T * u_BA; % 接点1 (AB上)
P2 = B + T * u_BC; % 接点2 (BC上)

% ★★★ 修正点：中心座標の計算方向を回転方向と一致させる ★★★
% 角の二等分線ベクトルを求める
bisector_vec = (u_BA + u_BC) / norm(u_BA + u_BC);
% 中心Oは、コーナーBから見て、フィレットの内側に入る必要がある。
% bisector_vecが指す方向が常に内側を向くとは限らないため、
% 回転方向（外積）の符号を使って、中心が常に正しい側に来るように調整する。
normal_vec_AB = [-v_AB(2), v_AB(1)] / norm(v_AB); % ABの法線ベクトル
% bisector_vecと法線ベクトルの内積が、回転方向の符号と一致するようにする
if sign(dot(bisector_vec, normal_vec_AB)) ~= sign(turn_cross_prod_z)
    bisector_vec = -bisector_vec;
end
d_BO = R / sin(theta / 2); % BからOまでの距離
O = B + d_BO * bisector_vec;
arc_center = O;


% --- 円弧上の点の生成 ---
start_angle = atan2(P1(2) - O(2), P1(1) - O(1));
end_angle = atan2(P2(2) - O(2), P2(1) - O(1));

% 回転方向に応じて角度範囲を正規化
if turn_cross_prod_z < 0 % 時計回り (CW)
    if start_angle < end_angle, start_angle = start_angle + 2*pi; end
else % 反時計回り (CCW)
    if end_angle < start_angle, end_angle = end_angle + 2*pi; end
end

angles = linspace(start_angle, end_angle, n_points);
arc_points = O + R * [cos(angles)', sin(angles)'];

% --- 最終経路の結合 ---
final_path = [A; arc_points; C];

% --- デバッグ情報 ---
if enable_debug, debug_print(A,B,C,theta,kappa,R,T,P1,P2,O,turn_cross_prod_z,start_angle,end_angle); end
end

function debug_print(A,B,C,theta,kappa,R,T,P1,P2,O,cross_z,start_a,end_a)
    fprintf('--- デバッグ情報 ---\n');
    fprintf('点 A: [%.2f, %.2f], B: [%.2f, %.2f], C: [%.2f, %.2f]\n', A, B, C);
    fprintf('コーナー角度 θ: %.2f deg\n', rad2deg(theta));
    fprintf('曲率 κ: %.2f, 半径 R: %.2f, 接点距離 T: %.2f\n', kappa, R, T);
    fprintf('接点 P1: [%.2f, %.2f], P2: [%.2f, %.2f]\n', P1, P2);
    fprintf('中心 O: [%.2f, %.2f]\n', O);
    fprintf('回転方向 (外積Z): %.2f -> %s\n', cross_z, iif(cross_z<0, '時計回り(CW)', '反時計回り(CCW)'));
    fprintf('円弧の角度範囲: %.2f -> %.2f deg\n', rad2deg(start_a), rad2deg(end_a));
    fprintf('---------------------\n');
end

function v = iif(c, t, f), if c, v=t; else, v=f; end, end