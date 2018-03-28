//Author :          Juan Palos
//Description:      Working with a stack

#include <iostream>
#include <fstream>
#include <queue>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;
using std::ifstream;

int main()
{
    queue<string> theQueue;
    
    string inFileName;
    
    ifstream inStream;
    
    bool open = false;
    
    while(open != true)
    {
        cout << "Please enter the file name you would like to use: ";
    
        cin >> inFileName;
    
        inStream.open(inFileName);
        
        if(!inStream.good())
        {
            cout << "\nError: File " << inFileName << " was not found.\nPlease make sure your spelling is correct and double check that" <<
            
                    " the file is in the correct location and try again.\n\n";
        }
        else
        {
            open = true;
        }
    }
    
    while(!inStream.eof())
    {
        string word;
        
        inStream >> word;
        
        theQueue.push(word);
    }
    
    inStream.close();
    
    while(!theQueue.empty())
    {
        cout << "Top of the stack holds: " << theQueue.front() << "\n\n" << endl;
        
        theQueue.pop();
    }
}