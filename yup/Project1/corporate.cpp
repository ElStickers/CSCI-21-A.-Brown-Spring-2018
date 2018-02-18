/*
 * Name        : corporate.cpp
 * Author      : Jacob Pawek
 * Date        : 2-16-18
 * Description : Function definitions for Corporate class
 */

#include "corporate.h"

/*
 * Corporate
 * Sets every variable value default unless argument is given.
 */
Corporate::Corporate()
{
    //cout << "Default Corporate constructor called" << endl;
    credit_line_ = 10000;
    overdraft_allowance_ = 5000;
    rebate_ = 5;
}

/*
 * Scans transaction vector to determine which are denied
 */
void Corporate::DetermineDenial()
{
    for (int i = 0; i < transactions_.size(); i++) 
    {
        if (balance_ - transactions_.at(i).amount() < -(overdraft_allowance_ + credit_line_))
        {
            transactions_.at(i).set_denial(true);
        }
        else
        {
            balance_ -= transactions_.at(i).amount();
        }
    }
}

/*
 * credit_line_ Mutator
 * Sets credit_line_ to the incoming double.
 * @param double credit_line - the credit_line to be set
 */
void Corporate::set_credit_line(double credit_line)
{
    credit_line_ = credit_line;
}

/*
 * credit_line_ Accessor
 * @return double - returns value of credit_line_
 */
double Corporate::credit_line()
{
    return credit_line_;
}

/*
 * overdraft_allowance_ Mutator
 * Sets overdraft_allowance_ to the incoming double.
 * @param double overdraft_allowance - the overdraft allowance to be set
 */
void Corporate::set_overdraft_allowance(double overdraft_allowance)
{
    overdraft_allowance_ = overdraft_allowance;
}

/*
 * overdraft_allowance_ Accessor
 * @return double - returns value of overdraft_allowance_
 */
double Corporate::overdraft_allowance()
{
    return overdraft_allowance_;
}

/*
 * rebate_ Mutator
 * Sets rebate_ to the incoming int.
 * @param int rebate - the rebate to be set
 */
void Corporate::set_rebate(int rebate)
{
    rebate_ = rebate;
}

/*
 * rebate_ Accessor
 * @return int - returns value of rebate_
 */
int Corporate::rebate()
{
    return rebate_;
}