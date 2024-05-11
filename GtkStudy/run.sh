#!/bin/zsh
cd ./build && rm -rf CMakeCache.txt CMakeFiles && cmake .. && make 
./gtkStudy
