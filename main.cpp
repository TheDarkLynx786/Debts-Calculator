#include <iostream>
#include "Node.h"
#include "Graph.h"
#include <vector>

using namespace std;

int main() {
    //Nodes
    Node* node1 = new Node("A", 1);
    Node* node2 = new Node("B", 2);
    Node* node3 = new Node("C", 3);
    Node* node4 = new Node("D", 4);
    Node* node5 = new Node("E", 5);
    Node* node6 = new Node("F", 6);
    Node* node7 = new Node("G", 2);

    //Graph
    Graph graph;
    graph.add_node(node1);
    graph.add_node(node2);
    graph.add_node(node3);
    graph.add_node(node4);
    graph.add_node(node5);
    graph.add_node(node6);
    graph.add_node(node7);

    graph.add_edge(node1, node2, 5);
    graph.add_edge(node1, node3, 10);
    graph.add_edge(node2, node4, 15);
    graph.add_edge(node3, node4, 20);
    graph.add_edge(node3, node5, 25);
    graph.add_edge(node4, node6, 15);
    graph.add_edge(node6, node7, 20);

    //Display Nodes
    graph.print_nodes();
    
    //Display Edges
    graph.print_edges();

    vector<Node*> dfs = graph.tarjan();

    for(Node* node : dfs) {
        cout << node->get_name() << " ";
    }

    // Clean up dynamically allocated memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;


    return 0;
}