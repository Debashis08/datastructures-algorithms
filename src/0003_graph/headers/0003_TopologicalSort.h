#pragma once

#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

namespace TopologicalSort
{
    enum color { WHITE, GRAY, BLACK };

    class Node
    {
    public:
        int data;
        int color;
        int discoveryTime;
        int finishingTime;
        int inDegree;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        int _time;
        bool _hasCycle;
        map<Node*, list<Node*>> _adjlist;
        map<int, Node*> _nodeMap;
        list<Node*> _topologicalSortedNodeList;
        Node* MakeOrFindNode(int value);
        void DepthFirstSearch(Node* DFSNode);
    public:
        void PushDirectedEdge(int valueU, int valueV);
        void PushSingleNode(int valueU);
        void TopologicalSort();
        void KahnTopologicalSort();
        vector<pair<int, pair<int, int>>> ShowTopologicalSortResult();
    };
}