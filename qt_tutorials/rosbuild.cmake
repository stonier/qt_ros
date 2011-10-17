include(${CMAKE_CURRENT_BINARY_DIR}/package.cmake)

##############################################################################
# Qt Environment
##############################################################################

# rosbuild_include does not work in rosbuild2 (no rospack assumption)
# but we do have the source directories scanned by toplevel.cmake
# rosbuild_include(qt_build qt-ros)
include(${qt_build_SOURCE_DIR}/qt-ros.cmake)

rosbuild_prepare_qt4(QtCore QtGui)
if(NOT QT4)
  message(STATUS " - qt_tutorial [no qt4]")
  return()
endif()

##############################################################################
# Subprojects
##############################################################################

add_subdirectory(common)
add_subdirectory(qtalker)
add_subdirectory(qlistener)
add_subdirectory(qadd_server)
add_subdirectory(qadd_client)
