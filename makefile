

all:
	cd ./docker/  && docker compose up -d --build 
	docker exec -it ros_2_h /bin/bash 
run_robot:
	docker exec  ros_2_h /bin/bash ./project/scripts/run_robot.sh 
