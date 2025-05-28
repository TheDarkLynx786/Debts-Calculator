#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node {
    private:
        int num;
        string name;
    
    public:
        // Constructor
        Node() {}

        // Constructor with parameters
        Node(string name, int value) : name(name), num(value) {}

        // Get Node Number
        int get_num() const;

        // Get Node Name
        string get_name() const;
};


#endif