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
#include <cctype>
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

class Board
{

  protected:
  
      vector<char> board_; //Holds the board layout
  
      int ships_still_swiming_; //Holds the amount of ships that are still swiming aka still alive

  public:
  
      Board(); //Constructor, sets vector size to board requirement (100) and "creates" and creates and "empty" board. (inserts "ohs" into every spot)
  
      vector<char> board_layout(); //Accesor, Returns the board layout/vector
  
      int get_ships_still_swiming(); //Accesor, returns the amount of ships that are still swimming aka still alive

      int CountShips(); //Iterates through vector looking for S or ship locations available to hit.
      
      void print_ships_remaining(); //Prints amount of targers that are left;
      
      void set_ships_still_swimming(int ships_swiming); //Sets the number of ship positions that haven't bit hit.

      void CreateGameBoard(); //Reads the board file and creates the board that you pick.
  
      void PrintBoard(); //Prints out the board that you selected showing you its current state during the game.
  
      void PostAction(int board_postion, char new_status); //Takes in user action (position of attack choice) and changes the display accordingly M = miss, o = nothing, H = hit, S = Ship segment.
      
      void Welcome(); //Displays a welcome message when begining the game
      
      void Victory(); //Displays a Victory message if the player wins against computer
      
      void GameOver(); //Displays a game over message if player looses to computer
      
      void CheckGameOver(); // Checks ship count to determine if all ships on one side have been shot down
  
};

#endif
