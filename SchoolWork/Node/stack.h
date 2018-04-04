/*
 *Author:       Juan Palos
 *Name:         stack.h
 *Description:  Stack Class Declarations
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stack>
#include "node.h"

using namespace std;

class Stack : public Node
{
    private:
    Node* head_;
    
    Node* current_;
    
    public:
    
    Stack();
    
    int size();
    
    string ToString();
    
    void InsertHead(int input);
    
    void InsertHead(string input);
    
    void RemoveHead();
    
    void Clear();
    
};

#endif