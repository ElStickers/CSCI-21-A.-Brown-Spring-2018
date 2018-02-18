/*
 * Name        : platinum.cpp
 * Author      : Jacob Pawek
 * Date        : 2-16-18
 * Description : Function definitions for Platinum class
 */

#include "platinum.h"

/*
 * Constructor
 * Sets every variable value default unless argument is given.
 */
Platinum::Platinum()
{
    //cout << "Default Platinum constructor called" << endl;
    credit_line_ = 5000;
    overdraft_allowance_ = 1000;
    rebate_ = 2;
}

/*
 * Scans transaction vector to determine which are denied
 */
void Platinum::DetermineDenial()
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
void Platinum::set_credit_line(double credit_line)
{
    credit_line_ = credit_line;
}

/*
 * credit_line_ Accessor
 * @return double - returns value of credit_line_
 */
double Platinum::credit_line()
{
    return credit_line_;
}

/*
 * overdraft_allowance_ Mutator
 * Sets overdraft_allowance_ to the incoming double.
 * @param double overdraft_allowance - the overdraft allowance to be set
 */
void Platinum::set_overdraft_allowance(double overdraft_allowance)
{
    overdraft_allowance_ = overdraft_allowance;
}

/*
 * overdraft_allowance_ Accessor
 * @return double - returns value of overdraft_allowance_
 */
double Platinum::overdraft_allowance()
{
    return overdraft_allowance_;
}

/*
 * rebate_ Mutator
 * Sets rebate_ to the incoming int.
 * @param int rebate - the rebate to be set
 */
void Platinum::set_rebate(int rebate)
{
    rebate_ = rebate;
}

/*
 * rebate_ Accessor
 * @return int - returns value of rebate_
 */
int Platinum::rebate()
{
    return rebate_;
}