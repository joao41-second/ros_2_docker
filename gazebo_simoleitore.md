##gazebo 


The gazebo is the simoleitor at use in this project. 


#if gazebo no open in docker execute the command 
```
xhost +local:docker
```
add in trminal config file for set defenitive 


# start gazebo
if start gazebo and use ros2 use the next command.
```
gazebo world.world  
ros2 launch gazebo_ros gazebo.launch.py -> this command avoid most problemes
```

# spawn_entity in gazebo 
```
ros2 run gazebo_ros spawn_entity.py -entity square_robot -file ./robot_basic.urdf -x 0 -y 0 -z 0.1
```


ros2 topic list
