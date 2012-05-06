##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.0)

##############################################################################
# Catkin
##############################################################################

project(qt_create)
find_package(ROS COMPONENTS catkin)
catkin_project(qt_create)

# Now moving to a pip project.

# TODO Daniel crea un link a roscreate-qt-pkg en /usr/local/bin

#install(FILES scripts/roscreate-qt-pkg
#  PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create/scripts
#  )
#
#install(DIRECTORY src
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create
#  )
#
#install(DIRECTORY templates
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create
#  )
#
#install(FILES .cproject .project .pydevproject manifest.xml CMakeLists.txt
#  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create
#  )

