# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
# 定义项目名称
project(learn_std_gtest)

find_package(glog REQUIRED)

# 查找并添加GTest库的依赖
find_package(GTest REQUIRED)

# 设置需要链接的库
set(link_lib glog::glog GTest::gtest)
if(!WIN32)
    set(link_lib "${link_lib} pthread")
endif()

# 将测试目录下的源文件添加到可执行文件中
aux_source_directory(./test DIR_TEST)

# 创建可执行文件，并链接所需的库和依赖
add_executable(learn_std_gtest Lmain.cpp ${DIR_TEST} test/learn_std.cpp)
target_link_libraries(learn_std_gtest ${link_lib})

# 设置可执行文件的头文件包含路径
target_include_directories(learn_std_gtest PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(learn_std_gtest PUBLIC ${GTest_INCLUDE_DIR})

# 启用测试
enable_testing()

