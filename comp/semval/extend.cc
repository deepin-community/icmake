//#define XERR
#include "semval.ih"

// static
void SemVal::extend(vector<unsigned> &dest, vector<unsigned> &src, 
                    unsigned shift)
{
    for_each(src.begin(), src.end(), 
        [&](unsigned offset)
        {
            dest.push_back(offset + shift);
        }
    );
}
