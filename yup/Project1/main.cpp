/*
 * Name        : main.cpp
 * Author      : Jacob Pawek
 * Date        : 2-1-18
 * Description : Test application outputs
 */
 
#include <iostream>
#include "collection.cpp"
#include "card.cpp"
#include "gold.cpp"
#include "platinum.cpp"
#include "corporate.cpp"
#include "transaction.cpp"


int main()
{
    char go_again = 'Y';
    while (go_again != 'N')
    {
        Collection test_collection;
        cout << "What would you like to view?" << endl;
        cout << "(1) - Denied transactions" << endl;
        cout << "(2) - Monthly bills" << endl;
        cout << endl << "Selection: ";
        int choice;
        cin >> choice;
        test_collection.FillVectors("input_data1.txt", "input_data2.txt");
        
        if (choice == 1)
            test_collection.DenialStatement("input_data2.txt");
        else if (choice == 2)
            test_collection.MonthlyStatement();
        cout << endl << "Would you like to view something else? (Y/N)" << endl;
        cin >> go_again;
        cout << endl;
        go_again = toupper(go_again);
    }
    
    return 0;
}