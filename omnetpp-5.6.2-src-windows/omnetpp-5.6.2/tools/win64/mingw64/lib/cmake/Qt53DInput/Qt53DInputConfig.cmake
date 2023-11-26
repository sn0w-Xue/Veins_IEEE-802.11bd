
if (CMAKE_VERSION VERSION_LESS 2.8.3)
    message(FATAL_ERROR "Qt 5 requires at least CMake version 2.8.3")
endif()

get_filename_component(_qt53DInput_install_prefix "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

# For backwards compatibility only. Use Qt53DInput_VERSION instead.
set(Qt53DInput_VERSION_STRING 5.9.1)

set(Qt53DInput_LIBRARIES Qt5::3DInput)

macro(_qt5_3DInput_check_file_exists file)
    if(NOT EXISTS "${file}" )
        message(FATAL_ERROR "The imported target \"Qt5::3DInput\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
endmacro()

macro(_populate_3DInput_target_properties Configuration LIB_LOCATION IMPLIB_LOCATION)
    set_property(TARGET Qt5::3DInput APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

    set(imported_location "${_qt53DInput_install_prefix}/bin/${LIB_LOCATION}")
    _qt5_3DInput_check_file_exists(${imported_location})
    if (_Qt53DInput_LIB_DEPENDENCIES)
        set(_list_sep ";")
    endif()
    set_target_properties(Qt5::3DInput PROPERTIES
        "INTERFACE_LINK_LIBRARIES_${Configuration}" "${_Qt53DInput_LIB_DEPENDENCIES}${_list_sep}${_Qt53DInput_STATIC_${Configuration}_LIB_DEPENDENCIES}"
        "IMPORTED_LOCATION_${Configuration}" ${imported_location}
        # For backward compatibility with CMake < 2.8.12
        "IMPORTED_LINK_INTERFACE_LIBRARIES_${Configuration}" "${_Qt53DInput_LIB_DEPENDENCIES}${_list_sep}${_Qt53DInput_STATIC_${Configuration}_LIB_DEPENDENCIES}"
    )

    set(imported_implib "${_qt53DInput_install_prefix}/lib/${IMPLIB_LOCATION}")
    _qt5_3DInput_check_file_exists(${imported_implib})
    if(NOT "${IMPLIB_LOCATION}" STREQUAL "")
        set_target_properties(Qt5::3DInput PROPERTIES
        "IMPORTED_IMPLIB_${Configuration}" ${imported_implib}
        )
    endif()
endmacro()

if (NOT TARGET Qt5::3DInput)

    set(_Qt53DInput_OWN_INCLUDE_DIRS "${_qt53DInput_install_prefix}/include/" "${_qt53DInput_install_prefix}/include/Qt3DInput")
    set(Qt53DInput_PRIVATE_INCLUDE_DIRS
        "${_qt53DInput_install_prefix}/include/Qt3DInput/5.9.1"
        "${_qt53DInput_install_prefix}/include/Qt3DInput/5.9.1/Qt3DInput"
    )

    foreach(_dir ${_Qt53DInput_OWN_INCLUDE_DIRS})
        _qt5_3DInput_check_file_exists(${_dir})
    endforeach()

    # Only check existence of private includes if the Private component is
    # specified.
    list(FIND Qt53DInput_FIND_COMPONENTS Private _check_private)
    if (NOT _check_private STREQUAL -1)
        foreach(_dir ${Qt53DInput_PRIVATE_INCLUDE_DIRS})
            _qt5_3DInput_check_file_exists(${_dir})
        endforeach()
    endif()

    set(Qt53DInput_INCLUDE_DIRS ${_Qt53DInput_OWN_INCLUDE_DIRS})

    set(Qt53DInput_DEFINITIONS -DQT_3DINPUT_LIB)
    set(Qt53DInput_COMPILE_DEFINITIONS QT_3DINPUT_LIB)
    set(_Qt53DInput_MODULE_DEPENDENCIES "3DCore;Gamepad;Gui;Core")


    set(Qt53DInput_OWN_PRIVATE_INCLUDE_DIRS ${Qt53DInput_PRIVATE_INCLUDE_DIRS})

    set(_Qt53DInput_FIND_DEPENDENCIES_REQUIRED)
    if (Qt53DInput_FIND_REQUIRED)
        set(_Qt53DInput_FIND_DEPENDENCIES_REQUIRED REQUIRED)
    endif()
    set(_Qt53DInput_FIND_DEPENDENCIES_QUIET)
    if (Qt53DInput_FIND_QUIETLY)
        set(_Qt53DInput_DEPENDENCIES_FIND_QUIET QUIET)
    endif()
    set(_Qt53DInput_FIND_VERSION_EXACT)
    if (Qt53DInput_FIND_VERSION_EXACT)
        set(_Qt53DInput_FIND_VERSION_EXACT EXACT)
    endif()

    set(Qt53DInput_EXECUTABLE_COMPILE_FLAGS "")

    foreach(_module_dep ${_Qt53DInput_MODULE_DEPENDENCIES})
        if (NOT Qt5${_module_dep}_FOUND)
            find_package(Qt5${_module_dep}
                5.9.1 ${_Qt53DInput_FIND_VERSION_EXACT}
                ${_Qt53DInput_DEPENDENCIES_FIND_QUIET}
                ${_Qt53DInput_FIND_DEPENDENCIES_REQUIRED}
                PATHS "${CMAKE_CURRENT_LIST_DIR}/.." NO_DEFAULT_PATH
            )
        endif()

        if (NOT Qt5${_module_dep}_FOUND)
            set(Qt53DInput_FOUND False)
            return()
        endif()

        list(APPEND Qt53DInput_INCLUDE_DIRS "${Qt5${_module_dep}_INCLUDE_DIRS}")
        list(APPEND Qt53DInput_PRIVATE_INCLUDE_DIRS "${Qt5${_module_dep}_PRIVATE_INCLUDE_DIRS}")
        list(APPEND Qt53DInput_DEFINITIONS ${Qt5${_module_dep}_DEFINITIONS})
        list(APPEND Qt53DInput_COMPILE_DEFINITIONS ${Qt5${_module_dep}_COMPILE_DEFINITIONS})
        list(APPEND Qt53DInput_EXECUTABLE_COMPILE_FLAGS ${Qt5${_module_dep}_EXECUTABLE_COMPILE_FLAGS})
    endforeach()
    list(REMOVE_DUPLICATES Qt53DInput_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt53DInput_PRIVATE_INCLUDE_DIRS)
    list(REMOVE_DUPLICATES Qt53DInput_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt53DInput_COMPILE_DEFINITIONS)
    list(REMOVE_DUPLICATES Qt53DInput_EXECUTABLE_COMPILE_FLAGS)

    set(_Qt53DInput_LIB_DEPENDENCIES "Qt5::3DCore;Qt5::Gamepad;Qt5::Gui;Qt5::Core")


    add_library(Qt5::3DInput SHARED IMPORTED)

    set_property(TARGET Qt5::3DInput PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${_Qt53DInput_OWN_INCLUDE_DIRS})
    set_property(TARGET Qt5::3DInput PROPERTY
      INTERFACE_COMPILE_DEFINITIONS QT_3DINPUT_LIB)

    set(_Qt53DInput_PRIVATE_DIRS_EXIST TRUE)
    foreach (_Qt53DInput_PRIVATE_DIR ${Qt53DInput_OWN_PRIVATE_INCLUDE_DIRS})
        if (NOT EXISTS ${_Qt53DInput_PRIVATE_DIR})
            set(_Qt53DInput_PRIVATE_DIRS_EXIST FALSE)
        endif()
    endforeach()

    if (_Qt53DInput_PRIVATE_DIRS_EXIST
        AND NOT CMAKE_VERSION VERSION_LESS 3.0.0 )
        add_library(Qt5::3DInputPrivate INTERFACE IMPORTED)
        set_property(TARGET Qt5::3DInputPrivate PROPERTY
            INTERFACE_INCLUDE_DIRECTORIES ${Qt53DInput_OWN_PRIVATE_INCLUDE_DIRS}
        )
        set(_Qt53DInput_PRIVATEDEPS)
        foreach(dep ${_Qt53DInput_LIB_DEPENDENCIES})
            if (TARGET ${dep}Private)
                list(APPEND _Qt53DInput_PRIVATEDEPS ${dep}Private)
            endif()
        endforeach()
        set_property(TARGET Qt5::3DInputPrivate PROPERTY
            INTERFACE_LINK_LIBRARIES Qt5::3DInput ${_Qt53DInput_PRIVATEDEPS}
        )
    endif()

    file(GLOB pluginTargetsMaybe "${CMAKE_CURRENT_LIST_DIR}/Qt53DInput_*.cmake")
    unset(pluginTargets)
    if (pluginTargetsMaybe)
        foreach(pluginTarget ${pluginTargetsMaybe})
            # exclude Qt5Qml factory plugins as they will be included later by Qt5QmlConfigExtras
            string(REGEX MATCH Qt5Qml_.*Factory.cmake excluded ${pluginTarget})
            if (excluded)
                continue()
            endif()
            file(STRINGS ${pluginTarget} matched REGEX Qt53DInput_PLUGINS)
            if (matched)
                list(APPEND pluginTargets ${pluginTarget})
            endif()
        endforeach()
    endif()

    macro(_populate_3DInput_plugin_properties Plugin Configuration PLUGIN_LOCATION)
        set_property(TARGET Qt5::${Plugin} APPEND PROPERTY IMPORTED_CONFIGURATIONS ${Configuration})

        set(imported_location "${_qt53DInput_install_prefix}/share/qt5/plugins/${PLUGIN_LOCATION}")
        _qt5_3DInput_check_file_exists(${imported_location})
        set_target_properties(Qt5::${Plugin} PROPERTIES
            "IMPORTED_LOCATION_${Configuration}" ${imported_location}
        )
        get_filename_component(_plugindir ${PLUGIN_LOCATION} PATH)
        get_filename_component(_plugindirname ${_plugindir} NAME)
        get_filename_component(_pluginname ${PLUGIN_LOCATION} NAME)
        string(REGEX REPLACE "^lib(.*)\\.a" "${_qt53DInput_install_prefix}/share/qt5/plugins/${_plugindirname}/\\1.prl" plugin_prl_file_location ${_pluginname})

    endmacro()

    if (pluginTargets)
        foreach(pluginTarget ${pluginTargets})
            include(${pluginTarget})
        endforeach()
    endif()

    _populate_3DInput_target_properties(RELEASE "Qt53DInput.dll" "libQt53DInput.dll.a" )



    _populate_3DInput_target_properties(DEBUG "Qt53DInputd.dll" "libQt53DInputd.dll.a" )






_qt5_3DInput_check_file_exists("${CMAKE_CURRENT_LIST_DIR}/Qt53DInputConfigVersion.cmake")

endif()
