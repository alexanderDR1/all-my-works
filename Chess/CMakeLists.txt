cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

add_executable(Chess main.cpp Board.cpp Board.h Piece.cpp Piece.h definitions.h)