cmake_minimum_required (VERSION 2.8.10)
project (Telemetry CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
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

add_executable(${PROJECT_NAME} ${SRC_FILES} )

install (TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})

