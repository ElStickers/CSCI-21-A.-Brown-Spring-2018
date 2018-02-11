/*
 * Name         : food_item.cpp
 * Author       : Juan Palos
 * Description  : Class Do Stuff File
 */
 
 #include "food_item.h"
 
/*
 * Constructor
 * two parameters, one for each private memeber variable
 * defaults name_ to "item"
 * defaults value_ to 0
 */
 
 FoodItem::FoodItem(string name, unsigned int value, unsigned int calories, string unit_of_measure, double units) {
     
     name_ = name;
     
     value_ = value;
     
     calories_ = calories;
     
     unit_of_measure_ = unit_of_measure;
     
     units_ =  units;
     
 }
 
/*
 * Destructor
 * Does Nothing
 * Must be Virtual
 */
 FoodItem::~FoodItem() {
     
 }
 
 /*
  * Accessors
  * For private variables
  */
 string FoodItem::unit_of_measure() {
      
      return unit_of_measure_;
      
  }
  
 unsigned int FoodItem::calories() {
      
      return calories_;
      
  }
  
  double FoodItem::units() {
      
      return units_;
  }
  
 /*
  * Mutators
  * For private variables
  */
 void FoodItem::set_calories(unsigned int calories) {
     
     calories_ = calories;
     
 }
 
 void FoodItem::set_unit_of_measure(string unit_of_measure) {
     
     unit_of_measure_ = unit_of_measure;
     
 }
 
 void FoodItem::set_units(double units) {
     
     units_ = units;
     
 }
 
 /*
  * Returns a string containing name_, value_, units_, unit_of_measure_ and calories_
  * (uses Item::ToString int its implementation)
  * units_ formatted to exactly two decimal places
  * Format -- name_. $value_, units_, unit_of_measure_, calories_ calories
  * Ex -- cookie, $1, 2.50 cookie(s), 250 calories
  */
 string FoodItem::ToString() {
     
     stringstream ss;
     
     ss << Item::ToString() << ", " << fixed << setprecision(2) << units_ << " " << unit_of_measure_ << ", " << calories_ << " calories";
     
     return ss.str();
     
 }