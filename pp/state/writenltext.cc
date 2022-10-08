//#define XERR
#include "state.ih"

void State::writeNLtext()
{
    d_scanner.write('\n');
    text();
}
