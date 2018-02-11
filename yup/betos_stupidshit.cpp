// lab7.cpp
// CSCI 111 section 4 = due 02/07/2018
// 
// description :

#include<iostream>
using namespace std;
int main() {
  
  int start;// Starting value given by user 
  int interval;// (interval)increment value given by user 
  int end;// end value given by user`
  int res;
  char choice;// user choice a or d

  cout << "Would you like to in a = ascending-order or d = descending-order ?" << endl;
  cin.get(choice);
  
  if (choice != 'a' || 'b') {
    
    cout << "Please enter 'a' or 'b'" << endl;
    
    return 1;
  
  }
  
  cout << "Enter the start value." << endl;
  cin >> start;
  cout << "Enter the interval value." << endl;
  cin >> interval;
  cout << "Enter the end value." << endl;
  cin >> end;
  cout << "Here the numbers:" << endl;
  
  
  if ( choice == 'a' && start > end ) { 
    
    cout << " Error: cannot count in ascending order when start value is greater than end value." << endl;
    
    exit(1);
    
  } 
  
  else if ( choice == 'a' ) {
    
      while ( start < end ) {
        
        int start_;
        
        cout << start << endl;
   
        start = start  + interval;
        
      }
      
      if ((start - interval) % 2 == 0) {
        
        cout << "The Number is Even" << endl;
      
      }
      
      else {
        
        cout << "The Number is Odd" << endl;
      
      }
 }  

  
  if ( choice == 'd' && start < end) { 
    
    cout << "Error: cannot count in descending order when start value is smaller than end value." << endl;
    
    exit(1);
    
  }
  if ( choice == 'd' ) { 
    
    while (start > end) {
      
      cout << start << endl;
      
      start = start - interval;
      
    }
  
  if ((start + interval) % 2 == 0) {
        
        cout << "The Number is Even" << endl;
      
      }
      
      else {
        
        cout << "The Number is Odd" << endl;
      
      }
  } 
  return 0;
}   
