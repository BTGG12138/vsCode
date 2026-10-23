import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, EmitEvent, RegisterEventHandler
from launch.conditions import IfCondition
from launch.events import matches_action
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node, LifecycleNode
from launch_ros.event_handlers import OnStateTransition
from launch_ros.events.lifecycle import ChangeState
from lifecycle_msgs.msg import Transition
import xacro  # 必须导入xacro

def generate_launch_description():
    pkg_cpp_demo = get_package_share_directory('cpp_demo')
    robot_xacro_path = os.path.join(pkg_cpp_demo, 'urdf', 'robot.xacro')

    #/home/btgg/Desktop/vsSoup/_ws/cpp_demo/urdf/room.sdf
    default_world = os.path.join(os.path.expanduser('~'), 'Desktop/vsSoup/_ws/cpp_demo/urdf', 'room.sdf')
    world = LaunchConfiguration('world')

    # 解析xacro，展开宏
    robot_description = xacro.process_file(robot_xacro_path).toxml()

    # 注意：仿真里所有节点必须统一 use_sim_time=true（用 /clock 仿真时钟），
    # 否则消息用墙钟时间戳、数据用仿真时间戳，rviz 会报
    # "Message Filter dropping message ... queue is full"，slam 也查不到 TF
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description, 'use_sim_time': True}]
    )

    # ========== 新增 joint_state_publisher ==========
    joint_state_publisher = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        parameters=[{'use_sim_time': True}],
    )

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('ros_gz_sim'), 'launch', 'gz_sim.launch.py')
        ),
        launch_arguments={'gz_args': ['-v 4 -r ', world]}.items()
    )

    create_robot = Node(
        package='ros_gz_sim',
        executable='create',
        # 模型原点是 base_footprint，距轮子接地点 0，稍抬高一点防止穿模
        arguments=['-topic', 'robot_description', '-z', '0.05'],
        output='screen'
    )

    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        parameters=[{'use_sim_time': True}],
        arguments=[
            # ROS -> GZ 速度指令：方向必须是 ] (ROS流向GZ)。
            # 写成 [ 的话指令发不进仿真，机器人完全不动
            '/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            # GZ -> ROS 里程计
            '/odom@nav_msgs/msg/Odometry[gz.msgs.Odometry',
            # GZ -> ROS TF：必须单向 [，双向 @ 会把 robot_state_publisher 的
            # 静态 TF 回灌进 gz 造成循环，odom->base_footprint 会丢
            '/tf@tf2_msgs/msg/TFMessage[gz.msgs.Pose_V',
            # 轮子关节角不桥接：当前 ros_gz_bridge 没有
            # gz.msgs.JointState <-> sensor_msgs/JointState 的转换模板，
            # 桥了只会报 "No template specialization" 警告；
            # rviz 里的轮子角度由 joint_state_publisher 提供
            # ========== 激光雷达（话题与 laser_plugin.xacro 里的 <topic>/scan</topic> 一致） ==========
            '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            # ========== 深度相机 camera01（rgbd_camera 自动派生出的子话题） ==========
            '/depth_camera/image@sensor_msgs/msg/Image[gz.msgs.Image',
            '/depth_camera/depth_image@sensor_msgs/msg/Image[gz.msgs.Image',
            '/depth_camera/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
            '/depth_camera/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            # ========== RGB 相机 camera02 ==========
            '/camera02/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/camera02/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            # 仿真时钟：gz-sim 的根级 /clock 不发布数据（实测），必须桥接
            # world 级 clock（/world/<world名>/clock），并 remap 到 ROS /clock。
            # 若 /clock 无数据，所有 use_sim_time 节点的 timer 都不会触发
            # （典型症状：joint_state_publisher 不发布，轮子没有 TF）
            '/world/tianzi_maze_size_11/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            # world 级 clock 话题 remap 成 ROS 标准的 /clock
            '--ros-args', '-r', '/world/tianzi_maze_size_11/clock:=/clock',
        ],
        output='screen'
    )

    # ========== slam_toolbox 在线建图：订阅 /scan + odom TF，发布 /map 和 map->odom TF ==========
    # slam_toolbox 是 lifecycle 节点，必须用 LifecycleNode 启动并触发
    # configure -> activate，否则它停在 unconfigured，不会订阅 /scan
    slam_params = os.path.join(pkg_cpp_demo, 'config', 'slam_toolbox.yaml')
    slam = LifecycleNode(
        package='slam_toolbox',
        executable='sync_slam_toolbox_node',
        name='slam_toolbox',
        namespace='',
        output='screen',
        parameters=[slam_params],
        condition=IfCondition(LaunchConfiguration('slam')),
    )

    slam_configure = EmitEvent(
        event=ChangeState(
            lifecycle_node_matcher=matches_action(slam),
            transition_id=Transition.TRANSITION_CONFIGURE
        ),
        condition=IfCondition(LaunchConfiguration('slam')),
    )

    slam_activate = RegisterEventHandler(
        OnStateTransition(
            target_lifecycle_node=slam,
            start_state='configuring',
            goal_state='inactive',
            entities=[
                EmitEvent(event=ChangeState(
                    lifecycle_node_matcher=matches_action(slam),
                    transition_id=Transition.TRANSITION_ACTIVATE
                ))
            ]
        ),
        condition=IfCondition(LaunchConfiguration('slam')),
    )

    # rviz2：显示机器人模型、激光雷达扫描、地图、深度相机点云/图像
    rviz2 = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', os.path.join(pkg_cpp_demo, 'config', 'robot.rviz')],
        condition=IfCondition(LaunchConfiguration('rviz')),
        parameters=[{'use_sim_time': True}],
        output='screen'
    )

    return LaunchDescription([
        DeclareLaunchArgument('world', default_value=default_world),
        DeclareLaunchArgument('rviz', default_value='true', description='启动 rviz2'),
        DeclareLaunchArgument('slam', default_value='true', description='启动 slam_toolbox 建图'),
        robot_state_publisher,
        joint_state_publisher, # 加入节点
        gz_sim,
        create_robot,
        bridge,
        slam,
        slam_configure,
        slam_activate,
        rviz2
    ])
