/*
 *Author:       Juan Palos
 *Description:  Node Stuff
 */
 
 #include "node.h"
 
 Node::Node()
 {
    next = NULL;
    
    data = "";
 }
 
 Node::Node(const string& input)
 {
     data = input;
     
     next = NULL;
 }
 
 string Node::contents()
 {
    return data;
 }
 
 Node* Node::next_node()
 {
     return next;
 }
 
 void Node::set_next_node(Node* nextNode)
 {
    next = nextNode;
 }
 
 void Node::set_contents(string input)
 {
     data = input;
 }