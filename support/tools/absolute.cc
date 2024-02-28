#define XERR
#include "tools.ih"

string Tools::absolute(string const &dir)
{
    return fs::absolute(dir).string();
}
