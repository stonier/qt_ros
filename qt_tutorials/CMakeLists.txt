project(qt_tutorials)
find_package(catkin)
# These find_package calls setup ROS_INCLUDE_DIRS and ROS_LIBRARIES and 
# all the component variables too (e.g. roscpp_INCLUDE_DIR?)
find_package(ROS REQUIRED COMPONENTS qt_build genmsg std_msgs roscpp)

include_directories(${ROS_INCLUDE_DIRS})

##############################################################################
# Ros Environment Configuration
##############################################################################

# set(CMAKE_VERBOSE_MAKEFILE TRUE)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically 
# included via the dependency call in manifest.xml
rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# Comms
##############################################################################

add_service_files(DIRECTORY srv FILES TwoInts.srv)
generate_messages(DEPENDENCIES std_msgs)

##############################################################################
# Subprojects
##############################################################################

foreach(subdir
    common
    qtalker
    qlistener
    qadd_server
    qadd_client
    )
  install(DIRECTORY ${subdir} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials)
  add_subdirectory(${subdir})
endforeach()

install(FILES manifest.xml CMakeLists.txt
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials
  )
install(DIRECTORY resources DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials)
install(DIRECTORY ui DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials)

catkin_project(qt_tutorials)

