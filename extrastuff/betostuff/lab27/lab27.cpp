#include <iostream>
#include <vector>

#include "activity.h"

using namespace std;

int main()
{
    int result;
    
    vector<Course> vs;
    
    vector<Course> *ptr;
    
    ptr = &vs;
    
    result = Menu(ptr);
    
    return 0;
}
