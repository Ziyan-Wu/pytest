cmake_minimum_required (VERSION 3.16)

project (myprogram)

set (CMAKE_BUILD_TYPE "Release")
#include_directories(thirdparty/val3dity/src)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/pybind11 py11)
pybind11_add_module(kf_cpp funcs.cpp)

add_executable (mytest main.cpp)
add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/val3dity/ val3)
# add_subdirectory (/home/elvis/code/val3dity/ build)
target_link_libraries (mytest LINK_PUBLIC val3dity)

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#  cmake .. -DLIBRARY=true
# -- Building val3dity library
# cmake ..
#-- Building val3dity library
#-- Configuring done
#-- Generating done
#-- Build files have been written to: /mnt/d/workplace/clion/pytest/com/build
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


# make
#Scanning dependencies of target kf_cpp
#[  3%] Building CXX object CMakeFiles/kf_cpp.dir/funcs.cpp.o
#[  7%] Linking CXX shared module kf_cpp.cpython-38-x86_64-linux-gnu.so
#[  7%] Built target kf_cpp
#Scanning dependencies of target thirdparty
#[ 11%] Building CXX object val3/CMakeFiles/thirdparty.dir/thirdparty/pugixml/pugixml.cpp.o
#[ 15%] Linking CXX static library libthirdparty.a
#[ 15%] Built target thirdparty
#Scanning dependencies of target val3dity
#[ 19%] Building CXX object val3/CMakeFiles/val3dity.dir/src/CityObject.cpp.o
#[ 23%] Building CXX object val3/CMakeFiles/val3dity.dir/src/CompositeSolid.cpp.o
#[ 26%] Building CXX object val3/CMakeFiles/val3dity.dir/src/CompositeSurface.cpp.o
#[ 30%] Building CXX object val3/CMakeFiles/val3dity.dir/src/Feature.cpp.o
#[ 34%] Building CXX object val3/CMakeFiles/val3dity.dir/src/GenericObject.cpp.o
#[ 38%] Building CXX object val3/CMakeFiles/val3dity.dir/src/GeometryTemplate.cpp.o
#[ 42%] Building CXX object val3/CMakeFiles/val3dity.dir/src/IndoorGraph.cpp.o
#[ 46%] Building CXX object val3/CMakeFiles/val3dity.dir/src/IndoorModel.cpp.o
#[ 50%] Building CXX object val3/CMakeFiles/val3dity.dir/src/MultiSolid.cpp.o
#[ 53%] Building CXX object val3/CMakeFiles/val3dity.dir/src/MultiSurface.cpp.o
#[ 57%] Building CXX object val3/CMakeFiles/val3dity.dir/src/Primitive.cpp.o
#[ 61%] Building CXX object val3/CMakeFiles/val3dity.dir/src/Solid.cpp.o
#[ 65%] Building CXX object val3/CMakeFiles/val3dity.dir/src/Surface.cpp.o
#[ 69%] Building CXX object val3/CMakeFiles/val3dity.dir/src/geomtools.cpp.o
#[ 73%] Building CXX object val3/CMakeFiles/val3dity.dir/src/input.cpp.o
#[ 76%] Building CXX object val3/CMakeFiles/val3dity.dir/src/main.cpp.o
#[ 80%] Building CXX object val3/CMakeFiles/val3dity.dir/src/val3dity.cpp.o
#[ 84%] Building CXX object val3/CMakeFiles/val3dity.dir/src/validate_prim_toporel.cpp.o
#[ 88%] Building CXX object val3/CMakeFiles/val3dity.dir/src/validate_shell.cpp.o
#[ 92%] Linking CXX static library libval3dity.a
#[ 92%] Built target val3dity
#Scanning dependencies of target mytest
#[ 88%] Building CXX object CMakeFiles/mytest.dir/main.cpp.o
#[ 92%] Linking CXX executable mytest
#[ 92%] Built target mytest
