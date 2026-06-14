#pragma once

#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

namespace dsa::topological_sort
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
        Node* _makeOrFindNode(int value);
        void _depthFirstSearch(Node* dFSNode);
    public:
        void pushDirectedEdge(int valueU, int valueV);
        void pushSingleNode(int valueU);
        void topologicalSort();
        void kahnTopologicalSort();
        vector<pair<int, pair<int, int>>> showTopologicalSortResult();
    };
}