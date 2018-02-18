/*
 * Name        : gold.h
 * Author      : Jacob Pawek
 * Date        : 2-16-18
 * Description : Header File for Gold class
 */

#ifndef GOLD_H
#define GOLD_H

#include "transaction.h"
#include "card.h"
#include "platinum.h"
#include "corporate.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

/*
 * Class Gold.
 * A class that holds attributes of a gold credit card
 */
class Gold : public Card
{
public:
    /*
     * Constructor
     * Sets every variable value to default unless argument is given.
     */
    Gold();
    
    /*
     * Scans transaction vector to determine which are denied
     */
    void DetermineDenial();
    
    /*
     * credit_line_ Mutator
     * Sets credit_line_ to the incoming double.
     * @param double credit_line - the credit_line to be set
     */
    void set_credit_line(double credit_line);

    /*
     * credit_line_ Accessor
     * @return double - returns value of credit_line_
     */
    double credit_line();

    /*
     * overdraft_allowance_ Mutator
     * Sets overdraft_allowance_ to the incoming double.
     * @param double overdraft_allowance - the overdraft allowance to be set
     */
    void set_overdraft_allowance(double overdraft_allowance);

    /*
     * overdraft_allowance_ Accessor
     * @return double - returns value of overdraft_allowance_
     */
    double overdraft_allowance();

    /*
     * rebate_ Mutator
     * Sets rebate_ to the incoming int.
     * @param int rebate - the rebate to be set
     */
    void set_rebate(int rebate);

    /*
     * rebate_ Accessor
     * @return int - returns value of rebate_
     */
    int rebate();
private:
    double credit_line_;
    double overdraft_allowance_;
    int rebate_;
};


#endif