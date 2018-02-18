/*
 * Name        : transaction.cpp
 * Author      : Jacob Pawek
 * Date        : 2-15-18
 * Description : Function definitions for Transaction class
 */
 
 #include "transaction.h"
/*
 * Constructor
 * Sets every variable value to default unless argument is given.
 */
Transaction::Transaction() 
{
    denial_ = false;
}
 
 
/*
 * card_number_ Mutator
 * Sets card_number_ to the incoming string.
 * @param string card_number - the card_number to be set
 */
void Transaction::set_card_number(string card_number) 
{
    card_number_ = card_number;
}

/*
 * card_number_ Accessor
 * @return string - returns value of card_number_
 */
string Transaction::card_number() 
{
    return card_number_;
}

/*
 * date_ Mutator
 * Sets date_ to the incoming string.
 * @param string date - the date to be set
 */
void Transaction::set_date(string date) 
{
    date_ = date;
}

/*
 * date_ Accessor
 * @return string - returns value of date_
 */
string Transaction::date() 
{
    return date_;
}

/*
 * trans_number_ Mutator
 * Sets trans_number_ to the incoming string.
 * @param string trans_number - the trans_number to be set
 */
void Transaction::set_trans_number(string trans_number) 
{
    trans_number_ = trans_number;
}

/*
 * trans_number_ Accessor
 * @return string - returns value of trans_number_
 */
string Transaction::trans_number() 
{
    return trans_number_;
}

/*
 * vendor_ Mutator
 * Sets vendor_ to the incoming string.
 * @param string vendor - the vendor to be set
 */
void Transaction::set_vendor(string vendor) 
{
    vendor_ = vendor;
}

/*
 * vendor_ Accessor
 * @return string - returns value of vendor_
 */
string Transaction::vendor() 
{
    return vendor_;
}

/*
 * amount_ Mutator
 * Sets amount_ to the incoming double.
 * @param double amount - the amount to be set
 */
void Transaction::set_amount(double amount) 
{
    amount_ = amount;
}

/*
 * amount_ Accessor
 * @return double - returns value of amount_
 */
double Transaction::amount() 
{
    return amount_;
}

/*
 * denial_ Mutator
 * Sets denial_ to the incoming bool.
 * @param bool denial - the denial status to be set
 */
void Transaction::set_denial(bool denial) 
{
    denial_ = denial;
}

/*
 * denial_ Accessor
 * @return bool - returns value of denial_
 */
bool Transaction::denial() 
{
    return denial_;
}