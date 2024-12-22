#include "../Headers/0003_Graph/0008_MinimumSpanningTreePrimAlgorithm.h"
#include<climits>
using namespace std;


namespace MinimumSpanningTreePrimAlgorithm
{
	Node::Node(int data)
	{
		this->data = data;
		this->parent = nullptr;
		this->key = INT_MAX;
		this->isInOperationalSet = false;
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

	// Graph Public Member Methods
	void Graph::PushUndirectedEdge(int dataU, int dataV, int weight)
	{
		Node* nodeU = this->MakeOrFindNode(dataU);
		Node* nodeV = this->MakeOrFindNode(dataV);

		this->_adjlist[nodeU].push_back({nodeV, weight});
		this->_adjlist[nodeV].push_back({nodeU, weight});
	}

	void Graph::FindMinimumSpanningTreePrimAlgorithm()
	{

	}
}