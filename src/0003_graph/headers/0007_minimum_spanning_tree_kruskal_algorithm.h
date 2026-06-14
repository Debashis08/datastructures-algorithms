#pragma once

#include <map>
#include <vector>
#include <list>
using namespace std;

namespace minimum_spanning_tree_kruskal_algorithm
{
	class Node
	{
	public:
		int data;
		Node* parent;
		int rank;
		Node(int data);
	};

	class Edge
	{
	public:
		Node* nodeU;
		Node* nodeV;
		int weight;
		Edge(Node* nodeU, Node* nodeV, int weight);
	};

	class Graph
	{
	private:
		map<Node*, vector<Node*>> _adjlist;
		map<int, Node*> _nodeMap;
		vector<Edge*> _edgeList;
		vector<pair<pair<int, int>, int>> _minimumSpanningTree;
		Node* _makeOrFindNode(int data);
		void _makeSet(Node* node);
		void _unionSet(Node* nodeU, Node* nodeV);
		void _linkSet(Node* nodeU, Node* nodeV);
		Node* _findSet(Node* node);

	public:
		void pushUndirectedEdge(int valueU, int valueV, int weight);
		void findMinimumSpanningTreeKruskalAlgorithm();
		vector<pair<pair<int, int>, int>> getMinimumSpanningTree();
	};
}