/*
 *Name: Luhn Algorithm v2
 *Author: Juan Palos
 *Date: 2/1/18
 *Description: Read credit card numbers from a file and check 
 *if card is valid and card type. ie.Visa, Mastercard, etc.
 */

#include "bincheck.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <vector> 
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

int main(){
    
    int card_num, temp;
    
    string c_num, line;
    
    stringstream ss;
    
    ifstream cardin("card_numbers.txt");
    
    if (cardin.fail()){
    cerr << "Error opening/creating a file. Please correct before continuing\n";
    exit(1);
  }
  
  
  

}