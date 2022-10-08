//#define XERR
#include "state.ih"

void State::hashLine()
{
    if (d_scanner.active())
        writeHashLine();
}
