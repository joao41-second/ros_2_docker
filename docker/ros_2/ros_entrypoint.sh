#!/bin/bash

echo ¨start the source¨
set -e

source /opt/ros/foxy/setup.bash

#exec "$@"
exec gazebo --verbose  -s libgazebo_ros_factory.so /app/simulator/words/word1.world 
