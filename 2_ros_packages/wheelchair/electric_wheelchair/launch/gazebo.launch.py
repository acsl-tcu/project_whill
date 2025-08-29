from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration, Command
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os
from launch.actions import TimerAction
import subprocess
from launch.actions import SetEnvironmentVariable
import xacro
from launch.actions import ExecuteProcess
from launch.actions import OpaqueFunction
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import EnvironmentVariable
from launch.substitutions import TextSubstitution

def launch_setup(context, *args, **kwargs):
    use_sim_time = (LaunchConfiguration('use_sim_time').perform(context).lower() == 'true')
    gpu          = LaunchConfiguration('gpu').perform(context)
    xacro_file   = os.path.join(
        get_package_share_directory('electric_wheelchair'),
        'xacro', 'wheelchair_2.xacro')
    pkg_electric_wheelchair = get_package_share_directory('electric_wheelchair')
    config_path = os.path.join(pkg_electric_wheelchair, 'config', 'controller.yaml')

    # Gazebo 用（model://）------------------
    doc_gz = xacro.process_file(
        xacro_file,
        mappings={'gpu': gpu, 
                  'for_gazebo': 'true',
                  'robotNamespace': 'wheelchair',
                  'controller_yaml': config_path
                  })
    # ファイルに保存して spawn_entity に渡す
    wheelchair_urdf_file = os.path.join(pkg_electric_wheelchair, 'urdf', 'wheelchair.urdf')
    gz_robot_path = wheelchair_urdf_file
    with open(gz_robot_path, 'w') as f:
        f.write(doc_gz.toxml())

    # RViz2／robot_state_publisher 用（package://）---
    doc_rviz = xacro.process_file(
        xacro_file,
        mappings={'gpu': gpu, 
                  'for_gazebo': 'false',
                  'robotNamespace': 'wheelchair',
                  'controller_yaml': config_path
                  })
    robot_desc_rviz = {'robot_description': doc_rviz.toxml()}

    rsp_node = Node(
        package   ='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        namespace= 'wheelchair',
        parameters=[robot_desc_rviz, {'use_sim_time': use_sim_time}],
        output    ='screen')

    # delete_entity = ExecuteProcess(
    #     cmd=['ros2', 'service', 'call', '/delete_entity', 'gazebo_msgs/srv/DeleteEntity', '{name: "wheelchair"}'],
    #     shell=True,
    #     output='screen'
    # )

    # Gazebo へスポーン
    spawn_node = TimerAction(
        period=1.0,
        actions=[Node(
            package   ='gazebo_ros',
            executable='spawn_entity.py',
            arguments =['-entity', 'wheelchair',
                        '-file',   gz_robot_path,         # ← Topic ではなくファイルで渡す
                        '-x', LaunchConfiguration('x'),
                        '-y', LaunchConfiguration('y'),
                        '-z', LaunchConfiguration('z'),
                        '-R', LaunchConfiguration('roll'),
                        '-P', LaunchConfiguration('pitch'),
                        '-Y', LaunchConfiguration('yaw')],
            output='screen')])

    # RViz2
    rviz_cfg  = os.path.join(
        get_package_share_directory('velodyne_description'),
        'rviz', 'example.rviz')
    rviz_node = Node(
        condition =IfCondition(LaunchConfiguration('rviz')),
        package   ='rviz2',
        executable='rviz2',
        arguments =['-d', rviz_cfg],
        output    ='screen')
    
    # model_path = PathJoinSubstitution([
    #     FindPackageShare('gazebo_sfm_plugin'),
    #     'models'
    # ])

    # set_model_path = SetEnvironmentVariable(
    #     'GAZEBO_MODEL_PATH',
    #     [EnvironmentVariable('GAZEBO_MODEL_PATH'), ':', model_path]
    # )

    # set_resource_path = SetEnvironmentVariable(
    #     'GAZEBO_RESOURCE_PATH',
    #     [EnvironmentVariable('GAZEBO_RESOURCE_PATH'), ':', model_path]
    # )

    # set_plugin_path = SetEnvironmentVariable(
    #     'GAZEBO_PLUGIN_PATH',
    #     [EnvironmentVariable('GAZEBO_PLUGIN_PATH'), ':', TextSubstitution(text='/root/ros2_ws/install/gazebo_sfm_plugin/lib')]
    # )

    # return [rsp_node, spawn_node, set_model_path, set_resource_path, set_plugin_path, rviz_node]
    return [rsp_node, spawn_node, rviz_node]


def generate_launch_description():
    # パッケージパス
    pkg_create_world = get_package_share_directory('create_world')
    pkg_electric_wheelchair = get_package_share_directory('electric_wheelchair')
    pkg_velodyne_description = get_package_share_directory('velodyne_description')

    # Xacroパス
    wheelchair_xacro_file = os.path.join(pkg_electric_wheelchair, 'xacro', 'wheelchair_2.xacro')
    wheelchair_urdf_file = os.path.join(pkg_electric_wheelchair, 'urdf', 'my_robo.urdf')
    wheelchair_mesh= os.path.join(pkg_electric_wheelchair, 'models','electric_wheelchair')
    static_obstacle_xacro = os.path.join(pkg_electric_wheelchair, 'xacro', 'static.urdf.xacro')
    # world_dir = os.path.join(pkg_create_world, 'models', '3rd_floor')

    world_dir = os.path.join(pkg_create_world,
        'world',
        'school3F.world')

    # world_dir = os.path.join(get_package_share_directory('gazebo_sfm_plugin'),
    #     'worlds',
    #     'cafe3.world')

    # ★ Python xacro API で一度 URDF 化する
    #    （必要な引数があれば mappings={'gpu':'true'} などで渡せます）
    # doc = xacro.process_file(wheelchair_xacro_file)
    # urdf_xml = doc.toxml()

    # # xacro→URDF を展開
    # subprocess.check_output(['xacro', wheelchair_xacro_file]).decode()

    # # 1) URDF を一度だけ /robot_description トピックに送る
    # publish_urdf = ExecuteProcess(
    #     cmd=[
    #         'ros2 ', 'topic ', 'pub ', '--once ',
    #         '/robot_description ', 'std_msgs/msg/String ',
    #         f"{{data: '''{urdf}'''}}"
    #     ],
    #     shell=False,
    # )

    # print('wheelchair_xacro_file:', world_dir)

    # Launch arguments
    launch_args = [
        DeclareLaunchArgument('paused', default_value='false'),
        DeclareLaunchArgument('use_sim_time', default_value='true'),
        DeclareLaunchArgument('gui', default_value='true'),
        DeclareLaunchArgument('headless', default_value='false'),
        DeclareLaunchArgument('debug', default_value='false'),
        DeclareLaunchArgument('world_name', default_value=world_dir),
        DeclareLaunchArgument('x', default_value='0'),
        DeclareLaunchArgument('y', default_value='0'),
        DeclareLaunchArgument('z', default_value='0'),
        DeclareLaunchArgument('roll', default_value='0'),
        DeclareLaunchArgument('pitch', default_value='0'),
        DeclareLaunchArgument('yaw', default_value='0'),
        DeclareLaunchArgument('gpu', default_value='true'),
        DeclareLaunchArgument('rviz', default_value='true'),
        DeclareLaunchArgument('x_obs101', default_value='8.0'),
        DeclareLaunchArgument('y_obs101', default_value='-0.6'),
        DeclareLaunchArgument('z_obs101', default_value='0'),
        DeclareLaunchArgument('roll_obs101', default_value='0'),
        DeclareLaunchArgument('pitch_obs101', default_value='0'),
        DeclareLaunchArgument('yaw_obs101', default_value='0'),
    ]
    # print('sc_xacro_file:', os.path.join(pkg_create_world, 'world', 'school3F.world'))
    # Gazebo world 起動
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')
        ),
        launch_arguments={
            'factory': 'true',
            'world': LaunchConfiguration('world_name'),
            'paused': LaunchConfiguration('paused'),
            'gui': LaunchConfiguration('gui'),
            'headless': LaunchConfiguration('headless'),
            'debug': LaunchConfiguration('debug'),
            # 'verbose': 'true',
        }.items()
    )


    model_path = os.path.join(get_package_share_directory('gazebo_sfm_plugin'), 'models')

    # set_model_path = SetEnvironmentVariable(
    #     'GAZEBO_MODEL_PATH',
    #     [EnvironmentVariable('GAZEBO_MODEL_PATH'), ':', model_path]
    # )

    # set_resource_path = SetEnvironmentVariable(
    #     'GAZEBO_RESOURCE_PATH',
    #     [EnvironmentVariable('GAZEBO_RESOURCE_PATH'), ':', model_path]
    # )


    # 環境変数：mesh と world のパスを Gazebo に渡す
    set_res_paths = [
        SetEnvironmentVariable(
            name='GAZEBO_MODEL_PATH',
            value=[
                EnvironmentVariable('GAZEBO_MODEL_PATH', default_value=''),
                TextSubstitution(text=':'),
                wheelchair_mesh,
                TextSubstitution(text=':'),
                world_dir,
                TextSubstitution(text=':'),
                model_path
            ]
        ),
        SetEnvironmentVariable(
            name='GAZEBO_RESOURCE_PATH',
            value=[
                EnvironmentVariable('GAZEBO_RESOURCE_PATH', default_value=''),
                TextSubstitution(text=':'),
                PathJoinSubstitution([wheelchair_mesh, 'meshes']),
                TextSubstitution(text=':'),
                PathJoinSubstitution([world_dir, 'meshes']),
                TextSubstitution(text=':'),
                model_path
            ]
        )
    ]
    # set_res_paths = [
    #     SetEnvironmentVariable(
    #         'GAZEBO_MODEL_PATH',
    #         ':'.join([
    #             os.environ.get('GAZEBO_MODEL_PATH', ''),
    #             wheelchair_mesh,
    #             world_dir,
    #             model_path
    #         ])
    #     ),
    #     SetEnvironmentVariable(
    #         'GAZEBO_RESOURCE_PATH',
    #         ':'.join([
    #             os.environ.get('GAZEBO_RESOURCE_PATH', ''),
    #             os.path.join(wheelchair_mesh, 'meshes'),
    #             os.path.join(world_dir, 'meshes'),
    #             model_path
    #         ])
    #     )
    # ]

    set_plugin_path = SetEnvironmentVariable(
        'GAZEBO_PLUGIN_PATH',
        [EnvironmentVariable('GAZEBO_PLUGIN_PATH'), ':', TextSubstitution(text=os.path.join(get_package_share_directory('gazebo_sfm_plugin'), 'lib'))]
    )

    # set_res_paths = [
    #     SetEnvironmentVariable('GAZEBO_RESOURCE_PATH',
    #         os.environ.get('GAZEBO_RESOURCE_PATH','') + ':' + os.path.join(wheelchair_mesh, 'meshes')),
    #     SetEnvironmentVariable('GAZEBO_MODEL_PATH', os.environ.get('GAZEBO_MODEL_PATH', '') + ':' + wheelchair_mesh),
    #     SetEnvironmentVariable('GAZEBO_RESOURCE_PATH',
    #         os.environ.get('GAZEBO_RESOURCE_PATH', '') + ':' + os.path.join(world_dir, 'meshes')),
    #     SetEnvironmentVariable('GAZEBO_MODEL_PATH', os.environ.get('GAZEBO_MODEL_PATH','') + ':' + world_dir),
    # ]

    # robot_state_publisher に URDF 文字列をそのまま渡す
    # rsp = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     output='screen',
    #     parameters=[
    #         {'robot_description': open(wheelchair_urdf_file).read()},
    #         {'use_sim_time': LaunchConfiguration('use_sim_time')},
    #     ],
    # )

    # use_xacro = True
    # if use_xacro:
    #     robot_description_content = xacro.process_file(wheelchair_xacro_file).toxml()
    # else:
    #     robot_description_content = open(wheelchair_urdf_file).read()

    # robot_state_publisher = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     name='robot_state_publisher',
    #     parameters=[
    #         {'robot_description': robot_description_content},
    #         {'use_sim_time': LaunchConfiguration('use_sim_time')},
    #     ],
    #     output='screen'
    # )

    # robot_state_publisher = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     name='robot_state_publisher',
    #     parameters=[{'robot_description': open(wheelchair_urdf_file).read()}],
    #     output='screen'
    # )

    # robot_state_publisher, wheelchair_spawn, rviz_launch  = launch_setup(True)
    wheelchair_setup = OpaqueFunction(function=launch_setup)

    # wheelchair_spawn = Node(
    #     package='gazebo_ros',
    #     executable='spawn_entity.py',
    #     arguments=[
    #         '-entity', 'wheelchair',
    #         # '-file', wheelchair_urdf_file,
    #         '-topic', 'robot_description',
    #         # '-param', 'robot_description',  # パラメータから読み込む
    #         # '-robot_namespace', 'wheelchair',  # ここで名前空間を与える
    #         '-x', LaunchConfiguration('x'),
    #         '-y', LaunchConfiguration('y'),
    #         '-z', LaunchConfiguration('z'),
    #         '-Y', LaunchConfiguration('yaw'),
    #     ],
    #     output='screen'
    # )

    # robot_state_publisher = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     namespace='',
    #     name='robot_state_publisher',
    #     # parameters=[{'robot_description': robot_description_content}],
    #     parameters=[{'robot_description': open(wheelchair_urdf_file).read()}],
    #     output='screen'
    # )

    # wheelchair_spawn = Node(
    #     package='gazebo_ros',
    #     executable='spawn_entity.py',
    #     namespace='wheelchair',
    #     parameters=[
    #         {'robot_description': open(wheelchair_urdf_file).read()}
    #     ],
    #     arguments=[
    #         '-entity', 'wheelchair',
    #         '-file', wheelchair_urdf_file,
    #         # '-topic', 'robot_description',
    #         # '-param', 'robot_description',
    #         # '-robot_namespace', 'wheelchair',
    #         '-x', LaunchConfiguration('x'),
    #         '-y', LaunchConfiguration('y'),
    #         '-z', LaunchConfiguration('z'),
    #         '-Y', LaunchConfiguration('yaw'),
    #     ],
    #     output='screen',
    # )

    # control_spawner = Node(
    #     package='controller_manager',
    #     executable='spawner',
    #     namespace='wheelchair',
    #     arguments=['joint_state_controller', 'diff_drive_controller',
    #                '--controller-manager', '/wheelchair/controller_manager'
    #                ],
    #     output='screen'
    # )

    # joint_state_spawner = Node(
    #     package='controller_manager',
    #     executable='spawner',
    #     namespace='wheelchair',
    #     arguments=['joint_state_controller',
    #             '--controller-manager', '/wheelchair/controller_manager'],
    #     output='screen'
    # )

    # diff_drive_spawner = Node(
    #     package='controller_manager',
    #     executable='spawner',
    #     namespace='wheelchair',
    #     arguments=['diff_drive_controller',
    #             '--controller-manager', '/wheelchair/controller_manager'],
    #     output='screen'
    # )


    # delayed_joint_state = TimerAction(
    #     period=3.0,  # 5秒遅延
    #     actions=[joint_state_spawner]
    # )
    # delayed_diff_drive = TimerAction(
    #     period=3.0,  # 5秒遅延
    #     actions=[diff_drive_spawner]
    # )

    # --- Electric wheelchair ---
    # robot_description_content=Command(['xacro', wheelchair_xacro_file])

    # urdf_xml = subprocess.check_output(['xacro', wheelchair_xacro_file]).decode()

    # static_tf = Node(
    #     package='tf2_ros',
    #     executable='static_transform_publisher',
    #     name='static_world_to_base',
    #     arguments=['0','0','0','0','0','0','world','base_link'],
    # )

    # root_rsp = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     namespace='',  # ルート名前空間
    #     parameters=[{
    #     'robot_description': open(wheelchair_urdf_file).read(),
    #     'use_sim_time': True
    #     }],
    #     output='screen'
    # )
    # print('wheelchair_xacro_file:', wheelchair_xacro_file)
    # print("Command引数:", ['xacro ', wheelchair_xacro_file])

    # delayed_robot_state_publisher = TimerAction(period=3.0, actions=[robot_state_publisher])
    # delayed_wheelchair_spawn = TimerAction(period=3.0, actions=[wheelchair_spawn])
    # delayed_control_spawner = TimerAction(period=1.0, actions=[control_spawner])

    # --- Static obstacle 101 ---
    # obstacle_description_101 = Command(['xacro ', static_obstacle_xacro, 'gpu:=', LaunchConfiguration('gpu')])
    # robot_state_publisher_101 = Node(
    #     package='robot_state_publisher',
    #     executable='robot_state_publisher',
    #     name='robot_state_publisher101',
    #     parameters=[{'robot_description': obstacle_description_101}]
    # )
    # spawn_obstacle_101 = Node(
    #     package='gazebo_ros',
    #     executable='spawn_entity.py',
    #     name='spawn_obstacle101',
    #     arguments=[
    #         '-entity', 'obstacle101',
    #         '-topic', 'obstacle_description101',
    #         '-x', LaunchConfiguration('x_obs101'),
    #         '-y', LaunchConfiguration('y_obs101'),
    #         '-z', LaunchConfiguration('z_obs101'),
    #         '-Y', LaunchConfiguration('yaw_obs101')
    #     ],
    #     output='screen'
    # )

    # --- コントローラなどのlaunch include例 ---
    control_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(pkg_electric_wheelchair, 'launch', 'control.launch.py')
        ])
    )

    # --- RViz ---
    # rviz_launch = TimerAction(
    #     period=3.0,  # コントローラ spawn 後に合わせる
    #     actions=[
    #         Node(
    #             package='rviz2',
    #             executable='rviz2',
    #             arguments=[
    #                 '-d', os.path.join(pkg_velodyne_description, 'rviz', 'example.rviz')
    #             ],
    #             condition=IfCondition(LaunchConfiguration('rviz')),
    #             output='screen'
    #         )
    #     ]
    # )

    return LaunchDescription(
        set_res_paths + 
        launch_args + 
        [
            # オンライン問い合わせをオフ（任意）
            SetEnvironmentVariable('GAZEBO_MODEL_DATABASE_URI', ''),
            gazebo_launch,
            # wheelchair_spawn,

            wheelchair_setup,
            # control_spawner,
            # delayed_control_spawner,
            # delayed_joint_state,
            # delayed_diff_drive,
            # publish_urdf,
            set_plugin_path,

            # robot_state_publisher,

            # robot_state_publisher_101,
            # spawn_obstacle_101,
            control_launch,

            # rviz_launch,
            
            # static_tf,
            # rsp,
        ]
    )