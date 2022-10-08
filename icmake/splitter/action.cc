//#define XERR
#include "splitter.ih"

void Splitter::action(unsigned *index)
{
    if (*index == 0)
        *index = d_optIdx;

    setAction();
}
