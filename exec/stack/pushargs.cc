//#define XERR
#include "stack.ih"

void Stack::pushArgs(unsigned idx, unsigned argc, char **argv)
{
    vector<string> vect;
    
    for ( ; idx != argc; ++idx)
        vect.push_back(argv[idx]);

    push(new List{ move(vect) });
}
