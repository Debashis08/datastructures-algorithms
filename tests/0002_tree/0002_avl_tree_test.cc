#include <gtest/gtest.h>
#include "0002_avl_tree.h"
#include "../0000_test_utilities/unit_test_helper.h"

namespace dsa::avl_tree
{
	UnitTestHelper utHelper;
	TEST(avlTreeTest, recursiveTest)
	{
		// Arrange
		AvlTree avlTree;
		avlTree.insertNode(50);
		avlTree.insertNode(30);
		avlTree.insertNode(40);
		avlTree.insertNode(70);
		avlTree.insertNode(80);
		avlTree.insertNode(90);

		// Act
		string actualResult = utHelper.serializeVectorToString(avlTree.recursiveInorderTraversal());
		string expectedResult = "[30 1][40 2][50 1][70 3][80 2][90 1]";
		// Assert
		EXPECT_EQ(actualResult, expectedResult);
	}
}