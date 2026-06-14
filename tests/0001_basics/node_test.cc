#include <gtest/gtest.h>
#include "node.h"

// demonstrate some basic assertions.
namespace dsa::node_testing
{
	TEST(testingNodeValue, positiveTestCase) 
	{
		// expect two strings not to be equal.
		EXPECT_EQ(2 * 4, 8);
	}
}