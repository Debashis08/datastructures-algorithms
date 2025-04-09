#include "../Headers/0003_Graph/0018_MaximumFlowGoldbergGenericPushRelabel.h"
#include<climits>
using namespace std;

namespace MaximumFlowGoldbergGenericPushRelabel
{
	// Graph Private Member Methods

	// Initializes Pre-Flow in the given Flow Network
	void Graph::InitializePreflow()
	{
		// The height of source is set to highest possible height value
		this->_height[this->_source] = this->_noOfVertices;

		// Iterating over all the vertices
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			// For the all the edges (source, v)
			if (this->_residualGraph[this->_source][i] > 0)
			{
				// v.excessFlow = capacity(source, v)
				this->_excessFlow[i] = this->_residualGraph[this->_source][i];

				// source.excessFlow = source.excessFlow - capacity(source, v)
				this->_excessFlow[this->_source] = this->_excessFlow[this->_source] - this->_residualGraph[this->_source][i];

				// Adjusting the flow and reverse flow along source->v and v->source respectively
				this->_residualGraph[i][this->_source] = this->_residualGraph[this->_source][i];
				this->_residualGraph[this->_source][i] = 0;
			}
		}
	}

	// Checks if there is any vertex which has excess flow
	bool Graph::CheckOverFlow()
	{
		// Iterating over all of the vertices
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			// Checks if the current vertex is not any special vertex like source, sink
			// and also if there is excess flow in the current vertex and it is already not present in the queue
			if (i!=this->_source && i!=this->_sink && this->_excessFlow[i] > 0 && this->_visited[i] == false)
			{
				// Insert the current vertex into the queue
				this->_nodeQueue.push(i);

				// Mark it as visited, so until it leaves the queue it is not inserted again even if all the excess flow is neutralized
				this->_visited[i] = true;
			}
		}

		// Checks if there is no vertex having excess flow then returns false
		if (this->_nodeQueue.empty())
		{
			return false;
		}

		return true;
	}

	// Pushes the flow from nodeU to its neighbour vertices
	bool Graph::Push(int nodeU)
	{
		int nodeV = -1;
		int minimumFlow = INT_MAX;

		// Iterating over all the vertices
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			// For G'.Adj[nodeU] select the vertex if edge (nodeU, i) is non-saturated and height[nodeU] == height[i] + 1
			if (this->_residualGraph[nodeU][i] > 0 && this->_height[nodeU] == this->_height[i] + 1)
			{
				nodeV = i;
				break;
			}
		}
		
		// Checks if any neighbour vertex found having non-saturated edge
		if (nodeV != -1)
		{
			// Calculate the flow amount to be added along the edge and excess flow subtracted from nodeU
			minimumFlow = min(this->_residualGraph[nodeU][nodeV], this->_excessFlow[nodeU]);

			// Adjust the flow and the reverse flow along (nodeU, nodeV)
			this->_residualGraph[nodeU][nodeV] = this->_residualGraph[nodeU][nodeV] - minimumFlow;
			this->_residualGraph[nodeV][nodeU] = this->_residualGraph[nodeV][nodeU] + minimumFlow;

			// Adjust the excess flows in nodeU and nodeV
			this->_excessFlow[nodeU] = this->_excessFlow[nodeU] - minimumFlow;
			this->_excessFlow[nodeV] = this->_excessFlow[nodeV] + minimumFlow;
			
			// Return that the Push operation is successful
			return true;
		}

		// Return that the Push operation is not successful
		return false;
	}

	// Relabels height of vertex nodeU when there are outgoing non-saturated edges available
	void Graph::Relabel(int nodeU)
	{
		int minimumHeight = INT_MAX;

		// Iterating over all the vertices
		for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
		{
			// For G'.Adj[nodeU] select for which nodeV, height[nodeU] <= height[nodeV]
			if (this->_residualGraph[nodeU][nodeV] > 0 && this->_height[nodeU] <= this->_height[nodeV])
			{
				// Get the minimum height among all these G'.Adj[nodeU]
				minimumHeight = min(minimumHeight, this->_height[nodeV]);
			}
		}

		// Set height[nodeU]
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

		// Initialize Pre-flow
		this->InitializePreflow();

		// Checks if there is some vertices which have excess flow
		while (this->CheckOverFlow())
		{
			// Get the vertex
			int nodeU = this->_nodeQueue.front();
			
			// Checks if the Push operation is successful
			if (this->Push(nodeU))
			{
				// Then remove the vertex from queue and set visited[nodeU] = true
				// so that on next CheckOverFlow() method call this vertex can be discovered if it still has some excess flow
				this->_nodeQueue.pop();
				this->_visited[nodeU] = false;
			}

			// If the Push operation is not successful
			else
			{
				// Then Relabel nodeU without removing it from the queue
				this->Relabel(nodeU);
			}
		}

		// Return the excess flow in the sink vertex which is actually the maximum flow along the given flow network
		return this->_excessFlow[this->_sink];
	}
}