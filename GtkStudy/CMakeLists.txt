cmake_minimum_required(VERSION 3.5)
project(GtkStudy C)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#为工程准备库文件
set(PKG_CONFIG_EXECUTABLE "/opt/homebrew/bin/pkg-config")
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-quartz-3.0)
##很重要没它连接不上,这个是指定库文件的路径给cmake,因为GTK3库文件
#不在/usr/lib/等环境变量上，所以要给个指定的路径
# gcc -o xx/xx/库文件 xx/xx/头文件 就是这么个意思
link_directories(${GTK3_LIBRARY_DIRS})

message(STATUS "GTK3 library flags: ${GTK3_LIBRARIES}")
message(STATUS "GTK3 library directory: ${GTK3_LIBDIR}")
#三部曲之一，为工程添加头文件
include_directories(${GTK3_INCLUDE_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

set(INCLUDE_DIRS ./include)
include_directories(${INCLUDE_DIRS})

#三部曲之二,为工程添加源文件
set(SOURCE_FILES_DIRS ./src)
#查找SOURCE_FILES_DIRS目录下的所有源文件，并将其添加到变量SOURCE中
aux_source_directory(${SOURCE_FILES_DIRS} SOURCE)
add_executable(gtkStudy ${SOURCE})
#三部曲之三，连接库文件
target_link_libraries(gtkStudy ${GTK3_LIBRARIES})

