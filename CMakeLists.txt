cmake_minimum_required (VERSION 2.6)
project (Telemetry)
# Version Number
set (Telemetry_VERSION_MAJOR 1)
set (Telemetry_VERSION_Minor 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/telemetry.h.in"
    "${PROJECT_BINARY_DIR}/telemetry.h"
    )

# add the binary tree to the search path for include files
# so that we will find telemetry.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(Telemetry telemetry.cpp)
