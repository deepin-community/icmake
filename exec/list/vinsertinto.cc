//#define XERR
#include "list.ih"

ostream &List::vInsertInto(ostream &out) const
{
    if (d_list.empty())
        return out;

    std::copy(d_list.begin(), d_list.end() - 1, 
              ostream_iterator<string>(out, " "));

    return out << d_list.back();
}
