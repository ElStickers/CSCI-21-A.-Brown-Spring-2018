#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <thread>
#include <vector>
#include "board.cpp"
#include "player.cpp"
#include "human.cpp"
using std::cout;
using std::stringstream;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
    Board start;
    
    start.Welcome();
    
    start.CreateGameBoard();
    
    Human get;
    
    get.GetTarget();
    
}
    





    // cout << "called ships_still_swiming()" << endl;
    
    // cout << ships_still_swiming_ << endl;
    
    // int ships = ships_still_swiming_;
    
    // if(ships == !0)
    // {
    //     cout << "There are " << ships << " ship targets left on the board." << endl;
    
    // }
    // else if (ships == 0)
    // {
    //     cout << ships << " ships remain." << endl;
        
    //     cout << "Congradulations! You have sunk all enemy ships. Good Work!" << endl;
    // }
    
    // Board begin;
    
    // Human play;
    
    // Board();
    
    // bool open = false;

    // string filename = "board1";

    // ifstream filein;
    
    // begin.Welcome();

    // while (open != true)
    // {
    //     cout << "Please enter the name of the GameBoard File you would like to use.\nPlease do not include extensions. (ie. .txt)\n";
        
    //     //cin >> filename;
        
    //     sleep(1.5);
        
    //     filename.append(".txt"); //if not a txt extension, erase this line and type in the file name inlcuding the extension when prompted.
        
    //     filein.open(filename);
        
    //     if(!filein.good())
    //     {
    //         cout << "\nError: File " << filename << " was not found.\nPlease make sure your spelling is correct and double check that" <<
    //                 " the file is in the dierectory and please try again.\n\n";
    //     }
    //     else
    //     {
    //         cout << "File found.\n\n";
    //         //sleep(1);
    //         cout << "Please wait while the file is opened.\n\n";
    //         //sleep(2);
    //         open = true;
    //     }
    // }
    
    // cout << "File opened succesfully.\n\n";
    
    // //sleep(2);
    
    // cout << "Creating gameboard...\n\n";
    
    // int array_position = 0;
    
    // for(int row = 1; row < 20; row++)
    // {
    //     string input;
        
    //     getline(filein, input);
        
    //     //cout << input << endl;
        
    //     if(row % 2 == 1 )
    //     {
    //         stringstream space(input);
            
    //         char board_space; //Holds the spaces between each board hole;
            
    //         for(int col = 0; col < 10; col++)
    //         {
    //             space >> board_space;
                
    //             if(board_space == 'S')
    //             {
    //                 begin.PostAction(array_position, 'S');
    //             }
    //             array_position++;
    //         }
    //     }
    // }
    
    // //sleep(2);
    
    // cout << "Board created.\n\n";
    
    // begin.PrintBoard();
    
    // int temp_ship = begin.CountShips();
    
    // begin.set_ships_still_swimming(temp_ship);
    
    // // cout << "print_ships_remaining()" << endl;
    
    // begin.print_ships_remaining();
    
    // // cout << "get_ships_still_swiming" << endl;
    
    // // cout << begin.get_ships_still_swiming() << endl;
    
    // begin.Victory();
    
    // begin.GameOver();
    
    // string temp = "1";
    
    // int tempint = 684;
    
    // cout << tempint << endl;
    
    // stringstream ss(temp);
    
    // ss >> tempint;
    
    // cout << tempint << endl;
    