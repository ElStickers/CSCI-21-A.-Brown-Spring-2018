/*
 * Name        : collection.h
 * Author      : Jacob Pawek
 * Date        : 2-10-18
 * Description : Header File for Collection class
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include "gold.h"
#include "platinum.h"
#include "corporate.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;
using std::fixed;
using std::setprecision;

/*
 * Class Collection.
 * A class that fills 3 vectors with Cards of different types and performs output functions
 */
class Collection
{
public:
    /*
     * Constructor
     * Sets collection_ pointer to null value
     */
    Collection();

    /*
     * Outputs all denied transactions along with reason for denial
     */
    void DenialStatement(string filename);
    
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
    void FillVectors(string filename1, string filename2);
    
    /*
     * gold_collection_ Accessor
     * @return vector<Gold> - returns vector
     */
    vector<Gold> gold_collection();
    
    /*
     * plat_collection_ Accessor
     * @return vector<Platinum> - returns vector
     */
    vector<Platinum> plat_collection();
    
    /*
     * corp_collection_ Accessor
     * @return vector<Corporate> - returns vector
     */
    vector<Corporate> corp_collection();
private:
    vector<Gold> gold_collection_;
    vector<Platinum> plat_collection_;
    vector<Corporate> corp_collection_;
};


#endif
