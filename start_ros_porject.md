For start the ros2 project we must set the source.
The source execute the list the commands to create a development environment.
in docker execute the coamnd.
'''
 source /opt/ros/humble/setup.sh
'''
Next step is create the folder for our project:
(in this project we only let's go to folder /src)
'''
mdkir  -p ros2_ws/src 
cd ~/ros2_ws
'''

The next step is cirate project extructur use the next command.
'''
ros2 pkg create ./src/packge --build-type ament_cmake --dependencies rclcpp std_msgs
'''
This command create a packge in disk package exit the nodes.

The next step is create code in c++ in folder ./src/package/src.
For execute the code use the:
'''bash
 cd /src
 colcon  build # commpile the project
 ros2 run <name_package> <node_name>
'''



