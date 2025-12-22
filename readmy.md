# Start the project the ros2 use the docker.

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
# Start install img the ros2
```
    docker pull osrf/ros:foxy-desktop
```
This command go the Download the img for presonal PC in this img are intalled ros2.
Use the next command for verficate if image is instaled.
```bash
docker images
```
Now can the start the img using the next command:
```
    docker run -it <image_name> /bin/bash
```
This command open the terminal in uor comtainer. The image_name is name for get the command `docker images`. 
Ok , run the our comtainer but if we exit we lose all our code.To solve this we have to create a volume this it a 
will be a path that linkd a real pc.
```
 docker run -it -v ./src:/src  ros:humble /bin/bash
```
     
