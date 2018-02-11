/*
 * Name         : magic_item.h
 * Author       : Juan Palos
 * Description  : Class Header File
 */
 
 #ifndef MAGIC_ITEM_H
 #define MAGIC_ITEM_H
 
 #include "item.h"
 #include <iostream>
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <cstdlib>
 #include <iomanip>
 using namespace std;
 
 class MagicItem : public Item {
     
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
      MagicItem(string name = "magicitem", unsigned int value = 0, string description = "no description", unsigned int mana_required = 0);
      
      /*
       * Destructor
       * Does Nothing
       * Must be virtual
       */
      ~MagicItem();
      
      /*
       * Accessors
       * For private variables
       */
      string description();
      
      unsigned int mana_required();
      
      /*
       * Mutators 
       * For private variables
       */
      void set_description(string description_);
      
      void set_mana_required(unsigned int mana_required_);
      
      /*
       * string ToString()
       * returns a string containing name_ and value_
       * format -- name_, $value_, description_, requires mana_required_ mana
       * ex. hat, $10, made of felt, requires 2 mana
       */
      string ToString();
      
    protected:
     
     /*
      * Holds a description of the magic item
      */
     string description_;
     
     /*
      * Holds the ammount of mana required to use the magic item
      */
     unsigned int mana_required_;
 };
 
 #endif
 