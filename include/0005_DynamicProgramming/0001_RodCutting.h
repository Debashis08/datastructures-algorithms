#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace RodCutting
{
	class DynamicProgramming
	{
	private:
		int _length;
		vector<int> _price;
		vector<int> _cutPositions;
	public:
		DynamicProgramming(int length, vector<int> price);
		int RecursiveRodCutting(int length);
		pair<int, vector<int>> DpGetMaximumProfitWithCuts();
	};
}