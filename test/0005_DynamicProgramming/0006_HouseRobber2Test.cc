#include<gtest/gtest.h>
#include "../../include/0005_DynamicProgramming/0006_HouseRobber2.h"

namespace HouseRobber2
{
	TEST(HouseRobber2, RecursionTest01)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 2, 2, 3, 1, 2 };
		int expectedMaximumLoot = 5;

		// Act
		int actualMaximumLoot = dp.RecursiveMaximumLoot(houseValues);

		// Assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

	TEST(HouseRobber2, DpTest01)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 2, 2, 3, 1, 2 };
		int expectedMaximumLoot = 5;

		// Act
		int actualMaximumLoot = dp.DpMaximumLoot(houseValues);

		// Assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

	TEST(HouseRobber2, DpTest02)
	{
		// Arrange
		DynamicProgramming dp;
		vector<int> houseValues = { 9, 1, 8, 2 };
		int expectedMaximumLoot = 17;

		// Act
		int actualMaximumLoot = dp.DpMaximumLoot(houseValues);

		// Assert
		ASSERT_EQ(expectedMaximumLoot, actualMaximumLoot);
	}

}