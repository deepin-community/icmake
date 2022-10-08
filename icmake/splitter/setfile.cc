//#define XERR
#include "splitter.ih"

string Splitter::setFile(unsigned idx)
{
    if (d_argv[idx][0] != '-')              // not an option
    {
        ++d_nFiles;
        return d_argv[idx];
    }

    return s_empty;
}
