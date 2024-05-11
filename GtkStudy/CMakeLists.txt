cmake_minimum_required(VERSION 3.8)
project(GtkStudy C)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#为工程准备库文件
set(PKG_CONFIG_EXECUTABLE "/opt/homebrew/bin/pkg-config")
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
##很重要没它连接不上,这个是指定库文件的路径给cmake,因为GTK4库文件
#不在/usr/lib/等环境变量上，所以要给个指定的路径
# gcc -o xx/xx/库文件 xx/xx/头文件 就是这么个意思
link_directories(${GTK4_LIBRARY_DIRS})

message(STATUS "GTK4 library flags: ${GTK4_LIBRARIES}")
message(STATUS "GTK4 library directory: ${GTK4_LIBDIR}")
#三部曲之一，为工程添加头文件
include_directories(${GTK4_INCLUDE_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})

set(INCLUDE_DIRS ./include)
include_directories(${INCLUDE_DIRS})

#三部曲之二,为工程添加源文件
set(SOURCE_FILES_DIRS ./src)
#查找SOURCE_FILES_DIRS目录下的所有源文件，并将其添加到变量SOURCE中
aux_source_directory(${SOURCE_FILES_DIRS} SOURCE)
add_executable(gtkStudy ${SOURCE})
#三部曲之三，连接库文件
target_link_libraries(gtkStudy ${GTK4_LIBRARIES})

