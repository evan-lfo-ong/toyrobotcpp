#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <utility>
#include <string>

using namespace std;

namespace ToyRobotNS {

	struct PlaceCommandArgs {
		int x;
		int y;
		string direction;
	};

	enum CommandID {
		UnknownCommand = -1,
		PlaceCommand,
		MoveCommand,
		LeftCommand,
		RightCommand,
		ReportCommand
	};

	namespace CommandParser {
		std::pair<CommandID, PlaceCommandArgs> ParseCommandLine(string input);
	}
}

#endif // COMMAND_PARSER_HPP