cmake_minimum_required(VERSION 3.16)

project(MiniOS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(myOs
    src/main.cpp
    src/process_manager.cpp
)
target_include_directories(myOs PRIVATE include)