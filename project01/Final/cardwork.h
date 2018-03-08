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

    /*
     * Outputs all denied transactions along with reason for denial
     */
    void CheckDenied(string transacfile);
    
    /*
     * Outputs necessary information about cards in collection
     */
    void MonthlyStatement();

    /*
     * Scans input file, placing information into each Gold, Platinum, or Corporate vector.
     * Continues resizing vectors until end of file is reached.
     * @param string filename1 - The first file from which to draw information for each card object
     * @param string filename2 - The second file from which to draw information for each transaction object
     */
    void Populate(string cards, string transacs);
    
    /*
     * gold_collection_ Accessor
     * @return vector<Gold> - returns vector
     */
    vector<GoldCard> gold_vec();
    
    /*
     * plat_collection_ Accessor
     * @return vector<Platinum> - returns vector
     */
    vector<PlatinumCard> plat_vec();
    
    /*
     * corp_collection_ Accessor
     * @return vector<Corporate> - returns vector
     */
    vector<CorporateCard> corp_vec();

};



#endif
