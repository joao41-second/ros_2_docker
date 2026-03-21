
ROBOT_NAME = base_link_p3_description 

help: ## list the comands
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
all: ## Start the docker and open the bash terminal 
	@cd ./docker/  && docker compose up -d --build 
	docker exec -it ros_2_h /bin/bash 
run_robot: ## Open the robot seted in variable name 
	@docker exec  ros_2_h /bin/bash ./project/scripts/run_robot.sh $(ROBOT_NAME)
