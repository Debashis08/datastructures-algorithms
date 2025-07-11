#include "../include/0003_Graph/0016_MaximumFlowEdmondsKarp.h"
#include<climits>
#include<queue>
using namespace std;

namespace MaximumFlowEdmondsKarp
{
	// Graph Private Member Methods
	void Graph::ResolveAntiParallelEdges()
	{
		int countParallelEdges = 0;
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (this->_adjMatrix[i][j] > 0 && this->_adjMatrix[j][i] > 0)
				{
					countParallelEdges++;
				}
			}
		}

		// As i->j and j->i both edges has been counted, actual count is count = count / 2
		countParallelEdges /= 2;

		this->_flagParallelEdges = countParallelEdges > 0;

		// If there are no anti-parallel edges, no need to modify the adjMatrix
		if (!this->_flagParallelEdges)
		{
			return;
		}

		int newNoOfVertices = this->_noOfVertices + countParallelEdges;

		// Modifying the adjMatrix
		for (auto& edge : this->_adjMatrix)
		{
			edge.resize(newNoOfVertices, 0);
		}
		int k = this->_noOfVertices;
		this->_visited.resize(newNoOfVertices, false);
		this->_parent.resize(newNoOfVertices, -1);
		this->_adjMatrix.resize(newNoOfVertices, vector<int>(newNoOfVertices, 0));

		// Removing the anti-parallel edges by adding new nodes
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (this->_adjMatrix[i][j] > 0 && this->_adjMatrix[j][i] > 0)
				{
					this->_adjMatrix[i][k] = this->_adjMatrix[i][j];
					this->_adjMatrix[k][j] = this->_adjMatrix[i][j];
					this->_adjMatrix[i][j] = 0;
					k++;
				}
			}
		}

		// Updating the total no of vertices after modifying the adjMatrix
		this->_noOfVertices = newNoOfVertices;
	}

	bool Graph::BreadthFirstSearch()
	{
		// Resetting the visited values
		fill(this->_visited.begin(), this->_visited.end(), false);

		// Resetting the parent values
		fill(this->_parent.begin(), this->_parent.end(), -1);

		queue<int> nodeQueue;
		nodeQueue.push(this->_source);
		this->_visited[this->_source] = true;

		while (!nodeQueue.empty())
		{
			int nodeU = nodeQueue.front();
			nodeQueue.pop();

			for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
			{
				if (!this->_visited[nodeV] && this->_residualGraph[nodeU][nodeV] > 0)
				{
					this->_parent[nodeV] = nodeU;
					this->_visited[nodeV] = true;
					nodeQueue.push(nodeV);
				}
			}
		}

		// Returning the visited value of the sink vertex, initially it was set to false
		return this->_visited[this->_sink];
	}

	// Graph Public Member Methods
	void Graph::CreateGraph(int noOfVertices)
	{
		this->_noOfVertices = noOfVertices;
		this->_source = 0;
		this->_sink = this->_noOfVertices - 1;
		this->_maximumFlow = 0;
		this->_flagParallelEdges = false;
		this->_adjMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, 0));
		this->_parent = vector<int>(this->_noOfVertices, -1);
		this->_visited = vector<bool>(this->_noOfVertices, false);
	}

	void Graph::PushDirectedEdge(int valueU, int valueV, int capacity)
	{
		this->_adjMatrix[valueU][valueV] = capacity;
	}

	int Graph::FindMaximumFlowEdmondsKarp()
	{
		// Resolving all the parallel edges if present
		this->ResolveAntiParallelEdges();
		this->_residualGraph = this->_adjMatrix;

		// While there exists a path p from source to sink in the residual network G'
		while (this->BreadthFirstSearch())
		{
			int augmentedPathFlow = INT_MAX;

			// Calculating c'(p) = min{ c'(u,v) : (u,v) is in p }
			for (int nodeV = this->_sink; nodeV > this->_source; nodeV = this->_parent[nodeV])
			{
				int nodeU = this->_parent[nodeV];
				augmentedPathFlow = min(augmentedPathFlow, this->_residualGraph[nodeU][nodeV]);
			}

			for (int nodeV = this->_sink; nodeV > this->_source; nodeV = this->_parent[nodeV])
			{
				int nodeU = this->_parent[nodeV];
				this->_residualGraph[nodeU][nodeV] -= augmentedPathFlow;
				this->_residualGraph[nodeV][nodeU] += augmentedPathFlow;
			}
			this->_maximumFlow += augmentedPathFlow;
		}

		return this->_maximumFlow;
	}
}