cmake_minimum_required(VERSION 3.16)
project(PokerBot)

set(CMAKE_CXX_STANDARD 14)

add_executable(PokerBot main.cpp src/PokerBot.cpp src/PokerBot.hpp src/enum.hpp src/GameManager.cpp src/GameManager.hpp)