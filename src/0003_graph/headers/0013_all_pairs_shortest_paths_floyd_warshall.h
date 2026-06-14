#pragma once

#include <vector>
using namespace std;

namespace all_pairs_shortest_paths_floyd_warshall
{
	class Graph
	{
	private:
		int  _noOfVertices;
		vector<vector<int>> _adjMatrix;
		vector<vector<int>> _shortestPathMatrixFloydWarshall;
		vector<vector<int>> _predecessorMatrix;
		void _initializeDistanceAndPredecessors();
		void _getShortestPath(int source, int destination, vector<int>& path);
		
	public:
		void createGraph(int noOfVertices);
		void pushDirectedEdge(int valueU, int valueV, int weight);
		void findAllPairsShortestPathsFloydWarshallSolution();
		vector<vector<int>> getFloydWarshallShortestPath();
	};
}