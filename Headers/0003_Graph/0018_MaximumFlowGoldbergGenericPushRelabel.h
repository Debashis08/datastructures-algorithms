#pragma once

#include<map>
#include<vector>
#include<queue>
using namespace std;

namespace MaximumFlowGoldbergGenericPushRelabel
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
		void InitializePreflow();
		bool CheckOverFlow();
		bool Push(int nodeU);
		void Relabel(int nodeU);
	public:
		void CreateGraph(int noOfVertices);
		void PushDirectedEdge(int valueU, int valueV, int capacity);
		int FindMaximumFlowGoldbergGenericPushRelabel();
	};
}