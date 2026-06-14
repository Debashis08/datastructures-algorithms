#pragma once

#include <map>
#include <string>
#include <vector>
using namespace std;

namespace dsa::difference_constraints_shortest_paths
{
	class Node
	{
	public:
		string data;
		int distance;
		Node(string data);
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
		map<string, Node*> _nodeMap;
		vector<Edge*> _edgeList;
		Node* _makeOrFindNode(string data);
		void _pushDirectedEdge(string valueU, string valueV, int weight);
		void _initializeSingleSource(Node* sourceNode);
		void _relax(Edge* edge);

	public:
		void pushAllDirectedEdges(vector<vector<int>> vectorA, vector<string> vectorX, vector<int> vectorB);
		bool findDifferenceConstraintsSolutionBellmanFord();
		vector<pair<string, int>> getDifferenceConstrtaintsSolution();
	};
}