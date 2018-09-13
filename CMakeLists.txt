cmake_minimum_required(VERSION 3.10)
project(Kruskal)

set(CMAKE_LEGACY_CYGWIN_WIN32 0)
set(CMAKE_CXX_STANDARD 17)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE B:\\CPP\\catch2)
add_executable(Kruskal main.cpp DJS.cpp DJS.h kruskal.cpp kruskal.h edge.cpp edge.h util.h util.cpp point.cpp point.h point.cpp test-main.cpp)
add_executable(Test DJS.cpp DJS.h kruskal.cpp kruskal.h edge.cpp edge.h util.h util.cpp point.cpp point.h point.cpp test-main.cpp test-kruskal.cpp)
target_link_libraries(Test Catch)

enable_testing()
add_test(NAME RandomTest COMMAND Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")