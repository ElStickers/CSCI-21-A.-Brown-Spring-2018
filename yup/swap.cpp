#include <iostream>
#include <windows.h>

using namespace std;

template <typename Type>

Type Swap (Type& x, Type& y){
    
    int temp = x;
    
    x = y;
    
    y = temp;
}

int main () {
    
    int w = 10 , u = 15;
    
    Swap(w,u);
    
    cout << u << " " << w;
    
    return 0;
    
}