#include "../Headers/0003_Graph/0018_MaximumFlowGoldbergGenericPushRelabel.h"
#include<queue>
#include<climits>
using namespace std;

namespace MaximumFlowGoldbergGenericPushRelabel
{
	// Graph Private Member Methods
	void Graph::InitializePreflow()
	{
		this->_height[this->_source] = this->_noOfVertices;

		for (int i = 0; i < this->_noOfVertices; i++)
		{
			if (this->_residualGraph[this->_source][i] > 0)
			{
				this->_excessFlow[i] = this->_residualGraph[this->_source][i];
				this->_excessFlow[this->_source] = this->_excessFlow[this->_source] - this->_residualGraph[this->_source][i];
				this->_residualGraph[i][this->_source] = this->_residualGraph[this->_source][i];
				this->_residualGraph[this->_source][i] = 0;
			}
		}
	}

	bool Graph::CheckOverFlow()
	{
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			if (i!=this->_source && i!=this->_sink && this->_excessFlow[i] > 0 && this->_visited[i] == false)
			{
				this->_nodeQueue.push(i);
				this->_visited[i] = true;
			}
		}

		if (this->_nodeQueue.empty())
		{
			return false;
		}

		return true;
	}

	bool Graph::Push(int nodeU)
	{
		int nodeV = -1;
		int minimumFlow = INT_MAX;

		for (int i = 0; i < this->_noOfVertices; i++)
		{
			if (this->_residualGraph[nodeU][i] > 0 && this->_height[nodeU] == this->_height[i] + 1)
			{
				nodeV = i;
				break;
			}
		}
		
		if (nodeV != -1)
		{
			minimumFlow = min(this->_residualGraph[nodeU][nodeV], this->_excessFlow[nodeU]);
			this->_residualGraph[nodeU][nodeV] = this->_residualGraph[nodeU][nodeV] - minimumFlow;
			this->_residualGraph[nodeV][nodeU] = this->_residualGraph[nodeV][nodeU] + minimumFlow;
			this->_excessFlow[nodeU] = this->_excessFlow[nodeU] - minimumFlow;
			this->_excessFlow[nodeV] = this->_excessFlow[nodeV] + minimumFlow;
			return true;
		}

		return false;
	}

	void Graph::Relabel(int nodeU)
	{
		int minimumHeight = INT_MAX;

		for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
		{
			if (this->_residualGraph[nodeU][nodeV] > 0 && this->_height[nodeU] <= this->_height[nodeV])
			{
				minimumHeight = min(minimumHeight, this->_height[nodeV]);
			}
		}

		this->_height[nodeU] = minimumHeight + 1;
	}


	// Graph Public Member Methods
	void Graph::CreateGraph(int noOfVertices)
	{
		this->_noOfVertices = noOfVertices;
		this->_source = 0;
		this->_sink = this->_noOfVertices - 1;
		this->_maximumFlow = 0;
		this->_adjMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, 0));
		this->_excessFlow = vector<int>(this->_noOfVertices, 0);
		this->_height = vector<int>(this->_noOfVertices, 0);
		this->_visited = vector<bool>(this->_noOfVertices, false);
	}

	void Graph::PushDirectedEdge(int valueU, int valueV, int capacity)
	{
		this->_adjMatrix[valueU][valueV] = capacity;
	}

	int Graph::FindMaximumFlowGoldbergGenericPushRelabel()
	{
		this->_residualGraph = this->_adjMatrix;

		this->InitializePreflow();
		while (this->CheckOverFlow())
		{
			int nodeU = this->_nodeQueue.front();
			if (this->Push(nodeU))
			{
				this->_nodeQueue.pop();
				this->_visited[nodeU] = false;
			}
			else
			{
				this->Relabel(nodeU);
			}
		}

		return this->_excessFlow[this->_sink];
	}
}