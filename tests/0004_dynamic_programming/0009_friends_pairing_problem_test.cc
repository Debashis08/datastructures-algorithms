#include <gtest/gtest.h>
#include "0009_friends_pairing_problem.h"

namespace dsa::friends_pairing_problem
{
	TEST(friendsPairingProblemDynamicProgrammingTest, recursiveCountFriendsPairingsTest1)
	{
		// arrange
		DynamicProgramming dp;
		int numberOfFriends = 3;
		int expectedPairings = 4;
		
		// act
		int actualPairings = dp.recursiveCountFriendsPairings(numberOfFriends);

		// assert
		ASSERT_EQ(expectedPairings, actualPairings);
		EXPECT_EQ(dp.recursiveCountFriendsPairings(4), 10);
		EXPECT_EQ(dp.recursiveCountFriendsPairings(5), 26);
	}

	TEST(friendsPairingProblemDynamicProgrammingTest, recursiveCountFriendsPairingsTest2)
	{
		// arrange
		DynamicProgramming dp;
		int numberOfFriends = 4;
		int expectedPairings = 10;

		// act
		int actualPairings = dp.recursiveCountFriendsPairings(numberOfFriends);

		// assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(friendsPairingProblemDynamicProgrammingTest, recursiveCountFriendsPairingsTest3)
	{
		// arrange
		DynamicProgramming dp;
		int numberOfFriends = 5;
		int expectedPairings = 26;

		// act
		int actualPairings = dp.recursiveCountFriendsPairings(numberOfFriends);

		// assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(friendsPairingProblemDynamicProgrammingTest, dpCountFriendsPairingsTest1)
	{
		// arrange
		DynamicProgramming dp;
		int numberOfFriends = 3;
		int expectedPairings = 4;

		// act
		int actualPairings = dp.recursiveCountFriendsPairings(numberOfFriends);

		// assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(friendsPairingProblemDynamicProgrammingTest, dpCountFriendsPairingsTest2)
	{
		// arrange
		DynamicProgramming dp;
		int numberOfFriends = 4;
		int expectedPairings = 10;

		// act
		int actualPairings = dp.recursiveCountFriendsPairings(numberOfFriends);

		// assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}

	TEST(friendsPairingProblemDynamicProgrammingTest, dpCountFriendsPairingsTest3)
	{
		// arrange
		DynamicProgramming dp;
		int numberOfFriends = 5;
		int expectedPairings = 26;

		// act
		int actualPairings = dp.recursiveCountFriendsPairings(numberOfFriends);

		// assert
		ASSERT_EQ(expectedPairings, actualPairings);
	}
}