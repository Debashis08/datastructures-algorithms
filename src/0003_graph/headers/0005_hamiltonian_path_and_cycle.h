#pragma once

#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

namespace hamiltonian_path_and_cycle
{
	class Node
	{
	public:
		int data;
		bool isVisited;
		Node(int value);
	};

	class Graph
	{
	private:
		bool _isHamiltonianCyclePresent;
		bool _isHamiltonianPathPresent;
		int _visitedNodeCount;
		Node* _startingNode;
		map<Node*, unordered_set<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<int> _hamiltonianPath;
		Node* _makeOrFindNode(int value);
		bool _isSafe(Node* nodeU, Node* nodeV);
		bool _hamiltonianCycleAndPathUtil(Node* node);

	public:
		void pushUndirectedEdge(int valueU, int valueV);
		void pushSingleNode(int valueU);
		void findHamiltonianCycleAndPath();
		bool isHamiltonianCyclePresent();
		bool isHamiltonianPathPresent();
		vector<int> getHamiltonianPath();
	};
}