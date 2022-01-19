cmake_minimum_required(VERSION 3.21)
project(hw2)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw2 main.cpp plane.cpp plane.h transport.cpp transport.h train.cpp train.h ship.cpp ship.h container.cpp container.h random.h)
