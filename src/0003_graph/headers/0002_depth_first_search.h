#pragma once

#include <list>
#include <map>
#include <string>
#include <vector>
using namespace std;

namespace dsa::depth_first_search
{
    enum color { WHITE, GRAY, BLACK };

    class Node
    {
    public:
        int data;
        int color;
        int discoveredTime;
        int finishingTime;
        Node* parent;
        Node(int value);
    };

    class Graph
    {
    private:
        int _time;
        map<Node*, list<Node*>> _adjlist;
        map<int, Node*> _nodeMap;
        Node* _makeOrFindNode(int value);
        void _depthFirstSearch(Node* Node);
    public:
        void pushDirectedEdge(int valueU, int valueV);
        void dfs();
        vector<pair<int, pair<int, int>>> showDFSResult();
    };
}