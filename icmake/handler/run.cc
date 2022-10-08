//#define XERR
#include "handler.ih"

bool Handler::run(string const &cmd)
{
    d_process.setCommand(LIBDIR "/" + cmd);

    if (d_verbose)
        cout << "calling `" << d_process.str() << "'\n";

    return d_doProcess;
}
