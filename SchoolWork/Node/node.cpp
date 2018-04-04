/*
 *Author:       Juan Palos
 *Name:         node.cpp
 *Description:  Node Class Function Definitions
 */
 
 #include "node.h"
 
 Node::Node()
 {
    next_ = NULL;
    
    data_ = "";
 }
 
 Node::Node(const string& input)
 {
     data_ = input;
     
     next_ = NULL;
 }
 
 string Node::contents()
 {
    return data_;
 }
 
 Node* Node::next_node()
 {
     return next_;
 }
 
 void Node::set_next_node(Node* nextNode)
 {
    next_ = nextNode;
 }
 
 void Node::set_contents(string input)
 {
     data_ = input;
 }