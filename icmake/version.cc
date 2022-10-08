#include "main.ih"

void version(string const &progname)
{
    size_t idx = progname.rfind('/');

    if (idx == string::npos)
        idx = 0;
    else
        ++idx;

    cout << progname.substr(idx) << " V" VERSION "\n";
}
        
