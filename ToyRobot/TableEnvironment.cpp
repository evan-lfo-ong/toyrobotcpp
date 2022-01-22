#include "TableEnvironment.hpp"

namespace ToyRobotNS {
	bool TableEnvironment::spaceAvailable(int x, int y) {
		return (
			x >= 0 && y >= 0 &&
			x < length && y < length
			);
	}
}