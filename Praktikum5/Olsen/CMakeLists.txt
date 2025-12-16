cmake_minimum_required(VERSION 3.10)

project(p5-ref)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  battleships
  battleship.cpp
  gameboard.cpp
  main.cpp
  part.cpp
  player.cpp
  ship.cpp
  battleship.h
  gameboard.h
  part.h
  player.h
  ship.h
  random.cpp random.h
  statistics.h statistics.cpp)
