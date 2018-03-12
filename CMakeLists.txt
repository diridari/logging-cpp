cmake_minimum_required(VERSION 3.5)
project(SimpleLogging)

include_directories(include)
set (src include/logging.h src/logging.cpp)
set(CMAKE_CXX_STANDARD 11)

add_executable(SimpleLoggingExpl1 ${src} example/example1.cpp)
add_executable(SimpleLoggingExpl2 ${src} example/example2.cpp)
add_executable(SimpleLoggingExpl3 ${src} example/example3.cpp)

ADD_LIBRARY( SimpleLoggingLib STATIC ${src})