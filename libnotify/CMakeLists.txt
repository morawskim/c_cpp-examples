cmake_minimum_required(VERSION 3.2)
project(libnotify)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(PkgConfig)

pkg_check_modules (NOTIFY REQUIRED libnotify>0.7)
include_directories(${NOTIFY_INCLUDE_DIRS})
link_directories(${NOTIFY_LIBRARY_DIRS})

set(SOURCE_FILES main.c)
add_executable(notify-demo ${SOURCE_FILES})
target_link_libraries(notify-demo ${NOTIFY_LIBRARIES})