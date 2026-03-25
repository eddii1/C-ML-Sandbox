cmake_minimum_required(VERSION 4.1)
project(proiect_oop)

set(CMAKE_CXX_STANDARD 20)

add_executable(proiect_oop main.cpp
        Vector.cpp
        Vector.h
        Matrix.cpp
        Matrix.h
        ParseCSV.cpp
        ParseCSV.h)
