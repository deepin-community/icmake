#define XERR
#include "handler.ih"

int Handler::child(string const &cmd)
{
    if (not run(cmd))
        return 0;

    d_process.start(Process::NONE);

    return d_process.waitForChild();
}
