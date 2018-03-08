/*
 * Name        : card.h
 * Author      : Jacob Pawek
 * Date        : 2-10-18
 * Description : Header File for Card class
 */

#ifndef CARD_H
#define CARD_H

#include "transac.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>
using std::setfill;
using std::setw;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

/*
 * Class Card.
 * A class that holds attributes of a credit card
 */
class Card
{
protected:
    string card_number_;
    char bank_type_;
    string first_name_;
    string last_name_;
    string card_type_;
    double balance_;
    vector<Transac> transacs_;
public:
    /*
     * Constructor
     * Sets every variable value to default unless argument is given.
     */
    Card();

    /*
     * Uses the Luhn Algorithm to determine if the card is valid or not and
     * returns 1 if the card is valid, otherwise returns 0.
     * @param string card_number - The card number to be checked for
     *                           - validity
     * @return bool - Whether or not the number is valid
     */
    bool LuhnValidityCheck();

    /*
     * Inspects first six digits of card number to determine which bank it
     * belongs to, and sets bank_type_ to the corresponding value (V for Visa, A
     * for American Express, D for Discover, M for Mastercard, or U for unknown).
     * @param string card_number - The card number of which to identify
     *                           - bank
     */
    void DetermineBankType(string card_number);
    
    /*
     * card_number_ Mutator
     * Sets card_number_ to the incoming string only if it is only filled
     * with digits, otherwise does nothing.
     * @param string card_number - the numeric card_number to set
     */
    void set_card_number(string card_number);

    /*
     * card_number_ Accessor
     * @return string - returns value of card_number_
     */
    string card_number();

    /*
     * bank_type_ Mutator
     * Sets bank_type_ to the incoming char only if it is either D, A, M, V,
     * or U.
     * @param char bank_type - the bank_type to be set
     */
    void set_bank_type(char bank_type);

    /*
     * bank_type_ Accessor
     * @return char - returns value of bank_type_
     */
    char bank_type();

    /*
     * first_name_ Mutator
     * Sets first_name_ to the incoming string.
     * @param string first_name - the first_name to be set
     */
    void set_first_name(string first_name);

    /*
     * first_name_ Accessor
     * @return string - returns value of first_name_
     */
    string first_name();

    /*
     * last_name_ Mutator
     * Sets last_name_ to the incoming string.
     * @param string last_name - the last_name to be set
     */
    void set_last_name(string last_name);

    /*
     * last_name_ Accessor
     * @return string - returns value of last_name_
     */
    string last_name();

    /*
     * card_type_ Mutator
     * Sets card_type_ to the incoming string, provided it is either "gold", "platinum", or "corporate"
     * @param string card_type - the card_type to be set
     */
    void set_card_type(string card_type);

    /*
     * card_type_ Accessor
     * @return string - returns value of card_type_
     */
    string card_type();

    /*
     * balance_ Mutator
     * Sets balance_ to the incoming double.
     * @param double balance - the balance to be set
     */
    void set_balance(double balance);

    /*
     * balance_ Accessor
     * @return double - returns value of balance_
     */
    double balance();

    /*
     * transactions_ Mutator
     * Sets transactions_ to the incoming double.
     * @param Transaction balance - the transactions vector to be set
     */
    void set_transactions(vector<Transacs> transac);
    
    /*
     * transactions_ Accessor
     * @return Transaction - returns vector of transactions
     */
    vector<Transac> transac();


};

#endif
