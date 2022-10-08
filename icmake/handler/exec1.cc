//#define XERR
#include "handler.ih"

int Handler::exec()
{
    return exec(&Handler::direct);
}
