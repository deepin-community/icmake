//#define XERR
#include "stack.ih"

void Stack::pushCharPtrPtr(char **src)
{
    vector<string> vect;

    while (*src)
    {
        vect.push_back(*src);
        ++src;
    }
    
    push(new List{ move(vect) });
}
