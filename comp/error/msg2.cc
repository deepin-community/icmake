//#define XERR
#include "error.ih"

namespace
{
    ofstream noOut;
}

// static
ostream &Error::msg(Semantic error)
{
    return display() ?
                cout << g_where << s_semantic[error]
            :
                noOut;
}
