cmake_minimum_required(VERSION 3.16)
project(FlisSzymon-etap1)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlisSzymon-etap1
        Magazyn.cpp
        Magazyn.h
        MagazynList.cpp
        MagazynList.h
        main.cpp
        Product.cpp
        Product.h
        Towar.cpp
        Towar.h
        TowarCiekly.cpp
        TowarCiekly.h
        TowarSypki.cpp
        TowarSypki.h
        Paleciak.cpp
        Paleciak.h
        stdin.txt)
