/*
 * Name         : human.cpp
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  :
 */
 
 #include "human.h"
 
 Human::Human()
 {
     
 }
 
 Board Human::Tracker_Board()
 {
     return Tracker_Board_;
 }
 
 void Human::GetTarget()
 {
     char row;
     
     int col;
     
     int loop = 0;
     
     bool valid = false;
     
     string coordinates;
     
     while(valid == false)
     {
         if(loop != 0)
         {
             cout << "Please pick some coordinates that wont harm civilians." << endl;
             
             cout << "Shot Coordinates: ";
             
             cin.ignore();
             
             getline(cin, coordinates);
         }
         else if(loop == 0)
         {
             cout << "Alright boss give us the coordinates you wish too shoot. (Row Col: ex.C 1)" << endl;
         
             cout << "Shot Coordinates: ";
             
             cin.ignore();
             
             getline(cin, coordinates);
         }
         
         stringstream temp(coordinates);
         
         temp >> row;
         
         temp >> col;
         
         switch(toupper(row))
         {
             case 'A':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     valid = true;
                     
                     break;
                 }
                 
                 break;
             }
             case 'B':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 10;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             case 'C':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 20;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             case 'D':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 30;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             case 'E':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 40;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             case 'F':
             if(col >= 0 && col < 10)
                 {
                     target_ = col + 50;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             
             case 'G':
             if(col >= 0 && col < 10)
                 {
                     target_ = col + 60;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             
             case 'H':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 70;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             case 'I':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 80;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             case 'J':
             {
                 if(col >= 0 && col < 10)
                 {
                     target_ = col + 90;
                     
                     valid = true;
                 }
                 else
                 {
                     loop++;
                     
                     cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                     
                     break;
                 }
                 
                 break;
             }
             
             default:
             {
                 cout << "Boss these coordinates are going to hit land! Please rethink your choice." << endl;
                 
                 loop++;
             }
         }
     }
     
 }
 
 void Human::AttackResult()
 {
     if(Comp_Board_.board_layout().at(target_) == 'S')
     {
         cout << "Boss, we've hit an enemy ship" << endl;
         
         Board set;
         
         set.PostAction(target_, 'H');
     }
     else if(Comp_Board_.board_layout().at(target_) == 'H')
     {
         cout << "Boss...we've already targeted that location. Please choose your shots more carefully next time." << endl;
     }
 }