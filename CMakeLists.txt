cmake_minimum_required(VERSION 3.5)
project(SimpleLogging)

include_directories(include)
set (src include/logging.h src/logging.cpp)
set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleLogging ${src} example/example.cpp)
ADD_LIBRARY( SimpleLoggingLib STATIC ${src})