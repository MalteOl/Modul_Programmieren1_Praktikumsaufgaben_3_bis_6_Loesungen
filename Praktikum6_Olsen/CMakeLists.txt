cmake_minimum_required(VERSION 3.5)

project(praktikum6_final LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(praktikum6_final main.cpp
    dinosaur.h dinosaur.cpp
    random.cpp random.h
    herbivore.h herbivore.cpp
    carnivore.h carnivore.cpp
    park.h park.cpp)

include(GNUInstallDirs)
install(TARGETS praktikum6_final
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
