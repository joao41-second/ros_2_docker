import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import xacro
from os.path import join


def generate_launch_description():

    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_ros_gz_rbot = get_package_share_directory('bart')

    robot_description_file = os.path.join(
        pkg_ros_gz_rbot,
        'urdf',
        'bart.xacro'
    )

    ros_gz_bridge_config = os.path.join(
        pkg_ros_gz_rbot,
        'config',
        'ros_gz_bridge_gazebo.yaml'
    )

    ros_control_config_file = os.path.join(
        pkg_ros_gz_rbot,
        'config',
        'controllers.yaml'
    )

    robot_description_config = xacro.process_file(robot_description_file)
    robot_description = {'robot_description': robot_description_config.toxml()}

    # -------------------------
    # Robot State Publisher
    # -------------------------
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[robot_description],
    )

    # -------------------------
    # Gazebo
    # -------------------------
    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            join(pkg_ros_gz_sim, "launch", "gz_sim.launch.py")
        ),
        launch_arguments={"gz_args": "-r -v 4 empty.sdf"}.items()
    )

    # -------------------------
    # Spawn robot
    # -------------------------
    spawn_robot = TimerAction(
        period=5.0,
        actions=[Node(
            package='ros_gz_sim',
            executable='create',
            arguments=[
                "-topic", "/robot_description",
                "-name", "bart",
                "-allow_renaming", "false",
                "-x", "0.0",
                "-y", "0.0",
                "-z", "0.32",
                "-Y", "0.0"
            ],
            output='screen'
        )]
    )

    # -------------------------
    # ros_gz_bridge
    # -------------------------
    ros_gz_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        parameters=[{'config_file': ros_gz_bridge_config}],
        output='screen'
    )

    # -------------------------
    # Lidar Topics Bridge (explicit bridge for LiDAR scan)
    # -------------------------
    lidar_bridge = Node(
    package='ros_gz_bridge',
    executable='parameter_bridge',
    arguments=[
        '/world/empty/model/bart/link/base_link/sensor/lidar/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan'
    ],
    remappings=[
        ('/world/empty/model/bart/link/base_link/sensor/lidar/scan', '/scan'),
    ],
    output='screen'
    )

    # -------------------------
    # controller_manager 
    # -------------------------

    controller_manager_node = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[ {'config_file':ros_control_config_file}],
        output='screen'
    )

    # -------------------------
    # controller_manager spawners
    # -------------------------
    joint_state_broadcaster_spawner = TimerAction(
        period=8.0,
        actions=[Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_state_broadcaster'],
            output='screen'
        )]
    )

    joint_trajectory_controller_spawner = TimerAction(
        period=10.0,
        actions=[Node(
            package='controller_manager',
            executable='spawner',
            arguments=['joint_trajectory_controller'],
            output='screen'
        )]
    )

    
    return LaunchDescription([
        gazebo,
        spawn_robot,
        ros_gz_bridge,
        lidar_bridge,
        robot_state_publisher,
        controller_manager_node,        # ← FALTA ESTE
        joint_state_broadcaster_spawner,
        joint_trajectory_controller_spawner
])
