#cmake_minimum_required(VERSION 3.16)
#project(pytest)
#
#set(CMAKE_CXX_STANDARD 11)
#
#add_subdirectory(thirdparty/pybind11)
#
#pybind11_add_module(kf_cpp wrappers.cpp)

cmake_minimum_required(VERSION 3.16)
project(pytest)

set(CMAKE_CXX_STANDARD 11)

# add_subdirectory --所填目录必须包含CMakeLists.txt
add_subdirectory(thirdparty/pybind11)
add_subdirectory(thirdparty/val3dity)

# include_directories() --提供了一个搜索头文件暂时的根目录
include_directories(thirdparty/val3dity/thirdparty)  # include "nlohmann-json/json.hpp"
include_directories(thirdparty/val3dity/src) # # 即 include <val3dity.h>

# link_directories --用来 添加需要链接的库文件路经,
# 把该路径添加到第三方库搜索路径中，这样就可以使用相对路径了
# 使用TARGET_LINK_LIBRARIES的时候，只需要给出动态链接库的名字就行了
# 比如，你的第三方动态库在/home/myproject/libs这个路径下，则通过命令：
# link_directories(/home/myproject/libs)
#link_directories(thirdparty/val3dity/build)

# target_link_libraries -- 设置要链接的库文件的名称
# 连接libhello.so库==== 连两个呢？？？？？？？
target_link_libraries(pytest libval3dity.a libthirdparty.a)

# link_libraries
#LINK_LIBRARIES(thirdparty/val3dity/build/libthirdparty.a)
#LINK_LIBRARIES(thirdparty/val3dity/build/libval3dity.a)

#add_library()
pybind11_add_module(kf_cpp wrappers.cpp)
# first: module name
