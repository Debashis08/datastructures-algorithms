#pragma once

#include<map>
#include<vector>
using namespace std;

namespace MaximumFlowEdmondsKarp
{
	class Graph
	{
	private:
		int _noOfVertices;
		int _source;
		int _sink;
		int _maximumFlow;
		bool _flagParallelEdges;
		vector<vector<int>> _adjMatrix;
		vector<vector<int>> _residualGraph;
		vector<int> _parent;
		vector<bool> _visited;
		void ResolveAntiParallelEdges();
		bool BreadthFirstSearch();
	public:
		void CreateGraph(int noOfVertices);
		void PushDirectedEdge(int valueU, int valueV, int capacity);
		int FindMaximumFlowEdmondsKarp();
	};
}