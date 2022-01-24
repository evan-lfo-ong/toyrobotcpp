# CMakeList.txt : CMake project for toyRobotCpp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
include_directories(
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/toyRobotCpp"
)
add_executable (toyRobotCpp "main.cpp" "CommandParser.cpp")
target_link_libraries(toyRobotCpp PUBLIC ToyRobot)

target_include_directories(
	toyRobotCpp PUBLIC 
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/ToyRobot"
	"${PROJECT_SOURCE_DIR}/toyRobotCpp"
)
