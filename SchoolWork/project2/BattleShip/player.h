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
    
    Board Human_Board_;
    
    Board Comp_Board_;
    
    int target_;
    
    public:
    
    Player(); //Constructor, Makes the target_ value = 0;
    
    Board Human_Board(); //Accesor for player 1 Board
    
    Board Comp_Board(); //Accesor for player 2 Board
    
    int Target(); //Accesor for player target choice
    
    void SetHumanBoard(Board Human_Board); //Mutator, sets player 2 Board to file chosen
    
    void SetCompBoard(Board Comp_Board); //Mutator, sets player 2 Board to file chosen
    
    void SetTarget(int target); //Mutator, sets player target
    
    void Invalid(); //Invalid shot ouput
    
    virtual void GetTarget() = 0; //Asks player for target. If computer choice picks a random number("will probably change")
    
    virtual void AttackResult() = 0; //Displays if attack hit or if it missed; 
};

#endif