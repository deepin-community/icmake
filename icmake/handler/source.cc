#define XERR
#include "handler.ih"

int Handler::source()
{
    if (not compile())
        return 1;

    d_splitter.setArgv(d_splitter.endOpts(), &d_file2.front());
    return exec(&Handler::child);
}
