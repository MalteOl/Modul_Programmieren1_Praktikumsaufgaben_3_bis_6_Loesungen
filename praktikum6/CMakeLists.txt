cmake_minimum_required(VERSION 3.5)

project(praktikum6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(praktikum6 main.cpp
    dinosaur.h dinosaur.cpp
    herbivor.h herbivor.cpp
    carnivore.h carnivore.cpp
    park.h park.cpp)

include(GNUInstallDirs)
install(TARGETS praktikum6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
