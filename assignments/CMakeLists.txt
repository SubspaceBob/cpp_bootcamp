cmake_minimum_required(VERSION 3.15)
project(Assignment2)
add_subdirectory(googletest)
include_directories(googletest/include)
include_directories(day5)
add_library(shape SHARED day5/shape.cpp)

add_executable(Shapy day5/main.cpp )
target_link_libraries(Shapy PUBLIC shape)
target_link_directories(Shapy PUBLIC .)

add_executable(unittest_Shapey day5/tests.cpp)
target_link_libraries(unittest_Shapey PUBLIC shape)
target_link_directories(unittest_Shapey PUBLIC .)

add_executable(gtest_Shapey mygtests.cpp)
target_link_libraries(gtest_Shapey PUBLIC shape gtest gtest_main)
target_link_directories(gtest_Shapey PUBLIC .)