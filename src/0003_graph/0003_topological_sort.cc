#include "0003_topological_sort.h"
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <stdexcept>
using namespace std;

namespace topological_sort
{
	Node::Node(int value)
	{
		this->data = value;
		this->color = WHITE;
		this->discoveryTime = INT_MAX;
		this->finishingTime = INT_MAX;
		this->inDegree = 0;
		this->parent = nullptr;
	}

	Node* Graph::makeOrFindNode(int value)
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

	void Graph::depthFirstSearch(Node* nodeU)
	{
		this->_time++;
		nodeU->discoveryTime = this->_time;
		nodeU->color = GRAY;
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->depthFirstSearch(nodeV);
			}
			else if (nodeV->color == GRAY)
			{
				this->_hasCycle = true;
				return;
			}
		}
		nodeU->color = BLACK;
		this->_time++;
		nodeU->finishingTime = this->_time;
		this->_topologicalSortedNodeList.push_front(nodeU);
	}

	void Graph::pushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->makeOrFindNode(valueU);
		Node* nodeV = this->makeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		nodeV->inDegree++;
	}

	void Graph::pushSingleNode(int valueU)
	{
		this->makeOrFindNode(valueU);
	}

	void Graph::topologicalSort()
	{
		this->_time = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->depthFirstSearch(iterator.second);
				if (this->_hasCycle == true)
				{
					break;
				}
			}
		}
	}

	void Graph::kahnTopologicalSort()
	{
		// step-1 compute in-degree of each vertices
		// this is already done while creating the graph
		this->_time = 0;
		queue<Node*> nodeQueue;

		// step-2 enqueue vertices with in-degree 0
		for (auto& node : this->_nodeMap)
		{
			if (node.second->inDegree == 0)
			{
				this->_time++;
				node.second->discoveryTime = this->_time;
				nodeQueue.push(node.second);
			}
		}

		// step-3 process vertices in queue
		while (!nodeQueue.empty())
		{
			Node* node = nodeQueue.front();
			nodeQueue.pop();
			this->_time++;
			node->finishingTime = this->_time;
			this->_topologicalSortedNodeList.push_back(node);
			
		// step-4 process all the neighbours of current node based on in-degree
			for (auto& neighbour : this->_adjlist[node])
			{
				neighbour->inDegree--;
				if (neighbour->inDegree == 0)
				{
					this->_time++;
					neighbour->discoveryTime = this->_time;
					nodeQueue.push(neighbour);
				}
			}
		}

		// step-5 check if a cycle exists
		if (this->_topologicalSortedNodeList.size() != this->_nodeMap.size())
		{
			this->_hasCycle = true;
		}
	}

	vector<pair<int, pair<int, int>>> Graph::showTopologicalSortResult()
	{
		if (this->_hasCycle == true)
		{
			return {};
		}
		vector<pair<int, pair<int, int>>> result;
		for (auto& node : this->_topologicalSortedNodeList)
		{
			result.push_back(make_pair(node->data, make_pair(node->discoveryTime, node->finishingTime)));
		}
		return result;
	}
}