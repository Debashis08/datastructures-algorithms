#include "0004_strongly_connected_components.h"
#include <vector>
#include <utility>
#include <climits>
using namespace std;

namespace strongly_connected_components
{
	Node::Node(int value)
	{
		this->data = value;
		this->discoveryTime = INT_MAX;
		this->finishingTime = INT_MAX;
		this->color = WHITE;
		this->parent = nullptr;
	}

	Node* Graph::_makeOrFindNode(int value)
	{
		Node* node = nullptr;
		if (this->_nodeMap.find(value) == this->_nodeMap.end())
		{
			node = new Node(value);
			this->_nodeMap[value] = node;
		}
		else
		{
			node = this->_nodeMap[value];
		}
		return node;
	}

	void Graph::_depthFirstSearchOnGraphG(Node* nodeU)
	{
		this->_time++;
		nodeU->discoveryTime = this->_time;
		nodeU->color = GRAY;
		for (auto nodeV : this->_adjlistG[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->_depthFirstSearchOnGraphG(nodeV);
			}
		}
		nodeU->color = BLACK;
		this->_time++;
		nodeU->finishingTime = this->_time;
		this->_nodesFinishingTimeOrder.push_front(nodeU);
	}

	void Graph::_depthFirstSearchOnGraphT(Node* nodeU, vector<int>& connectedComponents)
	{
		nodeU->color = GRAY;
		connectedComponents.push_back(nodeU->data);
		for (auto nodeV : this->_adjlistT[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->_depthFirstSearchOnGraphT(nodeV, connectedComponents);
			}
		}
		nodeU->color = BLACK;
	}

	void Graph::pushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->_makeOrFindNode(valueU);
		Node* nodeV = this->_makeOrFindNode(valueV);

		// creating the actual graph.
		this->_adjlistG[nodeU].push_back(nodeV);

		// creating the transpose of the actual graph.
		this->_adjlistT[nodeV].push_back(nodeU);
	}

	void Graph::pushSingleNode(int valueU)
	{
		this->_makeOrFindNode(valueU);
	}

	void Graph::dFSOnGraphG()
	{
		this->_time = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->_depthFirstSearchOnGraphG(iterator.second);
			}
		}
	}

	void Graph::dFSOnGraphT()
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->color = WHITE;
			iterator.second->parent = nullptr;
		}

		for (auto& iterator : this->_nodesFinishingTimeOrder)
		{
			if (iterator->color == WHITE)
			{
				vector<int> connectedComponents;
				this->_depthFirstSearchOnGraphT(iterator, connectedComponents);
				this->_allConnectedComponents.push_back(connectedComponents);
			}
		}
	}

	vector<vector<int>> Graph::findAllStronglyConnectedComponents()
	{
		this->dFSOnGraphG();
		this->dFSOnGraphT();
		return this->_allConnectedComponents;
	}
}