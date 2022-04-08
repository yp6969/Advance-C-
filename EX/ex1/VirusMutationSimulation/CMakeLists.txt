cmake_minimum_required(VERSION 3.21)
project(VirusMutationSimulation)

set(CMAKE_CXX_STANDARD 14)

add_executable(VirusMutationSimulation main.cpp SarsCov2.cpp SarsCov2.h Alpha.cpp Alpha.h Delta.cpp Delta.h Omicron.cpp Omicron.h Simulator.cpp Simulator.h RefCounter.cpp RefCounter.h utils.cpp utils.h)
