project(qt_tutorials)
find_package(catkin)
# These find_package calls setup ROS_INCLUDE_DIRS and ROS_LIBRARIES and 
# all the component variables too (e.g. roscpp_INCLUDE_DIR?)
find_package(ROS REQUIRED COMPONENTS qt_build std_msgs roscpp)

include_directories(${ROS_INCLUDE_DIRS})

##############################################################################
# Ros Environment Configuration
##############################################################################

#include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
#rosbuild_init()
# set(CMAKE_VERBOSE_MAKEFILE TRUE)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

##############################################################################
# Qt Environment
##############################################################################

# This is dan's qt cmake calls we have to replace

include(${CMAKE_CURRENT_SOURCE_DIR}/../qt_build/qt-ros.cmake)
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

install(FILES .cproject .gitignore .project rosbuild.cmake manifest.xml CMakeLists.txt
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials
  )
install(DIRECTORY resources DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials)
install(DIRECTORY ui DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_tutorials)

catkin_project(qt_tutorials
  VERSION 0.0.0
  )

