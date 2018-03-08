    /*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           (Enter Date Here)
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    
 */
 
 #include "goldcard.h"
 
//Constructor, sets variables to default values unless argument is present
GoldCard::GoldCard() {
    
    credit_amount_ = 3000;
    
    overdraft_allowance_ = 0;
    
    rebate_ = 1;
    
}

//Accessor, returns value of credit_amount
double GoldCard::credit_amount() {
    
    return credit_amount_;
    
}

//Accessor, returns value of overdraft_allowance
double GoldCard::overdraft_allowance() {
    
    return overdraft_allowance_;
    
}

//Accessor, returns value of rebate_
int GoldCard::rebate() {
    
    return rebate_;
    
}

//Checks for denied transacs
void GoldCard::CheckDenied() {
    
    for (int i = 0; i < transac_.size(); i++) {
        
    if (balance_ - transac_.at(i).transac_amount() < -(overdraft_allowance_ + credit_amount_)) {
            
        transac_.at(i).set_denied(true);
            
    } else {
            
        balance_ -= transac_.at(i).transac_amount();
            
        }
        
    }
    
} 

//Mutator, sets credit_amount to input argument
void GoldCard::set_credit_amount(double credit_amount) {
    
    credit_amount_ = credit_amount;
    
}

//Mutator, sets overdraft_allowance to input argument
void GoldCard::set_overdraft_allowance(double overdraft_allowance) {
    
    overdraft_allowance_ = overdraft_allowance;
    
}

//Mutator, sets rebate_ to the input argument 
void GoldCard::set_rebate(int rebate) {
    
    rebate_ = rebate;
    
}