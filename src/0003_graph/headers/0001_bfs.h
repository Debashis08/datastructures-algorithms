#pragma once

#include <vector>
#include <queue>
using namespace std;

namespace dsa::bfs
{
	class Graph
	{
	private:
	public:
		vector<int> bfs(vector<vector<int>>& adjMat, int n, int source);
	};
}