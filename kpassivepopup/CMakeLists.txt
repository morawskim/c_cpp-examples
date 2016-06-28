cmake_minimum_required(VERSION 3.5)
project(kpassivepopup)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
add_definitions(-DQT_USE_FAST_CONCATENATION -DQT_USE_FAST_OPERATOR_PLUS)
add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})

set(SOURCE_FILES main.cpp)
kde4_add_executable(kpassivepopup ${SOURCE_FILES})
target_link_libraries(kpassivepopup ${KDE4_KDECORE_LIBS} ${KDE4_KPARTS_LIBS} ${KDE4_KDEUI_LIBS})
