cmake_minimum_required(VERSION 3.16)
project(Huppy LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Quick)

qt_standard_project_setup()

set(PROJECT_SOURCES main.cpp)

if(QT_VERSION VERSION_LESS 6.2)
    list(APPEND PROJECT_SOURCES qml.qrc)
endif()

qt_add_executable(Huppy ${PROJECT_SOURCES})

if(QT_VERSION VERSION_GREATER_EQUAL 6.2)
    qt_add_qml_module(Huppy URI huppy VERSION 1.0 RESOURCE_PREFIX "/qt/qml/" QML_FILES Main.qml)
endif()

set_target_properties(Huppy PROPERTIES WIN32_EXECUTABLE TRUE)
target_link_libraries(Huppy PUBLIC Qt::Quick)

if(Qt6_FOUND)
    qt_import_qml_plugins(Huppy)
endif()
