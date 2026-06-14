#include "0014_all_pairs_shortest_paths_johnson.h"
#include <climits>
using namespace std;

namespace dsa::all_pairs_shortest_paths_johnson
{
	Node::Node(int data)
	{
		this->data = data;
		this->distance = INT_MAX;
		this->parent = nullptr;
		this->potentialWeight = 0;
	}

	Edge::Edge(Node* nodeU, Node* nodeV, int weight)
	{
		this->nodeU = nodeU;
		this->nodeV = nodeV;
		this->weight = weight;
	}

	// Graph private member methods
	Node* Graph::_makeOrFindNode(int data)
	{
		Node* node = nullptr;
		if (this->_nodeMap.find(data) == this->_nodeMap.end())
		{
			node = new Node(data);
			this->_nodeMap[data] = node;
		}
		else
		{
			node = this->_nodeMap[data];
		}
		return node;
	}

	void Graph::_pushAugmentedDirectedEdges(Node* sourceNode, Node* nodeV, int weight)
	{
		this->_augmentedAdjlist[sourceNode].push_back(nodeV);
		this->_augmentedEdgeList.push_back(new Edge(sourceNode, nodeV, weight));
	}

	void Graph::_initializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
			iterator.second->parent = nullptr;
		}
		sourceNode->distance = 0;
	}

	void Graph::_relaxBellmanFord(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
		}
	}

	bool Graph::_bellmanFord(Node* source)
	{
		this->_initializeSingleSource(source);

		for (int i = 0; i < this->_nodeMap.size() - 1; i++)
		{
			for (auto& edge : this->_augmentedEdgeList)
			{
				this->_relaxBellmanFord(edge);
			}
		}

		for (auto& edge : this->_augmentedEdgeList)
		{
			if (edge->nodeV->distance > (edge->nodeU->distance + edge->weight))
			{
				return false;
			}
		}
		return true;
	}

	void Graph::_relaxDijkstra(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			this->_operationalSet.erase(edge->nodeV);
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
			this->_operationalSet.insert(edge->nodeV);
		}
	}

	void Graph::_dijkstra(Node* source)
	{
		this->_initializeSingleSource(source);

		for (auto& node : this->_nodeMap)
		{
			this->_operationalSet.insert(node.second);
		}

		while (!this->_operationalSet.empty())
		{
			Node* nodeU = *(this->_operationalSet.begin());
			this->_operationalSet.erase(nodeU);

			for (auto& edge : this->_edgeMap[nodeU])
			{
				this->_relaxDijkstra(edge);
			}
		}
	}

	void Graph::_getShortestPath(int source, int destination, vector<int>& path)
	{
		if (this->_predecessorMatrix[source - 1][destination - 1] != source)
		{
			int predecessor = this->_predecessorMatrix[source - 1][destination - 1];
			this->_getShortestPath(source, predecessor, path);
			path.push_back(predecessor);
		}
	}

	// Graph public member methods
	void Graph::pushDirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->_makeOrFindNode(dataU);
		Node* nodeV = this->_makeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		Edge* edge = new Edge(nodeU, nodeV, weight);
		this->_edgeMap[nodeU].push_back(edge);
		this->_edgeList.push_back(edge);
	}

	bool Graph::findAllPairsShortestPathsJohnsonAlgorithm()
	{
		// creating the graph G'
		this->_augmentedAdjlist = this->_adjlist;
		this->_augmentedEdgeList = this->_edgeList;

		// source Node s
		Node* source = new Node(0);
		this->_nodeMap[0] = source;

		// creating all the augmented edges in G'.E = G.E U {(s, v) : v in G.V
		for (auto& node : this->_nodeMap)
		{
			if (node.second != source)
			{
				this->_pushAugmentedDirectedEdges(source, node.second, 0);
			}
		}

		if (this->_bellmanFord(source) == false)
		{
			return false;
		}
		else
		{
			this->_nodeMap.erase(0);
			for (auto& node : this->_nodeMap)
			{
				node.second->potentialWeight = node.second->distance;
			}

			for (auto& edge : this->_edgeList)
			{
				edge->weight = edge->weight + edge->nodeU->potentialWeight - edge->nodeV->potentialWeight;
			}

			this->_noOfVertices = (int)this->_nodeMap.size();
			this->_shortestPathMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, -1));
			this->_predecessorMatrix = vector<vector<int>>(this->_noOfVertices, vector<int>(this->_noOfVertices, -1));
			for (auto& iteratorU : this->_nodeMap)
			{
				Node* nodeU = iteratorU.second;
				this->_dijkstra(nodeU);
				for (auto& iteratorV : this->_nodeMap)
				{
					Node* nodeV = iteratorV.second;
					this->_shortestPathMatrix[nodeU->data - 1][nodeV->data - 1] = nodeV->distance + nodeV->potentialWeight - nodeU->potentialWeight;
					this->_predecessorMatrix[nodeU->data - 1][nodeV->data - 1] = nodeV->parent != nullptr ? nodeV->parent->data : -1;
				}
			}
			return true;
		}
	}

	vector<vector<int>> Graph::getAllPairsShortestPathsDistanceMatrix()
	{
		return this->_shortestPathMatrix;
	}

	vector<vector<int>> Graph::getAllPairsShortestPathsPathMatrix()
	{
		vector<vector<int>> result;
		for (int i = 0; i < this->_noOfVertices; i++)
		{
			for (int j = 0; j < this->_noOfVertices; j++)
			{
				if (i != j)
				{
					vector<int> path = {};
					path.push_back(i + 1);
					this->_getShortestPath(i + 1, j + 1, path);
					path.push_back(j + 1);
					result.push_back(path);
				}
			}
		}
		return result;
	}
}