#include "0006_eulerian_path_and_circuit.h"
#include <stack>
#include <algorithm>
using namespace std;

namespace eulerian_path_and_circuit
{
	Node::Node(int value)
	{
		this->data = value;
		this->degree = 0;
		this->inDegree = 0;
		this->outDegree = 0;
		this->visited = false;
	}

	// Graph private member methods
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
		nodeU->visited = true;
		for (auto& nodeV : this->_adjlist[nodeU])
		{
			if (nodeV->visited == false)
			{
				this->depthFirstSearch(nodeV);
			}
		}
	}

	bool Graph::isConnected()
	{
		// step-1 : make the visited property of all nodes as false. it is already done in constructor.

		// step-2 : find a node which do not have 0 degree.
		Node* node = nullptr;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->degree != 0)
			{
				node = iterator.second;
				break;
			}
		}

		// step-3 : if node is null, it means G.E is null, so G is connected, else call DFS to traverse the graph G.
		if (node == nullptr)
		{
			return true;
		}

		this->depthFirstSearch(node);

		// step-4 : checking if all the non-zero degree vertices have been visited or not.
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->visited == false && iterator.second->degree != 0)
			{
				return false;
			}
		}
		return true;
	}

	void Graph::eulerianPathHierholzerAlgorithm(Node* startingNode)
	{
		stack<Node*> currentPath;
		currentPath.push(startingNode);
		while (!currentPath.empty())
		{
			Node* currentNode = currentPath.top();
			if (!this->_adjlist[currentNode].empty())
			{
				Node* nextNode = this->_adjlist[currentNode].front();
				this->_adjlist[currentNode].pop_front();
				this->_adjlist[nextNode].remove(currentNode);
				currentPath.push(nextNode);
			}
			else
			{
				currentPath.pop();
				this->_eulerianPath.push_back(currentNode->data);
			}
		}
	}

	// Graph public member methods
	void Graph::pushUndirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->makeOrFindNode(valueU);
		Node* nodeV = this->makeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		nodeU->degree++;
		this->_adjlist[nodeV].push_back(nodeU);
		nodeV->degree++;
	}

	void Graph::pushDirectedEdge(int valueU, int valueV)
	{
		Node* nodeU = this->makeOrFindNode(valueU);
		Node* nodeV = this->makeOrFindNode(valueV);

		this->_adjlist[nodeU].push_back(nodeV);
		nodeU->outDegree++;
		nodeV->inDegree++;
	}

	void Graph::pushSingleNode(int valueU)
	{
		this->makeOrFindNode(valueU);
	}

	void Graph::findEulerianPathAndCircuit()
	{
		// if the graph is not connected then graph G is not-eulerian.
		if (this->isConnected() == false)
		{
			this->_isEulerianPathPresent = false;
			this->_isEulerianCircuitPresent = false;
			return;
		}

		int oddDegreeVertexCount = 0;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->degree & 1)
			{
				oddDegreeVertexCount++;
			}
		}

		// check-1 :  when no vertex with odd degree is present, then graph G is eulerian.
		if (oddDegreeVertexCount == 0)
		{
			this->_isEulerianPathPresent = true;
			this->_isEulerianCircuitPresent = true;
			return;
		}

		// check-2 : when 2 vertices have odd degree, then graph G is semi-eulerian.
		if (oddDegreeVertexCount == 2)
		{
			this->_isEulerianPathPresent = true;
			this->_isEulerianCircuitPresent = false;
			return;
		}

		// check-3 : when more than 2 vertices have odd degree, then graph G is not eulerian.
		if (oddDegreeVertexCount > 2)
		{
			this->_isEulerianPathPresent = false;
			this->_isEulerianCircuitPresent = false;
			return;
		}
	}

	bool Graph::isEulerianPathPresent()
	{
		return this->_isEulerianPathPresent;
	}

	bool Graph::isEulerianCircuitPresent()
	{
		return this->_isEulerianCircuitPresent;
	}

	vector<int> Graph::undirectedGraphGetEulerianPath()
	{
		// Case-3 : when more than 2 vertices have odd degree, then the graph G is not eulerian.
		// no eulerian path is posible.
		if (this->_isEulerianPathPresent == false)
		{
			return {};
		}

		// now 2 cases remains.
		// Case-2 : when 2 vertices have odd degree. choose any one of them.
		Node* node = nullptr;
		for (auto& iterator : this->_nodeMap)
		{
			if (iterator.second->degree & 1)
			{
				node = iterator.second;
				break;
			}
		}

		// Case-1 : when no vertex with odd degree is present. choose any vertex as starting point.
		if (node == nullptr)
		{
			node = this->_nodeMap[0];
		}
		this->eulerianPathHierholzerAlgorithm(node);
		reverse(this->_eulerianPath.begin(), this->_eulerianPath.end());
		return this->_eulerianPath;
	}
}