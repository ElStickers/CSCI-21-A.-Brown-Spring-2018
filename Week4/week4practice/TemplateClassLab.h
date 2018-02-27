
#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;

template<typename T>
class Box {
    private:
        T contents;
        
    public:
        Box(T newContents);
        
        T getContents();
        
        void setContents(T newContents);
        
        friend ostream& operator<<(ostream&, const T&);
};

#endif