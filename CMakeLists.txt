cmake_minimum_required(VERSION 3.12)
project(StarWars_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(test src/tests.cpp src/rebelfleet.cc src/rebelfleet.h src/imperialfleet.cc src/imperialfleet.h src/helper.cc src/helper.h src/battle.cc src/battle.h)
add_executable(example zadanie/starwars2_example.cc src/rebelfleet.cc src/rebelfleet.h src/imperialfleet.cc src/imperialfleet.h src/helper.cc src/helper.h src/battle.cc src/battle.h)
add_executable(example2 zadanie/starwars2_example.cc src/rebelfleet.cc src/rebelfleet.h src/helper.cc src/helper.h)