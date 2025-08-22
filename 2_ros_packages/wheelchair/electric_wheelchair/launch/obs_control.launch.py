from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # パッケージディレクトリ
    pkg_electric_wheelchair = get_package_share_directory('electric_wheelchair')
    obs_controller_yaml = os.path.join(pkg_electric_wheelchair, 'config', 'obs_controller.yaml')

    return LaunchDescription([
        # コントローラのspawner（namespace: obstacle）
        Node(
            package='controller_manager',
            executable='spawner',
            name='obs_controller_spawner',
            namespace='obstacle',
            arguments=['joint_state_controller', 'diff_drive_controller'],
            parameters=[obs_controller_yaml],
            output='screen',
        ),
        # 状態をTFに変換するrobot_state_publisher
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='obs_state_publisher',
            namespace='obstacle',  # ←obsごとに分ける場合はここも合わせて
            output='screen',
        ),
    ])