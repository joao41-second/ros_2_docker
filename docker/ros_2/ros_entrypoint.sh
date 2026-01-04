#!/bin/bash

echo ¨start the source¨
set -e

source /opt/ros/foxy/setup.bash

exec "$@"
#exec gazebo --verbose  /app/simulator/words/word1.world -s libgazebo_ros_factory.so
