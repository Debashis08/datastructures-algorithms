#include "0001_bfs.h"

namespace dsa::bfs
{
	vector<int> Graph::bfs(vector<vector<int>>& adjMat, int n, int source)
	{
		vector<bool> visited(n, false);
		vector<int> distance(n, -1);
		queue<int> q;

		q.push(source);
		visited[source] = true;
		distance[source] = 0;

		while (!q.empty())
		{
			int u = q.front();
			visited[u] = true;
			q.pop();

			for (auto& v : adjMat[u])
			{
				if (!visited[v])
				{
					distance[v] = distance[u] + 1;
					q.push(v);
				}
			}
		}

		return distance;
	}
}