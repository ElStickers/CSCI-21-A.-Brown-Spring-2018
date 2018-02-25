#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string word1 = "", word2 = "";
    char play;
    int size = 0;
    int yes = 0;
    int no = 0;
    int match = 0;
    int playagain = 0;
    while(true) //main loop
    {
        while (true)//question loop
        {
            switch(playagain)
            {
            case(0):
                cout << "Do you want to play the Anagram Game?" << endl;
                cout << "(y = yes) (n = no)" << endl;
                cin >> play;
                break;

            default:
                cout << "Do you want to play again?" << endl;
                cout << "(y = yes) (n = no)" << endl;
                cin >> play;
                break;
            }

            if(towlower(play) == 'y')
            {
                cout << "Please Enter Word 1: ";
                cin >> word1;
                cout << "Please Enter Word 2: ";
                cin >> word2;
                break;
            }
            else if (tolower(play) == 'n')
            {
                cout << "GoodBye." << endl;
                cout << "Anagram Session Statistics" << endl;
                cout << yes << " pair(s) of words were anagrams of each other." << endl;
                cout << no << " pair(s) of words were not anagrams of each other." << endl;
                return 1;
            }
            else
            {
                cout << "Please Enter 'Y' or 'N'" << endl << endl;
            }
        }

        if ( word1.length() != word2.length())
        {
            cout << "No: The words are not anagrams because they are not the same length." << endl;
            no++;
            playagain++;
            continue;
        }
        for(int i = 0; i < word1.length(); i++)
        {
            for (int x = 0; x < word2.length(); x++)
            {
                if(word1[i] == word2[x])
                {
                    word2[x] = ' ';
                    match++;
                }

            }
        }
        if(match == word1.length())
        {
            cout << "Yes: The words are anagrams of each other." << endl;
            yes++;
            match = 0;
            playagain++;
        }
        else if (match > word1.length())
        {
            cout << "No: The words are not anagrams of each other." << endl;
            no++;
            match = 0;
            playagain++;
        }
        else if (match < word1.length())
        {

            cout << "No: The words are not anagrams of each other." << endl;
            no++;
            match = 0;
            playagain++;
        }
    }

}
