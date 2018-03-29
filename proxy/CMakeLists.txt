cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
add_executable (proxy proxy.cpp main.cpp)
