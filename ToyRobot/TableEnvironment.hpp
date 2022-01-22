#ifndef TABLE_ENVIRONMENT_HPP
#define TABLE_ENVIRONMENT_HPP

#include "RobotEnvironment.hpp"

namespace ToyRobotNS {
	class TableEnvironment : public IRobotEnvironment {
	public:
		virtual bool spaceAvailable(int x, int y);
	private:
		unsigned int length = 5;
	};
}

#endif // TABLE_ENVIRONMENT_HPP