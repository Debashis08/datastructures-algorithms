#pragma once

#include<vector>
using namespace std;

/*
pattern 1
linear recurrence

description
There are n houses built in a line, each of which contains some money in it.
A robber wants to steal money from these houses, but he can't steal from two adjacent houses. the task is to find the maximum amount of money which can be stolen.

*/

namespace dsa::house_robber_1
{
	class DynamicProgramming
	{
	private:
	public:
		int findMaxLoot(vector<int>& houses);
	};
}