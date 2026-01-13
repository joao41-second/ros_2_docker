# what create robot in ros2 and gazebo

No ros2 os robos foncionao com canais de comonicasao como o /cmd
Este canais premitem comunicsao entire o robo e o pc central or entre nods.
no casso do simulador vamos ter dois nods um que vai ser o codigo que corre no hardwere real 
e outro que vai ser o robot que fornece respostar para o /cmd como o hardwere real chamemos de real_node
ao nos basearmos no node de simulasao sera possivle indetificar errors  real_node.

## Use robot example this repository 

Da ao user do pc o poder de correr graficos com o docker

```bash
    xhost +local:docker
```

Em um terminal dar start ao docker compose.

```bash
    cd docker
    docker compose up --build
```

Enquanto este comando estiver a rodar o conteirner do docker com ros2 vai estar ligado.
Em segida devemos em outro terminal abrir um acesso ao nosso conteirner.

```bash
    docker exec -it ros_2 bash
```

O commando anterior vai abrir um terminal dentro do conteirner.
    este terminal é como se fosso o nosso robo no casso o raspberry.
    e sera onde vamos rodar o simulador.

```
    source ./project/start.sh
    ros2 run gazebo_ros spawn_entity.py 
```
Apos usar os commandos anteriores vai abrir uma janela no Pc com o gazebo ja a rudar.
    inportante referir que o source que damos inicilamente e um script que inicia o ros2 
    sem ele o cmando ros2 nao vai exitir no sistema antes de dar qualquer commando de ros2 
    tem certeza de rodar o source.
    Agora vamos iniciar o nosso robo para isso iremos abir outro terminal no conteirner do ros_2.

```
    docker exec -it ros_2 bash
    source ./project/start.sh
    ros2 run gazebo_ros spawn_entity.py \
    -entity simple_robot \
    -file /app/project/src/my_robot_controller/urdf/simple_robot.urdf \
    -x 0 -y 0 -z 0.2
```
Ao dar este command ja deve aparecer um robo no gazebo mas este nao se vai mecher.
    Para fazer o robo mecher vamos ter que cirar um canal de comunicasão que servirar 
    para o gazebo se cumonicar com o ros2 este canal e cirado e gerido for um node de ros2 
    podendo ser virtual or um microcontolador ligado no pc via usb.
    podemos ver os canal exitentes usandoo o commando `ros2 topic list`.
    Para iniciar o canal de cumonicacão temos que usar:
``` 
        ros2 run  my_robot_controller forward_node
```
Agora o robo vai comessar a mecher bem de vargar mas vai da um zoom no simulador para ver.
    

