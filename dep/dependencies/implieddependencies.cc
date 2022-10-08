//#define XERR
#include "dependencies.ih"

    // start with the dependencies matrix, initially set all rows to inspect'
    // for each dependency[idx] to inspect: inspect its 'true' elements, 
    // and bit-or the elements of those vectors with those of dependency[idx].
    // Set idx's inspect status to true if dependency[idx] was changed.
    // Repeat this process untill no more changed were made.

void Dependencies::impliedDependencies()
{
                                // start with all paths are changed
    BoolVect inspect( d_size, true );

    bool changed;               // set to true if changes were made

    do                          // visit all rows, update their 'inspect' 
    {                           // status until no more changes were made
        changed = false;
        size_t idx = 0;
        while ((idx = findIdx(inspect, idx, true)) != d_size)
        {
            changed |= inspect[idx] = updateDependencies(idx);
            ++idx;
        }
    }
    while (changed);            // continue until no more changes

        // the diagonal can be ignored: by definition a class depends on
        // itself.
    for (size_t idx = 0; idx != d_size; ++idx)
        d_dependency[idx][idx] = false;

    setCount();

    showDependencies("Implied class dependencies:");
}










