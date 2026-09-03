cmake_minimum_required(VERSION 3.20)
project(ml_sandbox_cpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ml_sandbox
        src/main.cpp
        src/Vector.cpp
        src/Matrix.cpp
        src/Sample.cpp
        src/CsvParser.cpp
        src/Interface.cpp)

target_include_directories(ml_sandbox PRIVATE include)

if (MSVC)
    target_compile_options(ml_sandbox PRIVATE /W4)
else ()
    target_compile_options(ml_sandbox PRIVATE -Wall -Wextra -Wpedantic)
endif ()
