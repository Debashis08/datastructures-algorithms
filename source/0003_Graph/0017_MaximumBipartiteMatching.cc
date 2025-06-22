#include "../include/0003_Graph/0017_MaximumBipartiteMatching.h"
#include<climits>
#include<queue>
using namespace std;

namespace MaximumBipartiteMatching
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

	// This method is used to color the vertices of the graph to determine if the given graph is bipartite or not
	void Graph::ColorGraph()
	{
		// Color of all the vertices are initialised to WHITE
		fill(this->_color.begin(), this->_color.end(), WHITE);

		// Queue to hold the vertices
		queue<int> nodeQueue;

		for (int node = 0; node < this->_noOfVertices; node++)
		{
			// Check if the node is already not colored
			if (this->_color[node] == WHITE)
			{
				// The color of the node is set to RED
				this->_color[node] = RED;

				// The node is inserted into the queue
				nodeQueue.push(node);

				// Using BFS method to color all the vertices
				while (!nodeQueue.empty())
				{
					int nodeU = nodeQueue.front();
					nodeQueue.pop();

					// Iterating over G.Adj[nodeU]
					for (int nodeV = 0; nodeV < this->_noOfVertices; nodeV++)
					{
						// As there are no self loops, continue
						if (nodeU == nodeV)
						{
							continue;
						}
						// Check if there is an edge u --> v and nodeV is not colored yet
						else if (this->_residualGraph[nodeU][nodeV] != 0 && this->_color[nodeV] == WHITE)
						{
							// Set the color of nodeV opposite of nodeU
							this->_color[nodeV] = 1 - this->_color[nodeU];
							// Insert the nodeV into the queue
							nodeQueue.push(nodeV);
						}
						// Check if there is an edge u --> v and nodeV is of same color as nodeU
						else if (this->_residualGraph[nodeU][nodeV] != 0 && this->_color[nodeV] == this->_color[nodeU])
						{
							// Set the _isBipartite flag to false and return
							this->_isBipartite = false;
							return;
						}
					}
				}
			}
		}

		// If the above operation completes without returning yet that indicates the graph is bipartite
		// Set the _isBipartite flag to true and return
		this->_isBipartite = true;
		return;
	}

	// This method is used to create the additional edges
	// from the source vertex to the RED colored vertices and
	// from the BLUE colored vertices to the sink vertex
	void Graph::AddAdditionalEdges()
	{
		// Resizing the residual graph to accomodate space for the new edges
		for (auto& edge : this->_residualGraph)
		{
			edge.resize(this->_noOfVertices, 0);
		}

		this->_parent.resize(this->_noOfVertices, -1);
		this->_visited.resize(this->_noOfVertices, false);
		this->_color.resize(this->_noOfVertices, WHITE);
		this->_residualGraph.resize(this->_noOfVertices, vector<int>(this->_noOfVertices, 0));

		// Creating the additional edges
		for (int node = 0; node < this->_source; node++)
		{
			// From source vertex --> RED colored vertices
			if (this->_color[node] == RED)
			{
				this->_residualGraph[this->_source][node] = 1;
			}

			// From BLUE colored vertices --> sink vertex
			else if (this->_color[node] == BLUE)
			{
				this->_residualGraph[node][this->_sink] = 1;
			}
		}
	}

	// Implementation of BreadthFirstSearch for EdmondsKarp algorithm to find the path from source to sink
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
		this->_maximumFlow = 0;
		this->_flagParallelEdges = false;
		this->_adjMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, 0));
		this->_parent = vector<int>(this->_noOfVertices, -1);
		this->_visited = vector<bool>(this->_noOfVertices, false);
		this->_color = vector<int>(this->_noOfVertices, WHITE);
	}

	void Graph::PushDirectedEdge(int valueU, int valueV)
	{
		this->_adjMatrix[valueU][valueV] = 1;
	}

	int Graph::FindMaximumBipartiteMatching()
	{
		// Resolving all the parallel edges if present
		this->ResolveAntiParallelEdges();
		this->_residualGraph = this->_adjMatrix;

		this->ColorGraph();

		this->_source = this->_noOfVertices;
		this->_noOfVertices++;
		this->_sink = this->_noOfVertices;
		this->_noOfVertices++;

		this->AddAdditionalEdges();

		// While there exists a path p from source to sink in the residual network G'
		while (this->BreadthFirstSearch())
		{
			int augmentedPathFlow = 1;

			// No need to find the minimum amount of augmentedPathFlow as like standard EdmondsKarp algorithm
			// as here capacity of each edges is 1
			for (int nodeV = this->_sink; nodeV != this->_source; nodeV = this->_parent[nodeV])
			{
				int nodeU = this->_parent[nodeV];
				this->_residualGraph[nodeU][nodeV] -= augmentedPathFlow;
				this->_residualGraph[nodeV][nodeU] += augmentedPathFlow;
			}
			this->_maximumFlow += augmentedPathFlow;
		}

		return this->_maximumFlow;
	}

	// This method is used for finding the matchings
	vector<vector<int>> Graph::GetMatchings()
	{
		for (int nodeU = 0; nodeU < this->_adjMatrix.size(); nodeU++)
		{
			for (int nodeV = 0; nodeV < this->_adjMatrix.size(); nodeV++)
			{
				// Check if the nodeU and nodeV are not source or sink
				// and there is a flow of 1 unit from nodeU --> nodeV
				// which means nodeU --> nodeV is being used for the maximum flow (maximum matching)
				if ((nodeU != this->_source || nodeU != this->_sink || nodeV != this->_source || nodeV != this->_sink) 
					&& 
					(this->_adjMatrix[nodeU][nodeV] - this->_residualGraph[nodeU][nodeV]) == 1)
				{
					this->_matchings.push_back({ nodeU, nodeV });
				}
			}
		}

		return this->_matchings;
	}
}