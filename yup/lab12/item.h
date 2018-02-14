/*
 * Name        : item.h
 * Author      : Jacob Pawek
 * Description : Class Header File
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::stringstream;
using std::string;
using std::ostream;

class Item {
public:

 //Constructor
 //two parameters, one for each private member variable
 //defaults name_ to "item"
 //defaults value_ to 0
 Item(string name = "item", unsigned int value = 0);

 //Destructor
 //does nothing
 //must be virtual (add virtual keyword before the destructor)
 virtual ~Item();

 //Accessors and Mutators for the 2 private varaibles
 //use the naming scheme we have been using all semester
 string name();
 unsigned int value();
 
 void set_name(string name);
 void set_value(unsigned int value);

 //string ToString()
 //returns a string containing name_ and value_
 //Format -- "name_, $ value_"
 //EXAMPLE -- "shoes, $25"
 string ToString();
 
  protected:
  
 //string name_
 //holds the name of the item
 string name_;
 
 //unsigned int value_
 //holds the value of the item
 unsigned int value_;
};



#endif