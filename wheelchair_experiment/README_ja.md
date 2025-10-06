# 車椅子ナビゲーションシステム

## 使用方法

### ステップ1: 車椅子モードの設定

`main_astar.m`を開いて動作モードを設定します：

```matlab
mode = 2;  % 動作モードを選択:
           % 2: Gazebo物理シミュレーション（利用可能）
           % 3: 実機実験（利用可能）
           % 注意: 現在モード2と3のみ利用可能
```

### ステップ2: センサーとAutowareの設定

選択したモードに応じてセンサーとautowareを設定します：

```matlab
% モード2（Gazebo）の場合:
sensor(1) = true;   % Primeセンサー（Gazebo用）
sensor(2) = true;   % LiDAR（Gazebo、オンライン）
sensor(3) = false;  % RealSense
autoware(1) = false; % GazeboではAutoware無効

% モード3（実機）の場合:
sensor(1) = false;  % Prime（実機では使用しない）
sensor(2) = true;   % LiDAR（Gazebo、オンライン）
sensor(3) = false;  % RealSense
autoware(1) = true;  % 実機ではAutoware有効
```

### ステップ3: プログラムの実行

```matlab
run('main_astar.m')
```

## 制御モード（インタラクティブメニュー）

シミュレーション中に任意のキーを押すと制御モードメニューにアクセスできます：

### 利用可能な制御モード

1. **フロア変更モード**
   - エレベーターまでのパスを作成し、エレベーターに入ります
   - エレベーター進入機能付きの完全自律ナビゲーション
   - LiDAR追跡と障害物回避を有効にします

2. **ドア検出デバッグモード** 
   - ドア検出アルゴリズムのテスト専用
   - 通常のナビゲーションをバイパスしてドア検出テストに集中
   - アルゴリズム開発と検証に有用

3. **NDT姿勢検出モード**
   - 連続的な姿勢放送付きの手動制御
   - 姿勢データを表示しながら手動で車椅子を操作
   - キャリブレーションとテストに有用

4. **推定器なしフロア変更モード**
   - 経路追従を有効にするがLiDAR処理と追跡を無効にする
   - 障害物検出なしのナビゲーションのみ

5. **シミュレーション終了**
   - シミュレーションを終了

### インタラクティブメニューの使用

1. シミュレーション実行中に任意のキーを押す
2. メニューのオプション1-5から選択
3. 車椅子が選択されたモードに切り替わります
4. いつでも再度キーを押してメニューにアクセス可能

## クイックスタートの例

```matlab
% Gazeboシミュレーションの場合:
mode = 2;
sensor(1) = true;   % Prime
sensor(2) = true;   % LiDAR  
sensor(3) = false;  % RealSense
autoware(1) = false; % Autoware無効

% 実機の場合:
mode = 3;
sensor(1) = false;  % Prime無効
sensor(2) = true;   % LiDAR有効
sensor(3) = false;  % RealSense無効
autoware(1) = true;  % Autoware有効

% 次に実行:
run('main_astar.m')

% シミュレーション中に任意のキーを押して制御モードメニューにアクセス
```