//#define XERR
#include "dependencies.ih"

namespace {
    unsigned idx = 0;
}

void Dependencies::setClassIdx()
{
    d_classIdx.resize(d_size);

    for_each(d_classIdx.begin(), d_classIdx.end(),
        [=](unsigned &dest)
        {
            dest = idx;
            ++idx;
        }
    );
}
