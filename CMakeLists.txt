cmake_minimum_required(VERSION 3.5)
project(SimpleLogging)

include_directories(include)
set(src include/logging.h src/logging.cpp include/advancedConfiguration.h src/advancedConfiguration.cpp)
set(CMAKE_CXX_STANDARD 11)


#add_executable(exampleLogLevel ${src} example/exampleLogLevel.cpp)
#add_executable(exampleMessageSrc ${src} example/exampleMessageSrc.cpp)
#add_executable(example1 ${src} example/example1.cpp )
#add_executable(examplePointOfIntresed ${src} example/examplePointOfIntressed.cpp)
ADD_LIBRARY(SimpleLoggingLib STATIC ${src})