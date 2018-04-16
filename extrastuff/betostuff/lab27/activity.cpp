#include "activity.h"

#include <iostream>
#include <vector>

using namespace std;

int Menu(vector<Course> *ptr)
{
    int choice;
    
    bool stop = false;
    
    while(stop == false)
    {
    
        cout << "Course Management System" << endl;
        
        cout << "1) Add a new course" << endl;
        
        cout << "2) Add a new student" << endl;
        
        cout << "3) Display all the courses" << endl;
        
        cout << "4) Display all the students with in a course" << endl;
        
        cout << "5) Remove a course" << endl;
        
        cout << "6) Remove a student withing a course" << endl;
        
        cout << "7) Exit" << endl;
        
        cin >> choice;
        
        cin.ignore();
        
        switch(choice)
        {
            case 1: 
            {
                AddCourse(ptr);
                
                break;
            }
            
            case 3:
            {
                PrintCourse(ptr);
                
                break;
            }
            
            case 7:
            {
                Quit(stop);
                
                break;
            }
            
            default:
            {
                break;
            }
        }
    
    }
}

void AddCourse(vector<Course> *ptr)
{
    vector<Course> *temp = ptr;
    
    cout << "Enter a new course name." << endl;
    
    string newClass;
    
    getline(cin, newClass);
    
    int units;
    
    cout << "Enter number of units." << endl;
    
    cin >> units;
    
    cout << "Adding Course" << endl << endl;
    
    temp->push_back(Course(newClass, units));
}

void PrintCourse(vector<Course> *ptr)
{
    int size = ptr->size();
    
    for(int i = 0; i < size; i++)
    {
        string temp = ptr->at(i).getName();
        
        cout << "courseName = " << temp << endl;
    }
    
    cout << endl;
}

void Quit(bool &access)
{
    cout << "Come back again!" << endl;
    
    access = true;
}