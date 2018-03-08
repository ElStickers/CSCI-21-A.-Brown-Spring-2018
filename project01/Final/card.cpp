/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           2/28
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Function definitions fro the Card class.
 */

#include "card.h"

//constructor, sets all variables to a default unless argument is present
Card::Card() {

    card_number_ = "";
    first_name_ = "";
    last_name_ = "";
    card_type_ = "N/A";
    balance_ = 0;
    bank_ = 'U';
}
//Accessor, returns card_number_
string Card::card_number() {

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

vector<Transac>Card::transacs(){
    
    return transac_;
    
}

//Accessor, returns balance_
double Card::balance() {

    return balance_;

}
//Accessor, returns bank_
char Card::bank() {

    return bank_;

}
//Runs card number through luhn algorithm to check  its validity
bool Card::Luhn_Check() {
    string check = card_number_;

    int digits = check.size();

    int sum = 0, isSecond = false;

    for (int i = digits - 1; i >= 0; i--) {

        int d = check[i] - 'a';

        if (isSecond == true)
        {
            d = d * 2;
        }

        sum += d / 10;
        sum += d % 10;

        isSecond = !isSecond;

    }

    if (sum % 10 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}
//checks the digits of card to find bank origin
void Card::Check_Bank(string card_number) {
    
    switch (card_number.at(0)) {
        
        case '6':{
            
            if (card_number.find("6011") == 0 && card_number.size() == 16) {
                
                set_bank('D');
                
            } else if (card_number.find("65") == 0 && card_number.size() == 16) {
                
                set_bank('D');
                
            } else if (card_number.find("64") == 0 && card_number.size() == 16) {
                
                string check_three = "";
                
                for (int i = 0; i < 3; i++) {
                    
                     string temp;
                     
                     temp = card_number.at(i);
                     
                     check_three.append(temp);
                }
                int three;
                stringstream ss;
                ss << check_three;
                ss >> three;
                if (three >= 644 && three <= 649) {
                    set_bank('D');
                } else {
                    set_bank('U');
                }
            } else if (card_number.find("622") == 0 && card_number.size() == 16) {
                
                string check_six = "";
                
                for (int i = 0; i < 6; i++) {
                    
                    string temp;
                    
                    temp =  card_number.at(i);
                    
                    check_six.append(temp);
                }
                
                int six;
                stringstream ss;
                ss << check_six;
                ss >> six;
                
                if (six >= 622126 || six <= 622925) {
                    set_bank('D');
                } else {
                    set_bank('U');
                }
            
            } else {
                set_bank('U');
            }
        }
            break;
            
        case '5':{
        
            int two;
            stringstream ss;
            ss << card_number.at(1);
            ss >> two;
            if ((two >= 1 && two <= 5) && card_number.size() == 16) {
                set_bank('M');
            } else {
                set_bank('U');
            }
        }
            break;
            
        case '4':{
            
            if (card_number.size() >= 13 && card_number.size() <= 16) {
                set_bank('V');
            } else {
                set_bank('U');
            }
        }
            break;
            
        case '3':{
            
            if ((card_number.at(1) == '4' || card_number.at(1) == '7') && card_number.size() == 15) {
                set_bank('A');
            } else {
                set_bank('U');
            }
        }
            break;
            
        default:{
            set_bank('U');
        }
            break;
    }
}
//mutator, sets card_number_ to input if input isn't 0
void Card::set_card_number(string card_number){
    
    bool valid = 1;
    
    if (card_number != ""){
        
        for (int i = 0; i  < card_number.size(); i++){
            
            if (isdigit(card_number.at(i) == 0)){
                
            valid = 0;
        }
        if (valid == 1){
            card_number_ = card_number;
        }
    }
}
}

// mutator, sets first_name_ to input
void Card::set_first_name(string first_name) {
    
    first_name_ =  first_name;
    
}
// mutator, sets last_name_ to input
void Card::set_last_name(string last_name) {
    
    last_name_ = last_name;
    
}
// mutator, sets card_type_ to input
void Card::set_card_type(string card_type) {
    
    if(card_type == "gold" || card_type == "platinum" || card_type == "corporate") {
    
    card_type_ = card_type;
    
        
    }
    
}
//mutator, sets balance_ to input
void Card::set_balance(double balance) {
    
    balance_ = balance;
    
}
//mutator, sets bank_ to input
void Card::set_bank(char bank) {
    if (toupper(bank) == 'D' || 'M' || 'V' || 'A' || 'U') {
        bank_ = toupper(bank);
    }
    
}

void Card::set_transac(vector<Transac> transac) {
    
    transac_ = transac;
    
}
