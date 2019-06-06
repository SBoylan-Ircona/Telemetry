cmake_minimum_required (VERSION 3.4.0)
project (Telemetry CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Version Number
set (Telemetry_VERSION_MAJOR 1)
set (Telemetry_VERSION_Minor 0)
include(GNUInstallDirs)


set(SRC_FILES src/telemetry.cpp
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (telemetry.hpp.in ${CMAKE_BINARY_DIR}/inc/telemetry.hpp)
include_directories(${CMAKE_BINARY_DIR}/inc)

#import phosphor-hwmon
find_package(PkgConfig REQUIRED)
pkg_check_modules(HWMON phosphor-hwmon REQUIRED)
include_directories(${HWMON_INCLUDE_DIRS})
include_directories(${HWMON_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SRC_FILES} )

install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

