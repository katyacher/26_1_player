cmake_minimum_required(VERSION 3.0.0)

add_executable(26_1_player main.cpp ${MY_INCLUDE_DIR}/track.h track.cpp  ${MY_INCLUDE_DIR}/player.h player.cpp)

target_include_directories(26_1_player PUBLIC ${MY_INCLUDE_DIR})