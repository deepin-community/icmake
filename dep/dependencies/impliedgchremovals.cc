//#define XERR
#include "dependencies.ih"

    // find all dirs whose gch files must be removed, and mark the gch files
    // of depending directories also for removal
void Dependencies::impliedGchRemovals()
{
    size_t idx = 0;                 
    while ((idx = findIdx(d_indicator, idx, true)) != d_size)
    {
        dependentGch(idx);
        ++idx;
    }
}
