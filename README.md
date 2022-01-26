# toyRobotCpp

## Name
Toy Robot Code Challenge

## Description
A simple c++ project. 
Simulation of a toy robot that can be placed in a (default 5x5) environment.
User can input commands to move the toy robot around the environment

## Pre-requisites

### Windows

1. Install [Visual Studio Community Edition](https://visualstudio.microsoft.com/vs/community/)
2. Ensure that [Test Adapter for Google Test](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2022) is included in the Visual Studio installation

### MacOS / Linux

1. Install the following packages using appropriate package manager
    * build-essential
    * cmake
    * git

## Installation

1. Open terminal (macOs/linux) or [Developer Powershell](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-google-test-for-cpp?view=vs-2022) (windows)
2. Clone repository: `git clone https://gitlab.com/ong.evan/toyrobotcpp.git`
3. Create an output directory: `mkdir out`
4. Go to output directory and create makefiles: `cd out && cmake ..`
5. Build project: `make`
6. Executable is available at toyRobotCpp/out/toyRobotCpp

## Usage

./toyRobotCpp
* Program allows user to input robot commands through the standard input
* The following are valid commands
    * PLACE X,Y,DIRECTION 
        * places the toy robot in the X, Y coordinates specified
        * valid Direction strings are NORTH, SOUTH, EAST, and WEST
    * MOVE
        * moves the toy robot unit one unit forward in the direction it is facing
    * LEFT / RIGHT
        * Rotates the toy robot's direction by 90 degrees
        * Does not update the position
    * REPORT
        * Shows the current position and direction of the toy robot
    * EXIT 
        * closes the program
* Program discards All commands until a valid place command is issued
* Commands that will move the robot out of bounds will be ignored

## Test

1. Build the project
2. Go to the built test folder: `cd toyRobotCpp/out/toyRobotTest`
3. Execute test: `ctest`