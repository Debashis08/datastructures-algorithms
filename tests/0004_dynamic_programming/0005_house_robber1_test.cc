#include <gtest/gtest.h>
#include "0005_house_robber1.h"

namespace dsa::house_robber1
{
	TEST(houseRobber1, recursionTest)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 6, 7, 1, 3, 8, 2, 4 };
		int expectedMaximumLoot = 19;

		// act
		int actualMaximumLoot = dp.recursiveMaximumLoot(houseValues);

		// assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

	TEST(houseRobber1, dpTest)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 6, 7, 1, 3, 8, 2, 4 };
		int expectedMaximumLoot = 19;

		// act
		int actualMaximumLoot = dp.dpMaximumLoot(houseValues);

		// assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}
}