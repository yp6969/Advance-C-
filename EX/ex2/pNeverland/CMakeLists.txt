cmake_minimum_required(VERSION 3.20)
project(pNeverland)

set(CMAKE_CXX_STANDARD 11)

add_executable(pNeverland main.cpp Validation.cpp Validation.h User_Interaction.h User_Interaction.cpp  Graph.h Graph.cpp Neverland.cpp Neverland.h Configuration.cpp Configuration.h)
