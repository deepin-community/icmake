#define XERR
#include "handler.ih"

string Handler::range(unsigned begin, unsigned end) const
{
    if (begin == 0)                             // no begin option (e.g., -p)
        return "";

    if (begin > end)                            // begin > end -> endOpts
        end = d_splitter.endOpts();             // (e.g. at -e or else the 
                                                // actual options end)

    return catArgs(begin + 1, end);
}
