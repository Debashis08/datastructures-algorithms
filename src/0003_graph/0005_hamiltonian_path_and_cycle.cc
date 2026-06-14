#include "0005_hamiltonian_path_and_cycle.h"

using namespace std;
namespace dsa::hamiltonian_path_and_cycle
{
	Node::Node(int value)
	{
		this->data = value;
		this->isVisited = false;
	}

	// Graph private member methods
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

	bool Graph::_isSafe(Node* nodeU, Node* nodeV)
	{
		if (this->_adjlist[nodeU].find(nodeV) == this->_adjlist[nodeU].end())
		{
			return false;
		}
		if (nodeV->isVisited == true)
		{
			return false;
		}
		return true;
	}

	bool Graph::_hamiltonianCycleAndPathUtil(Node* nodeU)
	{
		if (this->_visitedNodeCount == this->_nodeMap.size())
		{
			if (this->_adjlist[nodeU].find(this->_startingNode) != this->_adjlist[nodeU].end())
			{
				this->_isHamiltonianCyclePresent = true;
				this->_isHamiltonianPathPresent = true;
				return true;
			}
			this->_isHamiltonianPathPresent = true;
			return false;
		}
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (this->_isSafe(nodeU, nodeV))
			{
				this->_hamiltonianPath.push_back(nodeV->data);
				nodeV->isVisited = true;
				this->_visitedNodeCount++;
				if (this->_hamiltonianCycleAndPathUtil(nodeV))
				{
					return true;
				}
				this->_visitedNodeCount--;
				nodeV->isVisited = false;
				this->_hamiltonianPath.pop_back();
			}
		}
		return false;
	}

	// Graph public member methods
	void Graph::pushUndirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->_makeOrFindNode(valueU);
		Node* nodeV = this->_makeOrFindNode(valueV);

		this->_adjlist[nodeU].insert(nodeV);
		this->_adjlist[nodeV].insert(nodeU);
	}

	void Graph::pushSingleNode(int valueU)
	{
		this->_makeOrFindNode(valueU);
	}

	void Graph::findHamiltonianCycleAndPath()
	{
		this->_isHamiltonianCyclePresent = false;
		this->_isHamiltonianPathPresent = false;
		this->_hamiltonianPath = {};
		this->_startingNode = this->_nodeMap[0];
		this->_hamiltonianPath.push_back(this->_startingNode->data);
		this->_startingNode->isVisited = true;
		this->_visitedNodeCount = 1;
		this->_hamiltonianCycleAndPathUtil(this->_startingNode);
	}

	bool Graph::isHamiltonianCyclePresent()
	{
		return this->_isHamiltonianCyclePresent;
	}

	bool Graph::isHamiltonianPathPresent()
	{
		return this->_isHamiltonianPathPresent;
	}

	vector<int> Graph::getHamiltonianPath()
	{
		return this->_hamiltonianPath;
	}
}