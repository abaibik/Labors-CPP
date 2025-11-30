cmake_minimum_required(VERSION 3.28)
project(Aufgabe14 CXX)

# Turning off extensions avoids an issue with the clang 16 compiler
# clang 17 and greater can avoid this setting
set(CMAKE_CXX_EXTENSIONS OFF)
# Set the version of C++ for the project
set(CMAKE_CXX_STANDARD 20)


add_executable(main)
target_sources(main
    PUBLIC
    main.cpp
)
target_sources(main
  PUBLIC
    FILE_SET CXX_MODULES FILES
    Employee.cppm
    Manager.cppm
    Worker.cppm
)