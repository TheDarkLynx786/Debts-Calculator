#include <iostream>
#include "Node.h"
#include "Graph.h"
#include <vector>

using namespace std;

int main() {
    //Nodes
    Node* node1 = new Node("Node1", 1);
    Node* node2 = new Node("Node2", 2);
    Node* node3 = new Node("Node3", 3);
    Node* node4 = new Node("Node4", 4);

    //Graph
    Graph graph;
    graph.add_node(node1);
    graph.add_node(node2);
    graph.add_node(node3);
    graph.add_node(node4);
    graph.add_edge(node1, node2, 5);
    graph.add_edge(node2, node3, 10);
    graph.add_edge(node3, node4, 15);
    graph.add_edge(node4, node1, 20);
    graph.add_edge(node1, node3, 25);

    //Display Nodes
    graph.print_nodes();
    
    //Display Edges
    graph.print_edges();

    // Clean up dynamically allocated memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;


    return 0;
}