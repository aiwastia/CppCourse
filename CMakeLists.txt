cmake_minimum_required (VERSION 3.10)
project (helloworld)
# The version number.
set (helloworld_VERSION_MAJOR 1)
set (helloworld_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
"${PROJECT_SOURCE_DIR}/helloworld.h.in"
"${PROJECT_BINARY_DIR}/helloworld.h"
)

# add the binary tree to the search path for include files
# so that we will find helloworld.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(helloworld heloworld.cpp)

