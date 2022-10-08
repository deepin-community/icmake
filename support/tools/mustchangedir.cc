//#define XERR
#include "tools.ih"

// static
void Tools::mustChangeDir(string const &path)
{
    if (not changeDir(path))
        throw Exception{} << "cannot chdir to " << path;
}
