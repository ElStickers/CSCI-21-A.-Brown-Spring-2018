/*
 * Name         : item.h
 * Author       : Juan Palos
 * Description  : Class Header File
 */
 
 #ifndef ITEM_H
 #define ITEM_H
 
 
 #include <iostream>
 #include <string>
 #include <sstream>
 #include <iostream>
 using namespace std;
 
 
 
 class Item {
     protected:
     
     //holds the name of the item
     string name_;
     
     //holds the value of the item
     unsigned int value_;
     
     public:
     
     /*
      * Constructor
      * two parameters, one for each private memeber variable
      * defaults name_ to "item"
      * defaults value_ to 0
      */
      Item(string name = "item", unsigned int value = 0);
      
      /*
       * Destructor
       * Does Nothing
       * Must be Virtual
       */
      virtual ~Item();
      
      /*
       * Accessors
       * For private variables
       */
      string name();
      
      unsigned int value();
      
      /*
       * Mutators 
       * For private variables
       */
      void set_name(string name_);
      
      void set_value(unsigned int value_);
      
      /*
       * string ToString()
       * returns a string containing name_ and value_
       * format -- name_, $value_
       * ex. shoes, $25
       */
      string ToString();
 };
 
 #endif
 