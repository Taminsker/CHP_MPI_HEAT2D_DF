cmake_minimum_required(VERSION 2.6)

project(CHP_MPI_HEAT2D_DF)
include(FindPkgConfig)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -ansi -O -Wwrite-strings -Wuninitialized -Wunreachable-code -Wno-missing-braces -Wno-missing-field-initializers -m64 -O3 -g -std=c++11" )

set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/exec)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/exec)

set(CMAKE_BUILD_TYPE Release)
set(TODAY "9-Mai-2020")

set(LIB_DIR ${CMAKE_SOURCE_DIR}/libs)

include(${LIB_DIR}/lib.cmake)

add_subdirectory (${CMAKE_SOURCE_DIR}/src/HeatMPI)
add_subdirectory (${CMAKE_SOURCE_DIR}/src/Exemple_1)
add_subdirectory (${CMAKE_SOURCE_DIR}/src/Exemple_2)
add_subdirectory (${CMAKE_SOURCE_DIR}/src/Exemple_3)
add_subdirectory (${CMAKE_SOURCE_DIR}/src/Exemples_123)

add_subdirectory (${CMAKE_SOURCE_DIR}/src/CompExe)
