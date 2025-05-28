#include <iostream>
#include "Node.h"

using namespace std;

int main() {
    // Create a Node object using the default constructor
    Node* node1 = new Node();

    // Create a Node object using the parameterized constructor
    Node* node2 = new Node("Node2", 10);

    // Output the node details
    cout << "Node 1: " << node1->get_name() << ", Number: " << node1->get_num() << endl;
    cout << "Node 2: " << node2->get_name() << ", Number: " << node2->get_num() << endl;

    return 0;
}