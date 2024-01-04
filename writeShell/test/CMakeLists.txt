cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_C_STANDARD 17)
#add_executable(writeShell ${SRC_LIST})
include_directories(../include)
add_executable(test  ../src/writeShell.c ./testSplit.c)

