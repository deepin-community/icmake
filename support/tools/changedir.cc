//#define XERR
#include "tools.ih"

// static
bool Tools::changeDir(string const &path)
{
    error_code ec;

    filesystem::current_path(path, ec);

    return not ec;          // ec: true, then couldn't chdir
}
