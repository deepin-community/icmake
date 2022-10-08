#define XERR
#include "handler.ih"

int Handler::dependencies()
{
    return direct("icm-dep" + 
                    catArgs(d_splitter.actionArgsIdx(), d_splitter.argc())); 
}
