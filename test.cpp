#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;
int main(){
string card_number = "5208721775139421";
char bank = 'd';
char bank_;
        if (toupper(bank) == 'D' || 'M' || 'V' || 'A' || 'U') {
            bank_ = toupper(bank);
        }
        cout << bank_;
    
}