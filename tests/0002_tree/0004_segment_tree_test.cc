#include<gtest/gtest.h>
#include "0004_segment_tree.h"

namespace dsa::segment_tree
{
	TEST(segmentTreeTest, queryTest001)
	{
		// Arrange
		vector<int> data = { 1,2,3,4,5,6,7,8,9,10 };
		SegmentTree segmentTree(data);

		// Act
		int queryResult = segmentTree.query(1, 6);

		// Assert
		ASSERT_EQ(queryResult, 27);
	}

	TEST(segmentTreeTest, updateTest001)
	{
		// Arrange
		vector<int> data = { 1,2,3,4,5,6,7,8,9,10 };
		SegmentTree segmentTree(data);

		// Act
		int queryResult01 = segmentTree.query(1, 6);
		segmentTree.update(4, 6);
		int queryResult02 = segmentTree.query(1, 6);

		// Assert
		ASSERT_EQ(queryResult01, 27);
		ASSERT_EQ(queryResult02, 28);
	}

}