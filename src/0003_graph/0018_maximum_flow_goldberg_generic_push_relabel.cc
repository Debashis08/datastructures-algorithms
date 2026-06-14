#include "0018_maximum_flow_goldberg_generic_push_relabel.h"
#include <climits>
using namespace std;

namespace dsa::maximum_flow_goldberg_generic_push_relabel
{
	// Graph private member methods

	// initializes pre-flow in the given flow network
	void Graph::_initializePreflow()
	{
		// the height of source is set to highest possible height value
		this->_height[this->_source] = this->_noOfVertices;

		// iterating over all the vertices
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			// for the all the edges (source, v)
			if (this->_residualGraph[this->_source][i] > 0)
			{
				// v.excessFlow = capacity(source, v)
				this->_excessFlow[i] = this->_residualGraph[this->_source][i];

				// source.excessFlow = source.excessFlow - capacity(source, v)
				this->_excessFlow[this->_source] = this->_excessFlow[this->_source] - this->_residualGraph[this->_source][i];

				// adjusting the flow and reverse flow along source->v and v->source respectively
				this->_residualGraph[i][this->_source] = this->_residualGraph[this->_source][i];
				this->_residualGraph[this->_source][i] = 0;
			}
		}
	}

	// checks if there is any vertex which has excess flow
	bool Graph::_checkOverFlow()
	{
		// iterating over all of the vertices
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			// checks if the current vertex is not any special vertex like source, sink
			// and also if there is excess flow in the current vertex and it is already not present in the queue
			if (i!=this->_source && i!=this->_sink && this->_excessFlow[i] > 0 && this->_visited[i] == false)
			{
				// insert the current vertex into the queue
				this->_nodeQueue.push(i);

				// mark it as visited, so until it leaves the queue it is not inserted again even if all the excess flow is neutralized
				this->_visited[i] = true;
			}
		}

		// checks if there is no vertex having excess flow then returns false
		if (this->_nodeQueue.empty())
		{
			return false;
		}

		return true;
	}

	// pushes the flow from nodeU to its neighbour vertices
	bool Graph::_push(int nodeU)
	{
		int nodeV = -1;
		int minimumFlow = INT_MAX;

		// iterating over all the vertices
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			// for G'.adj[nodeU] select the vertex if edge (nodeU, i) is non-saturated and height[nodeU] == height[i] + 1
			if (this->_residualGraph[nodeU][i] > 0 && this->_height[nodeU] == this->_height[i] + 1)
			{
				nodeV = i;
				break;
			}
		}
		
		// checks if any neighbour vertex found having non-saturated edge
		if (nodeV != -1)
		{
			// calculate the flow amount to be added along the edge and excess flow subtracted from nodeU
			minimumFlow = min(this->_residualGraph[nodeU][nodeV], this->_excessFlow[nodeU]);

			// adjust the flow and the reverse flow along (nodeU, nodeV)
			this->_residualGraph[nodeU][nodeV] = this->_residualGraph[nodeU][nodeV] - minimumFlow;
			this->_residualGraph[nodeV][nodeU] = this->_residualGraph[nodeV][nodeU] + minimumFlow;

			// adjust the excess flows in nodeU and nodeV
			this->_excessFlow[nodeU] = this->_excessFlow[nodeU] - minimumFlow;
			this->_excessFlow[nodeV] = this->_excessFlow[nodeV] + minimumFlow;
			
			// return that the push operation is successful
			return true;
		}

		// return that the push operation is not successful
		return false;
	}

	// relabels height of vertex nodeU when there are outgoing non-saturated edges available
	void Graph::_relabel(int nodeU)
	{
		int minimumHeight = INT_MAX;

		// iterating over all the vertices
		for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
		{
			// for G'.adj[nodeU] select for which nodeV, height[nodeU] <= height[nodeV]
			if (this->_residualGraph[nodeU][nodeV] > 0 && this->_height[nodeU] <= this->_height[nodeV])
			{
				// get the minimum height among all these G'.adj[nodeU]
				minimumHeight = min(minimumHeight, this->_height[nodeV]);
			}
		}

		// set height[nodeU]
		this->_height[nodeU] = minimumHeight + 1;
	}


	// Graph public member methods
	void Graph::createGraph(int noOfVertices)
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

	void Graph::pushDirectedEdge(int valueU, int valueV, int capacity)
	{
		this->_adjMatrix[valueU][valueV] = capacity;
	}

	int Graph::findMaximumFlowGoldbergGenericPushRelabel()
	{
		this->_residualGraph = this->_adjMatrix;

		// initialize pre-flow
		this->_initializePreflow();

		// checks if there is some vertices which have excess flow
		while (this->_checkOverFlow())
		{
			// get the vertex
			int nodeU = this->_nodeQueue.front();
			
			// checks if the push operation is successful
			if (this->_push(nodeU))
			{
				// then remove the vertex from queue and set visited[nodeU] = true
				// so that on next checkOverFlow() method call this vertex can be discovered if it still has some excess flow
				this->_nodeQueue.pop();
				this->_visited[nodeU] = false;
			}

			// if the push operation is not successful
			else
			{
				// then relabel nodeU without removing it from the queue
				this->_relabel(nodeU);
			}
		}

		// return the excess flow in the sink vertex which is actually the maximum flow along the given flow network
		return this->_excessFlow[this->_sink];
	}
}