/*
 * Name        : card.cpp
 * Author      : Jacob Pawek
 * Date        : 2-10-18
 * Description : Function definitions for Card class
 */

#include "card.h"

/*
 * Constructor
 * Sets every variable value default unless argument is given.
 */
Card::Card()
{
    //cout << "Default Card constructor called" << endl;
    card_number_ = "";
    bank_type_ = 'U';
    first_name_ = "";
    last_name_ = "";
    card_type_ = "";
    balance_ = 0;
}

/*
 * Uses the Luhn Algorithm to determine if the card is valid or not and
 * returns 1 if the card is valid, otherwise returns 0.
 * @param string card_number - The card number to be checked for
 *                           - validity
 * @return bool - Whether or not the number is valid
 */
bool Card::LuhnValidityCheck()
{
    string sum_number = card_number_;
    for (int i = card_number_.size() - 2; i >= 0; i -= 2)
    {
        int digit;
        {
            stringstream ss;
            ss << card_number_.at(i);
            ss >> digit;
        }
        char character;
        if (digit * 2 > 9)
        {
            {
                stringstream ss;
                ss << (digit * 2) - 9;
                ss >> character;
            }
            sum_number.at(i) = character;
        }
        else
        {
            {
                stringstream ss;
                ss << digit * 2;
                ss >> character;
            }
            sum_number.at(i) = character;
        }
    }
    int sum = 0;
    for (int i = 0; i <= card_number_.size() - 1; i++)
    {
        int digit;
        {
            stringstream ss;
            ss << sum_number.at(i);
            ss >> digit;
        }
        sum += digit;
    }
    if (sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
 * Inspects first six digits of card number to determine which bank it
 * belongs to, and sets bank_type_ to the corresponding value (V for Visa, A
 * for American Express, D for Discover, M for Mastercard, or U for unknown).
 * @param string card_number - The card number of which to identify
 *                           - bank
 */
void Card::DetermineBankType(string card_number)
{
    switch (card_number.at(0))
    {
    // Visa cards start with a 4
    case '4':
        // Visa cards are between 13 and 16 digits in length
        if (card_number.size() >= 13 && card_number.size() <= 16)
            set_bank_type('V');
        else
            set_bank_type('U');
        break;
    // American Express Cards start with 34 or 37
    case '3':
        // American Express cards are 15 digits in length
        if (card_number.at(1) == '4' || card_number.at(1) == '7' && card_number.size() == 15)
            set_bank_type('A');
        else
            set_bank_type('U');
        break;
    // Discover cards start with 6011, 622126 – 622925, 644 – 649, or 65
    case '6':
        // Check if the first four digits are 6011 and length is 16 digits
        if (card_number.find("6011") == 0 && card_number.size() == 16)
            set_bank_type('D');
        // Check if the first three digits are 622 and length is 16 digits
        else if (card_number.find("622") == 0 && card_number.size() == 16)
        {
            string first_six = "";
            for (int i = 0; i < 6; i++)
            {
                first_six += card_number.at(i);
            }
            int initial_six;
            // Plug string variable into stringstream to convert to integer
            {
                stringstream ss;
                ss << first_six;
                ss >> initial_six;
            }
            // Check if the first six digits fall into the range 622126 - 622925
            if (initial_six >= 622126 && initial_six <= 622925)
                set_bank_type('D');
            else
                set_bank_type('U');
        }
        // Check if the second digit is a 4 and langth is 16 digits
        else if (card_number.at(1) == '4' && card_number.size() == 16)
        {
            string first_three = "";
            for (int i = 0; i < 3; i++)
            {
                first_three += card_number.at(i);
            }
            int initial_three;
            // Plug string variable into stringstream to convert to integer
            {
                stringstream ss;
                ss << first_three;
                ss >> initial_three;
            }
            // Check if the first six digits fall into the range 644 - 649
            if (initial_three >= 644 && initial_three <= 649)
                set_bank_type('D');
            else
                set_bank_type('U');
        }
        // Check if the second digit is a 5 and length is 16 digits
        else if (card_number.at(1) == '5' && card_number.size() == 16)
            set_bank_type('D');
        else
            set_bank_type('U');
        break;
    // Master cards start with 51 - 55
    case '5':
        int second_digit;
        // Plug string variable into stringstream to convert to integer
        {
            stringstream ss;
            ss << card_number.at(1);
            ss >> second_digit;
        }
        // Check if the second digit falls into the range 1 - 5 and length is 16 digits
        if (second_digit >= 1 && second_digit <= 5 && card_number.size() == 16)
            set_bank_type('M');
        else
            set_bank_type('U');
        break;
    default:
        set_bank_type('U');
        break;
    }
}

/*
 * card_number_ Mutator
 * Sets card_number_ to the incoming string only if it is only filled
 * with exclusively digits, otherwise does nothing.
 * @param string card_number - the numeric card_number to set
 */
void Card::set_card_number(string card_number)
{
    if (card_number != "")
    {
        bool valid_num = 1;
        for (int i = 0; i < card_number.size(); i++)
        {
            if (isdigit(card_number.at(i)) == 0)
                valid_num = 0;
        }
        if (valid_num == 1)
            card_number_ = card_number;
    }
}

/*
 * card_number_ Accessor
 * @return string - returns value of card_number_
 */
string Card::card_number()
{
    return card_number_;
}

/*
 * bank_type_ Mutator
 * Sets bank_type_ to the incoming char only if it is either D, A, M, V,
 * or U.
 * @param char bank_type - the bank_type to be set
 */
void Card::set_bank_type(char bank_type)
{
    if (toupper(bank_type) == 'D' ||
            toupper(bank_type) == 'A' ||
            toupper(bank_type) == 'M' ||
            toupper(bank_type) == 'V' ||
            toupper(bank_type) == 'U')
        bank_type_ = bank_type;
}

/*
 * bank_type_ Accessor
 * @return char - returns value of bank_type_
 */
char Card::bank_type()
{
    return bank_type_;
}

/*
 * first_name_ Mutator
 * Sets first_name_ to the incoming string.
 * @param string first_name - the first_name to be set
 */
void Card::set_first_name(string first_name)
{
    first_name_ = first_name;
}

/*
 * first_name_ Accessor
 * @return string - returns value of first_name_
 */
string Card::first_name()
{
    return first_name_;
}

/*
 * last_name_ Mutator
 * Sets last_name_ to the incoming string.
 * @param string last_name - the last_name to be set
 */
void Card::set_last_name(string last_name)
{
    last_name_ = last_name;
}

/*
 * last_name_ Accessor
 * @return string - returns value of last_name_
 */
string Card::last_name()
{
    return last_name_;
}

/*
 * card_type_ Mutator
 * Sets card_type_ to the incoming string, provided it is either "gold", "platinum", or "corporate"
 * @param string card_type - the card_type to be set
 */
void Card::set_card_type(string card_type)
{
    if (card_type == "gold" || card_type == "platinum" || card_type == "corporate")
        card_type_ = card_type;
}

/*
 * card_type_ Accessor
 * @return string - returns value of card_type_
 */
string Card::card_type()
{
    return card_type_;
}

/*
 * balance_ Mutator
 * Sets balance_ to the incoming double.
 * @param double balance - the balance to be set
 */
void Card::set_balance(double balance)
{
    balance_ = balance;
}

/*
 * balance_ Accessor
 * @return double - returns value of balance_
 */
double Card::balance()
{
    return balance_;
}

/*
 * transactions_ Mutator
 * Sets transactions_ to the incoming double.
 * @param Transaction balance - the transactions vector to be set
 */
void Card::set_transactions(vector<Transaction> transactions) 
{
    transactions_ = transactions;
}

/*
 * transactions_ Accessor
 * @return Transaction - returns vector of transactions
 */
vector<Transaction> Card::transactions() 
{
    return transactions_;
}
