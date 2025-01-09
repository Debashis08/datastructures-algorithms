#include "../Headers/0003_Graph/0009_SingleSourceShortestPathBellmanFord.h"
#include<climits>
#include<algorithm>
using namespace std;

namespace SingleSourceShortestPathBellmanFord
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

	// Graph Private Member Methods
	Node* Graph::MakeOrFindNode(int data)
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

	void Graph :: InitializeSingleSource(Node* sourceNode)
	{
		for (auto& iterator : this->_nodeMap)
		{
			iterator.second->distance = INT_MAX;
			iterator.second->parent = nullptr;
		}
		sourceNode->distance = 0;
	}

	void Graph::Relax(Edge* edge)
	{
		if (edge->nodeU->distance != INT_MAX && (edge->nodeV->distance > (edge->nodeU->distance + edge->weight)))
		{
			edge->nodeV->distance = edge->nodeU->distance + edge->weight;
			edge->nodeV->parent = edge->nodeU;
		}
	}

	void Graph::GetShortestPath(Node* node, vector<int>& path)
	{
		path.push_back(node->data);
		if (node->parent != nullptr)
		{
			this->GetShortestPath(node->parent, path);
		}
	}

	// Graph Public Member Methods
	void Graph::PushDirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back(nodeV);
		this->_edgeList.push_back(new Edge(nodeU, nodeV, weight));
	}

	bool Graph::FindSingleSourceShortestPathBellmanFord(int data)
	{
		Node* source = this->_nodeMap[data];

		this->InitializeSingleSource(source);

		for (int i = 0; i < this->_nodeMap.size() - 1; i++)
		{
			for (auto& edge : this->_edgeList)
			{
				this->Relax(edge);
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

	vector<int> Graph::GetShortestPathBellmanFord(int data)
	{
		vector<int> path = {};
		Node* node = this->_nodeMap[data];
		this->GetShortestPath(node, path);
		reverse(path.begin(), path.end());
		return path;
	}
}