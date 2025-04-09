#include "../Headers/0003_Graph/0019_MaximumFlowRelabelToFront.h"
#include<climits>
#include<iterator>
using namespace std;

namespace MaximumFlowRelabelToFront
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

	// Discharges the excess flow from nodeU
	void Graph::Discharge(int nodeU)
	{
		// Check if excess flow of nodeU is > 0
		while (this->_excessFlow[nodeU] > 0)
		{
			// Falg to check if any amount of excess flow is pushed to any neighbour vertex
			bool hasPushed = false;

			// Iterating over all of the vertices
			for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
			{
				// For G'.Adj[nodeU] check if edge (nodeU, nodeV) is admissible
				if (this->_residualGraph[nodeU][nodeV] > 0 && this->_height[nodeU] == 1 + this->_height[nodeV])
				{
					// Push excess flow along the admissible edge (nodeU, nodeV)
					this->Push(nodeU, nodeV);
					// Set the hasPushed flag to true
					hasPushed = true;
					// Check if there is no excess flow left in nodeU then no need to check any more admissible edge going from nodeU
					if (this->_excessFlow[nodeU] == 0)
					{
						// Then break from iterating over G'.Adj[nodeU]
						break;
					}
				}
			}

			// Check if Push operation is not done yet
			if (!hasPushed)
			{
				// Then it indicates that all the outgoing edges from nodeU are inadmissible
				// so perform the Relabel operation on nodeU
				this->Relabel(nodeU);
			}
		}
	}

	// Pushes the flow from nodeU to its neighbour vertices
	void Graph::Push(int nodeU, int nodeV)
	{
		// Calculate the flow amount to be added along the edge and excess flow subtracted from nodeU
		int minimumFlow = min(this->_residualGraph[nodeU][nodeV], this->_excessFlow[nodeU]);

		// Adjust the flow and the reverse flow along (nodeU, nodeV)
		this->_residualGraph[nodeU][nodeV] = this->_residualGraph[nodeU][nodeV] - minimumFlow;
		this->_residualGraph[nodeV][nodeU] = this->_residualGraph[nodeV][nodeU] + minimumFlow;

		// Adjust the excess flows in nodeU and nodeV
		this->_excessFlow[nodeU] = this->_excessFlow[nodeU] - minimumFlow;
		this->_excessFlow[nodeV] = this->_excessFlow[nodeV] + minimumFlow;
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

	int Graph::FindMaximumFlowRelabelToFront()
	{
		this->_residualGraph = this->_adjMatrix;

		// Initialize Pre-flow
		this->InitializePreflow();

		// Make the list L = G.V - {source, sink}
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			if (i != this->_source && i != this->_sink)
			{
				this->_nodeList.push_back(i);
			}
		}

		// Set current vertex = L.head
		list<int>::iterator nodeUiterator = this->_nodeList.begin();

		// Iterate over all of the elements in the list L
		while (nodeUiterator != this->_nodeList.end())
		{
			// Get the height of current vertex
			int oldHeight = this->_height[*nodeUiterator];

			// Discharge the excess flow of current vertex
			this->Discharge(*nodeUiterator);

			// Check if the height of current vertex increases which means the current vertex got relabeled
			if (this->_height[*nodeUiterator] > oldHeight)
			{
				// Then move current vertex to the front of the list L
				this->_nodeList.splice(this->_nodeList.begin(), this->_nodeList, nodeUiterator);
			}

			// Go to the next vertex of current vertex in L
			nodeUiterator++;
		}

		// Return the excess flow in the sink vertex which is actually the maximum flow along the given flow network
		return this->_excessFlow[this->_sink];
	}
}