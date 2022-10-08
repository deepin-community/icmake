//#define XERR
#include "list.ih"

VarBase &List::vAddIs(VarBase const &rhs)
{
    auto const &rhsList = rhs.list();
    std::copy(rhsList.begin(), rhsList.end(), back_inserter(d_list));
    return *this;
}
