##gazebo 


The gazebo is the simulator to be used in this project. 


# if gazebo does not  open, out of the docker execute the next command 
```
xhost +local:docker
```
To set this definitive config, add it in terminal config file.

# start gazebo
To start gazebo and use ros2, use the next command.Do not forget to define *source* so that ros2 works.
```
ros2 launch gazebo_ros gazebo.launch.py 
```

# spawn_entity in gazebo 
```
ros2 run gazebo_ros spawn_entity.py -entity square_robot -file ./robot_basic.urdf -x 0 -y 0 -z 0.1
```
This comand spawns the robot in the window of the gazebo. 

# utils
This command lists the communication chanels that are running in ros2.
```
ros2 topic list

 ros2 topic echo /cmd_vel -> print the /cmd_vel terminal
```


ros2 run gazebo_ros spawn_entity.py \
  -entity simple_robot \
  -file /app/project/src/my_robot_controller/urdf/simple_robot.urdf \
  -x 0 -y 0 -z 0.2

