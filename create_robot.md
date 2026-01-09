#what create robot in ros2 and gazebo

No ros2 os robos foncionao com canais de comonicasao como o /cmd
Este canais premitem comunicsao entire o robo e o pc central or entre nods.
no casso do simulador vamos ter dois nods um que vai ser o codigo que corre no hardwere real 
e outro que vai ser o robot que fornece respostar para o /cmd como o hardwere real chamemos de real_node
ao nos basearmos no node de simulasao sera possivle indetificar errors  real_node.

## Create robot node 

a primira coisa a fazer é cirar um novo node para o nosso robo.

``` bash
ros2 pkg create my_robt --build-type ament_cmake --dependencies rclcpp geometry_msgs
cd  my_robt
mkdir -p urdf
```
The folder urdf is used for save the fails urdf ¨que seram usados para garar o modelo 3d do nosso robot
que vamos cirar agora.
```bash
vim ./robt.urdf
```

