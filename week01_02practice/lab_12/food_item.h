/*
 * Name         : food_item.h
 * Author       : Juan Palos
 * Description  : Class Header File
 */
 
 #ifndef FOOD_ITEM_H
 #define FOOD_ITEM_H
 
 #include "item.h"
 #include <iostream>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <cstdlib>
 #include <iomanip>
 using namespace std;
 
 class FoodItem : public Item {
     
     protected:
     
     /*
      * Holds a calorie count
      */
     unsigned int calories_;
     
     /*
      * Holds the unit of measure (such as ounces)
      */
     string unit_of_measure_;
     
     /*
      * Holds a count of how many units we have
      */
     double units_;
     
     public:
     
     /*
      * Constructor
      * Five parameters, one for each private member variable and two for the base class
      * Defaults name_ to "fooditem"
      * Defaults value_ to 0
      * Defaults calories_ to 0
      * Defaults unit_of_measure_ to "nounits"
      * Defaults units_ to 0
      */
      FoodItem(string name = "fooditem", unsigned int value = 0, unsigned int calories = 0, string unit_of_measure = "nounits", double units = 0);
      
      /*
       * Destructor
       * Does Nothing
       * Must be virtual
       */
      ~FoodItem();
      
      /*
       * Accessors
       * For private variables
       */
      string unit_of_measure();
      
      unsigned int calories();
      
      double units();
      
      /*
       * Mutators 
       * For private variables
       */
      void set_calories(unsigned int calories_);
      
      void set_unit_of_measure(string unit_of_measure_);
      
      void set_units(double units_);
      
      /*
       * string ToString()
       * returns a string containing name_ and value_
       * format -- name_, $value_
       * ex. shoes, $25
       */
      string ToString();
 };
 
 #endif