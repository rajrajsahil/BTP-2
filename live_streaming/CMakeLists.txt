cmake_minimum_required(VERSION 3.5.1)
project(kohli)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(live live_to_ccode.cpp)
target_link_libraries(live ${OpenCV_LIBS})
