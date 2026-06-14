#pragma once

#include <map>
#include <vector>
#include <list>
using namespace std;

namespace dsa::eulerian_path_and_circuit
{
	class Node
	{
	public:
		int data;
		int degree;
		int inDegree;
		int outDegree;
		bool visited;
		Node(int value);
	};

	class Graph
	{
	private:
		bool _isEulerianPathPresent;
		bool _isEulerianCircuitPresent;
		map<Node*, list<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<int> _eulerianPath;
		Node* _makeOrFindNode(int value);
		void _depthFirstSearch(Node* node);
		bool _isConnected();
		void _eulerianPathHierholzerAlgorithm(Node* startingNode);

	public:
		void pushUndirectedEdge(int valueU, int valueV);
		void pushDirectedEdge(int valueU, int valueV);
		void pushSingleNode(int valueU);
		void findEulerianPathAndCircuit();
		bool isEulerianPathPresent();
		bool isEulerianCircuitPresent();
		vector<int> undirectedGraphGetEulerianPath();
	};
}