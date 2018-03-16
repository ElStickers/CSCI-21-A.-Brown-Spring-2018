#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <vector>
#include "board.cpp"
using std::cout;
using std::stringstream;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
    Board begin;
    
    Board();
    
    bool open = false;

    string filename;

    ifstream filein;

    while (open != true)
    {
        cout << "Please enter the name of the GameBoard File you would like to use.\nPlease do not include extensions. (ie. .txt)\n";
        
        cin >> filename;
        
        filename.append(".txt"); //if not a txt extension, erase this line and type in the file name inlcuding the extension when prompted.
        
        filein.open(filename);
        
        if(!filein.good())
        {
            cout << "\nError: File " << filename << " was not found.\nPlease make sure your spelling is correct and double check that" <<
                    " the file is in the dierectory and please try again.\n\n";
        }
        else
        {
            cout << "File found.\n\n";
            //sleep(1);
            cout << "Please wait while the file is opened.\n\n";
            //sleep(2);
            open = true;
        }
    }
    
    cout << "File opened succesfully.\n\n";
    
    //sleep(2);
    
    cout << "Creating gameboard...\n\n";
    
    int array_position = 0;
    
    for(int row = 1; row < 20; row++)
    {
        string input;
        
        getline(filein, input);
        
        cout << input << endl;
        
        if(row % 2 == 1)
        {
            stringstream space(input);
            
            char board_space; //Holds the spaces between each board hole;
            
            for(int col = 0; col < 10; col++)
            {
                space >> board_space;
                
                if(board_space == 'S')
                {
                    begin.PostAction(array_position, 'S');
                }
                array_position++;
            }
        }
    }
    
    //sleep(2);
    
    cout << "Board created.\n\n";
    
    begin.PrintBoard();
}
