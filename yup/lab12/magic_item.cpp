/*
 * Name        : magic_item.cpp
 * Author      : Jacob Pawek
 * Description : Class Header File
 */

#include "magic_item.h"


//Constructor
//four parameters, one for each private member variable and two for the
//base class
//defaults name_ to "magicitem"
//defaults value_ to 0
//defaults description_ to "no description"
//defaults mana_required_ to 0
MagicItem::MagicItem(string name, unsigned int value, string description, unsigned int mana_required) : Item(name, value){
 name_ = name;
 value_ = value;
 description_ = description;
 mana_required_ = mana_required;
}
  
//Destructor
//does nothing
//must be virtual (add virtual keyword before the destructor)
MagicItem::~MagicItem() {
    
}
  
//Accessors and Mutators for the 2 private varaibles
//use the naming scheme we have been using all semester
string MagicItem::description() {
 return description_;
}
  
unsigned int MagicItem::mana_required() {
 return mana_required_;
}
  
void MagicItem::set_description(string description) {
 description_ = description;
}
  
void MagicItem::set_mana_required(unsigned int mana_required) {
 mana_required_ = mana_required;
}
  
//string ToString()
//returns a string containing name_, value_, desciption_, and
//mana_required_
//(uses Item::ToString in its implementation)
//Format -- name_, $value_, description_, requires mana_required_ mana
//EXAMPLE -- hat, $10, made of felt, requires 2 mana
string MagicItem::ToString() {
 stringstream ss;
 ss << Item::ToString() << ", " << description_ << ", requires " << mana_required_ << " mana";
 return ss.str();
}