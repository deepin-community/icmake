//#define XERR
#include "tools.ih"

// static
bool Tools::remove(string const &path)
{
    return fs::remove(path, s_ec);
}
