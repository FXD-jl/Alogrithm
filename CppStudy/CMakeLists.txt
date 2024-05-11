cmake_minimum_required(VERSION 3.8)
project(CppStudy)

set(CMAKE_CXX_STANDARD 20)  
#若不支持C++20，则编译阶段报错
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(PKG_CONFIG_EXECUTABLE "/opt/homebrew/bin/pkg-config")
find_package(PkgConfig REQUIRED)
set(ENV(PKG_CONFIG_PATH) "$ENV{PKG_CONFIG_PATH}:/opt/homebrew/Cellar/eigen/3.4.0_1/share/pkgconfig/")
pkg_check_modules(Eigen3 REQUIRED eigen3)

link_libraries(${Eigen3_LIBRARY_DIRS})
include_directories(${Eigen3_INCLUDE_DIRS})

set(SOURCE_FILES_DIRS ./src)
set(INCLUDE_DIRS ./include)

include_directories(${INCLUDE_DIRS})
aux_source_directory(${SOURCE_FILES_DIRS} SOURCE)
add_executable(CppStudy ${SOURCE} ${Eigen3_LIBRARIES})


