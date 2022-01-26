#ifndef TOY_ROBOT_HPP
#define TOY_ROBOT_HPP

#include <utility>
#include <string>
#include "RobotEnvironment.hpp"

using namespace std;

namespace ToyRobotNS {
	using Coordinate = std::pair<int, int>;
	enum CardinalDirection {
		North = 0,
		East,
		South,
		West
	};

	class ToyRobot {
	public:
		Coordinate place(int x, int y, string directionString);
		Coordinate move();
		CardinalDirection left();
		CardinalDirection right();
		std::string report();
		ToyRobot(IRobotEnvironment* = nullptr);

	private:
		Coordinate position = { 0, 0 };
		CardinalDirection direction = North;
		bool isPlaced = false;
		IRobotEnvironment* pEnv;
		void assertEnvironment();
		void assertPlacement();
	};

	class ToyRobotException : public std::exception {
	public:
		ToyRobotException(string msg);
		string getMessage();
	private:
		string message;
	};
}

#endif // TOY_ROBOT_HPP