#include "CommandParser.hpp"
#include <sstream>
#include <iostream>

using namespace std;

namespace ToyRobotNS {
	namespace CommandParser {
		pair<CommandID, PlaceCommandArgs> ParseCommandLine(string input) {
			string command;
			stringstream stream(input);

			stream >> command;

			CommandID id = (command == "PLACE") ? PlaceCommand :
				(command == "MOVE") ? MoveCommand :
				(command == "LEFT") ? LeftCommand :
				(command == "RIGHT") ? RightCommand :
				(command == "REPORT") ? ReportCommand :
				UnknownCommand;

			PlaceCommandArgs args = { -1, -1, "" };
			if (command == "PLACE") {
				int x, y;
				string direction;
				string argsStr;
				stream >> argsStr;
				stringstream argsStream(argsStr);
				int i = 0;
				while (argsStream.good()) {
					i++;
					string substr;
					getline(argsStream, substr, ',');
					switch (i) {
					case 1:
						x = atoi(substr.c_str());
						break;
					case 2:
						y = atoi(substr.c_str());
						break;
					case 3:
						direction = substr;
						break;
					default:
						break;
					}
				}
				args = { x, y, direction };
			}

			return { id, args };
		}
	}
}