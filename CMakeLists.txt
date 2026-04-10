cmake_minimum_required(VERSION 3.10)
project(PO_Projekt)

find_package(Curses REQUIRED)

add_executable(PO_Projekt main.cpp
        Swiat.cpp
        Swiat.h
        Organizm.cpp
        Organizm.h
        Roslina.cpp
        Roslina.h
        Zwierze.cpp
        Zwierze.h
        Czlowiek.cpp
        Czlowiek.h
        Wilk.cpp
        Wilk.h
        Owca.cpp
        Owca.h
        Lis.cpp
        Lis.h
        Zolw.cpp
        Zolw.h
        Antylopa.cpp
        Antylopa.h
        Trawa.cpp
        Trawa.h
        Mlecz.cpp
        Mlecz.h
        Guarana.cpp
        Guarana.h)

target_include_directories(PO_Projekt PRIVATE ${CURSES_INCLUDE_DIRS})

target_link_libraries(PO_Projekt PRIVATE ${CURSES_LIBRARIES})
