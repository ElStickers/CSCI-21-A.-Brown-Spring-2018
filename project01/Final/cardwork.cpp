/*
 * Name        : card_work.cpp
 * Author      : Juan Palos
 * Date        : 2-10-18
 * Description : Function definitions for CardWork class
 */

#include "cardwork.h"
#include "card.h"
#include "transac.h"

CardWork::CardWork(){
    
    gold_vec_.resize(1);
    plat_vec_.resize(1);
    corp_vec_.resize(1);
    
}

void CardWork::Populate(string cards, string transacs) {
    
    ifstream fin1(cards);
    
    ifstream fin2(transacs);
    
    if (fin1.fail() || fin2.fail()){
    
        cout << "Error opening one of the files.\nPlease make sure the names match the file names.\n";
    
        cout << cards << " " << transacs << endl;
    
        exit(1);
    }
    
    string temp;
    
    int gold = 0;
    
    int plat = 0;
    
    int corp = 0;
    
    while (!fin1.eof()) {
        
        string line;
    
        getline(fin1, temp);
    
        stringstream ss(temp);
    
        string temp_credit_num, temp_first_name, temp_last_name, temp_type;
    
        char dash;
    
        double temp_bal;
    
        ss >> temp_credit_num;
    
        ss >> temp_first_name;
    
        ss >> temp_last_name;
    
        ss >> temp_type;
    
        ss >> dash;
    
        ss >> temp_bal;
    
        vector<Transac> temp_trans;
        
        while (!fin2.eof()) {
            
            string temp_card_number, temp_date, temp_trans_num, temp_vendor, temp_price;
            
            double temp_amount;
            
            Transac temp;
            
            getline(fin2, temp_card_number, ':');
            
            getline(fin2, temp_date, ':');
            
            getline(fin2, temp_trans_num, ':');
            
            getline(fin2, temp_vendor, ':');
            
            getline(fin2, temp_price);
            
            stringstream ss(temp_price);
            
            ss >> temp_amount;
            
            if (temp_card_number == temp_credit_num) {
                
                temp.set_card_number(temp_card_number);
                
                temp.set_date(temp_date);
                
                temp.set_transac_num(temp_trans_num);
                
                temp.set_vendor(temp_vendor);
                
                temp.set_transac_amount(temp_amount);
                
                temp_trans.push_back(temp);
            }            
            
        }
        fin2.close();
        if (temp_type == "gold")
        {
            gold_vec_.at(gold).set_card_number(temp_credit_num);
            gold_vec_.at(gold).set_first_name(temp_first_name);
            gold_vec_.at(gold).set_last_name(temp_last_name);
            gold_vec_.at(gold).set_card_type(temp_type);
            gold_vec_.at(gold).set_balance(temp_bal);
            gold_vec_.at(gold).Check_Bank(gold_vec_.at(gold).card_number());
            gold_vec_.at(gold).set_transac(temp_trans);
            gold_vec_.resize(gold_vec_.size() + 1);
            gold++;
        }
        if (temp_type == "platinum")
        {
            plat_vec_.at(plat).set_card_number(temp_credit_num);
            plat_vec_.at(plat).set_first_name(temp_first_name);
            plat_vec_.at(plat).set_last_name(temp_last_name);
            plat_vec_.at(plat).set_card_type(temp_type);
            plat_vec_.at(plat).set_balance(temp_bal);
            plat_vec_.at(plat).Check_Bank(plat_vec_.at(plat).card_number());
            plat_vec_.at(plat).set_transac(temp_trans);
            plat_vec_.resize(plat_vec_.size() + 1);
            plat++;
        }
        if (temp_type == "corporate")
        {
            corp_vec_.at(corp).set_card_number(temp_credit_num);
            corp_vec_.at(corp).set_first_name(temp_first_name);
            corp_vec_.at(corp).set_last_name(temp_last_name);
            corp_vec_.at(corp).set_card_type(temp_type);
            corp_vec_.at(corp).set_balance(temp_bal);
            corp_vec_.at(corp).Check_Bank(corp_vec_.at(corp).card_number());
            corp_vec_.at(corp).set_transac(temp_trans);
            corp_vec_.resize(corp_vec_.size() + 1);
            corp++;
        }
    }
    gold_vec_.pop_back();
    plat_vec_.pop_back();
    corp_vec_.pop_back();
    fin1.close();
}

void CardWork::CheckDenied(string transacsfile) {
    
for (int i = 0; i < gold_vec_.size(); i++) {
        
        cout << "Denied transactions for Card Number: " << gold_vec_.at(i).card_number() << endl;
        
        cout << "Account Holder: " << gold_vec_.at(i).first_name() << gold_vec_.at(i).last_name() << endl;
        
        //cout << setfill('=') << setw(55) << " " << endl;
        
        gold_vec_.at(i).CheckDenied();
        
        for (int trans_i = 0; trans_i < gold_vec_.at(i).transacs().size(); trans_i++) {
            
            if (gold_vec_.at(i).transacs().at(trans_i).denied() == true) {
                
                cout << endl;
                
                cout << "Date: " << gold_vec_.at(i).transacs().at(trans_i).date() << endl;
                
                cout << "Transacstion Number: " << gold_vec_.at(i).transacs().at(trans_i).transac_num() << endl;
                
                cout << "Vendor: " << gold_vec_.at(i).transacs().at(trans_i).vendor() << endl;
                
                cout << "Amount: $" << fixed << setprecision(2) << gold_vec_.at(i).transacs().at(trans_i).transac_amount() << endl;
                
                cout << "Reason for denied: Transacstion exceeds overdraft allowance by $" 
                
                     <<  gold_vec_.at(i).transacs().at(trans_i).transac_amount() - (gold_vec_.at(i).credit_amount() + gold_vec_.at(i).overdraft_allowance() + gold_vec_.at(i).balance()) << endl << endl;
            }
        
        }
        
        cout << setfill('/') << setw(55) << " " << endl << endl;
    }
    
    for (int i = 0; i < plat_vec_.size(); i++) {
        
        cout << "Denied transactions for Card Number: " << plat_vec_.at(i).card_number() << endl;
        
        cout << "Account Holder: " << plat_vec_.at(i).first_name() << plat_vec_.at(i).last_name() << endl;
        
        cout << setfill('/') << setw(55) << " " << endl;
        
        plat_vec_.at(i).CheckDenied();
        
        for (int trans_i = 0; trans_i < plat_vec_.at(i).transacs().size(); trans_i++) {
            
            if (plat_vec_.at(i).transacs().at(trans_i).denied() == true) {
                
                cout << endl;
                
                cout << "Date: " << plat_vec_.at(i).transacs().at(trans_i).date() << endl;
                
                cout << "Transacstion Number: " << plat_vec_.at(i).transacs().at(trans_i).transac_num() << endl;
                
                cout << "Vendor: " << plat_vec_.at(i).transacs().at(trans_i).vendor() << endl;
                
                cout << "Amount: $" << fixed << setprecision(2) << plat_vec_.at(i).transacs().at(trans_i).transac_amount() << endl;
                
                cout << "Reason for denied: Transacstion exceeds overdraft allowance by $" 
                
                     <<  plat_vec_.at(i).transacs().at(trans_i).transac_amount() - (plat_vec_.at(i).credit_amount() + plat_vec_.at(i).overdraft_allowance() + plat_vec_.at(i).balance()) << endl << endl;
            }
        }
        
        cout << setfill('=') << setw(55) << " " << endl << endl;
    }
    
    for (int i = 0; i < corp_vec_.size(); i++) {
        
        cout << "Denied Transactions for Card Number: " << corp_vec_.at(i).card_number() << endl;
        
        cout << "Account Holder: " << corp_vec_.at(i).first_name() << corp_vec_.at(i).last_name() << endl;
        
        cout << setfill('/') << setw(55) << " " << endl;
        
        corp_vec_.at(i).CheckDenied();
        
        for (int trans_i = 0; trans_i < corp_vec_.at(i).transacs().size(); trans_i++) {
            
            if (corp_vec_.at(i).transacs().at(trans_i).denied() == true) {
                
                cout << endl;
                
                cout << "Date: " << corp_vec_.at(i).transacs().at(trans_i).date() << endl;
                
                cout << "Transacstion Number: " << corp_vec_.at(i).transacs().at(trans_i).transac_num() << endl;
                
                cout << "Vendor: " << corp_vec_.at(i).transacs().at(trans_i).vendor() << endl;
                
                cout << "Amount: $" << fixed << setprecision(2) << corp_vec_.at(i).transacs().at(trans_i).transac_amount() << endl;
                
                cout << "Reason for denied: Transacstion exceeds overdraft allowance by $" 
                
                     <<  corp_vec_.at(i).transacs().at(trans_i).transac_amount() - (corp_vec_.at(i).credit_amount() + corp_vec_.at(i).overdraft_allowance() + corp_vec_.at(i).balance()) << endl << endl;
            }
        }
        
        cout << setfill('/') << setw(55) << " " << endl << endl;
    }
    
}

void CardWork::MonthlyStatement() 
{
    cout << "Which card type would you like to see?" << endl;
    cout << "(1) - Gold" << endl;
    cout << "(2) - Platinum" << endl;
    cout << "(3) - Corporate" << endl;
    cout << endl << "Selection: ";
    int type_choice;
    cin >> type_choice;
    
    cout << "Which account would you like to view?" << endl;
    if (type_choice == 1)
    {
        for (int i = 0; i < gold_vec_.size(); i++)
        {
            cout << "(" << i + 1 << ") - " << setw(16) << setfill(' ') << gold_vec_.at(i).card_number() << " - " << gold_vec_.at(i).last_name() << ", " << gold_vec_.at(i).first_name() << endl;
        }
    }
    if (type_choice == 2)
    {
        for (int i = 0; i < plat_vec_.size(); i++)
        {
            cout << "(" << i + 1 << ") - " << setw(16) << setfill(' ')  << plat_vec_.at(i).card_number() << " - " << plat_vec_.at(i).last_name() << ", " << plat_vec_.at(i).first_name() << endl;
        }
    }
    if (type_choice == 3)
    {
        for (int i = 0; i < corp_vec_.size(); i++)
        {
            cout << "(" << i + 1 << ") - " << setw(16) << setfill(' ')  << corp_vec_.at(i).card_number() << " - " << corp_vec_.at(i).last_name() << ", " << corp_vec_.at(i).first_name() << endl;
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
    cout << "(13) - Full transacstion History" << endl;
    
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
            cout << "Account: " << gold_vec_.at(choice).card_number() << endl;
            cout << setfill('/') << setw(18) << "" << "Transacstion History" << setw(18) << "" << endl << endl;
            gold_vec_.at(choice).CheckDenied();
            for (int i = 0; i < gold_vec_.at(choice).transacs().size(); i++)
            {
                stringstream ss;
                ss << gold_vec_.at(choice).transacs().at(i).date().at(0) << gold_vec_.at(choice).transacs().at(i).date().at(1);
                int month_of_trans;
                ss >> month_of_trans;
                if (month_of_trans == month_choice || month_choice == 13)
                {
                    cout << "Date: " << gold_vec_.at(choice).transacs().at(i).date() << endl;
                    cout << "Transacstion Number: " << gold_vec_.at(choice).transacs().at(i).transac_num() << endl;
                    cout << "Vendor: " << gold_vec_.at(choice).transacs().at(i).vendor() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << gold_vec_.at(choice).transacs().at(i).transac_amount() << endl;
                    if (gold_vec_.at(choice).transacs().at(i).denied())
                        cout << "transacstion Denied. Overdraft limit of $" << gold_vec_.at(choice).overdraft_allowance() << " exceeded" << endl;
                    cout << endl;
                }
            }
            cout << setfill('/') << setw(56) << " " << endl << endl;
            cout << "Current Card Balance (before rebate): $" << fixed << setprecision(2) << gold_vec_.at(choice).balance() << endl;
            cout << "Rebate: " << gold_vec_.at(choice).rebate() << "%" << endl;
            cout << "Current Rebate Value: $" << -gold_vec_.at(choice).balance() * (gold_vec_.at(choice).rebate() / 100.0) << endl;
            cout << "Current Card Balance (after rebate): $" << gold_vec_.at(choice).balance() + (-gold_vec_.at(choice).balance() * (gold_vec_.at(choice).rebate() / 100.0)) << endl;
            if (-(gold_vec_.at(choice).balance() + (-gold_vec_.at(choice).balance() * (gold_vec_.at(choice).rebate() / 100.0))) > gold_vec_.at(choice).credit_amount())
                cout << "Warning: This account is overdrafted in the amount of $" << (gold_vec_.at(choice).balance() + (-gold_vec_.at(choice).balance() * (gold_vec_.at(choice).rebate() / 100.0))) + gold_vec_.at(choice).credit_amount() << endl;
            break;
        case 2:
            if (month_choice != 13)
            cout << "Showing bill for month: " << month_choice_name << endl;
            cout << "Account: " << plat_vec_.at(choice).card_number() << endl;
            cout << setfill('/') << setw(18) << "" << "transacstion History" << setw(18) << "" << endl << endl;
            plat_vec_.at(choice).CheckDenied();
            for (int i = 0; i < plat_vec_.at(choice).transacs().size(); i++)
            {
                stringstream ss;
                ss << plat_vec_.at(choice).transacs().at(i).date().at(0) << plat_vec_.at(choice).transacs().at(i).date().at(1);
                int month_of_trans;
                ss >> month_of_trans;
                if (month_of_trans == month_choice || month_choice == 13)
                {
                    cout << "Date: " << plat_vec_.at(choice).transacs().at(i).date() << endl;
                    cout << "transacstion Number: " << plat_vec_.at(choice).transacs().at(i).transac_num() << endl;
                    cout << "Vendor: " << plat_vec_.at(choice).transacs().at(i).vendor() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << plat_vec_.at(choice).transacs().at(i).transac_amount() << endl;
                    if (plat_vec_.at(choice).transacs().at(i).denied())
                        cout << "transacstion Denied. Overdraft limit of $" << plat_vec_.at(choice).overdraft_allowance() << " exceeded" << endl;
                    cout << endl;
                }
            }
            cout << setfill('/') << setw(56) << " " << endl << endl;
            cout << "Current Card Balance (before rebate): $" << fixed << setprecision(2) << plat_vec_.at(choice).balance() << endl;
            cout << "Rebate: " << plat_vec_.at(choice).rebate() << "%" << endl;
            cout << "Current Rebate Value: $" << -plat_vec_.at(choice).balance() * (plat_vec_.at(choice).rebate() / 100.0) << endl;
            cout << "Current Card Balance (after rebate): $" << plat_vec_.at(choice).balance() + (-plat_vec_.at(choice).balance() * (plat_vec_.at(choice).rebate() / 100.0)) << endl;
            if (-(plat_vec_.at(choice).balance() + (-plat_vec_.at(choice).balance() * (plat_vec_.at(choice).rebate() / 100.0))) > plat_vec_.at(choice).credit_amount())
                cout << "Warning: This account is overdrafted in the amount of $" << (plat_vec_.at(choice).balance() + (-plat_vec_.at(choice).balance() * (plat_vec_.at(choice).rebate() / 100.0))) + plat_vec_.at(choice).credit_amount() << endl;
            break;
        case 3:
            if (month_choice != 13)
            cout << "Showing bill for month: " << month_choice_name << endl;
            cout << "Account: " << corp_vec_.at(choice).card_number() << endl;
            cout << setfill('/') << setw(18) << "" << "transacstion History" << setw(18) << "" << endl << endl;
            corp_vec_.at(choice).CheckDenied();
            for (int i = 0; i < corp_vec_.at(choice).transacs().size(); i++)
            {
                stringstream ss;
                ss << corp_vec_.at(choice).transacs().at(i).date().at(0) << corp_vec_.at(choice).transacs().at(i).date().at(1);
                int month_of_trans;
                ss >> month_of_trans;
                if (month_of_trans == month_choice || month_choice == 13)
                {
                    cout << "Date: " << corp_vec_.at(choice).transacs().at(i).date() << endl;
                    cout << "transacstion Number: " << corp_vec_.at(choice).transacs().at(i).transac_num() << endl;
                    cout << "Vendor: " << corp_vec_.at(choice).transacs().at(i).vendor() << endl;
                    cout << "Amount: $" << fixed << setprecision(2) << corp_vec_.at(choice).transacs().at(i).transac_amount() << endl;
                    if (corp_vec_.at(choice).transacs().at(i).denied())
                        cout << "transacstion Denied. Overdraft limit of $" << corp_vec_.at(choice).overdraft_allowance() << " exceeded" << endl;
                    cout << endl;
                }
            }
            cout << setfill('/') << setw(56) << " " << endl << endl;
            cout << "Current Card Balance (before rebate): $" << fixed << setprecision(2) << corp_vec_.at(choice).balance() << endl;
            cout << "Rebate: " << corp_vec_.at(choice).rebate() << "%" << endl;
            cout << "Current Rebate Value: $" << -corp_vec_.at(choice).balance() * (corp_vec_.at(choice).rebate() / 100.0) << endl;
            cout << "Current Card Balance (after rebate): $" << corp_vec_.at(choice).balance() + (-corp_vec_.at(choice).balance() * (corp_vec_.at(choice).rebate() / 100.0)) << endl;
            if (-(corp_vec_.at(choice).balance() + (-corp_vec_.at(choice).balance() * (corp_vec_.at(choice).rebate() / 100.0))) > corp_vec_.at(choice).credit_amount())
                cout << "Warning: This account is overdrafted in the amount of $" << (corp_vec_.at(choice).balance() + (-corp_vec_.at(choice).balance() * (corp_vec_.at(choice).rebate() / 100.0))) + corp_vec_.at(choice).credit_amount() << endl;
            break;
    }
}