cmake_minimum_required(VERSION 3.16)

project(schiffeversenken LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(schiffeversenken main.cpp
    battleship.h battleship.cpp
    part.h part.cpp
    gameboard.h gameboard.cpp
    player.h player.cpp
    ship.h ship.cpp)

include(GNUInstallDirs)
install(TARGETS schiffeversenken
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
