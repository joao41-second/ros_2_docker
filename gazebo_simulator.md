##gazebo 


The gazebo is the simoleitor at use in this project. 


#if gazebo no open in docker execute the command 
```
xhost +local:docker
```
Add in trminal config file for set defenitive 


# start gazebo
if start gazebo and use ros2 use the next command.
```
ros2 launch gazebo_ros gazebo.launch.py 
```

# spawn_entity in gazebo 
```
ros2 run gazebo_ros spawn_entity.py -entity square_robot -file ./robot_basic.urdf -x 0 -y 0 -z 0.1
```
# utils
This command list the comonication chanels exciting running in ros2.
```
ros2 topic list

 ros2 topic echo /cmd_vel -> print the /cmd_vel terminal
```


ros2 run gazebo_ros spawn_entity.py \
  -entity simple_robot \
  -file /app/project/src/my_robot_controller/urdf/simple_robot.urdf \
  -x 0 -y 0 -z 0.2

