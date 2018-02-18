/*
 * Name        : card_work.cpp
 * Author      : Juan Palos
 * Date        : 2-10-18
 * Description : Function definitions for CardWork class
 */

#include "card_work.h"
#include "card.h"
#include "transaction.h"

CardWork::CardWork(){
    
    gold_vec_.resize(1);
    plat_vec_.resize(1);
    corp_vec_.resize(1);
    
}

void CardWork::Populate(string file1, string file2) {
    
    ifstream fin1(file1);
    ifstream fin2(file2);
    
    if (fin1.fail() || fin2.fail()){
        cout << "Error opening one of the files.\nPlease make sure the names match the file names.\n"
        cout << file1 << " " << file2 << endl;
        exit(1);
    }
    
    int gold = 0;
    int plat = 0;
    int corp = 0;
    
    while (!fin1.eof()) {
        
        string line;
        getline(fin, temp);
        stringstream input(temp);
        string temp_c_num, temp_f_name, temp_l_name, temp_type;
        char trash;
        double temp_bal;
        ss >> temp_c_num;
        ss >> temp_f_name;
        ss >> temp_l_name;
        ss >> temp_type;
        ss >> trash;       //place to hold the '-' from the input
        ss >> temp_bal;
    }
}