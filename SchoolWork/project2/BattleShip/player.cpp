/*
 * Name         : player.cpp
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  :
 */
 #include "player.h"
 
 Player::Player()
 {
     target_ = 0;
 }
 
 Board Player::Human_Board()
 {
     return Human_Board_;
 }
 
 Board Player::Comp_Board()
 {
     return Comp_Board_;
 }
 
 int Player::Target()
 {
     return target_;
 }
 
 void Player::SetHumanBoard(Board Human_Board)
 {
     Human_Board_ = Human_Board;
 }
 
 void Player::SetCompBoard(Board Comp_Board)
 {
     Comp_Board_ = Comp_Board;
 }
 
 void Player::SetTarget(int target)
 {
     target_ = target;
 }
 
 void Player::Invalid()
 {
     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
 }
