#include <gtest/gtest.h>
#include "0006_house_robber2.h"

namespace dsa::house_robber2
{
	TEST(houseRobber2, recursionTest01)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 2, 2, 3, 1, 2 };
		int expectedMaximumLoot = 5;

		// act
		int actualMaximumLoot = dp.recursiveMaximumLoot(houseValues);

		// assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

	TEST(houseRobber2, dpTest01)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 2, 2, 3, 1, 2 };
		int expectedMaximumLoot = 5;

		// act
		int actualMaximumLoot = dp.dpMaximumLoot(houseValues);

		// assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

	TEST(houseRobber2, dpTest02)
	{
		// arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 9, 1, 8, 2 };
		int expectedMaximumLoot = 17;

		// act
		int actualMaximumLoot = dp.dpMaximumLoot(houseValues);

		// assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

}