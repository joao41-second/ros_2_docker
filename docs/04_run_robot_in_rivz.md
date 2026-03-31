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
    joint_names: ['revolucionar_2','revolucionar_3','revolucionar_4','revolucionar_5','revolucionar_6','revolucionar_7','revolucionar_8','revolucionar_10','revolucionar_11','revolucionar_12'],
    points: [{
      positions: [0.0, 0.5, 0.5, 0.0, 0.0, 0.5, 0.0, 0.2, 0.0, 0.0],
      time_from_start: {sec: 2, nanosec: 0}
    }]
  }"
```
