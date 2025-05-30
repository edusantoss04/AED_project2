cmake_minimum_required(VERSION 3.26)
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
        Classes/Statistics.cpp
        Classes/FlightsManager.cpp)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)