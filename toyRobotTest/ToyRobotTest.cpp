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

TEST(ToyRobotAssertPlacement, NoPlacement) {
	ToyRobot target(new TableEnvironment());
	try {
		target.move();
		FAIL();
	}
	catch (ToyRobotException ex) {
		EXPECT_EQ(ex.getMessage(), "Robot is not yet placed");
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

TEST(ToyRobotMove, MoveNorth) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(2, 2, "NORTH");
		target.move();
		string result = target.report();
		EXPECT_EQ(result, "Output: 2, 3, NORTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotMove, MoveSouth) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(2, 2, "SOUTH");
		target.move();
		string result = target.report();
		EXPECT_EQ(result, "Output: 2, 1, SOUTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotMove, MoveEast) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(2, 2, "EAST");
		target.move();
		string result = target.report();
		EXPECT_EQ(result, "Output: 3, 2, EAST");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotMove, MoveWest) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(2, 2, "WEST");
		target.move();
		string result = target.report();
		EXPECT_EQ(result, "Output: 1, 2, WEST");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotMove, MoveUnavailable) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "SOUTH");
		target.move();
		string result = target.report();
		FAIL();
	}
	catch (ToyRobotException ex) {
		EXPECT_EQ(ex.getMessage(), "Cannot place in position (0, -1)");
	}
}

TEST(ToyRobotLeftRight, LeftFromNorth) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "NORTH");
		target.left();
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, WEST");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotLeftRight, LeftFromOthers) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "EAST");
		target.left();
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, NORTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotLeftRight, RightFromWest) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "WEST");
		target.right();
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, NORTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotLeftRight, RightFromOthers) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "EAST");
		target.right();
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, SOUTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotCombinations, Combination1) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "NORTH");
		target.move();
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 1, NORTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotCombinations, Combination2) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(0, 0, "NORTH");
		target.left();
		string result = target.report();
		EXPECT_EQ(result, "Output: 0, 0, WEST");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}

TEST(ToyRobotCombinations, Combination3) {
	ToyRobot target(new TableEnvironment());
	try {
		target.place(1, 2, "EAST");
		target.move();
		target.move();
		target.left();
		target.move();
		string result = target.report();
		EXPECT_EQ(result, "Output: 3, 3, NORTH");
	}
	catch (ToyRobotException ex) {
		// It is not expected to throw an exception
		FAIL();
	}
}