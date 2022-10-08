#define XERR
#include "handler.ih"

int Handler::direct(string const &cmd)
{
                    // returns d_doProcess if false -> 0 is returned
                    // or execution fails -> 1 is returned

    if (not run(cmd))               // don't run if d_doProcess is false
        return 0;

    d_process.start(Process::DIRECT);

    return 1;                           // not reached when exec succeeds
}
