cmake_minimum_required(VERSION 3.17)
project(14_18_ExpressionComputation)

set(CMAKE_CXX_STANDARD 11)

add_executable(14_18_ExpressionComputation
        Entities/Literal.h
        Parser/Parser.cpp Parser/Parser.h
        main.cpp)