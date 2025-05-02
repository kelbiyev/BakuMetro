cmake_minimum_required(VERSION 3.10)
project(BakuMetro_project)
option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.a/.lib)" ON)

add_library(Metro lib.cpp)

target_include_directories(Metro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)

add_executable(BakuMetro main.cpp)
target_link_libraries(BakuMetro Metro)
