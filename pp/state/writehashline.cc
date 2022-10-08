//#define XERR
#include "state.ih"

void State::writeHashLine()
{
    d_scanner.write("#\n");
    d_state = START;
}
