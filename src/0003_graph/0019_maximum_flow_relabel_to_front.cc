#include "0019_maximum_flow_relabel_to_front.h"
#include <climits>
#include <iterator>
using namespace std;

namespace maximum_flow_relabel_to_front
{
	// Graph private member methods

	// initializes pre-flow in the given flow network
	void Graph::initializePreflow()
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

	// discharges the excess flow from nodeU
	void Graph::discharge(int nodeU)
	{
		// check if excess flow of nodeU is > 0
		while (this->_excessFlow[nodeU] > 0)
		{
			// falg to check if any amount of excess flow is pushed to any neighbour vertex
			bool hasPushed = false;

			// iterating over all of the vertices
			for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
			{
				// for G'.adj[nodeU] check if edge (nodeU, nodeV) is admissible
				if (this->_residualGraph[nodeU][nodeV] > 0 && this->_height[nodeU] == 1 + this->_height[nodeV])
				{
					// push excess flow along the admissible edge (nodeU, nodeV)
					this->push(nodeU, nodeV);
					// set the hasPushed flag to true
					hasPushed = true;
					// check if there is no excess flow left in nodeU then no need to check any more admissible edge going from nodeU
					if (this->_excessFlow[nodeU] == 0)
					{
						// then break from iterating over G'.adj[nodeU]
						break;
					}
				}
			}

			// check if push operation is not done yet
			if (!hasPushed)
			{
				// then it indicates that all the outgoing edges from nodeU are inadmissible
				// so perform the relabel operation on nodeU
				this->relabel(nodeU);
			}
		}
	}

	// pushes the flow from nodeU to its neighbour vertices
	void Graph::push(int nodeU, int nodeV)
	{
		// calculate the flow amount to be added along the edge and excess flow subtracted from nodeU
		int minimumFlow = min(this->_residualGraph[nodeU][nodeV], this->_excessFlow[nodeU]);

		// adjust the flow and the reverse flow along (nodeU, nodeV)
		this->_residualGraph[nodeU][nodeV] = this->_residualGraph[nodeU][nodeV] - minimumFlow;
		this->_residualGraph[nodeV][nodeU] = this->_residualGraph[nodeV][nodeU] + minimumFlow;

		// adjust the excess flows in nodeU and nodeV
		this->_excessFlow[nodeU] = this->_excessFlow[nodeU] - minimumFlow;
		this->_excessFlow[nodeV] = this->_excessFlow[nodeV] + minimumFlow;
	}

	// relabels height of vertex nodeU when there are outgoing non-saturated edges available
	void Graph::relabel(int nodeU)
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

	int Graph::findMaximumFlowRelabelToFront()
	{
		this->_residualGraph = this->_adjMatrix;

		// initialize pre-flow
		this->initializePreflow();

		// make the list L = G.V - {source, sink}
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			if (i != this->_source && i != this->_sink)
			{
				this->_nodeList.push_back(i);
			}
		}

		// set current vertex = L.head
		list<int>::iterator nodeUiterator = this->_nodeList.begin();

		// iterate over all of the elements in the list L
		while (nodeUiterator != this->_nodeList.end())
		{
			// get the height of current vertex
			int oldHeight = this->_height[*nodeUiterator];

			// discharge the excess flow of current vertex
			this->discharge(*nodeUiterator);

			// check if the height of current vertex increases which means the current vertex got relabeled
			if (this->_height[*nodeUiterator] > oldHeight)
			{
				// then move current vertex to the front of the list L
				this->_nodeList.splice(this->_nodeList.begin(), this->_nodeList, nodeUiterator);
			}

			// go to the next vertex of current vertex in L
			nodeUiterator++;
		}

		// return the excess flow in the sink vertex which is actually the maximum flow along the given flow network
		return this->_excessFlow[this->_sink];
	}
}