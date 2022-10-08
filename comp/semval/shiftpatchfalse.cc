//#define XERR
#include "semval.ih"

void SemVal::shiftPatchFalse(unsigned shift)
{
    for (unsigned &offset: d_patchFalse)
        offset += shift;
}
