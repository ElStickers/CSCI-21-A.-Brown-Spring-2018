#include<iostream>
#include<cctype>
using namespace std;
locale loc;
int CountLetter(string sentence, char x ){
int i = 0;


 for (int k=0; k<sentence.length(); k++ )
 {
  if (tolower(x) == tolower(sentence[k]))
  {
    i++;
  }
 }
 return i;
}