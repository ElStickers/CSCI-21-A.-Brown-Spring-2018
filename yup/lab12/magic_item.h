/*
 * Name        : magic_item.h
 * Author      : Jacob Pawek
 * Description : Class Header File
 */

#ifndef MAGIC_ITEM_H
#define MAGIC_ITEM_H

#include "item.h"
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

class MagicItem : public Item {
 public:
 
  //Constructor
  //four parameters, one for each private member variable and two for the
  //base class
  //defaults name_ to "magicitem"
  //defaults value_ to 0
  //defaults description_ to "no description"
  //defaults mana_required_ to 0
  MagicItem(string name = "magicitem", unsigned int value = 0, string description = "no description", unsigned int mana_required = 0);
  
  //Destructor
  //does nothing
  //must be virtual (add virtual keyword before the destructor)
  virtual ~MagicItem();
  
  //Accessors and Mutators for the 2 private varaibles
  //use the naming scheme we have been using all semester
  string description();
  
  unsigned int mana_required();
  
  void set_description(string description);
  
  void set_mana_required(unsigned int mana_required);
  
  //string ToString()
  //returns a string containing name_, value_, desciption_, and
  //mana_required_
  //(uses Item::ToString in its implementation)
  //Format -- name_, $value_, description_, requires mana_required_ mana
  //EXAMPLE -- hat, $10, made of felt, requires 2 mana
  string ToString();
  
 protected:
 
  //holds a description of the magic item
  string description_;

  //holds the amount of mana required to use the magic item
  unsigned int mana_required_;
};



#endif