cmake_minimum_required(VERSION 3.20)
project(casino)

set(CMAKE_CXX_STANDARD 14)

add_executable(casino main.cpp src/blackjack.h src/game.h src/player.h src/slot.h src/blackjack.cpp src/game.cpp
        src/player.cpp src/slot.cpp)
