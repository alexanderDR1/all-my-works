cmake_minimum_required(VERSION 3.15)
project(DogsVsCats)

set(CMAKE_CXX_STANDARD 17)

add_executable(DogsVsCats main.cpp Animal.cpp Animal.h Dog.cpp Dog.h Cat.cpp Cat.h)