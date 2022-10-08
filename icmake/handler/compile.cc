#define XERR
#include "handler.ih"

int Handler::compile()
{
    file2(".bim");

    if (doCompile())
        return forced();

    if (d_verbose)
        cout << '`' << d_file2 << "' is up-to-date. Not calling\n"
                "       `" LIBDIR "/icm-comp" << 
                catArgs(d_splitter.actionArgsIdx(), d_splitter.argc()) << 
                "'\n";

    return 0;
}







