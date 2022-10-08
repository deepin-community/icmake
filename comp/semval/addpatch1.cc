#define XERR
#include "semval.ih"

void SemVal::addPatch(vector<unsigned> &patchVect)
{
    *this << as<short>(0);
    patchVect.push_back(d_code.size());
}
