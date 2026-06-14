#pragma once

#include <vector>
#include <queue>
using namespace std;

namespace dsa::maximum_flow_goldberg_generic_push_relabel
{
	class Graph
	{
	private:
		int _noOfVertices;
		int _source;
		int _sink;
		int _maximumFlow;
		vector<vector<int>> _adjMatrix;
		vector<vector<int>> _residualGraph;
		vector<int> _excessFlow;
		vector<int> _height;
		vector<bool> _visited;
		queue<int> _nodeQueue;
		void _initializePreflow();
		bool _checkOverFlow();
		bool _push(int nodeU);
		void _relabel(int nodeU);
	public:
		void createGraph(int noOfVertices);
		void pushDirectedEdge(int valueU, int valueV, int capacity);
		int findMaximumFlowGoldbergGenericPushRelabel();
	};
}