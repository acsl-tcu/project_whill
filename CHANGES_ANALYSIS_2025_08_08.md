# project_whill 変更点解析レポート (2025年8月8日以降)

## 概要
2025年8月8日以降のproject_whillプログラム群の主要な変更箇所を調査しました。
基準コミット: `a460e28` (2025年3月13日 17:06:03)
現在のコミット: `44e61d4` (Elevator_Gazebo branch)

## 主要な変更内容

### 1. 🆕 wheelchair_experiment ディレクトリの追加 (最大の変更)
- **日時**: 2025年8月以降
- **内容**: 車椅子ナビゲーション実験用の包括的なMATLABプログラム群を追加
- **ファイル数**: 約1,800ファイル以上を追加

#### 主要な追加機能:
- **A*経路計画システム** (`AStar_Utils.m`, `PathSetting_AStar.m`)
- **エレベーター制御機能** (`controlElevatorDoor.m`, `detectElevatorDoorState.m`, `enterElevator.m`)
- **LiDAR物体検出・追跡システム** (`src/Estimator/`, `src/codegen/mex/`)
- **フラッドフィル領域検出** (`Floodfill/FloodFillROI.m`)
- **Gazebo統合制御** (`sliding_door.xacro`, ROS制御インターフェース)
- **可視化・プロット機能** (`src/Plot/`)
- **MEX高速化システム** (`codegen/mex/`下の最適化関数群)
- **実験データ保存・解析機能** (`data/` ディレクトリ下)
- **包括的なテストツール群** (`testDoor.m`, `debug*.m`, Floodfill関連)

### 2. 🔧 コア機能の改善

#### 2.1 SharedControlMode システムの実装
- **ファイル**: `wheelchair_experiment/src/SharedControlMode.m`
- **目的**: コントロールと推定器間の通信機能
- **コミット**: `09d0cbc` "Implement SharedControlMode for Control-Estimate communication"

#### 2.2 ドア検出モードの統合
- **目的**: エレベータードア検出システムの改善
- **コミット**: `d393e61` "Integrate door detection mode with SharedControlMode system"

#### 2.3 NDT姿勢検出モードの追加
- **目的**: 手動制御実験用のNDT（Normal Distributions Transform）姿勢検出
- **コミット**: `ad38fa5` "Add NDT Pose Detection mode for manual control experiments"

### 3. 📊 実験データとドキュメント

#### 3.1 実験データの追加
- **ディレクトリ**: `wheelchair_experiment/data/20250825/` - `wheelchair_experiment/data/20250830/`
- **内容**: 日別の実験データ（A*アルゴリズム実験データを含む）
- **データ形式**: MATLABファイル（.mat）、プロット結果画像

#### 3.2 ドキュメントの充実
- **READMEファイル**: `wheelchair_experiment/README.md`, `wheelchair_experiment/README_ja.md`
- **技術文書**: 
  - `EvaluationPath_vec_gpu_Documentation.md`
  - `LiDAR_Object_Estimation_TODO.md`
  - `Reference/FPM_BoundingBox_Documentation.md`

### 4. 🛠️ 技術的改善

#### 4.1 トラッキングシステムの改良
- **機能**: 独立したトラッキングスイッチシステム
- **コミット**: `05c0d2b` "Add independent tracking switch system for estimator control"

#### 4.2 座標系とエレベーター中心位置の改善
- **コミット**: `688a5bf` "Improve elevator center position and coordinate system handling"

#### 4.3 可視化機能の拡張
- **機能**: NDTモード用のウェイポイントと車椅子姿勢の可視化
- **コミット**: `9a2c542` "Add waypoints and wheelchair pose visualization to theater plot for NDT mode"

#### 4.4 Gazebo統合システムの実装
- **機能**: シミュレーション環境と実機環境の統合制御
- **主要コンポーネント**:
  - `sliding_door.xacro`: エレベータースライドドア用URDFモデル
  - Gazebo制御プラグイン (`gazebo_ros_control`) 統合
  - `/sliding_door/door_joint_position_controller/command` ROSトピック制御
- **モード切り替え**: `main_astar.m`でmode=2（Gazebo）、mode=3（実機）の設定

#### 4.5 MEX関数の高速化システム
- **目的**: MATLAB計算の高速化
- **対象機能**:
  - `EvaluationPath_vec`: 経路評価処理
  - `mexLidarTracker`: LiDAR処理
  - `Discretemodel`: 離散化モデル
  - `Resampling`: リサンプリング処理
- **構造**: `codegen/mex/`ディレクトリ下に最適化されたMEXファイル

### 5. 🔄 最新の改善（Flood Fill ROI システム）
- **日時**: 最新コミット `44e61d4`
- **内容**: フラッドフィルROI（Region of Interest）システムの追加
- **機能**: 
  - 領域ベースの画像解析
  - 改良された実験データ処理
  - 包括的な機能改善

## コアシステム（1_launcher, 2_ros_packages, 3_dockerfiles）への影響
- **変更なし**: プロジェクトのコア部分（ROS関連、Docker設定、ランチャー）は変更されていません
- **互換性**: 既存のシステムとの互換性は維持されています

## 技術的詳細

### ファイル統計
- **総追加ファイル**: 約2,313ファイル
- **総追加行数**: 約729,757行
- **主要言語**: MATLAB (.m), C/C++ (.c/.cpp/.h), バイナリファイル (.mexw64/.mexa64)

### 主要なMATLABモジュール
1. **エレベーター制御**: エレベータードア状態検出・制御
2. **A*経路計画**: 最適経路計算アルゴリズム
3. **LiDAR処理**: 点群データ処理・物体検出
4. **追跡システム**: 拡張カルマンフィルタによる物体追跡
5. **可視化**: 実験結果・軌道の可視化システム
6. **Gazebo統合**: シミュレーション環境制御システム
7. **フラッドフィル**: 領域ベース画像解析・ROI検出

### Control.m・Estimate.m以外での主要な使用パターン

#### システム統合レベル
- **main.m**: `SharedControlMode`の初期化、MEX関数クリア
- **main_astar.m**: `PathSetting_AStar`、`gen_vehicle_points`の使用

#### パスプランニング機能
- **PathSetting_AStar.m**: `map2.mat`読み込み、`AStar_Utils`実行
- **generate_fillet.m**: 経路平滑化（フィレット生成）
- **PathSetting_original.m**: フォールバック経路定義

#### 独立テストツール群
- **testDoor.m**: Gazeboドア制御テスト
- **debugElevatorDoorDetection.m**: エレベータードア検出デバッグ
- **Floodfillディレクトリ**: `FloodFillROI.m`を中心とした領域解析システム
  - `testFloodFillROI.m`、`debugFloodFill.m`
  - `testRoomPainting.m`、`visualizeFloodFillComparison.m`

#### 高速化・最適化
- **codegenディレクトリ**: MEX関数による計算高速化
  - `EvaluationPath`、`mexLidarTracker`
  - `Discretemodel`、`Resampling`、`WP_extraction`

#### 支援モジュール
- **src/Plot/**: 可視化機能（`plotResult.m`、`myplotResult.m`等）
- **src/Object/**: オブジェクト管理（`@wheelchairObj`、`@rosBagPlayObj`等）
- **src/Other/**: GUI（`ElectricWheelchairApp.mlapp`）、ユーティリティ機能

## 影響と今後の課題

### 正の影響
- 🎯 車椅子ナビゲーション機能の大幅な拡張
- 📈 実験データ収集・解析能力の向上
- 🔬 研究開発のためのツール群の充実
- 📚 包括的なドキュメント体系
- 🤖 Gazeboシミュレーション環境との統合による開発効率向上
- ⚡ MEX関数による計算処理の高速化
- 🎮 独立したテストツール群による機能検証の容易化

### 注意点
- 📁 プロジェクトサイズの大幅な増加（約73万行追加）
- 🔧 コンパイル済みMEXファイルの依存関係管理
- 💾 大量の実験データによるストレージ要件の増加
- 🔄 Control.mとEstimate.m以外での複雑な機能依存関係の増加
- 🧩 多数の独立モジュール間の整合性管理の必要性

## 結論
2025年8月8日以降、project_whillは主に車椅子ナビゲーション実験のための包括的な機能追加により大幅に拡張されました。コアシステムは変更されておらず、新機能は既存システムとの互換性を保持しています。

**特筆すべき改善点**:
- **Gazebo統合**: シミュレーション環境での開発・テストが可能
- **MEX高速化**: 計算集約的処理の大幅な性能向上
- **モジュール化**: Control.m・Estimate.m以外での独立した機能群の充実
- **テスト体系**: 包括的なデバッグ・検証ツール群の整備

これらの追加により、より高度で実用的な車椅子自動ナビゲーション研究が可能になり、シミュレーションから実機まで一貫した開発環境が構築されています。

---
*調査日時: 2025年9月8日*
*基準期間: 2025年8月8日以降の変更*
*リポジトリ: project_whill (Elevator_Gazebo branch)*
