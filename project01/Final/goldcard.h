/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           (Enter Date Here)
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Reads credit card numbers from a file inputs the info into a or several vectors.
 *                  Then read in a transaction from a different file and match it to the stored card.
 */
 
 #ifndef GOLDCARD_H
 #define GOLDCARD_H
 
 #include "card_work.h"
 #include "card.h"
 
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
 using std::string;
 using std::ifstream;
 using std::stringstream;
 using std::vector;
 
 /*
  * GoldCard class
  * Derived from the Card class
  * Holds info unique to a Gold type card
  */
 class GoldCard : public Card {
     
     public:
        
        /*
         * Consturctor
         * Sets varibales to a default value
         * Unless inputs are passed in
         */
        GoldCard();
        
        /*
         * Mutator
         * Sets line_of_credit to input
         */
 };
 
 #endif
 