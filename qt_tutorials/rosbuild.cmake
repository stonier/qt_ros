include(${CMAKE_CURRENT_BINARY_DIR}/package.cmake)

##############################################################################
# Qt Environment
##############################################################################

#rosbuild_include(eros_build eros_build_utilities)
include(qt.cmake)
eros_prepare_qt4(QtCore QtGui) # Add the appropriate components here

##############################################################################
# Comms
##############################################################################

#rosbuild_gensrv()

##############################################################################
# Subprojects
##############################################################################

add_subdirectory(qtalker)
add_subdirectory(qlistener)
add_subdirectory(qadd_server)
add_subdirectory(qadd_client)
