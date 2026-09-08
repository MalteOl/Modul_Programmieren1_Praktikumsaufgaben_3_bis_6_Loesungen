cmake_minimum_required(VERSION 3.16)

project(praktikum2_aufgabe3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(praktikum2_aufgabe3 main.cpp)

include(GNUInstallDirs)
install(TARGETS praktikum2_aufgabe3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
