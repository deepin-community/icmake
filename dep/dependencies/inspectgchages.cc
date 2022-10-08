//#define XERR
#include "dependencies.ih"

void Dependencies::inspectGchAges()
{
    for (size_t idx = 0; idx != d_size; ++idx)
        inspectGchAge(idx);
}
