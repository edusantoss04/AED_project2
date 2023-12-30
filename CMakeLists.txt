cmake_minimum_required(VERSION 3.27)
project(AED_project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Classes)

add_executable(AED_project2
        Classes/Graph.cpp
        Classes/Graph.h
        Classes/DataManip.h
        Classes/DataManip.cpp
        Classes/Airport.cpp
        Classes/Airport.h
        Classes/Airline.h
        Classes/Airline.cpp
        Classes/main.cpp
        Classes/Coordinate.cpp
        Classes/Coordinate.h
        Classes/Country.h
        Classes/Country.cpp
        Classes/City.cpp
        Classes/City.h
        Classes/Menu.cpp
        Classes/Menu.h
        Classes/Statistics.cpp)
