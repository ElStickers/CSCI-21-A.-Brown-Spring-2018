/*
 *Author:       Juan Palos
 *Name:         stack.cpp
 *Description:  Stack Class Definitions
 */

#include "stack.h"

Stack::Stack()
{
    head_ = NULL;
    
    current_ = NULL;
}

int Stack::size()
{
    int temp = 0;
    
    Node* temp_node = head_;
    
    while(temp_node != NULL)
    {
        temp++;
        
        temp_node = temp_node->next_node();
    }
    
    return temp;
}

string Stack::ToString()
{
    string out;
    
    Node* temp = head_;
    
    while(temp != NULL)
    {
        out += temp->contents();
        
        out += ", ";
        
        temp = temp->next_node();
    }
    out = out.substr(0, out.size() - 2);
    
    return out;
}

void Stack::InsertHead(int input)
{
    string temp_input = to_string(input);
    
    Node* temp = new Node;
    
    temp->set_contents(temp_input);
    
    temp->set_next_node(head_);
    
    head_ = temp;    
}

void Stack::InsertHead(string input)
{
    //data_ = input;
    
    Node* temp = new Node;
    
    temp->set_contents(input);
    
    temp->set_next_node(head_);
    
    head_ = temp;
}

void Stack::RemoveHead()
{
    if(head_ != NULL)
    {
        Node* temp = head_;
        
        temp = temp->next_node();
        
        delete head_;
        
        head_ = temp;
        
    }
}

void Stack::Clear()
{
    while(head_ != NULL)
    {
    Node* temp = head_;
    
    temp = temp->next_node();
    
    delete head_;
    
    head_ = temp;
    
    }
}