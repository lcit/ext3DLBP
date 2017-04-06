cmake_minimum_required(VERSION 2.8)

project(ext3DLBP_project)

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++14 -O2")
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(. ../../include)

add_executable(main main.cpp)

target_link_libraries(main)

