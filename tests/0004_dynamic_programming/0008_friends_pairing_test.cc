#include<gtest/gtest.h>
#include "0008_friends_pairing.h"

namespace dsa::friends_pairing
{
    TEST(FriendsPairingTest, 0001_ZeroFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 0;
        int expectedWays = 0;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0002_SingleFriend)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 1;
        int expectedWays = 1;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0003_TwoFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 2;
        int expectedWays = 2; // (1, 2) can stay single or pair up

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0004_ThreeFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 3;
        int expectedWays = 4; // {1,2,3}, {(1,2),3}, {(1,3),2}, {(2,3),1}

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0005_FourFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 4;
        int expectedWays = 10;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0006_FiveFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 5;
        int expectedWays = 26;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0007_SixFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 6;
        int expectedWays = 76;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0008_MediumNumberOfFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 8;
        int expectedWays = 764;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }

    TEST(FriendsPairingTest, 0009_LargerNumberOfFriends)
    {
        // Arrange
        DynamicProgramming dp;
        int n = 10;
        int expectedWays = 9496;

        // Act
        int actualWays = dp.findPairings(n);

        // Assert
        ASSERT_EQ(expectedWays, actualWays);
    }
}