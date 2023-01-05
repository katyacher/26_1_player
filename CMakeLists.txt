cmake_minimum_required(VERSION 3.0.0)
project(26.1_player_oop VERSION 0.1.0)


add_executable(26.1_player_oop main.cpp player.h player.cpp track.h track.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
