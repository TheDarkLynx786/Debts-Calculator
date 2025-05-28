#include "Graph.h"
#include <iostream>

using namespace std;

// Add a node to the graph
void Graph::add_node(Node* node) { nodes.push_back(node); }

// Add an edge to the graph
void Graph::add_edge(Node* from, Node* to, int weight) { edges.push_back(make_pair(make_pair(from, to), weight)); }

// Display all nodes and their numbers
void Graph::print_nodes() const {
    cout << "Nodes: \n" << endl;
    for (const auto& node : nodes) {
        cout << node->get_name() << " - Node " << node->get_num() << endl;
    }
    cout << endl;
}

// Display all edges with their weights
void Graph::print_edges() const {
    cout << "Edges: \n" << endl;
    for (const auto& edge : edges) {
        cout << edge.first.first->get_name() 
             << " ---> " << edge.first.second->get_name() 
             << " | Weight: " << edge.second << endl;
    }
    cout << endl;
}