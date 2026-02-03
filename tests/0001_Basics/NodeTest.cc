#include <gtest/gtest.h>
#include "../include/0001_Basics/Node.h"

// Demonstrate some basic assertions.
namespace NodeTesting
{
	TEST(TestingNodeValue, PositiveTestCase) 
	{
		// Expect two strings not to be equal.
		EXPECT_EQ(2 * 4, 8);
	}
}