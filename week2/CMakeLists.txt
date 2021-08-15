cmake_minimum_required(VERSION 3.20)
project(week2)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES slow.cpp test_runner.h profile.h)
add_executable(red_belt ${SOURCES})
