cmake_minimum_required (VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
add_executable (singleton singleton.cpp main.cpp)
target_link_libraries(singleton Threads::Threads)
