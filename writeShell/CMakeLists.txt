cmake_minimum_required(VERSION 3.15)
project(writeShell)

set(CMAKE_C_STANDARD 17)
include_directories(./include)
aux_source_directory(./src SRC_LIST)
add_executable(writeShell ${SRC_LIST})


