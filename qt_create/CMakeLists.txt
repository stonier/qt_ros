project(qt_create)
find_package(ROS COMPONENTS catkin)

# TODO Daniel crea un link a roscreate-qt-pkg en /usr/local/bin

install(FILES scripts/roscreate-qt-pkg
  PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ OWNER_EXECUTE GROUP_EXECUTE WORLD_EXECUTE
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create/scripts
  )

install(DIRECTORY src
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create
  )

install(DIRECTORY templates
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create
  )

install(FILES .cproject .project .pydevproject manifest.xml CMakeLists.txt
  DESTINATION ${CMAKE_INSTALL_PREFIX}/share/qt_create
  )

catkin_project(qt_create
  VERSION 0.0.0
  )
