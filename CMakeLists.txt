set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES cmake/conan_provider.cmake)
cmake_minimum_required(VERSION 3.9)
project(FormatOutput CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_BUILD_TYPE Release)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

find_package(Qt5 REQUIRED COMPONENTS Core Gui Svg Widgets QWindowsIntegrationPlugin)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(main main.cpp resources/resources.qrc)
target_link_libraries(main Qt5::Core Qt5::Widgets Qt5::QWindowsIntegrationPlugin Qt5::Svg)

if (DEFINED qt_Qt5_QSvgPlugin_FRAMEWORKS_FOUND_DEBUG)
  target_link_libraries(main Qt5::QSvgIconPlugin Qt5::QSvgPlugin)
  target_compile_definitions(main PRIVATE HAS_SVG_PLUGIN=1)
endif()
