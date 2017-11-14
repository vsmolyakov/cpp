
project (dpmeans)
cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

include_directories(
   $ENV{WORKSPACE_HOME}/3rdparty/eigen/
   )

add_executable (dpmeans dpmeans.cpp)


