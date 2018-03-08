/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           2/28
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Function definitions for Transac Class.
 */

#include "transac.h"

/*
 * Transac class
 * Holds info about a cards transactions.
 */
//Constructor, Sets all variables to defualt values unless argument is present
Transac::Transac() {
    
    card_num_ = "";
    date_ = "";
    transac_num_ = "";
    vendor_ = "";
    transac_amount_ = 0;
    denied_ = false;
    
}
// Accesor, reutrns the value of card_num_
string Transac::card_number() {
    
    return card_num_;
    
} 
//Accessor, returns the value of date_
string Transac::date() {
    
    return date_;
    
}
//Accesor, returns the value of transac_num_
string Transac::transac_num() {
    
    return transac_num_;
    
} 
 //Accessor, retruns the value of vendor_
string Transac::vendor() {
    
    return vendor_;
    
}
//Accessor, returns the value of amount_
double Transac::transac_amount() {
    
    return transac_amount_;
    
}
//Accessor, returns true/false value for denied_
bool Transac::denied() {
    
    return denied_;
    
} 
//Mutator, sets card_num_ to incoming argument
void Transac::set_card_number(string card_num) {
    
    card_num_ = card_num;
    
} 
//Mutator, sets date_ to incoming argument
void Transac::set_date(string date) {
    
    date_ = date;
    
} 
//Mutator, sets transac_num_ to incoming argument
void Transac::set_transac_num(string transac_num) {
    
    transac_num_ = transac_num;
    
}
//Mutator, sets vendor_ to incoming argument
void Transac::set_vendor(string vendor) {
    
    vendor_ =  vendor;
    
}
//Mutator, sets amount_ to incoming
void Transac::set_transac_amount(double amount) {
    
    transac_amount_ = amount;
    
}
//Mutator, sets denied value to incoming argument
void Transac::set_denied(bool denied) {
    
    denied_ = denied;
    
}
