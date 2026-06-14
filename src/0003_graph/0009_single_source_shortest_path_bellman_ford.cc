#include "0009_single_source_shortest_path_bellman_ford.h"
#include <climits>
#include <algorithm>
using namespace std;

namespace dsa::single_source_shortest_path_bellman_ford
{
	Node::Node(int data)
	{
		this->data = data;
		this->distance = INT_MAX;
		this->parent = nullptr;
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

	void Graph :: _initializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
			iterator.second->parent = nullptr;
		}
		sourceNode->distance = 0;
	}

	void Graph::_relax(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
		}
	}

	void Graph::_getShortestPath(Node* node, vector<int>& path)
	{
		path.push_back(node->data);
		if (node->parent != nullptr)
		{
			this->_getShortestPath(node->parent, path);
		}
	}

	// Graph public member methods
	void Graph::pushDirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->_makeOrFindNode(dataU);
		Node* nodeV = this->_makeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_edgeList.push_back(new Edge(nodeU, nodeV, weight));
	}

	bool Graph::findSingleSourceShortestPathBellmanFord(int data)
	{
		Node* source = this->_nodeMap[data];

		this->_initializeSingleSource(source);

		for (int i = 0; i < this->_nodeMap.size() - 1; i++)
		{
			for (auto& edge : this->_edgeList)
			{
				this->_relax(edge);
			}
		}

		for (auto& edge : this->_edgeList)
		{
			if (edge->nodeV->distance > (edge->nodeU->distance + edge->weight))
			{
				return false;
			}
		}
		return true;
	}

	vector<int> Graph::getShortestPathBellmanFord(int data)
	{
		vector<int> path = {};
		Node* node = this->_nodeMap[data];
		this->_getShortestPath(node, path);
		reverse(path.begin(), path.end());
		return path;
	}
}