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

vector<Node*> Graph::get_nodes() { return this->nodes; }

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

/*vector<Node*> Graph::dfs() {
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
}*/

void Graph::dfs_solve() {
    vector<Node*> visited;
    stack<Node*> stack;
    dfs(nodes, visited, stack);

    cout << "DFS Search: " << endl;
    for(Node* md : visited) cout << md->get_name() << " ";
    cout << endl;
}

void Graph::dfs(vector<Node*> unvisited, vector<Node*>& visited, stack<Node*> exploration_stack) {
    // Base Case
    if(unvisited.size() == 0) return;

    // Step
    Node* node = (exploration_stack.size() == 0)? unvisited.front() : exploration_stack.top();
    if (exploration_stack.size() != 0) exploration_stack.pop();
    
    // If node is already visited (through the stack), then skip it
    if(node->is_visited()) {
        dfs(unvisited, visited, exploration_stack); 
        return;
    }

    // Set node to visited and add to "visited"
    node->set_visited();
    visited.push_back(node);
    
    // Remove from "unvisited"
    for(int i = 0; i < unvisited.size(); i++) { if(unvisited.at(i) == node) unvisited.erase(unvisited.begin() + i); }

    // Get adjacency list
    vector<Node*> adj_list = node->get_adjacency_list();

    // Add each adjacent node to the stack
    for(Node* nd : adj_list) exploration_stack.push(nd);

    dfs(unvisited, visited, exploration_stack);
    return;
}

/*vector<Node*> Graph::tarjan() {
    vector<Node*> unvisited = this->nodes;
    // This vector SHOULD have the correct DFS order of nodes ( if using push_front() )
    vector<Node*> visited = {};
    stack<Node*> stack;

    vector<int> dfs_num;
    int counter = 0;
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
            
            // Add to stack
            stack.push(temp);

            // Set DFS number
            dfs_num.push_back(counter);

            // Add first neighbord in adj list to stack
            vector<Node*> adj_list = temp->get_adjacency_list();
            bool adj = false;
            for(Node* node : adj_list) {
                if(!node->is_visited()) {
                    stack.push(node);
                    adj = true;
                    break;
                }
            }

            // This would mean that theres a single disconnected SCC
            if(!adj) {
                vector<Node*> new_scc;
                new_scc.push_back(temp);
                sccs.push_back(new_scc);
                stack.pop();
            }

        } else if(stack.size() > 0) { // When stack has Node(s)
            
            // Get top node from stack and pop
            temp = stack.top();

            // Set top node to visited
            temp->set_visited();
            visited.push_back(temp);
            
            // Remove node from unvisited
            for(int i = 0; i < unvisited.size(); i++) {
                if(temp == unvisited.at(i)) unvisited.erase(unvisited.begin() + i);
            }
            
            // Set DFS number


            // Push first neighboring node to the stack
            vector<Node*> adj_list = temp->get_adjacency_list();
            bool adj = false;
            for(Node* node : adj_list) {
                if(!node->is_visited()) {
                    stack.push(node);
                    adj = true;
                    break;
                }
            }

            if (!adj) {

            }
        }
        
        counter++;
    }

    return visited;
}*/

vector<vector<Node*>> Graph::tarjan_solve() {
    stack<Node*> scc_stack, exploration_stack;
    vector<vector<Node*>> sccs;
    vector<int> num(nodes.size(), -1), low(nodes.size(), -1);

    tarjan(nodes, scc_stack, exploration_stack, sccs, 0, num, low);
    
    return sccs;
}


void Graph::tarjan(vector<Node*>& unvisited, stack<Node*>& scc_stack, stack<Node*>& exploration_stack, vector<vector<Node*>>& sccs, int ct, vector<int>& num, vector<int>& low) {
    cout << "CT: " << ct << endl;
    
    // Base Case
    if (unvisited.size() == 0) { cout << "END" << endl; return; }
    cout << endl;

    for(Node* md : unvisited) cout << md->get_name() << " ";


    // Step
    Node* node = (exploration_stack.size() == 0)? unvisited.front() : exploration_stack.top();
    if (exploration_stack.size() != 0) exploration_stack.pop();

    cout << "Node: " << node->get_name() << endl;
    
    

    // Set dfs_low
    if(!node->is_visited()) {

        // Assign Node dfs_num and low_link
        num.at(ct) = low.at(ct) = ct;
        node->set_num(ct);

        cout << "DFS Num: " << num.at(ct) << endl;
        cout << "DFS Low: " << low.at(ct) << endl;

        cout << "Unvisited Node" << endl;
        cout <<  node->is_visited() << endl << endl;

        // Remove from "unvisited" and set node to visited
        for(int i = 0; i < unvisited.size(); i++) { if(unvisited.at(i) == node) unvisited.erase(unvisited.begin() + i); }
        node->set_visited();

        // Get adjacency list
        vector<Node*> adj_list = node->get_adjacency_list();

        // Add each adjacent node to the exploration stack
        for(Node* nd : adj_list) exploration_stack.push(nd);

        cout << endl;
        print_stack(exploration_stack);
        cout << endl;

        Node* comparison_node = exploration_stack.top();

        // Push node to scc_stack
        scc_stack.push(node);
        
        // Recurse 
        tarjan(unvisited, scc_stack, exploration_stack, sccs, ct + 1, num, low);

        // Adjust dfs_low
        low.at(node->get_num()) = min(low.at(node->get_num()), low.at(comparison_node->get_num()));
        
        cout << "DFS Low: " << low.at(node->get_num()) << endl;

    } else if (check_stack(node, scc_stack)) { cout << "Visited Node" << endl; low.at(node->get_num()) = min(low.at(node->get_num()), num.at(node->get_num()) ); cout << "DFS Num: " << num.at(ct) << endl; cout << "DFS Low: " << low.at(ct) << endl;}
    

    // Check if there is an SCC
    if (num.at(node->get_num()) == low.at(node->get_num()) && scc_stack.size() > 0) {
        vector<Node*> scc;
        cout << "SCC Found" << endl;
        Node* top_node;
        do {
            top_node = scc_stack.top();
            scc_stack.pop();
            scc.push_back(top_node);

        } while (node != top_node && scc_stack.size() > 0);
        
        for (Node* nd : scc) {
            cout <<  nd->get_name() << " ";
        }
        cout << endl;

        sccs.push_back(scc);
    }

}


void Graph::delete_nodes() { for(Node* nd : nodes) { delete nd; } }

bool Graph::check_stack(Node* node, stack<Node*> stack) {
    while(stack.size() != 0) { if (stack.top() == node) return true; else stack.pop(); }
    return false;
}

void Graph::print_stack(stack<Node*> stack) { 
    while(stack.size() != 0) { cout << stack.top()->get_name() << " "; stack.pop(); }
}