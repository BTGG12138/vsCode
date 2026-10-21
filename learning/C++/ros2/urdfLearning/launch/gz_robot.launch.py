import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
import xacro  # 必须导入xacro

def generate_launch_description():
    pkg_cpp_demo = get_package_share_directory('cpp_demo')
    robot_xacro_path = os.path.join(pkg_cpp_demo, 'urdf', 'third_robot.xacro')

    default_world = os.path.join(os.path.expanduser('~'), 'Desktop/vsSoup/_ws/cpp_demo/urdf', 'living_room.sdf')
    world = LaunchConfiguration('world')

    # 解析xacro，展开宏
    robot_description = xacro.process_file(robot_xacro_path).toxml()

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}]
    )

    # ========== 新增 joint_state_publisher ==========
    joint_state_publisher = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
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
        arguments=['-topic', '/robot_description', '-z', '0.15'],
        output='screen'
    )

    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            # ROS -> GZ 速度指令
            '/cmd_vel@geometry_msgs/msg/Twist[gz.msgs.Twist',
            # GZ -> ROS 里程计
            '/odom@nav_msgs/msg/Odometry@gz.msgs.Odometry',
            # GZ -> ROS TF
            '/tf@tf2_msgs/msg/TFMessage@gz.msgs.Pose_V',
            # ========== 修改joint_state桥接，移除写死的world名 ==========
            '/model/third_robot/joint_state@sensor_msgs/msg/JointState@gz.msgs.JointState',
            # 激光雷达
            '/model/third_robot/link/laser_link/sensor/laserscan@sensor_msgs/msg/LaserScan@gz.msgs.LaserScan',
            # 仿真时钟
            '/clock@rosgraph_msgs/msg/Clock@gz.msgs.Clock',
        ],
        output='screen'
    )

    return LaunchDescription([
        DeclareLaunchArgument('world', default_value=default_world),
        robot_state_publisher,
        joint_state_publisher, # 加入节点
        gz_sim,
        create_robot,
        bridge
    ])
