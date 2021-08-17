cmake_minimum_required (VERSION 3.16)

project (myprogram)

set (CMAKE_BUILD_TYPE "Release")

add_executable (mytest main.cpp)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/pybind11 py11.out)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/val3dity/ val3)
# add_subdirectory (/home/elvis/code/val3dity/ build)

target_link_libraries (mytest LINK_PUBLIC val3dity)

#pybind11_add_module(kf_cpp main.cpp)