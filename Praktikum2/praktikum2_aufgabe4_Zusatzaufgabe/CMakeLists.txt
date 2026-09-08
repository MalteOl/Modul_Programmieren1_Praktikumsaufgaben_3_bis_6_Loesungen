cmake_minimum_required(VERSION 3.16)

project(praktikum2_aufgabe4_Zusatzaufgabe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(praktikum2_aufgabe4_Zusatzaufgabe main.cpp)

include(GNUInstallDirs)
install(TARGETS praktikum2_aufgabe4_Zusatzaufgabe
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
