cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project(ASCIIArcade LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ASCIIArcade source.cpp "game.h" "game.cpp" "tictactoe.h")