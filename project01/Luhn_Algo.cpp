/*
 *Name: Luhn_Algo.cpp
 *Author: Juan Palos
 *Description: Program that checks credit card number validity with 
 *the Luhn Algorithm
 */
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <locale>
#include <chrono>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

//Program Begins Here
int main() {
    
    int i=0, card_num;
    
    //String Variable to hold the credit card number for transfer
    string cc_number, line;
    
    //Array that will hold card number after stored in string
    char cc_array[16];
    
    //Input Stream Declaration
    ifstream fin("card_numbers.txt");
    
    //Output Stream Declaration
    //ofstream fout("card_check.txt");
    
    //Making sure both file open correctly
    if (fin.fail() || fout.fail()) {
    cerr << "Error opening/creating one of the files. Please fix before continuing.\n";
    exit(1);
  }
    
    //Our Loop begins here.
    while(!fin.eof()){
        //gets the first number from the file
        getline(fin, line);
        //outputs the number
        cout << "Your card number is: " << line << "\n";
        //here begins the digit check loop to determine card type.
        
        //begin checking for the number four
        if (line.at(0) == '4'){
        
        cout << "This is a Visa card.\n\n";
        
        }
        //we check for number three if 
        else if (line.at(0) == '3'){
            
            if (line.at(1) == '4' || line.at(1) == '7'){
            
            cout << "This is an American Express card.\n\n" << endl;
            
            }else cout << "Unknown Card Number.\n\n";
        }
        else if (line.at(0) == '5'){
            
            if (line.at(1) == '1' || line.at(1) == '2' || line.at(1) == '3' || line.at(1) == '4' || line.at(1) == '5'){
            
            cout << "This is a Master Card card.\n\n" << endl;
            
            }else cout << "Unknown Card Number.\n\n";
            
        } //end of digit check loop
        
    }//end of file read loop
    
    //we now close the file.
    
    cout << "Number check complete.\nPlease wait while we attempt to close the file.\n";
    
    fin.close();
    
    if(!fin.is_open()){
        cout << "File has closed successfully.\nGoodbye.";
    }
    
}