cmake_minimum_required(VERSION 3.15)
project(gale_shaple)

set(CMAKE_C_STANDARD 17)
include_directories(./include)
aux_source_directory(./src SRC_LIST)
add_executable(gale_shaple ${SRC_LIST})

# 在使用 pkg_check_modules 命令时，实际上会生成一系列的变量，其中包括了需要链接的库的信息和相关的头文件路径。
# 例如，在使用 pkg_check_modules 命令后，会生成类似以下的变量：
# LIBRARY_NAME_LIBRARIES: 包含需要链接的库的名称。
# LIBRARY_NAME_INCLUDE_DIRS: 包含需要链接的库的头文件路径。
# 因此，在链接找到的库时，你可以使用这些变量来指定相应的库和头文件路径。示例如下：
# target_link_libraries(your_target_name ${LIBRARY_NAME_LIBRARIES})
# include_directories(${LIBRARY_NAME_INCLUDE_DIRS})
# 这样做就能够正确地将找到的库链接到你的项目中，并且让编译器能够找到这些库所需的头文件。

find_package(PkgConfig REQUIRED)
#这里的名字要求是pkgconfig的对应xx.pc中的xx
pkg_check_modules(COLLECTOR REQUIRED collectionc)

include_directories(${COLLECTOR_INCLUDE_DIRS})
#collectionc是作者.pc文件给库的名字，我也不知道为什么不统一写名
#由于是利用pkg-config工具链接，以下相当于clang test.c `pkg-config  --libs --cflags collectionc` -o test
target_link_libraries(gale_shaple ${COLLECTOR_LIBRARIES})


