#pragma once

#include <vector>
using namespace std;

namespace dsa::dfs
{
	class Graph
	{
	private:
		int _time;
		void _dfsVisit(vector<vector<int>>& adjMat, vector<bool>& visited, vector<vector<int>>& discoveryTimes, int node);
	public:
		vector<vector<int>> dfs(vector<vector<int>>& adjMat, int n);
	};
}