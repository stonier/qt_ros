project(qt_build)
find_package(ROS COMPONENTS catkin)

install(FILES .cproject .project qt-ros.cmake rosbuild.cmake manifest.xml CMakeLists.txt
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_build
  )

catkin_project(qt_build
  VERSION 0.0.0
  )

