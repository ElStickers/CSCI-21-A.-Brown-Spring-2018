//lab 9.cpp
// CSCI 111 section 4 = due 2/11/12
//
//random number generator

#include<iostream>
using namespace std;
int main()
{
// while (true) {
 int guess;
 bool play = true;
 int win;
 int RandomNumber;
 srand ( 99 );
 char choice;
 //RandomNumber = rand() % 10 + 1;

  cout << "would you like to play? (enter y or n)" << endl;
  
  cin >> choice;
  
  cin.ignore();
  
  do {
   win = 0;
   RandomNumber = rand() % 10 + 1;
   
      if (choice == 'y') {
          
      cout << "Enter your guess:" << endl;
      
      cin >> guess;
          
      if (guess > RandomNumber) {  
          system ("COLOR 04");
          cout << "Your guess is greater than the random number.\n" << endl;
          
      }
      
      else if (guess < RandomNumber) {
          
          cout << "Your guess is less than the random number.\n" << endl;
          
      }
  
      else if (guess == RandomNumber) {
      
      cout << "Congratulations. You guessed correctly.\n" << endl;
      
      cout << "Would you like to play again? (enter y or n)" << endl;
      
      cin >> choice;

      
  }
  
  }
          
  } while (choice == 'y');

          
      if (choice == 'n') {
      
      cout << "Thanks for playing. Come back again." << endl;
      
      exit(1);
}

}
  





