/*
 * Name        : food_item.cpp
 * Author      : Jacob Pawek
 * Description : Class Header File
 */

#include "food_item.h"

//Constructor
//five parameters, one for each private member variable and two for the
//base class
//defaults name_ to "fooditem"
//defaults value_ to 0
//defaults calories_ to 0
//defaults unit_of_measure_ to "nounits"
//defaults units_ to 0
FoodItem::FoodItem(string name, unsigned int value, unsigned int calories, string unit_of_measure, double units) : Item(name, value){
 name_ = name;
 value_ = value;
 calories_ = calories;
 unit_of_measure_ = unit_of_measure;
 units_ = units;
}
  
//Destructor
//does nothing
//must be virtual (add virtual keyword before the destructor)
FoodItem::~FoodItem() {
    
}
  
//Accessors and Mutators for the 3 private varaibles
//use the naming scheme we have been using all semester
unsigned int FoodItem::calories() {
    return calories_;
}
  
string FoodItem::unit_of_measure() {
    return unit_of_measure_;
}
  
double FoodItem::units() {
    return units_;
}
  
void FoodItem::set_calories(unsigned int calories) {
    calories_ = calories;
}
  
void FoodItem::set_unit_of_measure(string unit_of_measure) {
    unit_of_measure_ = unit_of_measure;
}
  
void FoodItem::set_units(double units) {
    units_ = units;
}
  
//string ToString()
//returns a string containing name_, value_, units_, unit_of_measure_,
//and calories_
//(uses Item::ToString in its implementation)
//units_ formatted to exactly two decimal places
//Format -- name_, $value_, units_ unit_of_measure_, calories_
//calories
//EXAMPLE -- cookie, $1, 2.50 cookie(s), 250 calories
string FoodItem::ToString() {
 stringstream ss;
 ss << Item::ToString() << ", " << fixed << setprecision(2) << units_ << " " << unit_of_measure_ << ", " << calories_ << " calories";
 return ss.str();
}