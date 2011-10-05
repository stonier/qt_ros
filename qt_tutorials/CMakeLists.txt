##############################################################################
# Rosbuild2
##############################################################################

if(ROSBUILD)
  include(rosbuild.cmake OPTIONAL)
  return()
endif()

##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.4.6)

##############################################################################
# Ros Environment Configuration
##############################################################################

include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
rosbuild_init()
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

##############################################################################
# Qt Environment
##############################################################################

rosbuild_include(qt_build qt-ros)
rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# Comms
##############################################################################

rosbuild_gensrv()

##############################################################################
# Subprojects
##############################################################################

add_subdirectory(qtalker)
add_subdirectory(qlistener)
add_subdirectory(qadd_server)
add_subdirectory(qadd_client)
