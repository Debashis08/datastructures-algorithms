#include <gtest/gtest.h>
#include<string>
#include "../include/0002_Tree/0001_BinarySearchTree.h"
#include "../0000_CommonUtilities/UnitTestHelper.h"

namespace BinarySearchTree
{
    UnitTestHelper unitTestHelper;

    TEST(BSTInsertData, RecursiveInorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = unitTestHelper.SerializeVectorToString(bst.GetRecursiveInorderTravesalResult());
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, RecursivePreorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);

        string actualResult = unitTestHelper.SerializeVectorToString(bst.GetRecursivePreorderTravesalResult());
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, RecursivePostorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);

        string actualResult = unitTestHelper.SerializeVectorToString(bst.GetRecursivePostorderTravesalResult());
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisInorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);
        

        string actualResult = unitTestHelper.SerializeVectorToString(bst.GetMorrisInorderTraversalResult());
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisPreorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = unitTestHelper.SerializeVectorToString(bst.GetMorrisPreorderTraversalResult());
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisPostorderTest)
    {
        BinarySearchTree bst;
        bst.InsertNode(50);
        bst.InsertNode(30);
        bst.InsertNode(60);


        string actualResult = unitTestHelper.SerializeVectorToString(bst.GetMorrisPostorderTraversalResult());
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }
}