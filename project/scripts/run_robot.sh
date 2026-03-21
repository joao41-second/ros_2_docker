
if [ -z "$1"]; then
	echo "the name not provided"
	exit -2
fi

cd project
source ./start.sh 
colcon build 
source ./start.sh 

ros2 launch $1 display.launch.py



