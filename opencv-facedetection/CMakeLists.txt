cmake_minimum_required(VERSION 2.8)
project(opencv_facedetection)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(PkgConfig)
pkg_check_modules (OpenCV3 REQUIRED opencv>=3.1.0)
include_directories(${OpenCV3_INCLUDE_DIRS})
link_directories(${OpenCV3_LIBRARY_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(opencv_facedetection ${SOURCE_FILES})
target_link_libraries(opencv_facedetection ${OpenCV3_LIBRARIES})