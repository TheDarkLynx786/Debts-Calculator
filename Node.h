#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
    private:
        int num;
        string name;
        bool visited;
        vector<Node*> adjacency_list;
    
    public:
        // Constructor
        Node() {
            num = 0;
            name = "";
            visited = false;
            adjacency_list = {};
        }

        // Constructor with parameters
        Node(string name, int value) : name(name), num(value), visited(false), adjacency_list({}) {}

        // Get Node Number
        int get_num() const;

        // Get Node Name
        string get_name() const;

        // Check if visited
        bool is_visited() const;
        
        // Set visited status
        void set_visited();

        // Add to adjacency list
        void add_neighbor(Node* neighbor);

        // Get adjacency list
        vector<Node*> get_adjacency_list();
};


#endif