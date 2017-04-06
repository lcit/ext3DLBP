cmake_minimum_required(VERSION 2.8)

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++14 -O2")
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

find_package(PythonInterp)
find_package(PythonLibs)
if(APPLE AND ${PYTHON_VERSION_MAJOR} EQUAL 3)
    find_package(Boost COMPONENTS python3)
else()
    find_package(Boost COMPONENTS python)
endif()

include_directories(../include ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
link_libraries(${Boost_LIBRARIES} ${PYTHON_LIBRARIES}) # Deprecated but so convenient!

add_library(ext3DLBPpy SHARED ext3DLBPpy.cpp)
set_target_properties(ext3DLBPpy PROPERTIES PREFIX "")
target_link_libraries(ext3DLBPpy ${Boost_LIBRARIES})
