cmake_minimum_required(VERSION 3.2)
project(monster)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)



add_subdirectory(./writeShell/src)
#add_subdirectory(./writeShell/test) 
#aux_source_directory(. DirSrcs)
#include_directories(./include)


