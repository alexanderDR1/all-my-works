cmake_minimum_required(VERSION 3.15)
project(BankSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankSystem main.cpp Client.h Client.cpp Worker.h Worker.cpp BankSystem.cpp BankSystem.h)