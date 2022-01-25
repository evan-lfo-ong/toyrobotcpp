#include <gtest/gtest.h>
#include "TableEnvironment.hpp"

using namespace ToyRobotNS;

TEST(TableEnvironmentTest, OriginSpaceAvailableTrue) {
	TableEnvironment target;
	EXPECT_EQ(target.spaceAvailable(0, 0), true);
}

TEST(TableEnvironmentTest, InsideSpaceAvailableTrue) {
	TableEnvironment target;
	EXPECT_EQ(target.spaceAvailable(2, 3), true);
}

TEST(TableEnvironmentTest, NegativeXSpaceAvailableFalse) {
	TableEnvironment target;
	EXPECT_EQ(target.spaceAvailable(-1, 0), false);
}

TEST(TableEnvironmentTest, NegativeYSpaceAvailableFalse) {
	TableEnvironment target;
	EXPECT_EQ(target.spaceAvailable(0, -1), false);
}

TEST(TableEnvironmentTest, OutsideXSpaceAvailableFalse) {
	TableEnvironment target;
	EXPECT_EQ(target.spaceAvailable(6, 0), false);
}

TEST(TableEnvironmentTest, OutsideYSpaceAvailableFalse) {
	TableEnvironment target;
	EXPECT_EQ(target.spaceAvailable(0, 99), false);
}