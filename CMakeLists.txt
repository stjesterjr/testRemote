cmake_minimum_required(VERSION 3.23)

project(app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(exec)

target_sources(exec
    PRIVATE
        src/main.cpp
)
