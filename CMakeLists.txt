# -------------------- PROJECT INFO --------------------
#   Title      :                       Tegra System
#   Author     :                       Kambiz Asadzadeh
#   Copyright  :                       The Genyleap
# ------------------------------------------------------

cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0048 NEW)

# Add include path for cmake modules
# ------ PROJECT EXTRA CMAKE ------

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

include(ExternalProject)
include(FetchContent)

# ------ PROJECT INFO ------
# Options
set(PROJECT_NAME "CoreInterface" CACHE STRING "Project Name.") #You can change "ProjectTemplate" with your project name.
set(PROJECT_TARGET ${PROJECT_NAME} CACHE STRING "Project Target Name.")

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 2)
set(PROJECT_VERSION_PATCH 383)
set(PROJECT_VERSION_TWEAK 0)

# ---- Project settings ----
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS ON)
endif()

set(PROJECT_CREATOR "Kambiz Asadzadeh" CACHE STRING "Creator of your project.") #Your project creator.

set(PROJECT_LICENSE_TYPE "LGPL-v3.0" CACHE STRING "Project License Type.") #Your project license type.

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
  execute_process(
    COMMAND git rev-parse --short HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE PROJECT_VERSION_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

endif()
if(NOT PROJECT_VERSION_TAG)
  set(PROJECT_VERSION_TAG 00000000)
endif()
set(PROJECT_VERSION_TAG_HEX 0x${PROJECT_VERSION_TAG})
set(PROJECT_VERSION_TYPE "alpha" CACHE STRING "Version type.")
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
set(PROJECT_VERSION_STRING ${PROJECT_VERSION})

# Supported languages include C, CXX (i.e. C++), CUDA, OBJC (i.e. Objective-C), OBJCXX, Fortran, HIP, ISPC, and ASM. By default C and CXX are enabled if no language options are given.
# Specify language NONE, or use the LANGUAGES keyword and list no languages, to skip enabling any languages.
set(PROJECT_LANGUAGES CXX)

#Use these keys [stl, qt, qtwidget, qtquick]
set(PROJECT_MAIN_TYPE "web" CACHE STRING "Library System.")

#Use these keys [macOS, Windows, Linux, iOS, Android]
set(PLATFORM_OS "macOS" CACHE STRING "OS Type.")

set(USE_FMT TRUE)

set(USE_NONE_STL_JSON TRUE)

set(CMAKE_BUILD_TYPE "Debug")

#You can replace your project description with this string.
set(PROJECT_DESCRIPTION "Tegra System is free open source multi-language Content Management System." CACHE STRING "Project Description")

#Your project website address.
set(PROJECT_HOMEPAGE_URL "https://github.com/genyleap/tegra" CACHE STRING "Project URL.")


#Project pre-configuration system.
configure_file(
  ${PROJECT_SOURCE_DIR}config.hpp.in
  ${PROJECT_SOURCE_DIR}config.hpp
)

project(
    ${PROJECT_NAME}
    LANGUAGES ${PROJECT_LANGUAGES}
    DESCRIPTION ${PROJECT_DESCRIPTION}
    HOMEPAGE_URL ${PROJECT_HOMEPAGE_URL}
    VERSION ${PROJECT_VERSION}
    )

# ------ PACKAGES CONFIG ------
include(project-setting)
if(project-setting)
  return()
endif()
set(project-setting ON)

# ------ CROSS-COMPILE CONFIG ------
include(cross-compile)
if(cross-compile)
  return()
endif()
set(cross-compile ON)

# ------ PROJECT CONFIG ------
include(color-message)
if(color-message)
  return()
endif()
set(color-message ON)

# ------ COMPILER CONFIG ------
include(compiler-options)
if(compiler-options)
  return()
endif()
set(compiler-options ON)

# ------ PACKAGES CONFIG ------
include(packages)
if(packages)
  return()
endif()
set(packages ON)

if(USE_QT AND NOT PROJECT_MAIN_TYPE STREQUAL "web")
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
endif()

set(SUFFIX_EXTRA *.in)
set(SUFFIX_HPPHEADER *.hpp)
set(SUFFIX_CSP *.csp)
set(SUFFIX_CSS *.css)
set(SUFFIX_JS *.js)
set(SUFFIX_SOURCE *.cpp)
set(SUFFIX_CONFIG *.json)
set(SUFFIX_TRANSLATIONS *.json)

if(PROJECT_MAIN_TYPE STREQUAL "qtwidget")
     set(SUFFIX_WIDGET *.ui)
elseif(PROJECT_MAIN_TYPE STREQUAL "qtquick")
     set(SUFFIX_QML *.qml)
     set(SUFFIX_QRC *.qrc)
elseif(PROJECT_MAIN_TYPE STREQUAL "web")
     set(SUFFIX_CSP *.csp)
     set(SUFFIX_HTML *.html)
     set(SUFFIX_CSS *.css)
     set(SUFFIX_JS *.js)
     set(SUFFIX_TRANSLATIONS *.json)
endif()

include_directories(include/) #include tegra's file.

file(GLOB PRECOMPILED precompiled/pch.hpp)
file(
    GLOB HEADERS
    source/${SUFFIX_HPPHEADER}
    source/installer/${SUFFIX_HPPHEADER}
    source/framework/${SUFFIX_HPPHEADER}
    source/core/${SUFFIX_HPPHEADER}
    source/core/extra/${SUFFIX_HPPHEADER}
    source/account/${SUFFIX_HPPHEADER}
    source/abstracts/${SUFFIX_HPPHEADER}
    source/abstracts/apis/${SUFFIX_HPPHEADER}
    source/abstracts/account/${SUFFIX_HPPHEADER}
    source/abstracts/dynamics/${SUFFIX_HPPHEADER}
    source/database/${SUFFIX_HPPHEADER}
    source/translator/${SUFFIX_HPPHEADER}
    source/install/${SUFFIX_HPPHEADER}
    source/view/installer/${SUFFIX_HPPHEADER}
)
file(
    GLOB SOURCES
    source/${SUFFIX_SOURCE}
    source/installer/${SUFFIX_SOURCE}
    source/framework/${SUFFIX_SOURCE}
    source/core/${SUFFIX_SOURCE}
    source/core/extra/${SUFFIX_SOURCE}
    source/account/${SUFFIX_SOURCE}
    source/abstracts/${SUFFIX_SOURCE}
    source/abstracts/apis/${SUFFIX_SOURCE}
    source/abstracts/account/${SUFFIX_SOURCE}
    source/abstracts/dynamics/${SUFFIX_SOURCE}
    source/database/${SUFFIX_SOURCE}
    source/translator/${SUFFIX_SOURCE}
    source/install/${SUFFIX_SOURCE}
    source/view/installer/${SUFFIX_SOURCE}
)


file(GLOB EXAMPLES
     source/examples/${SUFFIX_HPPHEADER}
     source/examples/${SUFFIX_SOURCE}
)
file(GLOB UTILS
     utilities/${SUFFIX_HPPHEADER}
     utilities/${SUFFIX_SOURCE}
)


file(GLOB TRANSLATIONS
    translations/${SUFFIX_TRANSLATIONS}
)

if(${PROJECT_MAIN_TYPE} STREQUAL "stl")
    set(HAS_USER_INTERFACE false)
    file(GLOB MAIN_ENTRY_POINT
         source/entrypoint/stl/${SUFFIX_HPPHEADER}
         source/entrypoint/stl/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "qt")
    file(GLOB MAIN_ENTRY_POINT
         source/entrypoint/qt/nogui/${SUFFIX_HPPHEADER}
         source/entrypoint/qt/nogui/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
    file(GLOB MAIN_ENTRY_POINT
        source/entrypoint/qt/qtwidget/${SUFFIX_HPPHEADER}
        source/entrypoint/qt/qtwidget/${SUFFIX_SOURCE}
        ui/widgets/${SUFFIX_HPPHEADER}
        ui/widgets/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtquick")
    file(GLOB MAIN_ENTRY_POINT
         source/entrypoint/qt/qtquick/${SUFFIX_HPPHEADER}
         source/entrypoint/qt/qtquick/${SUFFIX_SOURCE}
    )
elseif(${PROJECT_MAIN_TYPE} STREQUAL "web")
    file(GLOB MAIN_ENTRY_POINT
        source/entrypoint/stl/${SUFFIX_HPPHEADER}
        source/entrypoint/stl/${SUFFIX_SOURCE}
    )
endif()

if(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
   file(GLOB UI_SOURCE ui/widgets/${SUFFIX_WIDGET})
elseif(${PROJECT_MAIN_TYPE} STREQUAL "web")
  file(
      GLOB TEMPLATE_SOURCE templates/user/${SUFFIX_CSP}
      GLOB TEMPLATE_SOURCE templates/user/${SUFFIX_HTML}
      GLOB TEMPLATE_SOURCE templates/user/${SUFFIX_CSS}
      GLOB TEMPLATE_SOURCE templates/user/${SUFFIX_JS}

      GLOB TEMPLATE_SOURCE templates/admin/${SUFFIX_CSP}
      GLOB TEMPLATE_SOURCE templates/admin/statics/${SUFFIX_CSP}
      GLOB TEMPLATE_SOURCE templates/admin/${SUFFIX_HTML}
      GLOB TEMPLATE_SOURCE templates/admin/${SUFFIX_CSS}
      GLOB TEMPLATE_SOURCE templates/admin/${SUFFIX_JS}
  )
else()
   file(GLOB UI_SOURCE ui/qtquick/${SUFFIX_QRC})
endif()

file(
    GLOB CONFIGFILE config/${SUFFIX_CONFIG}
    GLOB CONFIGFILE ${SUFFIX_CONFIG}
)

file(GLOB SOURCESFILE
    #---C++---
    ${MAIN_ENTRY_POINT}
    ${HEADERS}
    ${SOURCES}
    ${UI_SOURCE}
    ${TEMPLATE_SOURCE}
    ${TRANSLATIONS}
    ${UTILS}
    ${CONFIGFILE}
    ${PRECOMPILED}
    ${EXAMPLES}
    )

source_group("PrecompiledHeaders"  FILES ${PRECOMPILED})
source_group("Utilities"  FILES ${UTILS})
source_group("Entry Point (Main)"   FILES ${MAIN_ENTRY_POINT})
source_group("Base"   FILES ${HEADERS} ${SOURCES})
source_group("UI"     FILES ${UI_SOURCE})
source_group("Templates"     FILES ${TEMPLATE_SOURCE})
source_group("Translations"     FILES ${TRANSLATIONS})
source_group("Config" FILES ${CONFIGFILE})
source_group("Examples"  FILES ${EXAMPLES})


# ------ PROJECT DIRECTORIES ------

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build/)
set(EXECUTABLE_OUTPUT_PATH ${dir}/final CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir}/final CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
SET(EXECUTABLE_OUTPUT_PATH ${dir}/final)
SET(LIBRARY_OUTPUT_PATH ${dir}/final)
SET(CMAKE_CACHEFILE_DIR ${dir})

message("CMAKE_BUILD_FILES_DIRECTORY: " ${CMAKE_BUILD_FILES_DIRECTORY})

# ------ OUTPUTS CONFIG ------

if(PLATFORM_OS STREQUAL "macOS")
    if(OS_ARCHITECTURES STREQUAL "")
      set(OS_ARCHITECTURES ${CMAKE_OSX_ARCHITECTURES})
      else()
      set(OS_ARCHITECTURES "x86_64")
    endif()
else()
    if(PROCESSOR_ARCHITECTURE STREQUAL "")
      set(OS_ARCHITECTURES ${PROCESSOR_ARCHITECTURE})
      else()
      set(OS_ARCHITECTURES "x86_64")
    endif()
    set(OS_ARCHITECTURES ${PROCESSOR_ARCHITECTURE})
endif()

message(STATUS "${BoldRed}------ ${PROJECT_TARGET} Tools Configuration ------${ColourReset}")
message(STATUS "${Bold}Language Standard${ColourReset}	    : C++[${CMAKE_CXX_STANDARD}]")
message(STATUS "${Bold}Compiler${ColourReset}		    : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "${Bold}Compiler Version${ColourReset}	    : ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "${Bold}OS Target${ColourReset}		    : ${CMAKE_HOST_SYSTEM}")
message(STATUS "${Bold}OS Version${ColourReset}		    : ${CMAKE_HOST_SYSTEM_VERSION}")
message(STATUS "${Bold}System Architecture${ColourReset}      : ${OS_ARCHITECTURES}")
message(STATUS "${Bold}Project License${ColourReset}	    : ${PROJECT_LICENSE_TYPE}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Framework Info ------${ColourReset}")
message(STATUS "${Bold}Name${ColourReset}			    : ${CMAKE_PROJECT_NAME}")
message(STATUS "${Bold}Description${ColourReset}		    : ${CMAKE_PROJECT_DESCRIPTION}")
message(STATUS "${Bold}Version${ColourReset}		    : ${PROJECT_VERSION}")
message(STATUS "${Bold}Creator${ColourReset}		    : ${PROJECT_CREATOR}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Project Configuration ------${ColourReset}")
message(STATUS "${Bold}DEVELOPER${ColourReset}		    : ${PROJECT_CREATOR}")
message(STATUS "${Bold}PROJECT_PROJECT${ColourReset}	    : ${PROJECT_NAME}")
message(STATUS "${Bold}PROJECT_TARGET${ColourReset}	    : ${PROJECT_TARGET}")
message(STATUS "${Bold}PROJECT_VERSION${ColourReset}	    : ${PROJECT_VERSION}")
message(STATUS "${Bold}PROJECT_VERSION_TYPE${ColourReset}	    : ${Underscore}${PROJECT_VERSION_TYPE}${ColourReset}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} Building Configuration ------${ColourReset}")
message(STATUS "${Bold}PROJECT_BUILD_SHARED${ColourReset}	: ${PROJECT_BUILD_SHARED}")
message(STATUS "${Bold}PROJECT_VERSION_TAG_HEX${ColourReset}	: ${PROJECT_VERSION_TAG_HEX}")
message(STATUS "${Bold}PROJECT_FOLDER_SUFFIX${ColourReset}	: ${PROJECT_FOLDER_SUFFIX}")
message(STATUS "${Bold}LIBRARY_OUTPUT_PATH${ColourReset}		: ${LIBRARY_OUTPUT_PATH}")
message(STATUS "${Bold}CMAKE_CURRENT_SOURCE_DIR${ColourReset}	: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "${BoldBlue}------ ${PROJECT_TARGET} End Configuration ------${ColourReset}")

include(CheckIncludeFileCXX)

check_include_file_cxx(any HAS_ANY)
check_include_file_cxx(string_view HAS_STRING_VIEW)
check_include_file_cxx(coroutine HAS_COROUTINE)
if (NOT "${CMAKE_CXX_STANDARD}" STREQUAL "")
    # Do nothing
elseif (HAS_ANY AND HAS_STRING_VIEW AND HAS_COROUTINE)
    set(CMAKE_CXX_STANDARD 20)
elseif (HAS_ANY AND HAS_STRING_VIEW)
    set(CMAKE_CXX_STANDARD 17)
else ()
    set(CMAKE_CXX_STANDARD 14)
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_STATIC "Enable building static for ${PROJECT_NAME}" FALSE)

if(ANDROID)
    set(DANDROID_NATIVE_API_LEVEL 23)
    if(NOT PROJECT_MAIN_TYPE STREQUAL "qtquick")
        #message(${BoldRed} "Please set {qtquick} key to PROJECT_MAIN_TYPE." ${ColourReset})
        set(PROJECT_MAIN_TYPE "qtquick")
    endif()
    add_library(${PROJECT_NAME} SHARED ${SOURCESFILE} ${UI_SOURCE})
else()
  if(USE_QT)
    #Add an executable to the project using the specified source files.
    add_executable(${PROJECT_NAME} ${SOURCESFILE} ${UI_SOURCE})
  else()
    #Add an executable to the project using the specified source files.
    if(ENABLE_STATIC)
        add_library(${PROJECT_NAME} STATIC ${SOURCESFILE})
        else()
        add_library(${PROJECT_NAME} SHARED ${SOURCESFILE})
    endif()
  endif()
endif()

#Support Qt6 & Qt5 Modules.
if(USE_QT)


    if(QT_VERSION_MAJOR EQUAL 6)
        qt_import_qml_plugins(${PROJECT_NAME})
        qt_finalize_executable(${PROJECT_NAME})
    endif()

    if(USE_QT5_FEATURES)

        if(${PROJECT_MAIN_TYPE} STREQUAL "qt")
            list(APPEND QT_MODULES Core Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
            list(APPEND QT_MODULES Core Widgets Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Widgets
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtquick")
            list(APPEND QT_MODULES Core Quick Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Quick
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        else()
            list(APPEND QT_MODULES Core Core5Compat)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Core5Compat
                )
        endif()
    else()
        if(${PROJECT_MAIN_TYPE} STREQUAL "qt")
            list(APPEND QT_MODULES Core)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtwidget")
            list(APPEND QT_MODULES Core Widgets)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Widgets
                )
        elseif(${PROJECT_MAIN_TYPE} STREQUAL "qtquick")
            list(APPEND QT_MODULES Core Quick)
            list(APPEND QT_MODULES_LINK
                Qt${QT_VERSION_MAJOR}::Core
                Qt${QT_VERSION_MAJOR}::Quick
                )
        endif()
    endif()
    find_package(QT NAMES Qt6 Qt5 COMPONENTS ${QT_MODULES} REQUIRED)
    find_package(Qt${QT_VERSION_MAJOR} COMPONENTS ${QT_MODULES} REQUIRED)

    if(USE_QT_QUICK_COMPILER)
    find_package(QtQuickCompiler)
    qt_add_resources(UI_SOURCE ui/qtquick/qml.qrc)
    endif()
    target_link_libraries(${PROJECT_NAME} PRIVATE ${QT_MODULES_LINK})
endif()

#Extra Modules
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_MODULES} ${OS_LIBS})
target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/source PRIVATE source
    ${LIB_TARGET_INCLUDE_DIRECTORIES}
    )

target_link_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source
    ${LIB_TARGET_LINK_DIRECTORIES}
    )

target_compile_definitions(${PROJECT_NAME} PRIVATE COREINTERFACE_LIBRARY)

if(ENABLE_DROGON_MODULE)
    find_package(Drogon CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon fmt::fmt)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ${LIB_TARGET_COMPILER_DEFINATION})
endif()

if (CMAKE_CXX_STANDARD LESS 17)
    # With C++14, use boost to support any, string_view and filesystem
    message(STATUS "use c++14")
    find_package(Boost 1.61.0 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)
elseif (CMAKE_CXX_STANDARD LESS 20)
    message(STATUS "use c++17")
else ()
    message(STATUS "use c++20")
endif ()

file(GLOB_RECURSE SCP_LIST ${CMAKE_CURRENT_SOURCE_DIR}/templates/user/*.csp)
file(GLOB_RECURSE SCP_LIST ${CMAKE_CURRENT_SOURCE_DIR}/templates/admin/*.csp)

foreach(cspFile ${SCP_LIST})
    message(STATUS "cspFile:" ${cspFile})
    get_filename_component(classname ${cspFile} NAME_WE)
    message(STATUS "view classname:" ${classname})
    ADD_CUSTOM_COMMAND(OUTPUT ${classname}.h ${classname}.cc
            COMMAND drogon_ctl
            ARGS create view ${cspFile}
            DEPENDS ${cspFile}
            VERBATIM )
    set(VIEWSRC ${VIEWSRC} ${classname}.cc)
endforeach()

#drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/templates
#                    ${CMAKE_CURRENT_BINARY_DIR}/templates)

drogon_create_views(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/templates
                     ${CMAKE_CURRENT_BINARY_DIR}/templates TRUE)

#set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS ${LIB_TARGET_PROPERTIES})
#This command generates installation rules for a project.
#Install rules specified by calls to the install() command within a source directory. are executed in order during installation.
install(TARGETS ${PROJECT_NAME} DESTINATION build/bin)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.json DESTINATION ${CMAKE_BINARY_DIR}/final)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config DESTINATION ${CMAKE_BINARY_DIR}/final)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/translations DESTINATION ${CMAKE_BINARY_DIR}/final)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/templates DESTINATION ${CMAKE_BINARY_DIR}/final)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/final/server-log)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/final)
install(DIRECTORY DESTINATION ${CMAKE_BINARY_DIR}/final/server-log)

add_compile_options(-frtti -fexceptions)
target_compile_options(${PROJECT_NAME} PUBLIC -frtti -fexceptions)

#Ignore unused files.
list(APPEND CPACK_SOURCE_IGNORE_FILES /.git/ /build/ .gitignore .DS_Store)

set(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
