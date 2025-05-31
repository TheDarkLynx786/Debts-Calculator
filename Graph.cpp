#include "Graph.h"
#include <iostream>
#include <stack>
#include <list>

using namespace std;

// Add a node to the graph
void Graph::add_node(Node* node) { nodes.push_back(node); }

// Add an edge to the graph
void Graph::add_edge(Node* from, Node* to, int weight) { 
    edges.push_back(make_pair(make_pair(from, to), weight)); 
    // from --> to
    from->add_neighbor(to); 
}

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

vector<Node*> Graph::tarjan() {
    vector<Node*> unvisited = this->nodes;
    // This vector SHOULD have the correct DFS order of nodes ( if using push_front() )
    vector<Node*> visited = {};
    stack<Node*> stack;

    //vector<int> dfs_num(unvisited.size(), -1);
    vector<int> dfs_low(unvisited.size(), -1);
    
    vector<vector<Node*>> sccs;

    while(unvisited.size() != 0) {
        Node* temp;
        
        // When no nodes are visited
        if(stack.size() == 0) {
            // Get front of univisited vector, remove it from unvisited, and set it as visited
            temp = unvisited.front();
            unvisited.erase(unvisited.begin());
            temp->set_visited();
            visited.push_back(temp);
            
            // If no nodes left in unvisited, break the loop
            if(unvisited.size() == 0) break;

            // For each neighbor of the node, push it to the stack
            vector<Node*> adj_list = temp->get_adjacency_list();
            for(Node* node : adj_list) {
                if(!node->is_visited()) stack.push(node);
            }

        } else if(stack.size() > 0) { // When stack has Node(s)
            
            // Get top node from stack and pop
            temp = stack.top();
            stack.pop();

            // Set top node to visited
            temp->set_visited();
            visited.push_back(temp);
            
            // Remove node from unvisited
            for(int i = 0; i < unvisited.size(); i++) {
                if(temp == unvisited.at(i)) unvisited.erase(unvisited.begin() + i);
            }
            
            // Push neighboring nodes to the stack
            vector<Node*> adj_list = temp->get_adjacency_list();
            for(Node* node : adj_list) {
                if(!node->is_visited()) stack.push(node);
            }
        }    
    }

    return visited;
}