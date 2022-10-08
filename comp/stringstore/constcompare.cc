//#define XERR
#include "stringstore.ih"

int StringStore::constCompare(unsigned lhsOffset, unsigned rhsOffset) const
{
    return d_string[ d_indexOf.find(lhsOffset)->second ].str.compare(
                d_string[ d_indexOf.find(rhsOffset)->second ].str
            );
}
