/*
 * Author:          Juan Palos
 * Name :           Luhn Algo Project Final
 * Special Thanks : The one, The only (literally The Only one. Google it.) Mr. Jacob Pawek.
 * Description :    Reads credit card numbers from a file inputs the info into a or several vectors.
 *                  Then read in a transaction from a different file and match it to the stored card.
 */
 
#include <iostream>

#include "cardwork.cpp"
#include "card.cpp"
#include "goldcard.cpp"
#include "platinumcard.cpp"
#include "corporatecard.cpp"
#include "transac.cpp"

using namespace std;

int main() {
 
 string file1, file2;
 int choice;
 
 cout << "Please enter the name of the file holding the Credit Card Information.\n(Please don't include file extensions.)\n";
 cout << "File One: ";
 cin >> file1;
 
 cout << "Please enter the name of the file holding the Transaction Information.\n(Please don't include file extensions.)\n";
 cout << "File Two: ";
 cin >> file2;
 
 file1.append(".txt");
 file2.append(".txt");
 int loop = 0;
 
 char status = 'y';
 
 
 while (toupper(status) == 'Y') {
 
 CardWork run;
 
 if ( loop > 0) {
 cout << "Would you like to view anything else? (Y/N)" << endl;
 
 char choice2;
 
 cin >> choice2;
 
 if (toupper(choice2) == toupper('y')) {
  
  status = 'y';
  
 }
 
 else if (toupper(choice2) == toupper('n')) {
  
  cout << "Exiting Program...\n";
 
  cout << "GoodBye.\n";
  
  status = 'n';
  
  return 1;
  
 }
 
 }
 
 cout << "What would you like to do?\n";
 
 cout << "1 = See Denied Transactions\n"
      << "2 = See Monthly Billing Statement\n"
      << "3 = Exit Program\n";
 cin >> choice;
 
 run.Populate(file1, file2);
 
 if (choice == 1) {
  
  run.CheckDenied(file2);
  
  loop++;
 }
 else if (choice == 2) {
  
  run.MonthlyStatement();
 
  loop ++;
  
 }
 
 else if (choice == 3) {
  
  cout << "Exiting Program...\n";
 
  cout << "GoodBye.\n";
  
  status = 'n';
 
  
 }
 
 else if (choice != 1 || 2 || 3) {

 cout << "Sorry " << choice << " wasn't an option.\nPlease select one of the options from above to continue.\n";
 
 }
  
 
 }
 
}