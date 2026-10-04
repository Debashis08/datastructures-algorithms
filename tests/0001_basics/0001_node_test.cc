#include <gtest/gtest.h>
#include "0001_node.h"

// Demonstrate some basic assertions.
namespace dsa::node_testing
{
	TEST(testingNodeValue, positiveTestCase) 
	{
		// Expect two values to be equal.
		Node* node = new Node();
		ASSERT_EQ(node->value, 8);
	}
}