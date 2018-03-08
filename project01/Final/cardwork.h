/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           (2/28
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Header file for CardWork class
 */

#ifndef CARDWORK_H
#define CARDWORK_H

#include "goldcard.h"
#include "platinumcard.h"
#include "corporatecard.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
using std::cout;
using std::cerr;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;
using std::setprecision;
using std::fixed;
using std::setfill;
using std::setw;

class CardWork {
    
protected:
    
    vector<GoldCard> gold_vec_;
    vector<PlatinumCard> plat_vec_;
    vector<CorporateCard> corp_vec_;

public:

    CardWork(); //Constructor, sets vectors size to one

     //Takes info from the input file and inserts info into corresponding vector
    void CheckDenied(string transacfile);
    
    //Takes info from the input file and checks with card vectors to add transaction data to the corresponding card number
    void MonthlyStatement();
    
    //Displays the transaction data of each card
    void Populate(string cards, string transacs);
    
    //Accesssor, returns gold card vector
    vector<GoldCard> gold_vec();
    
    // Accessor, returns platinum vector
    vector<PlatinumCard> plat_vec();

    //Accessor, retruns corporate card vector
    vector<CorporateCard> corp_vec();

};



#endif
