//#define XERR
#include "state.ih"

void State::text2content()
{
    d_scanner.text();
    d_state = CONTENT;
}
