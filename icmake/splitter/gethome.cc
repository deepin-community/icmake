//#define XERR
#include "splitter.ih"

// static
char const *Splitter::getHome()
{
    char const *cp = getenv("HOME");
    return cp != 0 ? cp : s_empty;
}
