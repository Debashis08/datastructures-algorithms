#include <gtest/gtest.h>
#include "../0000_test_utilities/unit_test_helper.h"
#include "0003_red_black_tree.h"

namespace dsa::red_black_tree
{
	UnitTestHelper utHelper;
	TEST(RedBlackTreeTest, SimpleDataTest)
	{
		// Arrange
		RedBlackTree rbTree;
		rbTree.insertNode(50);
		rbTree.insertNode(30);
		rbTree.insertNode(40);
		rbTree.insertNode(70);
		rbTree.insertNode(80);
		rbTree.insertNode(90);

		// Act
		string actualResult = utHelper.serializeVectorToString(rbTree.recursiveInorderTraversal());
		string expectedResult = "[30 2][40 2][50 2][70 1][80 2][90 1]";

		// Assert
		EXPECT_EQ(actualResult, expectedResult);
	}
}