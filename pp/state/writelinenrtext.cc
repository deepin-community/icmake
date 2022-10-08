//#define XERR
#include "state.ih"

void State::writeLineNrText()
{
    d_scanner.write('#');
    d_scanner.writeLineNr();
    writeNLtext();
}
