cmake_minimum_required(VERSION 3.10)

project(p5-ref)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setze Debug als Standard-Build-Typ, falls keiner angegeben ist
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

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
  random.cpp random.h)

# Optional: Debug-Informationen explizit aktivieren
set_target_properties(battleships PROPERTIES
  COMPILE_FLAGS "-g"
)
