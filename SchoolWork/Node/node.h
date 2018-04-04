/*
 *Author:       Juan Palos
 *Name:         node.h
 *Description:  Node Class Declarations
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node
{
    protected:
    
    string data_;
    
    Node* next_;

    public:
    
    Node();
    
    Node(const string& input);
    
    string contents();
    
    Node* next_node();
    
    void set_next_node(Node* nextNode);
    
    void set_contents(string input);
    
    
    
};

#endif