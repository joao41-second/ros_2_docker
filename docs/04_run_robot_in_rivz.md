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
