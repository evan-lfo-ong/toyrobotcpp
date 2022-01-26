include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	toyRobotTest
	"toyRobotTestMain.cpp"
	"TableEnvironmentTest.cpp"
	"ToyRobotTest.cpp"
)

target_link_libraries(
	toyRobotTest
	ToyRobot
	gtest_main
)

target_include_directories(
	toyRobotTest PUBLIC
	"${PROJECT_BINARY_DIR}"
	"${PROJECT_SOURCE_DIR}/ToyRobot"
	"${PROJECT_SOURCE_DIR}/toyRobotTest"
)

include(GoogleTest)
gtest_discover_tests(toyRobotTest)