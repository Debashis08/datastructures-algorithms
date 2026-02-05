#pragma once

#include <vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

Note: The problem is similar to Climbing Stairs - Count ways to reach Nth stair with the only difference that in this problem, we don't have to count those ways which only differ in ordering of the steps.

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair.

Input: n = 2
Output: 2
Explanation: There are two ways to climb 2 stairs: {1, 1} and {2}.

Input: n = 4
Output: 3
Explanation: Three ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2} and {2, 2}.

Input: n = 5
Output: 3
Explanation: Three ways to reach 5th stair: {1, 1, 1, 1, 1}, {1, 1, 1, 2} and {1, 2, 2}.
*/

namespace CountWaysToReachNthStairExcludeOrder
{
	class DynamicProgramming
	{
	private:
		int RecursiveCountWaysToReachNthStairExcludeOrderHelper(int n);
	public:
		int RecursiveCountWaysToReachNthStairExcludeOrder(int n);
		int DpCountWaysToReachNthStairExcludeOrder(int n);
	};
}