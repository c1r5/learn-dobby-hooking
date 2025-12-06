cmake_minimum_required(VERSION 3.10)
project(hook)

include_directories(include)

add_library(hook SHARED hook.cpp)

target_link_libraries(hook ${CMAKE_SOURCE_DIR}/lib/libdobby.so)
