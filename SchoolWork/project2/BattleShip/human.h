/*
 * Name         : human.cpp
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  :
 */
  
 #ifndef HUMAN_H
 #define HUMAN_H
 
 #include "player.h"
 
 #include <iostream>
 
 using namespace std;
 
 /*
  Class Human
  
  This class holds info and moves that belong to the human players action
  
  */
  
class Human : public Player
{
 
 private:
 
 Board Tracker_Board_;
 
 public:
 
 Human(); //Constructor
 
 Board Tracker_Board(); //Accesor, returns the tracking board
 
 void GetTarget(); //Asks player for target. If computer choice picks a random number("will probably change")
 
 void AttackResult(); //Displays if attack hit or if it missed; 
 
};
 
 #endif