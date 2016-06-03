cmake_minimum_required(VERSION 3.2)
project(libpuzzle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(PkgConfig)

pkg_check_modules (PUZZLE2 REQUIRED puzzle=0.11)
include_directories(${PUZZLE2_INCLUDE_DIRS})
link_directories(${PUZZLE2_LIBRARY_DIRS})
set(SOURCE_FILES main.c)

add_executable(puzzle-demo ${SOURCE_FILES})
target_link_libraries(puzzle-demo ${PUZZLE2_LIBRARIES})

