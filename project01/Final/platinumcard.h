/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           (Enter Date Here)
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Reads credit card numbers from a file inputs the info into a or several vectors.
 *                  Then read in a transaction from a different file and match it to the stored card.
 */
 
 #ifndef PLATINUMCARD_H
 #define PLATINUMCARD_H
 
 #include "cardwork.h"
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
  * Platinum class
  * Derived from the Card class
  * Holds info unique to a Platinum type card
  */
class PlatinumCard : public Card {
protected:
    
    double credit_amount_, overdraft_allowance_;
    
    int rebate_;

public:

    PlatinumCard(); //Constructor, sets variables to default values unless argument is present

    double credit_amount(); //Accessor, returns value of credit_amount
 
    double overdraft_allowance(); //Accessor, returns value of overdraft_allowance
 
    int rebate(); //Accessor, returns value of rebate_
 
    void CheckDenied(); //Checks for denied transacs

    void set_credit_amount(double credit_amount);//Mutator, sets credit_amount to input argument

    void set_overdraft_allowance(double overdraft_allowance); //Mutator, sets overdraft_allowance to input argument

    void set_rebate(int rebate); //Mutator, sets rebate_ to the input argument 

 };
 
 #endif
 