cmake_minimum_required(VERSION 3.20)
project(red_belt)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES paginator.cpp test_runner.h)
add_executable(red_belt ${SOURCES})
