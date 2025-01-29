#include "../Headers/0003_Graph/0003_TopologicalSort.h"
#include<vector>
#include<queue>
#include<utility>
#include<climits>
#include<stdexcept>
using namespace std;

namespace TopologicalSort
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

	Node* Graph::MakeOrFindNode(int value)
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

	void Graph::DepthFirstSearch(Node* nodeU)
	{
		this->time++;
		nodeU->discoveryTime = this->time;
		nodeU->color = GRAY;
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				nodeV->parent = nodeU;
				this->DepthFirstSearch(nodeV);
			}
			else if (nodeV->color == GRAY)
			{
				this->hasCycle = true;
				return;
			}
		}
		nodeU->color = BLACK;
		this->time++;
		nodeU->finishingTime = time;
		this->_topologicalSortedNodeList.push_front(nodeU);
	}

	void Graph::PushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
		Node* nodeV = this->MakeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		nodeV->inDegree++;
	}

	void Graph::PushSingleNode(int valueU)
	{
		Node* nodeU = this->MakeOrFindNode(valueU);
	}

	void Graph::TopologicalSort()
	{
		this->time = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->DepthFirstSearch(iterator.second);
				if (this->hasCycle == true)
				{
					break;
				}
			}
		}
	}

	void Graph::KahnTopologicalSort()
	{
		// Step-1 Compute in-degree of each vertices
		// This is already done while creating the graph
		this->time = 0;
		queue<Node*> nodeQueue;

		// Step-2 Enqueue vertices with in-degree 0
		for (auto& node : this->_nodeMap)
		{
			if (node.second->inDegree == 0)
			{
				this->time++;
				node.second->discoveryTime = time;
				nodeQueue.push(node.second);
			}
		}

		// Step-3 Process vertices in queue
		while (!nodeQueue.empty())
		{
			Node* node = nodeQueue.front();
			nodeQueue.pop();
			this->time++;
			node->finishingTime = time;
			this->_topologicalSortedNodeList.push_back(node);
			
		// Step-4 Process all the neighbours of current node based on in-degree
			for (auto& neighbour : this->_adjlist[node])
			{
				neighbour->inDegree--;
				if (neighbour->inDegree == 0)
				{
					this->time++;
					neighbour->discoveryTime = time;
					nodeQueue.push(neighbour);
				}
			}
		}

		// Step-5 Check if a cycle exists
		if (this->_topologicalSortedNodeList.size() != this->_nodeMap.size())
		{
			this->hasCycle = true;
		}
	}

	vector<pair<int, pair<int, int>>> Graph::ShowTopologicalSortResult()
	{
		if (this->hasCycle == true)
		{
			throw runtime_error("Cycle Detected");
		}
		vector<pair<int, pair<int, int>>> result;
		for (auto& node : this->_topologicalSortedNodeList)
		{
			result.push_back(make_pair(node->data, make_pair(node->discoveryTime, node->finishingTime)));
		}
		return result;
	}
}