cmake_minimum_required(VERSION 3.16)

project(Praktikum6_Mustakim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Praktikum6_Mustakim main.cpp
    carnivore.h carnivore.cpp
    dinosaur.h dinosaur.cpp
    herbivore.h herbivore.cpp
    park.h park.cpp)

include(GNUInstallDirs)
install(TARGETS Praktikum6_Mustakim
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
