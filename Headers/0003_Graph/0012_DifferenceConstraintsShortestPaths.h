#pragma once

#include<map>
#include<string>
#include<vector>
using namespace std;

namespace DifferenceConstraintsShortestPaths
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
		Node* startingNode;
		map<Node*, vector<Node*>> _adjlist;
		map<string, Node*> _nodeMap;
		vector<Edge*> _edgeList;
		Node* MakeOrFindNode(string data);
		void PushDirectedEdge(string valueU, string valueV, int weight);
		void InitializeSingleSource(Node* sourceNode);
		void Relax(Edge* edge);

	public:
		void PushAllDirectedEdges(vector<vector<int>> vectorA, vector<string> vectorX, vector<int> vectorB);
		bool FindDifferenceConstraintsSolutionBellmanFord();
		vector<int> GetDifferenceConstrtaintsSolution();
	};
}