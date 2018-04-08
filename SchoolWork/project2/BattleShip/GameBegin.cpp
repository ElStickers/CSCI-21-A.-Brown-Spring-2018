#include "board.h"
#include "board.cpp"

int main()
{
    Board begin;
    
    Board();
    
    begin.PrintBoard();
    
    begin.ships_still_swiming();
    
    begin.CreateGameBoard();
}
