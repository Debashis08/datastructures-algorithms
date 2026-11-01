#include "0002_dfs.h"

namespace dsa::dfs
{
	void Graph::_dfsVisit(vector<vector<int>>& adjMat, vector<bool>& visited, vector<vector<int>>& discoveryTimes, int node)
	{
		this->_time++;
		visited[node] = true;
		discoveryTimes[node][0] = this->_time;

		for (int v : adjMat[node])
		{
			if (!visited[v])
			{
				this->_dfsVisit(adjMat, visited, discoveryTimes, v);
			}
		}

		this->_time++;
		discoveryTimes[node][1] = this->_time;
	}

	vector<vector<int>> Graph::dfs(vector<vector<int>>& adjMat, int n)
	{
		vector<bool> visited(n, false);
		vector<vector<int>> discoveryTimes(n, vector<int>(2, -1));

		this->_time = 0;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i])
			{
				this->_dfsVisit(adjMat, visited, discoveryTimes, i);
			}
		}

		return discoveryTimes;
	}
}