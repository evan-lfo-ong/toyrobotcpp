#include <gtest/gtest.h>
#include <string>
#include "ToyRobot.hpp"
#include "TableEnvironment.hpp"

using namespace ToyRobotNS;

TEST(ToyRobotAssertEnvironment, NoEnvironment) {
	ToyRobot target;
	try {
		target.place(0, 0, "NORTH");
		// above command is expected to throw an error, next line should not be reached
		FAIL(); 
	}
	catch (ToyRobotException ex) {
		EXPECT_EQ(ex.getMessage(), "Robot is not in an environment");
	}
}

TEST(ToyRobotGetDirectionHelpers, DirectionNorth) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "NORTH");
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, NORTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotGetDirectionHelpers, DirectionSouth) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "SOUTH");
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, SOUTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotGetDirectionHelpers, DirectionEast) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "EAST");
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, EAST");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotGetDirectionHelpers, DirectionWest) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "WEST");
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, WEST");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotGetDirectionHelpers, DirectionUnknown) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "NORTH-WEST");
		string result = target.report();
		FAIL();
	}
	catch (ToyRobotException ex) {
		EXPECT_EQ(ex.getMessage(), "Unknown direction NORTH-WEST");
	}
}