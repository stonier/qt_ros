###############################
# Qt4
###############################
#
# On mingw_cross, system lib deps are in prl files which FindQt4 does not check, 
# this can lead to some shortages in the link dependencies especially when 
# statically building. So...if there is prl files to tell us about this, use them.
#
macro(qt_link_flags_from_prl component)
    string(TOUPPER ${component} COMPONENT_UPPER)
        set(FILE_PRL "NOTFOUND")
        find_file(FILE_PRL ${component}.prl ${QT_LIBRARY_DIR})
        if( FILE_PRL )
                file(READ ${FILE_PRL} PRL_CONTENTS) # Read .prl file
                string(REGEX MATCH "QMAKE_PRL_LIBS.+" PRL_LINE ${PRL_CONTENTS}) # Extract the line with linking flags
                string(REGEX REPLACE "-l" "" PRL_LINE ${PRL_LINE}) # Remove link flag symbols
                string(REGEX REPLACE "QMAKE_PRL_LIBS" "" PRL_LINE ${PRL_LINE}) # Remove non links
                string(REGEX REPLACE "=" "" PRL_LINE ${PRL_LINE}) # Remove non links
                string(REGEX MATCHALL "[^ \t\n]+" PRL_LINK_FLAGS ${PRL_LINE}) # Split the line by whitespaces
                # Don't double up in QT_LIBRARIES
                if(PRL_LINK_FLAGS)
                list(REMOVE_ITEM QT_LIBRARIES ${PRL_LINK_FLAGS})
                list(APPEND QT_LIBRARIES ${PRL_LINK_FLAGS})
                if(QT_${COMPONENT_UPPER}_LIB_DEPENDENCIES)
                        list(REMOVE_ITEM QT_${COMPONENT_UPPER}_LIB_DEPENDENCIES ${PRL_LINK_FLAGS})
                endif()
                list(APPEND QT_${COMPONENT_UPPER}_LIB_DEPENDENCIES ${PRL_LINK_FLAGS})
        endif()
        endif( FILE_PRL )
endmacro()
#
# Is a wrapper around FindQt4.cmake.
# 
# Mostly this is needed to satisfy a static mingw cross compile of qt, (mingw_cross)
# as the cmake FindQt4 handles this poorly. Optionally call with the components 
# you want to use, e.g.
# 
#     rosbuild_prepare_qt4()
#     rosbuild_prepare_qt4(QtGui QtCore)
#
# What this macro does:
#
# - calls the underlying FindQt4.cmake module with the specified components.
# - if compiling statically
#   - turns off -DQT_DLL if it's accidentally left on.
#   - checks to see if there are .prl's which can fill out the lib dependencies.
#
# Sets QT_FOUND and QT4_FOUND if QT/QT4 was found.
# Also sets QT_XXX_FOUND if the specific component (XXX) was found.
#
# See the official FindQt4.cmake module for more information (usually in 
# /usr/share/cmake-2.8/Modules/FindQt4.cmake 
#
macro(rosbuild_prepare_qt4)
    if ( ${ARGC} GREATER 0 )
        #foreach(arg ${ARGV})
        #  set(QT_COMPONENTS_ "${QT_COMPONENTS_} ${arg}")
        #endforeach()
        #string(STRIP ${QT_COMPONENTS_} QT_COMPONENTS_)
        #message("ARGV.........................${ARGV}")
        #message("QT_COMPONENTS................${QT_COMPONENTS_}")
        #message("QT_DEFINITIONS...............${QT_DEFINITIONS}")
        #find_package(Qt4 COMPONENTS ${QT_COMPONENTS_}) 
        #find_package(Qt4 COMPONENTS QtCore QtGui QtXml) 
        find_package(Qt4 COMPONENTS ${ARGV})
    else()
        find_package(Qt4)
    endif()

    if(NOT QT_QMAKE_EXECUTABLE)
      #set(QT4_FOUND QT4-NOTFOUND) # Do we actually need this?
    else()
        # This is needed on my ubuntu (cmake 2.8.0), but not on gentoo (cmake 2.8.1)
        # Probably later this can be dropped as it is done in 2.8.1+
        if(QT_IS_STATIC)
            list(REMOVE_ITEM QT_DEFINITIONS -DQT_DLL)
        endif()
    
        include(${QT_USE_FILE})
        include_directories(${CMAKE_CURRENT_BINARY_DIR}) # Needed to pick up ui files in build dir

        if(QT_IS_STATIC) 
            if(QT_USE_QAXCONTAINER) 
                qt_link_flags_from_prl(QAxContainer)
            endif()
            if(QT_USE_QAXSERVER) 
                qt_link_flags_from_prl(QAxServer)
            endif()
            if(QT_USE_QT3SUPPORT) 
                qt_link_flags_from_prl(Qt3Support)
            endif()
            if(QT_USE_QTCORE) 
                qt_link_flags_from_prl(QtCore)
            endif()
            if(QT_USE_QTGUI) 
                qt_link_flags_from_prl(QtGui)
            endif()
            if(QT_USE_QTMAIN) 
                qt_link_flags_from_prl(qtmain)
            endif()
            if(QT_USE_QTMULTIMEDIA) 
                qt_link_flags_from_prl(QtMultimedia)
            endif()
            if(QT_USE_QTNETWORK) 
                qt_link_flags_from_prl(QtNetwork)
            endif()
            if(QT_USE_QTOPENGL) 
                qt_link_flags_from_prl(QtOpenGL)
            endif()
            if(QT_USE_QTSCRIPT) 
                qt_link_flags_from_prl(QtScript)
            endif()
            if(QT_USE_QTSCRIPTTOOLS) 
                qt_link_flags_from_prl(QtScriptTools)
            endif()
            if(QT_USE_QTSQL) 
                qt_link_flags_from_prl(QtSql)
            endif()
            if(QT_USE_QTSVG) 
                qt_link_flags_from_prl(QtSvg)
            endif()
            if(QT_USE_QTTEST) 
                qt_link_flags_from_prl(QtTest)
            endif()
            if(QT_USE_QTWEBKIT) 
                qt_link_flags_from_prl(QtWebKit)
            endif()
            if(QT_USE_QTXMLPATTERNS) 
                qt_link_flags_from_prl(QtXmlPatterns)
            endif()
            if(QT_USE_QTXML) 
                qt_link_flags_from_prl(QtXml)
            endif()
        endif()
    endif()
    ADD_DEFINITIONS(-DQT_NO_KEYWORDS)
endmacro()
    
