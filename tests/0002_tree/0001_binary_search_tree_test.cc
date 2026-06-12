#include <gtest/gtest.h>
#include <string>
#include "0001_BinarySearchTree.h"
#include "../0000_common_utilities/UnitTestHelper.h"

namespace BinarySearchTree
{
    UnitTestHelper unitTestHelper;

    TEST(BSTInsertData, RecursiveInorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);


        string actualResult = unitTestHelper.SerializeVectorToString(bst.recursiveInorderTraversal());
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, RecursivePreorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);

        string actualResult = unitTestHelper.SerializeVectorToString(bst.recursivePreorderTravesal());
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, RecursivePostorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);

        string actualResult = unitTestHelper.SerializeVectorToString(bst.recursivePostorderTravesal());
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisInorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);
        

        string actualResult = unitTestHelper.SerializeVectorToString(bst.morrisInorderTraversal());
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisPreorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);


        string actualResult = unitTestHelper.SerializeVectorToString(bst.morrisPreorderTraversal());
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(BSTInsertData, MorrisPostorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);


        string actualResult = unitTestHelper.SerializeVectorToString(bst.morrisPostorderTraversal());
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }
}