#ifndef ROBOT_ENVIRONMENT_HPP
#define ROBOT_ENVIRONMENT_HPP

namespace ToyRobotNS {
	class IRobotEnvironment {
	public:
		virtual bool spaceAvailable(int x, int y) = 0;
	};
}

#endif // ROBOT_ENVIRONMENT_HPP