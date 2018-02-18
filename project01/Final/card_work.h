/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Date :           (Enter Date Here)
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Header file for CardWork class
 *                  Reads all files and sorts the information in the correct location (ie. vector)
 *                  As well as handling outputs
 */

#ifndef CARD_WORK_H
#define CARD_WORK_H

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
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;
using std::setprecision;
using std::fixed;

class CardWork {
    
private:
    
    vector<GoldCard> gold_vec_;
    vector<PlatinumCard> plat_vec_;
    vector<CorporateCard> corp_vec_;

public:
    /*
     * Constructor
     * Resizes Card Vectors To 1
     */
    CardWork();
    

    /*
     * Reads input files and populates the vectors for transactions, and all three card types.
     */
    void Populate(string input1, string input2);

};



#endif
