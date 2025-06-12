#include <gtest/gtest.h>
#include "../Headers/0001_Basics/Node.h"

// Demonstrate some basic assertions.
namespace NodeTesting
{
	TEST(TestingNodeValue, PositiveTestCase)
	{
		// Expect equality.
		EXPECT_EQ(2 * 4, 8);
	}
}