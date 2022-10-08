//#define XERR
#include "state.ih"

void State::err() const
{
    throw Exception{} << "internal error: reset request not at BOL";
}
