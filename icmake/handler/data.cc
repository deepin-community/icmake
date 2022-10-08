//#define XERR
#include "handler.ih"

int (Handler::*Handler::s_action[])()
{
    &Handler::compile,
    &Handler::dependencies,
    &Handler::exec,
    &Handler::forced,
    &Handler::preprocess,
    &Handler::source,
    &Handler::script,
    &Handler::unassemble,
};

