cmake_minimum_required(VERSION 3.9)
project(SimpleLogging)

include_directories(include)
set (src include/loging.h src/loging.cpp)
set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleLogging ${src} example/main.cpp)