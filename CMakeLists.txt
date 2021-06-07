#*
#* MODEL-BASED SOFTWARE DESIGN
#* LABORATORY 2 SOLUTION - A.Y. 2020/21
#* 
#* (C) 2021 JACOPO SINI, MASSIMO VIOLANTE - Politecnico di Torino 
#*/ 

cmake_minimum_required(VERSION 3.8)

set(This Controller)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_subdirectory(googletest)



set(Headers
    controller.h
)

set(Sources
    controller.c
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")