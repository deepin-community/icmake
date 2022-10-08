//#define XERR
#include "state.ih"

void State::nlHashLine()
{
    if (not d_scanner.active())
        return;

    d_scanner.write('\n');
    writeHashLine();
}
