#include <gtest/gtest.h>
#include <0005_DynamicProgramming/0009_FriendsPairingProblem.h>

namespace FriendsPairingProblem
{
	TEST(FriendsPairingProblemDynamicProgrammingTest, RecursiveCountFriendsPairingsTest1)
	{
		// Arrange
		DynamicProgramming dp;
		int numberOfFriends = 3;
		int expectedPairings = 4;
		
		// Act
		int actualPairings = dp.RecursiveCountFriendsPairings(numberOfFriends);

		// Assert
		ASSERT_EQ(expectedPairings, actualPairings);
		EXPECT_EQ(dp.RecursiveCountFriendsPairings(4), 10);
		EXPECT_EQ(dp.RecursiveCountFriendsPairings(5), 26);
	}

	TEST(FriendsPairingProblemDynamicProgrammingTest, RecursiveCountFriendsPairingsTest2)
	{
		// Arrange
		DynamicProgramming dp;
		int numberOfFriends = 4;
		int expectedPairings = 10;

		// Act
		int actualPairings = dp.RecursiveCountFriendsPairings(numberOfFriends);

		// Assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(FriendsPairingProblemDynamicProgrammingTest, RecursiveCountFriendsPairingsTest3)
	{
		// Arrange
		DynamicProgramming dp;
		int numberOfFriends = 5;
		int expectedPairings = 26;

		// Act
		int actualPairings = dp.RecursiveCountFriendsPairings(numberOfFriends);

		// Assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(FriendsPairingProblemDynamicProgrammingTest, DpCountFriendsPairingsTest1)
	{
		// Arrange
		DynamicProgramming dp;
		int numberOfFriends = 3;
		int expectedPairings = 4;

		// Act
		int actualPairings = dp.RecursiveCountFriendsPairings(numberOfFriends);

		// Assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(FriendsPairingProblemDynamicProgrammingTest, DpCountFriendsPairingsTest2)
	{
		// Arrange
		DynamicProgramming dp;
		int numberOfFriends = 4;
		int expectedPairings = 10;

		// Act
		int actualPairings = dp.RecursiveCountFriendsPairings(numberOfFriends);

		// Assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(FriendsPairingProblemDynamicProgrammingTest, DpCountFriendsPairingsTest3)
	{
		// Arrange
		DynamicProgramming dp;
		int numberOfFriends = 5;
		int expectedPairings = 26;

		// Act
		int actualPairings = dp.RecursiveCountFriendsPairings(numberOfFriends);

		// Assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}
}