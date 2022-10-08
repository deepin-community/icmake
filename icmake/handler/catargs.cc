#define XERR
#include "handler.ih"

string Handler::catArgs(unsigned begin, unsigned end) const
{
    string ret;

    for 
    (
        char const *const *beginArgs = d_splitter.argv() + begin,
                   *const *endArgs = d_splitter.argv() + end;
            beginArgs != endArgs; 
                ++beginArgs
    )
        (ret += ' ') += *beginArgs;

    return ret;
}
