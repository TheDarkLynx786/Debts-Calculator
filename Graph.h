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

        vector<vector<Node*>> tarjan_solve();

        void tarjan(vector<Node*> unvisited, stack<Node*> scc_stack, stack<Node*> exploration_stack, vector<vector<Node*>>& sccs, int ct, vector<int> num, vector<int> low);

        bool check_stack(Node* node, stack<Node*> stack);
        
        void delete_nodes();

        void print_nodes() const;

        void print_edges() const;
};

#endif