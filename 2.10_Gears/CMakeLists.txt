cmake_minimum_required(VERSION 3.0.0)
project(Gears VERSION 0.1.0)

add_executable("${PROJECT_NAME}" Graph/GraphNode.h Graph/Graph.h main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
