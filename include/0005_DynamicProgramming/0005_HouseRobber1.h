#pragma once
#include<vector>
using namespace std;

/*
Pattern 1
Linear Recurrence

Description
There are n houses built in a line, each of which contains some money in it.
A robber wants to steal money from these houses, but he can’t steal from two adjacent houses. The task is to find the maximum amount of money which can be stolen.

*/

namespace HouseRobber1
{
	class DynamicProgramming
	{
	private:
		int MaxLootRecursive(int house, vector<int>& houseValues);
	public:
		int RecursiveMaximumLoot(vector<int>& houseValues);
		int DpMaximumLoot(vector<int>& houseValues);
	};
}