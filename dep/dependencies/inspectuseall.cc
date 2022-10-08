//#define XERR
#include "dependencies.ih"

void Dependencies::inspectUseAll(size_t idx)
{
    if (not d_indicator[idx])           // no useAll file here: skip this dir.
        return;

    size_t dep = 0;
    while ((dep = findIdx(d_indicator, dep, false)) != d_size)
    {
        if (d_dependency[dep][idx])
            recursiveUseAll(dep);       // recursively inspect directory[dep]
        ++dep;
    }
}
