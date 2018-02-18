/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Reads credit card numbers from a file inputs the info into a or several vectors.
 *                  Then read in a transaction from a different file and match it to the stored card.
 */
 
 #include <iostream>
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
 using std::ifstream;
 using std::stringstream;
 using std::vector;
 
 class Card {
     
     private:
     
     string card_number_, 
            first_name_, 
            last_name, 
            type_, 
            current_balance_;
     char bank_;
     vector<Card> Cards_;
     
     public:
     
     /*
      * Constructor
      * Gives Card variables a default value
      * Unless other values are passed in
      */
     Card();
     vector<Card> PopulateCards();
     //runs card through the Luhn algorithm
     bool Luhn_Check();
     //fills Cards vector with default values
     
     
 };
 
 
 
 int main() {
     cout << Cards_(1);
 }
 
Card::Card(){
     
     card_number_ = " ";
     first_name_ = " ";
     last_name = " ";
     type_ = " ";
     current_balance_ = " ";
     
 }
 
bool Card::Luhn_Check(){
     
}

vector<Card> Card::PopulateCards(){
    
}