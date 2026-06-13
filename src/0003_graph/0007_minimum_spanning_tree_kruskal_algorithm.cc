#include "0007_minimum_spanning_tree_kruskal_algorithm.h"
#include <climits>
#include <algorithm>
using namespace std;

namespace minimum_spanning_tree_kruskal_algorithm
{
	Node::Node(int data)
	{
		this->data = data;
		this->parent = nullptr;
		this->rank = INT_MAX;
	}

	Edge::Edge(Node* nodeU, Node* nodeV, int weight)
	{
		this->nodeU = nodeU;
		this->nodeV = nodeV;
		this->weight = weight;
	}

	// Graph private member methods
	Node* Graph::makeOrFindNode(int data)
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

	void Graph::makeSet(Node* node)
	{
		node->parent = node;
		node->rank = 0;
	}

	void Graph::unionSet(Node* nodeU, Node* nodeV)
	{
		this->link(this->findSet(nodeU), this->findSet(nodeV));
	}

	void Graph::link(Node* nodeU, Node* nodeV)
	{
		if (nodeV->rank > nodeU->rank)
		{
			nodeU->parent = nodeV;
		}
		else
		{
			nodeV->parent = nodeU;
			if (nodeU->rank == nodeV->rank)
			{
				nodeU->rank += 1;
			}
		}
	}

	Node* Graph::findSet(Node* node)
	{
		if (node != node->parent)
		{
			node->parent = this->findSet(node->parent);
		}
		return node->parent;
	}

	// Graph public member methods
	void Graph::pushUndirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->makeOrFindNode(dataU);
		Node* nodeV = this->makeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_adjlist[nodeV].push_back(nodeU);
		this->_edgeList.push_back(new Edge(nodeU, nodeV, weight));
	}

	void Graph::findMinimumSpanningTreeKruskalAlgorithm()
	{
		for (auto& iterator : this->_nodeMap)
		{
			this->makeSet(iterator.second);
		}
		
		sort(this->_edgeList.begin(), this->_edgeList.end(), [](Edge* edgeX, Edge* edgeY) { return edgeX->weight < edgeY->weight; });

		for (auto& edge : this->_edgeList)
		{
			if (this->findSet(edge->nodeU) != this->findSet(edge->nodeV))
			{
				this->unionSet(edge->nodeU, edge->nodeV);
				this->_minimumSpanningTree.push_back({ {edge->nodeU->data, edge->nodeV->data}, edge->weight });
			}
		}
	}

	vector<pair<pair<int, int>, int>> Graph::getMinimumSpanningTree()
	{
		return this->_minimumSpanningTree;
	}
}