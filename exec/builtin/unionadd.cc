//#define XERR
#include "builtin.ih"

// static
void Builtin::unionAdd(vector<string> &dest, string const &src)
{
                                                // src not yet available
    if (find(dest.begin(), dest.end(), src) == dest.end())  
        dest.push_back(src);                    // then add it.
}
