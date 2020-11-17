cmake_minimum_required(VERSION 3.2)
project(test_thread)

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(test_thread main.cpp )
target_link_libraries(test_thread ${OpenCV_LIBS})