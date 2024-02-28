//#define XERR
#include "tools.ih"

// static
bool Tools::changeDir(string const &path)
{
    fs::current_path(path, s_ec);

    return not s_ec;          // ec: true, then couldn't chdir
}
