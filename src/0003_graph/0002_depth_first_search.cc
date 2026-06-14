#include "0002_depth_first_search.h"
#include <vector>
#include <utility>
#include <climits>
using namespace std;

namespace dsa::depth_first_search
{
	Node::Node(int value)
	{
		this->data = value;
		this->discoveredTime = INT_MAX;
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

	void Graph::_depthFirstSearch(Node* nodeU)
	{
		this->_time++;
		nodeU->discoveredTime = this->_time;
		nodeU->color = GRAY;
		for (auto nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->_depthFirstSearch(nodeV);
			}
		}
		nodeU->color = BLACK;
		this->_time++;
		nodeU->finishingTime = this->_time;
	}

	void Graph::pushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->_makeOrFindNode(valueU);
		Node* nodeV = this->_makeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
	}

	void Graph::dfs()
	{
		this->_time = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->_depthFirstSearch(iterator.second);
			}
		}
	}

	vector<pair<int, pair<int, int>>> Graph::showDFSResult()
	{
		vector<pair<int, pair<int, int>>> result;
		for (auto& node : this->_nodeMap)
		{
			result.push_back(make_pair(node.first, make_pair(node.second->discoveredTime, node.second->finishingTime)));
		}
		return result;
	}
}