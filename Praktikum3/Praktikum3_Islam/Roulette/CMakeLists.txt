cmake_minimum_required(VERSION 3.16)

project(Roulette LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Roulette main.cpp
    random.h random.cpp)

include(GNUInstallDirs)
install(TARGETS Roulette
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
