#pragma once

#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
there are n stairs, and a person standing at the bottom wants to reach the top. the person can climb either 1 stair or 2 stairs at a time. count the number of ways, the person can reach the top (order does not matter).

note: the problem is similar to climbing stairs - count ways to reach nth stair with the only difference that in this problem, we don't have to count those ways which only differ in ordering of the steps.

examples:

input: n = 1
output: 1
explanation: there is only one way to climb 1 stair.

input: n = 2
output: 2
explanation: there are two ways to climb 2 stairs: {1, 1} and {2}.

input: n = 4
output: 3
explanation: three ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2} and {2, 2}.

input: n = 5
output: 3
explanation: three ways to reach 5th stair: {1, 1, 1, 1, 1}, {1, 1, 1, 2} and {1, 2, 2}.
*/

namespace dsa::count_ways_to_reach_nth_stair_exclude_order
{
	class DynamicProgramming
	{
	private:
		int _recursiveCountWaysHelper(int n);
	public:
		int recursiveCountWays(int n);
		int dpCountWays(int n);
	};
}