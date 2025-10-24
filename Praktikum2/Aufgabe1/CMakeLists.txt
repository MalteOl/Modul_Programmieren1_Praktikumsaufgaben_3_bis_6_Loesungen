cmake_minimum_required(VERSION 3.16)

project(Aufgabe1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Aufgabe1 main.cpp
    random.h random.cpp)

include(GNUInstallDirs)
install(TARGETS Aufgabe1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
