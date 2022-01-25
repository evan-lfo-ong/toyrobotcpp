#include "ToyRobot.hpp"
#include <sstream>
#include <string>

using namespace std;

namespace ToyRobotNS {
	const string directionNames[] = { "NORTH", "EAST", "SOUTH", "WEST" };
	const int directionNamesSize = sizeof(directionNames) / sizeof(directionNames[0]);
	string getDirectionString(CardinalDirection dir) {
		return directionNames[dir];
	}
	CardinalDirection getDirection(string dir) {
		int result = -1;
		for (int i = 0; i < directionNamesSize; i++) {
			if (dir == directionNames[i]) {
				result = i;
				break;
			}
		}
		if (result == -1) {
			throw ToyRobotException("Unknown direction " + dir);
		} 
		return (CardinalDirection)result;
	}

	ToyRobot::ToyRobot(IRobotEnvironment* environment) {
		pEnv = environment;
		position = { 0, 0 };
		direction = North;
	}

	void ToyRobot::assertEnvironment() {
		if (pEnv == nullptr) {
			throw ToyRobotException("Robot is not in an environment");
		}
	}

	Coordinate ToyRobot::place(int x, int y, string directionString) {
		assertEnvironment();
		if (!pEnv->spaceAvailable(x, y)) {
			stringstream ss;
			ss << "Cannot place in position (" << x << ", " << y << ")";
			throw ToyRobotException(ss.str());
		}
		position = { x, y };
		direction = getDirection(directionString);
		return position;
	}

	Coordinate ToyRobot::move() {
		assertEnvironment();
		int x = position.first;
		int y = position.second;
		switch (direction) {
		case North: {
			y++;
			break;
		}
		case South: 
			y--;
			break;
		case East:
			x++;
			break;
		case West:
			x--;
			break;
		default:
			throw ToyRobotException("Unknown direction");
		}
		if (!pEnv->spaceAvailable(x, y)) {
			stringstream ss;
			ss << "Cannot place in position (" << x << ", " << y << ")";
			throw ToyRobotException(ss.str());
		}
		position = { x, y };
		return position;
	}

	CardinalDirection ToyRobot::left() {
		direction = (direction == North) ? West : (CardinalDirection)(direction - 1);
		return direction;
	}

	CardinalDirection ToyRobot::right() {
		direction = (direction == West) ? North : (CardinalDirection)(direction + 1);
		return direction;
	}

	string ToyRobot::report() {
		stringstream ss;
		ss << "Output: " << position.first << ", " << position.second 
		   << ", " << getDirectionString(direction);
		return ss.str();
	}

	ToyRobotException::ToyRobotException(string msg) {
		message = msg;
	}
	string ToyRobotException::getMessage() {
		return message;
	}
}