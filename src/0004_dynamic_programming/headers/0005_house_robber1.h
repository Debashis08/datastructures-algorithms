#pragma once
#include <vector>
using namespace std;

/*
pattern 1
linear recurrence

description
there are n houses built in a line, each of which contains some money in it.
A robber wants to steal money from these houses, but he can’t steal from two adjacent houses. the task is to find the maximum amount of money which can be stolen.

*/

namespace house_robber1
{
	class DynamicProgramming
	{
	private:
		int maxLootRecursive(size_t house, vector<int>& houseValues);
	public:
		int recursiveMaximumLoot(vector<int>& houseValues);
		int dpMaximumLoot(vector<int>& houseValues);
	};
}