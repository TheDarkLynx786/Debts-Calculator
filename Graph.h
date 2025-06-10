#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <utility>
#include <vector>
#include <stack>
#include "Node.h"

using namespace std;

class Graph {
    private:
        vector<Node*> nodes;
        vector<pair<pair<Node*, Node*>, int>> edges; // Edges are weighted

    public:
        // Constructor
        Graph() {}

        // Add a node to the graph
        void add_node(Node* node);

        vector<Node*> get_nodes();

        void add_edge(Node* from, Node* to, int weight);

        /*vector<Node*> dfs();*/

        void dfs(vector<Node*> unvisited, vector<Node*>& visited, stack<Node*> exploration_stack);

        vector<Node*> tarjan();

        void print_nodes() const;

        void print_edges() const;
};

#endif