#include<iostream>
#include "countletter.h"
using namespace std;

int main()
{

 string sentence;
 char z;

 cout << "Enter a sentence." << endl;
 getline(cin,sentence);
 cout << "Enter a letter." << endl;
 cin >> z;
 cout << "The letter " << z << " occured " << CountLetter(sentence, z) << " time." << endl;



 }
