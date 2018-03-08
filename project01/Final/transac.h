/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           2/28
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Header File for Transac Class.
 */
 
 #ifndef TRANSAC_H
 #define TRANSAC_H
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

 /* 
  * Transac class
  * Holds info about a cards transactions.
  */
  
  class Transac {
      protected:
      string card_num_, date_, transac_num_,vendor_;
      double transac_amount_;
      bool denied_;
      
      public:
      Transac(); //Constructor, Sets all variables to defualt values unless argument is present
      
      string card_number(); // Accesor, reutrns the value of card_num_
      
      string date(); //Accessor, returns the value of date_
      
      string transac_num(); //Accesor, returns the value of transac_num_
      
      string vendor(); //Accessor, retruns the value of vendor_
      
      double transac_amount(); //Accessor, returns the value of amount_
      
      bool denied(); //Accessor, returns true/false value for denied_
      
      void set_card_number(string card_num); //Mutator, sets card_num_ to incoming argument
      
      void set_date(string date); //Mutator, sets date_ to incoming argument
      
      void set_transac_num(string transac_num); //Mutator, sets transac_num_ to incoming argument
      
      void set_vendor(string vendor); //Mutator, sets vendor_ to incoming argument
      
      void set_transac_amount(double transac_amount); //Mutator, sets amount_ to incoming 
      
      void set_denied(bool denied); //Mutator, sets denied value to incoming argument

};

#endif