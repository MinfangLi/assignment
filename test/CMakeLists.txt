#*
#* MODEL-BASED SOFTWARE DESIGN
#* LABORATORY 2 SOLUTION - A.Y. 2020/21
#* 
#* (C) 2021 JACOPO SINI, MASSIMO VIOLANTE - Politecnico di Torino 
#*/ 

cmake_minimum_required(VERSION 3.8)

set(This ExampleTest)

set(Sources
    ExampleTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Controller
)

add_test(
    NAME ${This}
    COMMAND ${This}
)