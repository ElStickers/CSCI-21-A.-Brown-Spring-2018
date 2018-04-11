/*
 * Name         : human.cpp
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  :
 */

#ifndef GAME_H
#define GAME_H

#include "human.h"
#include "computer.h"

/*
 Class Game
 Starts and manages the status of the game
*/

class Game
{
    private:
    
    bool GameOver_;
    
    int turn_;
    
    Human player1_;
    
    Computer player2_;
    
    public:
    
    Game(); //Consturctor, makes GameOver_ value equal to false
    
    void GameBegin(string player1_board, string player2_board, int first_turn); //Starts game. Brings in all necessary info to decide first move and to set each gameboard and tracker board
    
    void Turn(int turn)
}
