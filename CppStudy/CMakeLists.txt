cmake_minimum_required(VERSION 3.8)
project(CppStudy CPP)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(SOURCE_FILES_DIRS ./src)
set(INCLUDE_DIRS ./include)

include_directories(${INCLUDE_DIRS})
aux_source_directory(${SOURCE_FILES_DIRS} SOURCE)
add_executable(CppStudy ${SOURCE})


