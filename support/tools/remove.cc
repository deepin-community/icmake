//#define XERR
#include "tools.ih"

// static
bool Tools::remove(string const &path)
{
    error_code ec;

    return filesystem::remove(path, ec);
}
