from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction, ExecuteProcess, IncludeLaunchDescription, SetEnvironmentVariable
from launch.conditions import IfCondition, UnlessCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch.conditions import IfCondition, UnlessCondition
import os
import xacro


def generate_launch_description():
    pkg_electric_wheelchair = get_package_share_directory('electric_wheelchair')
    wheelchair_xacro_file = os.path.join(pkg_electric_wheelchair, 'xacro', 'wheelchair_2.xacro')
    # Declare launch arguments
    host_ip_arg = DeclareLaunchArgument('hostIP', default_value='http://localhost:11345')
    logging_arg = DeclareLaunchArgument('logging', default_value='false')
    experiment_arg = DeclareLaunchArgument('experiment', default_value='false')

    electric_wc_dir = get_package_share_directory('electric_wheelchair')
    controller_yaml = os.path.join(
        get_package_share_directory('electric_wheelchair'),
        'config',
        'controller.yaml'
    )


    # モデルパスを通す（既存値に追記）
    model_path = os.path.join(pkg_electric_wheelchair, 'models', 'electric_wheelchair')
    gazebo_model_env = SetEnvironmentVariable(
        name='GAZEBO_MODEL_PATH',
        value=[TextSubstitution(text=model_path + ':'), EnvironmentVariable('GAZEBO_MODEL_PATH', default_value='')]
    )
    # プラグインパスも通す（factory/init などを確実に見せる）
    gazebo_plugin_env = SetEnvironmentVariable(
        name='GAZEBO_PLUGIN_PATH',
        value=[TextSubstitution(text='/opt/ros/humble/lib:'), EnvironmentVariable('GAZEBO_PLUGIN_PATH', default_value='')]
    )

    # model_path = f'{electric_wc_dir}/models/electric_wheelchair'
    # gazebo_env = SetEnvironmentVariable(
    #     name='GAZEBO_MODEL_PATH',
    #     value=f'{model_path}:$GAZEBO_MODEL_PATH'
    # )

    # SetEnvironmentVariable(
    # name='GAZEBO_PLUGIN_PATH',
    # value='/opt/ros/humble/lib:$GAZEBO_PLUGIN_PATH'
    # )

    # Conditional rosbag recording
    rosbag_record = ExecuteProcess(
        condition=IfCondition(LaunchConfiguration('logging')),
        cmd=['ros2', 'bag', 'record', '-a', '-o', '/root/Desktop/ex.bag'],
        output='screen'
    )

    # Conditional gazebo bridge and bridge node launch
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(electric_wc_dir, 'launch', 'gazebo.launch.py')
        ),
        condition=UnlessCondition(LaunchConfiguration('experiment'))
    )

    gazebo_bridge_node = Node(
        condition=UnlessCondition(LaunchConfiguration('experiment')),
        package='wheelchair_gazebo_bridge',
        executable='wheelchair_gazebo_bridge',
        name='gazebo_bridge',
        output='screen'
    )

    return LaunchDescription([
        host_ip_arg,
        logging_arg,
        experiment_arg,
        gazebo_model_env,
        gazebo_plugin_env,
        rosbag_record,
        gazebo_launch,
        gazebo_bridge_node,
        gazebo_env,
    ])