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
Board::GameBoard()
{
    board_.resize (100, 'o');

    ships_still_swiming_ = 17; //Counting ships by thier health. 17 = 1 5 health ship, 1 4 health ship, 2 3 health ships, and 1 2 health ship.
}

//Accesor, Returns the board layout/vector
vector<char> Board::board()
{
    return board_;
}

//Accesor, returns the amount of ships that are still swimming aka still alive
Board::ships_still_swiming()
{
    return ships_still_swiming_;
}

//Reads the board file and creates the board that you pick.
Board::CreateGameBoard()
{
    bool open = false;

    string filename;

    ifstream filein;

    while (open != true)
    {
        cout << "Please Enter the name of the GameBoard File you would like to use.\nPlease do not include extensions. (ie. .txt, .in...)" << endl;

        cin >> filename;

        filename.append(".txt");

        filein.open(filename);

        if(!filein.good())
        {
            cout << "Error: File " << filename << " was not found.\nPlease make sure your spelling is correct and double check that" <<
                 " the file is in the dierectory try again." << endl;
        }
        else
        {
            cout << "File found.\nPlease wait while the file is opened.\n\n";
            sleep(3);
            open = true;
        }
    }
    
    cout << "File opened succesfully.\n\n";
    sleep(2);
    cout << "Creating gameboard....\n\n";
    sleep(2);
    cout << "Board created.\n\n";

}
}
