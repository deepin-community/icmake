//#define XERR
#include "dependencies.ih"

void Dependencies::localHeader(size_t idx, string const &header)
{
                                    // this header has already been visited
    if (d_inspecting.find(header) != d_inspecting.end())
        return;

    d_inspecting.insert(header);    // we're inspecting a new header
    d_localHeader[idx].push_back(header);

    dependency(idx, header);        // check it: indirect recursion.
}
