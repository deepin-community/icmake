#define XERR
#include "handler.ih"

int Handler::unassemble()
{
    return direct("icmun " + d_splitter.versionCheck() + 
                    catArgs(d_splitter.actionArgsIdx(), d_splitter.argc()));
}
