# cmake_minimum_required(VERSION 2.4.6)
# include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Append to CPACK_SOURCE_IGNORE_FILES a semicolon-separated list of
# directories (or patterns, but directories should suffice) that should
# be excluded from the distro.  This is not the place to put things that
# should be ignored everywhere, like "build" directories; that happens in
# rosbuild/rosbuild.cmake.  Here should be listed packages that aren't
# ready for inclusion in a distro.
#
# This list is combined with the list in rosbuild/rosbuild.cmake.  Note
# that CMake 2.6 may be required to ensure that the two lists are combined
# properly.  CMake 2.4 seems to have unpredictable scoping rules for such
# variables.
#list(APPEND CPACK_SOURCE_IGNORE_FILES /core/experimental)

# DJS - I think this is old rosbuild macro only
#rosbuild_make_distribution(0.1.2)

cmake_minimum_required(VERSION 2.8)

project(ros_qt)

find_package(catkin)

foreach(subdir
    qt_build
    qt_create
    qt_tutorials 
    )
  add_subdirectory(${subdir})
endforeach()

install(FILES stack.xml stack.yaml qt_ros_dev.rosinstall qt_ros.rosinstall README.mediawiki
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_ros)

