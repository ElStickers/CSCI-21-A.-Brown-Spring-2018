/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           (Enter Date Here)
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Reads credit card numbers from a file inputs the info into a or several vectors.
 *                  Then read in a transaction from a different file and match it to the stored card.
 */
 
 #include "card.h"
 
    //constructor, sets all variables to a default unless argument is present
     Card::Card() {
         
         card_number_ = 0;
         first_name_ = "";
         last_name_ = "";
         card_type_ = "";
         balance_ = 0;
         bank_ = "";
     }
     //Accessor, returns card_number_
     long long Card::card_number(){
         
         return card_number_;
         
     }
     //Accessor, returns first_name_
     string Card::first_name() {
         
         return first_name_;
         
     }
     //Accessor, returns last_name_
     string Card::last_name() {
         
         return last_name_;
         
     } 
     //Accessor, returns card_type_
     string Card::card_type() {
         
         return card_type_;
         
     }
     //Accessor, returns balance_
     double Card::balance() {
         
         return balance_;
         
     } 
     //Accessor, returns bank_
     char Card::bank() {
         
         return bank_;
         
     } 
     
     bool Luhn_Check(); //Runs card number through luhn algorithm to check  its validity
     
     void Check_Bank(long long card_number); //checks the digits of card to find bank origin
     
     void set_card_number(string card_number); //mutator, sets card_number_ to input
     
     void set_first_name(string first_name); // mutator, sets first_name_ to input
     
     void set_last_name(string last_name); // mutator, sets last_name_ to input
     
     void set_card_type(string card_type); // mutator, sets card_type_ to input
     
     void set_balance(double balance); //mutator, sets balance_ to input
     
     void set_bank(char bank); //mutator, sets bank_ to input