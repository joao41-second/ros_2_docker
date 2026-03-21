if [ -z "$1"]; then
	echo "the name not provided"
	exit -2
fi

echo "\n \nesta a aqui "$2" \n \n" 
cd project
source ./start.sh 
colcon build 
source ./start.sh 

if [[ "$2" == "gazebo" ]]; then
	ros2 launch $1 gazebo.launch.py
elif [[ "$2" == "riv" ]]; then
	ros2 launch $1 display.launch.py
fi

