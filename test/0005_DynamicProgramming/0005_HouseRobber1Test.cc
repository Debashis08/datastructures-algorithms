#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0005_HouseRobber1.h"

namespace HouseRobber1
{
	TEST(HouseRobber1, RecursionTest)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 6, 7, 1, 3, 8, 2, 4 };
		int expectedMaximumLoot = 19;

		// Act
		int actualMaximumLoot = dp.RecursiveMaximumLoot(houseValues);

		// Assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

	TEST(HouseRobber1, DpTest)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 6, 7, 1, 3, 8, 2, 4 };
		int expectedMaximumLoot = 19;

		// Act
		int actualMaximumLoot = dp.DpMaximumLoot(houseValues);

		// Assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}
}