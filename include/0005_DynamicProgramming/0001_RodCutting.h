#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace RodCutting
{
	class DynamicProgramming
	{
	private:
		int _totalLength;
		vector<int> _price;
		vector<int> _cutPositions;
	public:
		DynamicProgramming(vector<int> price);
		int RecursiveRodCutting(int length);
		pair<int, vector<int>> DpGetMaximumProfitWithCuts(int length);
	};
}