﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

add_compile_options(-std=c++17)

project ("toyRobotCpp")

# Include ToyRobot library
add_subdirectory ("ToyRobot")

# Include main toyRobotCpp executable
add_subdirectory ("toyRobotCpp")

# Include toyRobot Test
add_subdirectory("toyRobotTest")
