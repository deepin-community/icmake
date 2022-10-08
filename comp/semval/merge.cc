//#define XERR
#include "semval.ih"

// static
void SemVal::merge(vector<unsigned> &dest, vector<unsigned> &src)
{
    dest.insert(dest.end(), src.begin(), src.end());
    src.clear();
}
