/*
 * Name         : item.cpp
 * Author       : Juan Palos
 * Description  : Class Do Stuff File
 */
 
 #include "item.h"
 
/*
 * Constructor
 * two parameters, one for each private memeber variable
 * defaults name_ to "item"
 * defaults value_ to 0
 */
 
 Item::Item(string name, unsigned int value) {
     
     name_ = name;
     
     value_ = value;
     
 }
 
/*
 * Destructor
 * Does Nothing
 * Must be Virtual
 */
 Item::~Item() {
     
 }
 
 /*
  * Accessors
  * For private variables
  */
 string Item::name() {
      
      return name_;
      
  }
  
 unsigned int Item::value() {
      
      return value_;
      
  }
  
 /*
  * Mutators
  * For private variables
  */
 void Item::set_name(string name) {
     
     name_ = name;
     
 }
 
 void Item::set_value(unsigned int value) {
     
     value_ = value;
     
 }
 
 /*
  * string ToString()
  * returns a string containing name_ and value_
  * format -- name_, $value_;
  * ex. shoes, $25;
  */
 string Item::ToString() {
     
     stringstream ss;
     
     ss << name_ << ", $" << value_;
     
     return ss.str();
     
 }