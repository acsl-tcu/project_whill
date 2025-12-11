#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""WHILL Chair CRの制御ROS2プログラム\n
Auther:Koki Yamaguchi, Masanori Imoto\n
year:2025 \n
"""
import os
import traceback
from time import sleep, time

import rclpy
from geometry_msgs.msg import Twist, Vector3, Vector3Stamped
from rclpy.node import Node
from std_msgs.msg import Bool, Float64, Int16
from whill import ComWHILL
import numpy as np

class whill_ope(ComWHILL):
    def __init__(self, ros, port='/dev/ttyUSB-WhillCR'):
        super().__init__(port)
        self.ros = ros
        self.WHILL_REFRESH_RATE = 10.0  # WHILLのデータ更新周期[ms]
        self.WHILL_INPUT_RATE = 0.03  # 制御周期[s]
        # マニュアル操作検知用変数の定義
        self.joy_x = 0.0
        self.joy_y = 0.0
        self.last_joy_time = 0.0
        self.joy_suppression_time = 3.0  # Joy入力後に制御指令を無効化する時間[s]
        # WHILL速度計算用パラメータ
        self.wheel_radius = 0.135 # 車輪半径[m]
        self.wheel_base = 0.495 # トレッド幅[m]
        self.prev_left_angle = None
        self.prev_right_angle = None
        # データ受信のコールバック関数の定義
        self.register_callback('data_set_0', self.callback0)
        self.register_callback('data_set_1', self.callback1)
        # 電源が入ったことを通知するCallBackの定義
        self.register_callback('power_on', self.power_on_callback)

        # 電源オン
        self.send_power_on_com(1)
        self.start_data_stream(100)
        while 1:
            if self.power_status == 1:
                break
            else:
                self.refresh()

        # モードプロファイルの読み込み
        self.request_speed_profile()

        # モードの設定
        self.desired_speedmode = 4
        """
        0 : mode1
        1 : mode2
        2 : mode3
        3 : mode4
        4 : 外部入力
        5 : スマホ入力
        """
        # Config for output max speed
        pf = self.speed_profile[self.desired_speedmode]
        self.set_speed_profile(self.desired_speedmode,
                          forward_speed_max=60, # pf["forward_speed"],
                          forward_accel=90, # pf["forward_acceleration"],
                          forward_decel=pf["forward_deceleration"],
                          reverse_speed_max=pf["reverse_speed"],
                          reverse_accel=pf["reverse_acceleration"],
                          reverse_decel=pf["reverse_deceleration"],
                          turn_speed_max=pf["turn_speed"],
                          turn_accel=pf["turn_acceleration"],
                          turn_decel=pf["turn_deceleration"])
        #self.set_speed_profile_via_dict(
        #    self.desired_speedmode, self.speed_profile[self.desired_speedmode])

        # whill内部情報のストリーム開始
        self.start_data_stream(self.WHILL_REFRESH_RATE)

        self.send_joystick(int(0), int(0))  # TODO ジョイスティックコマンド
       # self.send_velocity(int(0), int(0))

    def normalize_angle_diff(self, angle_diff):
        """角度差を-π~+πの範囲に正規化"""
        while angle_diff > np.pi:
            angle_diff -= 2.0 * np.pi
        while angle_diff < -np.pi:
            angle_diff += 2.0 * np.pi
        return angle_diff

    def calculate_velocity(self, left_motor_angle, right_motor_angle, diff_time_ms):
        """
        WHILLの速度を計算
        
        Args:
            left_motor_angle: 左モーター角度 [rad] (-π ~ +π)
            right_motor_angle: 右モーター角度 [rad] (-π ~ +π)
            diff_time_ms: 前回からの経過時間 [ms]
            
        Returns:
            tuple: (linear_velocity [m/s], angular_velocity [rad/s])
                   初回呼び出しまたはdiff_time_ms=0の場合は (0.0, 0.0)
        """
        # 初回呼び出しの場合
        if self.prev_left_angle is None or self.prev_right_angle is None:
            self.prev_left_angle = left_motor_angle
            self.prev_right_angle = right_motor_angle
            return 0.0, 0.0
        
        if diff_time_ms <= 0:
            return 0.0, 0.0
        
        dt = diff_time_ms / 1000.0
        
        # 角度差分を計算（wrapping考慮）
        delta_left = self.normalize_angle_diff(left_motor_angle - self.prev_left_angle)
        delta_right = self.normalize_angle_diff(right_motor_angle - self.prev_right_angle)
        
        # 各車輪の角速度 [rad/s]
        omega_left = delta_left / dt
        omega_right = delta_right / dt
        
        # 各車輪の線形速度 [m/s]
        v_left = omega_left * self.wheel_radius
        v_right = omega_right * self.wheel_radius
        
        # ロボット中心の並進速度（前進方向） [m/s]
        #linear_velocity = (v_right + v_left) / 2.0
        
        # ロボットの角速度（回転） [rad/s]
        #angular_velocity = (v_right - v_left) / self.wheel_base
        
        # 次回計算のために現在の角度を保存
        self.prev_left_angle = left_motor_angle
        self.prev_right_angle = right_motor_angle
        
        return v_left, v_right

    def callback0(self):  # コールバック関数0のモードプロファイル
        # print(self.speed_profile[self.speed_mode_indicator])
        pass

    def callback1(self):
        """WHILLからのデータを取得するコールバック関数1
        主にモーターの角度やスピード，走行モード，ジョイスティックの入力など逐次的にデータが変わるものが対象
        """
        # ROS2メッセージの初期化
        level = Int16()
        current = Float64()
        motor_angle = Vector3()
        motor_speed = Vector3()
        motor_speed_fang = Vector3()
        motor_speed_ts = Vector3Stamped()
        speedmode = Int16()
        joy = Vector3()

        # データの格納
        level.data, current.data = self.battery.values()
        motor_angle.x, motor_speed.x = self.right_motor.values()
        motor_angle.y, motor_speed.y = self.left_motor.values()
        motor_speed_fang.x, motor_speed_fang.y = self.calculate_velocity(motor_angle.x, motor_angle.y, self.time_diff_ms)
        motor_speed_fang.x = motor_speed_fang.x / 1000 * 3600 # m/s -> km/h
        motor_speed_fang.y = motor_speed_fang.y / 1000 * 3600 # m/s -> km/h
        motor_speed_ts.vector = motor_speed_fang
        #motor_speed_ts.header.stamp.sec = 0
        motor_speed_ts.header.stamp.nanosec = self.time_diff_ms
        speedmode.data = self.speed_mode_indicator
        joy_x, joy_y = self.joy.values()
        joy.x = float(joy_x)
        joy.y = float(joy_y)
        #print(f'Class-{type(self.time_diff_ms)}')
        #print(f'TimeCount-{self.timestamp_current}')
        #print(f'TimeDiff-{self.time_diff_ms}')
        #print(f'MS-{motor_speed}')

        # ROS2へトピックの配信
        self.ros.puber_battery_level.publish(level)
        self.ros.puber_battery_current.publish(current)
        self.ros.puber_motor_angle.publish(motor_angle)
        self.ros.puber_motor_speed.publish(motor_speed)
        self.ros.puber_motor_speed_ts.publish(motor_speed_ts)
        self.ros.puber_speedmode.publish(speedmode)
        self.ros.puber_joy.publish(joy)
        # マニュアル操作検知のため保存
        self.joy_x = float(joy_x)
        self.joy_y = float(joy_y)

        self.whill.refresh()

    def power_on_callback(self):
        """Whillから電源が入ったことを知らされた際に実行する関数"""
        print('WHILL wakes up')

    def send_power_on_com(self, io):
        """whillのイグニッションを管理するための関数"""
        if io:
            self.send_power_on()
        else:
            self.send_power_off()

    def request_speed_profile(self, profile_list=[0, 1, 2, 3, 4, 5]):
        """速度モードの一覧をリクエストする関数"""
        for i in profile_list:
            old_count = self.seq_data_set_0
            self.start_data_stream(10, 0, i)
            while old_count == self.seq_data_set_0:
                self.refresh()        

    def velocity2joy(self, v, w):
        """速度・角速度入力をジョイスティック入力に変換する関数"""
        d = 0.5  # ホイール間距離
        pf = self.speed_profile[self.desired_speedmode]
        self.ros.get_logger().info(f"Speed PF:{pf}")
        if 0.0 <= v:
            # 前進と後進で変換が違う為分岐
            front_joy = min(100.0 * v / (pf["forward_speed"] / 36), 100)
        else:
            front_joy = max(100.0 * v / (pf["reverse_speed"] / 36), -100)
        turn_v = -w * d  # 円旋回の定義で単位変換している
        side_joy = max(min(100, 100.0 * turn_v /
                       (pf["turn_speed"] / 36)), -100)
        # print(front_joy , side_joy)
        return front_joy, side_joy

    def velocity2cmd(self, v, w):
        """速度・角速度入力を実機入力に変換する関数"""
        unit = 0.004 # 最小単位 km/h
        front = min(max(v*3.6/unit,-500),1500)
        side = min(max(-w*3.6/unit,-750),750)
        return front, side



class node(Node):
    def __init__(self) -> None:
        super().__init__("whill")
        # 初期値の設定
        self.sub_vel_t = time()
        self.v = 0
        self.w = 0

        # ROS2 subscriberを定義する
        self.create_subscription(
            Twist, '~/cmd_vel', self.sub_cmd_vel, 1)  # ROS速度コマンドの送信
        self.create_subscription(
            Bool, '~/cmd_power', self.sub_cmd_power, 1)  # Whillのイグニッションを設定する

        # ROS2 Publisherを定義している
        self.puber_battery_level = self.create_publisher(
            Int16, "~/battery_level", 10)
        self.puber_battery_current = self.create_publisher(
            Float64, "~/battery_current", 10)
        self.puber_motor_angle = self.create_publisher(
            Vector3, "~/motor_angle", 10)
        self.puber_motor_speed = self.create_publisher(
            Vector3, "~/motor_speed", 10)
        self.puber_motor_speed_ts = self.create_publisher(
            Vector3Stamped, "~/motor_speed_ts", 10)
        self.puber_speedmode = self.create_publisher(
            Int16, "~/speed_mode", 10)
        self.puber_joy = self.create_publisher(
            Vector3, "~/joy", 10)

        # whillへの接続フェーズ
        self.whill = whill_ope(self)
        
        self.create_timer(self.WHILL_INPUT_RATE, self.mainloop)

    def sub_cmd_vel(self, topic):
        """速度・角速度指令トピックを購読し構造体に格納する関数"""
        self.v = topic.linear.x
        self.w = topic.angular.z
        self.sub_vel_t = time()

    def sub_cmd_power(self, topic):
        """電源の制御に関するトピックを購読しWHILLの電源を制御する関数"""
        self.whill.send_power_on_com(topic.data)

    def pub_battey_stat(self, level, current):
        """バッテリーの状態をトピック配信する関数"""
        self.puber_battery_level.publish(level)
        self.puber_battery_current.publish(current)

    # def mainloop(self):
    #     """メインの実行関数\n
    #     コンストラクタで設定した制御周期でジョイスティックコマンドを送信する．
    #     """
    #     if time() < 1.0 + self.sub_vel_t:
    #         joy_x, joy_y = self.whill.velocity2joy(self.v, self.w)
    #         # Remote control only
    #         self.whill.send_joystick(int(joy_x), int(joy_y))
    #         # Accept Manual control
    #         #command_bytes = [self.whill.CommandID.SET_JOYSTICK,
    #         #                 self.whill.UserControl.ENABLE,
    #         #                 int(joy_x), int(joy_y)]
    #         #self.whill.send_command(command_bytes)
    #         self.get_logger().info(f"V:{self.v}, W:{self.w}")
    #         self.get_logger().info(f"for:{joy_x}, back:{joy_y}")
    #     else:
    #         joy_x = 0
    #         joy_y = 0
    #         self.whill.send_joystick(int(0), int(0))
    #         command_bytes = [self.whill.CommandID.SET_JOYSTICK,
    #                          self.whill.UserControl.ENABLE, 0, 0]
    #         self.whill.send_command(command_bytes)
    #     self.whill.refresh()

    def mainloop(self):
        """メインの実行関数\n
        コンストラクタで設定した制御周期で速度コマンドを送信する．
        """
        # マニュアル操作をチェック
        joy_x = self.whill.joy_x
        joy_y = self.whill.joy_y
        # Joy入力があった時刻を保持
        if joy_x != 0 and joy_y != 0:
            self.whill.last_joy_time = time()
        # 制御指令を送信(安全のためマニュアル操作割り込み有)
        if (time() < 1.0 + self.sub_vel_t 
            and joy_x == 0 and joy_y == 0
            and (time() - self.whill.last_joy_time) > self.whill.joy_suppression_time):
            a, b = self.whill.velocity2cmd(self.v, self.w)
            self.whill.send_velocity(front=int(a), side=int(b))
            self.get_logger().info(f"V:{self.v}, W:{self.w}")
            self.get_logger().info(f"CmdV:{a}, CmdW:{b}")
        else:
            front = 0
            side = 0
            #self.whill.send_velocity(int(0), int(0))
            front_up = (front & 0xFF00) >> 8
            front_low = (front & 0x00FF)
            side_up = (side & 0xFF00) >> 8
            side_low = (side & 0x00FF)
            command_bytes = [self.whill.CommandID.SET_VELOCITY,
                             self.whill.UserControl.ENABLE,
                             front_up, front_low,
                             side_up, side_low]
            self.whill.send_command(command_bytes)
        self.whill.refresh()


def main(args=None):
    rclpy.init(args=args)
    ros = node()
    ros.get_logger().info('WHILL ready!!')
    try:
        rclpy.spin(ros)  # ROSのコールバック実行・終了待機
    except KeyboardInterrupt:
        ros.get_logger().info('Shutdown')
    except:
        traceback.print_exc()  # エラーが発生した場合のエラー出力

    # システムが終了するときには必ず．ジョイスティックコマンドが[0,0]を出力
    ros.whill.send_joystick(int(0), int(0))
    #ros.whill.send_velocity(int(0), int(0))
    sleep(1)
    ros.whill.send_power_on_com(0)  # 電源OFF

    # ROSノードの終了
    ros.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
