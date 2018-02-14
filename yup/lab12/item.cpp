/*
 * Name        : item.cpp
 * Author      : Jacob Pawek
 * Description : Class Header File
 */

#include "item.h"


 //Constructor
 //two parameters, one for each private member variable
 //defaults name_ to "item"
 //defaults value_ to 0
 Item::Item(string name, unsigned int value) {
  name_ = name;
  value_ = value;
 }

 //Destructor
 //does nothing
 //must be virtual (add virtual keyword before the destructor)
 Item::~Item() {
     
 }

 //Accessors and Mutators for the 2 private varaibles
 //use the naming scheme we have been using all semester
 string Item::name() {
  return name_;
 }
 
 unsigned int Item::value() {
  return value_;
 }
 
 void Item::set_name(string name) {
  name_ = name;
 }
 
 void Item::set_value(unsigned int value) {
  value_ = value;
 }

 //string ToString()
 //returns a string containing name_ and value_
 //Format -- "name_, $ value_"
 //EXAMPLE -- "shoes, $25"
 string Item::ToString() {
 stringstream ss;
 ss << name_ << ", $" << value_;
 return ss.str();
 }