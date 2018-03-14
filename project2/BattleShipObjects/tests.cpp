#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
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
                    " the file is in the dierectory try again.\n\n";
        }
        else
        {
            cout << "File found.\n\n";
            sleep(1);
            cout << "Please wait while the file is opened.\n\n";
            sleep(3);
            open = true;
        }
    }
    
    cout << "File opened succesfully.\n\n";
    
    sleep(2);
    
    cout << "Creating gameboard...\n\n";
    
    sleep(2);
    
    cout << "Board created.\n\n";
}
