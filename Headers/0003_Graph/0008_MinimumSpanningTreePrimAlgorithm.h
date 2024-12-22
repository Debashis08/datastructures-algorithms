# pragma once

#include<map>
#include<vector>
#include<set>
using namespace std;

namespace MinimumSpanningTreePrimAlgorithm
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
		set<Node*, CompareNodeKey> _operationalSet;
		Node* MakeOrFindNode(int data);
	public:
		void PushUndirectedEdge(int valueU, int valueV, int weight);
		void FindMinimumSpanningTreePrimAlgorithm();
		vector<pair<pair<int, int>, int>> GetMinimumSpanningTree();
	};
}