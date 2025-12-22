cmake_minimum_required(VERSION 3.8)
project(meu_pacote)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


cmake_minimum_required(VERSION 3.5)
project(meu_pacote)

# Encontrar pacotes do ROS 2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Criar executável
add_executable(ola_mundo src/main.cpp)

# Linkar bibliotecas
ament_target_dependencies(ola_mundo rclcpp)

# Instalar o executável
install(TARGETS
  ola_mundo
  DESTINATION lib/${PROJECT_NAME}
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
