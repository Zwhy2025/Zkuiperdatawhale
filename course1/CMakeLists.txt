# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.16)

# 定义项目名称
project(kuiper_datawhale_course1)

# 查找并添加benchmark库的依赖
find_package(benchmark REQUIRED) 
find_package(OpenMP REQUIRED)
find_package(Armadillo REQUIRED)
find_package(glog REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

# 查找并添加GTest库的依赖
find_package(GTest REQUIRED)

# 设置需要链接的库
set(link_lib glog::glog GTest::gtest)
if(!WIN32)
    set(link_lib "${link_lib} pthread")
endif()

# 设置需要链接的数学库
set(link_math_lib ${ARMADILLO_LIBRARIES} ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})

# 将测试目录下的源文件添加到可执行文件中
aux_source_directory(./test DIR_TEST_ARMA)

# 创建可执行文件，并链接所需的库和依赖
add_executable(kuiper_datawhale_course1 course1_main.cpp ${DIR_TEST_ARMA})
target_link_libraries(kuiper_datawhale_course1 ${link_lib} ${link_math_lib} OpenMP::OpenMP_CXX)

# 设置可执行文件的头文件包含路径
target_include_directories(kuiper_datawhale_course1 PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(kuiper_datawhale_course1 PUBLIC ${GTest_INCLUDE_DIR})
target_include_directories(kuiper_datawhale_course1 PUBLIC ${Armadillo_INCLUDE_DIR})

# 启用测试
enable_testing()

