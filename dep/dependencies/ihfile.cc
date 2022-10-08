//#define XERR
#include "dependencies.ih"

string Dependencies::ihFile(size_t idx) const
{
    return d_directory[idx] + d_options.dotIH();
}
