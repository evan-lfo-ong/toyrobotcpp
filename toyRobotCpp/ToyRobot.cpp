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
			throw new ToyRobotException("Unknown direction " + dir);
		} 
		return (CardinalDirection)result;
	}

	Coordinate ToyRobot::place(int x, int y, string directionString) {
		position = { x, y };
		direction = getDirection(directionString);
		return position;
	}

	Coordinate ToyRobot::move() {
		return position;
	}

	CardinalDirection ToyRobot::left() {
		direction = (direction == West) ? North : (CardinalDirection)(direction + 1);
		return direction;
	}

	CardinalDirection ToyRobot::right() {
		direction = (direction == North) ? West : (CardinalDirection)(direction - 1);
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