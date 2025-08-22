from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from launch.actions import TimerAction
import os
import xacro

def generate_launch_description():
    electric_wc_dir = get_package_share_directory('electric_wheelchair')
    # controller_yaml = os.path.join(electric_wc_dir, 'config', 'controller.yaml')

    # コントローラのspawner（controller_manager自体はgazebo_ros2_control pluginが自動起動する

    joint_state_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster', '--controller-manager', '/wheelchair/controller_manager'],
        output='screen'
    )

    diff_drive_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['diff_drive_controller', '--controller-manager', '/wheelchair/controller_manager'],
        output='screen'
    )

    caster_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=[
            'caster_velocity_controller',
            '--controller-manager', '/wheelchair/controller_manager'
        ],
        output='screen'
        )


     # Gazebo が plugin 初期化を完了するまで待ってからコントローラを起動
    # delayed_controller_spawner = TimerAction(
    #       period=3.0,  # Gazebo server/plugin が立ち上がるまでの猶予（秒）
    #       actions=[controller_spawner, diff_drive_spawner]
    # )

    delayed_joint_state = TimerAction(
        period=2.0,
        actions=[joint_state_spawner]
    )

    delayed_diff_drive = TimerAction(
        period=2.0,
        actions=[diff_drive_spawner]
    )

    delayed_caster_controller = TimerAction(
        period=2.0,  # 他のcontrollerより遅らせる
        actions=[caster_controller_spawner]
    )
    # robot_state_publisher = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     parameters=[{'robot_description': robot_description_content}],
    #     output='screen'
    # )
    # Joint state publisher
    # joint_state_publisher = Node(
    #     package='joint_state_publisher',
    #     executable='joint_state_publisher',
    #     name='wheelchair',
    #     output='screen'
    # )

    # joint_state_publisherは通常不要（robot_state_publisherのみでOK）
    return LaunchDescription([
        # robot_state_publisher,
        # joint_state_publisher,
        # delayed_controller_spawner,
        delayed_joint_state,
        delayed_diff_drive,
        delayed_caster_controller,
        # controller_spawner,
        # diff_drive_spawner
    ])
# from launch import LaunchDescription
# from launch_ros.actions import Node
# from launch.actions import DeclareLaunchArgument
# from ament_index_python.packages import get_package_share_directory
# from launch.conditions import IfCondition, UnlessCondition
# import os

# def generate_launch_description():
#     electric_wc_dir = get_package_share_directory('electric_wheelchair')
#     controller_yaml = os.path.join(electric_wc_dir, 'config', 'controller.yaml')

#     # Controller spawner node
#     controller_spawner = Node(
#         package='controller_manager',
#         executable='spawner',
#         name='controller_spawner',
#         namespace='wheelchair',
#         output='screen',
#         arguments=['joint_state_controller', 'diff_drive_controller']
#     )

#     # Robot state publisher
#     robot_state_publisher = Node(
#         package='robot_state_publisher',
#         executable='robot_state_publisher',
#         name='robot_state_publisher',
#         output='screen'
#     )

#     # Joint state publisher
#     joint_state_publisher = Node(
#         package='joint_state_publisher',
#         executable='joint_state_publisher',
#         name='joint_state_publisher',
#         output='screen'
#     )

#     return LaunchDescription([
#         # Load parameters from YAML
#         Node(
#             package='rclcpp_components',  # This triggers param loading indirectly
#             executable='component_container',
#             name='param_loader_dummy',
#             parameters=[controller_yaml],
#             output='log'
#         ),
#         controller_spawner,
#         robot_state_publisher,
#         joint_state_publisher
#     ])
