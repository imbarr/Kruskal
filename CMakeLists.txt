# cmake_minimum_required(VERSION <specify CMake version here>)
project(Kruskal)

set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kruskal main.cpp DJS.cpp DJS.h kruskal.cpp kruskal.h edge.cpp edge.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")