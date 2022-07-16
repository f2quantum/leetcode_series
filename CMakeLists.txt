cmake_minimum_required(VERSION 3.16)
project(leetcode_series)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-DCLIONENV)
add_definitions(-Dmain114514=main)
add_executable(main main.cpp lib/dataStruct.cpp)
# 修改文件目录就成
add_executable(leetcode  _leetcode/74.cpp _leetcode/136.cpp)
