/*
 * Name        : project1.cpp
 * Author      : Jacob Pawek
 * Date        : 2-1-18
 * Description : Identify credit card types based on digit patterns attributed to various companies
 */
 
 #include "project1.h"
 
 int main() {
     // Create instance of Card class
     Card card1;
     // Declare input file stream
     ifstream fin;
     // Open input file
     string file_to_open;
     cout << "Enter a file to read" << endl;
     cout << "Reminder: Please enter in format filename.txt" << endl;
     cout << "File: ";
     cin >> file_to_open;
     fin.open(file_to_open);
     // Check to make sure file opened properly
     if (!fin.is_open()) {
      cout << "Error: could not open file " << file_to_open << endl;
      return 1;
     }
     
     string card_num;
     
     // Loops until end of file is reached
     cout << endl;
     while (!fin.eof()) {
     fin >> card_num;
     // Outputs the card number to the screen
     cout << "The number is: " << card_num << endl;
     // Calls a function to check the card type
     card1.CheckCardType(card_num);
     }
     // Closes file when end is reached
     cout << "\nReached end of file" << endl;
     cout << "Attempting to close file..." << endl;
     fin.close();
     if (!fin.is_open()) {
      cout << "File closed successfully" << endl;
     }
     return 0;
 }
 
 
 /*
  * Inspects first six digits of card number to determine which bank it
  * belongs to, and sets bank_type_ to the corresponding value.
  * @param string card_number - The card number of which to identify
  *                           - bank
  */
 void Card::DetermineBankType(string card_number) {
  switch (card_number.at(0)) {
   
   
   // Visa cards start with a 4
   case '4':
    cout << "This appears to be a Visa card" << endl;
    break;
    
    
   // American Express Cards start with 34 or 37
   case '3':
    if (card_number.at(1) == '4' || card_number.at(1) == '7')
     cout << "This appears to be an American Express card" << endl;
    else
     cout << "Unknown card type" << endl;
    break;
    
    
   // Discover cards start with 6011, 622126 – 622925, 644 – 649, or 65
   case '6':
    // Check if the first four digits are 6011
    if (card_number.find("6011") == 0)
    cout << "This appears to be a Discover card" << endl;
    // Check if the first three digits are 622
    else if (card_number.find("622") == 0) {
     string first_six = "";
     for (int i = 0; i < 6; i++) {
      first_six += card_number.at(i);
     }
     int initial_six;
     // Plug string variable into stringstream to convert to integer
     {
      stringstream ss;
      ss << first_six;
      ss >> initial_six;
     }
     // Check if the first six digits fall into the range 622126 - 622925
     if (initial_six >= 622126 && initial_six <= 622925)
      cout << "This appears to be a Discover card" << endl;
     else
      cout << "Unknown card type" << endl;
    }
    // Check if the second digit is a 4
    else if (card_number.at(1) == '4') {
     string first_three = "";
     for (int i = 0; i < 3; i++) {
      first_three += card_number.at(i);
     }
     int initial_three;
     // Plug string variable into stringstream to convert to integer
     {
      stringstream ss;
      ss << first_three;
      ss >> initial_three;
     }
     // Check if the first six digits fall into the range 644 - 649
     if (initial_three >= 644 && initial_three <= 649)
      cout << "This appears to be a Discover card" << endl;
     else
      cout << "Unknown card type" << endl;
    }
    // Check if the second digit is a 5
    else if (card_number.at(1) == '5')
     cout << "This appears to be a Discover card" << endl;
    else
     cout << "Unknown card type" << endl;
    break;
    
    
   // Master cards start with 51 - 55
   case '5':
    int second_digit;
    // Plug string variable into stringstream to convert to integer
    {
     stringstream ss;
     ss << card_number.at(1);
     ss >> second_digit;
    }
    // Check if the second digit falls into the range 1 - 5
    if (second_digit >= 1 && second_digit <= 5)
    cout << "This appears to be a MasterCard" << endl;
    else
     cout << "Unknown card type" << endl;
    break;
   default:
    cout << "Unknown card type" << endl;
    break;
  }
 }