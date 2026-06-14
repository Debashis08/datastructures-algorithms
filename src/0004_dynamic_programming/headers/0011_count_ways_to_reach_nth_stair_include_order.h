#pragma once

#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
there are n stairs, and a person standing at the bottom wants to climb stairs to reach the top. 
the person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways that a person can reach at the top.

note: this problem is similar to count ways to reach nth stair (order does not matter) with the only difference that in this problem, 
we count all distinct ways where different orderings of the steps are considered unique.

examples:

input: n = 1
output: 1
explanation: there is only one way to climb 1 stair.

input: n = 2
output: 2
explanation: there are two ways to reach 2th stair: {1, 1} and {2}.

input: n = 4
output: 5
explanation: there are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
*/

namespace dsa::count_ways_to_reach_nth_stair_include_order
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