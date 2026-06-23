#Run the robot use 

when use the ROS2 for visualization the robot is normal using the two applications the rivz and gazebo.

The rivz is used for visualize junts and testing same. 
for execute use the  next commands.  
```
	ros2 launch (nome do pakage) gazebo.launch.py
    or 
    make run_robot // use the normal termiinal not in ros2 bash  
```
The gazebo using for testing the rial use de robot simutaing the real word 
```
	ros2 launch (nome do pakage) display.launch.py
    or 
    make run_robot_gazebo  // use the normal termiinal not in ros2 bash
```
Move _junts the robot unsig the command 
```
 ros2 topic pub --once /joint_trajectory_controller/joint_trajectory   trajectory_msgs/msg/JointTrajectory   "{
    joint_names: ['fix_1','Dir_E_T','Dir_E_F','Dir_D_F','Dir_D_T','Fix_2','Wheel_E_F','Wheel_D_T','Wheel_D_F','Wheel_E_T'],
    points: [{
      positions: [0.0, 0.5, 0.5, 0.0, 0.0, 0.5, 0.0, 0.2, 0.0, 0.0],
      time_from_start: {sec: 2, nanosec: 0}
    }]
  }"
ros2 topic pub --once /velocity_controller/joint_trajectory trajectory_msgs/msg/JointTrajectory "{
  joint_names: ['fix_1'],
  points: [{
    positions: [0.0],
    velocities: [2.0],
    time_from_start: {sec: 2}
  }]
}"

```
