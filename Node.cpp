#include "Node.h"
#include <iostream>


using namespace std;


// Get Node Number
int Node::get_num() const {
    return num;
}

// Get Node Name
string Node::get_name() const {
    return this->name;
}

// Get Visited
bool Node::is_visited() const {
    return this->visited;
}

// Set visited status
void Node::set_visited() {
    this->visited = true;
}

// Add to adjacency list
void Node::add_neighbor(Node* neighbor) {
    adjacency_list.push_back(neighbor);
}

// Get adjacency list
vector<Node*> Node::get_adjacency_list() {
    return adjacency_list;
}