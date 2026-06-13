#include "0010_directed_acyclic_graph_shortest_path.h"
#include <climits>
#include <algorithm>
using namespace std;

namespace directed_acyclic_graph_shortest_path
{
	Node::Node(int data)
	{
		this->data = data;
		this->color = WHITE;
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

	void Graph::depthFirstSearch(Node* nodeU)
	{
		nodeU->color = GRAY;
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				this->depthFirstSearch(nodeV);
			}
		}
		nodeU->color = BLACK;
		this->_topologicalSortedNodeList.push_front(nodeU);
	}

	void Graph::topologicalSort()
	{
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->depthFirstSearch(iterator.second);
			}
		}
	}

	void Graph::initializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
			iterator.second->parent = nullptr;
		}
		sourceNode->distance = 0;
	}

	void Graph::relax(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
		}
	}

	void Graph::getShortestPath(Node* node, vector<int>& path)
	{
		path.push_back(node->data);
		if (node->parent != nullptr)
		{
			this->getShortestPath(node->parent, path);
		}
	}

	// Graph public member methods
	void Graph::pushDirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->makeOrFindNode(dataU);
		Node* nodeV = this->makeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_edgeMap[nodeU].push_back(new Edge(nodeU, nodeV, weight));
	}

	void Graph::findDAGShortestPath(int data)
	{
		this->topologicalSort();
		Node* source = this->_nodeMap[data];
		this->initializeSingleSource(source);
		for (auto& node : this->_topologicalSortedNodeList)
		{
			for (auto& edge : this->_edgeMap[node])
			{
				this->relax(edge);
			}
		}
	}

	vector<int> Graph::getDAGShortestPath(int data)
	{
		vector<int> path = {};
		Node* node = this->_nodeMap[data];
		this->getShortestPath(node, path);
		reverse(path.begin(), path.end());
		return path;
	}
}