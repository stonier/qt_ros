cmake_minimum_required(VERSION 2.8)

project(qt_ros)
find_package(ROS COMPONENTS catkin genmsg)
catkin_stack()


foreach(subdir
    qt_build
    qt_create
    qt_tutorials
    )
  add_subdirectory(${subdir})
endforeach()

# install all manifests
install_matching_to_share(manifest.xml)

install(FILES stack.xml qt_ros.rosinstall README.mediawiki
        DESTINATION share/qt_ros)

