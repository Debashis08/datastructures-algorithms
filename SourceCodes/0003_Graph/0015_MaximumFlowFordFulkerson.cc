#include "../Headers/0003_Graph/0015_MaximumFlowFordFulkerson.h"
using namespace std;

namespace MaximumFlowFordFulkerson
{
	// Graph Private Member Methods
	void Graph::ResolvePrallelEdges()
	{
		int countParallelEdges = 0;
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (this->_adjMatrix[i][j] != 0 && this->_adjMatrix[j][i] != 0)
				{
					countParallelEdges++;
				}
			}
		}

		// As i->j and j->i both edges has been counted, actual count is count = count / 2
		countParallelEdges /= 2;

		this->_flagParallelEdges = countParallelEdges > 0 ? true : false;

		for (auto& edge : this->_adjMatrix)
		{
			edge.resize(this->_noOfVertices + countParallelEdges, 0);
		}
		int k = this->_noOfVertices;
		this->_noOfVertices += countParallelEdges;
		this->_visited.resize(this->_noOfVertices, false);
		this->_parent.resize(this->_noOfVertices, -1);
		this->_adjMatrix.resize(this->_noOfVertices, vector<int>(this->_noOfVertices, 0));

		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (this->_adjMatrix[i][j] != 0 && this->_adjMatrix[j][i] != 0)
				{
					this->_adjMatrix[i][k] = this->_adjMatrix[i][j];
					this->_adjMatrix[k][j] = this->_adjMatrix[i][j];
					this->_adjMatrix[i][j] = 0;
					k++;
				}
			}
		}
	}

	void Graph::DepthFirstSearchVisit(int nodeU)
	{
		this->_visited[nodeU] = true;
		for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
		{
			if (!this->_visited[nodeV] && this->_residualGraph[nodeU][nodeV] > 0)
			{
				this->_parent[nodeV] = nodeU;
				this->DepthFirstSearchVisit(nodeV);
			}
		}
	}

	bool Graph::DepthFirstSearch()
	{
		fill(this->_visited.begin(), this->_visited.end(), false);
		fill(this->_parent.begin(), this->_parent.end(), -1);
		this->DepthFirstSearchVisit(this->_source);
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

	int Graph::FindMaximumFlowFordFulkerson()
	{
		// Resolving all the parallel edges if present
		this->ResolvePrallelEdges();
		this->_residualGraph = this->_adjMatrix;
		int augmentedPathFlow = INT_MAX;

		// While there exists a path p from source to sink in the residual network G'
		while (this->DepthFirstSearch())
		{
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