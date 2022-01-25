// toyRobotCpp.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include "ToyRobot.hpp"
#include "TableEnvironment.hpp"
#include "CommandParser.hpp"

using namespace std;
using namespace ToyRobotNS;

int main()
{
	ToyRobot robot(new TableEnvironment());
	string input;
	while (input != "EXIT") {
		try {
			cout << "> ";
			getline(cin, input, '\n');
			auto parsed = CommandParser::ParseCommandLine(input);
			auto args = parsed.second;
			switch (parsed.first) {
			case PlaceCommand:
				robot.place(args.x, args.y, args.direction);
				break;
			case MoveCommand:
				robot.move();
				break;
			case LeftCommand:
				robot.left();
				break;
			case RightCommand:
				robot.right();
				break;
			case ReportCommand:
				cout << robot.report() << endl;
				break;
			default:
				cout << "Unknown command" << endl;
			}
		}
		catch (ToyRobotException ex) {
			cout << ex.getMessage() << endl;
		}
	}
	return 0;
}
