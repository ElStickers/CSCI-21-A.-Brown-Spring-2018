#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <locale>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

int main(){
    int card_num, temp;
    
    string cc_number, line;
    
    stringstream ss;
    
    ifstream cardin("card_numbers.txt");
    
    if (cardin.fail()){
    cerr << "Error opening/creating the file.\n";
    exit(1);
  }
  
  getline (cardin, line);
  
  cout << line << endl;
  
  int i;
  
  int number[i];
  
  for (i = 0; i < line.size(); i++){
      
      number[i] = line.at(i) - '0';
  }
  
  cout << number[16];
}