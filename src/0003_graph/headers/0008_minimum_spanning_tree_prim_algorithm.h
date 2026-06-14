# pragma once

#include <map>
#include <vector>
#include <set>
using namespace std;

namespace minimum_spanning_tree_prim_algorithm
{
	class Node
	{
	public:
		int data;
		Node* parent;
		int key;
		bool isInOperationalSet;
		Node(int data);
	};

	class CompareNodeKey
	{
	public:
		bool operator()(const Node* nodeU, const Node* nodeV) const
		{
			return nodeU->key < nodeV->key;
		}
	};

	class Graph
	{
	private:
		map<Node*, vector<pair<Node*, int>>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<pair<pair<int, int>, int>> _minimumSpanningTree;
		multiset<Node*, CompareNodeKey> _operationalSet;
		Node* _makeOrFindNode(int data);
	public:
		void pushUndirectedEdge(int valueU, int valueV, int weight);
		void findMinimumSpanningTreePrimAlgorithm();
		vector<pair<pair<int, int>, int>> getMinimumSpanningTree();
	};
}