#include "../Headers/0003_Graph/0010_DirectedAcyclicGraphShortestPath.h"
#include<climits>
using namespace std;

namespace DirectedAcyclicGraphShortestPath
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

	void Graph::DepthFirstSearch(Node* nodeU)
	{
		nodeU->color = GRAY;
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->color == WHITE)
			{
				this->DepthFirstSearch(nodeV);
			}
		}
		nodeU->color = BLACK;
		this->_topologicalSortedNodeList.push_front(nodeU);
	}

	void Graph::TopologicalSort()
	{
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->color == WHITE)
			{
				this->DepthFirstSearch(iterator.second);
			}
		}
	}

	void Graph::InitializeSingleSource(Node* sourceNode)
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
		this->_edgeMap[nodeU].push_back(new Edge(nodeU, nodeV, weight));
	}

	void Graph::FindDAGShortestPath(int data)
	{
		this->TopologicalSort();
		Node* source = this->_nodeMap[data];
		this->InitializeSingleSource(source);
		for (auto& node : this->_topologicalSortedNodeList)
		{
			for (auto& edge : this->_edgeMap[node])
			{
				this->Relax(edge);
			}
		}
	}

	vector<int> Graph::GetDAGShortestPath(int data)
	{
		vector<int> path = {};
		Node* node = this->_nodeMap[data];
		this->GetShortestPath(node, path);
		reverse(path.begin(), path.end());
		return path;
	}
}