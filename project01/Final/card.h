/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           2/28
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Header File for card class
 */
 #ifndef CARD_H
 #define CARD_H
 
 #include "transac.h"
 
 #include <iostream>
 #include <iomanip>
 #include <sstream>
 #include <fstream>
 #include <cctype>
 #include <string>
 #include <cstdlib>
 #include <vector> 
 using std::cout;
 using std::cerr;
 using std::cin;
 using std::endl;
 using std::string;
 using std::ifstream;
 using std::stringstream;
 using std::vector;

 
 /* 
  * Card class
  * Holds info all card types share, Runs some card validation tests as well
  */
 class Card {
     
     protected:
     string card_number_; // hold card number in string
     string first_name_, last_name_, card_type_;//hold firs and last name as well as card type (ie gold )
     double balance_; //holds card balance
     char bank_;//holds bank id
     vector<Transac> transac_;
     public:
     
     Card();//constructor, sets all variables to a default unless argument is present
     
     string card_number(); //Accessor, returns card_number_
     
     string first_name(); //Accessor, returns first_name_
     
     string last_name(); //Accessor, returns last_name_
     
     string card_type(); //Accessor, returns card_type_
     
     vector<Transac> transacs(); //Accessor, returns a vector of card transactions.
     
     double balance(); //Accessor, returns balance_
     
     char bank(); //Accessor, returns bank_
     
     bool Luhn_Check(); //Runs card number through luhn algorithm to check  its validity
     
     void Check_Bank(string card_number); //checks the digits of card to find bank origin
     
     void set_card_number(string card_number); //mutator, sets card_number_ to input
     
     void set_first_name(string first_name); // mutator, sets first_name_ to input
     
     void set_last_name(string last_name); // mutator, sets last_name_ to input
     
     void set_card_type(string card_type); // mutator, sets card_type_ to input
     
     void set_balance(double balance); //mutator, sets balance_ to input
     
     void set_bank(char bank); //mutator, sets bank_ to input
     
     void set_transac(vector<Transac> transac); //mutator, inputs transaction info into the vector
     
    
 };
 
 #endif