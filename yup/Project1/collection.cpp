/*
 * Name        : collection.cpp
 * Author      : Jacob Pawek
 * Date        : 2-10-18
 * Description : Function definitions for Collection class
 */

#include "collection.h"
#include "card.h"
#include "transaction.h"

/*
 * Constructor
 * Sets collection_ pointer to null value
 */
Collection::Collection()
{
    //cout << "Default Collection constructor called" << endl;
    gold_collection_.resize(1);
    plat_collection_.resize(1);
    corp_collection_.resize(1);
}

/*
 * Outputs all denied transactions along with reason for denial
 */
void Collection::DenialStatement(string filename)
{
    for (int i = 0; i < gold_collection_.size(); i++)
    {
        cout << "Denied Transactions for Card Number: " << gold_collection_.at(i).card_number() << endl;
        cout << "Account Holder: " << gold_collection_.at(i).last_name() << ", " << gold_collection_.at(i).first_name() << endl;
        cout << setfill('=') << setw(55) << " " << endl;
        gold_collection_.at(i).DetermineDenial();
        for (int trans_i = 0; trans_i < gold_collection_.at(i).transactions().size(); trans_i++)
        {
            if (gold_collection_.at(i).transactions().at(trans_i).denial() == true)
            {
                cout << endl;
                cout << "Date: " << gold_collection_.at(i).transactions().at(trans_i).date() << endl;
                cout << "Transaction Number: " << gold_collection_.at(i).transactions().at(trans_i).trans_number() << endl;
                cout << "Vendor: " << gold_collection_.at(i).transactions().at(trans_i).vendor() << endl;
                cout << "Amount: $" << fixed << setprecision(2) << gold_collection_.at(i).transactions().at(trans_i).amount() << endl;
                cout << "Reason for Denial: Transaction exceeds overdraft allowance by $" 
                     <<  gold_collection_.at(i).transactions().at(trans_i).amount() - (gold_collection_.at(i).credit_line() + gold_collection_.at(i).overdraft_allowance() + gold_collection_.at(i).balance()) << endl << endl;
            }
        }
        cout << setfill('=') << setw(55) << " " << endl << endl;
    }
    
    for (int i = 0; i < plat_collection_.size(); i++)
    {
        cout << "Denied Transactions for Card Number: " << plat_collection_.at(i).card_number() << endl;
        cout << "Account Holder: " << plat_collection_.at(i).last_name() << ", " << plat_collection_.at(i).first_name() << endl;
        cout << setfill('=') << setw(55) << " " << endl;
        plat_collection_.at(i).DetermineDenial();
        for (int trans_i = 0; trans_i < plat_collection_.at(i).transactions().size(); trans_i++)
        {
            if (plat_collection_.at(i).transactions().at(trans_i).denial() == true)
            {
                cout << endl;
                cout << "Date: " << plat_collection_.at(i).transactions().at(trans_i).date() << endl;
                cout << "Transaction Number: " << plat_collection_.at(i).transactions().at(trans_i).trans_number() << endl;
                cout << "Vendor: " << plat_collection_.at(i).transactions().at(trans_i).vendor() << endl;
                cout << "Amount: $" << fixed << setprecision(2) << plat_collection_.at(i).transactions().at(trans_i).amount() << endl;
                cout << "Reason for Denial: Transaction exceeds overdraft allowance by $" 
                     <<  plat_collection_.at(i).transactions().at(trans_i).amount() - (plat_collection_.at(i).credit_line() + plat_collection_.at(i).overdraft_allowance() + plat_collection_.at(i).balance()) << endl << endl;
            }
        }
        cout << setfill('=') << setw(55) << " " << endl << endl;
    }
    
    for (int i = 0; i < corp_collection_.size(); i++)
    {
        cout << "Denied Transactions for Card Number: " << corp_collection_.at(i).card_number() << endl;
        cout << "Account Holder: " << corp_collection_.at(i).last_name() << ", " << corp_collection_.at(i).first_name() << endl;
        cout << setfill('=') << setw(55) << " " << endl;
        corp_collection_.at(i).DetermineDenial();
        for (int trans_i = 0; trans_i < corp_collection_.at(i).transactions().size(); trans_i++)
        {
            if (corp_collection_.at(i).transactions().at(trans_i).denial() == true)
            {
                cout << endl;
                cout << "Date: " << corp_collection_.at(i).transactions().at(trans_i).date() << endl;
                cout << "Transaction Number: " << corp_collection_.at(i).transactions().at(trans_i).trans_number() << endl;
                cout << "Vendor: " << corp_collection_.at(i).transactions().at(trans_i).vendor() << endl;
                cout << "Amount: $" << fixed << setprecision(2) << corp_collection_.at(i).transactions().at(trans_i).amount() << endl;
                cout << "Reason for Denial: Transaction exceeds overdraft allowance by $" 
                     <<  corp_collection_.at(i).transactions().at(trans_i).amount() - (corp_collection_.at(i).credit_line() + corp_collection_.at(i).overdraft_allowance() + corp_collection_.at(i).balance()) << endl << endl;
            }
        }
        cout << setfill('=') << setw(55) << " " << endl << endl;
    }
}

/*
 * Outputs necessary information about cards in collection
 */
void Collection::MonthlyStatement() 
{
    cout << "What type of card would you like to access?" << endl;
    cout << "(1) - Gold" << endl;
    cout << "(2) - Platinum" << endl;
    cout << "(3) - Corporate" << endl;
    cout << endl << "Selection: ";
    int type_choice;
    cin >> type_choice;
    
    cout << "Which account would you like to access?" << endl;
    if (type_choice == 1)
    {
        for (int i = 0; i < gold_collection_.size(); i++)
        {
            cout << "(" << i + 1 << ") - " << setw(16) << setfill(' ') << gold_collection_.at(i).card_number() << " - " << gold_collection_.at(i).last_name() << ", " << gold_collection_.at(i).first_name() << endl;
        }
    }
    if (type_choice == 2)
    {
        for (int i = 0; i < plat_collection_.size(); i++)
        {
            cout << "(" << i + 1 << ") - " << setw(16) << setfill(' ')  << plat_collection_.at(i).card_number() << " - " << plat_collection_.at(i).last_name() << ", " << plat_collection_.at(i).first_name() << endl;
        }
    }
    if (type_choice == 3)
    {
        for (int i = 0; i < corp_collection_.size(); i++)
        {
            cout << "(" << i + 1 << ") - " << setw(16) << setfill(' ')  << corp_collection_.at(i).card_number() << " - " << corp_collection_.at(i).last_name() << ", " << corp_collection_.at(i).first_name() << endl;
        }
    }
    cout << endl << "Selection: ";
    int choice;
    cin >> choice;
    choice--;

    cout << "Which month would you like to view?" << endl;
    cout << " (1) - January" << endl;
    cout << " (2) - February" << endl;
    cout << " (3) - March" << endl;
    cout << " (4) - April" << endl;
    cout << " (5) - May" << endl;
    cout << " (6) - June" << endl;
    cout << " (7) - July" << endl;
    cout << " (8) - August" << endl;
    cout << " (9) - September" << endl;
    cout << "(10) - October" << endl;
    cout << "(11) - November" << endl;
    cout << "(12) - December" << endl;
    cout << "(13) - Full Transaction History" << endl;
    
    cout << endl << "Selection: ";
    int month_choice;
    cin >> month_choice;
    string month_choice_name;
    switch (month_choice)
    {
        case 1:
            month_choice_name = "January";
            break;
        case 2:
            month_choice_name = "February";
            break;
        case 3:
            month_choice_name = "March";
            break;
        case 4:
            month_choice_name = "April";
            break;
        case 5:
            month_choice_name = "May";
            break;
        case 6:
            month_choice_name = "June";
            break;
        case 7:
            month_choice_name = "July";
            break;
        case 8:
            month_choice_name = "August";
            break;
        case 9:
            month_choice_name = "September";
            break;
        case 10:
            month_choice_name = "October";
            break;
        case 11:
            month_choice_name = "November";
            break;
        case 12:
            month_choice_name = "December";
            break;
    }
    
    switch (type_choice)
    {
        case 1: 
            if (month_choice != 13)
                cout << "Showing bill for month: " << month_choice_name << endl;
            cout << "Account: " << gold_collection_.at(choice).card_number() << endl;
            cout << setfill('=') << setw(18) << "" << "Transaction History" << setw(18) << "" << endl << endl;
            gold_collection_.at(choice).DetermineDenial();
            for (int i = 0; i < gold_collection_.at(choice).transactions().size(); i++)
            {
                stringstream ss;
                ss << gold_collection_.at(choice).transactions().at(i).date().at(0) << gold_collection_.at(choice).transactions().at(i).date().at(1);
                int month_of_trans;
                ss >> month_of_trans;
                if (month_of_trans == month_choice || month_choice == 13)
                {
                    cout << "Date: " << gold_collection_.at(choice).transactions().at(i).date() << endl;
                    cout << "Transaction Number: " << gold_collection_.at(choice).transactions().at(i).trans_number() << endl;
                    cout << "Vendor: " << gold_collection_.at(choice).transactions().at(i).vendor() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << gold_collection_.at(choice).transactions().at(i).amount() << endl;
                    if (gold_collection_.at(choice).transactions().at(i).denial())
                        cout << "Transaction Denied. Overdraft limit of $" << gold_collection_.at(choice).overdraft_allowance() << " exceeded" << endl;
                    cout << endl;
                }
            }
            cout << setfill('=') << setw(56) << " " << endl << endl;
            cout << "Current Card Balance (before rebate): $" << fixed << setprecision(2) << gold_collection_.at(choice).balance() << endl;
            cout << "Rebate: " << gold_collection_.at(choice).rebate() << "%" << endl;
            cout << "Current Rebate Value: $" << -gold_collection_.at(choice).balance() * (gold_collection_.at(choice).rebate() / 100.0) << endl;
            cout << "Current Card Balance (after rebate): $" << gold_collection_.at(choice).balance() + (-gold_collection_.at(choice).balance() * (gold_collection_.at(choice).rebate() / 100.0)) << endl;
            if (-(gold_collection_.at(choice).balance() + (-gold_collection_.at(choice).balance() * (gold_collection_.at(choice).rebate() / 100.0))) > gold_collection_.at(choice).credit_line())
                cout << "Warning: This account is overdrafted in the amount of $" << (gold_collection_.at(choice).balance() + (-gold_collection_.at(choice).balance() * (gold_collection_.at(choice).rebate() / 100.0))) + gold_collection_.at(choice).credit_line() << endl;
            break;
        case 2:
            if (month_choice != 13)
                cout << "Showing bill for month: " << month_choice_name << endl;
            cout << "Account: " << plat_collection_.at(choice).card_number() << endl;
            cout << setfill('=') << setw(18) << "" << "Transaction History" << setw(18) << "" << endl << endl;
            plat_collection_.at(choice).DetermineDenial();
            for (int i = 0; i < plat_collection_.at(choice).transactions().size(); i++)
            {
                stringstream ss;
                ss << plat_collection_.at(choice).transactions().at(i).date().at(0) << plat_collection_.at(choice).transactions().at(i).date().at(1);
                int month_of_trans;
                ss >> month_of_trans;
                if (month_of_trans == month_choice || month_choice == 13)
                {
                    cout << "Date: " << plat_collection_.at(choice).transactions().at(i).date() << endl;
                    cout << "Transaction Number: " << plat_collection_.at(choice).transactions().at(i).trans_number() << endl;
                    cout << "Vendor: " << plat_collection_.at(choice).transactions().at(i).vendor() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << plat_collection_.at(choice).transactions().at(i).amount() << endl;
                    if (plat_collection_.at(choice).transactions().at(i).denial())
                        cout << "Transaction Denied. Overdraft limit of $" << plat_collection_.at(choice).overdraft_allowance() << " exceeded" << endl;
                    cout << endl;
                }
            }
            cout << setfill('=') << setw(56) << " " << endl << endl;
            cout << "Current Card Balance (before rebate): $" << fixed << setprecision(2) << plat_collection_.at(choice).balance() << endl;
            cout << "Rebate: " << plat_collection_.at(choice).rebate() << "%" << endl;
            cout << "Current Rebate Value: $" << -plat_collection_.at(choice).balance() * (plat_collection_.at(choice).rebate() / 100.0) << endl;
            cout << "Current Card Balance (after rebate): $" << plat_collection_.at(choice).balance() + (-plat_collection_.at(choice).balance() * (plat_collection_.at(choice).rebate() / 100.0)) << endl;
            if (-(plat_collection_.at(choice).balance() + (-plat_collection_.at(choice).balance() * (plat_collection_.at(choice).rebate() / 100.0))) > plat_collection_.at(choice).credit_line())
                cout << "Warning: This account is overdrafted in the amount of $" << (plat_collection_.at(choice).balance() + (-plat_collection_.at(choice).balance() * (plat_collection_.at(choice).rebate() / 100.0))) + plat_collection_.at(choice).credit_line() << endl;
            break;
        case 3:
            if (month_choice != 13)
                cout << "Showing bill for month: " << month_choice_name << endl;
            cout << "Account: " << corp_collection_.at(choice).card_number() << endl;
            cout << setfill('=') << setw(18) << "" << "Transaction History" << setw(18) << "" << endl << endl;
            corp_collection_.at(choice).DetermineDenial();
            for (int i = 0; i < corp_collection_.at(choice).transactions().size(); i++)
            {
                stringstream ss;
                ss << corp_collection_.at(choice).transactions().at(i).date().at(0) << corp_collection_.at(choice).transactions().at(i).date().at(1);
                int month_of_trans;
                ss >> month_of_trans;
                if (month_of_trans == month_choice || month_choice == 13)
                {
                    cout << "Date: " << corp_collection_.at(choice).transactions().at(i).date() << endl;
                    cout << "Transaction Number: " << corp_collection_.at(choice).transactions().at(i).trans_number() << endl;
                    cout << "Vendor: " << corp_collection_.at(choice).transactions().at(i).vendor() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << corp_collection_.at(choice).transactions().at(i).amount() << endl;
                    if (corp_collection_.at(choice).transactions().at(i).denial())
                        cout << "Transaction Denied. Overdraft limit of $" << corp_collection_.at(choice).overdraft_allowance() << " exceeded" << endl;
                    cout << endl;
                }
            }
            cout << setfill('=') << setw(56) << " " << endl << endl;
            cout << "Current Card Balance (before rebate): $" << fixed << setprecision(2) << corp_collection_.at(choice).balance() << endl;
            cout << "Rebate: " << corp_collection_.at(choice).rebate() << "%" << endl;
            cout << "Current Rebate Value: $" << -corp_collection_.at(choice).balance() * (corp_collection_.at(choice).rebate() / 100.0) << endl;
            cout << "Current Card Balance (after rebate): $" << corp_collection_.at(choice).balance() + (-corp_collection_.at(choice).balance() * (corp_collection_.at(choice).rebate() / 100.0)) << endl;
            if (-(corp_collection_.at(choice).balance() + (-corp_collection_.at(choice).balance() * (corp_collection_.at(choice).rebate() / 100.0))) > corp_collection_.at(choice).credit_line())
                cout << "Warning: This account is overdrafted in the amount of $" << (corp_collection_.at(choice).balance() + (-corp_collection_.at(choice).balance() * (corp_collection_.at(choice).rebate() / 100.0))) + corp_collection_.at(choice).credit_line() << endl;
            break;
    }
}

/*
 * Scans input file, placing information into each Card index.
 * Continues resizing collection_ vector until end of file is reached.
 * Sets quantity_ to final size of collection_ vector.
 * @param string filename1 - The first file from which to draw information for each card object
 * @param string filename2 - The second file from which to draw information for each transaction object
 */
void Collection::FillVectors(string filename1, string filename2)
{
    ifstream fin;
    ifstream filein;
    fin.open(filename1);
    int gold_i = 0;
    int plat_i = 0;
    int corp_i = 0;
    while (!fin.eof())
    {
        string temp;
        getline(fin, temp);
        stringstream ss(temp);
        string temp_card_number, temp_first_name, temp_last_name, temp_type;
        char dash;
        double temp_balance;
        ss >> temp_card_number;
        ss >> temp_first_name;
        ss >> temp_last_name;
        ss >> temp_type;
        ss >> dash;
        ss >> temp_balance;
        vector<Transaction> temp_trans;
        filein.open(filename2);
        while (!filein.eof())
        {
            string temp_card_num, temp_date, temp_trans_num, temp_vendor, temp_price;
            double temp_amount;
            Transaction temp;
            getline(filein, temp_card_num, ':');
            getline(filein, temp_date, ':');
            getline(filein, temp_trans_num, ':');
            getline(filein, temp_vendor, ':');
            getline(filein, temp_price);
            stringstream ss(temp_price);
            ss >> temp_amount;
            if (temp_card_num == temp_card_number)
            {
                temp.set_card_number(temp_card_num);
                temp.set_date(temp_date);
                temp.set_trans_number(temp_trans_num);
                temp.set_vendor(temp_vendor);
                temp.set_amount(temp_amount);
                temp_trans.push_back(temp);
            }
        }
        filein.close();
        if (temp_type == "gold")
        {
            gold_collection_.at(gold_i).set_card_number(temp_card_number);
            gold_collection_.at(gold_i).set_first_name(temp_first_name);
            gold_collection_.at(gold_i).set_last_name(temp_last_name);
            gold_collection_.at(gold_i).set_card_type(temp_type);
            gold_collection_.at(gold_i).set_balance(temp_balance);
            gold_collection_.at(gold_i).DetermineBankType(gold_collection_.at(gold_i).card_number());
            gold_collection_.at(gold_i).set_transactions(temp_trans);
            gold_collection_.resize(gold_collection_.size() + 1);
            gold_i++;
        }
        if (temp_type == "platinum")
        {
            plat_collection_.at(plat_i).set_card_number(temp_card_number);
            plat_collection_.at(plat_i).set_first_name(temp_first_name);
            plat_collection_.at(plat_i).set_last_name(temp_last_name);
            plat_collection_.at(plat_i).set_card_type(temp_type);
            plat_collection_.at(plat_i).set_balance(temp_balance);
            plat_collection_.at(plat_i).DetermineBankType(plat_collection_.at(plat_i).card_number());
            plat_collection_.at(plat_i).set_transactions(temp_trans);
            plat_collection_.resize(plat_collection_.size() + 1);
            plat_i++;
        }
        if (temp_type == "corporate")
        {
            corp_collection_.at(corp_i).set_card_number(temp_card_number);
            corp_collection_.at(corp_i).set_first_name(temp_first_name);
            corp_collection_.at(corp_i).set_last_name(temp_last_name);
            corp_collection_.at(corp_i).set_card_type(temp_type);
            corp_collection_.at(corp_i).set_balance(temp_balance);
            corp_collection_.at(corp_i).DetermineBankType(corp_collection_.at(corp_i).card_number());
            corp_collection_.at(corp_i).set_transactions(temp_trans);
            corp_collection_.resize(corp_collection_.size() + 1);
            corp_i++;
        }
    }
    gold_collection_.pop_back();
    plat_collection_.pop_back();
    corp_collection_.pop_back();
    fin.close();
}

/*
 * gold_collection_ Accessor
 * @return vector<Gold> - returns vector
 */
vector<Gold> Collection::gold_collection()
{
    return gold_collection_;
}

/*
 * plat_collection_ Accessor
 * @return vector<Platinum> - returns vector
 */
vector<Platinum> Collection::plat_collection()
{
    return plat_collection_;
}

/*
 * corp_collection_ Accessor
 * @return vector<Corporate> - returns vector
 */
vector<Corporate> Collection::corp_collection()
{
    return corp_collection_;
}
