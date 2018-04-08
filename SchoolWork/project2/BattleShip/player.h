/*
 * Name         : player.h
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  :
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

#include <iostream>
using std::cout;
using std::endl;

/*
 * Class Player.h file.
 * Holds plater information and possible player action functions
 */
class Player
{
    protected:
    Board player1_board;
    
    Board player2_board;
    
    int target_;
    
    public:
    
    Player(); //Constructor, Makes the target_ value = 0;
    
    
};

#endif