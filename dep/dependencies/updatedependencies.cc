//#define XERR
#include "dependencies.ih"

    // inspect d_dependency[idx]. Find all [dep] elements for which 
    // d_dependency[idx][dep] is true. All elements that were set in
    // d_dependency[dep] must also be set in d_dependency[idx]. 
    // if no changes were made, return false, otherwise return true

bool Dependencies::updateDependencies(size_t idx)
{
    BoolVect &update = d_dependency[idx]; // the vector to inspect

    bool updated = false;

    size_t dep = 0;
    while ((dep = findIdx(update, dep, true)) != d_size)
    {
        updated |= orBoolVect(update, d_dependency[dep]);
        ++dep;
    }    

    return updated;
}
