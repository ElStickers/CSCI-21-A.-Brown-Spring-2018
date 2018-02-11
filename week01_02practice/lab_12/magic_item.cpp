/*
 * Name         : magic_item.cpp
 * Author       : Juan Palos
 * Description  : Class Do Stuff File
 */
 
 #include "magic_item.h"
 
/*
 * Constructor
 * two parameters, one for each private memeber variable
 * defaults name_ to "item"
 * defaults value_ to 0
 */
 
 MagicItem::MagicItem(string name, unsigned int value, string description, unsigned int mana_required) : Item(name, value) {
     
     name_ = name;
     
     value_ = value;
     
     description_ = description;
     
     mana_required_ = mana_required;
     
 }
 
/*
 * Destructor
 * Does Nothing
 * Must be Virtual
 */
 MagicItem::~MagicItem() {
     
 }
 
 /*
  * Accessors
  * For private variables
  */
 string MagicItem::description() {
      
      return description_;
      
  }
  
 unsigned int MagicItem::mana_required() {
      
      return mana_required_;
      
  }
  
 /*
  * Mutators
  * For private variables
  */
 void MagicItem::set_description(string description) {
     
     description_ = description;
     
 }
 
 void MagicItem::set_mana_required(unsigned int mana_required) {
     
     mana_required_ = mana_required;
     
 }
 
 
 /*
  * Returns a string containing name_, value_, units_, unit_of_measure_ and calories_
  * (uses Item::ToString int its implementation)
  * units_ formatted to exactly two decimal places
  * Format -- name_. $value_, description_, requires mana_required_ mana
  * Ex -- hat, $10, made of felt, requires 2 mana
  */
 string MagicItem::ToString() {
     
     stringstream ss;
     
     ss << Item::ToString() << ", " << description_ << ", requires " << mana_required_ << " mana";
     
     return ss.str();
     
 }