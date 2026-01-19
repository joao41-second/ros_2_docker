# Start the project the ros2 using the docker.

install docker:
```bash
sudo apt update
sudo apt install -y docker.io
sudo systemctl start docker
sudo systemctl enable docker
```
install docker Compose:
```bash
sudo apt update
sudo apt install -y docker-compose
```
# Start instaling the image of the ros2
```
    docker pull osrf/ros:foxy-desktop
```
This command makes the Download of the image for personal PC. In this image is intalled ros2.
Use the next command to check if image is instaled.
```bash
docker images
```
Now to start the img use the next command:
```
    docker run -it <image_name> /bin/bash
```
This command opens the terminal in your container. The image_name is the name to get the command `docker images`. 
Ok ,run your container but if you exit you lose all your code.To solve this you have to create a volume. This 
will be a path that links to a real pc.
```
 docker run -it -v ./src:/src  ros:humble /bin/bash
```

