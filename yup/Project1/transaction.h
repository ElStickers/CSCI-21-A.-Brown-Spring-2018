/*
 * Name        : transaction.h
 * Author      : Jacob Pawek
 * Date        : 2-15-18
 * Description : Header File for Transaction class
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H


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
 * Class Transation.
 * A class that holds attributes of a credit card's transactions
 */
class Transaction {
public:
    /*
     * Constructor
     * Sets every variable value to default unless argument is given.
     */
    Transaction();
    
    /*
     * card_number_ Mutator
     * Sets card_number_ to the incoming string.
     * @param string card_number - the card_number to be set
     */
    void set_card_number(string card_number);
    
    /*
     * card_number_ Accessor
     * @return string - returns value of card_number_
     */
    string card_number();
    
    /*
     * date_ Mutator
     * Sets date_ to the incoming string.
     * @param string date - the date to be set
     */
    void set_date(string date);

    /*
     * date_ Accessor
     * @return string - returns value of date_
     */
    string date();
    
    /*
     * trans_number_ Mutator
     * Sets trans_number_ to the incoming string.
     * @param string trans_number - the trans_number to be set
     */
    void set_trans_number(string trans_number);

    /*
     * trans_number_ Accessor
     * @return string - returns value of trans_number_
     */
    string trans_number();
    
    /*
     * vendor_ Mutator
     * Sets vendor_ to the incoming string.
     * @param string vendor - the vendor to be set
     */
    void set_vendor(string vendor);

    /*
     * vendor_ Accessor
     * @return string - returns value of vendor_
     */
    string vendor();
    
    /*
     * amount_ Mutator
     * Sets amount_ to the incoming double.
     * @param double amount - the amount to be set
     */
    void set_amount(double amount);

    /*
     * amount_ Accessor
     * @return double - returns value of amount_
     */
    double amount();
    
    /*
     * denial_ Mutator
     * Sets denial_ to the incoming bool.
     * @param bool denial - the denial status to be set
     */
    void set_denial(bool denial);

    /*
     * denial_ Accessor
     * @return bool - returns value of denial_
     */
    bool denial();
private:
    string card_number_;
    string date_;
    string trans_number_;
    string vendor_;
    double amount_;
    bool denial_;
};

#endif