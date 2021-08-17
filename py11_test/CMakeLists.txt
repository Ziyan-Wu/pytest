cmake_minimum_required(VERSION 3.16)
project(py11test)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(../thirdparty/pybind11 py11)

find_package(pybind11 REQUIRED)
#----only can be used after install pybind11, but encouter permission error
pybind11_add_module(kf_cpp wrappers.cpp)