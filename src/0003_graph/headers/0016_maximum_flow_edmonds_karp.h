#pragma once

#include <map>
#include <vector>
using namespace std;

namespace dsa::maximum_flow_edmonds_karp
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
		void _resolveAntiParallelEdges();
		bool _breadthFirstSearch();
	public:
		void createGraph(int noOfVertices);
		void pushDirectedEdge(int valueU, int valueV, int capacity);
		int findMaximumFlowEdmondsKarp();
	};
}