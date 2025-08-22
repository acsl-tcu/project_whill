# from launch import LaunchDescription
# from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction
# from launch.substitutions import LaunchConfiguration
# from launch_ros.actions import Node
# from launch.launch_description_sources import PythonLaunchDescriptionSource
# from ament_index_python.packages import get_package_share_directory
# import os
# import xacro

# def launch_setup(context, *args, **kwargs):
#     # 各ディレクトリ取得
#     electric_wc_dir = get_package_share_directory('electric_wheelchair')

#     # Launch引数から値を取得
#     gpu = LaunchConfiguration('gpu').perform(context)

#     # xacro 展開
#     xacro_file = os.path.join(electric_wc_dir, 'xacro', 'wheelchair_2.xacro')
#     doc = xacro.process_file(xacro_file, mappings={'gpu': gpu})
#     robot_description = {'robot_description': doc.toxml()}

#     # ノード定義
#     rsp_node = Node(
#         package='robot_state_publisher',
#         executable='robot_state_publisher',
#         parameters=[robot_description],
#         output='screen'
#     )

#     spawn_node = Node(
#         package='gazebo_ros',
#         executable='spawn_entity.py',
#         arguments=[
#             '-entity', 'wheelchair',
#             '-topic', 'robot_description'
#         ],
#         output='screen'
#     )

#     return [rsp_node, spawn_node]

# def generate_launch_description():
#     # create_world や gazebo_ros ディレクトリ
#     create_world_dir = get_package_share_directory('create_world')
#     gazebo_ros_dir = get_package_share_directory('gazebo_ros')

#     # Launch引数定義
#     declared_args = [
#         DeclareLaunchArgument('world_name', default_value=os.path.join(create_world_dir, 'world', 'school3F.world')),
#         DeclareLaunchArgument('use_sim_time', default_value='true'),
#         DeclareLaunchArgument('gui', default_value='true'),
#         DeclareLaunchArgument('paused', default_value='false'),
#         DeclareLaunchArgument('headless', default_value='false'),
#         DeclareLaunchArgument('debug', default_value='false'),
#         DeclareLaunchArgument('gpu', default_value='true')
#     ]

#     # Gazebo の launch を読み込む
#     gazebo = IncludeLaunchDescription(
#         PythonLaunchDescriptionSource(
#             os.path.join(gazebo_ros_dir, 'launch', 'gazebo.launch.py')
#         ),
#         launch_arguments={
#             'world': LaunchConfiguration('world_name'),
#             'paused': LaunchConfiguration('paused'),
#             'use_sim_time': LaunchConfiguration('use_sim_time'),
#             'gui': LaunchConfiguration('gui'),
#             'headless': LaunchConfiguration('headless'),
#             'debug': LaunchConfiguration('debug'),
#         }.items()
#     )

#     return LaunchDescription(declared_args + [gazebo, OpaqueFunction(function=launch_setup)])


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

    model_path = f'{electric_wc_dir}/models/electric_wheelchair'
    gazebo_env = SetEnvironmentVariable(
        name='GAZEBO_MODEL_PATH',
        value=f'{model_path}:$GAZEBO_MODEL_PATH'
    )

    SetEnvironmentVariable(
    name='GAZEBO_PLUGIN_PATH',
    value='/opt/ros/humble/lib:$GAZEBO_PLUGIN_PATH'
    )

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
        rosbag_record,
        gazebo_launch,
        gazebo_bridge_node,
        gazebo_env,
    ])