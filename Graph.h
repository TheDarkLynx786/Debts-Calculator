#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <utility>
#include <vector>
#include "Node.h"

using namespace std;

class Graph {
    private:
        vector<Node*> nodes;
        vector<pair<pair<Node*, Node*>, int>> edges;

    public:
        // Constructor
        Graph() {}

        // Add a node to the graph
        void add_node(Node* node);

        void add_edge(Node* from, Node* to, int weight);

        void print_nodes() const;

        void print_edges() const;
};

#endif