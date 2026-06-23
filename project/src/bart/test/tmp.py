
from launch.actions import SetEnvironmentVariable

    gz_resource_path = SetEnvironmentVariable(
        name='GZ_SIM_RESOURCE_PATH',
        value=os.path.join(pkg_ros_gz_rbot, 'models')
    )
