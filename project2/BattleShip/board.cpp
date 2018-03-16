/*
 * Name         : board.cpp
 * Author       : Juan Palos
 * Date         : (Enter Date)
 * Description  : Function Definitions for Board Class
 */

#include "board.h"

/*
 *Constructor, sets vector size to board requirement (100) and "creates" and creates and "empty" board.
 *(inserts "ohs" into every spot)
 * Also sets the amount of ships on the board at the begining of the game.
 */
Board::Board()
{
    board_.resize (100, 'o');

    ships_still_swiming_ = 17; //Counting ships by thier health. 17 = 1 5 health ship, 1 4 health ship, 2 3 health ships, and 1 2 health ship.
}

//Accesor, Returns the board layout/vector
vector<char> Board::board_layout()
{
    return board_;
}

//Accesor, returns the amount of ships that are still swimming aka still alive
int Board::ships_still_swiming()
{
    return ships_still_swiming_;
}

//Reads the board file and creates the board that you pick.
void Board::CreateGameBoard()
{
    Board begin;
    
    bool open = false;

    string filename;

    ifstream filein;

    while (open != true)
    {
        cout << "Please enter the name of the GameBoard File you would like to use.\nPlease do not include extensions. (ie. .txt)\n";
        
        cin >> filename;
        
        filename.append(".txt"); //if not a txt extension, erase this line and type in the file name inlcuding the extension when prompted.
        
        filein.open(filename);
        
        if(!filein.good())
        {
            cout << "\nError: File " << filename << " was not found.\nPlease make sure your spelling is correct and double check that" <<
                    " the file is in the dierectory and please try again.\n\n";
        }
        else
        {
            cout << "File found.\n\n";
            //sleep(1);
            cout << "Please wait while the file is opened.\n\n";
            //sleep(2);
            open = true;
        }
    }
    
    cout << "File opened succesfully.\n\n";
    
    //sleep(2);
    
    cout << "Creating gameboard...\n\n";
    
    int array_position = 0;
    
    for(int row = 1; row < 20; row++)
    {
        string input;
        
        getline(filein, input);
        
        if(row % 2 == 1)
        {
            stringstream space(input);
            
            char board_space; //Holds the spaces between each board hole;
            
            for(int col = 0; col < 10; col++)
            {
                space >> board_space;
                
                if(board_space == 'S')
                {
                    PostAction(array_position, 'S');
                }
                array_position++;
            }
        }
    }
    
    //sleep(2);
    
    cout << "Board created.\n\n";
}

//Prints out the board that you selected showing you its current state during the game.
void Board::PrintBoard()
{
    cout << " ";
    
    for(int i = 0; i < 10; i++)
    {
        cout << " " << i;
        
        if(i == 9)
        {
            cout << endl;
        }
    }
    
    char label = 'A';
    
    for(int col = 0; col < 10; col ++)
    {
        cout << label;
        
        label++;
        
        for(int row = 0; row < 10; row++)
        {
            cout << " " << board_.at((row * 10) + col);
            
            if(row == 9)
            {
                cout << endl;
            }
        }
    }
}

//Takes in user action (position of attack choice) and changes the display accordingly M = miss, o = nothing, H = hit, S = Ship.
void Board::PostAction(int board_postion, char new_status)
{
    if(tolower(new_status) == 's' || tolower(new_status) == 'h' || tolower(new_status) == 'm')
    {
        board_.at(board_postion) = new_status;
    }
}

//Sets the number of ship positions that haven't bit hit.
void Board::set_ships_still_swimming(int ships_still_swiming)
{
    ships_still_swiming_ = ships_still_swiming;
}
