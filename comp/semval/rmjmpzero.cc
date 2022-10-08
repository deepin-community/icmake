//#define XERR
#include "semval.ih"

void SemVal::rmJmpZero()
{
    if ( d_patchFalse.size() and d_patchFalse.back() == d_code.size() )
    {
        d_patchFalse.pop_back();
        d_code.resize(d_code.size() - sizeof(char) - sizeof(short));
    }

    patchFalse(END);
}
