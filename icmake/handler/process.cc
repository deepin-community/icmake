#define XERR
#include "handler.ih"

int Handler::process()
{
    return (this->*s_action[d_splitter.actionOpt()]) ();
}
