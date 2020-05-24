cmake_minimum_required(VERSION 3.15)
project(wargame-a)

set(CMAKE_CXX_STANDARD 14)

add_executable(wargame-a Demo.cpp TestCounter.cpp doctest.h DemoGame.cpp DemoGame.hpp Soldier.hpp FootSoldier.cpp FootSoldier.hpp FootCommander.cpp FootCommander.hpp Sniper.cpp Sniper.hpp SniperCommander.cpp SniperCommander.hpp Paramedic.cpp Paramedic.hpp ParamedicCommander.cpp ParamedicCommander.hpp Board.cpp Board.hpp Test.cpp)
