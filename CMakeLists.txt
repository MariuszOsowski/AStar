cmake_minimum_required(VERSION 3.3)
project(GridAStar)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp AStar/Node.cpp AStar/Node.h AStar/AStarInferface.h AStar/AStarInterface.cpp GridAStar.cpp GridAStar.h Helper.cpp Helper.h)
add_executable(GridAStar ${SOURCE_FILES})