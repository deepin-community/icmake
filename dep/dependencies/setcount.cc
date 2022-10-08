//#define XERR
#include "dependencies.ih"

void Dependencies::setCount()
{
    for (unsigned idx = 0; idx != d_size; ++idx)
        d_classCount[idx] = 
            d_size - count(d_dependency[idx].begin(), d_dependency[idx].end(), 
                           0);

    sort(d_classIdx.begin(), d_classIdx.end(), 
        [&](unsigned lhs, unsigned rhs)
        {
            return d_classCount[lhs] > d_classCount[rhs];
        }
    );
}
