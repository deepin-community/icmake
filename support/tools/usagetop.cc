//#define XERR
#include "tools.ih"

// static
ostream &Tools::usageTop(string const &progname)
{
    return
        cout << '\n' <<
            progname << " by " AUTHOR "\n" <<
            progname << " V" VERSION "\n"
            "Copyright (c) GPL " YEARS ". NO WARRANTY.\n"
            "\n"
            "Usage: " << progname;
}
