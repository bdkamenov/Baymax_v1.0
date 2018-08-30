cmake_minimum_required(VERSION 3.12)
project(Baymax_v1_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(Baymax_v1_0 main.cpp baymax_core/    src/window.cpp baymax_core/include/window.h)