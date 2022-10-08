#define XERR
#include "stringstore.ih"

string const &StringStore::str(unsigned offset) const
{
    return d_string[d_indexOf.find(offset)->second].str;
}
