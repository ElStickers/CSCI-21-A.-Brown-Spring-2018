/*
 * Name        : food_item.h
 * Author      : Jacob Pawek
 * Description : Class Header File
 */

#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

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

class FoodItem : public Item {
 public:
 
  //Constructor
  //five parameters, one for each private member variable and two for the
  //base class
  //defaults name_ to "fooditem"
  //defaults value_ to 0
  //defaults calories_ to 0
  //defaults unit_of_measure_ to "nounits"
  //defaults units_ to 0
  FoodItem(string name = "fooditem", unsigned int value = 0, unsigned int calories = 0, string unit_of_measure = "nounits", double units = 0);
  
  //Destructor
  //does nothing
  //must be virtual (add virtual keyword before the destructor)
  virtual ~FoodItem();
  
  //Accessors and Mutators for the 3 private varaibles
  //use the naming scheme we have been using all semester
  unsigned int calories();
  
  string unit_of_measure();
  
  double units();
  
  void set_calories(unsigned int calories);
  
  void set_unit_of_measure(string unit_of_measure);
  
  void set_units(double units);
  
  //string ToString()
  //returns a string containing name_, value_, units_, unit_of_measure_,
  //and calories_
  //(uses Item::ToString in its implementation)
  //units_ formatted to exactly two decimal places
  //Format -- name_, $value_, units_ unit_of_measure_, calories_
  //calories
  //EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories
  string ToString();
  
 protected:
 
  //holds a calorie count
  unsigned int calories_;

  //holds the unit of measure (such as "ounces")
  string unit_of_measure_;
  
  //holds a count of how many units we have
  double units_;
};

#endif