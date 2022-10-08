//#define XERR
#include "list.ih"

VarBase *List::vcopy() const
{
    return new List{ vector<string>{ d_list } };
}
