/*
 * Name         : board.cpp
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  :
 */
  
 #ifndef BOARD_H
 #define BOARD_H
 
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::vector;
 
 using namespace std;
 
 /*
  Class Board
  
  Holds status of gameboard
  
  */
  
class board {
 
 protected:
 
 vector<char> board_; //Holds the board layout
 
 int ships_still_swiming_; //Holds the amount of ships that are still swiming aka still alive
 
 public:
 
 GameBoard(); //Constructor, sets vector size to board requirement (100) and "creates" and creates and "empty" board. (inserts "ohs" into every spot)

 vector<char> board(); //Accesor, Returns the board layout/vector
 
 int ships_still_swiming(); //Accesor, returns the amount of ships that are still swimming aka still alive
 
 void CreateGameBoard(); //Reads the board file and creates the board that you pick.
 
 void PrintBoard(); //Prints out the board that you selected showing you its current state during the game.
 
 void PostAction(); //Takes in user action (position of attack choice) and changes the display accordingly M = miss, o = nothing, H = hit, S = Ship segment.
 
}
 
 #endif