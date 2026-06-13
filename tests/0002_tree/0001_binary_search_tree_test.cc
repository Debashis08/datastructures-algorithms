#include <gtest/gtest.h>
#include <string>
#include "0001_binary_search_tree.h"
#include "../0000_common_utilities/unit_test_helper.h"

namespace binary_search_tree
{
    UnitTestHelper unitTestHelper;

    TEST(bSTInsertData, recursiveInorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);


        string actualResult = unitTestHelper.serializeVectorToString(bst.recursiveInorderTraversal());
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(bSTInsertData, recursivePreorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);

        string actualResult = unitTestHelper.serializeVectorToString(bst.recursivePreorderTravesal());
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(bSTInsertData, recursivePostorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);

        string actualResult = unitTestHelper.serializeVectorToString(bst.recursivePostorderTravesal());
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(bSTInsertData, morrisInorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);
        

        string actualResult = unitTestHelper.serializeVectorToString(bst.morrisInorderTraversal());
        string expectedResult = "30 50 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(bSTInsertData, morrisPreorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);


        string actualResult = unitTestHelper.serializeVectorToString(bst.morrisPreorderTraversal());
        string expectedResult = "50 30 60";

        EXPECT_EQ(actualResult, expectedResult);
    }

    TEST(bSTInsertData, morrisPostorderTest)
    {
        BinarySearchTree bst;
        bst.insertNode(50);
        bst.insertNode(30);
        bst.insertNode(60);


        string actualResult = unitTestHelper.serializeVectorToString(bst.morrisPostorderTraversal());
        string expectedResult = "30 60 50";

        EXPECT_EQ(actualResult, expectedResult);
    }
}